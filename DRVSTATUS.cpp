#include "TMCStepper.h"
#include "TMC_MACROS.h"

constexpr uint8_t DRV_STATUS_reg_set::address[];

GET_REG_GROUP(TMC2041Stepper, DRV_STATUS)

GET_REG(TMC2041Stepper, DRV_STATUS, bool, stst)
GET_REG(TMC2041Stepper, DRV_STATUS, bool, olb)
GET_REG(TMC2041Stepper, DRV_STATUS, bool, ola)
GET_REG(TMC2041Stepper, DRV_STATUS, bool, s2gb)
GET_REG(TMC2041Stepper, DRV_STATUS, bool, s2ga)
GET_REG(TMC2041Stepper, DRV_STATUS, bool, otpw)
GET_REG(TMC2041Stepper, DRV_STATUS, bool, ot)
GET_REG(TMC2041Stepper, DRV_STATUS, uint8_t, cs_actual)
GET_REG(TMC2041Stepper, DRV_STATUS, uint16_t, sg_result)

inline bool TMC2041Stepper::stallguard(uint8_t i) { return stst(i); }



