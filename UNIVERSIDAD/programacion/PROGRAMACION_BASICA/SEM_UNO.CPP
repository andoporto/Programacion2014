
#include <stdio.h>
#include <conio.h>

void main()
{
 int N,S,U,X,P;
 clrscr ();
 N=1;S=0;U=-1;

 while (N<15)
 {
	printf("\n Ingrese un valor: ");
	scanf ("%d",&X);

	if (X<0)
		 S=S+X;
	else
	{
	  U=U+1;
	  if (U==0)
	  {
		M=X;
	    P=N;
	  }
	  else
	  { if (X>M)
	 	   {
			M=X;
	    	P=N;
           }

        }
    }
	N=N+1;

 printf("\n Ubicacion del mayor valor de los positivos: %d la suma de los negativos es: %d el mayor de los positivos es: %d cantidad de positivos: %d",P,S,M,U);

	getch();
}

