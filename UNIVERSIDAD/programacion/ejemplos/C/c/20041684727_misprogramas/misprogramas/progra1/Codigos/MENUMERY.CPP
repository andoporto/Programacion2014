#include<stdio.h>
#include<conio.h>

void main()
{
char opc;
int aux;
clrscr();
textcolor(15);
aux=1;
do
{
	if (kbhit())
	{
	opc=getch();


	switch(aux)
	{
	case 1:
			gotoxy(20,3);
			printf("M E N U    P R I N C I P A L " );
			textcolor(4);
			gotoxy(20,6);
			cprintf("A L T A S");
			textcolor(15);
			gotoxy(20,9);
			cprintf("B A J A S ");
			gotoxy(20,12);
			cprintf("C O N S U L T A S");
			gotoxy(20,15);
			cprintf("S A L I R");
			if(opc==80)
				aux=2;
			else
			if(opc==72)
				aux=4;
			break;
	case 2:  clrscr();
			gotoxy(20,3);
			printf("M E N U    P R I N C I P A L " );
			textcolor(15);
			gotoxy(20,6);
			cprintf("A L T A S");
			textcolor(4);
			gotoxy(20,9);
			cprintf("B A J A S ");
			textcolor(15);
			gotoxy(20,12);
			cprintf("C O N S U L T A S");
			gotoxy(20,15);
			cprintf("S A L I R");
			if(opc==80)
				aux=3;
			else
			  if(opc==72)
			   aux=1;
			break;
	case 3:   	clrscr();
				gotoxy(20,3);

				printf("M E N U    P R I N C I P A L " );
				textcolor(15);
				gotoxy(20,6);
				cprintf("A L T A S");
				gotoxy(20,9);
				cprintf("B A J A S ");
				textcolor(4);
				gotoxy(20,12);
				cprintf("C O N S U L T A S");
				textcolor(15);
				gotoxy(20,15);
				cprintf("S A L I R");

				if(opc==80)
					aux=4;
				else
				 if(opc==72)
					aux=2;
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
						textcolor(4);
						gotoxy(20,15);
						cprintf("S A L I R");

						if(opc==72)
						aux=3;
						else
						if(opc==80)
						aux=1;
						break;

}
}
}while(opc!=27);
}