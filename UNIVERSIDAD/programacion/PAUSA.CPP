#include <stdio.h>
void pausa(void) ;
main()
{
  int contador = 1;
    printf("VALOR DEL CONTADOR DENTRO DEL while \n");
      while (contador <= 10) {
	  if(contador == 5 ) pausa();
	      printf("%d\n", contador++);
		}
		  pausa() ;
		    printf("VALOR DEL CONTADOR LUEGO DE SALIR DEL while: %d", contador) ;
		      return 0;
		      }

		      void pausa(void)
		      {
		      char c ;
		      printf("\nAPRIETE ENTER PARA CONTINUAR ") ;
		      while( (c = getchar()) != '\n') ;
}