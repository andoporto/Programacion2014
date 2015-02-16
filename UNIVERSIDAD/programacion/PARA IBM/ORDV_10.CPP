 //ordenar un vector de 10 elementos//
#include <stdio.h>
#include <conio.h>   

void main()
{
 int i, vec[10], marca, aux;
 printf ("Carga del vector \n");
 for (i=0;i<10;i++)
   {
    printf("Posicion: %d Dato: ",i+1);
    scanf("%d", &vec[i]);
    }
  /*ordenamiento en forma ascendente*/
  marca=0;
  while (marca == 0)
  {
   marca=1;
   for (i=0;i<9;i++)
   {
    if (vec[i] > vec [i+1])
    {
      aux=vec[i];
      vec[i]=vec[i+1];
      vec[i+1]=aux;
      marca=0;
     }
    }
     }
     printf("\n\n Informe del vector ordenado");
    for (i=0;i<10;i++)
    	printf("\n Posicion: %d Dato: %d", i+1,vec[i]);
    printf ("\n\n\n\t Tipee una tecla para finalizar");
    getch();
    }



