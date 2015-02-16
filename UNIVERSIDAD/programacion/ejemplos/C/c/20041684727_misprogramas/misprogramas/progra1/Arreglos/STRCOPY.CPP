#include <stdio.h>
#include <string.h>
#include <conio.h>
int main(void)
{
	clrscr();
	 char destin[50],cadorig[50];
		printf("Introduce la cadena que desees copiar: ");gets(cadorig);
		strcpy(destin, cadorig);
		printf("%s\n", destin);
		getch();
	 return 0;
 }
