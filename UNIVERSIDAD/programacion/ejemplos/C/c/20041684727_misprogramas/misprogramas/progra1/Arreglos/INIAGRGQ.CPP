#include<stdio.h>
#include<conio.h>
void main()
{
clrscr();
int a[10],i,totale,opc;
for(i=0;i<10;i++)
{
	totale=0;
	a[i]=0;
}
for(;;)
{
clrscr();
gotoxy(25,10);printf("1. Inicializar");
gotoxy(25,11);printf("2. Agregar");
gotoxy(25,12);printf("3. Eliminar");
gotoxy(25,13);printf("4. Visualizar");
gotoxy(25,14);printf("5. Salir");
gotoxy(23,17);printf("Introduce una opcion:");
scanf("%d",&opc);
	switch(opc)
	{
		case 1:
//				clrscr();
				for(i=0;i<10;i++)
				{
					a[i]=0;
					totale=0;
				}
		break;
		case 2:
				clrscr();
				if(totale<10)
				{
					printf("Qu‚ valor desea agregar?: ");scanf("%d",&a[totale]);
 //					a[totale]=num;
					totale++;
				}
				else
					printf("No hay espacio para ningun valor!!!");
		break;
		case 3:
				clrscr();
				if(totale>0)
				{
					printf("Esta opcion elimina el ultimo valor");
					i=totale-1;
					a[i]=0;
					totale--;
				}
				else
					printf("No hay ningun valor para eliminar");
		break;
		case 4:
				clrscr();
				for(i=0;i<10;i++)
				{
					gotoxy(10,7);printf("Esta opcion visualiza los valores que se encuentran en el arreglo");
					gotoxy(20,9+i);printf("%d",a[i]);
				}
				getch();
		break;
		case 5:break;
		default:
				clrscr();
				gotoxy(25,12);printf("Introduce una opcion valida!!!");
	}
 //	getch();
	if(opc==5)
		break;
}
}

