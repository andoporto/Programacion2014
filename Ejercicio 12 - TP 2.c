#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANT 100

void mostrartodo(char alu[][80], float notas[][6], int);
int ingresedatos(char alu[][80]);
void ingresenotas(float notas[][6], char alu[][80], int);
void mostrartodo(char alu[][80], float notas[][6], int);
float prom1(float notas[][6], int );
float prom2(float notas[][6], int, int n);

int main()
{
    int total;
    char alumnos[CANT][80];
    total = ingresedatos(alumnos);
    float notas[total][6];
    ingresenotas(notas, alumnos, total);
    mostrartodo(alumnos, notas, total);
    return 0;
}

int ingresedatos(char alu[][80])
{
    int n=0;
    printf(" Ingreso de alumnos: \n Ingrese 'FIN' para terminar\n Ingrese apellido/s y nombre/s: \n\n");
    do
    {
        printf("Alumno %d: ", n+1);
        fflush(stdin);
        scanf("%[^\n]", alu[n]);
    }while(strcmp(alu[n++],"FIN"));
    n--;
    return n;
}

void ingresenotas(float notas[][6], char alu[][80], int total)
{
    int n=0, i;
    printf("\n Ingrese las notas de los alumnos: \n Recuerde que son %d alumnos: \n\n", total);
    do
    {
        printf(" Alumno: %s ", alu[n]);
        for(i=0;i<6;i++)
        {
            printf("\n Nota P%d: ", i+1);
            fflush(stdin);
            scanf("%f", &notas[n][i]);
        }
        n++;
    }while(n<total);

}