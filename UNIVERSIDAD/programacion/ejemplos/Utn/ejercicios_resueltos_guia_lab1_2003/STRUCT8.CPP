#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#define M 1
#define N 1

struct producto {

int codigo;
int stock;
float precio;
char des[15];
};

struct datos {

char nombre[15];
char direccion[15];
};

struct cliente {

int codigo;
struct datos dat;
float total;
};

void main(void){

int band=0, cod, cod2, i, j, k, n;
float precio;

struct producto vect[M];
struct cliente vect2[N];

for(i=0; i<M; i++)
{
clrscr();
printf("C¢digo de producto: ");
scanf("%d", &vect[i].codigo);
printf("\nPrecio unitario: ");
scanf("%d", &precio);
vect[i].precio = precio;
printf("\nDescripci¢n: ");
fflush(stdin);
gets(vect[i].des);
printf("\nStock: ");
scanf("%d", &vect[i].stock);
	if(i<N)
	{
	clrscr();
	printf("C¢digo de cliente: ");
	scanf("%d", &vect2[i].codigo);
	printf("\nDatos");
	printf("\n\nNombre: ");
	fflush(stdin);
	gets(vect2[i].dat.nombre);
	printf("\nDirecci¢n: ");
	fflush(stdin);
	gets(vect2[i].dat.direccion);
	printf("\nMonto acumulado de compras: ");
	scanf("%f", &precio);
	vect2[i].total = precio;
	}
}
clrscr();
printf("Ingrese c¢digo de cliente: ");
scanf("%d", &j);
printf("\nIngrese c¢digo de producto: ");
scanf("%d", &k);
printf("\nCantidad vendida: ");
scanf("%d", &n);
clrscr();
for(i=0; i<M; i++)
{
	if(k==vect[i].codigo)
	{
	cod = i;
	band++;
	}
	if(j==vect2[i].codigo)
	{
	cod2 = i;
	band++;
	}
	if(band==2)
	break;
}
if(i==M)
band=0;
if(n < vect[cod].stock && band!=0)
{
vect[cod].stock = vect[cod].stock - n;
vect2[cod2].total = (float)n * vect[cod].precio + vect2[cod2].total;
}
if(band!=0)
{
clrscr();
printf("El cliente con numero de codigo %d realizo una compra de %d %s\npor un total de $%.2f", j, n, vect[cod].des, n * vect[cod].precio);
getch();
}
clrscr();
printf("Clientes cuyo monto acumulado de compras supera los $1000:\n\n\n");
printf("    ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
printf("    ³     Codigo     ³     Nombre     ³   Direcci¢n    ³Monto de compras³\n");
printf("    ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´\n    ");
for(i=0; i<N; i++)
	if(vect2[i].total > 1000)
		printf("³%16d³%16s³%16s³%16.2f³\n    ", vect2[i].codigo, vect2[i].dat.nombre, vect2[i].dat.direccion, vect2[i].total);
printf("ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
getch();
}











