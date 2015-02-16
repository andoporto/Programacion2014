#include <stdio.h>
#include <conio.h>
#include <math.h>
 void main()
  {
    clrscr();
    double po,p1,p,qo,q1,pi,tol;
    int i,iteraciones,c=0;
    printf("programa para encontrar una solucion de f(x)=0 dada las aprox. iniciales p0 y p1:\n");
    printf("dada la funcion x^3+4x^2-10:\n");
    printf("introduzca la aproximacion inicial Po y P1 respectivamente:\n");
    scanf("%lf",&po);
    scanf("%lf",&p1);
    printf("introduzca el numero de iteraciones:\n");
    scanf("%d",&iteraciones);
    printf("Ingrese la tolerancia:\n");
    scanf("%d",tol);
    i=2;
    qo=(pow(po,3)+(4*pow(po,2))-10);
    q1=(pow(p1,3)+(4*pow(p1,2))-10);
    while (i<iteraciones)
    {
    p=p1-(q1*((p1-po)/(q1-qo)));
    pi=(pow(p,3)+(4*pow(p,2))-10);
    if ((fabs(p-p1))<tol)
     {
       c++;
       break;
     }
    else
    {
     i++;
     po=p1;
     qo=q1;
     p1=p;
     q1=pi;
    }
  }
   if(c!=0)
     printf("Procedimiento completado con exito:\np= %f",p);
   else
     printf("El procedimiento fracaso despues de %d iteraciones",iteraciones);

   getch();
   }





