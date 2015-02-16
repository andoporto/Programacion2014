#include <stdio.h>
#include <conio.h>
#include <stdib.h>

int maximo(int[],int);

struct alum
{
   int alt;
	int edad;
};

void main()
{

	struct alum t[5];
   int i;
   FILE * A1;

   for(i=0;i<5;i++)
   {
   	printf("Ingrese la altura ");
      scanf("%d",&t[i].alt);
      printf("Ingrese la edad ");
      scanf("%d",&t[i].edad);
   }

   for(i=0;i<5;i++)
   {

   	if ((A1=fopen("arhivo.dat")


   }




}




