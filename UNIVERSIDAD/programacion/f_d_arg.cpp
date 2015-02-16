#include <stdio.h>
#include <conio.h>

void asterisco (); /* declaracion de la funcion sin parametros*/
void main ()

{
	clrscr();
	asterisco (); /* la llamada a la funcion*/
	printf("ARGENTINA");
	asterisco ();
        getch();
}


void asterisco ()
{
printf("***");
}


