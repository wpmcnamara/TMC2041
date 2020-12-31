#include "TMC2041.h"

constexpr uint8_t IOIN_reg_set::address[];

GET_REG_GROUP(TMC2041, IOIN)

GET_REG(TMC2041, IOIN, bool, io0_in)
GET_REG(TMC2041, IOIN, bool, io1_in)
GET_REG(TMC2041, IOIN, bool, io2_in)
GET_REG(TMC2041, IOIN, bool, io3_in)
GET_REG(TMC2041, IOIN, bool, iop_in)
GET_REG(TMC2041, IOIN, bool, ion_in)
GET_REG(TMC2041, IOIN, bool, nextaddr_in)
GET_REG(TMC2041, IOIN, bool, drv_enn_in)
GET_REG(TMC2041, IOIN, bool, sw_comp_in)
GET_REG(TMC2041, IOIN, uint8_t, version)