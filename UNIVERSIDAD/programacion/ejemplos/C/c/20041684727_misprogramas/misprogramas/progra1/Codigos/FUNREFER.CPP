#include<stdio.h>
#include<conio.h>

void leer_datos(int *p);
void  ver_datos(int *p);
void main()
{
int num[10];
 clrscr();
 leer_datos(&num[0]);
  ver_datos(&num[0]);
}


void leer_datos(int *p)
{
 for(int i=0;i<10;i++)
	{
	printf("Numero %d: ",i+1);
	 scanf("%d",p);
	p++;
	}
}

void ver_datos(int *p)
{
 for(int i=0;i<10;i++)
	{
	printf("  Numero %d = %d\n",i+1,*p);
	p++;
	}
}