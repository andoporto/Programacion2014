#include <conio.h>
#include <stdio.h>

void main (void){
float may, men, n;
int i, band=0;
for(i = 0; i < 5; i++)
{
clrscr();
printf("ingrese un n£mero: ");
scanf("%f", &n);
if( n < men || band == 0)
	{
	men = n;
	band = 1;
	}
if( n > may || band == 0)
	{
	may = n;
	band = 1;
	}
}
printf("\n\nEl mayor de los n£meros es %.2f y el menor es %.2f", may, men);
getch();
}