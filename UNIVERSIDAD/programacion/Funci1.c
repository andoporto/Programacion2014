#include <stdio.h>

/* Declaraci¢n de la funci¢n y el tipo de sus par metros */
double valor_medio(double p_valor, double s_valor, double inc) ;
clrscr();
void main()

{

double x, y, z, resultado ;
/*clrscr(); */
printf("Ingrese el primer valor: ") ;
scanf("%lf", &x ) ;
printf("\nIngrese el segundo valor: ");
scanf("%lf", &y ) ;
printf("\nIngrese el incremento    : ");
scanf("%lf", &z) ;
resultado = valor_medio( x, y, z );     /* llamada a la funci¢n y
					      pasaje de argumentos   */

printf("\n\nResultado de la operaci¢n: %lf", resultado) ;

printf("\n\nValor con que quedaron las variables: ") ;
printf("\n Primer valor : %lf ", x ) ;
printf("\n Segundo valor: %lf ", y ) ;
printf("\n Incremento   : %lf ", z ) ;

	 }

	 getch();
	  /* Definici¢n de la funci¢n y sus par metros */
   double valor_medio( double p_valor, double s_valor, double inc )
	      {
		 p_valor  += inc ;
		 s_valor += inc ;
		 return ( (p_valor + s_valor ) / 2.0 ) ;
					      }

