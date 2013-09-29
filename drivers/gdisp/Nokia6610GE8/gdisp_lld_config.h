/*
 * This file is subject to the terms of the GFX License. If a copy of
 * the license was not distributed with this file, you can obtain one at:
 *
 *              http://ugfx.org/license.html
 */

/**
 * @file    drivers/gdisp/Nokia6610GE8/gdisp_lld_config.h
 * @brief   GDISP Graphic Driver subsystem low level driver header for the Nokia6610 GE8 display.
 *
 * @addtogroup GDISP
 * @{
 */

#ifndef _GDISP_LLD_CONFIG_H
#define _GDISP_LLD_CONFIG_H

#if GFX_USE_GDISP 

/*===========================================================================*/
/* Driver hardware support.                                                  */
/*===========================================================================*/

#define GDISP_DRIVER_NAME				"Nokia6610GE8"
#define GDISP_DRIVER_STRUCT				GDISP_Nokia6610GE8

#ifndef GDISP_NOKIA_ORIENTATION
	#define GDISP_NOKIA_ORIENTATION			TRUE
#endif

#if GDISP_NOKIA_ORIENTATION && GDISP_NEED_CONTROL
	#define GDISP_HARDWARE_CONTROL			TRUE
	#define GDISP_HARDWARE_DRAWPIXEL		TRUE
	#define GDISP_HARDWARE_FILLS			TRUE
	#define GDISP_HARDWARE_BITFILLS			TRUE
#else
	#define GDISP_HARDWARE_CONTROL			TRUE
	#define GDISP_HARDWARE_STREAM_WRITE		TRUE
#endif

#define GDISP_PIXELFORMAT				GDISP_PIXELFORMAT_RGB444
/* This driver supports both packed and unpacked pixel formats and line formats.
 * 	By default we leave these as FALSE.
 */
#define GDISP_PACKED_PIXELS				FALSE
#define GDISP_PACKED_LINES				FALSE

#endif	/* GFX_USE_GDISP */

#endif	/* _GDISP_LLD_CONFIG_H */
/** @} */
