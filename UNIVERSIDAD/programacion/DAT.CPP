#include <stdio.h>
#include <conio.h>


 void main ()
 {

   int i;
   int dni;
   int p2;
   int p1;

   for (i=0; i<3;i++)
   {
    textcolor(BLUE);   /*color de los scanf*/
    clrscr();

    textcolor(GREEN);
    cprintf("Ingrese DNI: ");
    scanf("%d",dni);

    textcolor(YELLOW);
    cprintf("Ingrese parcial 1: ");
    scanf("%d",p1);

    textcolor(MAGENTA);
    cprintf("Ingrese parcial 2: ");
     scanf("%d",p2);
     }
    }