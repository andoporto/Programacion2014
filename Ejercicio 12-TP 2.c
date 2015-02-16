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

void mostrartodo(char alu[][80], float notas[][6], int total)
{
    FILE *fp;
    int i;
    float promgral, promev[5];
    fp = fopen("alumnos.txt", "wt");
    if(fp)
        printf("El archivo se abrio correctamente");
    else
    {
        printf("El archivo fallo en la apertura");
        exit(1);
    }
    fputs("12 12345678901234567890123456789012345 12345 12345 12345 12345 12345 12345   12345\n", fp);
    fputs("   Apellido/s, Nombre/s                 P. 1  P. 2  P. 3  P. 4  P. 5  P. 6 - Prome\n", fp);
    fputs("   =================================== ===== ===== ===== ===== ===== ===== - =====\n", fp);
    fputs("\n",fp);
    for(i=0;i<total;i++)
    {
        promgral = prom1(notas, i);
        fprintf(fp, "%2d %-35s %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f - %5.2f\n", i, alu[i], notas[i][0], notas[i][1], notas[i][2], notas[i][3], notas[i][4], notas[i][5], promgral);
    }
    fputs("\n",fp);
    for(i=0;i<6;i++)
    {
        promev[i] = prom2(notas, total, i);
    }
    fprintf(fp,"  PROMEDIO POR EVALUACION:             %5.2f %5.2f %5.2f %5.2f %5.2f %5.2f \n", promev[0], promev[1], promev[2], promev[3], promev[4], promev[5]);
}

float prom1(float notas[][6], int n)
{
    int i;
    float prom;
    for(i=0;i<6;i++)
    {
        prom+=notas[n][i];
    }
    prom/=i;
    return prom;
}

float prom2(float notas[][6], int total, int n)
{
    int i;
    float prom=0;
    for(i=0;i<total;i++)
    {
        prom+=notas[i][n];
    }
    prom/=total;
    return prom;
}
