/*de la carpeta*/

#include <stdio.h>
#include <conio.h>

int suma (int a, int b);


void main ()

{
	clrscr();

	int a;
	int b;
	int s;
	int i;
		for (i=1;i<=20;i++)
		{
		printf("\n");
		printf("Ingrese valores de A y B: ");
		scanf("%d%d",&a,&b);
		s = suma(a,b);
  		printf("La suma es: %d",s);
  		}
	    getch();
}


int suma (int a,int b)
{
 int su;
 su= a+b;
 return su;
}
