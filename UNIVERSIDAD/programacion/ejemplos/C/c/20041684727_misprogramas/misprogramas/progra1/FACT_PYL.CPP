#include<stdio.h>
#include<conio.h>
void main ()
{
clrscr();
 int n,fact=1;
 textcolor(3);
 gotoxy(15,3);
 printf("PROGRAMA PARA CALCULAR EL FACTOTRIAL DE UN NUMERO");
 gotoxy(1,6);cprintf("hasta que numero");
  scanf("%d",&n);
 for (n=n;n>0;n--){
     fact=fact*n;
     }
     cprintf("factorial es:%d",fact);
     getch();

}

