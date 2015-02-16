#include <stdio.h>
#include <conio.h>

 void main()
{
 float A,B,S,I;
 clrscr();


for (I=1;I<=5;I++)
 {
    printf("\n Ingrese el primer cateto: ");
    scanf("%f",&A);
    printf("\n Ingrese el segundo cateto: ");
    scanf("%f",&B);
    S=((A*B)/2);
    printf("\n La superficie del triángulo vale: %.2f \n\n",S);
 }

 getch();
}