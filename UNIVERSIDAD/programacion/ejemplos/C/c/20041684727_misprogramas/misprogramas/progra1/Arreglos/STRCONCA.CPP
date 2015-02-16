#include <string.h>
#include <stdio.h>
#include <conio.h>
int main(void)
{
	clrscr();
	 char destino[25],cad1[50],cad2[50],cad3[50];
	 char *blank = " ";/* *c = "C++", *turbo = "Turbo";*/
	printf("Introduce un texto: ");gets(cad1);
	printf("Introduce un texto: ");gets(cad2);
	printf("Introduce un texto: ");gets(cad3);

	 strcpy(destino, cad1);
	 strcat(destino, blank);
	 strcat(destino, cad2);
	 strcat(destino, blank);
	 strcat(destino, cad3);

	 printf("%s\n", destino);
	 getch();
	 return 0;
}