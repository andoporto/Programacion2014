#include <stdio.h>
#include <conio.h>

 void main()
{
 int S,X,I;
 S=0;
 clrscr();

 for(I=1;I<=10;I=I+1)
 {
  printf("\n Ingrese un valor: ");
  scanf("%d",&X);
  if ((X<45)&&(X>-45))
    S=S+X;
 }
  printf("\n La suma de los valores que estan entre 45 y -45 es: %d",S);
  getch();
}