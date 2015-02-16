#include <stdio.h>
#include<conio.h>
void main()
		  {
		   clrscr();
		   char tecla;
		   unsigned long a;
		   int n,b,c,aux;
		   do
			 {
			  do
				{           // Recopilacion de los datos
				 printf("Hasta que numero deseas calcular? ");
				 scanf("%d",&n);
				 if (n<0)   // Validacion de datos de entrada
					{
					 printf("Debe ser un numero mayor de o para poder ");
					 printf("realizar el calculo, trata de nuevo\n");
					}
				} while(n<=0);
				a=1;b=0;      //Asignacion de valores
				for(c=1;c<=n;c++)  //proceso de generacion de la serie
				   {
					printf("%ld,",a);
					aux=a;
					a+=b;
					b=aux;
				   }
			  printf("\nDeseas realizar otro calculo? S/N\n");
			  tecla=getch();
			 }while(tecla!=110);
		   getch();
		  }