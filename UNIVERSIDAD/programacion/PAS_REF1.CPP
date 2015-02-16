/*pasaje por referencia*/
#include <stdio.h>
#include <conio.h>

void cambio(int vec[]); /*prototipo*/

main ()
{
 clrscr();
 int i, vec[3];
 printf("Valores desde main antes de llamar a la funcion cambio: \n");
  for (i=0; i<3; i++)
   {
    vec [i]=i; /*se le asigna a cada elemento del vector el valor del indice*/
    printf("vec[%d]=%d\t",i,vec[i]);
   }
   cambio(vec);
   printf("Valores desde main despues de llamar a la funcion cambio: \n");
  for (i=0; i<3; i++)
   {
    printf("vec[%d]=%d\t",i,vec[i]);
    getch();
   }
   /*fin de main*/

   void cambio(int vec[])  /*definicion de la funcion cambio*/
   {
    int i;
     printf("\n Valores desde la funcion despues de modificarlos: \n");
	for (i=0; i<3; i++) 	{
	 vec[i]=9; /*se le asigna a los tres elementos el valor 9*/
	 printf("vec[%d]=%d\t",i,vec[i]);
	}
     return;
    }  /*fin de funcion cambio*/
        



