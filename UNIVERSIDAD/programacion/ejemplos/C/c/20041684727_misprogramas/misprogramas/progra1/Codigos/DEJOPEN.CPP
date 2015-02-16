#include<stdio.h>
#include<conio.h>
void main()
	      {
	       clrscr();
	       int a,b,c;
	       printf("\Dame un numero");
	       scanf("%d",&a);
	       printf("\Dame un segundo numero");
	       scanf("%d",&b);
	       printf("\Dame el ultimo numero");
	       scanf("%d",&c);
	       if(a>b && a>c && b>c)
	       printf("A es mayor y C el menor");
	       if(a>b && a>c && b<c)
	       printf("A es mayor y B el menor");
	       if(b>a && b>c && a<c)
	       printf("B es mayor y A el menor");
	       if(b>a && b>c && a>c)
	       printf("B es mayor y C el menor");
	       if(c>a && c>b && a<b)
	       printf("C es mayor y A el menor");
	       if(c>a && c>b && a>b)
	       printf("C es mayor y B el menor");
	       if(a==b && b==c)
	       printf("A,B y C son la misma mamada");
	       if(a==b && c>a)
	       printf("A y B son iguales y C es mayor");
	       if(a==b && c<a)
	       printf("A y B son iguales y C es menor");
	       if(b==c && a>b)
	       printf("B y C son iguales y A es mayor");
	       if(b==c && a<b)
	       printf("B y C son iguales y A es menor");
	       if(a==c && a<b)
	       printf("A y C son iguales y B es mayor");
	       if(a==c && a>b)
	       printf("A y C son iguales y B es menor");
	       getch();
	       }