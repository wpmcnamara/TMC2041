#include "TMCStepper.h"
#include "TMC_MACROS.h"

constexpr uint8_t DRV_STATUS_t::address[];

// DRV_STATUS
uint32_t TMC2041Stepper::DRV_STATUS(uint8_t motor) {  return read(DRV_STATUS_register.address[motor]); }

bool 	TMC2041Stepper::stst(uint8_t motor)		{ DRV_STATUS_t r{0}; r.sr = DRV_STATUS(motor); return r.stst;	}
bool 	TMC2041Stepper::olb(uint8_t motor)		{ DRV_STATUS_t r{0}; r.sr = DRV_STATUS(motor); return r.olb;	}
bool 	TMC2041Stepper::ola(uint8_t motor)		{ DRV_STATUS_t r{0}; r.sr = DRV_STATUS(motor); return r.ola;	}
bool 	TMC2041Stepper::s2gb(uint8_t motor)		{ DRV_STATUS_t r{0}; r.sr = DRV_STATUS(motor); return r.s2gb;	}
bool 	TMC2041Stepper::s2ga(uint8_t motor)		{ DRV_STATUS_t r{0}; r.sr = DRV_STATUS(motor); return r.s2ga;		}
bool 	TMC2041Stepper::otpw(uint8_t motor)		{ DRV_STATUS_t r{0}; r.sr = DRV_STATUS(motor); return r.otpw;	}
bool 	TMC2041Stepper::ot(uint8_t motor)		{ DRV_STATUS_t r{0}; r.sr = DRV_STATUS(motor); return r.ot;		}
bool 	TMC2041Stepper::stallguard(uint8_t motor)		{ DRV_STATUS_t r{0}; r.sr = DRV_STATUS(motor); return r.stst;	}
uint8_t TMC2041Stepper::cs_actual(uint8_t motor)		{ DRV_STATUS_t r{0}; r.sr = DRV_STATUS(motor); return r.cs_actual;	}
uint16_t TMC2041Stepper::sg_result(uint8_t motor)		{ DRV_STATUS_t r{0}; r.sr = DRV_STATUS(motor); return r.sg_result;	}



