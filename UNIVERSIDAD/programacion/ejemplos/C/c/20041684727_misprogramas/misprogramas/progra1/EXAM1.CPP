#include<stdio.h>
#include<conio.h>
void main()
	  {
	   int n,i,x,y,z,aux;
	   clrscr();
	   printf("Hasta que posicion");
	   scanf("%d",&i);
	   if(i==1)
	     printf("1");
	   if(i==2)
	     printf("1,2");
	   if (i==3)
	      printf("1,2,3");
	   if(i>3)
	      {
	       x=1;
	       y=2;
	       z=3;
	       printf("1,2,3,");
	       for(n=0;n<=i-4;n++)
		  {
		   aux=x+y+z;
		   printf("%d,",aux);
		   x=y;
		   y=z;
		   z=aux;
		   }
		  }
	   getch();
	  }
