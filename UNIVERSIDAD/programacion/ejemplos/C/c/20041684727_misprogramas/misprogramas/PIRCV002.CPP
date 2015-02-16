/*Programa para transformar kilometros a metros, centimetros y milimetros*/
#include<stdio.h>
#include<conio.h>
void main()
				 {
				  float km,mts,cm,mm;
				  clrscr();
				  printf("Este programa transforma kilometros a metros, milimetros\n");
				  printf(" y centimetros, teclea la cantidad de kilometros: ");
				  scanf("%f", &km);
				  mts=km*1000;
				  cm=km*10000;
				  mm=km*100000;
				  printf("La cantidad en metros=%f\n", mts);
				  printf("La cantidad en centimetros=%f\n", cm);
				  printf("La cantidad en milimetros=%f\n", mm);
				  getch();
				 }

