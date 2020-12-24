#pragma once

//#define TMCDEBUG

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-function"
#pragma GCC diagnostic ignored "-Wunused-variable"

#if defined(ARDUINO) && ARDUINO >= 100
	#include <Arduino.h>
#endif

#include <Stream.h>
#include <SPI.h>


#pragma GCC diagnostic pop

#include "TMC2041_registers.h"

//#define INIT_REGISTER(REG) REG##_t REG##_register = REG##_t
#define SET_ALIAS(TYPE, DRIVER, NEW, ARG, OLD) TYPE (DRIVER::*NEW)(ARG) = &DRIVER::OLD

#define TMCSTEPPER_VERSION 0x000701 // v0.7.1

class TMCStepper {
	public:
		uint16_t cs2rms(uint8_t motor, uint8_t CS);
		void rms_current(uint8_t motor, uint16_t mA);
		void rms_current(uint8_t motor, uint16_t mA, float mult);
		uint16_t rms_current(uint8_t motor);
		void hold_multiplier(float val) { holdMultiplier = val; }
		float hold_multiplier() { return holdMultiplier; }
		uint8_t test_connection();

		// Helper functions
		void microsteps(uint8_t motor, uint16_t ms);
		uint16_t microsteps(uint8_t motor);
		void blank_time(uint8_t motor, uint8_t value);
		uint8_t blank_time(uint8_t motor);
		void hysteresis_end(uint8_t motor, int8_t value);
		int8_t hysteresis_end(uint8_t motor);
		void hysteresis_start(uint8_t motor, uint8_t value);
		uint8_t hysteresis_start(uint8_t motor);
		int16_t cur_a(uint8_t motor);
		int16_t cur_b(uint8_t motor);





	protected:
		TMCStepper(float RS) : Rsense(RS) {};

		static constexpr uint8_t TMC_READ = 0x00,TMC_WRITE = 0x80;

		virtual void write(uint8_t, uint32_t) = 0;
		virtual uint32_t read(uint8_t) = 0;

		virtual void ihold(uint8_t motor, uint8_t value);
		virtual void irun(uint8_t motor, uint8_t value);
		virtual uint8_t ihold(uint8_t motor);
		virtual uint8_t irun(uint8_t motor);
		virtual uint32_t DRV_STATUS(uint8_t motor);
		virtual uint8_t hend(uint8_t motor);
		virtual void hend(uint8_t motor, uint8_t value);
		virtual void hstrt(	uint8_t motor, uint8_t B);
		virtual uint8_t hstrt(uint8_t motor);
		virtual void mres(uint8_t motor, uint8_t B);
		virtual uint8_t mres(uint8_t motor);
		virtual void tbl(uint8_t motor,	uint8_t B);
		virtual uint8_t tbl(uint8_t motor);
		virtual void vsense(uint8_t, bool) = 0;
		virtual bool vsense(uint8_t) = 0;
		virtual uint32_t MSCURACT(uint8_t motor);

		INIT_REGISTER(GCONF);		
		INIT_REGISTER(GSTAT);
		INIT_REGISTER(SLAVECONF);		
		INIT_REGISTER(IOOUT);		
		INIT_REGISTER_PAIR(CHOPCONF);	
		INIT_REGISTER_PAIR(COOLCONF);	
		INIT_REGISTER_PAIR(DRV_STATUS);		
		INIT_REGISTER_PAIR(IHOLD_IRUN);	
		INIT_REGISTER_PAIR(MSCNT);
		INIT_REGISTER_PAIR(MSCURACT);

		const float Rsense;
		float holdMultiplier = 0.5;
};



class TMC2041Stepper : public TMCStepper {
	public:
		TMC2041Stepper(uint16_t pinCS, float RS = default_RS, int8_t link_index = -1);

		void begin();
		void defaults();
		void setSPISpeed(uint32_t speed);
		void switchCSpin(bool state);
		bool isEnabled();
		void push();

		// Helper functions
		void sg_current_decrease(uint8_t value);
		uint8_t sg_current_decrease();

		// RW: GCONF
		uint32_t GCONF();
		void GCONF(	uint32_t value);

		void single_driver ( bool B);
		void stepdir1_en ( bool B);
        void stepdir2_en ( bool B);
        void test_mode ( bool B);
        void shaft1_rev ( bool B);
        void shaft2_rev ( bool B);
        void lock_gconf ( bool B);

		bool single_driver ();
		bool stepdir1_en ();
        bool stepdir2_en ();
        bool test_mode ();
        bool shaft1_rev ();
        bool shaft2_rev ();
        bool lock_gconf ();

		// R+C: GSTAT
		uint32_t GSTAT();
		bool    reset();
		bool 	drv1_err();
		bool 	drv2_err();
		bool    uv_cp();		

		// R: IFCNT
		uint8_t IFCNT();

		// W: SLAVECONF
		void SLAVECONF(uint16_t input);
      	void slaveaddr (uint8_t input);
      	void senddelay (uint8_t input);

		// R: IOIN
		uint32_t IOIN();
		bool io0_in();
		bool io1_in();
		bool io2_in();
		bool io3_in();
		bool iop_in();
		bool ion_in();
		bool nextaddr_in();
		bool drv_enn_in();
		bool sw_comp_in();
		uint8_t version();

		//W: IOOUT
		void IOOUT (uint8_t);
		void io0_out(bool B);
		void io1_out(bool B);
		void io2_out(bool B);
		void ioddr0(bool B);
		void ioddr1(bool B);
		void ioddr2(bool B);

		// W: IHOLD_IRUN
		void IHOLD_IRUN(uint8_t motor, uint32_t input);
		uint8_t ihold(uint8_t motor);
		uint8_t irun(uint8_t motor);
		uint8_t iholddelay(uint8_t motor);
		void 	ihold(uint8_t motor, uint8_t B);
		void 	irun(uint8_t motor,	uint8_t B);
		void 	iholddelay(	uint8_t motor, uint8_t B);

		// R: MSCNT
		uint16_t MSCNT(uint8_t motor);

		// R: MSCURACT
		uint32_t MSCURACT(uint8_t motor);

		// RW: CHOPCONF
		uint32_t CHOPCONF(uint8_t motor);
		void CHOPCONF(uint8_t motor, uint32_t value);
		void toff(uint8_t motor, uint8_t B);
		void hstrt(	uint8_t motor, uint8_t B);
		void hend(uint8_t motor, uint8_t B);
		void fd3(uint8_t motor, uint8_t B);
		void disfdcc(	uint8_t motor, bool	B);
		void rndtf(uint8_t motor, bool B);
		void chm(uint8_t motor, bool B);
		void tbl(uint8_t motor,	uint8_t B);
		void vsense(uint8_t motor, bool B);
		void mres(uint8_t motor, uint8_t B);
		void intpol16(uint8_t motor, bool B);
		void dedge(uint8_t motor, bool B);
		void diss2g(uint8_t motor, bool B);

		uint8_t toff(uint8_t motor);
		uint8_t hstrt(uint8_t motor);
		uint8_t hend(uint8_t motor);
		uint8_t fd3(uint8_t motor);
		bool 	disfdcc(uint8_t motor);
		bool 	rndtf(uint8_t motor);
		bool 	chm(uint8_t motor);
		uint8_t tbl(uint8_t motor);
		bool 	vsense(uint8_t motor);
		uint8_t mres(uint8_t motor);
		bool 	intpol16(uint8_t motor);
		bool 	dedge(uint8_t motor);
		bool 	diss2g(uint8_t motor);

		// W: COOLCONF
		void COOLCONF(uint8_t, uint32_t value);
		uint32_t COOLCONF(uint8_t motor);
		void semin(uint8_t motor, uint8_t B);
		void seup(uint8_t motor, uint8_t B);
		void semax(uint8_t motor, uint8_t B);
		void sedn(uint8_t motor, uint8_t B);
		void seimin(uint8_t motor, bool B);
		void sgt(uint8_t motor, int8_t B);
		void sfilt(uint8_t motor, bool	B);

		// R: DRV_STATUS
		uint32_t DRV_STATUS(uint8_t motor);
		uint16_t sg_result(uint8_t motor);
		bool fsactive(uint8_t motor);
		uint8_t cs_actual(uint8_t motor);
		bool stallguard(uint8_t motor);
		bool ot(uint8_t motor);
		bool otpw(uint8_t motor);
		bool s2ga(uint8_t motor);
		bool s2gb(uint8_t motor);
		bool ola(uint8_t motor);
		bool olb(uint8_t motor);
		bool stst(uint8_t motor);

		// Function aliases
		uint8_t status_response;

	protected:
		void beginTransaction();
		void endTransaction();
		uint8_t transfer(const uint8_t data);
		void transferEmptyBytes(const uint8_t n);
		void write(uint8_t addressByte, uint32_t config);
		uint32_t read(uint8_t addressByte);

		INIT_REGISTER(GCONF);		
		INIT_REGISTER(GSTAT);
		INIT_REGISTER(SLAVECONF);		
		INIT_REGISTER(IOOUT);		
		INIT_REGISTER_PAIR(CHOPCONF);	
		INIT_REGISTER_PAIR(COOLCONF);	
		INIT_REGISTER_PAIR(DRV_STATUS);		
		INIT_REGISTER_PAIR(IHOLD_IRUN);	
		INIT_REGISTER_PAIR(MSCNT);
		INIT_REGISTER_PAIR(MSCURACT);




		static uint32_t spi_speed; // Default 2MHz
		const uint16_t _pinCS;
		static constexpr float default_RS = 0.11;

		int8_t link_index;
		static int8_t chain_length;
};


