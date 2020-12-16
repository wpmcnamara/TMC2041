#include "TMCStepper.h"
#include "TMC_MACROS.h"

#define SET_REG(SETTING) IHOLD_IRUN_register.SETTING = B; write(IHOLD_IRUN_register.address[M], IHOLD_IRUN_register.sr)

// IHOLD_IRUN
void TMC2041Stepper::IHOLD_IRUN(uint8_t motor,uint32_t input) {
	IHOLD_IRUN_register.sr = input;
	write(IHOLD_IRUN_register.address[motor], IHOLD_IRUN_register.sr);
}

void 	TMC2041Stepper::ihold(uint8_t M, uint8_t B) 		{ SET_REG(ihold);		}
void 	TMC2041Stepper::irun(uint8_t M, uint8_t B)  		{ SET_REG(irun); 		}
void 	TMC2041Stepper::iholddelay(uint8_t M, uint8_t B)	{ SET_REG(iholddelay); 	}

