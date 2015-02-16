#include <stdio.h>
#include <stdlib.h>

#define FIL1 2
#define COL1 3

#define FIL2 3
#define COL2 4

char* multiplicarMatrices(int[FIL1][COL1],int[FIL2][COL2]);
void mostrarMatriz (int*,int,int);

int main()
{
    int mat1[FIL1][COL1] = {{1,2,3},{4,5,6}};
    int mat2[FIL2][COL2] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int *mat3;
    printf("Matriz 1:\n\n");
    mostrarMatriz(mat1,FIL1,COL1);
    printf("\n\n");
    printf("Matriz 2:\n\n");
    mostrarMatriz (mat2,FIL2,COL2);
    printf("\n\n");

    if (COL1!=FIL2)
      {
          printf ("No se puede realizar la multiplicacion");
          getch();
          exit(1);
      }
    mat3=multiplicarMatrices (mat1,mat2);
    printf("\n\n");
    printf("Matriz resultado:\n\n");
    mostrarMatriz(mat3,FIL1,COL2);
	printf("\n");
    return 0;
}

int* multiplicarMatrices (int m1[FIL1][COL1],int m2[FIL2][COL2])
    {int i,j,k;
     int *m3;
     m3= (int*)calloc(COL1*FIL2,sizeof(int));
     if (!m3)
        return NULL;
    for( i=0;i<FIL1;i++)
        for( k=0;k<COL2;k++)
            for( j=0;j<FIL2;j++)
                *(m3+k+i*COL2)+=m1[i][j]*m2[j][k];      //mat3[i][k]+=(mat1[i][j]*mat2[j][k]);
    return m3;
    }

void mostrarMatriz (int *m,int fil, int col)
{
    int i,j;
    for( i=0;i<fil;i++)
        {
        for( j=0;j<col;j++)
            printf("%d\t",*(m+i*col+j));
        printf("\n");
        }
    printf("\n");
}