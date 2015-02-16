/*Programa que calcula la hipotenusa de un triangulo rectangulo*/
#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
		  {
		   float co,ca,k;
		   clrscr();
		   printf("Este programa c…lcula el valor de la hipotenusa de un triangulo\n");
		   printf(" rectangulo.\n Dame el valor de el cateto opuesto: ");
		   scanf("%f", &co);
		   printf("Dame el valor del cateto adyasente: ");
		   scanf("%f", &ca);
		   k=sqrt((co*co)+(ca*ca));
		   printf("La hipotenusa= %f", k);
		   getch();
		  }