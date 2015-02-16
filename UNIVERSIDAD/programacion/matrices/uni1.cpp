#include <stdio.h>
#include<conio.h>
#define FIL 5
#define COL 4

void main()
{
  clrscr();
  int i,j,notas[FIL][COL];
  float prom1,prom2,suma;

  printf("Promedios por estudiante; \n");
	for (i=0; i<FIL;i++)
	{
	 printf("\n Ingrese las %d notas del estudiante: %d \n\n",COL, i+1);
	 suma=0;
	   for (j=0;j<COL;j++)
	   {
		printf("Materia: %d    ", j+1);
		scanf("%d",&notas[i][j]);
		suma=suma+notas[i][j];
		}

		prom1=suma/COL;
		printf("\n La nota promedio del estudiante %d es: %.2f",i+1,prom1);
    }

    /*recorremos ahora la matriz por columna para responder al segundo punto*/

    printf(" \n Promedios por columna \n");
    for (j=0;j<COL;j++)
    {
	 suma=0;
	    for (i=0;i<COL;i++)
		suma=suma+notas[i][j];
	    prom2=suma/FIL;
	    printf("\n La nota promedio de la asignatura %d es: %.2f ",j+1,prom2);
	}
}










