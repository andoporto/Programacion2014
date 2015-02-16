/*Programa que lee 3 cantidadesy determina cual es el mayor, y tambiän si hay
nómeros iguales*/
#include<stdio.h>
#include<conio.h>
void main()
		  {
		   int num1,num2,num3;
		   clrscr();
		   printf("Este programa compara 3 cantidades, determina cual es el mayor\n");
		   printf(" o bien, si son iguales.");
		   printf(" Acontinuaciïn escribe los valores de los nómeros.\n");
		   printf(" Dame el valor de el nómero 1: ");
		   scanf("%d", &num1);
		   printf("Dame el valor del nómero 2: ");
		   scanf("%d", &num2);
		   printf("Dame el valor del nómero 3: ");
		   scanf("%d", &num3);
		   if ((num1>num2)&&(num1>num3)&&(num2>num3))
			  printf("El mayor es el nómero 1 y el menor es el nómero 3");
			  if ((num1>num2)&&(num1>num3)&&(num3>num2))
				 printf("El mayor es el nómero 1 y el menor es el nómero 2");
				 if ((num2>num1)&&(num2>num3)&&(num1>num3))
					printf(" el mayor es el nómero 2 y el menor es el nómero 3");
					if ((num2>num1)&&(num2>num3)&&(num3>num1))
					   printf("El mayor es el nómero 2 y el menor es el nómero 1");
					   if ((num3>num1)&&(num3>num2)&&(num1>num2))
						  printf("El mayor es el nómero 3 y el menor es el nómero 2");
						  if ((num3>num1)&&(num3>num2)&&(num2>num1))
							 printf("El mayor es el nómero 3 y el menor es el nómero 1");
							 if(num1==num2)
							   printf("El n£mero 1 y el numero2 son iguales");
							   if (num1==num3)
								  printf("El nómero 1 y le nómero 3 son iguales");
								  if (num2==num3)
									  printf("El nómero 2 y el nómero 3 son iguales");
		   getch();
		  }



