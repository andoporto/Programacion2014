/*Programa que determinasi un triangulo es  equilatero, isosceles o escaleno*/
#include<stdio.h>
#include<conio.h>
void main()
		  {
		   float l1,l2,l3;
		   clrscr();
		   printf("Este programa te muestra si un triangulo es equilatero,\n");
		   printf(" isosceles o escaleno. Teclea el primer lado del trangulo: ");
		   scanf("%f", &l1);
		   printf("Teclea el segundo lado del triangulo: ");
		   scanf("%f", &l2);
		   printf("Teclea el tercer lado del triangulo: ");
		   scanf("%f", &l3);
		   if ((l1==l2)&&(l2==l3)&&(l1==l3))
			  printf("Es un triangulo equilatero.");
			  if ((l1==l2)||(l1==l3)||(l2==l3))
				 printf("Es un triangulo isosceles.");
				 if ((l1!=l2)&&(l1!=l3)&&(l3!=l2))
					printf("Es un triangulo escaleno.");
		   getch();
		  }