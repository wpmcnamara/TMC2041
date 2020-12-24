#include "TMCStepper.h"
#include "TMC_MACROS.h"


constexpr uint8_t GSTAT_reg_set::address[];

GET_REG_GROUP(TMC2041Stepper, GSTAT)

GET_REG(TMC2041Stepper, GSTAT, bool, reset)
GET_REG(TMC2041Stepper, GSTAT, bool, drv1_err)
GET_REG(TMC2041Stepper, GSTAT, bool, drv2_err)
GET_REG(TMC2041Stepper, GSTAT, bool, uv_cp)

inline bool TMC2041Stepper::reset()		    { return reset(0);      }
inline bool TMC2041Stepper::drv1_err()		{ return drv1_err(0);   }
inline bool TMC2041Stepper::drv2_err()		{ return drv2_err(0);   }
inline bool TMC2041Stepper::uv_cp()		    { return uv_cp(0);      }
