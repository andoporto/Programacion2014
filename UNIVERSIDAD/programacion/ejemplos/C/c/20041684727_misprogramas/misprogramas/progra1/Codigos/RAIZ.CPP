#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
clrscr();
float x,r,q;
	printf("Programa que calcula el valor de la raiz de x\n");
	printf("\nDame el valor de x:   ");
	scanf("%f",&x);
	r=x/2;
do
	{
		 r=0.5*(r+(x/r));
		 printf(" %f ",r);
	}
	while(fabs(x-(r*r))>0.001);
printf("\n\tLa raiz de %.2f es: %.4f",x,r);
getch();
}

