#include<stdio.h>
#include<conio.h>
#include<math.h>

float funcion(float *po);
void main()
{
	float x0,x1,TOL,fx0,fx1,x,fx;
	int No,i,ban=0;
	clrscr();
	printf("Dame aproximacion inicial po: ");scanf("%f",&x0);
	printf("Dame aproximacion inicial pi: ");scanf("%f",&x1);
	printf("Dame el margen de error: ");scanf("%f",&TOL);
	printf("Dame el numero maximo de iteraciones: ");scanf("%d",&No);
	i=1;

	while(i<=No)
	{
		fx0=funcion(&x0);
		fx1=funcion(&x1);
		x=x0-(x1-x0)*fx0/(fx1-fx0);
		if(fabs(x-x1)<TOL)
		{
			ban=1;break;
		}

		if(fabs(fx=funcion(&x))<TOL)
		{
			ban=1;break;
		}

		i++;
		x0=x1;x1=x;

	}
	if(ban==0)
		{printf("\nEl metodo fracaso despues de %d iteraciones\nProcedimiento completado insatisfactoriamente",i-2);}
	if(ban==1)
		{printf("\n%f",x);}
	getch();
}

float funcion(float *p)
{       //Mi funcion es: x`3+2x`2+10x-20=0
	int cant,j,num,i;
	float fp;
	fp=(pow(*p,3)+(2*pow(*p,2))+(10*(*p)-20));
	return fp;
}