#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


void main();
{
 clrscr(); 
 int marca,s,i,j,m,n,r,a,b,a1,b1,pesquisa,x[10][10];
 s=0;r=0;
 printf("Ingrese la cantidad de filas-entre 1 y 10-\n");
 scanf("%d",&m);
 printf("Ingrese la cantidad de columnas-entre 1 y 10-\n");
 scanf("%d",&n);
 printf("Ingrese los valores de la matriz");
	for(i=0;i<m;i++)
	{
	 for(j=0;j<n;j++)
	  scanf("%d",&n);
 
 
 
 
 if (stock=fopen("stockfe.dat","rb"))==NULL)
  {
    printf("Error al abrir el archivo );
	exit(0);
	}
clrscr();
printf("Ingrese el numero de articulo: ");
 scanf("%d",&numero); fflush(stdin);
 busq_secuencial(stock,numero);
 busq_directa(stock,numero);
 busq_binaria(stock,numero);
 fclose(stock);
 }
 void busq_secuencial(FILE *ar,int nro);
 {
  struct arti a;
  fread(&a,sizeof(struct arti),1,ar);
  while(!feof(ar)&&a.nume!=nro)
   fread(&a,sizeof(struct arti),1,ar);
  if (feof(ar)
	printf("el numero de articulo: %d, no esta en el archivo\n",nro);
  else
   {
    printf("Articulo encontrado. Sus Datos son: %d %-26s\n",a.nume,a.desc);
	printf("%.2f %d\n",a.costo,a.saldo);
	}
	getch();
  }
  
  void busq_directa(FILE *ar,int nro);
  {
   struct arti a;
   long int tam,desp;
   fseek(ar,0,2);
   tam=ftell(ar)/sizeof(struct art);
   if (nro>0 && nro<=tam)
   {
    desp=(long int) (nro-1)*sizeof(struct arti);
	fseek(ar,desp,0);
	fread(&a,sizeof(struct arti),1,ar);
	printf("Articulo encontrado. Sus Datos son: %d %-26s\n",a.nume,a.desc);
	printf("%.2f %d\n",a.costo,a.saldo);
	}
	else
		printf("el numero de articulo: %d, no esta en el archivo\n",nro);
	getch();
   }
   
   void busq_binaria(FILE *ar,int nro);
  {
	struct arti a;
	int sen=0;
   long int tam,desp;
   fseek(ar,0,2);
  ult=(ftell(ar)/sizeof(struct art))-1;
  while (pri<=ult && sen==0)
   {
    med=(pri+ult)/2;
	fseek(ar,desp,0);
	fread(&a,sizeof(struct arti),1,ar);
	if (nro==a.nume)
		sen=1;
	else
	   if (nro<a.nume)
	    ult=med-1;
		
		
	
	
	printf("Articulo encontrado. Sus Datos son: %d %-26s\n",a.nume,a.desc);
	printf("%.2f %d\n",a.costo,a.saldo);
	}
	else
		printf("el numero de articulo: %d, no esta en el archivo\n",nro);
	getch();
   }
   
  
  
 
			  