/*Programa que sive para calcular el �rea y el per�metro de un circulo*/
#include<stdio.h>
#include<conio.h>
void main()
		   {
			float a,p,r;
			const float pi=3.141632;
			clrscr();
			printf("Este programa c�lcula el �rea y el per�metro\n");
			printf(" de un circulo, escribe el valor del r�dio: ");
			scanf("%f", &r);
			a=2*(pi*r);
			p=pi*(r*r);
			printf("El �rea es:%f\n", a);
			printf("El perimetro es:%f",p);
			getch();
		   }