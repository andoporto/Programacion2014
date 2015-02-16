#include <stdio.h>
#include <conio.h>

 void main()
{
 int CONT=0,A,N;
 float PROM,SUM;
 clrscr();
 printf("\n Ingrese cantidad de datos: ");
 scanf("%d",&N);
 while (CONT<N)
 {
  printf("\n Ingrese el dato: ");
  scanf("%d",&A);
  SUM=A+SUM;
  CONT=CONT+1;
  printf(" Valor ingresado: %d \n",A);
 }
  printf("\n \n La sumatoria vale: %.0f",SUM);
  PROM=SUM/CONT;
  printf("\n El promedio vale: %.2f",PROM);
  getch();
}