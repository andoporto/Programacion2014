#include <stdio.h>
#include <conio.h>

void main (void)
{
	int i, vec[9];
	clrscr();
	for(i=0; i<10; i++)
   {
   	printf("Ingrese un número: ");
   	scanf("%d", &vec[i]);
   }
   for(i=0; i<10; i++)
   	printf("*%d", vec[i]);
   getch();
}


