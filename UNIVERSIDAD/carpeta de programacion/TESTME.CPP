#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void leedato(int, int);
void ordenadecreciente(int a[][],int);


void main (void)
{
int i,j,d,m,sector,cantloc,numdia,prim,dant;
int ventas[10];
float impo1,impo2,impo3,impo, total=0;
char cod;


for(i=1;i<8;i++)
   ventas[i];
   for(j=1;j<10;j++)
	total[i][j]=0;
printf("Ingrese el dia: ");
v=leedato(1,31);
printf("Ingrese el mes  : ");
v1=leedato(1,12);
printf("Ingrese el a�o  : ");
v2=leedato(1900,9999); 

printf("Ingrese el numero del vendedor  : ");
 scanf("%d,&nv);
 while (nv>0)
 {
  v3=leedato(1,8); 
  printf("Ingrese el numero de cliente  : ");
  v4=leedato(1,10); 
  printf("Ingrese la cantidad vendida : ");
  v5=leedato(1,9999);  
  total[v3-1][v4-1]=v5;
  printf("Ingrese el numero del vendedor  : ");
  scanf("%d,&nv);
  ch++;  
  }
  
    
  printf("Ingrese el numero de cliente  : ");
  scanf("%d,&nc); 
  printf("Ingrese la razon social: ");
  scanf("%d,&rs);    
  printf("Ingrese el numero del vendedor  : ");
  scanf("%d,&nv);
  printf("Ingrese el numero de articulo: ");
  scanf("%d,&na);
  printf("Ingrese la cantidad vendida : ");
  scanf("%d,&cv);
  
   while (nc!=0)
   {
    total[nv-1][na-1]+=cv;
	  scanf("%d,&nc); 
  printf("Ingrese la razon social: ");
  scanf("%d,&rs); 
  printf("Ingrese el numero de articulo: ");
  scanf("%d,&na);
  printf("Ingrese el importe de venta: ");
  scanf("%d,&iv);
  ca++;
  ventas[nv-1]+=iv;
  if (b==0||iv>may)
  {
   may=iv;
   ncmay=nc;
   rsmay=rs;
   b=1;
  }
  printf("Ingrese el numero de cliente  : ");
  scanf("%d,&nc); 
  printf("Ingrese la razon social: ");
  scanf("%d,&rs);    
  printf("Ingrese el numero del vendedor  : ");
  scanf("%d,&nv);
  printf("Ingrese el numero de articulo: ");
  scanf("%d,&na);
  printf("Ingrese la cantidad vendida : ");
  scanf("%d,&cv);
vtaact=fopen("ventasac.mae","wb");
for(i=1;i<8;i++)   
   for(j=1;j<10;j++)
		if(total[i][j]>0)
		{
		 v.nv=i+1;
		 v.na=j+1;
		 v.cv=total[i][j];
		 fwrite=(v,sizeof(vent),1,vtaact);
		}
fclose(vtaac);
ct=ch+ca;
ordenadecreciente(total,ct);
for(i=1;i<8;i++)  
	printf("%d     %d",ventas[i],i+1);
for(i=1;i<8;i++)
	if (i==0||ventas[i]>may)
		 may=ventas[i];
pos=posiciondelmayor(ventas);
printf("%d     %d",may,pos+1);
   

 



   
   
   

printf(" - ingrese el dia y mes de la actividad (dd/mm) : ");


clrscr();
marca=0;
do
	{
   printf("\n");
   if(marca==1)
      error();
	marca=1;
	
	fflush(stdin);
	scanf("%d/%d",&d,&m);
	}

