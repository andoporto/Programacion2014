/*Imprime y calcula el promedio de seis puntajes*/

#include <stdio.h>

int main(void);
void imprimirPuntajes(float puntajes[]);

int main(void)
{
 char universidad[]="Universidad Tecnologica Nacional";
 float puntajes[6]={88.7, 90.4, 76.0, 100.0, 86.7};
 float promedio=0.0;
 int contador;
  /*Llamada a función que imprime las notas*/
  imprimirPuntajes(puntajes);

  /*Computa el total de los puntajes*/

  for (contador=0;contador<6;contador++)
   {promedio+=puntajes[contador];}
   /*Computa el promedio*/
   promedio  /=(float)6;
   printf("\n En la %s, el promedio de sus notas es de %.1f",universidad,promedio);
   return 0;
 }

void imprimirPuntajes(float puntajes[6])
{
 /*Imprime las seis calificaciones*/
  int contador;
  printf("Estos son sus puntajes:\n");
  /*Titulo*/
    for (contador=0;contador<6;contador++)
      printf("%.1f \n", puntajes[contador]);
   //return 0;
 }
