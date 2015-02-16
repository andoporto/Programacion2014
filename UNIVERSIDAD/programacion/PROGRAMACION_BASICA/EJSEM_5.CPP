#include <stdio.h>
#include <conio.h>

 void main()
{
 long int S,X;
 S=0;
 clrscr();
 while(S<=78500)
 {
  printf("\n Ingrese un valor: ");
  scanf("%ld",&X);
  S=S+X;
 }
  printf("\n \n El valor de la suma es: %ld",S);
  getch();
}