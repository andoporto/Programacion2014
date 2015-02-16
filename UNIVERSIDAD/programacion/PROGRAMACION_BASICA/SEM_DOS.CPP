
#include <stdio.h>
#include <conio.h>

void main()
{
 int N,S,C,X,m,U;
 clrscr ();
 N=C=0;P=1;

 printf("\n Ingrese un valor (cero paar cerrar): ");
 scanf ("%d",&X);

 while (X!=0)
 {

	if (X<10)
		 P=P+X;
	else
	{
	  C=C+1;
	  if (C==1)
	  {
		m=X;
	    U=N;
	  }
	  else
	  { if (X<m)
	 	   {
			m=X;
	    	U=N;
           }

        }
    }
    printf("\n Ingrese un valor (cero paar cerrar): ");
    scanf ("%d",&X);

	N=N+1;

 printf("\n \n Numero de valores: %d producto de valores menores a 10: %d cantidad de valores mayores a 10: %d cubicacion del menor de los mayores a 10: %d",N,P,C,m,U);

	getch();
}

