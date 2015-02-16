#include <stdio.h>
#include <conio.h>

void main (void){

int a[10], b[10], c[10], i;

for(i=0; i<=10; i++)
	{
	clrscr();
	printf("Ingrese numero de A: ");
	scanf("%d", &a[i]);
	printf("Ingrese numero de B: ");
	scanf("%d", &b[i]);
	if(a[i] < b[i])
	c[i] = a[i];
	else
	c[i] = b[i];
	}
clrscr();
printf("\t\t\tA\t\tB\t\tC\n\n");
for(i=0; i<=10; i++)
printf("\n\n\t\t\t%d\t\t%d\t\t%d", a[i], b[i], c[i]);
getch();
}
