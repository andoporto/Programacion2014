  #include <conio.h>
  #include <stdio.h>
  #include <stdlib.h>
  cargamat (int mat[][4],int,int);
  void main()
  {int mat[3][4];
	int sf[3],i,j;
   cargamat(mat,3,4);
  for(i=0;i<3;i++)
  sf[i]=0;
  for(j=0;j<4;j++)
  sf[i]+=mat[i][j];
  getch();
  }
  cargamat(int m[][4],int f,int c)
   {int i=0,j=0;
   printf("cargar la matriz");
   for(i=0;i<f;i++)
  		 for(j=0;j<c;j++)
			scanf("%d",&m[i][j]);
	}

