#include<stdio.h>
#include<conio.h>
void cambiar(int*a,int*b);
void ordenar(int *a, int *b, int *c);
void main()
{
  int a,b,c;
  clrscr();
  printf("Introduce valor de a:    ");scanf("%d",&a);
  printf("Introduce el valor de b:   ");scanf("%d",&b);
  printf("Introduce el valor de c:   ");scanf("%d",&c);
  ordenar(&a,&b,&c);
  printf("Valor 1 %d\n",a);
  printf("Valor 2 %d\n",b);
  printf("Valor 3 %d\n",c);
  getch();
}
void ordenar(int *a,int *b,int *c)
{
	if(*a>*b)
		cambiar(&*a,&*b);
	if(*a>*c)
		cambiar(&*a,&*c);
	if(*b>*c)
		cambiar(&*b,&*c);

}
void cambiar(int*a,int*b)
	{
		int aux;
		aux=*a;
		*a=*b;
		*b=aux;

	}
