
  //apuntadores.
#include<stdio.h>
#include<conio.h>
void main()
			{
			 clrscr();
			 int x,*p,**q,***i;
			 x=10;
			 textcolor(18);
			 cprintf("direccion= %x      contenido=%d\n", &x,x);
			 p=&x;
			 *p=20;
			 printf("direccion del apuntador=%x,direccion del apuntado=%x,contenido=%d\n", &p,p,*p);
			 q=&p;
			 **q=30;
			 printf("direccion apuntado%x, direccion apunta=%x, contenido=%d\n", &q,q,**q);
			 i=&q;
			 ***i=40;
			 printf("direccion apuntado%x, direccion apunta=%x, contenido=%d\n", &i,i,***i);
			 getch();
			}
