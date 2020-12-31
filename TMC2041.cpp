#include "TMC2041.h"

int8_t TMC2041::chain_length = 0;
uint32_t TMC2041::spi_speed = 16000000/8;

/*
void TMC2041::push(uimt8_t motor) {
	GCONF(GCONF_register.sr);
	IHOLD_IRUN(0, IHOLD_IRUN_register.sr);
	CHOPCONF(0, CHOPCONF_register.sr);
  COOLCONF(0, COOLCONF_register.sr);
}*/


TMC2041::TMC2041(uint16_t pinCS, float RS, int8_t link) :
  Rsense(RS),
  _pinCS(pinCS),
  link_index(link)
  {
    //Serial.printf("TMC2041::TMC2041(uint16_t pinCS, float RS, int8_t link)\n");

    defaults();
    if (link > chain_length)
      chain_length = link;
  }

void TMC2041::defaults() {
 
    GCONF_register.reg[0].sr = 0x00000006;
    IHOLD_IRUN_register.reg[0].sr = 0x000F1000;
    IHOLD_IRUN_register.reg[1].sr = 0x000F1000;
    CHOPCONF_register.reg[0].sr = 0x000101D5;
    CHOPCONF_register.reg[1].sr = 0x000101D5;
}

__attribute__((weak))
void TMC2041::setSPISpeed(uint32_t speed) {
  spi_speed = speed;
}

__attribute__((weak))
void TMC2041::switchCSpin(bool state) {
  digitalWrite(_pinCS, state);
}

__attribute__((weak))
void TMC2041::beginTransaction() {
    SPISettings settings(2000000, MSBFIRST, SPI_MODE0); 
    SPI.beginTransaction(settings);
}
__attribute__((weak))
void TMC2041::endTransaction() {
    SPI.endTransaction();
}

__attribute__((weak))
uint8_t TMC2041::transfer(const uint8_t data) {
  uint8_t out = 0;
    out = SPI.transfer(data);
  return out;
}

void TMC2041::transferEmptyBytes(const uint8_t n) {
  for (uint8_t i = 0; i < n; i++) {
    transfer(0x00);
  }
}

__attribute__((weak))
uint32_t TMC2041::read(uint8_t addressByte) {
  uint32_t out = 0UL;
  int8_t i = 1;
  switchCSpin(LOW);
  transfer(addressByte);
  // Clear SPI
  transferEmptyBytes(4);

  // Shift the written data to the correct driver in chain
  // Default link_index = -1 and no shifting happens
  while(i < link_index) {
    transferEmptyBytes(5);
    i++;
  }

  switchCSpin(HIGH);
  switchCSpin(LOW);

  // Shift data from target link into the last one...
  while(i < chain_length) {
    transferEmptyBytes(5);
    i++;
  }

  // ...and once more to MCU
  status_response = transfer(addressByte); // Send the address byte again
  out  = transfer(0x00);
  out <<= 8;
  out |= transfer(0x00);
  out <<= 8;
  out |= transfer(0x00);
  out <<= 8;
  out |= transfer(0x00);
  endTransaction();
  switchCSpin(HIGH);
  return out;
}

__attribute__((weak))
void TMC2041::write(uint8_t addressByte, uint32_t config) {
  addressByte |= TMC_WRITE;
  int8_t i = 1;
  beginTransaction();
  switchCSpin(LOW);
  status_response = transfer(addressByte);
  transfer(config>>24);
  transfer(config>>16);
  transfer(config>>8);
  transfer(config);
  while(i < link_index) {
    transferEmptyBytes(5);
    i++;
  }

  endTransaction();
  switchCSpin(HIGH);
}

void TMC2041::begin() {
    Serial.printf("2041 Begin\n");
  //set pins
  pinMode(_pinCS, OUTPUT);
  switchCSpin(HIGH);
  SPI.begin();
  GCONF(0, GCONF_register.reg[0].sr);
  CHOPCONF(0, CHOPCONF_register.reg[0].sr);
  CHOPCONF(1, CHOPCONF_register.reg[1].sr);
  IHOLD_IRUN(0, IHOLD_IRUN_register.reg[0].sr);
  IHOLD_IRUN(1, IHOLD_IRUN_register.reg[1].sr);
 Serial.printf("2041 Begin done\n");
}

/*
int16_t TMC2041::cur_a() {
  MSCURACT_t r{0};
  r.sr = MSCURACT();
  int16_t value = r.cur_a - 256;
  //if (value > 255) value -= 512;
  return value;
}
int16_t TMC2041::cur_b() {
  MSCURACT_t r{0};
  r.sr = MSCURACT();
  int16_t value = r.cur_b -256;
  //if (value > 255) value -= 512;
  return value;
}*/

void TMC2041::microsteps(uint8_t index, uint16_t ms) {
  switch(ms) {
    case 256: mres(index, 0); break;
    case 128: mres(index, 1); break;
    case  64: mres(index, 2); break;
    case  32: mres(index, 3); break;
    case  16: mres(index, 4); break;
    case   8: mres(index, 5); break;
    case   4: mres(index, 6); break;
    case   2: mres(index, 7); break;
    case   0: mres(index, 8); break;
    default: break;
  }
}

/*
  Requested current = mA = I_rms/1000
  Equation for current:
  I_rms = (CS+1)/32 * V_fs/(R_sense+0.02ohm) * 1/sqrt(2)
  Solve for CS ->
  CS = 32*sqrt(2)*I_rms*(R_sense+0.02)/V_fs - 1

  Example:
  vsense = 0b0 -> V_fs = 0.325V
  mA = 1640mA = I_rms/1000 = 1.64A
  R_sense = 0.10 Ohm
  ->
  CS = 32*sqrt(2)*1.64*(0.10+0.02)/0.325 - 1 = 26.4
  CS = 26
*/

uint16_t TMC2041::cs2rms(uint8_t index, uint8_t CS) {
  return (float)(CS+1)/32.0 * (vsense(index) ? 0.180 : 0.325)/(Rsense+0.02) / 1.41421 * 1000;
}

void TMC2041::rms_current(uint8_t index, uint16_t mA) {
  uint8_t CS = 32.0*1.41421*mA/1000.0*(Rsense+0.02)/0.325 - 1;
  // If Current Scale is too low, turn on high sensitivity R_sense and calculate again
  if (CS < 16) {
    vsense(index, true);
    CS = 32.0*1.41421*mA/1000.0*(Rsense+0.02)/0.180 - 1;
  } else { // If CS >= 16, turn off high_sense_r
    vsense(index, false);
  }

  if (CS > 31)
    CS = 31;

  irun(index, CS);
  ihold(index, CS*holdMultiplier);
  //val_mA = mA;
}
void TMC2041::rms_current(uint8_t index, uint16_t mA, float mult) {
  holdMultiplier = mult;
  rms_current(index, mA);
}

uint16_t TMC2041::rms_current(uint8_t index) {
  return cs2rms(index, irun(index));
}

int16_t TMC2041::cur_a_scaled(uint8_t index) {
  int16_t value = cur_a(index);
  if (value > 255) value -= 512;
  return value;
}
int16_t TMC2041::cur_b_scaled(uint8_t index) {
  int16_t value = cur_b(index);
  if (value > 255) value -= 512;
  return value;
}