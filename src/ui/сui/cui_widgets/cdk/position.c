#include <cdk_int.h>

/*
 * $Author: tom $
 * $Date: 2011/05/15 19:43:38 $
 * $Revision: 1.13 $
 */

#undef	ObjOf
#define ObjOf(ptr)    (ptr)

/*
 * This allows the user to use the cursor keys to adjust the
 * position of the widget.
 */
void positionCDKWidget (CDKOBJS *obj, WINDOW *win)
{
   /* *INDENT-EQLS* */
   CDKSCREEN *screen = ScreenOf (obj);
   WINDOW *parent    = screen->window;
   int origX         = getbegx (win);
   int origY         = getbegy (win);
   int begX          = getbegx (parent);
   int begY          = getbegy (parent);
   int endX          = begX + getmaxx (WindowOf (obj));
   int endY          = begY + getmaxy (WindowOf (obj));

   chtype key;
   boolean functionKey;

   /* Let them move the widget around until they hit return. */
   while ((key = (chtype)getchCDKWidget (obj, &functionKey)) != KEY_ENTER)
   {
      switch (key)
      {
      case KEY_UP:
      case '8':
	 if (getbegy (win) > begY)
	 {
	    moveCDKWidget (obj, 0, -1, TRUE, TRUE);
	 }
	 else
	 {
	    Beep ();
	 }
	 break;
      case KEY_DOWN:
      case '2':
	 if (getendy (win) < endY)
	 {
	    moveCDKWidget (obj, 0, 1, TRUE, TRUE);
	 }
	 else
	 {
	    Beep ();
	 }
	 break;
      case KEY_LEFT:
      case '4':
	 if (getbegx (win) > begX)
	 {
	    moveCDKWidget (obj, -1, 0, TRUE, TRUE);
	 }
	 else
	 {
	    Beep ();
	 }
	 break;
      case KEY_RIGHT:
      case '6':
	 if (getendx (win) < endX)
	 {
	    moveCDKWidget (obj, 1, 0, TRUE, TRUE);
	 }
	 else
	 {
	    Beep ();
	 }
	 break;
      case '7':
	 if (getbegy (win) > begY && getbegx (win) > begX)
	 {
	    moveCDKWidget (obj, -1, -1, TRUE, TRUE);
	 }
	 else
	 {
	    Beep ();
	 }
	 break;
      case '9':
	 if (getendx (win) < endX && getbegy (win) > begY)
	 {
	    moveCDKWidget (obj, 1, -1, TRUE, TRUE);
	 }
	 else
	 {
	    Beep ();
	 }
	 break;
      case '1':
	 if (getbegx (win) > begX && getendy (win) < endY)
	 {
	    moveCDKWidget (obj, -1, 1, TRUE, TRUE);
	 }
	 else
	 {
	    Beep ();
	 }
	 break;
      case '3':
	 if (getendx (win) < endX && getendy (win) < endY)
	 {
	    moveCDKWidget (obj, 1, 1, TRUE, TRUE);
	 }
	 else
	 {
	    Beep ();
	 }
	 break;
      case '5':
	 moveCDKWidget (obj, CENTER, CENTER, FALSE, TRUE);
	 break;
      case 't':
	 moveCDKWidget (obj, getbegx (win), TOP, FALSE, TRUE);
	 break;
      case 'b':
	 moveCDKWidget (obj, getbegx (win), BOTTOM, FALSE, TRUE);
	 break;
      case 'l':
	 moveCDKWidget (obj, LEFT, getbegy (win), FALSE, TRUE);
	 break;
      case 'r':
	 moveCDKWidget (obj, RIGHT, getbegy (win), FALSE, TRUE);
	 break;
      case 'c':
	 moveCDKWidget (obj, CENTER, getbegy (win), FALSE, TRUE);
	 break;
      case 'C':
	 moveCDKWidget (obj, getbegx (win), CENTER, FALSE, TRUE);
	 break;
      case CDK_REFRESH:
	 eraseCDKScreen (ScreenOf (obj));
	 refreshCDKScreen (ScreenOf (obj));
	 break;
      case KEY_ESC:
	 moveCDKWidget (obj, origX, origY, FALSE, TRUE);
	 break;
      default:
	 Beep ();
	 break;
      }
   }
}
