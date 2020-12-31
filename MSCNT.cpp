#include "TMC2041.h"

constexpr uint8_t MSCNT_reg_set::address[];

GET_REG_GROUP(TMC2041, MSCNT)

GET_REG(TMC2041, MSCNT, uint16_t, mscnt)