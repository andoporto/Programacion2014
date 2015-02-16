
#include<stdio.h>
#include<conio.h>

void main()
{
clrscr();
int x,y,n,m[8][8],i,a,b,mx,my,sim,ant,t,ref,irr,asi,s,trans;
for(a=0;a<8;a++)
   {
	for(b=0;b<8;b++)
	m[a][b]=0;
   }
x=0;
y=0;

printf("\n\n\n\t'Programa qu muestra las porpiedades de una matriz\n\n\t   de acuerdo a una relacion de pares ordenados'");
printf("\n\n\tCual es el tama¤o de la matriz: ");scanf("%d",&t);
printf("\nCuantos pares ordenados son: ");scanf("%d",&n);
printf("\nDame los pares ordenados:\n");
for(s=0;s<n;s++)
		{
		printf("Dame el primer numero del par %d :",s+1);scanf("%d",&x);
		printf("Dame el segundo numero del par %d :",s+1);scanf("%d",&y);
		m[x-1][y-1]=1;
		}
printf("n\n\Presione una tecla para continuar.......");


clrscr();


for(mx=0;mx<t;mx++)
   {
	printf("\n");
	for(my=0;my<t;my++)
	printf("%d ",m[mx][my]);
   }
for(int w=0;w<t;w++)
	for(int z=0;z<t;z++)
		{
		if(m[w][z]==m[z][w])
		  sim=1;
		else
			{
			sim=0;
			w=z=t;
			}
		}
if(sim==1)
printf("\n\n-Simetrica");
else
printf("\n\n-No Simetrica");

for(int c=0;c<t;c++)
	for(int d=0;d<t;d++)
		{
		if(m[c][d]==m[d][c])
		  {
		  if(c==d)
			ant=1;
		  else
			{
			ant=0;
			c=d=t;
			}
		   }
		else
		ant=1;

}
if(ant==1)
printf("\n\n-Antisimetrica");
else
printf("\n\n-No Antisimetrica");

for(int h=0;h<t;h++)
	for(int g=0;g<t;g++)
		if(h==g)
			{
			if(m[h][g]==1)
				ref=1;
			else
				h=g=t;
			}
		else
			ref=0;
if(ref==1)
printf("\n\n-Reflexiva");
else
printf("\n\n-No Reflexiva");


for(int l=0;l<t;l++)
	for(int u=0;u<t;u++)
		if(l==u)
			{
			if(m[l][u]==0)
				irr=1;
			else
				l=u=t;
			}
		else
			irr=0;
if(irr==1)
printf("\n\n-Irreflexiva");
else
printf("\n\n-No Irreflexiva");

if(irr==1)
for(int r=0;r<t;r++)
	for(int e=0;e<t;e++)
		{
		if(m[r][e]==m[e][r])
		  {
			if(r==e)
				{
				if(r==0)
				asi=1;
				else
				asi=0;
				r=e=t;
				}
			else
			{
			asi=0;
			r=e=t;
			}
		  }
		else
		asi=1;
	  }
if(asi==1)
printf("\n\n-Asimetrica");
else
printf("\n\n-No Asimetrica");

trans=1;
for(int j=0;j<t;j++)
	{
	for(i=0;i<t;i++)
	if(m[j][i]==1)
	   {
	   for(int k=0;k<t;k++)
			if(m[i][k]==1)
				if(m[j][k]!=0)
				trans=0;
	   }

	}

if(trans==1)
printf("\n\n-Transitiva");
else
printf("\n\n-No Transitiva");

if(sim==1&&trans==1&&ref==1)
	printf("\n\n-Equivalente");

printf("\n\n\n\n\t\tPrograma realizado por:");
printf("\n\n\n\n\t\tFernando S nchez Galindo");
printf("\n\n\t\t          y");
printf("\n\n\t\tJorge Antonio Pe¤aloza Hinostrosa");
getch();
}