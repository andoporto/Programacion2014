#include<stdio.h>
#include<conio.h>
#include<math.h>

float funcion(float *po);
void main()
{
	float TOL,po,p,TI,EXP,fpo,ap;
	int No,i,ban=0;
	clrscr();
	gotoxy(30,1);printf("METODO DE PUNTO FIJO");
	gotoxy(8,3);printf("Programa para encontrar una solucion de f(x)=0 dada la funcion:");
	gotoxy(30,5);printf("1/2(10-x^3)^1/2 = 0");
	gotoxy(15,8);printf("Dame aproximacion inicial: ");scanf("%f",&po);
	gotoxy(15,9);printf("Dame el margen de error: ");scanf("%f",&TOL);
	gotoxy(15,10);printf("Dame el numero maximo de iteraciones: ");scanf("%d",&No);
	for(i=1;i<=No;i++)
	{
		fpo=funcion(&po);
		p=fpo;
		if(fabs(p-po)<TOL)
		{
			ban=1;break;
		}
		else
			po=p;
	}
	if(ban==1)
		{
			gotoxy(25,13);printf("x= %f para que f(x)=0",p);
			gotoxy(20,15);printf("Procedimiento completado satisfactoriamente");
		}
	else
	{
	 gotoxy(20,15);printf("Procedimiento completado insatisfactoriamente");
	}
	getch();
}

float funcion(float *po)
{       //Mi funcion es: 1/2(10-x^3)^1/2=0
	int cant,j,num,i;
	float fpo;
	fpo=0.5*pow(10-pow(*po,3),0.5);
	return fpo;
}