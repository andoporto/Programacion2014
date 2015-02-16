#include <stdio.h>
#include <stdlib.h>

#define FIL1 2
#define COL1 3

#define FIL2 3
#define COL2 4

void multiplicarMatrices(int[FIL1][COL1],int[FIL2][COL2],int[FIL1][COL2]);
void mostrarMatriz1 (int[][COL1]);
void mostrarMatriz2(int mat[][COL2]);
void mostrarMatrizRes(int mat[][COL2]);

void main()
{
    int mat1[FIL1][COL1] = {{1,2,3},{4,5,6}};
    int mat2[FIL2][COL2] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int mat3[FIL1][COL2] = {0};

    mostrarMatriz1(mat1);
    printf("\n\n");
    mostrarMatriz2 (mat2);
    printf("\n\n");

    if (COL1!=FIL2)
      {
          printf ("No se puede realizar la multiplicacion");
          getch();
          exit(1);
      }
    multiplicarMatrices (mat1,mat2,mat3);
    printf("\n\n");
    mostrarMatrizRes(mat3);
    getch();
}

void multiplicarMatrices (int m1[FIL1][COL1],int m2[FIL2][COL2],int m3[FIL1][COL2])
{
    int i,j,z;
    for (i=0;i<FIL1;i++)
       {
           for (j=0;j<COL2;j++)
              {
                  for (z=0;z<FIL2;z++)
                     m3[i][j]+=(m1[i][z] * m2[z][j]);
              }
       }
}

void mostrarMatriz1(int mat[][COL1])
{
    int i,j;
    for (i=0;i<FIL1;i++)
       {
           printf("\n");
           for (j=0;j<COL1;j++)
               printf("%d \t",mat[i][j]);
       }

}

void mostrarMatriz2(int mat[][COL2])
{
    int i,j;
    for (i=0;i<FIL2;i++)
       {
           printf("\n");
           for (j=0;j<COL2;j++)
               printf("%d \t",mat[i][j]);
       }

}

void mostrarMatrizRes(int mat[][COL2])
{
    int i,j;
    for (i=0;i<FIL1;i++)
       {
           printf("\n");
           for (j=0;j<COL2;j++)
               printf("%d \t",mat[i][j]);
       }

}