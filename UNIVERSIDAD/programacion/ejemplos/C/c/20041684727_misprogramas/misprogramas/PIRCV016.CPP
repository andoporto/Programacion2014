/*Programa que determina si un n—mero es par o impar*/
#include<stdio.h>
#include<conio.h>
void main()
		   {
			clrscr();
			int num;
			printf("Este programa determina si un n—mero es par o impar.\n");
			printf("Teclea el n—mero a determinar: ");
			scanf("%d", &num);
			if (num%2!=0)
			   printf("Es un numero impar");
			else
			printf("Es n—mero par.");
			getch();
		   }