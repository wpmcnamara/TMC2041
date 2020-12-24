#include "TMCStepper.h"
#include "TMC_MACROS.h"

constexpr uint8_t IHOLD_IRUN_reg_set::address[];

SET_REG_GROUP(TMC2041Stepper, IHOLD_IRUN)
GET_SHADOW_REG_GROUP(TMC2041Stepper, IHOLD_IRUN)

SET_REG(TMC2041Stepper, IHOLD_IRUN, uint8_t, ihold)
SET_REG(TMC2041Stepper, IHOLD_IRUN, uint8_t, irun)
SET_REG(TMC2041Stepper, IHOLD_IRUN, uint8_t, iholddelay)

GET_SHADOW_REG(TMC2041Stepper, IHOLD_IRUN, uint8_t, ihold)
GET_SHADOW_REG(TMC2041Stepper, IHOLD_IRUN, uint8_t, irun)
GET_SHADOW_REG(TMC2041Stepper, IHOLD_IRUN, uint8_t, iholddelay)

