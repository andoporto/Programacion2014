#include<stdio.h>
#include<conio.h>
void main()
	   {
	    int i,suma=0;
	    clrscr();
	    for (i=3;i<=99;i=i+3)
		{
		 printf("%d ", i);
		 suma=suma+i;
		 //i=i+3;
		}
	    printf("\n suma=%d", suma);
	    getch();
	   }