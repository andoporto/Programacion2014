
#include <stdio.h>
#include <conio.h>

  void main()
{
 int POS,MAYOR,X,i,S;
 float PROM;
 clrscr ();
 S=0;POS=0;PROM=0;MAYOR=0;

 for (i=1;i<=15;i++)
 {
	printf("\n Ingrese un valor: ");
	scanf ("%d",&X);

	if (X==0)
		pos=i;
 }

 printf("\n Posicion del valor nulo: %d",POS);
 for (i=1;i<=POS;i++)
 {
  printf("\n Ingrese un valor: ");
  scanf ("%d",&X);
  S=S+X;
 }
 PROM=S/POS;

 printf(\n \n Promedio de valores del primer lote: %d",MAYOR);

 for (i=1;i<=POS;i++)
 {
  printf("\n \n Ingrese un valor: ");
  scanf ("%d",&X);

  if (i==POS)
  	MAYOR=X;
  else
  {
	 if (X>MAYOR)
	 		MAYOR=X;
  }
 }
 printf(\n \n Valor maximo del segundo lote: %d",MAYOR);



 }

	printf ("\n \n El mayor valor es: %d,M);
	getch();
}

