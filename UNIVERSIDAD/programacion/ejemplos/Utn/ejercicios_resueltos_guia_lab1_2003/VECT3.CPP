#include <stdio.h>
#include <conio.h>
#include <ctype.h>

void main ()
{

	int vect[9], i, n;
	char seguir;

	for( i = 0; i < 10; i++)
	vect[i] = 0;
	do
	{
	clrscr();
	printf("Elija posici¢n: ");
	scanf("%d", &i);
		while( i < 0 || i > 9 )
		{
		clrscr();
		printf("Elija posici¢n: ");
		scanf("%d", &i);
		}
	printf("\nNumero: ");
	scanf("%d", &n);
	vect[i] = vect[i] + n;
	fflush(stdin);
	printf("\n\n\nDesea seguir s/n?: ");
	scanf("%c", &seguir);
	seguir = tolower(seguir);
	}while( seguir == 's');
	clrscr();
	for( i = 0; i < 10; i++)
	printf("\nElemento %d = %d", i, vect[i]);
	getch();
}
