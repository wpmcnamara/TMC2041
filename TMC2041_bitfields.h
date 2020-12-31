#pragma once
#pragma pack(push, 1)

typedef struct GCONF_bits {
    bool    single_driver       : 1, 
            stepdir1_en         : 1, 
            stepdir2_en         : 1;
    uint8_t                     : 4; 
    bool    test_mode           : 1,
            shaft1_rev          : 1,
            shaft2_rev          : 1,
            lock_gconf          : 1;
} GCONF_bits_t;

typedef struct GSTAT_bits {
    bool    reset       : 1,
            drv1_err    : 1,
            drv2_err    : 1,
            uv_cp       : 1;
} GSTAT_bits_t;

typedef struct IHOLD_IRUN_bits {
    uint8_t ihold       : 5,
                        : 3,
            irun        : 5,
                        : 3,
            iholddelay  : 4;
} IHOLD_IRUN_bits_t;

typedef struct MSCNT_bits { 
    uint16_t mscnt : 10;
} MSCNT_bits_t;

typedef struct MSCURACT_bits {
    int16_t cur_a   : 9,
                    : 7,
            cur_b   : 9;
} MSCURACT_bits_t;

typedef struct CHOPCONF_bits {
    uint8_t toff    : 4,
            hstrt   : 3,
            hend    : 4,
            fd3     : 1;
    bool    disfdcc : 1,
            rndtf   : 1,
            chm     : 1;
    uint8_t tbl     : 2;
    bool    vsense  : 1;
    uint8_t         : 6,
            mres    : 4;
    bool    intpol  : 1,
            dedge   : 1,
            diss2g  : 1;
} CHOPCONF_bits_t;



typedef struct COOLCONF_bits {
    uint8_t semin   : 4,
                    : 1,
            seup    : 2,
                    : 1,
            semax   : 4,
                    : 1,
            sedn    : 2;
    bool    seimin  : 1;
    int8_t  sgt     : 7,
                    : 1;
    bool    sfilt   : 1;
} COOLCONF_bits_t;



typedef struct DRV_STATUS_bits {
    uint16_t sg_result  : 10;
    uint8_t             : 6;
    uint8_t cs_actual   : 5,
                        : 3;
    bool    stallguard  : 1,
            ot          : 1,
            otpw        : 1,
            s2ga        : 1,
            s2gb        : 1,
            ola         : 1,
            olb         : 1,
            stst        : 1;
} DRV_STATUS_bits_t;

typedef struct SLAVECONF_bits {
    uint8_t slaveaddr : 8;
    uint8_t senddelay : 4;
} SLAVECONF_bits_t;

typedef struct IOOUT_bits {
    bool    io0_out : 1,
            io1_out : 1,
            io2_out : 1,
                    : 1,
            ioaddr0  : 1,
            ioaddr1  : 1,
            ioaddr2  : 1,
                    : 1;
} IOOUT_bits_t;

typedef struct IOIN_bits {
    bool    io0_in      : 1,
            io1_in      : 1,
            io2_in      : 1,
            io3_in      : 1,
            iop_in      : 1,
            ion_in      : 1,
            nextaddr_in : 1,
            drv_enn_in  : 1,
            sw_comp_in  : 1;
    uint8_t version     : 8;
} IOIN_bits_t;



typedef struct IFCNT_bits {
    uint8_t ifcnt; 
} IFCNT_bits_t;

