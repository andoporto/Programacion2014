#include <stdio.h>
#include <string.h>
#include <conio.h>

void main()
     {
     clrscr();
     char cadena[]="Gorka es un tipo estupendo";
     char *p;
     int espacios=0, letras_e=0;

     p = cadena;
     while (*p!='\0')
           {
           if (*p==' ') espacios++;
           if (*p=='e') letras_e++;
           p++;
           }
     printf( "En la cadena \"%s\" hay:\n", cadena );
     printf( "  %i espacios\n", espacios );
     printf( "  %i letras e\n", letras_e );
     getch();
     }
