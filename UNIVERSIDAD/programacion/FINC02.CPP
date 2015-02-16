/*programa que utiliza una funcion promedio*/
#include<stdio.h>
#include<conio.h>
float promedio();
void main()
{
 float p;
 p=promedio();
 printf ("promedio= %f", p);
}

float promedio()
	  {
	   int n;
	   clrscr();
	   float suma=0,p;
	   printf("de cuantas calificaciones quieres el promedio");
	   scanf("%d", &n);
	   for (int i=0;i<n;i++)
		   {
			printf("Teclea la calificacion : %d", i+1);
			scanf("%f", &p);
			p+=p/n;
		   }
		  // p=suma/n;
		  // return p;
	  getch();
	  }