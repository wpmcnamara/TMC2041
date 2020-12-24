

#include "TMCStepper.h"
#include "TMC_MACROS.h"

constexpr uint8_t MSCURACT_reg_set::address[];

GET_REG_GROUP(TMC2041Stepper, MSCURACT)

GET_REG(TMC2041Stepper, MSCURACT, uint16_t, cur_b)
GET_REG(TMC2041Stepper, MSCURACT, uint16_t, cur_a)
