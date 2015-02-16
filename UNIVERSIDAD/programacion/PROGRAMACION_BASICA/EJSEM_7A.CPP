#include <stdio.h>
#include <conio.h>

 void main()
{
 int N,S,I;
 clrscr();
 S=0;
 printf("\n Ingrese un numero: ");
 scanf("%d",&N);
 for(I=1;I<=N;I++)
   S=S+I;
 printf("\n \n La suma vale: %d",S);
 getch();
}