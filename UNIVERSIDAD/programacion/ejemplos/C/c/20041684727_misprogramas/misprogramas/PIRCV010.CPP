/*Programa que c…lcula el promŠdio de 5 calificaciones dadas por el usuario*/
#include<stdio.h>
#include<conio.h>
void main()
		  {
		   float c1,c2,c3,c4,c5,prom;
		   clrscr();
		   printf("Programa para c…lcular el promedio de 5 calificaciones\n");
		   printf("Dame la calificaci•n 1: ");
		   scanf ("%f", &c1);
		   printf("Dame la calificaci•n 2: ");
		   scanf("%f", &c2);
		   printf("Dame la calificaci•n 3: ");
		   scanf("%f", &c3);
		   printf("Dame la calificaci•n 4: ");
		   scanf("%f", &c4);
		   printf("Dame la calificaci•n 5: ");
		   scanf("%f", &c5);
		   prom=(c1+c2+c3+c4+c5)/5;
		   printf("El promedio es:%f ", prom);
		   getch();
		  }
