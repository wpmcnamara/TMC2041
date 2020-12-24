#include "TMCStepper.h"
#include "TMC_MACROS.h"

constexpr uint8_t CHOPCONF_reg_set::address[];

SET_REG_GROUP(TMC2041Stepper, CHOPCONF)
GET_REG_GROUP(TMC2041Stepper, CHOPCONF)

SET_REG(TMC2041Stepper, CHOPCONF, uint8_t, toff)
SET_REG(TMC2041Stepper, CHOPCONF, uint8_t, hstrt)
SET_REG(TMC2041Stepper, CHOPCONF, uint8_t, hend)
SET_REG(TMC2041Stepper, CHOPCONF, uint8_t, fd3)
SET_REG(TMC2041Stepper, CHOPCONF, bool, disfdcc)
SET_REG(TMC2041Stepper, CHOPCONF, bool, rndtf)
SET_REG(TMC2041Stepper, CHOPCONF, bool, chm)
SET_REG(TMC2041Stepper, CHOPCONF, uint8_t, tbl)
SET_REG(TMC2041Stepper, CHOPCONF, bool, vsense)
SET_REG(TMC2041Stepper, CHOPCONF, uint8_t, mres)
SET_REG(TMC2041Stepper, CHOPCONF, bool, intpol)
SET_REG(TMC2041Stepper, CHOPCONF, bool, dedge)
SET_REG(TMC2041Stepper, CHOPCONF, bool, diss2g)

GET_REG(TMC2041Stepper, CHOPCONF, uint8_t, toff)
GET_REG(TMC2041Stepper, CHOPCONF, uint8_t, hstrt)
GET_REG(TMC2041Stepper, CHOPCONF, uint8_t, hend)
GET_REG(TMC2041Stepper, CHOPCONF, uint8_t, fd3)
GET_REG(TMC2041Stepper, CHOPCONF, bool, disfdcc)
GET_REG(TMC2041Stepper, CHOPCONF, bool, rndtf)
GET_REG(TMC2041Stepper, CHOPCONF, bool, chm)
GET_REG(TMC2041Stepper, CHOPCONF, uint8_t, tbl)
GET_REG(TMC2041Stepper, CHOPCONF, bool, vsense)
GET_REG(TMC2041Stepper, CHOPCONF, uint8_t, mres)
GET_REG(TMC2041Stepper, CHOPCONF, bool, intpol)
GET_REG(TMC2041Stepper, CHOPCONF, bool, dedge)
GET_REG(TMC2041Stepper, CHOPCONF, bool, diss2g)
