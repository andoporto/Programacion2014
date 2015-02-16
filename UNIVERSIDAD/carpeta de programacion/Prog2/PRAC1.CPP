#include <stdio.h>
#include <conio.h>

int leedato(int,int);

void main()
{
  int nven,nart,numeven,numeart;
  clrscr();
  
  printf("\n Ingrese N de vendedor: ");
  scanf("%d",&nven);
  numeven=leedato(1,8);
  while (numeven<0)
	{
	  printf("\n Ingrese N de articulo: ");
      scanf("%d",&nart);
	  numeart=leedato(1,10);
	  getch();
	}
}
 
int leedato(int x,int y)
{
 int p;
 	do
	{
	  if (p<x||p>y)
	  {
	   printf("Nota no v lida") ;
	   getch();
	   delline();
	   printf("\r");
	  }
	} while(p<x||p>y);
return(p);
}
	