#include<stdio.h>
#include<conio.h>

void mensaje();
void main()
{
 clrscr();
 mensaje();
 getch();
}

void mensaje()
		   {
		   gotoxy(35,15);
			printf("Hola mundo");
		   }
