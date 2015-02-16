#include <stdio.h>
#include <conio.h>
#define FALSO  0
#define CIERTO 1
#define CENT_POR_INCH  25.4
void pausa(void)                 ;
void mostrar_menu(void)          ;
int seleccion(void)              ;
void cm_a_pulgadas(void)         ;
void grados_a_fahrenheit(void)   ;
double leer_valor(void)          ;

main()
{
  int fin = FALSO;
  while (!fin) {
    mostrar_menu();
    switch(seleccion()) {
      case 1:
        cm_a_pulgadas();
        break;
      case 2:
        grados_a_fahrenheit();
        break;
      case 3:
        fin = CIERTO;
        break;
      default:
        printf("\n¡Error en la Seleccion!\a\a\n");
        pausa() ;
    }
  }
  return 0;
}
/* Funciones */

void pausa(void)
{
char c = 0;
printf("\n\n\nAPRIETE ENTER PARA CONTINUAR ") ;
while( (c = getch()) != '\r') ;
}
void mostrar_menu(void)
{
  clrscr();
  printf("\n         Menu\n");
  printf("---------------------------\n");
  printf("1:  Centimetros a pulgadas\n");
  printf("2:  Celsius a Fahrenheit\n");
  printf("3:  Terminar\n");
}
int seleccion(void)
{
  printf("\nEscriba el n£mero de su Selecci¢n: ");
  return (getche() - '0');
}

void cm_a_pulgadas(void)
{
  double centimetros;  /* Guardará el valor pasado por leer_valor() */
  double pulgadas    ; /* Guardará el valor calculado */
  printf("\nEscriba los Centimetros a convertir: ");
  centimetros = leer_valor();
  pulgadas = centimetros  * CENT_POR_INCH;
  printf("%.3f Centimetros = %.3f Pulgadas\n", centimetros, pulgadas);
  pausa()   ;
}
void grados_a_fahrenheit(void)
{
  double grados;  /* Guardará el valor pasado por leer_valor() */
  double fahrenheit  ; /* Guardará el valor calculado */
  printf("\nEscriba los Grados a convertir: ");
  grados = leer_valor();
  fahrenheit = (((grados * 9.0)/5.0) + 32.0) ;
  printf("%.3f Grados = %.3f Fahrenheit", grados, fahrenheit);
  pausa();
}
double leer_valor(void)
{
  double valor;  /* Variable para guardar lo leido del teclado */
  scanf("%lf", &valor);
  return valor;
}
