#ifndef __UNFD_KAISERS_LINUX_H__
#define __UNFD_KAISERS_LINUX_H__

#include <linux/delay.h>
#include <linux/mm.h>
#include <linux/highmem.h>
#include <linux/string.h>
#include <linux/slab.h>
#include <linux/dma-mapping.h>
#include <linux/interrupt.h>
#include <linux/sched.h>
#include <asm/io.h>
#include <asm/memory.h>
#include <mach/io.h>

#define REG_BANK_CLKGEN						(0x580)
#define REG_BANK_CHIPTOP					(0xF00)
#define REG_BANK_FCIE0						(0x8980)
#define REG_BANK_FCIE2						(0x8A00)
#define REG_BANK_TIMER0						(0x1810)

#define RIU_PM_BASE							(IO_ADDRESS(0x1F000000))
#define RIU_BASE							(IO_ADDRESS(0x1F200000))

#define REG(Reg_Addr)						(*(volatile U16*)(Reg_Addr))
#define REG_OFFSET_SHIFT_BITS				2
#define GET_REG_ADDR(x, y)					(x+((y)<<REG_OFFSET_SHIFT_BITS))

#define REG_WRITE_UINT16(reg_addr, val)		REG(reg_addr) = val
#define REG_READ_UINT16(reg_addr, val)		val = REG(reg_addr)
#define HAL_WRITE_UINT16(reg_addr, val)		(REG(reg_addr) = val)
#define HAL_READ_UINT16(reg_addr, val)		val = REG(reg_addr)
#define REG_SET_BITS_UINT16(reg_addr, val)	REG(reg_addr) |= (val)
#define REG_CLR_BITS_UINT16(reg_addr, val)	REG(reg_addr) &= ~(val)
#define REG_W1C_BITS_UINT16(reg_addr, val)	REG_WRITE_UINT16(reg_addr, REG(reg_addr)&(val))

#define MPLL_CLK_REG_BASE_ADDR				GET_REG_ADDR(RIU_BASE, REG_BANK_CLKGEN)
#define CHIPTOP_REG_BASE_ADDR				GET_REG_ADDR(RIU_BASE, REG_BANK_CHIPTOP)
#define FCIE_REG_BASE_ADDR					GET_REG_ADDR(RIU_BASE, REG_BANK_FCIE0)
#define FCIE_NC_CIFD_BASE					GET_REG_ADDR(RIU_BASE, REG_BANK_FCIE2)
#define TIMER0_REG_BASE_ADDR				GET_REG_ADDR(RIU_PM_BASE, REG_BANK_TIMER0)

#define REG50_ECC_CTRL_INIT_VALUE			0

#define UNFD_ST_PLAT						0x80000000
#define IF_IP_VERIFY						0 // [CAUTION]: to verify IP and HAL code, defaut 0

// debug
#define FCIE3_DUMP_DEBUG_BUS				1

//FCIE4 DDR Nand
#define FCIE4_DDR					0

#define FCIE_LFSR	1

#define SPARE640B_CIFD512B_PATCH    		1

#define NAND_PAD_BYPASS_MODE	    1
#define NAND_PAD_TOGGLE_MODE	    2
#define NAND_PAD_ONFI_SYNC_MODE		3

#if (defined(FCIE4_DDR) && FCIE4_DDR)
#define NC_SET_DDR_MODE()           REG_WRITE_UINT16(NC_DDR_CTRL, pNandDrv->u16_Reg58_DDRCtrl);
#define NC_CLR_DDR_MODE()           REG_CLR_BITS_UINT16(NC_DDR_CTRL, BIT_DDR_MASM);
#else
#define NC_SET_DDR_MODE()
#define NC_CLR_DDR_MODE()
#endif

#if (defined(FCIE4_DDR) && FCIE4_DDR)
#define DQS_MODE_0P0T		0
#define DQS_MODE_0P5T		1
#define DQS_MODE_1P0T		2
#define DQS_MODE_1P5T		3
#define DQS_MODE_2P0T		4
#define DQS_MODE_2P5T		5
#define DQS_MODE_3P0T		6
#define DQS_MODE_3P5T		7

#define DQS_MODE_TABLE_CNT	4 // should modify to 8
#define DQS_MODE_SEARCH_TABLE {DQS_MODE_1P5T, DQS_MODE_0P0T, DQS_MODE_2P0T, DQS_MODE_2P5T}
#define DQS_MODE_TABLE		{DQS_MODE_0P0T, DQS_MODE_1P5T, DQS_MODE_2P0T, DQS_MODE_2P5T}

#define	NC_ONFI_DEFAULT_TRR 		12
#define	NC_ONFI_DEFAULT_TCS 		7
#define NC_ONFI_DEFAULT_TWW			8
#define NC_ONFI_DEFAULT_TWHR 		5
#define NC_ONFI_DEFAULT_TADL 		6
#define NC_ONFI_DEFAULT_TCWAW 		4
#define	NC_ONFI_DEFAULT_RX40CMD 	4
#define	NC_ONFI_DEFAULT_RX40ADR 	7
#define	NC_ONFI_DEFAULT_RX56 		10

#define	NC_TOGGLE_DEFAULT_TRR 		8
#define	NC_TOGGLE_DEFAULT_TCS 		6
#define NC_TOGGLE_DEFAULT_TWW 		7
#define	NC_TOGGLE_DEFAULT_TWHR 		5
#define	NC_TOGGLE_DEFAULT_TADL 		7
#define	NC_TOGGLE_DEFAULT_TCWAW 	2
#define	NC_TOGGLE_DEFAULT_RX40CMD 	4
#define	NC_TOGGLE_DEFAULT_RX40ADR 	5
#define	NC_TOGGLE_DEFAULT_RX56 		15
#endif

#define NC_INST_DELAY	1
#define NC_HWCMD_DELAY	1
#define NC_TRR_TCS		1
#define NC_TWHR_TCLHZ			1
#define NC_TCWAW_TADL			1

#define	NC_SDR_DEFAULT_TRR 			7
#define	NC_SDR_DEFAULT_TCS 			6
#define NC_SDR_DEFAULT_TWW			5
#define	NC_SDR_DEFAULT_TWHR 		4
#define	NC_SDR_DEFAULT_TADL 		8
#define	NC_SDR_DEFAULT_TCWAW 		2
#define	NC_SDR_DEFAULT_RX40CMD 		4
#define	NC_SDR_DEFAULT_RX40ADR 		5
#define	NC_SDR_DEFAULT_RX56 		5


#define NC_SEL_FCIE3						1
#if NC_SEL_FCIE3
#include "drvNAND_reg_v3.h"

#undef ECC_CODE_BYTECNT_4BIT
#undef ECC_CODE_BYTECNT_8BIT
#undef ECC_CODE_BYTECNT_20BIT
#undef ECC_CODE_BYTECNT_24BIT

#define ECC_CODE_BYTECNT_4BIT        8
#define ECC_CODE_BYTECNT_8BIT       14
#define ECC_CODE_BYTECNT_20BIT      34
#define ECC_CODE_BYTECNT_24BIT      40

#else
#error "Error! no FCIE registers selected."
#endif

#define IF_FCIE_SHARE_PINS					1 // 1: need to nand_pads_switch at HAL's functions.
#define IF_FCIE_SHARE_CLK					1 // 1: need to nand_clock_setting at HAL's functions.
#define IF_FCIE_SHARE_IP					1 // A3 might use SD

#define ENABLE_NAND_INTERRUPT_MODE			1

#define NAND_DRIVER_ROM_VERSION				0 // to save code size
#define AUTO_FORMAT_FTL						0

#define ENABLE_CUS_READ_ENHANCEMENT			0

#define __VER_UNFD_FTL__					0
//=====================================================
// Nand Driver configs
//=====================================================
#define NAND_BUF_USE_STACK					0
#define NAND_ENV_FPGA						1
#define NAND_ENV_ASIC						2
#ifdef __FPGA_MODE__	// currently G1 don't care this macro, even in ROM code
#define NAND_DRIVER_ENV						NAND_ENV_FPGA
#else
#define NAND_DRIVER_ENV						NAND_ENV_ASIC
#endif

#define UNFD_CACHE_LINE						0x80
//=====================================================
// tool-chain attributes
//=====================================================
#define UNFD_PACK0
#define UNFD_PACK1							__attribute__((__packed__))
#define UNFD_ALIGN0
#define UNFD_ALIGN1							__attribute__((aligned(UNFD_CACHE_LINE)))

//=====================================================
// debug option
//=====================================================
#define NAND_TEST_IN_DESIGN					0      /* [CAUTION] */

//#ifndef NAND_DEBUG_MSG
#define NAND_DEBUG_MSG						1
//#endif

/* Define trace levels. */
#define UNFD_DEBUG_LEVEL_ERROR				(1)    /* Error condition debug messages. */
#define UNFD_DEBUG_LEVEL_WARNING			(2)    /* Warning condition debug messages. */
#define UNFD_DEBUG_LEVEL_HIGH				(3)    /* Debug messages (high debugging). */
#define UNFD_DEBUG_LEVEL_MEDIUM				(4)    /* Debug messages. */
#define UNFD_DEBUG_LEVEL_LOW				(5)    /* Debug messages (low debugging). */

/* Higer debug level means more verbose */
#ifndef UNFD_DEBUG_LEVEL
#define UNFD_DEBUG_LEVEL					UNFD_DEBUG_LEVEL_WARNING
#endif

#if defined(NAND_DEBUG_MSG) && NAND_DEBUG_MSG
#define nand_print_tmt						//msPrintfFunc
#define nand_printf							printk
#define nand_debug(dbg_lv, tag, str, ...)				\
	do {												\
		if (dbg_lv > UNFD_DEBUG_LEVEL)				\
			break;									\
		else {										\
			if (tag)									\
			{                                       \
				nand_printf("[%s]\t",__func__);				\
				/*nand_print_tmt(__func__);*/				\
			}                                       \
													\
			nand_printf(str, ##__VA_ARGS__);			\
			/*nand_print_tmt(str, ##__VA_ARGS__);*/			\
		}											\
	} while(0)
#else /* NAND_DEBUG_MSG */
#define nand_printf(...)
#define nand_debug(enable, tag, str, ...)	{}
#endif /* NAND_DEBUG_MSG */

static __inline void nand_assert(int condition)
{
	if (!condition) {
        panic("%s\n UNFD Assert(%d)\n", __func__, __LINE__);
	}
}

#define nand_die() \
	do { \
		nand_assert(0); \
	} while(0);

#define nand_stop() \
	while(1)  nand_reset_WatchDog();

//=====================================================
// HW Timer for Delay
//=====================================================
#define TIMER0_ENABLE						GET_REG_ADDR(TIMER0_REG_BASE_ADDR, 0x00)
#define TIMER0_HIT							GET_REG_ADDR(TIMER0_REG_BASE_ADDR, 0x01)
#define TIMER0_MAX_LOW						GET_REG_ADDR(TIMER0_REG_BASE_ADDR, 0x02)
#define TIMER0_MAX_HIGH						GET_REG_ADDR(TIMER0_REG_BASE_ADDR, 0x03)
#define TIMER0_CAP_LOW						GET_REG_ADDR(TIMER0_REG_BASE_ADDR, 0x04)
#define TIMER0_CAP_HIGH						GET_REG_ADDR(TIMER0_REG_BASE_ADDR, 0x05)

#define HW_TIMER_DELAY_1us					1
#define HW_TIMER_DELAY_10us					10
#define HW_TIMER_DELAY_100us				100
#define HW_TIMER_DELAY_1ms					(1000 * HW_TIMER_DELAY_1us)
#define HW_TIMER_DELAY_5ms					(5    * HW_TIMER_DELAY_1ms)
#define HW_TIMER_DELAY_10ms					(10   * HW_TIMER_DELAY_1ms)
#define HW_TIMER_DELAY_100ms				(100  * HW_TIMER_DELAY_1ms)
#define HW_TIMER_DELAY_500ms				(500  * HW_TIMER_DELAY_1ms)
#define HW_TIMER_DELAY_1s					(1000 * HW_TIMER_DELAY_1ms)

extern void delay_us( unsigned us );
extern U32  nand_hw_timer_delay(U32 u32usTick);
extern U32 	nand_check_DDR_pad(void);

//=====================================================
// Pads Switch
//=====================================================
#define reg_nf_en                          GET_REG_ADDR(CHIPTOP_REG_BASE_ADDR, 0x06)
#define BIT_NAND_MODE_MASK                  (BIT15|BIT14|BIT13|BIT12|BIT1|BIT0)
#define BIT_NAND_MODE2                      (BIT1)
#define BIT_NAND_MODE1                      (BIT0)


#define reg_fcie2macro_sd_bypass            GET_REG_ADDR(CHIPTOP_REG_BASE_ADDR, 0x35)
#define BIT_SD_USE_BYPASS               	BIT7
#define BIT_FCIE2MACRO_SD_BYPASS        	BIT6
#define BIT_reg_emmc_rstn_en                BIT5
#define BIT_reg_emmc_rstn                   BIT4
#define BIT_PAD_IN_SEL_SD                   BIT1
#define BIT_PAD_IN_SEL_SDIO                 BIT0


#define reg_allpad_in						GET_REG_ADDR(CHIPTOP_REG_BASE_ADDR, 0x50)

#define BANK0014		                    (RIU_PM_BASE+(0xA00<<2))
#define REG_BANK0014_00		                GET_REG_ADDR(BANK0014, 0x00)
#define REG_BANK0014_01		                GET_REG_ADDR(BANK0014, 0x01)
#define REG_BANK0014_11		                GET_REG_ADDR(BANK0014, 0x11)
#define REG_BANK0014_0D		                GET_REG_ADDR(BANK0014, 0x0D)
#define POWERCUT_ADVAL		                0xD0


extern U32 nand_pads_switch(U32 u32EnableFCIE);

//=====================================================
// set FCIE clock
//=====================================================
#define DECIDE_CLOCK_BY_NAND			1

#define NFIE_CLK_300K           (0 << 2)
#define NFIE_CLK_750K           (1 << 2)
#define NFIE_CLK_5_4M           (2 << 2)
#define NFIE_CLK_13M            (3 << 2)
#define NFIE_CLK_18M            (4 << 2)
#define NFIE_CLK_22_7M          (5 << 2)
#define NFIE_CLK_27M            (6 << 2)
#define NFIE_CLK_32M            (7 << 2)
#define NFIE_CLK_43_2M          (8 << 2)
#define NFIE_CLK_54M            (9 << 2)
#define NFIE_CLK_72M            (10 << 2)
#define NFIE_CLK_86M            (11 << 2)
#define NFIE_CLK_XTAL           (13 << 2)
#define NFIE_CLK_62M            (14 << 2)

#define NFIE_CLK_TABLE_CNT    13
#define NFIE_CLK_TABLE    {NFIE_CLK_300K, NFIE_CLK_750K, NFIE_CLK_5_4M, NFIE_CLK_13M, \
                            NFIE_CLK_18M, NFIE_CLK_22_7M, NFIE_CLK_27M, NFIE_CLK_32M,\
                            NFIE_CLK_43_2M, NFIE_CLK_54M, NFIE_CLK_62M, NFIE_CLK_72M, NFIE_CLK_86M}

#define NFIE_CLK_TABLE_STR    {"300K", "750K", "5.4M", "13M", \
                            "18M", "22.7M", "27M", "32M",\
                            "43.2M", "54M", "62M", "72M", "86M"}

#define NFIE_300K_VALUE          300000
#define NFIE_750K_VALUE          750000
#define NFIE_5_4M_VALUE         5400000
#define NFIE_13M_VALUE        13000000
#define NFIE_18M_VALUE        18000000
#define NFIE_22_7M_VALUE    22700000
#define NFIE_27M_VALUE        27000000
#define NFIE_32M_VALUE        32000000
#define NFIE_43_2M_VALUE    43200000
#define NFIE_54M_VALUE        54000000
#define NFIE_62M_VALUE        62000000
#define NFIE_72M_VALUE        72000000
#define NFIE_86M_VALUE        86000000

#define NFIE_CLK_VALUE_TABLE    {    NFIE_300K_VALUE, NFIE_750K_VALUE, NFIE_5_4M_VALUE, NFIE_13M_VALUE, \
                            NFIE_18M_VALUE, NFIE_22_7M_VALUE, NFIE_27M_VALUE, NFIE_32M_VALUE, \
                            NFIE_43_2M_VALUE, NFIE_54M_VALUE, NFIE_62M_VALUE, NFIE_72M_VALUE, NFIE_86M_VALUE}


/*Define 1 cycle Time for each clock note: define value must be the (real value -1)*/
#define NFIE_1T_300K        3332
#define NFIE_1T_750K        1332
#define NFIE_1T_5_4M        184
#define NFIE_1T_13M            76
#define NFIE_1T_18M            55
#define NFIE_1T_22_7M        43
#define NFIE_1T_27M            37
#define NFIE_1T_32M            31
#define NFIE_1T_43_2M        23
#define NFIE_1T_54M            18
#define NFIE_1T_62M            15
#define NFIE_1T_72M            13
#define NFIE_1T_86M            11

#define NFIE_1T_TABLE    {NFIE_1T_300K, NFIE_1T_750K, NFIE_1T_5_4M, NFIE_1T_13M,    \
                            NFIE_1T_18M, NFIE_1T_22_7M, NFIE_1T_27M, NFIE_1T_32M, \
                            NFIE_1T_43_2M, NFIE_1T_54M, NFIE_1T_62M, NFIE_1T_72M, NFIE_1T_86M}

#if 0
#define NFIE_4CLK_TABLE_CNT	8
#define NFIE_4CLK_TABLE	{	NFIE_CLK_6M, NFIE_CLK_27M, NFIE_CLK_36M, \
							NFIE_CLK_40M, NFIE_CLK_48M, NFIE_CLK_54M, \
							NFIE_CLK_60M, NFIE_CLK_75M}

#define NFIE_4CLK_TABLE_STR	{	"6M", "27M", "36M", \
							"40M", "48M", "54M", \
							"60M", "75M"}

#define NFIE_4CLK_VALUE_TABLE	{ 	NFIE_6M_VALUE, NFIE_27M_VALUE, NFIE_36M_VALUE, \
								 	NFIE_40M_VALUE, NFIE_48M_VALUE, NFIE_54M_VALUE, \
								 	NFIE_60M_VALUE, NFIE_75M_VALUE}

#define NFIE_4CLK_1T_TABLE	{	NFIE_1T_6M, NFIE_1T_27M, NFIE_1T_36M, \
								NFIE_1T_40M, NFIE_1T_48M, NFIE_1T_54M, \
								NFIE_1T_60M, NFIE_1T_75M}
#endif

#define DUTY_CYCLE_PATCH					0 // 1: to enlarge low width for tREA's worst case of 25ns
#if DUTY_CYCLE_PATCH
#define FCIE3_SW_DEFAULT_CLK				NFIE_CLK_86M
#define FCIE_REG41_VAL						((2<<9)|(2<<3)) // RE,WR pulse, Low:High=3:1
#define REG57_ECO_FIX_INIT_VALUE			0
#else
#define FCIE3_SW_DEFAULT_CLK				NFIE_CLK_54M
#define FCIE_REG41_VAL						0               // RE,WR pulse, Low:High=1:1
#define REG57_ECO_FIX_INIT_VALUE			BIT_NC_LATCH_DATA_1_0_T	// delay 1.0T
#endif
#define FCIE3_SW_SLOWEST_CLK                NFIE_CLK_18M

#define NAND_SEQ_ACC_TIME_TOL				16 //in unit of ns

#define reg_ckg_fcie						GET_REG_ADDR(MPLL_CLK_REG_BASE_ADDR, 0x64)
#define EMMC_CLK_MASK						(BIT12|BIT11|BIT10)
#define REG_CLK_EMMC						GET_REG_ADDR(MPLL_CLK_REG_BASE_ADDR, 0x64)

extern U32  nand_clock_setting(U32 u32ClkParam);

extern void nand_DumpPadClk(void);

//=====================================================
// transfer DMA Address
//=====================================================
#define MIU_BUS_WIDTH_BITS					3 // Need to confirm

#define MIU_CHECK_LAST_DONE					1

//=====================================================
// misc
//=====================================================
//#define BIG_ENDIAN
#define LITTLE_ENDIAN

typedef struct NAND_DRIVER_PLATFORM_DEPENDENT
{
	U8 *pu8_PageSpareBuf;
	U8 *pu8_PageDataBuf;
	U32	u32_DMAAddrOffset;
	U32	u32_RAMBufferOffset;
	U32	u32_RAMBufferLen;

}NAND_DRIVER_PLAT_CTX, *P_NAND_DRIVER_PLAT;

#define NC_REG_MIU_LAST_DONE				NC_MIE_EVENT

#define NANDINFO_ECC_TYPE                   ECC_TYPE_40BIT1KB
#define  malloc(x) kmalloc(x, GFP_KERNEL)
#define free kfree

#endif
