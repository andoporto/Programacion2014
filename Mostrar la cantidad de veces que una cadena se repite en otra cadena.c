#include <stdio.h>
#include <stdlib.h>
#define aMayusc(X)((X)>='a'&&(X)<='z'?(X)-32:(X))

int cantrepeticiones (char*,char*);

int main()
{
    char cad1[]= "ananana";
    char cad2[]= "ana";
    puts(cad1);
    puts(cad2);
    printf ("La cadena 2 se repite %d veces en la cadena 1",cantrepeticiones(cad1,cad2));
    printf ("\n");
    return 0;
}

int cantrepeticiones(char* c1, char* c2)
{
    int repeticiones=0;
    char* coindicencia=c1;  //Para guardar la posicion donde encuentra coincidencia con el primer caracter de la cadena a buscar
    char* inicio=c2; // Para poder volver al inicio de la cadena a buscar, en caso de no encontrarla completa
    while (*c1)
    {
        if (aMayusc(*c1)==aMayusc(*c2))
        {
            coindicencia=c1; //Guardo la posicion de la primera coincidencia
            while (*c1 && *c2 && aMayusc(*c1)==aMayusc(*c2))
            {
                c1++;
                c2++;
            }
            if (!*c2)
                repeticiones+=1;
            c1=coindicencia; // Vuelvo a la posicion de la primera coincidencia de caracteres
            c2=inicio; //Vuelvo al inicio del a cadena a buscar, por que el puntero quedo en el \0 o en la posicion donde no hubo coincidencia
        }
        c1++;
    }
    return repeticiones;
}
