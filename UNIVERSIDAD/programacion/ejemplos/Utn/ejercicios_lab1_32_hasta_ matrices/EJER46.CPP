#include <stdio.h>
#include <conio.h>

void main (void){

int n1, n2, r1, opc;

do
{
clrscr();

printf("\n\n\n\n\n\n\n\n\n\t\t\t\t   MENU\n\n\n\n\n\t\t\t\t 1_Sumar\n\n\n\t\t\t\t 2_Restar\n\n\n\t\t\t\t 3_Multiplicar\n\n\n\t\t\t\t 4_Dividir\n\n\n\t\t\t\t 5_Salir\n\n\n\n\n\t\t\t\t Opci¢n: "); scanf("%d", &opc); while(opc > 5){ printf("Opci¢n: "); scanf("%d", &opc);}
switch(opc){
case 1: clrscr(); printf("\n\nN£mero 1: "); scanf("%d", &n1); printf("\n\nN£mero 2: "); scanf("%d", &n2); r1 = n1 + n2; printf("\n\n%d + %d = %d", n1, n2, r1); break;
case 2: clrscr(); printf("\n\nN£mero 1: "); scanf("%d", &n1); printf("\n\nN£mero 2: "); scanf("%d", &n2); r1 = n1 - n2; printf("\n\n%d - %d = %d", n1, n2, r1); break;
case 3: clrscr(); printf("\n\nN£mero 1: "); scanf("%d", &n1); printf("\n\nN£mero 2: "); scanf("%d", &n2); r1 = n1 * n2; printf("\n\n%d * %d = %d", n1, n2, r1); break;
case 4: clrscr(); printf("\n\nN£mero 1: "); scanf("%d", &n1); printf("\n\nN£mero 2: "); scanf("%d", &n2); while(n2==0) { printf("\n\nIngrese otro n£mero: "); scanf("%d", &n2);} r1 = n1 / n2; printf("\n\n%d / %d = %d", n1, n2, r1); break;
}
}while(opc!=5);
getch();
}