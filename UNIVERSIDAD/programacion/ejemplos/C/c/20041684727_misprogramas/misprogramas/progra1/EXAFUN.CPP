#include<stdio.h>
#include<conio.h>
#include<math.h>

void main()
		   {
			int opc;
			clrscr();
			gotoxy(35,6);
			textcolor(15);
			printf("Menu Principal");
			gotoxy(30,10);
			printf("1. Metodo del punto fijo");
			gotoxy(30,12);
			printf("2. Metodo de la secante");
			gotoxy(30,14);
			printf("3. Metodo de la pasicion falsa");
			gotoxy(30,16);
			printf("4. Metodode la biseccion");
			gotoxy(30,18);
			printf("5. Metodo de Newton-Rapson\n");
			gotoxy(10,20);
			printf("Elige el numero de la opcion que deseas ejecutar: ");
			scanf("%d", &opc);
			switch (opc)
				   {
					case 1:
						   //Metodo de punto fijo
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
break;


					case 2:
						   //Metodo de la secante
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


						   break;
					case 3:
						   printf("Metodo no resuelto");

						   break;
					case 4:

						   //Metodo de la biseccion
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
						   break;
					case 5:
						   //Metodo de Newton-Rapson

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


			default:
					printf("Opcion no valida");
					break;
			getch();
			}





//Metodo de la posicion falsa (falta)


/*//Metodo de Newton-Rapson

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
}*/
