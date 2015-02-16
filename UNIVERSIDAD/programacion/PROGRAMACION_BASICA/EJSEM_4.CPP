#include <stdio.h>
#include <conio.h>

 void main()
{
 int A,B,S,P,I;
 S=0;P=0;
 clrscr();

 for(I=1;I<=15;I++)
 {
  printf("\n Ingrese un valor: ");
  scanf("%d",&A);
  printf("\n Ingrese otro valor: ");
  scanf("%d",&B);

  S=A+B;
  P=A*B;
  printf("\n \n La suma vale: %d y la multiplicacion vale: %d \n\n",S,P);
  getch();
 }
 getch();
}