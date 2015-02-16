#include<stdio.h>
#include<conio.h>
#include<math.h>

float funcion(float *p);
void main()
{
	float a,b,TOL,fa,fb,p,fp;
	int No,i,ban=0;
	clrscr();
	printf("Dame extremo a: ");scanf("%f",&a);
	printf("Dame extremo b: ");scanf("%f",&b);
	printf("Dame el margen de error: ");scanf("%f",&TOL);
	printf("Dame el numero maximo de iteraciones: ");scanf("%d",&No);
	i=1;
	while(i<=No)
	{
		fa=funcion(&a);fb=funcion(&b);
		p=a-(((a-b)*fa)/(fa-fb));
		fp=funcion(&p);
		if(fabs(fp)<TOL)
		{
			ban=1;break;//	a++; p=b+1;
		}
		if(fabs(b-a)<TOL)
		{
			p=(b+a)/2;
			ban=2;break;
		}
		if((fb*fp)>0)
			b=p;
		if((fb*fp)<0))
			a=p;
		i++;
		}
	}
	if(ban==1)
		{printf("\nfp: %f\n",fp);printf("Procedimiento completado satisfactoriamente");}
	if(ban==2)
		{printf("\nfp: %f\n",fp);printf("Procedimiento completado satisfactoriamente");}

	if(ban==0)
		printf("\nEl metodo fracas¢ despues de %d iteraciones\nProcedimiento completado insatisfactoriamente!!!",i-1);
	getch();
}

float funcion(float *p)
{       //Mi funcion es: x'3+4x'2-10
	int cant,j,num,i;
	float fp;
	fp=(pow(*p,3)+(4*pow(*p,2))-10);
	return fp;
}