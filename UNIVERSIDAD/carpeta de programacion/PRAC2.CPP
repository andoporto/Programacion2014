#include <stdio.h>
#include <conio.h>

int leedato(int,int);

void main()
{
  int numeven,numeart;
  clrscr();
  
  printf("\n Ingrese N de vendedor: ");
  numeven=leedato(1,8);
  while (numeven<0)
	{
	  printf("\n Ingrese N de articulo: ");
	  numeart=leedato(1,10);
     printf("\n El articulo es el: %d",numeart); 
	  getch();
	}

}

int leedato(int x,int y)
{
 int da;
 	do
	{
       scanf("%d%",&da);  
	} while(da<x||da>y);
return(da);
}
	