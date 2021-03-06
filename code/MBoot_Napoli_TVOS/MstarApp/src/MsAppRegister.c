//<MStar Software>
//******************************************************************************
// MStar Software
// Copyright (c) 2010 - 2012 MStar Semiconductor, Inc. All rights reserved.
// All software, firmware and related documentation herein ("MStar Software") are
// intellectual property of MStar Semiconductor, Inc. ("MStar") and protected by
// law, including, but not limited to, copyright law and international treaties.
// Any use, modification, reproduction, retransmission, or republication of all
// or part of MStar Software is expressly prohibited, unless prior written
// permission has been granted by MStar.
//
// By accessing, browsing and/or using MStar Software, you acknowledge that you
// have read, understood, and agree, to be bound by below terms ("Terms") and to
// comply with all applicable laws and regulations:
//
// 1. MStar shall retain any and all right, ownership and interest to MStar
//    Software and any modification/derivatives thereof.
//    No right, ownership, or interest to MStar Software and any
//    modification/derivatives thereof is transferred to you under Terms.
//
// 2. You understand that MStar Software might include, incorporate or be
//    supplied together with third party`s software and the use of MStar
//    Software may require additional licenses from third parties.
//    Therefore, you hereby agree it is your sole responsibility to separately
//    obtain any and all third party right and license necessary for your use of
//    such third party`s software.
//
// 3. MStar Software and any modification/derivatives thereof shall be deemed as
//    MStar`s confidential information and you agree to keep MStar`s
//    confidential information in strictest confidence and not disclose to any
//    third party.
//
// 4. MStar Software is provided on an "AS IS" basis without warranties of any
//    kind. Any warranties are hereby expressly disclaimed by MStar, including
//    without limitation, any warranties of merchantability, non-infringement of
//    intellectual property rights, fitness for a particular purpose, error free
//    and in conformity with any international standard.  You agree to waive any
//    claim against MStar for any loss, damage, cost or expense that you may
//    incur related to your use of MStar Software.
//    In no event shall MStar be liable for any direct, indirect, incidental or
//    consequential damages, including without limitation, lost of profit or
//    revenues, lost or damage of data, and unauthorized system use.
//    You agree that this Section 4 shall still apply without being affected
//    even if MStar Software has been modified by MStar in accordance with your
//    request or instruction for your use, except otherwise agreed by both
//    parties in writing.
//
// 5. If requested, MStar may from time to time provide technical supports or
//    services in relation with MStar Software to you for your use of
//    MStar Software in conjunction with your or your customer`s product
//    ("Services").
//    You understand and agree that, except otherwise agreed by both parties in
//    writing, Services are provided on an "AS IS" basis and the warranty
//    disclaimer set forth in Section 4 above shall apply.
//
// 6. Nothing contained herein shall be construed as by implication, estoppels
//    or otherwise:
//    (a) conferring any license or right to use MStar name, trademark, service
//        mark, symbol or any other identification;
//    (b) obligating MStar or any of its affiliates to furnish any person,
//        including without limitation, you and your customers, any assistance
//        of any kind whatsoever, or any information; or
//    (c) conferring any license or right under any intellectual property right.
//
// 7. These terms shall be governed by and construed in accordance with the laws
//    of Taiwan, R.O.C., excluding its conflict of law rules.
//    Any and all dispute arising out hereof or related hereto shall be finally
//    settled by arbitration referred to the Chinese Arbitration Association,
//    Taipei in accordance with the ROC Arbitration Law and the Arbitration
//    Rules of the Association by three (3) arbitrators appointed in accordance
//    with the said Rules.
//    The place of arbitration shall be in Taipei, Taiwan and the language shall
//    be English.
//    The arbitration award shall be final and binding to both parties.
//
//******************************************************************************
//<MStar Software>
#include <stddef.h>
#include <exports.h>
#include <MsCmdTable.h>
#include <config.h>

#include <MsBoot.h>
#include <ShareType.h>

#if CONFIG_RESCUE_ENV  && CONFIG_RESCUE_ENV_IR_TRIGGER
#include <MsSystem.h>
#endif

#define WDT_TIMEOUT_DEFAULT 60
#define WDT_TIMEOUT_MIN 5
#define WDT_TIMEOUT_ENV_STR "WDT_TUMEOUT"

void App_Register_Process(void)
{
#if CONFIG_RESCUE_ENV
#if CONFIG_RESCUE_ENV_AUTO_TRIGGER
    Add_Command_Table ("BrickTerminator" , 0, STAGE_PROCESS);
#else
#if CONFIG_RESCUE_ENV_IR_TRIGGER
    {
        unsigned int u32Value = 0;
        char *pEnv = getenv(BRICK_TERMINATOR_IR_TRIGGERED_STRING);
        if(NULL != pEnv)
        {
            u32Value = (unsigned int)simple_strtoul(pEnv, NULL, 10);
            if(1 == u32Value)
            {
                Add_Command_Table ("BrickTerminator" , 0, STAGE_PROCESS);
            }
        }
    }
#endif //CONFIG_RESCUE_ENV_IR_TRIGGER
#endif //CONFIG_RESCUE_ENV_AUTO_TRIGGER
#endif //CONFIG_RESCUE_ENV
    Add_Command_Table ("sync_mmap" , 0, STAGE_PROCESS);
    #if defined (CONFIG_SECURITY_BOOT)
    Add_Command_Table ("SecureInit" , 0, STAGE_PROCESS);
    #endif
    #ifdef CONFIG_DISPLAY_VERSIONINFO
    Add_Command_Table ("mversion" , 0, STAGE_PROCESS);
    #endif
    Add_Command_Table ("bootargs_set" , 0, STAGE_PROCESS);
    Add_Command_Table ("config2env" , 0, STAGE_PROCESS);
    Add_Command_Table ("if_51OnRam_set" , 0, STAGE_PROCESS);
}

//you can type "showtb 0" in mboot console to see registered cmd.
void App_Register_ToKernel(void)
{
    // Add_Command_Table ("delay 0" , 0, STAGE_TOKERNEL);
#if (CONFIG_PANEL_INIT)
    Add_Command_Table ("panel_pre_init" , 0, STAGE_TOKERNEL);
#endif
#if defined(CONFIG_ENABLE_4K2K_PANEL)
#if defined(CONFIG_INX_NOVA_VB1)
    Add_Command_Table("inx_panel_set_init", 0, STAGE_TOKERNEL);
#endif
#endif
#if(ENABLE_HDMI_TX == 1)
    Add_Command_Table ("hdmi init" , 0, STAGE_TOKERNEL);
#endif

    Add_Command_Table ("pm_power_test" , 0, STAGE_TOKERNEL);
#if (CONFIG_ENABLE_RTPM)
    Add_Command_Table ("runtime_pm" , 0, STAGE_TOKERNEL);
#endif

#if defined (CONFIG_URSA6_VB1)
    Add_Command_Table ("send_I2C_cmd_to_ursa6" , 0, STAGE_TOKERNEL); 
#endif

    #ifdef CONFIG_DISPLAY_LOGO
    #if defined(CONFIG_BOOTLOGO_4K2K)
        #define BOOTLOGO "bootlogo 0 0 1 1 boot0.jpg"
    #elif (ENABLE_MSTAR_KENYA == 1)
        #define BOOTLOGO "bootlogo 0 0 1 1 bootlogo.jpg"
    #else
        #define BOOTLOGO "bootlogo"
    #endif
    char* opt_logo = NULL;
    opt_logo = getenv("logo");
    if(opt_logo != NULL)
    {
        int logo_on = 0;
        logo_on = simple_strtol(opt_logo, NULL, 10);
        if(logo_on > 0 && logo_on < 3)
        {
            Add_Command_Table (BOOTLOGO , 0, STAGE_TOKERNEL);
            #if defined (CONFIG_URSA_6M40)
            Add_Command_Table ("ursa_lvds_on" , 0, STAGE_TOKERNEL);
            #endif
			#if defined (CONFIG_URSA_8)
            Add_Command_Table ("ursa8_lvds_on" , 0, STAGE_TOKERNEL);
			#endif
        }
    }
    else
    {
            Add_Command_Table (BOOTLOGO , 0, STAGE_TOKERNEL);
            #if defined (CONFIG_URSA_6M40)
            Add_Command_Table ("ursa_lvds_on" , 0, STAGE_TOKERNEL);
            #endif
    }
    #endif

#if defined(CONFIG_INX_VB1) && defined(CONFIG_BOOTLOGO_4K2K)
        Add_Command_Table("panel_inx_vb1_init",0,STAGE_TOKERNEL);
#endif

    #ifdef CONFIG_POWER_MUSIC
    char* opt_music = NULL;
    opt_music = getenv("music");
    if(opt_music != NULL)
    {
        int music_on = 0;
        music_on = simple_strtol(opt_music, NULL, 10);
        if(music_on > 0 && music_on < 3)
        {
            Add_Command_Table ("bootmusic" , 0, STAGE_TOKERNEL);
        }
    }
    else
    {
        Add_Command_Table ("bootmusic" , 0, STAGE_TOKERNEL);
    }
    #endif

    #if (CONFIG_MSTAR_FASTBOOT_ENABLE)
    Add_Command_Table ("fastboot" , 0, STAGE_TOKERNEL);
    #endif

    #ifdef CONFIG_GENERIC_MMC
		Add_Command_Table ("mmc slcrelwrchk" , 0, STAGE_TOKERNEL);
    #endif
#if (CONFIG_WDT)
    {
        char cmd[CMD_BUF] = {};
        unsigned int u32Timeout = WDT_TIMEOUT_DEFAULT;
        char *pEnv = getenv(WDT_TIMEOUT_ENV_STR);

        if(pEnv != NULL)
        {
            u32Timeout = (unsigned int)simple_strtol(pEnv, NULL, 10);
        }
        if(u32Timeout < WDT_TIMEOUT_MIN) // NOTE: should not be too short to prevent infinite reboot
        {
            printf("%s: Incorrect WDT TIMEOUT, should be not less than '%u', at %d\n", __func__, WDT_TIMEOUT_MIN, __LINE__);
            u32Timeout = WDT_TIMEOUT_MIN;
        }
        memset(cmd, 0, sizeof(cmd));
        sprintf(cmd, "wdt_enable %u", u32Timeout);
        Add_Command_Table (cmd , 0, STAGE_TOKERNEL);
    }
#endif
#if defined (CONFIG_INX_NOVA_VB1)
    Add_Command_Table ("inx_nova_set_4k2k_2division", 0, STAGE_TOKERNEL);
#endif
#if defined (CONFIG_URSA_8)
        Add_Command_Table ("ursa8_set_osd_mode" , 0, STAGE_TOKERNEL);
#endif
#if defined (CONFIG_URSA_6M40) 
        Add_Command_Table ("ursa_set_osd_mode" , 0, STAGE_TOKERNEL);
#endif

#if (ENABLE_MODULE_TEE==1) // alway in bottom
     Add_Command_Table ("SecureBootCmd" , 0, STAGE_TOKERNEL);
#endif

}

