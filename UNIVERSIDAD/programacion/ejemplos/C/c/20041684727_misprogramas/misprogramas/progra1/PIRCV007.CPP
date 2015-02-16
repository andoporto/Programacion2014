/*Programa que lee una cantidad entera de tres digitos y la desglosa en
unidades decenas y centenas*/
#include<stdio.h>
#include<conio.h>
void main()
		  {
		   int cant,cent,dec,uni;
		   clrscr();
		   printf("Este programa desglosa una cantidad de hasta tres dçgitos");
		   printf(" en unidades, decenas y centenas\n");
		   printf("Escribe la cantidad a desglosar: ");
		   scanf("%d", &cant);
		   cent=cant/100;
		   cant=cant%100;
		   dec=cant/10;
		   cant=cant%10;
		   uni=cant/1;
		   printf("Centenas=%d\n", cent);
		   printf("decenas=%d\n", dec);
		   printf("unidades=%d\n", uni);
		   getch();
		  }
