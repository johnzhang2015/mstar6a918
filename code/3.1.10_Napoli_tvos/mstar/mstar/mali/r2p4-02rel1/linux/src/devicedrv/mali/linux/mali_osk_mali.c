/*
 * Copyright (C) 2010-2012 ARM Limited. All rights reserved.
 * 
 * This program is free software and is provided to you under the terms of the GNU General Public License version 2
 * as published by the Free Software Foundation, and any use by you of this program is subject to the terms of such GNU licence.
 * 
 * A copy of the licence is included with the program, and can also be obtained from Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

/**
 * @file mali_osk_mali.c
 * Implementation of the OS abstraction layer which is specific for the Mali kernel device driver
 */
#include <linux/kernel.h>
#include <asm/uaccess.h>

#include "mali_kernel_common.h" /* MALI_xxx macros */
#include "mali_osk.h"           /* kernel side OS functions */
#include "mali_uk_types.h"
#include "mali_kernel_linux.h"  /* exports initialize/terminate_kernel_device() definition of mali_osk_low_level_mem_init() and term */
#include "arch/config.h"        /* contains the configuration of the arch we are compiling for */

#ifdef MSTAR
static _mali_osk_errcode_t _mstar_get_mmap( u32 num_resources, _mali_osk_resource_t *arch_config );
#endif

/* is called from mali_kernel_constructor in common code */
_mali_osk_errcode_t _mali_osk_init( void )
{
	if (0 != initialize_kernel_device()) MALI_ERROR(_MALI_OSK_ERR_FAULT);

	mali_osk_low_level_mem_init();
	
	MALI_SUCCESS;
}

/* is called from mali_kernel_deconstructor in common code */
void _mali_osk_term( void )
{
	mali_osk_low_level_mem_term();
	terminate_kernel_device();
}

_mali_osk_errcode_t _mali_osk_resources_init( _mali_osk_resource_t **arch_config, u32 *num_resources )
{
    *num_resources = sizeof(arch_configuration) / sizeof(arch_configuration[0]);
    *arch_config = arch_configuration;

#ifdef MSTAR
    if (_mstar_get_mmap(*num_resources, *arch_config) != _MALI_OSK_ERR_OK)
    {
        MALI_ERROR(_MALI_OSK_ERR_FAULT);
    }
#endif /* MSTAR */

    return _MALI_OSK_ERR_OK;
}

void _mali_osk_resources_term( _mali_osk_resource_t **arch_config, u32 num_resources )
{
    /* Nothing to do */
}

#ifdef MSTAR
_mali_osk_errcode_t _mstar_get_mmap( u32 num_resources, _mali_osk_resource_t *arch_config )
{
#if defined(MSTAR_GLADIUS)
    int i;

    for (i = 0; i < num_resources; i++)
    {
        if (MEM_VALIDATION == arch_config[i].type)
        {
            arch_config[i].base = 0x00000000;
            arch_config[i].size = 0xfffff000;
        }
    }
#endif

    return _MALI_OSK_ERR_OK;
}
#endif /* MSTAR */
