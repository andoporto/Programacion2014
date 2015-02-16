/*Programa que lee 2 numeros y nos dice cual es el mayor, o bien, si son iguales*/
#include<stdio.h>
#include<conio.h>
void main()
		  {
		   int num1,num2;
		   clrscr();
		   printf("Programa que lee 2 n—meros y determina cual es el mayor,\n");
		   printf(" o bien, si son iguales. Teclea el primer n—mero: ");
		   scanf("%d", &num1);
		   printf("Teclea el segundo n—mero: ");
		   scanf("%d", &num2);
		   if (num1==num2)
			   printf("Los dos n—meros son iguales");
			   if (num1>num2)
				  printf(" El primer n—mero es mayor que el segundo");
				  if (num1<num2)
				  printf("El segundo n—mero es mayor que el primero");
		   getch();
		  }