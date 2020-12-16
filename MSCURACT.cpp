

#include "TMCStepper.h"
#include "TMC_MACROS.h"

uint32_t TMC2041Stepper::MSCURACT(uint8_t motor) { return read(MSCURACT_register.address[motor]); } 