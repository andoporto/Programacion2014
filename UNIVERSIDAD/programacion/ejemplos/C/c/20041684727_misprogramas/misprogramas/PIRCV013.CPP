/*Programa que lee 3 cantidadesy determina cual es el mayor, y tambi�n si hay
n�meros iguales*/
#include<stdio.h>
#include<conio.h>
void main()
		  {
		   int num1,num2,num3;
		   clrscr();
		   printf("Este programa compara 3 cantidades, determina cual es el mayor\n");
		   printf(" o bien, si son iguales.");
		   printf(" Acontinuaci�n escribe los valores de los n�meros.\n");
		   printf(" Dame el valor de el n�mero 1: ");
		   scanf("%d", &num1);
		   printf("Dame el valor del n�mero 2: ");
		   scanf("%d", &num2);
		   printf("Dame el valor del n�mero 3: ");
		   scanf("%d", &num3);
		   if ((num1>num2)&&(num1>num3)&&(num2>num3))
			  printf("El mayor es el n�mero 1 y el menor es el n�mero 3");
			  if ((num1>num2)&&(num1>num3)&&(num3>num2))
				 printf("El mayor es el n�mero 1 y el menor es el n�mero 2");
				 if ((num2>num1)&&(num2>num3)&&(num1>num3))
					printf(" el mayor es el n�mero 2 y el menor es el n�mero 3");
					if ((num2>num1)&&(num2>num3)&&(num3>num1))
					   printf("El mayor es el n�mero 2 y el menor es el n�mero 1");
					   if ((num3>num1)&&(num3>num2)&&(num1>num2))
						  printf("El mayor es el n�mero 3 y el menor es el n�mero 2");
						  if ((num3>num1)&&(num3>num2)&&(num2>num1))
							 printf("El mayor es el n�mero 3 y el menor es el n�mero 1");
							 if(num1==num2)
							   printf("El n�mero 1 y el numero2 son iguales");
							   if (num1==num3)
								  printf("El n�mero 1 y le n�mero 3 son iguales");
								  if (num2==num3)
									  printf("El n�mero 2 y el n�mero 3 son iguales");
		   getch();
		  }



