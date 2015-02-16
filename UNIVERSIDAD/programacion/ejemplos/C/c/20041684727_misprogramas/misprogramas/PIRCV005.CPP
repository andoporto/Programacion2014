/*Programa que resuelve ecuaciones de 2§ grado con valores enteros positivos
introducidos por el usuario*/
#include<stdio.h>
#include<conio.h>
void main()
		  {
		  int a,b,c,x;
		   clrscr();
		   printf("Este programa te ayuda a c…lcular una ecuaci•n");
		   printf(" de 2§ grado con valores enteros positivos\n");
		   printf("introduce el valor de a: \n");
		   scanf("%d", &a);
		   printf("introduce el valor de b: \n");
		   scanf("%d", &b);
		   printf("introduce el valor de c: \n");
		   scanf("%d", &c);
		   x=(a*a)+(2*(a*b))+(c*c);
		   printf("El valor de x= %d", x);
		   getch();
		  }