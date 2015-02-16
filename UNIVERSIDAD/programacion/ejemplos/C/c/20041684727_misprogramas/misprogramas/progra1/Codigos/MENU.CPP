#include<stdio.h>
#include<conio.h>

void main()
{
char tecla;
int cont;
clrscr();
textcolor(15);
fflush(stdin);
cont=1;
do
{
	if (kbhit())
	{
	tecla=getch();


	switch(cont)
	{
	case 1:
			gotoxy(20,3);
			printf("M E N U    P R I N C I P A L " );
			textcolor(2);
			gotoxy(20,6);
			cprintf("A L T A S");
			textcolor(15);
			gotoxy(20,9);
			cprintf("B A J A S ");
			gotoxy(20,12);
			cprintf("C O N S U L T A S");
			gotoxy(20,15);
			cprintf("S A L I R");
			if(tecla==80)
				cont=2;
			break;
	case 2:  clrscr();
			gotoxy(20,3);
			printf("M E N U    P R I N C I P A L " );
			textcolor(15);
			gotoxy(20,6);
			cprintf("A L T A S");
			textcolor(2);
			gotoxy(20,9);
			cprintf("B A J A S ");
			textcolor(15);
			gotoxy(20,12);
			cprintf("C O N S U L T A S");
			gotoxy(20,15);
			cprintf("S A L I R");
			if(tecla==80)
				cont=3;
			else
			  if(tecla==72)
			   cont=1;
			break;
	case 3:   	clrscr();
				gotoxy(20,3);

				printf("M E N U    P R I N C I P A L " );
				textcolor(15);
				gotoxy(20,6);
				cprintf("A L T A S");
				gotoxy(20,9);
				cprintf("B A J A S ");
				textcolor(2);
				gotoxy(20,12);
				cprintf("C O N S U L T A S");
				textcolor(15);
				gotoxy(20,15);
				cprintf("S A L I R");

				if(tecla==80)
					cont=4;
				else
				 if(tecla==72)
					cont=2;
				break;
	case 4:    			clrscr();
						gotoxy(20,3);
						textcolor(15);
						printf("M E N U    P R I N C I P A L " );
						textcolor(15);
						gotoxy(20,6);
						cprintf("A L T A S");
						gotoxy(20,9);
						cprintf("B A J A S ");
						gotoxy(20,12);
						cprintf("C O N S U L T A S");
						textcolor(2);
						gotoxy(20,15);
						cprintf("S A L I R");

						if(tecla==72)
						cont=3;
						break;

}
}
}while(tecla!=27);
}