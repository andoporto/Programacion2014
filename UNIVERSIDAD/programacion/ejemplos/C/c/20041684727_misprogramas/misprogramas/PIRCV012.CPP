/*Programa que lee un n—mero y si n>0, escribe es n—mero positivo,si n=0,
escribe, el n—mero es 0, y si es < que 0, escribe n—mero negativo*/
#include<stdio.h>
#include<conio.h>
void main()
		  {
		   int num;
		   clrscr();
		   printf("Programa que lee un n—mero y muestra si es positivo,\n");
		   printf(" negativo o es 0. ");
		   printf("Escribe el n—mero: ");
		   scanf("%d", &num);
		   if (num>0)
			   printf("Es un n—mero positivo");
			  if (num==0)
				  printf("El n—mero=0");
				  if (num<0)
					  printf(" Es un n—mero negativo");
		   getch();
		  }