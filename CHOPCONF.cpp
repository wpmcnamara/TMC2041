#include "TMCStepper.h"
#include "TMC_MACROS.h"

#define SET_REG(SETTING) CHOPCONF_register.SETTING = B; write(CHOPCONF_register.address[M], CHOPCONF_register.sr)

// CHOPCONF
uint32_t TMC2041Stepper::CHOPCONF(uint8_t motor) {
	return read(CHOPCONF_register.address[motor]);
}
void TMC2041Stepper::CHOPCONF(uint8_t motor, uint32_t input) {
	CHOPCONF_register.sr = input;
	write(CHOPCONF_register.address[motor], CHOPCONF_register.sr);
}
void TMC2041Stepper::toff(		uint8_t M, uint8_t B )	{ SET_REG(toff);	}
void TMC2041Stepper::hstrt(		uint8_t M, uint8_t B )	{ SET_REG(hstrt);	}
void TMC2041Stepper::hend(		uint8_t M, uint8_t B )	{ SET_REG(hend);	}
void TMC2041Stepper::fd3(		uint8_t M, uint8_t B )	{ SET_REG(fd3);		}
void TMC2041Stepper::disfdcc(	uint8_t M, bool 	B )	{ SET_REG(disfdcc);	}
void TMC2041Stepper::rndtf(		uint8_t M, bool 	B )	{ SET_REG(rndtf);	}
void TMC2041Stepper::chm(		uint8_t M, bool 	B )	{ SET_REG(chm);		}
void TMC2041Stepper::tbl(		uint8_t M, uint8_t B )	{ SET_REG(tbl);		}
void TMC2041Stepper::vsense(	uint8_t M, bool 	B )	{ SET_REG(vsense);	}
void TMC2041Stepper::mres(		uint8_t M, uint8_t B )	{ SET_REG(mres);	}
void TMC2041Stepper::intpol16(	uint8_t M, bool 	B )	{ SET_REG(intpol);	}
void TMC2041Stepper::dedge(		uint8_t M, bool 	B )	{ SET_REG(dedge);	}
void TMC2041Stepper::diss2g(	uint8_t M, bool 	B )	{ SET_REG(diss2g);	}

uint8_t TMC2041Stepper::toff(uint8_t motor)		{ CHOPCONF_t r{0}; r.sr = CHOPCONF(motor); return r.toff;	}
uint8_t TMC2041Stepper::hstrt(uint8_t motor)		{ CHOPCONF_t r{0}; r.sr = CHOPCONF(motor); return r.hstrt;	}
uint8_t TMC2041Stepper::hend(uint8_t motor)		{ CHOPCONF_t r{0}; r.sr = CHOPCONF(motor); return r.hend;	}
uint8_t TMC2041Stepper::fd3(uint8_t motor)		{ CHOPCONF_t r{0}; r.sr = CHOPCONF(motor); return r.fd3;		}
bool 	TMC2041Stepper::disfdcc(uint8_t motor)	{ CHOPCONF_t r{0}; r.sr = CHOPCONF(motor); return r.disfdcc;	}
bool 	TMC2041Stepper::rndtf(uint8_t motor)		{ CHOPCONF_t r{0}; r.sr = CHOPCONF(motor); return r.rndtf;	}
bool 	TMC2041Stepper::chm(uint8_t motor)		{ CHOPCONF_t r{0}; r.sr = CHOPCONF(motor); return r.chm;		}
uint8_t TMC2041Stepper::tbl(uint8_t motor)		{ CHOPCONF_t r{0}; r.sr = CHOPCONF(motor); return r.tbl;		}
bool 	TMC2041Stepper::vsense(uint8_t motor)	{ CHOPCONF_t r{0}; r.sr = CHOPCONF(motor); return r.vsense;	}
uint8_t TMC2041Stepper::mres(uint8_t motor)		{ CHOPCONF_t r{0}; r.sr = CHOPCONF(motor); return r.mres;	}
bool 	TMC2041Stepper::intpol16(uint8_t motor)	{ CHOPCONF_t r{0}; r.sr = CHOPCONF(motor); return r.intpol;	}
bool 	TMC2041Stepper::dedge(uint8_t motor)		{ CHOPCONF_t r{0}; r.sr = CHOPCONF(motor); return r.dedge;	}
bool 	TMC2041Stepper::diss2g(uint8_t motor)	{ CHOPCONF_t r{0}; r.sr = CHOPCONF(motor); return r.diss2g;	}

