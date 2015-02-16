#include <stdio.h>
#include <stdlib.h>

int main()
{
 int i,p2,p1;
 float v,may1,may2;
 system("cls");
 for (i=0;i<7;i++)
 {
  printf("\n Ingrese un valor: ");
  scanf ("%f",&v);

	  if (i==0)
	  {
	    may1=v;
	    p1=i;
	  }
	  else
	  {
	    if (v>may1)
	    {
		 may2=may1;
		 p2=p1;
		 may1=v;
		 p1=i;
	    }
	    else
	    {
	      if (i==1)
	      {
	       may2=v;
	       p2=i;
	      }
	      else
	      {
	       if (v>may2)
	       {
		    may2=v;
		    p2=i;
	       }
	      }
	    }
	  }
 }
	printf("\n Primer mayor: %.2f posicion: %d  segundo  mayor: %.2f posicion: %d ",may1,p1+1,may2,p2+1);

}
