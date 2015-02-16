/*
LOS CODIGOS SON NUMEROS ENTEROS
LOS NOMBRES DE LOS PRODUCTOS PERMITEN MAXIMO 20 LETRAS
LOS PRECIOS SON NUMEROS CON COMA FLOTANTE
AL HACER LA VENTA SE DEBEN DAR CODIGOS VALIDOS O SEA YA CAPTURADOS EN LA BASE DE DATOS
*/
#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#define max_prod 20		//SI SE QUIEREN CAMBIAR LA CANTIDAD DE PRODUCTOS A GUARDAR SE MODIFICA LA CANTIDAD AQUI
#define CAPTURA 5       //SI SE QUIERE CAMBIAR LA CANTIDAD DE PRODUCTOS A VENDER SE MODIFICA LA CANTIDAD AQUI
main ()
{

int cant;
int codigo[max_prod];			//21 codigos contando el 0
char producto[max_prod][20];	//21 productos de maximo 20 letras del producto
float precio[max_prod];		//21 PRECIOS MAXIMO


clrscr();

printf("		CAPTURA DE LA BASE DE DATOS \n");
printf("\nSOLO SE PERMITEN MAXIMO 20 PRODUCTOS\n");
printf("CUANTOS PRODUCTOS DESEAS CAPTURAR? ");
scanf("%d",&cant);

//capturo los productos con su c¢digo
for (int cont=1;cont<=cant;cont++)
	{
		printf("\n");
		printf("DAME EL %dø PRODUCTO ",cont);	scanf("%s",&producto[cont]);
		printf("DAME SU CODIGO ");			scanf("%d",&codigo[cont]);
		printf("DAME SU PRECIO UNITARIO ");		scanf("%f",&precio[cont]);
	}

getch();

int codigo2,num;
float total=0;

textbackground(1);
clrscr();

textcolor(2);
gotoxy(24,1);cprintf("TIENDA DE AUTOSERVICIO EL COCHINITO VELOZ ");
gotoxy(3,2);cprintf("CODIGO");
gotoxy(20,2);cprintf("PRODUCTO");
gotoxy(35,2);cprintf("PRECIO");
gotoxy(58,2);cprintf("CANTIDAD");
gotoxy(72,2);cprintf(" TOTAL");

	for(cont=1;cont<=CAPTURA;cont++)		//numero de VENTAS= 3
		{

			gotoxy(1,cont+3);	scanf("%d",&codigo2);
			for (int i=1;i<=cant;i++)
				{
					if(codigo2==codigo[i])
						{
						gotoxy(10,cont+3);	printf("%s",producto[i]);
						gotoxy(35,cont+3);	printf("%f",precio[i]);
						gotoxy(61,cont+3);	scanf("%d",&num);
						gotoxy(70,cont+3);	printf("%f",num*precio[i]);
						total=num*precio[i]+total;
						}
				}

		}

gotoxy(20,24);textcolor(0+128); cprintf("TOTAL DE LA VENTA = %f",total);
getch();
return(0);
}