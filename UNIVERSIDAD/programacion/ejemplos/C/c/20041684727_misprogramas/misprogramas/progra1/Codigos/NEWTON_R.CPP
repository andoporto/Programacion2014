#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
 clrscr();
 int i=1,n=100,po=2,fp,dfp;
 float p,tol=0.0001;
 printf("Programa que resuelve el metodo de newton raphson\n");
	fp=2*2*2;
	dfp=3*4;
	while(i<=n)
	{
	 p=((po-fp)/dfp);
	 if((abs(p-po))<tol)
		{
		printf("El resultado es : %f",p);
		break;
		}
	i++;
	po=p;
	}
  if(i==100)
	printf("el metodo fracaso despues de %d interacciones",i);
       getch();
       }