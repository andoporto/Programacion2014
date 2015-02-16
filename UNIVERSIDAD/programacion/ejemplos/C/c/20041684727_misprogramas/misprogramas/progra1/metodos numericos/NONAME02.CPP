//arreglodeapuntadores
#include<stdio.h>
#include<conio.h>
void main()
		 {
		  int x,y,z,*p[3],i;
		  clrscr();
		  p[0]=&x;
		  p[1]=&y;
		  p[2]=&z;
		  printf("variable x= %d,variable y=%d, variable z=%d", x,y,z);
		  for (i=0;i<=3;i++)
			   *p[i]=(i+1)*10;
		  x=*p[0];
		  y=*p[1];
		  z=*p[2];
		  printf("variable x= %d,variable y=%d, variable z=%d", x,y,z);
		  getch();
		  }