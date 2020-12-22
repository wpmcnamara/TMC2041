
#include "TMCStepper.h"
#include "TMC_MACROS.h"

constexpr uint8_t MSCNT_t::address[];

uint16_t TMC2041Stepper::MSCNT(uint8_t motor) {
  return read(MSCNT_register.address[motor]);
}
