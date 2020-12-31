#pragma once
#pragma pack(push, 1)
#include <TMC2041_bitfields.h>

#define INIT_REGISTER(R) R##_reg_set_t R##_register = R##_reg_set_t{0}
#define INIT_REGISTER_PAIR(R) R##_reg_set_t R##_register = R##_reg_set_t{0,0}

#define SET_REG_DEF(TYPE, BITFIELD) void BITFIELD(uint8_t i, TYPE v);
#define GET_REG_DEF(TYPE, BITFIELD) TYPE BITFIELD(uint8_t i);
#define GET_SHADOW_REG_DEF(TYPE, BITFIELD) TYPE BITFIELD(uint8_t i);

#define SET_REG_GROUP_DEF(REG) void REG(uint8_t index, uint32_t value); 
#define GET_REG_GROUP_DEF(REG) uint32_t REG(uint8_t index);
#define GET_SHADOW_REG_GROUP_DEF(REG) uint32_t REG(uint8_t index);

#define SET_REG(CLASS, REG, TYPE, BITFIELD) void CLASS::BITFIELD(uint8_t i, TYPE v) { \
    REG##_register.reg[i].reg.BITFIELD = v; \
    write(REG##_reg_set::address[i], REG##_register.reg[i].sr); \
    }

#define GET_REG(CLASS, REG, TYPE, BITFIELD) TYPE CLASS::BITFIELD(uint8_t i) { \
    REG##_register.reg[i].sr=read(REG##_register.address[i]); \
    return REG##_register.reg[i].reg.BITFIELD; \
    }

#define GET_SHADOW_REG(CLASS, REG, TYPE, BITFIELD) TYPE CLASS::BITFIELD(uint8_t i) { \
    return REG##_register.reg[i].reg.BITFIELD; \
    }

#define SET_REG_GROUP(CLASS, REG) void CLASS::REG(uint8_t index, uint32_t value) { \
    REG##_register.reg[index].sr = value; \
    write(REG##_register.address[index], \
    REG##_register.reg[index].sr); \
    }

#define GET_REG_GROUP(CLASS, REG) uint32_t CLASS::REG(uint8_t index) { \
    REG##_register.reg[index].sr=read(REG##_register.address[index]); \
    return REG##_register.reg[index].sr; \
    }

#define GET_SHADOW_REG_GROUP(CLASS, REG) uint32_t CLASS::REG(uint8_t index) { \
    return REG##_register.reg[index].sr; \
    }

typedef union GCONF_reg {
    uint16_t sr : 11;
    GCONF_bits_t reg;
} GCONF_reg_t;

typedef struct GCONF_reg_set {
    constexpr static uint8_t address[1] = {0x00};
    GCONF_reg_t reg[1];
} GCONF_reg_set_t;

typedef union GSTAT_reg {
    uint8_t sr : 4;
    GSTAT_bits_t reg;
} GSTAT_reg_t;

typedef struct GSTAT_reg_set {
    constexpr static uint8_t address[1] = {0x01};
    GSTAT_reg_t reg[1];
} GSTAT_reg_set_t;

typedef union IHOLD_IRUN_reg {
    uint32_t sr : 20;
    IHOLD_IRUN_bits_t reg;
} IHOLD_IRUN_reg_t;

typedef struct IHOLD_IRUN_reg_set {
    constexpr static uint8_t address[2] = {0x30,0x50};
    IHOLD_IRUN_reg_t reg[2];
} IHOLD_IRUN_reg_set_t;

typedef union MSCNT_reg {
    uint16_t sr : 10;
    MSCNT_bits_t reg;
} MSCNT_reg_t;

typedef struct MSCNT_reg_set { 
    constexpr static uint8_t address[2] = {0x6A,0x7A}; 
    MSCNT_reg_t reg[2];
} MSCNT_reg_set_t;

typedef union MSCURACT_reg {
    uint32_t sr : 25;
    MSCURACT_bits_t reg;   
} MSCURACT_reg_t;

typedef struct MSCURACT_reg_set {
    constexpr static uint8_t address[2] = {0x6B,0x7B};
    MSCURACT_reg_t reg[2];
} MSCURACT_reg_set_t;

typedef union CHOPCONF_reg {
    uint32_t sr : 32;
    CHOPCONF_bits_t reg;    
} CHOPCONF_reg_t;

typedef struct CHOPCONF_reg_set {
    constexpr static uint8_t address[2] = {0x6C,0x7C};
    CHOPCONF_reg_t reg[2];
} CHOPCONF_reg_set_t;

typedef union COOLCONF_reg {
    uint32_t sr : 25;   
    COOLCONF_bits_t reg;
} COOLCONF_reg_t;

typedef struct COOLCONF_reg_set {
    constexpr static uint8_t address[2] = {0x6D,0x7D};
    COOLCONF_reg_t reg[2];
} COOLCONF_reg_set_t;

typedef union DRV_STATUS_reg {
    int32_t sr;   
    DRV_STATUS_bits_t reg;
} DRV_STATUS_reg_t;

typedef struct DRV_STATUS_reg_set {
    constexpr static uint8_t address[2] = {0x6F,0x7F};
    DRV_STATUS_reg_t reg[2];
} DRV_STATUS_reg_set_t;

typedef union SLAVECONF_reg {
    uint16_t sr : 12;
    SLAVECONF_bits_t reg;
} SLAVECONF_reg_t;

typedef struct SLAVECONF_reg_set {
    constexpr static uint8_t address[1] = {0x03};
    SLAVECONF_reg_t reg[1];
} SLAVECONF_reg_set_t;

typedef union IOOUT_reg {
    uint8_t sr : 8;
    IOOUT_bits_t reg;
} IOOUT_reg_t;

typedef struct IOOUT_reg_set {
    constexpr static uint8_t address[1] = {0x04};
    IOOUT_reg_t reg[1];
} IOOUT_reg_set_t;

typedef union IOIN_reg {
    uint32_t sr : 17;
    IOIN_bits_t reg;
} IOIN_reg_t;

typedef struct IOIN_reg_set {
    constexpr static uint8_t address[1] = {0x04};
    IOIN_reg_t reg[1];
} IOIN_reg_set_t;

typedef union IFCNT_reg {
    uint8_t sr;
    IFCNT_bits_t reg;
} IFCNT_reg_t;

typedef struct IFCNT_reg_set {
    constexpr static uint8_t address[1] = {0x02};
    IFCNT_reg_t reg[1];
} IFCNT_reg_set_t;

