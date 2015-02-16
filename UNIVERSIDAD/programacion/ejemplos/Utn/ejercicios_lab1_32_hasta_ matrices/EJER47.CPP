#include <stdio.h>
#include <conio.h>

void main (void){

int a, b, c, d, e, n;

clrscr();
printf("\n\n\n\t\t\tFecha de Pascua del 2003");
a = 2003 % 19;
b = 2003 % 4;
c = 2003 % 7;
d = ( 19 * a + 24 ) % 30;
e = ( 2 * b + 4 * c + 6 * d + 5 ) % 7;
n = ( 22 + d + e );
if( n > 31 )
printf("\n\n\t\t\t%d de Abril", n - 31);
else
printf("\n\n\t\t\t%d de Marzo", n);
getch();
}
