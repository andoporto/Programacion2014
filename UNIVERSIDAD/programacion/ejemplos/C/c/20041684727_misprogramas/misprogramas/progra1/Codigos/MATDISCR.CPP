#include<stdio.h>
#include<conio.h>
void main ()
{
clrscr();
int m1[50][50],m2[50][50],m3[50][50],i,j,k,l,m,ac1=0,ac2=0;
printf("dame el numero de pares ordenados:  ");
 scanf("%d",&m);
printf("\n");
printf("A continuacion se mostrara la matriz inicializada en ceros\n");
for(i=0;i<m;i++)
   for(j=0;j<m;j++){   //inicializa la matriz en ceros
      m1[i][j]=0;
		   }
for(i=0;i<m;i++){
    printf("\n");        //imprime la pinche matriz en ceros
    for(j=0;j<m;j++)
       printf("[%d] ", m1[i][j]);
		}
printf("\n");
for(i=0;i<m;i++){
   printf("valor de elemento  x  par ordenado #%d\n",i+1);
    scanf("%d",&ac1);
   ac1=j;     //aqui va i
   printf("valor de elemento  y  par ordenado #%d\n",i+1);
    scanf("%d",&ac2);
   ac2=i;    //aqui va j
//   m1[ac1-1][ac2-1]=1;    //corregir esta operacion
		}
printf("Esta es tu relacion\n");
for(i=0;i<m;i++)                  //imprime la relacion mal
   printf("(%d,%d),",ac1,ac2);

for(i=0;i<m;i++){
    printf("\n");            //imprime la matriz pero no como quiero
    for(j=0;j<m;j++)
       printf("[%d] ", m1[i][j]);
		}                      //esta basura de abajo es otro puto
						   //programa
/*printf("dame los valores de la matriz 1\n");
for(i=0;i<m;i++)
   for(j=0;j<m;j++){
      m3[i][j]=0;
      printf("Valor [%d,%d] \n",i+1,j+1);
       scanf("%d",& m1[i][j]);
		   }
printf("dame los valores de la matriz 2\n");
for(i=0;i<m;i++)
   for(j=0;j<m;j++){
      printf("Valor [%d,%d] \n",i+1,j+1);
       scanf("%d",& m2[i][j]);
		   }
for(i=0;i<m;i++)
   for(l=0;l<m;l++)
      {
      k=0;
      for(j=0;(j<m && k<m);j++){
	 m3[k][l]=(m1[i][j]*m2[k][l])+m3[k][l];
      k++;
			       }
      }

 for(i=0;i<m;i++){
    printf("\n");
    for(j=0;j<m;j++){
       printf("[%d] ", m3[i][j]);
		    }
		 }   */
getch();
}