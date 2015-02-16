#include <stdio.h>
#define MAX 10

void leermat (int a[MAX] [MAX],int m, int n);
void sumamat(int a[][MAX], int b[][MAX], int c[MAX][MAX], int m, int n);
void escrmat(int a[][MAX], int m, int n);

void main()
{
	int m,n;
	int a [MAX][MAX],b[MAX][MAX],c[MAX][MAX];
	printf("Ingrese el numero de filas de las dos matrices: ");
	scanf("%d",&m);
	printf("Ingrese el numero de columnas de las dos matrices: ");
	scanf("%d",&n);
	printf("Ingrese los datos de la primera matriz: \n");
	leermat(a,m,n);
	printf("Ingrese los datos de la segunda matriz: \n");
	leermat(b,m,n);
	sumamat(a,b,c,m,n);
	printf("La suma de los elementos es: \n");
	escrmat(c,m,n);
}     /*fin del main*/

void leermat (int a[MAX] [MAX],int m, int n)
{
	int fila,columna;
		for (fila=0;fila<m;fila++) {
			printf("Introduzca los datos de la fila %d \n", fila+1);
				for (columna=0;columna<n;columna++)
					scanf("%d",&a[fila][columna]);
		}
return;
}

void sumamat(int a[][MAX], int b[][MAX], int c[MAX][MAX], int m, int n)
{
	int fila,columna;
		for (fila=0;fila<m;fila++)
				for (columna=0;columna<n;columna++)
					c[fila][columna]=a[fila][columna]+b[fila][columna];
return;
}

void escrmat(int a[][MAX], int m, int n)
{
	int fila,columna;
		for (fila=0;fila<m;fila++)
				{
				for (columna=0;columna<n;columna++)
					printf("%4d",c[fila][columna]);
					printf("\n");
				}
return;
}

