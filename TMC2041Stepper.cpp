#include "TMCStepper.h"
#include "TMC_MACROS.h"

int8_t TMC2041Stepper::chain_length = 0;
uint32_t TMC2041Stepper::spi_speed = 16000000/8;

/*
void TMC2041Stepper::push(uimt8_t motor) {
	GCONF(GCONF_register.sr);
	IHOLD_IRUN(IHOLD_IRUN_register.sr);
	CHOPCONF(CHOPCONF_register.sr);
  COOLCONF(COOLCONF_register.sr);
}*/


TMC2041Stepper::TMC2041Stepper(uint16_t pinCS, float RS, int8_t link) :
  TMCStepper(RS),
  _pinCS(pinCS),
  link_index(link)
  {
    Serial.printf("TMC2041Stepper::TMC2041Stepper(uint16_t pinCS, float RS, int8_t link)\n");
    defaults();
    if (link > chain_length)
      chain_length = link;
  }

void TMC2041Stepper::defaults() {
 
    GCONF_register.sr = 0x00000006;
    IHOLD_IRUN_register.sr = 0x000F1000;
    CHOPCONF_register.sr = 0x000101D5;
}

__attribute__((weak))
void TMC2041Stepper::setSPISpeed(uint32_t speed) {
  spi_speed = speed;
}

__attribute__((weak))
void TMC2041Stepper::switchCSpin(bool state) {
  digitalWrite(_pinCS, state);
}

__attribute__((weak))
void TMC2041Stepper::beginTransaction() {
    SPISettings settings(2000000, MSBFIRST, SPI_MODE0); 
    SPI.beginTransaction(settings);
}
__attribute__((weak))
void TMC2041Stepper::endTransaction() {
    SPI.endTransaction();
}

__attribute__((weak))
uint8_t TMC2041Stepper::transfer(const uint8_t data) {
  uint8_t out = 0;
    out = SPI.transfer(data);
  return out;
}

void TMC2041Stepper::transferEmptyBytes(const uint8_t n) {
  for (uint8_t i = 0; i < n; i++) {
    transfer(0x00);
  }
}

__attribute__((weak))
uint32_t TMC2041Stepper::read(uint8_t addressByte) {
  uint32_t out = 0UL;
  int8_t i = 1;

  beginTransaction();
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
void TMC2041Stepper::write(uint8_t addressByte, uint32_t config) {
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

void TMC2041Stepper::begin() {
    Serial.printf("2041 Begin\n");
  //set pins
  pinMode(_pinCS, OUTPUT);
  switchCSpin(HIGH);
  SPI.begin();
  GCONF(GCONF_register.sr);
  CHOPCONF(0, CHOPCONF_register.sr);
  IHOLD_IRUN(0, IHOLD_IRUN_register.sr);
  CHOPCONF(1, CHOPCONF_register.sr);
  IHOLD_IRUN(1, IHOLD_IRUN_register.sr);
}

/*
int16_t TMC2041Stepper::cur_a() {
  MSCURACT_t r{0};
  r.sr = MSCURACT();
  int16_t value = r.cur_a - 256;
  //if (value > 255) value -= 512;
  return value;
}
int16_t TMC2041Stepper::cur_b() {
  MSCURACT_t r{0};
  r.sr = MSCURACT();
  int16_t value = r.cur_b -256;
  //if (value > 255) value -= 512;
  return value;
}*/