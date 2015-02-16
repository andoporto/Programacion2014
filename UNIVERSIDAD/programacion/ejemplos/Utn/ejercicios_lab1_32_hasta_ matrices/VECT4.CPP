#include <stdio.h>
#include <conio.h>
#include <ctype.h>

void main (void){

int i, dia;
float mes[31], max, gasto;
char seguir;

for(i=0; i<=30; i++)
mes[i] = 0;

do
{
clrscr();
printf("Dia: ");
scanf("%d", &i);
printf("\nGasto: ");
scanf("%f", &gasto);
mes[i-1] = mes[i-1] + gasto;
fflush(stdin);
printf("Desea seguir s/n?: ");
scanf("%c", &seguir);
seguir = tolower(seguir);
}while(seguir=='s');
max=mes[0];
for(i=0; i<=30; i++)
if(mes[i] > max)
{
max=mes[i];
dia=i+1;
}
clrscr();
printf("El dia que mas gasto fue en el dia %d", dia);
getch();
}






