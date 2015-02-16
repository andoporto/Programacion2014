#include <stdio.h>
#include <conio.h>

void main (void){

int n, x, y, z;

clrscr();
printf("Escriba un a¤o: ");
scanf("%d", &n);
x = n % 4;
y = n % 100;
z = n % 400;
if( x == 0 && y != 0 || y == 0 && z == 0 )
printf("\n\n%d es un a¤o bisiesto", n);
else
printf("\n\n%d no es un a¤o bisiesto", n);
gotoxy(1,50);
printf("Presione una tecla para salir");
getch();
}