#include <conio.h>

int main(void)
{
   struct text_info ti;
      gettextinfo(&ti);
	 cprintf("window left      %2d\r\n",ti.winleft);
	    cprintf("window top       %2d\r\n",ti.wintop);
	       cprintf("window right     %2d\r\n",ti.winright);
		  cprintf("window bottom    %2d\r\n",ti.winbottom);
		     cprintf("attribute        %2d\r\n",ti.attribute);
			cprintf("normal attribute %2d\r\n",ti.normattr);
			   cprintf("current mode     %2d\r\n",ti.currmode);
			      cprintf("screen height    %2d\r\n",ti.screenheight);
				 cprintf("screen width     %2d\r\n",ti.screenwidth);
				    cprintf("current x        %2d\r\n",ti.curx);
				       cprintf("current y        %2d\r\n",ti.cury);
					  return 0;
					  }
