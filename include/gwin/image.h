/*
 * This file is subject to the terms of the GFX License. If a copy of
 * the license was not distributed with this file, you can obtain one at:
 *
 *              http://chibios-gfx.com/license.html
 */

/**
 * @file	include/gwin/image.h
 * @brief	GWIN image widget header file.
 *
 * @defgroup Image Image
 * @ingroup GWIN
 *
 * @details		GWIN allos it to create an image widget. The widget
 *				takes no user input.
 *
 * @pre			GFX_USE_GDISP must be set to TRUE in your gfxconf.h
 * @pre			GFX_USE_GWIN must be set to TRUE in your gfxconf.h
 * @pre			GDISP_NEED_IMAGE must be set to TRUE in your gfxconf.h
 * @pre			GWIN_NEED_IMAGE must be set to TRUE in your gfxconf.h
 * @pre			At least one image type must be enabled in your gfxconf.h
 *
 * @{
 */

#ifndef _GWIN_IMAGE_H
#define _GWIN_IMAGE_H

// This file is included within "gwin/gwin.h"

// An image window
typedef struct GImageWidget_t {
	GWindowObject	g;

	gdispImage		*image;
	color_t			bgColor;
} GImageWidget;

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief				Create an image widget.
 * @details				A console widget allows to display a picture.
 * @return				NULL if there is no resultant drawing area, otherwise the widget handle.
 *
 * @param[in] widget	The image widget structure to initialise. If this is NULL, the structure is dynamically allocated.
 * @param[in] pInit		The initialization parameters to use.
 *
 * @note				The default background color gets set to the current default one.
 * @note				An image widget does not save the current drawing state. It is not automatically redrawn if the window
 *						is moved or its visibility state is changed.
 *
 * @api
 */	
GHandle gwinImageCreate(GImageWidget *widget, GWindowInit *pInit);

/**
 * @brief				Sets the sets the io fields in the image structure to routines that support reading from an image stored
 *						in RAM or flash.
 * @return				TRUE if the IO open function succeeds
 *
 * @param[in] gh		The widget (must be an image widget)
 * @param[in[ memory	A pointer to the image in RAM or Flash
 *
 * @api
 */
bool_t gwinImageOpenMemory(GHandle gh, const void* memory);

#if defined(WIN32) || GFX_USE_OS_WIN32 || GFX_USE_OS_POSIX || defined(__DOXYGEN__)
	/**
	 * @brief				Sets the sets the io fields in the image structure to routines that support reading from an image stored
	 *						in a simulators native file system.
	 * @return				TRUE if the IO open function succeeds
	 *
	 * @param[in] gh		The widget (must be an image widget)
	 * @param[in[ memory	The filename to open
	 *
	 * @api
	 */
	bool_t gwinImageOpenFile(GHandle gh, const char* filename);
#endif

#if GFX_USE_OS_CHIBIOS || defined(__DOXYGEN__)
	/**
	 * @brief				Sets the sets the io fields in the image structure to routines that support reading from an image stored
	 *						on a BaseFileStream (eg. an SD-Card).
	 * @return				TRUE if the IO open function succeeds
	 *
	 * @param[in] gh		The widget (must be an image widget)
	 * @param[in[ memory	A pointer to the (open) BaseFileStream object.
	 *
	 * @api
	 */
	bool_t gwinImageOpenStream(GHandle gh, void *streamPtr);
#endif

/**
 * @brief				Cache an image.
 * @details				Decodes and caches the current frame into RAM.
 *
 * param[in] gh			The widget (must be an image widget)
 *
 * @return				GDISP_IMAGE_ERR_OK (0) on success or an error code.
 *
 * @api
 */
gdispImageError gwinImageCache(GHandle gh);

/**
 * @brief				Set the background color of an image widget.
 * @details				Transparent images need a background color. If no background color has been set, the current default
 *						on is used.
 *
 * @param[in] gh		The widget (must be an image widget)
 * @param[in] bgColor	The background color to be set
 *
 * @api
 */
void gwinImageSetBgColor(GHandle gh, color_t bgColor);

void gwinImageDraw(GHandle gh);

#ifdef __cplusplus
}
#endif

#endif // _GWIN_IMAGE_H
/** @} */

