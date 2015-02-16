#include <stdio.h>
#include <conio.h>

 void main()
{
 int N,S,C;
 clrscr();
 S=0;C=0;
 printf("\n Ingrese un numero: ");
 scanf("%d",&N);
 while(C<=N)
 {
   S+=C;
   C++;
 }
 printf("\n La suma vale: %d",S);
 getch();
}