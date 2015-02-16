/*Programa que c…lcula una edad en base a la fecha de nacimiento de la persona,
la fecha debe ser cambiada cada a¤o*/
#include<stdio.h>
#include<conio.h>
void main()
		 {
		  int fecdn,edad;
		  const a=2004;
		  clrscr();
		  printf("Este programa calcula tu edad en base a tu fecha de nacimiento\n");
		  printf("Acontinuaci•n, escribe tu fecha de nacimiento\n");
		  printf(" y presiona enter para realizar el c…lculo: ");
		  scanf("%d", &fecdn);
		  edad=a-fecdn;
		  printf(" tu edad es:%d a¤os.", edad);
		  getch();
		 }
