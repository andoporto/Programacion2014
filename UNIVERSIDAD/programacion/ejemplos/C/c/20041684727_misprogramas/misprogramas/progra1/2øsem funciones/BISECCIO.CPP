#include<stdio.h>
#include<conio.h>
#include<math.h>

float funcion(float *p);
void main()
{
	float a,b,TOL,fa,fb,p,fp;
	int No,i,ban=0;
	clrscr();
	gotoxy(8,3);printf("Programa para encontrar una solucion de f(x)=0 dada la funcion:");
	gotoxy(30,5);printf("x^3+4x^2-10 = 0");
	gotoxy(15,8);printf("Dame extremo a: ");scanf("%f",&a);
	gotoxy(15,9);printf("Dame extremo b: ");scanf("%f",&b);
	gotoxy(15,10);printf("Dame la tolerancia: ");scanf("%f",&TOL);
	gotoxy(15,11);printf("Dame el numero maximo de iteraciones: ");scanf("%d",&No);
	i=1;
	while(i<=No)
	{
		p= a+((b-a)/2);
		fp=funcion(&p);
		if(fp==0 ||(b-a)/2<TOL)
		{
			ban=1;
			break;
		}
		else
		{
			i++;
			fa=funcion(&a);
			fb=funcion(&b);
			if((fa*fp)>0)
				a=p;
			else
				b=p;
		}
	}
	if(ban==1)
		{
			gotoxy(25,14);printf("x= %f para que f(x)=0",p);
			gotoxy(15,17);printf("Procedimiento completado satisfactoriamente");
		}
	if(ban==0)
	{
		gotoxy(15,17);
		printf("El metodo fracas¢ despues de %d iteraciones\nProcedimiento completado insatisfactoriamente!!!",i-1);
	}
	getch();
}

float funcion(float *p)
{       //Mi funcion es: x'3+4x'2-10
	int cant,j,num,i;
	float fp;
	fp=(pow(*p,3)+(4*pow(*p,2))-10);
	return fp;
}