/*Programa que transforma grados Farenthgey a Centigrados*/
#include<stdio.h>
#include<conio.h>
void main()
		  {
		   float f,c;
		   clrscr();
		   printf("Este programa transforma grados Farenthgey a\n");
		   printf(" grados Centigrados, escribe la cantidad de grados centigrados: ");
		   scanf("%f", &f);
		   c=(f-32)*5/9;
		   printf("La catidad de grados Farenthgey=%f", c);
		   getch();
		  }