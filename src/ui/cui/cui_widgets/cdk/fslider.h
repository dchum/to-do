/*
 * $Id: gen-slider.h,v 1.10 2025/01/09 00:20:21 tom Exp $
 */

#ifndef CDKINCLUDES
#ifndef CDKFSLIDER_H
#define CDKFSLIDER_H	1

#ifdef __cplusplus
extern "C" {
#endif

#ifndef CDK_H
#define CDKINCLUDES
#include <cdk.h>
#undef CDKINCLUDES
#include <binding.h>
#include <cdkscreen.h>
#include <cdk_objs.h>
#endif

/*
 * Copyright 2004-2012,2025 Thomas E. Dickey
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, distribute with
 * modifications, sublicense, and/or sell copies of the Software, and to permit
 * persons to whom the Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
 * ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR
 * IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * Except as contained in this notice, the name(s) of the above copyright
 * holders shall not be used in advertising or otherwise to promote the sale,
 * use or other dealings in this Software without prior written authorization.
 */

/*
 * Define the CDK widget FSlider structure.
 */
struct SFSlider {
   CDKOBJS	obj;
   WINDOW *	parent;
   WINDOW *	win;
   WINDOW *	shadowWin;
   WINDOW *	fieldWin;
   WINDOW *	labelWin;
   int		titleAdj;
   chtype *	label;
   int		labelLen;
   int		boxHeight;
   int		boxWidth;
   int		fieldWidth;
   int		fieldEdit;	/* offset from right-margin of field */
   chtype	filler;
   float	low;
   float	high;
   float	inc;
   float	fastinc;
   float	current;
   int		digits;
   EExitType	exitType;
   boolean	shadow;
};
typedef struct SFSlider CDKFSLIDER;

/*
 * This creates a new pointer to a CDK float-FSlider widget.
 */
CDKFSLIDER *newCDKFSlider (
		CDKSCREEN *	/* cdkscreen */,
		int		/* xpos */,
		int		/* ypos */,
		const char *	/* title */,
		const char *	/* label */,
		chtype		/* fieldAttr */,
		int		/* fieldWidth */,
		float		/* start */,
		float		/* low */,
		float		/* high */,
		float		/* inc */,
		float		/* fastInc */,
		int		/* digits */,
		boolean		/* Box */,
		boolean		/* shadow */);

/*
 * This activates the widget.
 */
float activateCDKFSlider (
		CDKFSLIDER *	/* widget */,
		chtype *	/* actions */);

/*
 * This injects a single character into the widget.
 */
#define injectCDKFSlider(obj,input) injectCDKWidget(obj,input,Float)

/*
 * This sets various attributes of the widget.
 */
void setCDKFSlider (
		CDKFSLIDER *	/* widget */,
		float		/* low */,
		float		/* high */,
		float		/* value */,
		boolean		/* Box */);

/*
 * These set/get the low and high values.
 */
void setCDKFSliderLowHigh (
		CDKFSLIDER *	/* widget */,
		float		/* low */,
		float		/* high */);

float getCDKFSliderLowValue (
		CDKFSLIDER *	/* widget */);

float getCDKFSliderHighValue (
		CDKFSLIDER *	/* widget */);

/*
 * These set/get the digits.
 */
void setCDKFSliderDigits (
		CDKFSLIDER *	/* widget */,
		int		/* digits */);

int getCDKFSliderDigits (
		CDKFSLIDER *	/* widget */);

/*
 * These set/get the current value.
 */
void setCDKFSliderValue (
		CDKFSLIDER *	/* widget */,
		float		/* value */);

float getCDKFSliderValue (
		CDKFSLIDER *	/* widget */);

/*
 * This sets the box attribute of the widget.
 */
void setCDKFSliderBox (
		CDKFSLIDER *	/* widget */,
		boolean		/* Box */);

boolean getCDKFSliderBox (
		CDKFSLIDER *	/* widget */);

/*
 * These set the drawing characters of the widget.
 */
#define setCDKFSliderULChar(w,c)            setULCharOf(w,c)
#define setCDKFSliderURChar(w,c)            setURCharOf(w,c)
#define setCDKFSliderLLChar(w,c)            setLLCharOf(w,c)
#define setCDKFSliderLRChar(w,c)            setLRCharOf(w,c)
#define setCDKFSliderVerticalChar(w,c)      setVTCharOf(w,c)
#define setCDKFSliderHorizontalChar(w,c)    setHZCharOf(w,c)
#define setCDKFSliderBoxAttribute(w,c)      setBXAttrOf(w,c)

/*
 * This sets the background color of the widget.
 */
#define setCDKFSliderBackgroundColor(w,c) setCDKWidgetBackgroundColor(ObjOf(w),c)

/*
 * This sets the background attribute of the widget.
 */
#define setCDKFSliderBackgroundAttrib(w,c) setBKAttrOf(w,c)

/*
 * This draws the widget on the screen.
 */
#define drawCDKFSlider(obj,Box) drawCDKWidget(obj,Box)

/*
 * This erases the widget from the screen.
 */
#define eraseCDKFSlider(obj) eraseCDKWidget(obj)

/*
 * This moves the widget to the given location on the screen.
 */
#define moveCDKFSlider(obj,xpos,ypos,relative,refresh) moveCDKWidget(obj,xpos,ypos,relative,refresh)

/*
 * This allows the user to interactively position the widget on the screen.
 */
#define positionCDKFSlider(widget) positionCDKWidget(ObjOf(widget),widget->win)

/*
 * This destroys the widget and associated memory.
 */
#define destroyCDKFSlider(obj) destroyCDKWidget(obj)

/*
 * These set the pre/post process callback functions.
 */
#define setCDKFSliderPreProcess(w,f,d)  setCDKWidgetPreProcess(ObjOf(w),f,d)
#define setCDKFSliderPostProcess(w,f,d) setCDKWidgetPostProcess(ObjOf(w),f,d)

#ifdef __cplusplus
}
#endif

#endif /* CDKFSLIDER_H */
#endif /* CDKINCLUDES */
