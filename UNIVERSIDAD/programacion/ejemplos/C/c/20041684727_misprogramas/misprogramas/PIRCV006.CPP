/*Programa que calcula el voltaje en base a la intancidad y
resistencia, valores que da el usuario*/
#include<stdio.h>
#include<conio.h>
void main()
		  {
		   float i,r,v;
		   clrscr();
		   printf("Este programa calcula un voltaje.\n");
		   printf(" Dame la intencidad: ");
		   scanf("%f", &i);
		   printf("Dame la resistencia: ");
		   scanf("%f", &r);
		   v=i*r;
		   printf("El voltaje es=%f", v);
		   getch();
		  }