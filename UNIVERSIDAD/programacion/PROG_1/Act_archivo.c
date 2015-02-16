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
   char busco[LONGI];
	t_info info;
	FILE *pa;
	clrscr();
	if(argc!=3)exit(printf("Error\n"));
	pa = fopen(argv[1],argv[2]);
   if(pa==NULL)exit(printf("Error\n"));
   printf("ingrese dato a buscar:");fflush(stdin);
   gets(busco);
   fread(&info,sizeof(t_info),1,pa);
   while(!feof(pa))

   fclose(pa);

}