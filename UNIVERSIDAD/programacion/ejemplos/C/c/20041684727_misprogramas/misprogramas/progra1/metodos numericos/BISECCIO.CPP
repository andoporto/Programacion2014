#include <stdio.h>
#include <conio.h>
#include <math.h>
 void main()
 {
   clrscr();
   float a,b,p,fp,fa,tol;
   int i,c=0,iteraciones;

   printf("Programa para encontrar una solucion de f(x)=0 Dada la funcion continua: \n");
   printf("f(x)= x^3+4x^2-10\n");
   printf("Ingrese el intervalo (a,b) respectivamente; Donde [a*b<0] : \n");
   scanf("%f",&a);
   scanf("%f",&b);
   printf("Cuantas iteraciones desea que se realizen para encontrar la raiz: \n");
   scanf("%d",&iteraciones);
   printf("Ingrese la tolerancia, tal que tolerancia sea mayor que cero: \n");
   scanf("%f",&tol);
   i=1;
   while(i<=iteraciones)
   {
      p=a+((b-a)/2);
      fp=((pow(p,3))+((4*(pow(p,2)))-10));
      fa=((pow(a,3))+((4*(pow(a,2)))-10));

	 if((((b-a)/2)<tol)||(fp==0))

      {
	 c++;
	 break;
      }
      else
      {
	 i++;

      }
      if((fa*fp)>0)
	a=p;
      else
	b=p;
    }

   if(c!=0)
   printf("Procedimiento completado con exito:\np= %f",p);
   else
   printf("El procedimiento fracaso despues de %d iteraciones",iteraciones);

   getch();
   }
