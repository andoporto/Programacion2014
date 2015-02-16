#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void leedato(int, int);
void ordenadecreciente(int a[][],int);


void main (void)
{
int i,d,m,sector,cantloc,numdia,prim,dant;
int ventas[i];
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
printf("Ingrese el año  : ");
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
while(valfecha(d,m)==0||d==99);
dant=d;

printf("\n - ingrese importes ");
printf("\n\n\t* sector 1 : ");
scanf("%f",&impo1);
printf("\n\t* sector 2 : ");
scanf("%f",&impo2);
printf("\n\t* sector 3 : ");
scanf("%f",&impo3);
linea('*');

while(d!=99)
	{
	if(d==1)
   	borrar(loclibres);
	else
		creamatriz(loclibres);

	printf("\n\n\t\t\t- datos de la venta -\n");

	marca=0;
	do
		{
	   printf("\n");
   	if(marca==1)
     		error();
		marca=1;
      printf(" - sector : ");
      scanf ("%d",&sector);
		}
	while(sector!=1 && sector!=2 && sector!=3 && sector!=4);

	while(sector!=4)
		{
		marca=0;
	   do
	   	{
		   printf("\n");
   		if(marca==1)
     			error();
         marca=1;
         printf(" - localidades : ");
         scanf ("%d",&cantloc);
			}
	 	while(cantloc>10||cantloc<1);

		marca=0;
	   do
   		{
		   printf("\n");
   		if(marca==1)
     			error();
         marca=1;
			printf(" - en el dia : ");
			scanf ("%d",&numdia);
	      }
   	while(numdia<d||numdia>30);

		disponible(loclibres,numdia,cantloc,sector,&cod,&prim);

		printf("\n\n - resumen");
      if(cod=='s')
      	{
			switch(sector)
				{
				case 1 : impo=impo1*cantloc;
	  	      break;
	     	   case 2 : impo=impo2*cantloc;
	         break;
	        	case 3 : impo=impo3*cantloc;
	        	break;
	         }
			printf("\n\n\tdia\tmes\tsector\tlocalidades\tdesde\thasta\timporte");
			linea('-');
		   printf("\t%d\t%d\t%d\t%d\t\t%d\t%d\t$%.2f\n", numdia,m,sector,cantloc,prim,prim+cantloc-1,impo);
			linea('=');
			total+=impo;
         locvendidas[sector-1]+=cantloc;
	   	}
	   else
			{
   		printf("\t\t\tno hay localidades libres!!!\n\n");
			linea('=');
         }
		marca=0;
		do
			{
		   printf("\n");
   		if(marca==1)
     			error();
         marca=1;
	      printf(" - sector : ");
			scanf ("%d",&sector);
	 		}
 	      while(sector!=1 && sector!=2 && sector!=3 && sector!=4);
		}
	grabaarchivo(loclibres);

	printf("\n");
   linea('=');

	printf("\n\tlos datos del dia %d/%d fueron guardados satisfactoriamente",d,m);

	printf("\n");
	linea('=');

	getch();
   clrscr();

   marca=0;
   do
		{
	   printf("\n");
   	if(marca==1)
     		error();
      marca=1;
		printf(" - ingrese el dia de la actividad : ");
   	scanf("%d",&d);
		}
	while(valfecha(d,m)==0||d<=dant);
   linea('-');
	}
clrscr();
linea('*');
linea('*');
printf("\n - resumen de ventas del mes %d",m);
for(i=0;i<=2;i++)
	printf("\n\n\t* sector %d, %d localidades vendidas",i+1,locvendidas[i]);
printf("\n\n\t* total recaudado : $%.2f\n",total);
linea('*');
linea('*');

gotoxy(30,wherey()+4);
printf("programa finalizado!!!");
getch();
}

////////////////////////////////////////////////////////////////////////////////

int valfecha(int dd, int mm)
{
if(dd>=1&&dd<=30&&mm>=1&&mm<=12||dd==99)
  	return(1);
else
  	return(0);
}

////////////////////////////////////////////////////////////////////////////////

void borrar(int matriz[30][40])
{
int i, j;
for(i=0;i<=29;i++)
	for(j=0;j<=39;j++)
      matriz[i][j]=0;
}

////////////////////////////////////////////////////////////////////////////////

void creamatriz(int datos[30][40])
{
int i,j;
file *fichero;

fichero = fopen("libres.mae","rb");

if(!fichero)
	{
   clrscr();
	printf("\n\n\n\n\terror : el fichero \"libres.mae\" no se puede hayar");
	getch();
   exit(1);
   }

for(i=0;i<=29;i++)
 	for(j=0;j<=39;j++)
    	fread(&datos[i][j],sizeof(int),1,fichero);

fclose(fichero);
}

////////////////////////////////////////////////////////////////////////////////

void grabaarchivo(int datos[30][40])
{
int i, j;
file *fichero;

fichero = fopen("libres.mae","wb");

if(fichero==null)
	{
	clrscr();
   printf("\n\n\n\terror al actualizar datos del dia");
   printf("\n\n\n\taplicacion finalizada!!!");
	getch();
   exit(1);
   }
else
	for(i=0;i<=29;i++)
		for(j=0;j<=39;j++)
     		fwrite(&datos[i][j],sizeof(int),1,fichero);

fclose(fichero);
}

////////////////////////////////////////////////////////////////////////////////

void disponible(int datos[30][40], int numdia, int cantloc, int sector, char *cod, int *prim)
{
int ni, nf, j, marca=0;

switch(sector)
	{
   case 1 : ni=0;
            nf=19;
   break;
   case 2 : ni=20;
   			nf=29;
   break;
   case 3 : ni=30;
   			nf=39;
   break;
   }

do
	{
   if(datos[numdia-1][ni]==0)
		{
	   if(ni+cantloc-1<=nf)
   		{
			marca=1;
	      *prim=ni+1;
   	   *cod='s';
	      nf=ni+cantloc-1;
			for(j=ni;j<=nf;j++)
      		datos[numdia-1][j]=1;
	      }
		else
   		{
      	marca=1;
      	*cod='n';
	      }
	   }
	else
	   {
	   if(ni<nf)
			ni++;
	   else
	   	{
	      marca=1;
	      *cod='n';
	      }
	   }
   }
while(marca==0);
}

////////////////////////////////////////////////////////////////////////////////

void linea(char simbolo)
{
int j;
printf("\n");
for(j=0;j<=79;j++)
	printf("%c",simbolo);
}

////////////////////////////////////////////////////////////////////////////////

void error()
{
gotoxy(1,wherey()-2);
clreol();
beep(2000, 100);
}

////////////////////////////////////////////////////////////////////////////////

void inicio(void)
{
int x1, x2;
char texto1[]="teatro municipal de la matanza";
char texto2[]="sistema de control de venta de localidades";

for(x1=1,x2=80;x1<=80;x1++,x2--)
   {
   gotoxy(x1,10);
	printf("/");
   gotoxy(x2,11);
	printf("\\");
   beep(1500, 10);
   sleep(5);
   }

printf("\n\n\t");
for(x1=0;x1<sizeof(texto1);x1++)
	{
	printf("%c",texto1[x1]);
   beep(1800, 10);
   sleep(50);
   }

printf("\n\n\t\t\t");
for(x1=0;x1<sizeof(texto2);x1++)
	{
	printf("%c",texto2[x1]);
   beep(1800, 10);
   sleep(50);
   }
printf("\n");
for(x1=1,x2=80;x1<=80;x1++,x2--)
   {
   gotoxy(x1,17);
	printf("\\");
   gotoxy(x2,18);
	printf("/");
   beep(1500, 10);
   sleep(5);
   }
sleep(2500);
}
