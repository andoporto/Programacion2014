#include <stdio.h>
#include <conio.h>

void main (void){

int vect[19], may, i, pos;

for ( i = 0; i < 20; i++ )
{
clrscr();
printf("Ingrese un n£mero: ");
scanf("%d", &vect[i]);

while(vect[i] < 0)
	{
	clrscr();
	printf("Ingrese un n£mero positivo: ");
	scanf("%d", &vect[i]);
	}

if(i == 0 || vect[i] > may)
	{
	may = vect[i];
	pos = i + 1;
	}
}
clrscr();
printf("El n£mero mas alto es %d y fue leido en la posici¢n %d", may, pos);
printf("\n\nTodos los numeros son:\n\n");
for( i = 0; i < 20; i++ )
printf("*%d", vect[i]);
getch();
}




