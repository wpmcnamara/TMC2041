
#include "TMCStepper.h"
#include "TMC_MACROS.h"

uint16_t TMC2041Stepper::MSCNT(uint8_t motor) {
  return read(MSCNT_register.address[motor]);
}
