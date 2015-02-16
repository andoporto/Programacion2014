 #include<stdio.h>
 #include<conio.h>
 void main()
	    {
	     int i,n,suma=0;
	     clrscr();
	     printf("dame el numero  a calcular: ");
	     scanf("%d", &n);
	     for (i=n;i>=1;i=i-1)
		  suma=suma+i;
	     printf("%d",suma);
	     getch();
	    }