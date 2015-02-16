#include<stdio.h>
#include<conio.h>
void main()
{
	clrscr();
	int A[50],B[50],a[50],b[50],i,eA=0,eB,j=8,k,ban,cer,si=0,cont=0,d,contrans=0,con;
	gotoxy(10,10);printf("Cuantos elementos del conjunto A va a introducir?: ");
	scanf("%d",&eA);clrscr();
//	gotoxy(10,12);printf("Cuantos elementos del conjunto B va a introducir?: ");
//	scanf("%d",&eB);clrscr();
	eB=eA;
	gotoxy(7,5);printf("A={ ");
	for(i=0;i<eA;i++)
	{
		gotoxy(j+2,5);scanf("%d",&A[i]);gotoxy(j+3,5);printf(",");j+=3;
	}
	printf("}");
	for(i=0;i<eA;i++)
		B[i]=A[i];
//	clrscr();
//	gotoxy(7,7);printf("B={ ");j=8;
//	for(i=0;i<eB;i++)
//	{
//		gotoxy(j+3,7);scanf("%d",&B[i]);gotoxy(j+5,7);printf(",");j+=4;
//	}
//	printf("}");
	gotoxy(7,10);printf("Cuantos elementos va a tener la relacion?: ");scanf("%d",&cer);gotoxy(7,10);clreol();
	gotoxy(1,10);printf("R={");j=4;
	for(k=0;k<cer;k++)
	{
		gotoxy(j,10);printf("(");scanf("%d",&a[k]);
		y:
		for(i=0;i<eA;i++)
		{
			if(a[k]==A[i]){
				ban=0;break;}
			else
				ban=1;
		 }

		 if(ban==1)
			{
				gotoxy(5,12);printf("Ese elemento no lo puedes poner no esta en el dominio!!!");getch();
				gotoxy(5,12);clreol();gotoxy(j+1,10);clreol();scanf("%d",&a[k]);goto y;
			}
		gotoxy(j+2,10);printf(",");
		scanf("%d",&b[k]);
		ya:
		for(i=0;i<eB;i++)
		{
			if(b[k]==B[i]){
				ban=0;break; }
			else
				ban=1;
		}
		if(ban==1)
		{
			gotoxy(5,12);printf("Ese elemento no lo puedes poner no esta en el codominio!!!");getch();
			gotoxy(5,12);clreol();gotoxy(j+5,10);clreol();scanf("%d",&b[k]);goto ya;
		}
		gotoxy(j+4,10);printf("),");j+=6;

	}
		for(i=0;i<cer;i++)
			for(d=i+1;d<(cer-1);d++)
				if(a[i]==a[d] && b[i]==b[d])
				{
				gotoxy(5,11);printf("Ese par ya esta en la relacion!!!");getch();
				gotoxy(5,11);clreol();gotoxy(j-5,10);clreol();scanf("%d",&a[k]);j-=5;goto y;

				}

	printf("}\n\n");

		for(i=0;i<cer;i++)
			for(d=0;d<cer;d++)
			{
				if(b[i]==b[d])
					 contrans+=1;
			}
int conreflexiva=0;
cont=0;
for(k=0;k<eA;k++)
{
	for(i=0;i<cer;i++)
		if((A[k]==a[i])&&(B[k]==b[i]))
			conreflexiva+=1;
}
if(conreflexiva==eA)
	printf("\nEs reflexiva");
else
	printf("\nNo es reflexiva");
if(conreflexiva==0)
	printf("\nEs irreflexiva");
else
	printf("\nNo es irreflexiva");

for(k=0;k<cer;k++)
{
	for(i=0;i<cer;i++)
		if((a[k]==b[i])&&(b[k]==a[i]))
			cont+=1;
}
if(cont==0)
	printf("\nEs antisimetrica");
if(cont==cer)
	printf("\nEs simetrica");
if(cont==0 && conreflexiva==0)
	printf("\nEs asimetrica");

for(k=0;k<cer;k++)       //el numero de elementos de la relacion debe ser 2eA
	for(i=0;i<cer;i++)
		for(j=0;j<cer;j++)
			//if(a[k]==a[j]&&b[k]==a[i]&&b[i]==b[j])//&&k!=i&&k!=j&&i!=j)
					if(a[k]==a[j]&&b[k]==a[i]&&b[i]==b[j])
						si++;
				//si++;
con=contrans;
if(si==con)
	printf("\nEs transitiva");
else
	printf("\nNo es transitiva");
getch();
if(conreflexiva==eA&&cont==cer&&si==con)
{
clrscr();gotoxy(25,12);printf("ES UNA RELACION EQUIVALENTE");
}

getch();
}