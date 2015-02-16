#include<stdio.h>
#include<conio.h>
#include<math.h>

float funcion(float *p);
float derivada(float *p);
void main()
{
	float po,p,TOL,fp,fpo,dpo,a,b,fa,fb,ban=0;
	int No,i;//ban=0;
	clrscr();
	gotoxy(8,3);printf("Programa para encontrar una solucion de f(x)=0 dada la funcion:");
	gotoxy(30,5);printf("x^3+4x^2-10 = 0");
	gotoxy(15,8);printf("Dame aproximacion inicial: ");scanf("%f",&po);
	gotoxy(15,9);printf("Dame el margen de error: ");scanf("%f",&TOL);
	gotoxy(15,10);printf("Dame el numero maximo de iteraciones: ");scanf("%d",&No);
	i=1;
	while(i<=No)
	{
		fpo=funcion(&po);
		dpo=derivada(&po);

		p=po-fpo/dpo;
		if(fabs(p-po)<TOL)
		{
			ban=1;break;
		}
		else
			i++;
			po=p;
	}
	if(ban==1)
		{
			gotoxy(25,13);printf("x= %f para hacer f(x)=0",p);
			gotoxy(20,15);printf("Procedimiento completado satisfactoriamente");
		}
	else
	{
		gotoxy(20,15);printf("El metodo fracaso despues de %d iteraciones",i-1);
		gotoxy(20,16);printf("Procedimiento completado sin exito");
	}
	getch();
}

float funcion(float *po)
{       //Mi funcion es: xï3+4x'2-10 =0
	float fpo;
	fpo=pow(*po,3)+4*pow(*po,2)-10;
	return fpo;
}

float derivada(float *po)
{       //Mi funcion es: xï3-2xï2-5=0
	float dpo;
	dpo=3*(pow(*po,2))+(8*(*po));
	return dpo;
}