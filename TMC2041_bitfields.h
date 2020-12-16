//#pragma once
#pragma pack(push, 1)

struct GCONF_t {
    constexpr static uint8_t address = 0x00;
    union {
        uint16_t sr : 11;
        struct {
            bool  single_driver : 1, 
            stepdir1_en : 1, 
            stepdir2_en : 1;
            uint8_t     : 4; 
            bool test_mode : 1,
            shaft1_rev : 1,
            shaft2_rev : 1,
            lock_gconf : 1;
        };
    };
};

struct GSTAT_t {
    constexpr static uint8_t address = 0x01;
    union {
        uint8_t sr : 4;
        struct {
        bool  reset : 1,
                drv1_err : 1,
                drv2_err : 1,
                uv_cp : 1;
        };
    };
};

struct IHOLD_IRUN_t {
    constexpr static uint8_t address[2] = {0x30,0x50};
    union {
        uint32_t sr : 20;
        struct {
        uint8_t ihold : 5,
                        : 3,
                irun : 5,
                    : 3,
                iholddelay : 4;
        };
    };
};

struct MSCNT_t { 
    constexpr static uint8_t address[2] = {0x6A,0x7A}; 
    union {
        uint16_t sr : 10;
        uint16_t mscnt : 10;
    };
};

struct MSCURACT_t {
    constexpr static uint8_t address[2] = {0x6B,0x7B};
    union {
        uint32_t sr : 25;
        struct {
        int16_t cur_a : 9,
                        : 7,
                cur_b : 9;
        };
    };
};

struct CHOPCONF_t {
    constexpr static uint8_t address[2] = {0x6C,0x7C};
    union {
        uint32_t sr : 32;
        struct {
            uint8_t toff : 4,
                    hstrt : 3,
                    hend : 4,
                    fd3 : 1;
            bool    disfdcc : 1,
                    rndtf : 1,
                    chm : 1;
            uint8_t tbl : 2;
            bool    vsense : 1;
            uint8_t :6,
                    mres : 4;
            bool    intpol : 1,
                    dedge : 1,
                    diss2g : 1;
        };
    };
};

struct COOLCONF_t {
    constexpr static uint8_t address[2] = {0x6D,0x7D};
    union {
        uint32_t sr : 25;
        struct {
            uint8_t semin : 4,
                            : 1,
                    seup : 2,
                            : 1,
                    semax : 4,
                            : 1,
                    sedn : 2;
            bool    seimin : 1;
            int8_t  sgt : 7,
                        : 1;
            bool    sfilt : 1;
        };
    };
};



struct DRV_STATUS_t {
    constexpr static uint8_t address[2] = {0x6F,0x7F};
    union {
        uint32_t sr;
        struct {
            uint16_t sg_result : 10;
            uint8_t            : 6;
            uint8_t cs_actual : 5,
                            : 3;
            bool  stallguard : 1,
                ot : 1,
                otpw : 1,
                s2ga : 1,
                s2gb : 1,
                ola : 1,
                olb : 1,
                stst : 1;
        };
    };
};

struct SLAVECONF_t {
constexpr static uint8_t address = 0x03;
    union {
        uint16_t sr : 12;
        struct {
        uint8_t slaveaddr : 8;
        uint8_t senddelay : 4;
        };
    };
};

struct IOOUT_t {
    constexpr static uint8_t address = 0x04;
    union {
        bool sr : 8;
        struct {
            bool io0_out : 1,
            io1_out : 1,
            io2_out : 1,
                    : 1,
            ioddr0 : 1,
            ioddr2 : 1,
            ioddr3 : 1,
                    : 1;
        };
    };
};

struct IOIN_t {
    constexpr static uint8_t address = 0x04;
    union {
        uint32_t sr : 17;
        struct {
            bool  io0_in : 1,
                io1_in : 1,
                io2_in : 1,
                io3_in : 1,
                iop_in : 1,
                ion_in : 1,
                nextaddr_in : 1,
                drv_enn_in : 1,
                sw_comp_in : 1;
                uint8_t version : 8;
        };
    };
};



struct IFCNT_t {
    constexpr static uint8_t address = 0x02;
    union {
        uint8_t sr;
        uint8_t ifcnt;
    };   
};

