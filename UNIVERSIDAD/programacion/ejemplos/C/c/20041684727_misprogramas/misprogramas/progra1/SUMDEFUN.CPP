#include<stdio.h>
#include<conio.h>
int sumar (int *n1,int *n2);

 void main ()
		  {
		   int n1,n2,res=0;
		   clrscr();
		   printf("programa que lee 2 numeros y");
		   printf(" los suma por medio de funciones\n");
		   printf("Teclea el primer numero: ");scanf("%d", &n1);
		   printf("Teclea el segundo numero: ");scanf("%d", &n2);
		   res=sumar (&n1,&n2);
		   printf("El resultado es: %d", res);
		   getch();
		  }

//funcion
int sumar(int *a,int *b)
	{
	 int res;
	 return *a+*b;
	}