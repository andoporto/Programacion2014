#include <stdio.h>
#include <string.h>
#include <conio.h>
int main(void)
{
	clrscr();
	char cad[50];
	int str;
	printf("Introduce un texto: ");gets(cad);
	str=strlen(cad);
	if(str==9)
		printf("Yo tambien te quiero mucho!!!\n");
	else
		printf("Mucho gusto\n");

	printf("La longitud de la cadena es: %d espacios\n", strlen(cad));
	getch();
	return 0;
}