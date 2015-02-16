#include<stdio.h>
#include<conio.h>
void main()
{
char a[50],b[50];
int ban, x,y,i;
clrscr();
gotoxy(10,2);printf("Introduce una cadena \n");
gets(a);
gotoxy(10,5);printf("Introduce texto \n");
gets(b);
x=0;
while(a[x])
x++;
y=0;
while(b[y])
 y++;
if(x==y)
  ban=1;
for(i=0;i<=x &&ban;i++)
  if(a[i]!=b[i])
	ban=0;
if(ban)
printf("Son igualitos");
else
printf("Son diferentitos");
getch();
}