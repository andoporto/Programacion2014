#include<COnio.h>
#include<STdio.h>
#include<STdlib.h>

int **creo_matriz(int f, int c, int **matriz);
int **lleno_matriz(int f, int c, int **matriz);
void bajo_matriz(int f, int c, int **matriz);

void main(){

int f,c;
int **mat;

clrscr();

printf("cant filas, cant columnas\n");
scanf("%d %d",&f,&c);

mat = creo_matriz(f, c, mat);
mat = lleno_matriz(f, c, mat);

bajo_matriz(f, c, mat);





//Muestro
int i,j;
for (i=0;i<f;i++)
{
 for (j=0;j<c;j++) printf("%d",mat[i][j]);
 printf("\n");
}

  getch();

}


int **creo_matriz(int f, int c, int **matriz)
{
int i;

//divido en filas enteras
   // matriz = (int**) calloc(f,sizeof(int));
      matriz = (int**) malloc(f);

//divido cada fila con columnas enteras
   //for (i=0; i<f;i++) matriz[i] =  (int*) calloc(c,sizeof(int));
   for (i=0; i<f;i++) matriz[i] =  (int*) malloc(c);

return matriz;

}


int **lleno_matriz(int f, int c, int **matriz)
{
 int i,j;

 for (i=0;i<f;i++){
  for (j=0;j<c;j++){
    printf("ingresar posicion %d, %d",i+1,j+1);
    scanf("%d", &matriz[i][j]);
  			    }
                  }
 return matriz;
}

void bajo_matriz(int f, int c, int **matriz)
{
int i, j;

FILE *fout = fopen("C:\\matrix.txt","wt");  //Arch.Salida

for(i=0;i<f;i++){
   for(j=0;j<c;j++) fprintf(fout,"%d",matriz[i][j]);
                    //fwrite(&matriz[i][j],sizeof(int),1,fout) ;
                }

 fclose(fout);


}
