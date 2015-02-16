/*Programa que compara 3
numeros y detecte si alguno es la suma de los otros 2*/
#include<stdio.h>
#include<conio.h>
void main()
		   {
			int a,b,c;
			clrscr();
			printf("Este programa lee 3 numeros y compara si la suma ");
			printf("de alguno de los dos es igual  al tercero\n");
			printf("Dame el numero A: \n");
			scanf("%d",&a);
			printf("Dame el numero B: \n");
			scanf("%d",&b);
			printf("Dame el numero C: \n");
			scanf("%d",&c);
			if((a+b)==c)
			  printf("A+B=C");
			if((a+c)==b)
			  printf("A+C=B");
			if((b+c)==a)
			  printf("B+C=A");
			if(((a+b)!=c)&&((a+c)!=b)&&((b+c)!=a))
			  printf("Ninguna suma coinside");
			getch();
		   }