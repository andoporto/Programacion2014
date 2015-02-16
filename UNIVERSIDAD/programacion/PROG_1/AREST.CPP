#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

void main (void)
struct dato{
			int legajo;
			char nombre[15];
			char apellido[15];
            int dato;
            };
struct dato alumno;

FILE*fp;
if((fp=fopen("padron.dat","wb"))==NULL;
{
 printf("\n no se pudo abrir el archivo");
 exit(1);
 }
 
 do
 {
  printf("\ningrese legajo");
  scanf("%d",&alumno.legajo);
  printf("\n ingrese nombre
 }