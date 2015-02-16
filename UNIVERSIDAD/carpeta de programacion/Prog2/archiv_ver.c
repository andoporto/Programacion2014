#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define LONGI 51
typedef struct
{
	char apyn[LONGI];
   int edad;
   float prom;
}t_info;
void main(int argc, char *argv[])
{
   int z;
	t_info info;
	FILE *pa;
	clrscr();
	if(argc!=3)exit(printf("Error\n"));
	pa = fopen(argv[1],argv[2]);
   if(pa==NULL)exit(printf("Error\n"));
   for(z=0;z<4;z++)
   {
   	printf("ingrese Apellido:\n");gets(info.apyn);
      printf("ingrese Edad:\n");scanf("%d",&info.edad);
      printf("ingrese Promedio:\n");scanf("%f",&info.prom);
      fwrite(&info,sizeof(t_info),1,pa);
      fflush(stdin);
   }
   fclose(pa);

}
