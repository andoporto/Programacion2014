#include <stdio.h>
#include <string.h>
#include <conio.h>

#define ELEMENTOS       5

void main()
     {
     clrscr();
     char *dichos[ELEMENTOS] = {
         "La avaricia rompe el saco",
         "Más Vale pájaro en mano que ciento volando",
         "No por mucho madrugar amanece más temprano",
         "Año de nieves, año de bienes",
         "A caballo regalado no le mires el diente"
         };
     char *temp;
     int i, j;

     printf( "Lista desordenada:\n" );
     for( i=0; i<ELEMENTOS; i++ )
          printf( "  %s.\n", dichos[i] );
     for( i=0; i<ELEMENTOS-1; i++ )
          for( j=0; j<ELEMENTOS; j++ )
               if (strcmp(dichos[i], dichos[j])>0)
                  {
                  temp = dichos[i];
                  dichos[i] = dichos[j];
                  dichos[j] = temp;
                  }
     printf( "Lista ordenada:\n" );
     for( i=0; i<ELEMENTOS; i++ )
          printf( "  %s.\n", dichos[i] );
     getch();
     }
