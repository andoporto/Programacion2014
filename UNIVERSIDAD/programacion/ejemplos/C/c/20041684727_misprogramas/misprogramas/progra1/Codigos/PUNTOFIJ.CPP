#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
 clrscr();
 int i=1,n=100,po=2;
 float tol=0.0001,gpo,p;
 printf("Programa que calcula el metodo de punto fijo\n");
 gpo=po*po;
 while(i<=n)
 {
 p=gpo;
 if((abs(p-po))<tol)
  {
   printf("El resultado es = %d ",p);
   break;
  }
 else
  {
   i++;
   po=p;
  }
 }
 if(i==100)
 printf("El prograna fracaso");
 getch();
}