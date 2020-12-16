#include "TMCStepper.h"
#include "TMC_MACROS.h"


// GSTAT
uint32_t TMC2041Stepper::GSTAT() {
	return read(GSTAT_register.address);
}



bool TMC2041Stepper::reset() { GSTAT_t r{0}; r.sr = GSTAT(); return r.reset;		}
bool TMC2041Stepper::drv1_err() { GSTAT_t r{0}; r.sr = GSTAT(); return r.drv1_err;		}
bool TMC2041Stepper::drv2_err() { GSTAT_t r{0}; r.sr = GSTAT(); return r.drv2_err;		}
bool TMC2041Stepper::uv_cp() { GSTAT_t r{0}; r.sr = GSTAT(); return r.uv_cp;		}
