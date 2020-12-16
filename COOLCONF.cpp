#include "TMCStepper.h"
#include "TMC_MACROS.h"

#define SET_REG(SETTING) COOLCONF_register.SETTING = B; write(COOLCONF_register.address[M], COOLCONF_register.sr);

// COOLCONF
uint32_t TMC2041Stepper::COOLCONF(uint8_t motor) {  return read(COOLCONF_register.address[motor]); }
void TMC2041Stepper::COOLCONF(uint8_t motor, uint32_t input) {
	COOLCONF_register.sr = input;
	write(COOLCONF_register.address[motor], COOLCONF_register.sr);
}

void TMC2041Stepper::semin(		uint8_t M, uint8_t B )	{ SET_REG(semin);	}
void TMC2041Stepper::seup(		uint8_t M, uint8_t B )	{ SET_REG(seup);	}
void TMC2041Stepper::semax(		uint8_t M, uint8_t B )	{ SET_REG(semax);	}
void TMC2041Stepper::sedn(		uint8_t M, uint8_t B )	{ SET_REG(sedn);		}
void TMC2041Stepper::seimin(	uint8_t M, bool 	B )	{ SET_REG(seimin);	}
void TMC2041Stepper::sgt(		uint8_t M, int8_t 	B )	{ SET_REG(sgt);	}
void TMC2041Stepper::sfilt(		uint8_t M, bool 	B )	{ SET_REG(sfilt);		}
