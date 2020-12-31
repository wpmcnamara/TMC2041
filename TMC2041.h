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


class TMC2041 {
	public:
		TMC2041(uint16_t pinCS, float RS = default_RS, int8_t link_index = -1);

		void begin();
		void defaults();
		void setSPISpeed(uint32_t speed);
		void switchCSpin(bool state);
		bool isEnabled();
		void push();

        void microsteps(uint8_t index, uint16_t ms) ;
        uint16_t cs2rms(uint8_t index,uint8_t CS);
        void rms_current(uint8_t index,uint16_t mA);
        void rms_current(uint8_t index,uint16_t mA, float mult);
        uint16_t rms_current(uint8_t index);

		// RW: GCONF
		SET_REG_GROUP_DEF(GCONF)
		GET_REG_GROUP_DEF(GCONF)

		SET_REG_DEF(bool, single_driver)
		SET_REG_DEF(bool, stepdir1_en)
		SET_REG_DEF(bool, stepdir2_en)
		SET_REG_DEF(bool, test_mode)
		SET_REG_DEF(bool, shaft1_rev)
		SET_REG_DEF(bool, shaft2_rev)
		SET_REG_DEF(bool, lock_gconf)

		GET_REG_DEF(bool, single_driver)
		GET_REG_DEF(bool, stepdir1_en)
		GET_REG_DEF(bool, stepdir2_en)
		GET_REG_DEF(bool, test_mode)
		GET_REG_DEF(bool, shaft1_rev)
		GET_REG_DEF(bool, shaft2_rev)
		GET_REG_DEF(bool, lock_gconf)

		// R+C: GSTAT
		GET_REG_GROUP_DEF(GSTAT)

        GET_REG_DEF(bool, reset)
		GET_REG_DEF(bool, drv1_err)
		GET_REG_DEF(bool, drv2_err)
		GET_REG_DEF(bool, uv_cp)

		// R: IFCNT
        GET_REG_GROUP_DEF(IFCNT)

        GET_REG_DEF(uint8_t, ifcnt)

		// W: SLAVECONF
        SET_REG_GROUP_DEF(SLAVECONF)
        GET_SHADOW_REG_GROUP_DEF(SLAVECONF)

        SET_REG_DEF(uint8_t, slaveaddr)
        SET_REG_DEF(uint8_t, senddelay)
        GET_SHADOW_REG_DEF(uint8_t, slaveaddr)
        GET_SHADOW_REG_DEF(uint8_t, senddelay)

		// R: IOIN
        GET_REG_GROUP_DEF(IOIN)

        GET_REG_DEF(bool, io0_in)
        GET_REG_DEF(bool, io1_in)
        GET_REG_DEF(bool, io2_in)
        GET_REG_DEF(bool, io3_in)
        GET_REG_DEF(bool, iop_in)
        GET_REG_DEF(bool, ion_in)
        GET_REG_DEF(bool, nextaddr_in)
        GET_REG_DEF(bool, drv_enn_in)
        GET_REG_DEF(bool, sw_comp_in)
        GET_REG_DEF(uint8_t, version)        

		//W: IOOUT
        SET_REG_GROUP_DEF(IOOUT)
        GET_SHADOW_REG_GROUP_DEF(IOOUT)

        SET_REG_DEF(bool, io0_out)
        SET_REG_DEF(bool, io1_out)
        SET_REG_DEF(bool, io2_out)
        SET_REG_DEF(bool, ioaddr0)
        SET_REG_DEF(bool, ioaddr1)
        SET_REG_DEF(bool, ioaddr2)

        GET_SHADOW_REG_DEF(bool, io0_out)
        GET_SHADOW_REG_DEF(bool, io1_out)
        GET_SHADOW_REG_DEF(bool, io2_out)
        GET_SHADOW_REG_DEF(bool, ioaddr0)
        GET_SHADOW_REG_DEF(bool, ioaddr1)
        GET_SHADOW_REG_DEF(bool, ioaddr2)        

        // W: IHOLD_IRUN
        SET_REG_GROUP_DEF(IHOLD_IRUN)
        GET_SHADOW_REG_GROUP_DEF(IHOLD_IRUN)

        SET_REG_DEF(uint8_t, ihold)
        SET_REG_DEF(uint8_t, irun)
        SET_REG_DEF(uint8_t, iholddelay)

        GET_SHADOW_REG_DEF(uint8_t, ihold)
        GET_SHADOW_REG_DEF(uint8_t, irun)
        GET_SHADOW_REG_DEF(uint8_t, iholddelay)

		// R: MSCNT
        GET_REG_GROUP_DEF(MSCNT)

        GET_REG_DEF(uint16_t, mscnt)

		// R: MSCURACT
        GET_REG_GROUP_DEF(MSCURACT)

        GET_REG_DEF(uint16_t, cur_b)
        GET_REG_DEF(uint16_t, cur_a)

		// RW: CHOPCONF
        SET_REG_GROUP_DEF(CHOPCONF)
        GET_REG_GROUP_DEF(CHOPCONF)

        SET_REG_DEF(uint8_t, toff)
        SET_REG_DEF(uint8_t, hstrt)
        SET_REG_DEF(uint8_t, hend)
        SET_REG_DEF(uint8_t, fd3)
        SET_REG_DEF(bool, disfdcc)
        SET_REG_DEF(bool, rndtf)
        SET_REG_DEF(bool, chm)
        SET_REG_DEF(uint8_t, tbl)
        SET_REG_DEF(bool, vsense)
        SET_REG_DEF(uint8_t, mres)
        SET_REG_DEF(bool, intpol)
        SET_REG_DEF(bool, dedge)
        SET_REG_DEF(bool, diss2g)

        GET_REG_DEF(uint8_t, toff)
        GET_REG_DEF(uint8_t, hstrt)
        GET_REG_DEF(uint8_t, hend)
        GET_REG_DEF(uint8_t, fd3)
        GET_REG_DEF(bool, disfdcc)
        GET_REG_DEF(bool, rndtf)
        GET_REG_DEF(bool, chm)
        GET_REG_DEF(uint8_t, tbl)
        GET_REG_DEF(bool, vsense)
        GET_REG_DEF(uint8_t, mres)
        GET_REG_DEF(bool, intpol)
        GET_REG_DEF(bool, dedge)
        GET_REG_DEF(bool, diss2g)

		// W: COOLCONF
        SET_REG_GROUP_DEF(COOLCONF)
        GET_SHADOW_REG_GROUP_DEF(COOLCONF)

        SET_REG_DEF(uint8_t, semin)
        SET_REG_DEF(uint8_t, seup)
        SET_REG_DEF(uint8_t, semax)
        SET_REG_DEF(uint8_t, sedn)
        SET_REG_DEF(bool, seimin)
        SET_REG_DEF(uint8_t, sgt)
        SET_REG_DEF(bool, sfilt)

        GET_SHADOW_REG_DEF(uint8_t, semin)
        GET_SHADOW_REG_DEF(uint8_t, seup)
        GET_SHADOW_REG_DEF(uint8_t, semax)
        GET_SHADOW_REG_DEF(uint8_t, sedn)
        GET_SHADOW_REG_DEF(bool, seimin)
        GET_SHADOW_REG_DEF(uint8_t, sgt)
        GET_SHADOW_REG_DEF(bool, sfilt)

		// R: DRV_STATUS
        GET_REG_GROUP_DEF(DRV_STATUS)

        GET_REG_DEF(bool, stst)
        GET_REG_DEF(bool, olb)
        GET_REG_DEF(bool, ola)
        GET_REG_DEF(bool, s2gb)
        GET_REG_DEF(bool, s2ga)
        GET_REG_DEF(bool, otpw)
        GET_REG_DEF(bool, ot)
        GET_REG_DEF(uint8_t, cs_actual)
        GET_REG_DEF(uint16_t, sg_result)

        inline bool stallguard(uint8_t i) { return stst(i); }   
        int16_t cur_a_scaled(uint8_t index);
        int16_t cur_b_scaled(uint8_t index);

	protected:
		void beginTransaction();
		void endTransaction();
		uint8_t transfer(const uint8_t data);
		void transferEmptyBytes(const uint8_t n);
		void write(uint8_t addressByte, uint32_t config);
		uint32_t read(uint8_t addressByte);

		static uint32_t spi_speed; // Default 2MHz
		static constexpr float default_RS = 0.11;

		int8_t link_index;
		static int8_t chain_length;
	private:
        float holdMultiplier;
        uint8_t status_response;
		static constexpr uint8_t TMC_READ = 0x00,
                                 TMC_WRITE = 0x80;
        const float Rsense;
        const uint16_t _pinCS;

		INIT_REGISTER(GCONF);		
		INIT_REGISTER(GSTAT);
        INIT_REGISTER(IFCNT);
		INIT_REGISTER(SLAVECONF);	
        INIT_REGISTER(IOIN);
		INIT_REGISTER(IOOUT);	
        INIT_REGISTER_PAIR(IHOLD_IRUN);	
        INIT_REGISTER_PAIR(MSCNT);
        INIT_REGISTER_PAIR(MSCURACT);	
		INIT_REGISTER_PAIR(CHOPCONF);	
		INIT_REGISTER_PAIR(COOLCONF);	
		INIT_REGISTER_PAIR(DRV_STATUS);		

};


