/*Programa que ordena 5 numero del menor al mayor
Diana Ivonne Aceves Ruelas
18 de abril del 2004*/
#include<stdio.h>
#include<conio.h>
void main()
{
clrscr();
int arr[5],i,j,aux,a;
for(a=0;a<5;a++)
{
	printf("Introduce un numero: ");
	scanf("%d",&arr[a]);
}
for(j=0;j<5;j++)
{
	for(a=0;a<5;a++)
	{
		if(arr[0]>arr[a+1])
		{
			aux=arr[a];
			arr[a]=arr[a+1];
			arr[a+1]=aux;
		}
	}
}
for(i=1;i<6;i++)
		printf("%d\n",arr[i]);
getch();

}

