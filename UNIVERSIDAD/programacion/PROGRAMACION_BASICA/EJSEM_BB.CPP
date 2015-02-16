#include <stdio.h>
#include <conio.h>
#include <math.h>

 void main()
{
 float a,b,h;
 clrscr();
 printf("\n Ingrese el primer cateto: ");
 scanf("%f",&a);
 printf("\n Ingrese el segundo cateto: ");
 scanf("%f",&b);

 if (a!=b)
 {
   h=sqrt((a*a)+(b*b));
   printf("\n \n La hipotenusa vale:  %.2f",h);
 }
 else
   printf("\n \n Los dos valores son iguales");
 getch();
}
