#include "TMC2041.h"

constexpr uint8_t GSTAT_reg_set::address[];

GET_REG_GROUP(TMC2041, GSTAT)

GET_REG(TMC2041, GSTAT, bool, reset)
GET_REG(TMC2041, GSTAT, bool, drv1_err)
GET_REG(TMC2041, GSTAT, bool, drv2_err)
GET_REG(TMC2041, GSTAT, bool, uv_cp)