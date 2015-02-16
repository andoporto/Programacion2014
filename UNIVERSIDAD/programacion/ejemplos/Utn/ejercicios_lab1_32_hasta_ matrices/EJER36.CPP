#include <conio.h>
#include <stdio.h>
#include <ctype.h>

void main (void){
char nombre[20], seguir = 's';
float n1, n2, n3, n4, n5, n6, prom;
do
{
clrscr();
flushall;
printf("Nombre: ");
scanf("%s", &nombre);
printf("\nNota 1: ");
scanf("%f", &n1);
printf("\nNota 2: ");
scanf("%f", &n2);
printf("\nNota 3: ");
scanf("%f", &n3);
printf("\nNota 4: ");
scanf("%f", &n4);
printf("\nNota 5: ");
scanf("%f", &n5);
printf("\nNota 6: ");
scanf("%f", &n6);
prom = (n1 + n2 + n3 + n4 + n5 + n6) / 6;
clrscr();
printf("\nNOMBRE DEL ALUMNO: %s PROMEDIO: %.1f", nombre, prom);
printf("\n\nDesea seguir s/n?: ");
seguir = getch();
seguir = tolower(seguir);
}while(seguir == 's');
}