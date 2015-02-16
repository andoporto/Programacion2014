


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

float valido(float,float);
char seccionvalida(char);
int perfecto(int);
int factorial(int);
/*int fecha(int,int,int); */

void main ()

{
/*int fe;*/
int ct;
int st;
int flag=0,flag2=0;
int pet;
int per;
int tmin;
int fac;
/*int mes,dia,anio,i;*/

float te, max, min, prom;
char sec, secant, secmin, secmax,seccion, a, b, c,f;

/*do
{

printf ("Ingrese fecha ");

fe=fecha(anio,mes,dia);
}while (fe!=0);*/

printf("Ingrese secci¢n: ");
sec=seccionvalida(seccion);
flag=0,flag2=0;

while (sec!='f')
{
	secant=sec; st=0;
		while (secant==sec && ct<=10)
		{
		   printf ("Ingrese temperatura: ");
		   getch();
		   te=valido(8,135);
		   ct++;
		   st+=te;
			if (flag2==0 || te>max)
			      {	max=te;
				secmax=sec;
				flag2=1;
					}
			if (flag==0 || te<min)
				{min=te;
				secmin=sec;
				flag=1;
					}

			if (te>100)
			{
				pet=floor(te);
				per=perfecto(pet);
				  if (per==0)

				    printf ("El nro perfecto");
					else
					  printf ("El nro no es perfecto");


			}
			/*printf ("Fecha: %d", fe);*/



			printf ("Ingrese secci¢n");
			sec=seccionvalida(seccion);
		}
	prom=st/ct;
	/*printf ("La fecha es:%d",fe);
	printf ("El promedio de temperatura y la seccion son:%f%c",prom, secant);*/
	tmin=floor(min);
	 if (tmin<12)
		{
		 fac=factorial(tmin);
		 /*printf ("La fecha es:%d",fe);*/
		printf ("el factorial es: %d",fac);
		}
}

/*printf ("La fecha es:%d",fe);*/
printf ("La temperatura maxima y su seccion es:%f%c",max,secmax);
printf ("La temperatura minima y su seccion es:%f%c",min,secmin);
getch();

}








float valido(float x, float y)
{
 float dato;
	do
	 {
	  printf ("Ingrese temperatura: ");
	  scanf("%f",&dato);
		}while (dato<x && dato>y);
	return (dato);
}






int perfecto (int x)
{int s, p, i;
 s=0;

	for (i=1;i<x-1;i++)
	{
	 if (x%i==0)
		s+=i;
	}

	   if (s==x)
		p=0;
		else
		p=-1;

return (p);
}





char seccionvalida (char seccion)
{

	do
	{
	  printf ("Ingrese seccion: ");
	  scanf("%c",&seccion);
		} while (seccion!= 'a' && seccion!= 'b' && seccion!= 'c' && seccion!='f' );
	   return (seccion);
}

int  factorial (int n)
{
int f;
int i;

f=1;
	for (i=1;i<n;i++)
		{
		 f=f*i;
		 }
return (f);

}



/*int fecha (int anio,int mes,int dia)
{
 int cd;
 int f;

  printf ("Ingrese dia: ");
  scanf("%d",&dia);
  printf ("Ingrese mes: ");
  scanf("%d",&mes);
  printf ("Ingrese año: ");
  scanf("%d",&anio);
  getch();



 if (anio>1900 && anio<2030)
    {
	if (mes==2)

	  if (anio%4==0 && anio%100!=0||anio%400==0)

		 cd=29;
	  else
		    cd=28;

		if (dia>=1&& dia<=cd)

		 f=0;
		 else
		   f=-1;
    }
		else
		   {
		   if (mes==1 ||mes==3 ||mes==5 ||mes==7 ||mes==8 ||mes==10 ||mes==12)

			if (dia>=1&& dia<=31)

		      f=0;
			 else
			   f=-1;
			else
			if (mes==4 ||mes==6 ||mes==9||mes==11)


			 if (dia>=1&& dia<=30)

		      f=0;
			 else
			   f=-1;
				else
				   printf("El mes es incorrecto");
		 }
				    /*else*/
				    /*f=-1;*/

/*return (f);


	 }*/

