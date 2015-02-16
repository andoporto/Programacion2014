#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
clrscr();
int x=0,y=0,exp=0,s;
long int num=0,val=0,bdiez=1,numb=0,dec=0,bin=0,oct=0;
gotoxy(8,1);
printf("Programa que convierte un n£mero de un sistema num‚rico a otro.\n\n");
printf("\tNumero a introducir.\t\tSistema a transformar.\n");
printf("\t1.- Decimal.\t\t\t1.- Decimal\n");
printf("\t2.- Binario.\t\t\t2.- Binario\n");
printf("\t3.- Octal.  \t\t\t3.- Octal.\n\n");
printf("Seleccione el sistema del numero que introducir : ");
scanf("%d",&x);
printf("A que sistema desea transformar el n£mero: ");
scanf("%d",&y);
if(x==1&&y==2)
  {
     printf("Opcion seleccionada >Decimal a binario<\nTeclee el n£mero en decimal ");
     scanf("%ld",&num);
     while (num>0)
     {
	val=num%2;
	num=num/2;
	numb+=val*bdiez;
	bdiez=bdiez*10;
     }
   printf("El n£mero convertido a binario es :%ld",numb);
  }
if(x==1&&y==3)
  {
      printf("Opcion seleccionada >Decimal a octal<\nTeclee el n£mero en decimal ");
      scanf("%ld",&num);
      while (num>0)
      {
	val=num%8;
	num=num/8;
	numb+=val*bdiez;
	bdiez=bdiez*10;
      }
   printf("El n£mero convertido a octal es :%d",numb);
  }
if(x==2&&y==1)
   {
      printf("Opci¢n seleccionada >Binario a decimal<\nTeclee el n£mero en binario" );
      scanf("%ld",&num);
      bdiez=0;
      while(num>0)
      {
	val=num%10;
	num=num/10;
	bdiez+=val*pow(2,exp);
	exp++;
      }

    printf("El numero convertido a decimal es :%d",bdiez);
   }
if(x==2&&y==3)
  {
      printf("Opci¢n seleccionada >Binario a octal<\nTeclee el n£mero en binario " );
      scanf("%ld",&bin);
    for(dec=0;bin>0;bin=bin/10)
    {
     oct=bin%10;
     dec=(oct*(pow(2,exp)))+dec;
     exp++;
    }
    oct=0;
    for(exp=0;dec>0;exp++)
    {
     bin=dec%8;
     dec=dec/8;
     oct=(bin*(pow(10,exp)))+oct;
    }
    printf("El n£mero convertido a octal es: %ld",oct);
  }
if(x==3&&y==1)
   { s=0;
     printf("Opci¢n seleccionada >Octal a Decimal<\nTeclee numero en octal ");
     scanf("%ld",&num);
     while(num>0)
     {
     y=num%10;
     num=num/10;
     numb+=y*pow(8,s);
     s++;
     }
    printf("El numero convertido a decimal es: %ld\n",numb);
   }
if(x==3&&y==2)
    {	printf("Opcion seleccionada >Octal a Binario<\nTeclee numero en octal ");
	scanf("%ld",&oct);
	for(dec=0;oct>0;oct=oct/10)
	   {
	      bin=oct%10;
	      dec=(bin*(pow(8,exp)))+dec;
	      exp++;
	   }
	bin=0;
	for(exp=0;dec>0;exp++)
	   {
	      oct=dec%2;
	      dec=dec/2;
	      bin=(oct*(pow(10,exp)))+bin;
	   }
    printf("El n£mero convertido a binario es: %ld",bin);
  }
if((x==1&&y==1)||(x==2&&y==2)||(x==3&&y==3))
printf("Opcion sin sentido no convertir s nada");
getch();
}