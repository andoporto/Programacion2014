/*Programa que calcula x1 y x2 en una ecuaci•n cuadratica*/
#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
		  {
		   float x1,x2;
		   int a,b,c;
		   clrscr();
		   printf("Programa que calcula el valor de x1 y x2 en una ecuaci•n\n");
		   printf(" cuadratica. Acontinuaci•n ingresa el valor de a: ");
		   scanf("%d", &a);
		   printf("Ahora ingresa el valor de b: ");
		   scanf("%d", &b);
		   printf(" Por ultimo, ingresa el valor de c: ");
		   scanf("%d", &b);
		   x1=sqrt((4*a*c)+b)/(2*a)+(-b);
		   x2=sqrt((4*a*c)+b)/(2*a)+b;
		   printf("El valor de x1=%f\n", x1);
		   printf("El valor de x2=%f", x2);
		   getch();
		  }



