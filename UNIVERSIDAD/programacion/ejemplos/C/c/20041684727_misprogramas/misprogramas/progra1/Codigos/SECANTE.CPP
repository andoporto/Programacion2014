#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
 clrscr();
 int p0=2,p1=4,n=100,q0,q1,i=2;
 float tol=0.0001,p,fp;
 printf("Programa para el metodo de la secante\n");
 q0=2*2;
 q1=4*4;
 while(i<=n)
 {
  p=p1-(q1*((p1-p0)*(q1-q0)));
  fp=p*p;
  if((abs(p-p1))<tol)
  {
   printf("El resultado es = %f",p);
   break;
  }
  else
  {
   i++;
   p0=p1;
   q0=q1;
   p1=p;
   q1=fp;
  }
 }
 if(i==100)
 printf("El metodo fracaso despues de %d interacciones",i);
 getch();
}