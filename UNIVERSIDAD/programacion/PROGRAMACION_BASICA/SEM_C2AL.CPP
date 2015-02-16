#include <stdio.h>
#include <conio.h>

 void main()
{
 int C,N,CONT;
 float P,S,X;
 S=0;CONT=0;C=0;
 clrscr();
 printf("\n Ingrese el n£mero de datos: ");
 scanf("%d",&N);
 while (CONT<N)
 {
  printf("\n Ingrese temperatura: ");
  scanf("%f",&X);

  if (X>33)
  {
   S=S+X;
   C++;
  }
  CONT++;
 }
  if (C!=0)
  {
   P=S/C;
   printf("\n El promedio de los valores mayores a 33 es: %.2f",P);
  }
  else
	printf("\n No hay valores mayores a 33  %d",CONT);
  getch();
}