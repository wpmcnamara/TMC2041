#include "TMCStepper.h"
#include "TMC_MACROS.h"


#define SET_REG(SETTING) GCONF_register.SETTING = B; write(GCONF_register.address, GCONF_register.sr)



// GCONF
uint32_t TMC2041Stepper::GCONF() {
	return read(GCONF_register.address);
}
void TMC2041Stepper::GCONF(uint32_t input) {
	GCONF_register.sr = input;
	write(GCONF_register.address, GCONF_register.sr);
}



void TMC2041Stepper::single_driver(bool B) { SET_REG(single_driver);};
void TMC2041Stepper::stepdir1_en(bool B) { SET_REG(stepdir1_en);};
void TMC2041Stepper::stepdir2_en(bool B) { SET_REG(stepdir2_en);};
void TMC2041Stepper::test_mode(bool B) { SET_REG(test_mode);};
void TMC2041Stepper::shaft1_rev(bool B) { SET_REG(shaft1_rev);};
void TMC2041Stepper::shaft2_rev(bool B) { SET_REG(shaft2_rev);};
void TMC2041Stepper::lock_gconf(bool B) { SET_REG(lock_gconf);};


bool TMC2041Stepper::single_driver() { GCONF_t r{0}; r.sr = GCONF(); return r.single_driver;		}
bool TMC2041Stepper::stepdir1_en() { GCONF_t r{0}; r.sr = GCONF(); return r.stepdir1_en;		}
bool TMC2041Stepper::stepdir2_en() { GCONF_t r{0}; r.sr = GCONF(); return r.stepdir2_en;		}
bool TMC2041Stepper::test_mode() { GCONF_t r{0}; r.sr = GCONF(); return r.test_mode;		}
bool TMC2041Stepper::shaft1_rev() { GCONF_t r{0}; r.sr = GCONF(); return r.shaft1_rev;		}
bool TMC2041Stepper::shaft2_rev() { GCONF_t r{0}; r.sr = GCONF(); return r.shaft2_rev;		}
bool TMC2041Stepper::lock_gconf() { GCONF_t r{0}; r.sr = GCONF(); return r.lock_gconf;		}

