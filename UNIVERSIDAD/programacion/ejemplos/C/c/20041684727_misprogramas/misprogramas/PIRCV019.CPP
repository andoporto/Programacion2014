/*Programa que lee un n—mero entero y deterna si es divisible entre 3,5,7*/
#include<stdio.h>
#include<conio.h>
void main()
		  {
		   int num;
		   clrscr();
		   printf("Este programa analiza un n—mero y  te muestra si es divisible\n");
		   printf(" entre 3, 5, y 7. teclea por favor un n—mero entero positivo: ");
		   scanf("%d", &num);
		   if ((num%3==0)&&(num%5==0)&&(num%7==0))
			  printf("Es divisible entre 3, 5 y 7.");
			  if (num%3==0)
				 printf("Es divisible entre 3.\n");
				 if (num%5==0)
					printf("Es divisible entre 5.\n");
					if (num%7==0)
						printf("Es divisible entre 7.\n");
			getch();
		   }