	#include <conio.h>
   #include <stdio.h>
   #include <stdlib.h>
   void main()
   {	int mat[3][4];
   	int i,j;
   	printf("ingrese los valores por fila");
   	for(i=0;i<3;i++)
       	for(j=0;j<4;j++)
    	       scanf("%d",&mat[i][j]);

    for(i=0;i<3;i++)
       for(j=0;j<4;j++)
           printf("la matriz quedo como %d ",mat[i][j]);
    getch();

    }//fin del main