#include <stdio.h>
#include <conio.h>

void main()
{
	char letra;
	int a, e, i, o, u, cont;
	cont = 0;
	a = 0;
	e = 0;
	i = 0;
	o = 0;
	u = 0;
	textcolor(BLUE
	);
	clrscr();
	while (cont < 20)
	{
		cprintf("Ingrese un caracter: ");
		scanf("%s", &letra);
		switch(letra)
		{
			case 'a': a = a + 1; break;
			case 'e': e = e + 1; break;
			case 'i': i = i + 1; break;
			case 'o': o = o + 1; break;
			case 'u': u = u + 1; break;
		}
		cont = cont + 1;
	}
	printf("\n\nLa cantidad de letras 'a' son: %d", a);
	printf("\nLa cantidad de letras 'e' son: %d", e);
	printf("\nLa cantidad de letras 'i' son: %d", i);
	printf("\nLa cantidad de letras 'o' son: %d", o);
	printf("\nLa cantidad de letras 'u' son: %d", u);
	gotoxy(1,24);
	printf("Presione una tecla para salir");
	getch();
}