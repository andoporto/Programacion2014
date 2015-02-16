#include <stdio.h>
#include <conio.h>
#include <math.h>
 void main()
  {
    clrscr();
    double  Po,tol,p1,gPo;
    int iteraciones,i,c=0;

    printf("Programa para encontrar la solucion de P=g(p) dada una aproximacion inicial Po.\n");
    printf("Dada la ecuacion g(x)=x^3+4x^2-10\n");
    printf("Ingrese la aproximacion inicial |Po.|\n");
    scanf("%lf",&Po);
    printf("Ingrese la tolerancia para encontrar la solucion:\n");
    scanf("%lf",&tol);
    printf("Ingrese el numero de iteraciones: \n");
    scanf("%d",&iteraciones);

    i=1;
    while(i<=iteraciones)
     {
       gPo=(sqrt(10-(Po*Po*Po))*0.5);
       p1=gPo;

       if((fabs(p1-Po))<tol)
       {
	 c++;
	 break;
	}
	else
	{
	  i++;
	  Po=p1;
	}
     }
    if(c!=0)
    printf("Procedimiento completado satisfactoriamente;\n P= %lf",p1);
    else
    {
    printf("El metodo fracaso depues de %d iteraciones.",iteraciones);
    }
  getch();
}