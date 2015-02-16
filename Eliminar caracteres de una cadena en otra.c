#include <stdio.h>
#include <stdlib.h>
#define TAM 50

char* eliminarChars (char*,char*);

int main()
{
    char cad1[TAM];
    char cad2[TAM];
    printf("\n Ingrese cadena 1: ");
    gets(cad1);
    printf("\n Ingrese cadena 2: ");
    gets(cad2);
    printf("\n Cadena1 recortada: ");
    puts(eliminarChars(cad1,cad2));
    printf("\n");
    return 0;
}

char* eliminarChars (char* c1, char*c2)
{
    char *pl,*pe; // Puntero de lectura, puntero de escritura
    pl=pe=c1;
    while (*c2)
    {
        while (*pl)
        {
            if (*pl!=*c2)
            {
                *pe=*pl;  // Va sobrescribiendo la cadena, corriendo los caracteres  a la izquierda
                pe++;
            }
            pl++; //Con esto se saltea los caracteres que tiene que eliminar
        }
        *pe='\0'; //Pone un \0 para achicar la cadena
        pl=pe=c1; //Vuelve los punteros a la primera posicion
        c2++;
    }
    return c1;
}
