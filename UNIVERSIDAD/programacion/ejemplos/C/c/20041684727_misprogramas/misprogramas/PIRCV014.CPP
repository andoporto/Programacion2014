/*Programa que determina el tipo de ra�z de una ecuaci�n cuadratica*/
#include<stdio.h>
#include<conio.h>
void main()
		   {
			int a,b,c,disc;
			clrscr();
			printf("Programa que analiza el discriminante de una ecuaci�n\n");
			printf(" cuadratica y determina el tipo de ra�z del que consta.\n");
			printf("Teclea el valor de a: ");
			scanf("%d", &a);
			printf("Teclea le valor de b: ");
			scanf("%d", &b);
			printf("Teclea el valor de c: ");
			scanf("%d", &c);
			disc=(4*a*c)-b;
			if (disc>0)
				printf("Son raices distintas.");
				if (disc==0)
				   printf("Son raices iguales.");
				   if (disc<0)
					   printf("Son raices imaginarias.");
			getch();

		   }
