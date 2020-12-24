#include "TMCStepper.h"
#include "TMC_MACROS.h"

constexpr uint8_t COOLCONF_reg_set::address[];

SET_REG_GROUP(TMC2041Stepper, COOLCONF)
GET_SHADOW_REG_GROUP(TMC2041Stepper, COOLCONF)


SET_REG(TMC2041Stepper, COOLCONF, uint8_t, semin)
SET_REG(TMC2041Stepper, COOLCONF, uint8_t, seup)
SET_REG(TMC2041Stepper, COOLCONF, uint8_t, semax)
SET_REG(TMC2041Stepper, COOLCONF, uint8_t, sedn)
SET_REG(TMC2041Stepper, COOLCONF, bool, seimin)
SET_REG(TMC2041Stepper, COOLCONF, uint8_t, sgt)
SET_REG(TMC2041Stepper, COOLCONF, bool, sfilt)

GET_SHADOW_REG(TMC2041Stepper, COOLCONF, uint8_t, semin)
GET_SHADOW_REG(TMC2041Stepper, COOLCONF, uint8_t, seup)
GET_SHADOW_REG(TMC2041Stepper, COOLCONF, uint8_t, semax)
GET_SHADOW_REG(TMC2041Stepper, COOLCONF, uint8_t, sedn)
GET_SHADOW_REG(TMC2041Stepper, COOLCONF, bool, seimin)
GET_SHADOW_REG(TMC2041Stepper, COOLCONF, uint8_t, sgt)
GET_SHADOW_REG(TMC2041Stepper, COOLCONF, bool, sfilt)
