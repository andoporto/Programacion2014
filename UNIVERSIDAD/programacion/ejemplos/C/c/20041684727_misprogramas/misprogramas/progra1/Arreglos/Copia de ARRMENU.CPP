#include<stdio.h>
#include<conio.h>
void main()
{
clrscr();
float a[10],b[10],c[10];
int i,opc;
for(i=0;i<10;i++)
{
	gotoxy(15,7);printf("Dame un numero para el arreglo a, posicion: %d : ",i+1);
	scanf("%f",&a[i]);
	gotoxy(15,9);printf("Dame un numero para el arreglo b, posicion: %d : ",i+1);
	scanf("%f",&b[i]);
	gotoxy(63,7);clreol();	gotoxy(63,9);clreol();
}
clrscr();
gotoxy(27,11);printf("1. Suma");
gotoxy(27,12);printf("2. Resta");
gotoxy(27,13);printf("3. Multiplicaci¢n");
gotoxy(27,14);printf("4. Divisi¢n");
gotoxy(25,7);printf("Selecciona una opcion: ");
scanf("%d",&opc);
clrscr();
switch(opc)
{
	case 1: for(i=0;i<10;i++)
					{
						c[i]=a[i]+b[i];
						gotoxy(27,7+i);printf("%.2f + %.2f = %.2f",a[i],b[i],c[i]);
					}
						break;
	case 2: for(i=0;i<10;i++)
					{
						c[i]=a[i]-b[i];
						gotoxy(27,7+i);printf("%.2f - %.2f = %.2f",a[i],b[i],c[i]);
					}
						break;
	case 3: for(i=0;i<10;i++)
					{
						c[i]=a[i]*b[i];
						gotoxy(27,7+i);printf("%.2f * %.2f = %.2f",a[i],b[i],c[i]);
					}
						break;
	case 4: for(i=0;i<10;i++)
					{
						c[i]=a[i]/b[i];
						gotoxy(27,7+i);printf("%.2f / %.2f = %.2f",a[i],b[i],c[i]);
					}
						break;
	default:printf("Seleccione una opci¢n del menu!!!");
}
getch();
}

