/*Programa que transforma grados a radianes*/
#include<stdio.h>
#include<conio.h>
void main()
		  {
		   float gra,rad;
		   const float pi=3.141632;
		   clrscr();
		   printf("Programa que transforma grados a radianes.");
		   printf(" Que cantidad de grados quieres combertir a radianes?: ");
		   scanf("%f", &gra);
		   rad=(gra*pi)/180;
		   printf("El resultado es=%f radianes", rad);
		   getch();
		  }