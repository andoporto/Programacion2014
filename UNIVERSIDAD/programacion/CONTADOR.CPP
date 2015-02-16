#include <stdio.h>
#include <conio.h>
#define FALSO 0
#define CIERTO 1
int finalizar(void);
int lea_char(void) ;
main()
{
  clrscr();
  int i = 0;
    int fin = FALSO;
      printf("Ejemplo de Funciones que retornan valor\n");
	 getch();
	while (fin == FALSO) {
	    i++;
		printf("i == %d\n", i);
		    fin = finalizar();
		      }
			printf("\n\nFIN DEL PROGRAMA........");
			 getch();
			  return 0;
			  }
			  int finalizar(void)
			  {
			    int c;
			      printf("Otro n£mero ? (s/n) ");
				do {
				    c = lea_char() ;
				      } while ((c != 'n') && (c != 's'));
					return (c == 'n');
					}
					int lea_char(void)
					{
					int j ;
					if( (j = getch()) >= 'A' && j <= 'Z' )
					 return( j + ( 'a' - 'A') ) ;
					 else
					  return j ;
					  }
