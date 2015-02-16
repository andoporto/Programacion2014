#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct regi
{
long int nc;
char nom[24];
float sdo;
};

struct mov
{
long int nc;
int mes;
int dia;
int cod;
float im;
};

int buscar(struct regi, int , long int);

void main ()
{
 FILE *st, *movi;
 struct regi rg[2000],*p;
 struct mov mo;
 int sinm[2000], mas5[2000],i=0,t,pos;

 if((st=fopen("saldante.dat","rb"))== NULL)
 {
 printf("error al abrir el archivo");
 exit(0);
 }

 fread (&rg[i],sizeof(struct regi), 1, st);

 while (!feof(st))
	{
   sinm[i]=0;
   mas5[i]=0;
   i++;
   fread(&rg[i],sizeof(struct regi),1,st);
   }

 fclose(st);
 t=i-1;

 if((movi=fopen("movi.dat","rb"))==NULL)
 {
 printf("error al abrir el archivo");
 exit(0);
 }

 fread(&mo,sizeof(struct mov),1,movi);
 p=rg;
 while(!feof(movi))
 {
 pos = buscar(*p , t, mo.nc);
 if(pos>-1)
 	{
   if(mo.cod==1)
   	{
      rg[pos].sdo+=mo.im;
      }
   else
   	{
      rg[pos].sdo-=mo.im;
      mas5[pos]++;
      }
   sinm[pos]=1;
   }
 fread(&mo,sizeof(struct mov),1,movi);
 }

 fclose(movi);

 if((st=fopen("saldante.dat","wb"))== NULL)
 {
 printf("error al abrir el archivo");
 exit(0);
 }

 for(i=0;i<=t;i++)
 	{
   fwrite(&rg[i],sizeof(struct regi),1,st);
   }

 fclose(st);

 for(i=0;i<=t;i++)
 	{
   if(sinm[i]==0)
   	{
      printf("%ld%f",rg[i].nc,rg[i].sdo);
      }
   }

 for(i=0;i<=t;i++)
 	{
   if(mas5[i]>5)
   	{
      printf("%ld",rg[i].nc);
      }
   }
 }

 int buscar(struct regi *x, int y, long int z)
 {
 int s=-1, i=0;

 while(i<=y && s==-1)
	{
   if(z==x[i].nc)
   	{
      s=i;
      }
   i++;
   }
 return(s);
 }















