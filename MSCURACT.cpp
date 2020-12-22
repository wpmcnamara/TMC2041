

#include "TMCStepper.h"
#include "TMC_MACROS.h"

constexpr uint8_t MSCURACT_t::address[];

uint32_t TMC2041Stepper::MSCURACT(uint8_t motor) { return read(MSCURACT_register.address[0]); } 