#include <stdio.h>
#include <conio.h>

main ()
{
int cont=0,x,y,suma;
printf ("Dame el n£mero de elementos que deseas: ");
scanf ("%d",&x);
	do
	{
	y=cont;
	suma=cont+y;
	printf ("%d ",suma);
	}
	while (cont++ <= x);
}




#include <stdio.h>
void main()
{
  int n,a,b,c,aux;
  do{                   // Se lle el número hasta que sea mayor que cero.
      printf("\nDame un numero :");
      scanf("%d",&n);
  } while(n<=0);
  a=1;b=0;
  for(c=1;c<=n;c++)
  {
    printf("%d\t",a);
    aux=a;
    a+=b;
    b=aux;
  }
}

