#include "TMC2041.h"

constexpr uint8_t IFCNT_reg_set::address[];

GET_REG_GROUP(TMC2041, IFCNT)

GET_REG(TMC2041, IFCNT, uint8_t, ifcnt)