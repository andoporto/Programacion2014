#include <stdio.h>
#include <conio.h>

void main()
{
	int c, n;
	clrscr();
	textcolor(MAGENTA);
	cprintf("\nEscribe un n£mero del 0 al 10: ");
	scanf("%d", &n);
	while (( n > 10 ) || ( n < 0 ))
	{
		cprintf("\nEscribe un n£mero del 0 al 10: ");
		scanf("%d", &n);
	}
	for ( c = 1; c <= 10; c++ )
	{
	       printf("\n\t\t\t\t%d * %d = %d", n, c, n * c);
	}
	getch();
}
