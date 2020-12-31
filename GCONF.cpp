#include "TMC2041.h"

constexpr uint8_t GCONF_reg_set::address[];

// GCONF
SET_REG_GROUP(TMC2041, GCONF)
GET_REG_GROUP(TMC2041, GCONF)

SET_REG(TMC2041, GCONF, bool, single_driver)
SET_REG(TMC2041, GCONF, bool, stepdir1_en)
SET_REG(TMC2041, GCONF, bool, stepdir2_en)
SET_REG(TMC2041, GCONF, bool, test_mode)
SET_REG(TMC2041, GCONF, bool, shaft1_rev)
SET_REG(TMC2041, GCONF, bool, shaft2_rev)
SET_REG(TMC2041, GCONF, bool, lock_gconf)

GET_REG(TMC2041, GCONF, bool, single_driver)
GET_REG(TMC2041, GCONF, bool, stepdir1_en)
GET_REG(TMC2041, GCONF, bool, stepdir2_en)
GET_REG(TMC2041, GCONF, bool, test_mode)
GET_REG(TMC2041, GCONF, bool, shaft1_rev)
GET_REG(TMC2041, GCONF, bool, shaft2_rev)
GET_REG(TMC2041, GCONF, bool, lock_gconf)
