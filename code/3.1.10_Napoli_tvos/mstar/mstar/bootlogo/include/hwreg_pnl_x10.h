////////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2008-2009 MStar Semiconductor, Inc.
// All rights reserved.
//
// Unless otherwise stipulated in writing, any and all information contained
// herein regardless in any format shall remain the sole proprietary of
// MStar Semiconductor Inc. and be kept in strict confidence
// ("MStar Confidential Information") by the recipient.
// Any unauthorized act including without limitation unauthorized diMODlosure,
// copying, use, reproduction, sale, distribution, modification, disassembling,
// reverse engineering and compiling of the contents of MStar Confidential
// Information is unlawful and strictly prohibited. MStar hereby reserves the
// rights to any and all damages, losses, costs and expenses resulting therefrom.
//
////////////////////////////////////////////////////////////////////////////////

#ifndef _HWREG_MOD_H_
#define _HWREG_MOD_H_

#include "SdMisc.h"

#define _PK_L_(bank, addr)   (((MS_U16)(bank) << 8) | (MS_U16)((addr)*2))
#define _PK_H_(bank, addr)   (((MS_U16)(bank) << 8) | (MS_U16)((addr)*2+1))

#define REG_TABLE_END      0xFFFF

//=============================================================
//----------------------------------------------
//  PANEL RELATED REGISTERS
//----------------------------------------------
#if defined (PRJ_X5) || defined(PRJ_X10) || defined(PRJ_X10P)
#define LPLL_LOOPGAIN                     16
#elif defined(PRJ_X9)
#define LPLL_LOOPGAIN                     32
#else
#define LPLL_LOOPGAIN                     8
#endif

#if defined(PRJ_X10)
#define REG_MOD_BASE                0x303200
#define REG_UTMI1_BASE              0x3A00 //0x103A00
#else
#define REG_MOD_BASE                0x3200 // 0x103200
#define REG_UTMI1_BASE              0x3A00 //0x103A00
#endif
//=============================================================
//----------------------------------------------
//  BK00: GOPINT
//----------------------------------------------
#define REG_MOD_BK00_00_L      _PK_L_(0x00, 0x00)
#define REG_MOD_BK00_00_H      _PK_H_(0x00, 0x00)
#define REG_MOD_BK00_01_L      _PK_L_(0x00, 0x01)
#define REG_MOD_BK00_01_H      _PK_H_(0x00, 0x01)
#define REG_MOD_BK00_02_L      _PK_L_(0x00, 0x02)
#define REG_MOD_BK00_02_H      _PK_H_(0x00, 0x02)
#define REG_MOD_BK00_03_L      _PK_L_(0x00, 0x03)
#define REG_MOD_BK00_03_H      _PK_H_(0x00, 0x03)
#define REG_MOD_BK00_04_L      _PK_L_(0x00, 0x04)
#define REG_MOD_BK00_04_H      _PK_H_(0x00, 0x04)
#define REG_MOD_BK00_05_L      _PK_L_(0x00, 0x05)
#define REG_MOD_BK00_05_H      _PK_H_(0x00, 0x05)
#define REG_MOD_BK00_06_L      _PK_L_(0x00, 0x06)
#define REG_MOD_BK00_06_H      _PK_H_(0x00, 0x06)
#define REG_MOD_BK00_07_L      _PK_L_(0x00, 0x07)
#define REG_MOD_BK00_07_H      _PK_H_(0x00, 0x07)
#define REG_MOD_BK00_08_L      _PK_L_(0x00, 0x08)
#define REG_MOD_BK00_08_H      _PK_H_(0x00, 0x08)
#define REG_MOD_BK00_09_L      _PK_L_(0x00, 0x09)
#define REG_MOD_BK00_09_H      _PK_H_(0x00, 0x09)
#define REG_MOD_BK00_0A_L      _PK_L_(0x00, 0x0A)
#define REG_MOD_BK00_0A_H      _PK_H_(0x00, 0x0A)
#define REG_MOD_BK00_0B_L      _PK_L_(0x00, 0x0B)
#define REG_MOD_BK00_0B_H      _PK_H_(0x00, 0x0B)
#define REG_MOD_BK00_0C_L      _PK_L_(0x00, 0x0C)
#define REG_MOD_BK00_0C_H      _PK_H_(0x00, 0x0C)
#define REG_MOD_BK00_0D_L      _PK_L_(0x00, 0x0D)
#define REG_MOD_BK00_0D_H      _PK_H_(0x00, 0x0D)
#define REG_MOD_BK00_0E_L      _PK_L_(0x00, 0x0E)
#define REG_MOD_BK00_0E_H      _PK_H_(0x00, 0x0E)
#define REG_MOD_BK00_0F_L      _PK_L_(0x00, 0x0F)
#define REG_MOD_BK00_0F_H      _PK_H_(0x00, 0x0F)
#define REG_MOD_BK00_10_L      _PK_L_(0x00, 0x10)
#define REG_MOD_BK00_10_H      _PK_H_(0x00, 0x10)
#define REG_MOD_BK00_11_L      _PK_L_(0x00, 0x11)
#define REG_MOD_BK00_11_H      _PK_H_(0x00, 0x11)
#define REG_MOD_BK00_12_L      _PK_L_(0x00, 0x12)
#define REG_MOD_BK00_12_H      _PK_H_(0x00, 0x12)
#define REG_MOD_BK00_13_L      _PK_L_(0x00, 0x13)
#define REG_MOD_BK00_13_H      _PK_H_(0x00, 0x13)
#define REG_MOD_BK00_14_L      _PK_L_(0x00, 0x14)
#define REG_MOD_BK00_14_H      _PK_H_(0x00, 0x14)
#define REG_MOD_BK00_15_L      _PK_L_(0x00, 0x15)
#define REG_MOD_BK00_15_H      _PK_H_(0x00, 0x15)
#define REG_MOD_BK00_16_L      _PK_L_(0x00, 0x16)
#define REG_MOD_BK00_16_H      _PK_H_(0x00, 0x16)
#define REG_MOD_BK00_17_L      _PK_L_(0x00, 0x17)
#define REG_MOD_BK00_17_H      _PK_H_(0x00, 0x17)
#define REG_MOD_BK00_18_L      _PK_L_(0x00, 0x18)
#define REG_MOD_BK00_18_H      _PK_H_(0x00, 0x18)
#define REG_MOD_BK00_19_L      _PK_L_(0x00, 0x19)
#define REG_MOD_BK00_19_H      _PK_H_(0x00, 0x19)
#define REG_MOD_BK00_1A_L      _PK_L_(0x00, 0x1A)
#define REG_MOD_BK00_1A_H      _PK_H_(0x00, 0x1A)
#define REG_MOD_BK00_1B_L      _PK_L_(0x00, 0x1B)
#define REG_MOD_BK00_1B_H      _PK_H_(0x00, 0x1B)
#define REG_MOD_BK00_1C_L      _PK_L_(0x00, 0x1C)
#define REG_MOD_BK00_1C_H      _PK_H_(0x00, 0x1C)
#define REG_MOD_BK00_1D_L      _PK_L_(0x00, 0x1D)
#define REG_MOD_BK00_1D_H      _PK_H_(0x00, 0x1D)
#define REG_MOD_BK00_1E_L      _PK_L_(0x00, 0x1E)
#define REG_MOD_BK00_1E_H      _PK_H_(0x00, 0x1E)
#define REG_MOD_BK00_1F_L      _PK_L_(0x00, 0x1F)
#define REG_MOD_BK00_1F_H      _PK_H_(0x00, 0x1F)
#define REG_MOD_BK00_20_L      _PK_L_(0x00, 0x20)
#define REG_MOD_BK00_20_H      _PK_H_(0x00, 0x20)
#define REG_MOD_BK00_21_L      _PK_L_(0x00, 0x21)
#define REG_MOD_BK00_21_H      _PK_H_(0x00, 0x21)
#define REG_MOD_BK00_22_L      _PK_L_(0x00, 0x22)
#define REG_MOD_BK00_22_H      _PK_H_(0x00, 0x22)
#define REG_MOD_BK00_23_L      _PK_L_(0x00, 0x23)
#define REG_MOD_BK00_23_H      _PK_H_(0x00, 0x23)
#define REG_MOD_BK00_24_L      _PK_L_(0x00, 0x24)
#define REG_MOD_BK00_24_H      _PK_H_(0x00, 0x24)
#define REG_MOD_BK00_25_L      _PK_L_(0x00, 0x25)
#define REG_MOD_BK00_25_H      _PK_H_(0x00, 0x25)
#define REG_MOD_BK00_26_L      _PK_L_(0x00, 0x26)
#define REG_MOD_BK00_26_H      _PK_H_(0x00, 0x26)
#define REG_MOD_BK00_27_L      _PK_L_(0x00, 0x27)
#define REG_MOD_BK00_27_H      _PK_H_(0x00, 0x27)
#define REG_MOD_BK00_28_L      _PK_L_(0x00, 0x28)
#define REG_MOD_BK00_28_H      _PK_H_(0x00, 0x28)
#define REG_MOD_BK00_29_L      _PK_L_(0x00, 0x29)
#define REG_MOD_BK00_29_H      _PK_H_(0x00, 0x29)
#define REG_MOD_BK00_2A_L      _PK_L_(0x00, 0x2A)
#define REG_MOD_BK00_2A_H      _PK_H_(0x00, 0x2A)
#define REG_MOD_BK00_2B_L      _PK_L_(0x00, 0x2B)
#define REG_MOD_BK00_2B_H      _PK_H_(0x00, 0x2B)
#define REG_MOD_BK00_2C_L      _PK_L_(0x00, 0x2C)
#define REG_MOD_BK00_2C_H      _PK_H_(0x00, 0x2C)
#define REG_MOD_BK00_2D_L      _PK_L_(0x00, 0x2D)
#define REG_MOD_BK00_2D_H      _PK_H_(0x00, 0x2D)
#define REG_MOD_BK00_2E_L      _PK_L_(0x00, 0x2E)
#define REG_MOD_BK00_2E_H      _PK_H_(0x00, 0x2E)
#define REG_MOD_BK00_2F_L      _PK_L_(0x00, 0x2F)
#define REG_MOD_BK00_2F_H      _PK_H_(0x00, 0x2F)
#define REG_MOD_BK00_30_L      _PK_L_(0x00, 0x30)
#define REG_MOD_BK00_30_H      _PK_H_(0x00, 0x30)
#define REG_MOD_BK00_31_L      _PK_L_(0x00, 0x31)
#define REG_MOD_BK00_31_H      _PK_H_(0x00, 0x31)
#define REG_MOD_BK00_32_L      _PK_L_(0x00, 0x32)
#define REG_MOD_BK00_32_H      _PK_H_(0x00, 0x32)
#define REG_MOD_BK00_33_L      _PK_L_(0x00, 0x33)
#define REG_MOD_BK00_33_H      _PK_H_(0x00, 0x33)
#define REG_MOD_BK00_34_L      _PK_L_(0x00, 0x34)
#define REG_MOD_BK00_34_H      _PK_H_(0x00, 0x34)
#define REG_MOD_BK00_35_L      _PK_L_(0x00, 0x35)
#define REG_MOD_BK00_35_H      _PK_H_(0x00, 0x35)
#define REG_MOD_BK00_36_L      _PK_L_(0x00, 0x36)
#define REG_MOD_BK00_36_H      _PK_H_(0x00, 0x36)
#define REG_MOD_BK00_37_L      _PK_L_(0x00, 0x37)
#define REG_MOD_BK00_37_H      _PK_H_(0x00, 0x37)
#define REG_MOD_BK00_38_L      _PK_L_(0x00, 0x38)
#define REG_MOD_BK00_38_H      _PK_H_(0x00, 0x38)
#define REG_MOD_BK00_39_L      _PK_L_(0x00, 0x39)
#define REG_MOD_BK00_39_H      _PK_H_(0x00, 0x39)
#define REG_MOD_BK00_3A_L      _PK_L_(0x00, 0x3A)
#define REG_MOD_BK00_3A_H      _PK_H_(0x00, 0x3A)
#define REG_MOD_BK00_3B_L      _PK_L_(0x00, 0x3B)
#define REG_MOD_BK00_3B_H      _PK_H_(0x00, 0x3B)
#define REG_MOD_BK00_3C_L      _PK_L_(0x00, 0x3C)
#define REG_MOD_BK00_3C_H      _PK_H_(0x00, 0x3C)
#define REG_MOD_BK00_3D_L      _PK_L_(0x00, 0x3D)
#define REG_MOD_BK00_3D_H      _PK_H_(0x00, 0x3D)
#define REG_MOD_BK00_3E_L      _PK_L_(0x00, 0x3E)
#define REG_MOD_BK00_3E_H      _PK_H_(0x00, 0x3E)
#define REG_MOD_BK00_3F_L      _PK_L_(0x00, 0x3F)
#define REG_MOD_BK00_3F_H      _PK_H_(0x00, 0x3F)
#define REG_MOD_BK00_40_L      _PK_L_(0x00, 0x40)
#define REG_MOD_BK00_40_H      _PK_H_(0x00, 0x40)
#define REG_MOD_BK00_41_L      _PK_L_(0x00, 0x41)
#define REG_MOD_BK00_41_H      _PK_H_(0x00, 0x41)
#define REG_MOD_BK00_42_L      _PK_L_(0x00, 0x42)
#define REG_MOD_BK00_42_H      _PK_H_(0x00, 0x42)
#define REG_MOD_BK00_43_L      _PK_L_(0x00, 0x43)
#define REG_MOD_BK00_43_H      _PK_H_(0x00, 0x43)
#define REG_MOD_BK00_44_L      _PK_L_(0x00, 0x44)
#define REG_MOD_BK00_44_H      _PK_H_(0x00, 0x44)
#define REG_MOD_BK00_45_L      _PK_L_(0x00, 0x45)
#define REG_MOD_BK00_45_H      _PK_H_(0x00, 0x45)
#define REG_MOD_BK00_46_L      _PK_L_(0x00, 0x46)
#define REG_MOD_BK00_46_H      _PK_H_(0x00, 0x46)
#define REG_MOD_BK00_47_L      _PK_L_(0x00, 0x47)
#define REG_MOD_BK00_47_H      _PK_H_(0x00, 0x47)
#define REG_MOD_BK00_48_L      _PK_L_(0x00, 0x48)
#define REG_MOD_BK00_48_H      _PK_H_(0x00, 0x48)
#define REG_MOD_BK00_49_L      _PK_L_(0x00, 0x49)
#define REG_MOD_BK00_49_H      _PK_H_(0x00, 0x49)
#define REG_MOD_BK00_4A_L      _PK_L_(0x00, 0x4A)
#define REG_MOD_BK00_4A_H      _PK_H_(0x00, 0x4A)
#define REG_MOD_BK00_4B_L      _PK_L_(0x00, 0x4B)
#define REG_MOD_BK00_4B_H      _PK_H_(0x00, 0x4B)
#define REG_MOD_BK00_4C_L      _PK_L_(0x00, 0x4C)
#define REG_MOD_BK00_4C_H      _PK_H_(0x00, 0x4C)
#define REG_MOD_BK00_4D_L      _PK_L_(0x00, 0x4D)
#define REG_MOD_BK00_4D_H      _PK_H_(0x00, 0x4D)
#define REG_MOD_BK00_4E_L      _PK_L_(0x00, 0x4E)
#define REG_MOD_BK00_4E_H      _PK_H_(0x00, 0x4E)
#define REG_MOD_BK00_4F_L      _PK_L_(0x00, 0x4F)
#define REG_MOD_BK00_4F_H      _PK_H_(0x00, 0x4F)
#define REG_MOD_BK00_50_L      _PK_L_(0x00, 0x50)
#define REG_MOD_BK00_50_H      _PK_H_(0x00, 0x50)
#define REG_MOD_BK00_51_L      _PK_L_(0x00, 0x51)
#define REG_MOD_BK00_51_H      _PK_H_(0x00, 0x51)
#define REG_MOD_BK00_52_L      _PK_L_(0x00, 0x52)
#define REG_MOD_BK00_52_H      _PK_H_(0x00, 0x52)
#define REG_MOD_BK00_53_L      _PK_L_(0x00, 0x53)
#define REG_MOD_BK00_53_H      _PK_H_(0x00, 0x53)
#define REG_MOD_BK00_54_L      _PK_L_(0x00, 0x54)
#define REG_MOD_BK00_54_H      _PK_H_(0x00, 0x54)
#define REG_MOD_BK00_55_L      _PK_L_(0x00, 0x55)
#define REG_MOD_BK00_55_H      _PK_H_(0x00, 0x55)
#define REG_MOD_BK00_56_L      _PK_L_(0x00, 0x56)
#define REG_MOD_BK00_56_H      _PK_H_(0x00, 0x56)
#define REG_MOD_BK00_57_L      _PK_L_(0x00, 0x57)
#define REG_MOD_BK00_57_H      _PK_H_(0x00, 0x57)
#define REG_MOD_BK00_58_L      _PK_L_(0x00, 0x58)
#define REG_MOD_BK00_58_H      _PK_H_(0x00, 0x58)
#define REG_MOD_BK00_59_L      _PK_L_(0x00, 0x59)
#define REG_MOD_BK00_59_H      _PK_H_(0x00, 0x59)
#define REG_MOD_BK00_5A_L      _PK_L_(0x00, 0x5A)
#define REG_MOD_BK00_5A_H      _PK_H_(0x00, 0x5A)
#define REG_MOD_BK00_5B_L      _PK_L_(0x00, 0x5B)
#define REG_MOD_BK00_5B_H      _PK_H_(0x00, 0x5B)
#define REG_MOD_BK00_5C_L      _PK_L_(0x00, 0x5C)
#define REG_MOD_BK00_5C_H      _PK_H_(0x00, 0x5C)
#define REG_MOD_BK00_5D_L      _PK_L_(0x00, 0x5D)
#define REG_MOD_BK00_5D_H      _PK_H_(0x00, 0x5D)
#define REG_MOD_BK00_5E_L      _PK_L_(0x00, 0x5E)
#define REG_MOD_BK00_5E_H      _PK_H_(0x00, 0x5E)
#define REG_MOD_BK00_5F_L      _PK_L_(0x00, 0x5F)
#define REG_MOD_BK00_5F_H      _PK_H_(0x00, 0x5F)
#define REG_MOD_BK00_60_L      _PK_L_(0x00, 0x60)
#define REG_MOD_BK00_60_H      _PK_H_(0x00, 0x60)
#define REG_MOD_BK00_61_L      _PK_L_(0x00, 0x61)
#define REG_MOD_BK00_61_H      _PK_H_(0x00, 0x61)
#define REG_MOD_BK00_62_L      _PK_L_(0x00, 0x62)
#define REG_MOD_BK00_62_H      _PK_H_(0x00, 0x62)
#define REG_MOD_BK00_63_L      _PK_L_(0x00, 0x63)
#define REG_MOD_BK00_63_H      _PK_H_(0x00, 0x63)
#define REG_MOD_BK00_64_L      _PK_L_(0x00, 0x64)
#define REG_MOD_BK00_64_H      _PK_H_(0x00, 0x64)
#define REG_MOD_BK00_65_L      _PK_L_(0x00, 0x65)
#define REG_MOD_BK00_65_H      _PK_H_(0x00, 0x65)
#define REG_MOD_BK00_66_L      _PK_L_(0x00, 0x66)
#define REG_MOD_BK00_66_H      _PK_H_(0x00, 0x66)
#define REG_MOD_BK00_67_L      _PK_L_(0x00, 0x67)
#define REG_MOD_BK00_67_H      _PK_H_(0x00, 0x67)
#define REG_MOD_BK00_68_L      _PK_L_(0x00, 0x68)
#define REG_MOD_BK00_68_H      _PK_H_(0x00, 0x68)
#define REG_MOD_BK00_69_L      _PK_L_(0x00, 0x69)
#define REG_MOD_BK00_69_H      _PK_H_(0x00, 0x69)
#define REG_MOD_BK00_6A_L      _PK_L_(0x00, 0x6A)
#define REG_MOD_BK00_6A_H      _PK_H_(0x00, 0x6A)
#define REG_MOD_BK00_6B_L      _PK_L_(0x00, 0x6B)
#define REG_MOD_BK00_6B_H      _PK_H_(0x00, 0x6B)
#define REG_MOD_BK00_6C_L      _PK_L_(0x00, 0x6C)
#define REG_MOD_BK00_6C_H      _PK_H_(0x00, 0x6C)
#define REG_MOD_BK00_6D_L      _PK_L_(0x00, 0x6D)
#define REG_MOD_BK00_6D_H      _PK_H_(0x00, 0x6D)
#define REG_MOD_BK00_6E_L      _PK_L_(0x00, 0x6E)
#define REG_MOD_BK00_6E_H      _PK_H_(0x00, 0x6E)
#define REG_MOD_BK00_6F_L      _PK_L_(0x00, 0x6F)
#define REG_MOD_BK00_6F_H      _PK_H_(0x00, 0x6F)
#define REG_MOD_BK00_70_L      _PK_L_(0x00, 0x70)
#define REG_MOD_BK00_70_H      _PK_H_(0x00, 0x70)
#define REG_MOD_BK00_71_L      _PK_L_(0x00, 0x71)
#define REG_MOD_BK00_71_H      _PK_H_(0x00, 0x71)
#define REG_MOD_BK00_72_L      _PK_L_(0x00, 0x72)
#define REG_MOD_BK00_72_H      _PK_H_(0x00, 0x72)
#define REG_MOD_BK00_73_L      _PK_L_(0x00, 0x73)
#define REG_MOD_BK00_73_H      _PK_H_(0x00, 0x73)
#define REG_MOD_BK00_74_L      _PK_L_(0x00, 0x74)
#define REG_MOD_BK00_74_H      _PK_H_(0x00, 0x74)
#define REG_MOD_BK00_75_L      _PK_L_(0x00, 0x75)
#define REG_MOD_BK00_75_H      _PK_H_(0x00, 0x75)
#define REG_MOD_BK00_76_L      _PK_L_(0x00, 0x76)
#define REG_MOD_BK00_76_H      _PK_H_(0x00, 0x76)
#define REG_MOD_BK00_77_L      _PK_L_(0x00, 0x77)
#define REG_MOD_BK00_77_H      _PK_H_(0x00, 0x77)
#define REG_MOD_BK00_78_L      _PK_L_(0x00, 0x78)
#define REG_MOD_BK00_78_H      _PK_H_(0x00, 0x78)
#define REG_MOD_BK00_79_L      _PK_L_(0x00, 0x79)
#define REG_MOD_BK00_79_H      _PK_H_(0x00, 0x79)
#define REG_MOD_BK00_7A_L      _PK_L_(0x00, 0x7A)
#define REG_MOD_BK00_7A_H      _PK_H_(0x00, 0x7A)
#define REG_MOD_BK00_7B_L      _PK_L_(0x00, 0x7B)
#define REG_MOD_BK00_7B_H      _PK_H_(0x00, 0x7B)
#define REG_MOD_BK00_7C_L      _PK_L_(0x00, 0x7C)
#define REG_MOD_BK00_7C_H      _PK_H_(0x00, 0x7C)
#define REG_MOD_BK00_7D_L      _PK_L_(0x00, 0x7D)
#define REG_MOD_BK00_7D_H      _PK_H_(0x00, 0x7D)
#define REG_MOD_BK00_7E_L      _PK_L_(0x00, 0x7E)
#define REG_MOD_BK00_7E_H      _PK_H_(0x00, 0x7E)
#define REG_MOD_BK00_7F_L      _PK_L_(0x00, 0x7F)
#define REG_MOD_BK00_7F_H      _PK_H_(0x00, 0x7F)


//----------------------------------------------
//  BK01: IP1F2
//----------------------------------------------
#define REG_MOD_BK01_00_L      _PK_L_(0x01, 0x00)
#define REG_MOD_BK01_00_H      _PK_H_(0x01, 0x00)
#define REG_MOD_BK01_01_L      _PK_L_(0x01, 0x01)
#define REG_MOD_BK01_01_H      _PK_H_(0x01, 0x01)
#define REG_MOD_BK01_02_L      _PK_L_(0x01, 0x02)
#define REG_MOD_BK01_02_H      _PK_H_(0x01, 0x02)
#define REG_MOD_BK01_03_L      _PK_L_(0x01, 0x03)
#define REG_MOD_BK01_03_H      _PK_H_(0x01, 0x03)
#define REG_MOD_BK01_04_L      _PK_L_(0x01, 0x04)
#define REG_MOD_BK01_04_H      _PK_H_(0x01, 0x04)
#define REG_MOD_BK01_05_L      _PK_L_(0x01, 0x05)
#define REG_MOD_BK01_05_H      _PK_H_(0x01, 0x05)
#define REG_MOD_BK01_06_L      _PK_L_(0x01, 0x06)
#define REG_MOD_BK01_06_H      _PK_H_(0x01, 0x06)
#define REG_MOD_BK01_07_L      _PK_L_(0x01, 0x07)
#define REG_MOD_BK01_07_H      _PK_H_(0x01, 0x07)
#define REG_MOD_BK01_08_L      _PK_L_(0x01, 0x08)
#define REG_MOD_BK01_08_H      _PK_H_(0x01, 0x08)
#define REG_MOD_BK01_09_L      _PK_L_(0x01, 0x09)
#define REG_MOD_BK01_09_H      _PK_H_(0x01, 0x09)
#define REG_MOD_BK01_0A_L      _PK_L_(0x01, 0x0A)
#define REG_MOD_BK01_0A_H      _PK_H_(0x01, 0x0A)
#define REG_MOD_BK01_0B_L      _PK_L_(0x01, 0x0B)
#define REG_MOD_BK01_0B_H      _PK_H_(0x01, 0x0B)
#define REG_MOD_BK01_0C_L      _PK_L_(0x01, 0x0C)
#define REG_MOD_BK01_0C_H      _PK_H_(0x01, 0x0C)
#define REG_MOD_BK01_0D_L      _PK_L_(0x01, 0x0D)
#define REG_MOD_BK01_0D_H      _PK_H_(0x01, 0x0D)
#define REG_MOD_BK01_0E_L      _PK_L_(0x01, 0x0E)
#define REG_MOD_BK01_0E_H      _PK_H_(0x01, 0x0E)
#define REG_MOD_BK01_0F_L      _PK_L_(0x01, 0x0F)
#define REG_MOD_BK01_0F_H      _PK_H_(0x01, 0x0F)
#define REG_MOD_BK01_10_L      _PK_L_(0x01, 0x10)
#define REG_MOD_BK01_10_H      _PK_H_(0x01, 0x10)
#define REG_MOD_BK01_11_L      _PK_L_(0x01, 0x11)
#define REG_MOD_BK01_11_H      _PK_H_(0x01, 0x11)
#define REG_MOD_BK01_12_L      _PK_L_(0x01, 0x12)
#define REG_MOD_BK01_12_H      _PK_H_(0x01, 0x12)
#define REG_MOD_BK01_13_L      _PK_L_(0x01, 0x13)
#define REG_MOD_BK01_13_H      _PK_H_(0x01, 0x13)
#define REG_MOD_BK01_14_L      _PK_L_(0x01, 0x14)
#define REG_MOD_BK01_14_H      _PK_H_(0x01, 0x14)
#define REG_MOD_BK01_15_L      _PK_L_(0x01, 0x15)
#define REG_MOD_BK01_15_H      _PK_H_(0x01, 0x15)
#define REG_MOD_BK01_16_L      _PK_L_(0x01, 0x16)
#define REG_MOD_BK01_16_H      _PK_H_(0x01, 0x16)
#define REG_MOD_BK01_17_L      _PK_L_(0x01, 0x17)
#define REG_MOD_BK01_17_H      _PK_H_(0x01, 0x17)
#define REG_MOD_BK01_18_L      _PK_L_(0x01, 0x18)
#define REG_MOD_BK01_18_H      _PK_H_(0x01, 0x18)
#define REG_MOD_BK01_19_L      _PK_L_(0x01, 0x19)
#define REG_MOD_BK01_19_H      _PK_H_(0x01, 0x19)
#define REG_MOD_BK01_1A_L      _PK_L_(0x01, 0x1A)
#define REG_MOD_BK01_1A_H      _PK_H_(0x01, 0x1A)
#define REG_MOD_BK01_1B_L      _PK_L_(0x01, 0x1B)
#define REG_MOD_BK01_1B_H      _PK_H_(0x01, 0x1B)
#define REG_MOD_BK01_1C_L      _PK_L_(0x01, 0x1C)
#define REG_MOD_BK01_1C_H      _PK_H_(0x01, 0x1C)
#define REG_MOD_BK01_1D_L      _PK_L_(0x01, 0x1D)
#define REG_MOD_BK01_1D_H      _PK_H_(0x01, 0x1D)
#define REG_MOD_BK01_1E_L      _PK_L_(0x01, 0x1E)
#define REG_MOD_BK01_1E_H      _PK_H_(0x01, 0x1E)
#define REG_MOD_BK01_1F_L      _PK_L_(0x01, 0x1F)
#define REG_MOD_BK01_1F_H      _PK_H_(0x01, 0x1F)
#define REG_MOD_BK01_20_L      _PK_L_(0x01, 0x20)
#define REG_MOD_BK01_20_H      _PK_H_(0x01, 0x20)
#define REG_MOD_BK01_21_L      _PK_L_(0x01, 0x21)
#define REG_MOD_BK01_21_H      _PK_H_(0x01, 0x21)
#define REG_MOD_BK01_22_L      _PK_L_(0x01, 0x22)
#define REG_MOD_BK01_22_H      _PK_H_(0x01, 0x22)
#define REG_MOD_BK01_23_L      _PK_L_(0x01, 0x23)
#define REG_MOD_BK01_23_H      _PK_H_(0x01, 0x23)
#define REG_MOD_BK01_24_L      _PK_L_(0x01, 0x24)
#define REG_MOD_BK01_24_H      _PK_H_(0x01, 0x24)
#define REG_MOD_BK01_25_L      _PK_L_(0x01, 0x25)
#define REG_MOD_BK01_25_H      _PK_H_(0x01, 0x25)
#define REG_MOD_BK01_26_L      _PK_L_(0x01, 0x26)
#define REG_MOD_BK01_26_H      _PK_H_(0x01, 0x26)
#define REG_MOD_BK01_27_L      _PK_L_(0x01, 0x27)
#define REG_MOD_BK01_27_H      _PK_H_(0x01, 0x27)
#define REG_MOD_BK01_28_L      _PK_L_(0x01, 0x28)
#define REG_MOD_BK01_28_H      _PK_H_(0x01, 0x28)
#define REG_MOD_BK01_29_L      _PK_L_(0x01, 0x29)
#define REG_MOD_BK01_29_H      _PK_H_(0x01, 0x29)
#define REG_MOD_BK01_2A_L      _PK_L_(0x01, 0x2A)
#define REG_MOD_BK01_2A_H      _PK_H_(0x01, 0x2A)
#define REG_MOD_BK01_2B_L      _PK_L_(0x01, 0x2B)
#define REG_MOD_BK01_2B_H      _PK_H_(0x01, 0x2B)
#define REG_MOD_BK01_2C_L      _PK_L_(0x01, 0x2C)
#define REG_MOD_BK01_2C_H      _PK_H_(0x01, 0x2C)
#define REG_MOD_BK01_2D_L      _PK_L_(0x01, 0x2D)
#define REG_MOD_BK01_2D_H      _PK_H_(0x01, 0x2D)
#define REG_MOD_BK01_2E_L      _PK_L_(0x01, 0x2E)
#define REG_MOD_BK01_2E_H      _PK_H_(0x01, 0x2E)
#define REG_MOD_BK01_2F_L      _PK_L_(0x01, 0x2F)
#define REG_MOD_BK01_2F_H      _PK_H_(0x01, 0x2F)
#define REG_MOD_BK01_30_L      _PK_L_(0x01, 0x30)
#define REG_MOD_BK01_30_H      _PK_H_(0x01, 0x30)
#define REG_MOD_BK01_31_L      _PK_L_(0x01, 0x31)
#define REG_MOD_BK01_31_H      _PK_H_(0x01, 0x31)
#define REG_MOD_BK01_32_L      _PK_L_(0x01, 0x32)
#define REG_MOD_BK01_32_H      _PK_H_(0x01, 0x32)
#define REG_MOD_BK01_33_L      _PK_L_(0x01, 0x33)
#define REG_MOD_BK01_33_H      _PK_H_(0x01, 0x33)
#define REG_MOD_BK01_34_L      _PK_L_(0x01, 0x34)
#define REG_MOD_BK01_34_H      _PK_H_(0x01, 0x34)
#define REG_MOD_BK01_35_L      _PK_L_(0x01, 0x35)
#define REG_MOD_BK01_35_H      _PK_H_(0x01, 0x35)
#define REG_MOD_BK01_36_L      _PK_L_(0x01, 0x36)
#define REG_MOD_BK01_36_H      _PK_H_(0x01, 0x36)
#define REG_MOD_BK01_37_L      _PK_L_(0x01, 0x37)
#define REG_MOD_BK01_37_H      _PK_H_(0x01, 0x37)
#define REG_MOD_BK01_38_L      _PK_L_(0x01, 0x38)
#define REG_MOD_BK01_38_H      _PK_H_(0x01, 0x38)
#define REG_MOD_BK01_39_L      _PK_L_(0x01, 0x39)
#define REG_MOD_BK01_39_H      _PK_H_(0x01, 0x39)
#define REG_MOD_BK01_3A_L      _PK_L_(0x01, 0x3A)
#define REG_MOD_BK01_3A_H      _PK_H_(0x01, 0x3A)
#define REG_MOD_BK01_3B_L      _PK_L_(0x01, 0x3B)
#define REG_MOD_BK01_3B_H      _PK_H_(0x01, 0x3B)
#define REG_MOD_BK01_3C_L      _PK_L_(0x01, 0x3C)
#define REG_MOD_BK01_3C_H      _PK_H_(0x01, 0x3C)
#define REG_MOD_BK01_3D_L      _PK_L_(0x01, 0x3D)
#define REG_MOD_BK01_3D_H      _PK_H_(0x01, 0x3D)
#define REG_MOD_BK01_3E_L      _PK_L_(0x01, 0x3E)
#define REG_MOD_BK01_3E_H      _PK_H_(0x01, 0x3E)
#define REG_MOD_BK01_3F_L      _PK_L_(0x01, 0x3F)
#define REG_MOD_BK01_3F_H      _PK_H_(0x01, 0x3F)
#define REG_MOD_BK01_40_L      _PK_L_(0x01, 0x40)
#define REG_MOD_BK01_40_H      _PK_H_(0x01, 0x40)
#define REG_MOD_BK01_41_L      _PK_L_(0x01, 0x41)
#define REG_MOD_BK01_41_H      _PK_H_(0x01, 0x41)
#define REG_MOD_BK01_42_L      _PK_L_(0x01, 0x42)
#define REG_MOD_BK01_42_H      _PK_H_(0x01, 0x42)
#define REG_MOD_BK01_43_L      _PK_L_(0x01, 0x43)
#define REG_MOD_BK01_43_H      _PK_H_(0x01, 0x43)
#define REG_MOD_BK01_44_L      _PK_L_(0x01, 0x44)
#define REG_MOD_BK01_44_H      _PK_H_(0x01, 0x44)
#define REG_MOD_BK01_45_L      _PK_L_(0x01, 0x45)
#define REG_MOD_BK01_45_H      _PK_H_(0x01, 0x45)
#define REG_MOD_BK01_46_L      _PK_L_(0x01, 0x46)
#define REG_MOD_BK01_46_H      _PK_H_(0x01, 0x46)
#define REG_MOD_BK01_47_L      _PK_L_(0x01, 0x47)
#define REG_MOD_BK01_47_H      _PK_H_(0x01, 0x47)
#define REG_MOD_BK01_48_L      _PK_L_(0x01, 0x48)
#define REG_MOD_BK01_48_H      _PK_H_(0x01, 0x48)
#define REG_MOD_BK01_49_L      _PK_L_(0x01, 0x49)
#define REG_MOD_BK01_49_H      _PK_H_(0x01, 0x49)
#define REG_MOD_BK01_4A_L      _PK_L_(0x01, 0x4A)
#define REG_MOD_BK01_4A_H      _PK_H_(0x01, 0x4A)
#define REG_MOD_BK01_4B_L      _PK_L_(0x01, 0x4B)
#define REG_MOD_BK01_4B_H      _PK_H_(0x01, 0x4B)
#define REG_MOD_BK01_4C_L      _PK_L_(0x01, 0x4C)
#define REG_MOD_BK01_4C_H      _PK_H_(0x01, 0x4C)
#define REG_MOD_BK01_4D_L      _PK_L_(0x01, 0x4D)
#define REG_MOD_BK01_4D_H      _PK_H_(0x01, 0x4D)
#define REG_MOD_BK01_4E_L      _PK_L_(0x01, 0x4E)
#define REG_MOD_BK01_4E_H      _PK_H_(0x01, 0x4E)
#define REG_MOD_BK01_4F_L      _PK_L_(0x01, 0x4F)
#define REG_MOD_BK01_4F_H      _PK_H_(0x01, 0x4F)
#define REG_MOD_BK01_50_L      _PK_L_(0x01, 0x50)
#define REG_MOD_BK01_50_H      _PK_H_(0x01, 0x50)
#define REG_MOD_BK01_51_L      _PK_L_(0x01, 0x51)
#define REG_MOD_BK01_51_H      _PK_H_(0x01, 0x51)
#define REG_MOD_BK01_52_L      _PK_L_(0x01, 0x52)
#define REG_MOD_BK01_52_H      _PK_H_(0x01, 0x52)
#define REG_MOD_BK01_53_L      _PK_L_(0x01, 0x53)
#define REG_MOD_BK01_53_H      _PK_H_(0x01, 0x53)
#define REG_MOD_BK01_54_L      _PK_L_(0x01, 0x54)
#define REG_MOD_BK01_54_H      _PK_H_(0x01, 0x54)
#define REG_MOD_BK01_55_L      _PK_L_(0x01, 0x55)
#define REG_MOD_BK01_55_H      _PK_H_(0x01, 0x55)
#define REG_MOD_BK01_56_L      _PK_L_(0x01, 0x56)
#define REG_MOD_BK01_56_H      _PK_H_(0x01, 0x56)
#define REG_MOD_BK01_57_L      _PK_L_(0x01, 0x57)
#define REG_MOD_BK01_57_H      _PK_H_(0x01, 0x57)
#define REG_MOD_BK01_58_L      _PK_L_(0x01, 0x58)
#define REG_MOD_BK01_58_H      _PK_H_(0x01, 0x58)
#define REG_MOD_BK01_59_L      _PK_L_(0x01, 0x59)
#define REG_MOD_BK01_59_H      _PK_H_(0x01, 0x59)
#define REG_MOD_BK01_5A_L      _PK_L_(0x01, 0x5A)
#define REG_MOD_BK01_5A_H      _PK_H_(0x01, 0x5A)
#define REG_MOD_BK01_5B_L      _PK_L_(0x01, 0x5B)
#define REG_MOD_BK01_5B_H      _PK_H_(0x01, 0x5B)
#define REG_MOD_BK01_5C_L      _PK_L_(0x01, 0x5C)
#define REG_MOD_BK01_5C_H      _PK_H_(0x01, 0x5C)
#define REG_MOD_BK01_5D_L      _PK_L_(0x01, 0x5D)
#define REG_MOD_BK01_5D_H      _PK_H_(0x01, 0x5D)
#define REG_MOD_BK01_5E_L      _PK_L_(0x01, 0x5E)
#define REG_MOD_BK01_5E_H      _PK_H_(0x01, 0x5E)
#define REG_MOD_BK01_5F_L      _PK_L_(0x01, 0x5F)
#define REG_MOD_BK01_5F_H      _PK_H_(0x01, 0x5F)
#define REG_MOD_BK01_60_L      _PK_L_(0x01, 0x60)
#define REG_MOD_BK01_60_H      _PK_H_(0x01, 0x60)
#define REG_MOD_BK01_61_L      _PK_L_(0x01, 0x61)
#define REG_MOD_BK01_61_H      _PK_H_(0x01, 0x61)
#define REG_MOD_BK01_62_L      _PK_L_(0x01, 0x62)
#define REG_MOD_BK01_62_H      _PK_H_(0x01, 0x62)
#define REG_MOD_BK01_63_L      _PK_L_(0x01, 0x63)
#define REG_MOD_BK01_63_H      _PK_H_(0x01, 0x63)
#define REG_MOD_BK01_64_L      _PK_L_(0x01, 0x64)
#define REG_MOD_BK01_64_H      _PK_H_(0x01, 0x64)
#define REG_MOD_BK01_65_L      _PK_L_(0x01, 0x65)
#define REG_MOD_BK01_65_H      _PK_H_(0x01, 0x65)
#define REG_MOD_BK01_66_L      _PK_L_(0x01, 0x66)
#define REG_MOD_BK01_66_H      _PK_H_(0x01, 0x66)
#define REG_MOD_BK01_67_L      _PK_L_(0x01, 0x67)
#define REG_MOD_BK01_67_H      _PK_H_(0x01, 0x67)
#define REG_MOD_BK01_68_L      _PK_L_(0x01, 0x68)
#define REG_MOD_BK01_68_H      _PK_H_(0x01, 0x68)
#define REG_MOD_BK01_69_L      _PK_L_(0x01, 0x69)
#define REG_MOD_BK01_69_H      _PK_H_(0x01, 0x69)
#define REG_MOD_BK01_6A_L      _PK_L_(0x01, 0x6A)
#define REG_MOD_BK01_6A_H      _PK_H_(0x01, 0x6A)
#define REG_MOD_BK01_6B_L      _PK_L_(0x01, 0x6B)
#define REG_MOD_BK01_6B_H      _PK_H_(0x01, 0x6B)
#define REG_MOD_BK01_6C_L      _PK_L_(0x01, 0x6C)
#define REG_MOD_BK01_6C_H      _PK_H_(0x01, 0x6C)
#define REG_MOD_BK01_6D_L      _PK_L_(0x01, 0x6D)
#define REG_MOD_BK01_6D_H      _PK_H_(0x01, 0x6D)
#define REG_MOD_BK01_6E_L      _PK_L_(0x01, 0x6E)
#define REG_MOD_BK01_6E_H      _PK_H_(0x01, 0x6E)
#define REG_MOD_BK01_6F_L      _PK_L_(0x01, 0x6F)
#define REG_MOD_BK01_6F_H      _PK_H_(0x01, 0x6F)
#define REG_MOD_BK01_70_L      _PK_L_(0x01, 0x70)
#define REG_MOD_BK01_70_H      _PK_H_(0x01, 0x70)
#define REG_MOD_BK01_71_L      _PK_L_(0x01, 0x71)
#define REG_MOD_BK01_71_H      _PK_H_(0x01, 0x71)
#define REG_MOD_BK01_72_L      _PK_L_(0x01, 0x72)
#define REG_MOD_BK01_72_H      _PK_H_(0x01, 0x72)
#define REG_MOD_BK01_73_L      _PK_L_(0x01, 0x73)
#define REG_MOD_BK01_73_H      _PK_H_(0x01, 0x73)
#define REG_MOD_BK01_74_L      _PK_L_(0x01, 0x74)
#define REG_MOD_BK01_74_H      _PK_H_(0x01, 0x74)
#define REG_MOD_BK01_75_L      _PK_L_(0x01, 0x75)
#define REG_MOD_BK01_75_H      _PK_H_(0x01, 0x75)
#define REG_MOD_BK01_76_L      _PK_L_(0x01, 0x76)
#define REG_MOD_BK01_76_H      _PK_H_(0x01, 0x76)
#define REG_MOD_BK01_77_L      _PK_L_(0x01, 0x77)
#define REG_MOD_BK01_77_H      _PK_H_(0x01, 0x77)
#define REG_MOD_BK01_78_L      _PK_L_(0x01, 0x78)
#define REG_MOD_BK01_78_H      _PK_H_(0x01, 0x78)
#define REG_MOD_BK01_79_L      _PK_L_(0x01, 0x79)
#define REG_MOD_BK01_79_H      _PK_H_(0x01, 0x79)
#define REG_MOD_BK01_7A_L      _PK_L_(0x01, 0x7A)
#define REG_MOD_BK01_7A_H      _PK_H_(0x01, 0x7A)
#define REG_MOD_BK01_7B_L      _PK_L_(0x01, 0x7B)
#define REG_MOD_BK01_7B_H      _PK_H_(0x01, 0x7B)
#define REG_MOD_BK01_7C_L      _PK_L_(0x01, 0x7C)
#define REG_MOD_BK01_7C_H      _PK_H_(0x01, 0x7C)
#define REG_MOD_BK01_7D_L      _PK_L_(0x01, 0x7D)
#define REG_MOD_BK01_7D_H      _PK_H_(0x01, 0x7D)
#define REG_MOD_BK01_7E_L      _PK_L_(0x01, 0x7E)
#define REG_MOD_BK01_7E_H      _PK_H_(0x01, 0x7E)
#define REG_MOD_BK01_7F_L      _PK_L_(0x01, 0x7F)
#define REG_MOD_BK01_7F_H      _PK_H_(0x01, 0x7F)

//=============================================================
//----------------------------------------------
//  READ/WRITE PANEL REGISTERS
//----------------------------------------------
#if REG_MOD_BASE != 0x303200
#define MOD_W2BYTE( u32Reg, u16Val)\
            ( { RIU_WRITE_2BYTE(REG_MOD_BASE << 1, ((u32Reg) >> 8) & 0x00FF ); \
                RIU_WRITE_2BYTE( (REG_MOD_BASE + ((u32Reg) & 0xFF) ) << 1, u16Val ); } )

#define MOD_R2BYTE( u32Reg ) \
            ( { RIU_WRITE_2BYTE(REG_MOD_BASE << 1, ((u32Reg) >> 8) & 0x00FF ); \
                RIU_READ_2BYTE( (REG_MOD_BASE + ((u32Reg) & 0xFF) ) << 1) ; } )

#define MOD_R2BYTEMSK( u32Reg, u16mask)\
            ( { RIU_WRITE_2BYTE(REG_MOD_BASE << 1, ((u32Reg) >> 8) & 0x00FF ); \
                RIU_READ_2BYTE( (REG_MOD_BASE + ((u32Reg) & 0xFF) ) << 1) & (u16mask); })

#define MOD_W2BYTEMSK( u32Reg, u16Val, u16Mask)\
            ( { RIU_WRITE_2BYTE(REG_MOD_BASE << 1, ((u32Reg) >> 8) & 0x00FF ); \
                RIU_WRITE_2BYTE( (REG_MOD_BASE + ((u32Reg) & 0xFF) )<<1 , (RIU_READ_2BYTE( (REG_MOD_BASE + ((u32Reg) & 0xFF) ) << 1 ) & ~(u16Mask)) | ((u16Val) & (u16Mask)) ); } )
#else
#define MOD_W2BYTE( u32Reg, u16Val)\
            ( { FRC_RIU_WRITE_2BYTE( (REG_MOD_BASE + ((u32Reg) & 0xFF) ) << 1, u16Val ); } )

#define MOD_R2BYTE( u32Reg ) \
            ( { FRC_RIU_READ_2BYTE( (REG_MOD_BASE + ((u32Reg) & 0xFF) ) << 1) ; } )

#define MOD_R2BYTEMSK( u32Reg, u16mask)\
            ( { FRC_RIU_READ_2BYTE( (REG_MOD_BASE + ((u32Reg) & 0xFF) ) << 1) & (u16mask); })

#define MOD_W2BYTEMSK( u32Reg, u16Val, u16Mask)\
            ( { FRC_RIU_WRITE_2BYTE( (REG_MOD_BASE + ((u32Reg) & 0xFF) )<<1 , (FRC_RIU_READ_2BYTE( (REG_MOD_BASE + ((u32Reg) & 0xFF) ) << 1 ) & ~(u16Mask)) | ((u16Val) & (u16Mask)) ); } )
#endif
//Set MOD Power Down, REG_MOD_BK00_28_L
#define FRC_MOD_PD_MODATOP     BIT(0)
#define FRC_MOD_PD_REG_A       BIT(6)  // Power down Regulator CH12~25
#define FRC_MOD_PD_REG_B       BIT(7)  // Power down Regulator CH0~11

/* LPLL */
#define L_BK_LPLL(x)                BK_REG_L(REG_LPLL_BASE, x)
#define H_BK_LPLL(x)                BK_REG_H(REG_LPLL_BASE, x)

/* UTMI1 */
#define L_BK_UTMI1(x)               BK_REG_L(REG_UTMI1_BASE, x)
#define H_BK_UTMI1(x)               BK_REG_H(REG_UTMI1_BASE, x)

#endif

