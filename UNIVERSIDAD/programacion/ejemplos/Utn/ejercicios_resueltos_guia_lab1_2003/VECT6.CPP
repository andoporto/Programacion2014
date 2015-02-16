#include <stdio.h>
#include <conio.h>

void main (void){

int aux, i, j, n[20];

for(i=0; i<20; i++)
	{
	clrscr();
	printf("\nIngrese un numero entero positivo: ");
	scanf("%d", &n[i]);
	while(n[i]<0)
		{
		clrscr();
		printf("\nIngrese el numero de nuevo: ");
		scanf("%d", &n[i]);
		}
	}
clrscr();
printf("Sus numeros son: ");
gotoxy(1,4);
for(i=0; i<=20; i++)
printf("*%d", n[i]);
gotoxy(1,8);
printf("Los numeros positivos en orden decreciente son:");
gotoxy(1,10);
for(i=0; i<19; i++)
	for(j=i+1; j<20; j++)
		if(n[i] < n[j])
			{
			aux=n[i];
			n[i]=n[j];
			n[j]=aux;
			}
for(i=0; i<20; i++)
printf("*%d", n[i]);
getch();
}
