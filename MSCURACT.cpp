#include "TMC2041.h"

constexpr uint8_t MSCURACT_reg_set::address[];

GET_REG_GROUP(TMC2041, MSCURACT)

GET_REG(TMC2041, MSCURACT, uint16_t, cur_b)
GET_REG(TMC2041, MSCURACT, uint16_t, cur_a)
