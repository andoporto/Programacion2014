#include<stdio.h>
#include<conio.h>
void main()
{
clrscr();
char nombre[5][50],sexo[5];
int edad[5],i,I;
float prom[5];
printf("programa que almacena datos de 5 personas\n\n");
for(i=0;i<5;i++){
printf("Nombre completo alumno # %d  ",i+1);
  gets(nombre[i]);
printf("           Edad alumno # %d  ",i+1);
 scanf("%d",&edad[i]);
fflush(stdin);
printf("           Sexo alumno # %d  ",i+1);
 scanf("%c",&sexo[i]);
printf("       Promedio alumno # %d  ",i+1);
 scanf("%f",&prom[i]);
fflush(stdin);
				}
printf("Cual alumno quieres visualisar ");
 scanf("%d",&I);
		   printf("Nombre %s\n ",nombre[I]);
		   printf("  Edad %d\n ",edad[I]);
		   printf("  Sexo %c\n ",sexo[I]);
		   printf("Promed %f\n ",prom[I]);
}
getch();
