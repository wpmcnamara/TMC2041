
#include "TMCStepper.h"
#include "TMC_MACROS.h"

constexpr uint8_t MSCNT_reg_set::address[];

GET_REG_GROUP(TMC2041Stepper, MSCNT)

GET_REG(TMC2041Stepper, MSCNT, uint16_t, mscnt)