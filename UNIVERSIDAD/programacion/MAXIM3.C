
 #include <stdio.h>
 #include <stdlib.h>
 #include <conio.h>
     void main()
   {
	clrscr ();
	float a,b,c,max;
	char ub;


	printf("Ingrese 3 valores separados por un espacio: ");
	scanf ("%f%f%f",&a,&b,&c);

	if (a>b) {max=a; ub='p';}
		else   {max=b; ub='s';}

	if (c>max) {max=c; ub='t';}

	printf ("El mayor vale %5.2f y es el %2c",max, ub);
	getch();
	 }
