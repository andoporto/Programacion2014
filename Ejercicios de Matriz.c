#include <stdio.h>
#include <stdlib.h>
/*#define FIL 5
#define COL 5*/
#define FIL 6
#define COL 6

void mostrarMatriz (int [][COL]);
void diagonalPrincipal (int [][COL]);
void diagonalSecundaria (int [][COL]);
void trianguloSuperior (int [][COL]);
void trianguloInferior (int [][COL]);
void trianguloArriba (int [][COL]);
void trianguloAbajo (int [][COL]);
void trianguloIzquierdo (int [][COL]);
void trianguloDerecho (int [][COL]);

int main()
{
    //int m[FIL][COL]={{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}}; // Matriz 5x5
    int m[FIL][COL]={{1,2,3,4,5,6},{7,8,9,10,11,12},{13,14,15,16,17,18},{19,20,21,22,23,24},{25,26,27,28,29,30},{31,32,33,34,35,36}}; //<Matriz 6x6
    mostrarMatriz(m);
    printf("\n\n");
    printf("Elementos de la diagonal principal: ");
    diagonalPrincipal(m);
    printf("\n\n");
    printf("Elementos de la diagonal secundaria: ");
    diagonalSecundaria(m);
    printf("\n\n");
    printf("Elementos del triangulo superior: ");
    trianguloSuperior(m);
    printf("\n\n");
    printf("Elementos del triangulo inferior: ");
    trianguloInferior(m);
    printf("\n\n");
    printf("Elementos del triangulo de arriba: ");
    trianguloArriba(m);
    printf("\n\n");
    printf("Elementos del triangulo de abajo: ");
    trianguloAbajo(m);
    printf("\n\n");
    printf("Elementos del triangulo de la izquierda: ");
    trianguloIzquierdo(m);
    printf("\n\n");
    printf("Elementos del triangulo de la derecha: ");
    trianguloDerecho(m);
}

void mostrarMatriz(int mat[][COL])
{
    int i,j;
    for (i=0;i<FIL;i++)
       {
           printf("\n");
           for (j=0;j<COL;j++)
               printf("%d \t",mat[i][j]);
       }

}

void diagonalPrincipal(int mat[][COL])
{
    int i;
    for (i=0;i<FIL;i++)
        printf("%d ",mat[i][i]);
}

void diagonalSecundaria(int mat[][COL])
{
    int i;
    for (i=0;i<FIL;i++)
        printf("%d ",mat[i][(FIL-1)-i]);
}

void trianguloSuperior(int mat[][COL])
{
    int i,j;
    for (i=0;i<FIL-1;i++)
        for (j=i+1;j<COL;j++)
            printf("%d ",mat[i][j]);
}

void trianguloInferior(int mat[][COL])
{
    int i,j;
    for (i=1;i<FIL;i++)
        for (j=0;j<i;j++)
            printf("%d ",mat[i][j]);
}

void trianguloArriba(int mat[][COL])
{
    int i,j;
    for (i=0;i<(FIL-1)/2;i++)
        for (j=i+1;j<(FIL-1)-i;j++)
            printf("%d ",mat[i][j]);
}

void trianguloAbajo(int mat[][COL])
{
    int i,j;
    for (i=(FIL/2)+1;i<FIL;i++)
        for (j=FIL-i;j<i;j++)
            printf ("%d ",mat[i][j]);
}

void trianguloIzquierdo(int mat[][COL])
{
    int i,j;
    for (j=0;j<(FIL-1)/2;j++)
        for (i=j+1;i<(FIL-1)-j;i++)
            printf ("%d ",mat[i][j]);
}

void trianguloDerecho(int mat[][COL])
{
    int i,j;
    for (j=FIL-1;j>(FIL-1)/2;j--)
        for (i=FIL-j;i<j;i++)
            printf ("%d ",mat[i][j]);
}

