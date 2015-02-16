#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAM 60
#define CANT_A 5

/*
Falta que grabe los elementos del vector en un archivo de texto.
*/

char menu (char [][TAM], char *);
void mostrarmenu (char [][TAM]);
void pausa (char *);
void iniarray (float *, int *);
void minimo (float *, int *);
void pospares (float *, int *);
void ordeninverso (float *, int *);
void ejecutar (char, float*, int *);

int main()
{
    int cant;
    float *pa, array[CANT_A];
    pa=&array[0];   //Trabajo en modo indirecto, sin utilizar subíndices. A las funciones les envío la dirección del primer elemento del vector, mediante este puntero.
    char opcion, *msj="Opcion incorrecta", *msj2="Fin del programa";
    char matrizopciones[][TAM]={"abcs", "Minimo elemento en un array", "Promedio posiciones pares", "Orden inverso", "Salir"};
    iniarray(pa, &cant);
    opcion=menu(matrizopciones, msj);
    ejecutar(opcion, pa, &cant);
    pausa(msj2);
    getchar();
    return 0;
}

char menu (char matrizopciones[][TAM], char *msj)
{
    char c;
    mostrarmenu(matrizopciones);
    printf("\nElija una opcion: ");
    scanf("%c", &c);
    c=tolower(c);   //Si el usuario ingresa un carácter en mayúscula, lo convierte a minúscula.
    while(!strchr(matrizopciones[0], c)) //Si no encuentra ningún carácter válido, utilizado en las opciones del programa,
    {                                    //strchr envía el carácter nulo, validando el while.
        pausa(msj); //msj="Opción incorrecta".
        system("pause");
        system("cls");
        mostrarmenu(matrizopciones);
        printf("\nElija una opcion: ");
        scanf("%c", &c);
        c=tolower(c);
    }
    return c;
}

void mostrarmenu (char matrizopciones[][TAM])
{
    int i;
    for (i=0; matrizopciones[0][i]; i++)
    {
        printf("%c - %s\n", matrizopciones[0][i], matrizopciones[i+1]); //%c Imprime el carácter, asignado a cada función, en la posición [0][i] de la matriz.
    }                                                                   //%s La cadena [i+1], en otras palabras, la leyenda de cada opción del programa.
}

void pausa (char *msj)
{   if (*msj);
        printf("\n\n%s\n", msj);
    fflush(stdin);  //Limpieza buffer teclado.
}

void iniarray (float *array, int *cant)
{
    int i;
    do
    {
        printf("Ingrese cantidad de elementos: ");
        scanf("%d", cant);
        if (*cant>CANT_A)
        {
            printf("\nEl limite es de %d elementos.\n\n", CANT_A);
            system("pause");
            system("cls");
        }
        if (*cant<=0)
        {
            printf("\nEl limite debe ser superior a 0.\n\n");
            system("pause");
            system("cls");
        }
    }while (*cant<=0 || *cant>CANT_A);

    for (i=0; i<*cant; i++)
    {
        printf("Ingrese un valor en la posicion #%d: ", i+1);
        scanf("%f", (array+i));
    }
    system("cls");
    fflush(stdin);  //Limpieza buffer teclado.
}

void minimo (float *array, int *cant)
{

}
}
