/*Programa para sumar fracciones*/
#include<stdio.h>
#include<conio.h>
void main()
		   {
			int num1,num2,num3,denum1,denum2,mcm,aux1,aux2;
			clrscr();
			gotoxy(20,2);
			printf ("Este programa calcula la suma de 2 fracciones\n");
			gotoxy(30,8);
			printf("Dame la primera fraccion: (      /      )");
			gotoxy(57,8);
			scanf("%d",&num1);
			gotoxy(64,8);
			scanf("%d",&denum1);
			gotoxy(30,10);
			printf("Dame la segunda fraccion: (      /     )");
			gotoxy(57,10);
			scanf("%d",&num2);
			gotoxy(64,10);
			scanf("%d",&denum2);
			mcm=denum1*denum2;
			aux1=(mcm/denum1)*num1;
			aux2=(mcm/denum2)*num2;
			num3=aux1+aux2;
			gotoxy(30,12);
			printf("La fraccion resultante es: (     /     )");
			gotoxy(58,12);
			printf("%d",num3);
			gotoxy(64,12);
			printf("%d",mcm);
			getch();
		   }