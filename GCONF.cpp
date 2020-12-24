#include "TMCStepper.h"
#include "TMC_MACROS.h"

constexpr uint8_t GCONF_reg_set::address[];

// GCONF
SET_REG_GROUP(TMC2041Stepper, GCONF)
GET_REG_GROUP(TMC2041Stepper, GCONF)

SET_REG(TMC2041Stepper, GCONF, bool, single_driver)
SET_REG(TMC2041Stepper, GCONF, bool, stepdir1_en)
SET_REG(TMC2041Stepper, GCONF, bool, stepdir2_en)
SET_REG(TMC2041Stepper, GCONF, bool, test_mode)
SET_REG(TMC2041Stepper, GCONF, bool, shaft1_rev)
SET_REG(TMC2041Stepper, GCONF, bool, shaft2_rev)
SET_REG(TMC2041Stepper, GCONF, bool, lock_gconf)

GET_REG(TMC2041Stepper, GCONF, bool, single_driver)
GET_REG(TMC2041Stepper, GCONF, bool, stepdir1_en)
GET_REG(TMC2041Stepper, GCONF, bool, stepdir2_en)
GET_REG(TMC2041Stepper, GCONF, bool, test_mode)
GET_REG(TMC2041Stepper, GCONF, bool, shaft1_rev)
GET_REG(TMC2041Stepper, GCONF, bool, shaft2_rev)
GET_REG(TMC2041Stepper, GCONF, bool, lock_gconf)


inline void TMC2041Stepper::single_driver(bool v) 	{ single_driver(0, v);	}
inline void TMC2041Stepper::stepdir1_en(bool v) 	{ stepdir1_en(0, v); 	}
inline void TMC2041Stepper::stepdir2_en(bool v) 	{ stepdir2_en(0, v); 	}
inline void TMC2041Stepper::test_mode(bool v) 		{ test_mode(0, v);		}
inline void TMC2041Stepper::shaft1_rev(bool v) 		{ shaft1_rev(0, v);		}
inline void TMC2041Stepper::shaft2_rev(bool v)	 	{ shaft2_rev(0, v);		}
inline void TMC2041Stepper::lock_gconf(bool v)	 	{ lock_gconf(0, v);		}

inline bool TMC2041Stepper::single_driver()		{ return single_driver(0); 	}
inline bool TMC2041Stepper::stepdir1_en() 		{ return stepdir1_en(0); 	}
inline bool TMC2041Stepper::stepdir2_en() 		{ return stepdir2_en(0); 	}
inline bool TMC2041Stepper::test_mode() 		{ return test_mode(0); 		}
inline bool TMC2041Stepper::shaft1_rev() 		{ return shaft1_rev(0); 	}
inline bool TMC2041Stepper::shaft2_rev() 		{ return shaft2_rev(0); 	}
inline bool TMC2041Stepper::lock_gconf() 		{ return lock_gconf(0); 	}

