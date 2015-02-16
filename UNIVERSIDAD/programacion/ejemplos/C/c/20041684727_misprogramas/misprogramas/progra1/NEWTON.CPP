//metodo de newton rapson
#include <stdio.h>
#include <conio.h>
#include <math.h>
 void main()
  {
   double Po,tol,p,fpo,dxPo,fp;
   int iteraciones,i,c=0;
   clrscr();

   printf("Programa para encontrar una solucion de f(x)=0 dada una aproximacion inicial.\n");
   printf("Dada la funcion f(x)=x^3+4x^2-10\n");
   printf("Ingrese la aproximacion inicial:\n");
   scanf("%lf",&Po);
   printf("Ingrese la tolerancia:\n");
   scanf("%lf",&tol);
   printf("Ingrese el numero de iteraciones:\n");
   scanf("%d",&iteraciones);

   i=1;
   while(i<=iteraciones)
    {
     fpo=((Po*Po*Po)+(4*(Po*Po))-10);
     dxPo=((3*(Po*Po))+(8*Po));
     p=(Po-(fpo/dxPo));
     fp=((p*p*p)+(4*(p*p))-10);

     if((fabs(p-Po))<tol)
     {
	 c++;
	 break;
     }
     else
	{
	  i++;
	  Po=p;
	}
     }
    if(c!=0)
    printf("Procedimiento completado satisfactoriamente;\n P= %lf",p);
    else
    {
    printf("El metodo fracaso depues de %d iteraciones.",iteraciones);
    }
  getch();
}
