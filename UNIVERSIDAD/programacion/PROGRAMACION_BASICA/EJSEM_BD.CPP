#include <stdio.h>
#include <conio.h>
#include <math.h>

 void main()
{
 float a,b,h;
 clrscr();
 printf("\n Ingrese el primer cateto (cero para salir): ");
 scanf("%f",&a);
 printf("\n Ingrese el segundo cateto (cero para salir): ");
 scanf("%f",&b);

while ((a!=0)&&(b!=0))
 {
   h=sqrt((a*a)+(b*b));
   printf("\n La hipotenusa vale:  %.2f \n\n",h);

   printf("\n Ingrese el primer cateto (cero para salir): ");
   scanf("%f",&a);
   printf("\n Ingrese el segundo cateto (cero para salir): ");
   scanf("%f",&b);

 }

 getch();
}