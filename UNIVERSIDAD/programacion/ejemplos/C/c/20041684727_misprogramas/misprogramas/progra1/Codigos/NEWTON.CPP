//Fernando Sánchez Galindo
//I.S.C. 2º semestre ITESU
//Programa que calcula raiz de x por el metodo de 	newwton

#include<stdio.h>
#include<conio.h>
#include<math.h>

void main()
{
clrscr();
int x;
double r,aprox,y;
const float error=0.001;
	printf("Programa que calcula el valor de la raiz de x\n");
	printf("Dame el valor de x:   ");
	scanf("%f",&x);
	   r=x/2;
		do
		{
		 r=(r+(x/r))/2;
		aprox=(r*r);
		y=x-aprox;
		}while((abs(y))>=error);

	printf("El valor es:   %f",r);

getch();
}

