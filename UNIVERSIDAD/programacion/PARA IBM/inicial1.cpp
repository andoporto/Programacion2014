#include <stdio.h>
#include <conio.h>

union _persona
      {
      char nombre[10];
      char inicial;
      } pers;

void main()
     {
     clrscr();
     printf("Escribe tu nombre: ");
     gets(pers.nombre);
     printf("\nTu nombre es: %s\n", pers.nombre);
     printf("Tu inicial es: %c\n", pers.inicial);
     getch();
     }

