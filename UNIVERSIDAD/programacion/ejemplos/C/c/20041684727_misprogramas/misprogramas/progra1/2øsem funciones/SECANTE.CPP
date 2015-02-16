#include<stdio.h>
#include<conio.h>
#include<math.h>

float funcion(float *po);
void main()
{
	float p0,p1,TOL,q0,q1,p,fp;
	int No,i,ban=0;
	clrscr();
	printf("Dame aproximacion inicial po: ");scanf("%f",&p0);
	printf("Dame aproximacion inicial pi: ");scanf("%f",&p1);
	printf("Dame el margen de error: ");scanf("%f",&TOL);
	printf("Dame el numero maximo de iteraciones: ");scanf("%d",&No);
	i=2;
	q0=funcion(&p0);
	q1=funcion(&p1);

	while(i<=No)
	{
		p=(p1-(q1*(p1-p0)))/(q1-q0);
		if(fabs(p-p1)<TOL)
		{
			ban=1;break;
		}
		i++;
		p0=p1;q0=q1;p1=p;
		fp=funcion(&p);
		q1=fp;
	}
	if(ban==1)
			{printf("\np: %f\n",p);printf("Procedimiento completado satisfactoriamente");}
	else
		printf("\nEl metodo fracaso despues de %d iteraciones\nProcedimiento completado insatisfactoriamente",i-2);
	getch();
}

float funcion(float *p)
{       //Mi funcion es: 3x+2=0
	int cant,j,num,i;
	float fp;
	fp=(3*(*p))+2;
	return fp;
}