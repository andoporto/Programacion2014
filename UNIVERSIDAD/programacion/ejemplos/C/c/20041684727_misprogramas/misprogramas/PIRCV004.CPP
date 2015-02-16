/*Programa que sive para calcular el Örea y el perçmetro de un circulo*/
#include<stdio.h>
#include<conio.h>
void main()
		   {
			float a,p,r;
			const float pi=3.141632;
			clrscr();
			printf("Este programa cÖlcula el Örea y el perçmetro\n");
			printf(" de un circulo, escribe el valor del rÖdio: ");
			scanf("%f", &r);
			a=2*(pi*r);
			p=pi*(r*r);
			printf("El Örea es:%f\n", a);
			printf("El perimetro es:%f",p);
			getch();
		   }