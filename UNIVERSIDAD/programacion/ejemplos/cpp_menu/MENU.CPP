/*Se puede hacer sin tanto menu solo lo
hago asi para que se vea mejor el programa*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

void cubo()
{
int lado,sn=1;
clrscr();
textbackground(1);
textcolor(15);
do
{
switch(sn)
{
case 1:
clrscr();                       			//limpia pantalla
		textbackground(0);
		textcolor(WHITE);
		cprintf("                                                 Francisco Javier Herrera Vargas");		//nombre programa
		cprintf("El volumen de un cubo                                                           ");


textbackground(BLUE);
textcolor(WHITE);
gotoxy(3,10);cprintf("La dimension del lado es: ");
scanf("%d",&lado);
gotoxy(3,46);cprintf("El volumen de un cubo es: ");
textbackground(1);
textcolor(14);
cprintf("%d",lado*lado*lado);
textbackground(0);
textcolor(15);
gotoxy(1,48);cprintf("                                                                                 ");
gotoxy(1,49);cprintf("Deseas calcular otro volumen Si (1) No (2)                      ");
cprintf("                                                                            Elije una opcion: ");
scanf("%d",&sn);
textbackground(BLUE);
textcolor(WHITE);
break;
case 2:
break;
default:
printf("\n\nSolo 1 o 2: ");
scanf("%d",&sn);
}
}
while(sn!=2);
}

void agenda()
{
int x=0, eleccion=0, opcion=0,numero, opcion2=1;

typedef struct {

char nombre[15];

char telefono[15];} persona;

persona nombres[100];

clrscr();
textbackground(1);
textcolor(15);
do
{
clrscr();
	textbackground(0);
	textcolor(WHITE);
	cprintf("                                                 Francisco Javier Herrera Vargas");		//nombre programa
	cprintf("Agenda telefonica                                                               ");
	gotoxy(3,10);printf("1.- Altas");
	printf("\n\n  2.- Cambios");
	printf("\n\n  3.- Bajas");
	printf("\n\n  4.- Consulta");
	printf("\n\n  5.- Salir");
	printf("\n\n  Elija una opcion: ");
	scanf("%d",&opcion);
	switch(opcion)
	{
case 1:  	//altas
textbackground(1);
textcolor(WHITE);
clrscr();
textbackground(0);
textcolor(WHITE);
cprintf("                                                 Francisco Javier Herrera Vargas");		//nombre programa
cprintf("Agenda telefonica                                                               ");
textbackground(1);
textcolor(15);
gotoxy(3,10);cprintf("Cuantas personas deseas ingresar: ");
	scanf("%d",&numero);
	for(x=0; x < numero; x++)
	{
	gotoxy(3,12+(2*x+1));printf("Introduce el nombre de la persona numero %d: ",x+1);
	scanf("%s", &nombres[x].nombre);
	gotoxy(3,12+(2*x+2));printf("Introduce el telefono de la persona numero %d: ",x+1);
	scanf("%s", &nombres[x].telefono);
	 }
	break;

case 2:		//cambios
	do
	{
	textbackground(1);
	textcolor(WHITE);
	clrscr();
	textbackground(0);
	textcolor(WHITE);
	cprintf("                                                 Francisco Javier Herrera Vargas");		//nombre programa
	cprintf("Agenda telefonica                                                               ");
	textbackground(1);
	textcolor(15);
	gotoxy(3,10);printf("Lista de nombres");
	for(x=0;x<numero;x++)
	{
	gotoxy(3,12+x);printf("%d.- %s ",x+1,nombres[x].nombre);
	}
	gotoxy(3,30);printf("Introduce el numero de la persona que quieres cambiar (cero para salir): ");
	scanf("%d", &eleccion);

	if(eleccion != 0 && eleccion <= numero)
	{
	gotoxy(3,32);printf("Nombre: %s", nombres[eleccion-1].nombre);

	gotoxy(3,34);printf("Telefono: %s", nombres[eleccion-1].telefono);

	gotoxy(3,36);printf("Que quieres cambiar nombre (1) numero (2) cancelar (3): ");
	scanf("%d",&opcion2);
	do
	{
	switch(opcion2)
	{
	case 1:
	gotoxy(3,38);printf("Cambia el nombre numero %d: ",eleccion);
	scanf("%s", &nombres[eleccion-1].nombre);
	opcion2=3;
	break;
	case 2:
	gotoxy(3,38);printf("Cambia el telefono numero %d: ",eleccion);
	scanf("%s", &nombres[eleccion-1].telefono);
	opcion2=3;
	break;

	case 3:
	opcion2=3;
	break;
	default:
	printf("\n\nSolo las opciones disponibles: ");
	scanf("%d",&opcion2);
	}
	}
	while(opcion2!=3);
	}
	}
	while(eleccion!=0);
	break;

case 3:
	textbackground(1);
	textcolor(WHITE);
	clrscr();
	textbackground(0);
	textcolor(WHITE);
	cprintf("                                                 Francisco Javier Herrera Vargas");		//nombre programa
	cprintf("Agenda telefonica                                                               ");
	textbackground(1);
	textcolor(15);
	gotoxy(3,10);printf("Lista de nombres");
	for(x=0;x<numero;x++)
	{
	gotoxy(3,12+x);printf("%d.- %s ",x+1,nombres[x].nombre);
	}
	gotoxy(3,30);printf("Introduce el numero de la persona a dar de baja (cero para salir): ");
	scanf("%d", &eleccion);

	if(eleccion != 0 && eleccion <= numero)
	{
	gotoxy(3,32);printf("Nombre: %s", nombres[eleccion-1].nombre);

	gotoxy(3,32);printf("Telefono: %s", nombres[eleccion-1].telefono);

	strcpy(nombres[eleccion-1].nombre," ");
	strcpy(nombres[eleccion-1].telefono," ");

	}
break;


case 4:		//consulta
clrscr();

	do{
	textbackground(1);
	textcolor(WHITE);
	clrscr();
	textbackground(0);
	textcolor(WHITE);
	cprintf("                                                 Francisco Javier Herrera Vargas");		//nombre programa
	cprintf("Agenda telefonica                                                               ");
	textbackground(1);
	textcolor(15);
	gotoxy(3,10);printf("Lista de nombres");
	for(x=0;x<numero;x++)
	{
	gotoxy(3,12+x);printf("%d.- %s ",x+1,nombres[x].nombre);
	}
	gotoxy(3,30);printf("Introduce el numero de la persona que quieres consultar (cero para salir): ");
	scanf("%d", &eleccion);

	if(eleccion != 0 && eleccion <= numero)
	{
	gotoxy(3,32);printf("Nombre: %s", nombres[eleccion-1].nombre);

	gotoxy(3,34);printf("Telefono: %s", nombres[eleccion-1].telefono);
	getche();
	}
	}
	while(eleccion != 0);
	break;

case 5:
textbackground(1);
textcolor(WHITE);
break;
default:
printf("\n\nOpcion no disponible elija otra");
getche();
}
}
while(opcion!=5);
}

void palindromo()
{
	int cont=0;
	int op=0,aux=0,j=0,i=0,resp=1;
	char pal[80];  char vec[80];

	clrscr();
	textbackground(1);
	textcolor(15);
	do
	{
	clrscr();
	textbackground(0);
	textcolor(WHITE);
	cprintf("                                                 Francisco Javier Herrera Vargas");		//nombre programa
	cprintf("Palindromo                                                                      ");
		for(i=0;pal[i]!='\0';i++)   //limpiar
			pal[i]=' ';
		for(j=0;vec[j]!='\0';j++)   //limpiar
			vec[j]=' ';
		for(cont=0;pal[cont]!='\0';cont++)   //limpiar
			pal[cont]=' ';
		cont=0;
		if(resp==1)
		{
		gotoxy(3,25);printf("Ingrese una palabra:");
			scanf("%s",&pal);

			for(i=0;pal[i]!='\0';i++)
			{
				cont++;
			}
			cont=cont-1;
			aux=cont;

			j=0;
			while(j<=aux)
			{
				vec[j]=pal[cont];
				cont--;
				j++;
			}

			cont=0;j=0;op=0;
			while(pal[cont]==vec[j]&&pal[cont]!='\0'&&vec[j]!='\0')
			{
				cont++;
				j++;
				op++;
			}

			if(op==i)
			{
				textbackground(1);
				textcolor(YELLOW);
				gotoxy(3,28);cprintf("Si es palindromo");}
			else
			{       textbackground(1);
				textcolor(YELLOW);
				gotoxy(3,28);cprintf("No es palindromo");}
	}
	textbackground(0);
	textcolor(15);
	gotoxy(1,48);cprintf("                                                                                 ");
	gotoxy(1,49);cprintf("Deseas revisar otra palabra Si (1) No (2)                       ");
	cprintf("                                                                            Elije una opcion: ");
	scanf("%d",&resp);
	textbackground(BLUE);
	textcolor(WHITE);
	}
	while(resp!=2);
}

unidades(char num[6],char uni[100],int u) //para convertir del 0 al 9
{
	if(num[u]=='0')
	strcpy(uni,"cero");

	if(num[u]=='1')
	strcpy(uni,"uno");

	if(num[u]=='2')
	strcpy(uni,"dos");

	if(num[u]=='3')
	strcpy(uni,"tres");

	if(num[u]=='4')
	strcpy(uni,"cuatro");

	if(num[u]=='5')
	strcpy(uni,"cinco");

	if(num[u]=='6')
	strcpy(uni,"seis");

	if(num[u]=='7')
	strcpy(uni,"siete");

	if(num[u]=='8')
	strcpy(uni,"ocho");

	if(num[u]=='9')
	strcpy(uni,"nueve");

return uni[100];
}

decenas(char num[6],char uni[100],char dec[100],int u,int u2,int d) 		//funcion para convertir del 10 al 99
{
	if(num[d]=='1')					//convierte del 10 al 19
	{
		if(num[u2]=='0')
		strcpy(dec,"diez");

		if(num[u2]=='1')
		strcpy(dec,"once");

		if(num[u2]=='2')
		strcpy(dec,"doce");

		if(num[u2]=='3')
		strcpy(dec,"trece");

		if(num[u2]=='4')
		strcpy(dec,"catorce");

		if(num[u2]=='5')
		strcpy(dec,"quince");

		if(num[u]== '0' || num[u]== '1' || num[u]== '2' || num[u]== '3' || num[u]== '4' || num[u]== '5')	//convierte 16 al 19
		{	}
			else
			{
			strcpy(dec,"dieci");
			unidades(num,uni,u);
			strcpy(dec,strcat(dec,uni));
			}
	}

	if(num[d]=='2')	// 20 al 29
	{
		if(num[u2]=='0')
		strcpy(dec,"veinte");

		if(num[u]=='0')
		{	}
			else
			{
			strcpy(dec,"veinti");
			unidades(num,uni,u);
			strcpy(dec,strcat(dec,uni));
			}
	}

	if(num[d]=='3')	//30 al 39
	{
		if(num[u2]=='0')
		strcpy(dec,"treinta");

		if(num[u]=='0')
		{	}
			else
			{
			strcpy(dec,"treinta y ");
			unidades(num,uni,u);
			strcpy(dec,strcat(dec,uni));
			}
	}

	if(num[d]=='4')	//40 al 49
	{
		if(num[u2]=='0')
		strcpy(dec,"cuarenta");

		if(num[u]=='0')
		{	}
			else
			{
			strcpy(dec,"cuarenta y ");
			unidades(num,uni,u);
			strcpy(dec,strcat(dec,uni));
			}
	}

	if(num[d]=='5')		//50 al 59
	{
		if(num[u2]=='0')
		strcpy(dec,"cincuenta");

		if(num[u]=='0')
		{	}
			else
			{
			strcpy(dec,"cincuenta y ");
			unidades(num,uni,u);
			strcpy(dec,strcat(dec,uni));
			}
	}

	if(num[d]=='6')		//60 al 69
	{
		if(num[u2]=='0')
		strcpy(dec,"sesenta");

		if(num[u]=='0')
		{	}
			else
			{
			strcpy(dec,"sesenta y ");
			unidades(num,uni,u);
			strcpy(dec,strcat(dec,uni));
			}
	}

	if(num[d]=='7')		//70 al 79
	{
		if(num[u2]=='0')
		strcpy(dec,"setenta");

		if(num[u]=='0')
		{	}
			else
			{
			strcpy(dec,"setenta y ");
			unidades(num,uni,u);
			strcpy(dec,strcat(dec,uni));
			}
	}

	if(num[d]=='8')		//80 al 89
	{
		if(num[u2]=='0')
		strcpy(dec,"ochenta");

		if(num[u]=='0')
		{	}
			else
			{
			strcpy(dec,"ochenta y ");
			unidades(num,uni,u);
			strcpy(dec,strcat(dec,uni));
			}
	}

	if(num[d]=='9')		//90 al 99
	{
		if(num[u2]=='0')
		strcpy(dec,"noventa");

		if(num[u]=='0')
		{	}
			else
			{
			strcpy(dec,"noventa y ");
			unidades(num,uni,u);
			strcpy(dec,strcat(dec,uni));
			}
	}


return dec[100];
}

centenas(char num[6],char uni[100],char dec[100],char cen[100],int u,int u2,int d,int c)		//funcion que convierte del 100 al 199
{
	if(num[c]=='1')
	{
		if(num[u]=='0' && num[u2]=='0')
		strcpy(cen,"cien");
		else
		{
			strcpy(cen,"ciento ");
			if(num[d]=='0')
			{
				unidades(num,uni,u);
				strcpy(cen,strcat(cen,uni));
			}
			else
			{
				decenas(num,uni,dec,u,u2,d);
				strcpy(cen,strcat(cen,dec));
			}
		}
	}
	if(num[c]=='2')
	{
		if(num[u]=='0' && num[u2]=='0')
		strcpy(cen,"doscientos");
		else
		{
			strcpy(cen,"doscientos ");
			if(num[d]=='0')
			{
				unidades(num,uni,u);
				strcpy(cen,strcat(cen,uni));
			}
			else
			{
				decenas(num,uni,dec,u,u2,d);
				strcpy(cen,strcat(cen,dec));
			}
		}
	}

	if(num[c]=='3')
	{
		if(num[u]=='0' && num[u2]=='0')
		strcpy(cen,"trescientos");
		else
		{
			strcpy(cen,"trescientos ");
			if(num[d]=='0')
			{
				unidades(num,uni,u);
				strcpy(cen,strcat(cen,uni));
			}
			else
			{
				decenas(num,uni,dec,u,u2,d);
				strcpy(cen,strcat(cen,dec));
			}
		}
	}

	if(num[c]=='4')
	{
		if(num[u]=='0' && num[u2]=='0')
		strcpy(cen,"cuatrocientos");
		else
		{
			strcpy(cen,"cuatrocientos ");
			if(num[d]=='0')
			{
				unidades(num,uni,u);
				strcpy(cen,strcat(cen,uni));
			}
			else
			{
				decenas(num,uni,dec,u,u2,d);
				strcpy(cen,strcat(cen,dec));
			}
		}
	}

	if(num[c]=='5')
	{
		if(num[u]=='0' && num[u2]=='0')
		strcpy(cen,"quinientos");
		else
		{
			strcpy(cen,"quinientos ");
			if(num[d]=='0')
			{
				unidades(num,uni,u);
				strcpy(cen,strcat(cen,uni));
			}
			else
			{
				decenas(num,uni,dec,u,u2,d);
				strcpy(cen,strcat(cen,dec));
			}
		}
	}

	if(num[c]=='6')
	{
		if(num[u]=='0' && num[u2]=='0')
		strcpy(cen,"seiscientos");
		else
		{
			strcpy(cen,"seiscientos ");
			if(num[d]=='0')
			{
				unidades(num,uni,u);
				strcpy(cen,strcat(cen,uni));
			}
			else
			{
				decenas(num,uni,dec,u,u2,d);
				strcpy(cen,strcat(cen,dec));
			}
		}
	}

	if(num[c]=='7')
	{
		if(num[u]=='0' && num[u2]=='0')
		strcpy(cen,"setecientos");
		else
		{
			strcpy(cen,"setecientos ");
			if(num[d]=='0')
			{
				unidades(num,uni,u);
				strcpy(cen,strcat(cen,uni));
			}
			else
			{
				decenas(num,uni,dec,u,u2,d);
				strcpy(cen,strcat(cen,dec));
			}
		}
	}

	if(num[c]=='8')
	{
		if(num[u]=='0' && num[u2]=='0')
		strcpy(cen,"ochocientos");
		else
		{
			strcpy(cen,"ochocientos ");
			if(num[d]=='0')
			{
				unidades(num,uni,u);
				strcpy(cen,strcat(cen,uni));
			}
			else
			{
				decenas(num,uni,dec,u,u2,d);
				strcpy(cen,strcat(cen,dec));
			}
		}
	}

	if(num[c]=='9')
	{
		if(num[u]=='0' && num[u2]=='0')
		strcpy(cen,"novecientos");
		else
		{
			strcpy(cen,"novecientos ");
			if(num[d]=='0')
			{
				unidades(num,uni,u);
				strcpy(cen,strcat(cen,uni));
			}
			else
			{
				decenas(num,uni,dec,u,u2,d);
				strcpy(cen,strcat(cen,dec));
			}
		}
	}
return cen[100];
}

miles(char num[6],char uni[100],char dec[100],char cen[100],char mil[100],int u,int u2,int d,int c,int m) //Funcion que convierte del 1000 al 9999
{
int aux=1;
	if(num[m]=='1')
	{
		if(num[u]=='0' && num[u2]=='0' && num[d]=='0')
		strcpy(mil,"mil");
		else
		{
		strcpy(mil,"mil ");
			if(num[c]=='0' && num[d]=='0')
			{
			unidades(num,uni,u);
			strcpy(mil,strcat(mil,uni));
			aux=2;
			}
			if(num[d]=='0' && aux==1)
			{
			decenas(num,uni,dec,u,u2,d);
			strcpy(mil,strcat(mil,dec));
			aux=2;
			}
			if(aux==1)
			{
			centenas(num,uni,dec,cen,u,u2,d,c);
			strcpy(mil,strcat(mil,cen));
			}
		}
	}

	if(num[m]=='2')
	{
		if(num[u]=='0' && num[u2]=='0' && num[d]=='0')
		strcpy(mil,"dos mil");
		else
		{
		strcpy(mil,"dos mil ");
			if(num[c]=='0' && num[d]=='0')
			{
			unidades(num,uni,u);
			strcpy(mil,strcat(mil,uni));
			aux=2;
			}
			if(num[d]=='0' && aux==1)
			{
			decenas(num,uni,dec,u,u2,d);
			strcpy(mil,strcat(mil,dec));
			aux=2;
			}
			if(aux==1)
			{
			centenas(num,uni,dec,cen,u,u2,d,c);
			strcpy(mil,strcat(mil,cen));
			}
		}
	}

	if(num[m]=='3')
	{
		if(num[u]=='0' && num[u2]=='0' && num[d]=='0')
		strcpy(mil,"tres mil");
		else
		{
		strcpy(mil,"tres mil ");
			if(num[c]=='0' && num[d]=='0')
			{
			unidades(num,uni,u);
			strcpy(mil,strcat(mil,uni));
			aux=2;
			}
			if(num[d]=='0' && aux==1)
			{
			decenas(num,uni,dec,u,u2,d);
			strcpy(mil,strcat(mil,dec));
			aux=2;
			}
			if(aux==1)
			{
			centenas(num,uni,dec,cen,u,u2,d,c);
			strcpy(mil,strcat(mil,cen));
			}
		}
	}

	if(num[m]=='4')
	{
		if(num[u]=='0' && num[u2]=='0' && num[d]=='0')
		strcpy(mil,"cuatro mil");
		else
		{
		strcpy(mil,"cuatro mil ");
			if(num[c]=='0' && num[d]=='0')
			{
			unidades(num,uni,u);
			strcpy(mil,strcat(mil,uni));
			aux=2;
			}
			if(num[d]=='0' && aux==1)
			{
			decenas(num,uni,dec,u,u2,d);
			strcpy(mil,strcat(mil,dec));
			aux=2;
			}
			if(aux==1)
			{
			centenas(num,uni,dec,cen,u,u2,d,c);
			strcpy(mil,strcat(mil,cen));
			}
		}
	}

	if(num[m]=='5')
	{
		if(num[u]=='0' && num[u2]=='0' && num[d]=='0')
		strcpy(mil,"cinco mil");
		else
		{
		strcpy(mil,"cinco mil ");
			if(num[c]=='0' && num[d]=='0')
			{
			unidades(num,uni,u);
			strcpy(mil,strcat(mil,uni));
			aux=2;
			}
			if(num[d]=='0' && aux==1)
			{
			decenas(num,uni,dec,u,u2,d);
			strcpy(mil,strcat(mil,dec));
			aux=2;
			}
			if(aux==1)
			{
			centenas(num,uni,dec,cen,u,u2,d,c);
			strcpy(mil,strcat(mil,cen));
			}
		}
	}

	if(num[m]=='6')
	{
		if(num[u]=='0' && num[u2]=='0' && num[d]=='0')
		strcpy(mil,"seis mil");
		else
		{
		strcpy(mil,"seis mil ");
			if(num[c]=='0' && num[d]=='0')
			{
			unidades(num,uni,u);
			strcpy(mil,strcat(mil,uni));
			aux=2;
			}
			if(num[d]=='0' && aux==1)
			{
			decenas(num,uni,dec,u,u2,d);
			strcpy(mil,strcat(mil,dec));
			aux=2;
			}
			if(aux==1)
			{
			centenas(num,uni,dec,cen,u,u2,d,c);
			strcpy(mil,strcat(mil,cen));
			}
		}
	}

	if(num[m]=='7')
	{
		if(num[u]=='0' && num[u2]=='0' && num[d]=='0')
		strcpy(mil,"siete mil");
		else
		{
		strcpy(mil,"siete mil ");
			if(num[c]=='0' && num[d]=='0')
			{
			unidades(num,uni,u);
			strcpy(mil,strcat(mil,uni));
			aux=2;
			}
			if(num[d]=='0' && aux==1)
			{
			decenas(num,uni,dec,u,u2,d);
			strcpy(mil,strcat(mil,dec));
			aux=2;
			}
			if(aux==1)
			{
			centenas(num,uni,dec,cen,u,u2,d,c);
			strcpy(mil,strcat(mil,cen));
			}
		}
	}

	if(num[m]=='8')
	{
		if(num[u]=='0' && num[u2]=='0' && num[d]=='0')
		strcpy(mil,"ocho mil");
		else
		{
		strcpy(mil,"ocho mil ");
			if(num[c]=='0' && num[d]=='0')
			{
			unidades(num,uni,u);
			strcpy(mil,strcat(mil,uni));
			aux=2;
			}
			if(num[d]=='0' && aux==1)
			{
			decenas(num,uni,dec,u,u2,d);
			strcpy(mil,strcat(mil,dec));
			aux=2;
			}
			if(aux==1)
			{
			centenas(num,uni,dec,cen,u,u2,d,c);
			strcpy(mil,strcat(mil,cen));
			}
		}
	}

	if(num[m]=='9')
	{
		if(num[u]=='0' && num[u2]=='0' && num[d]=='0')
		strcpy(mil,"nueve mil");
		else
		{
		strcpy(mil,"nueve mil ");
			if(num[c]=='0' && num[d]=='0')
			{
			unidades(num,uni,u);
			strcpy(mil,strcat(mil,uni));
			aux=2;
			}
			if(num[d]=='0' && aux==1)
			{
			decenas(num,uni,dec,u,u2,d);
			strcpy(mil,strcat(mil,dec));
			aux=2;
			}
			if(aux==1)
			{
			centenas(num,uni,dec,cen,u,u2,d,c);
			strcpy(mil,strcat(mil,cen));
			}
		}
	}
return mil[100];
}

decenasmil(char num[6],char uni[100],char dec[100],char cen[100],char mil[100], char dmil[100],int u,int u2,int d,int c,int m,int dm) //Funcion que convierte del 10 000 al 99 999
{
int aux=1;
	if(num[dm]=='1')
	{
		if(num[m]=='0' && num[dm]=='1')
		{
			if(num[c]=='0' && num[d]=='0' && num[u]=='0')
			{
			strcpy(dmil,"diez mil");
			aux=2;
			}
			else
			strcpy(dmil,"diez mil ");
			if(num[c]=='0' && num[d]=='0' && aux==1)
			{
			unidades(num,uni,u);
			strcpy(dmil,strcat(dmil,uni));
			aux=2;
			}
			if(num[c]=='0' && aux==1)
			{
			decenas(num,uni,dec,u,u2,d);
			strcpy(dmil,strcat(dmil,dec));
			aux=2;
			}
			if(aux==1)
			{
			centenas(num,uni,dec,cen,u,u2,d,c);
			strcpy(dmil,strcat(dmil,cen));
			aux=2;
			}
		}

		if(num[m]=='1' && num[dm]=='1')
		{
			if(num[c]=='0' && num[d]=='0' && num[u]=='0')
			{
			strcpy(dmil,"once mil");
			aux=2;
			}
			else
			strcpy(dmil,"once mil ");
			if(num[c]=='0' && num[d]=='0' && aux==1)
			{
			unidades(num,uni,u);
			strcpy(dmil,strcat(dmil,uni));
			aux=2;
			}
			if(num[c]=='0' && aux==1)
			{
			decenas(num,uni,dec,u,u2,d);
			strcpy(dmil,strcat(dmil,dec));
			aux=2;
			}
			if(aux==1)
			{
			centenas(num,uni,dec,cen,u,u2,d,c);
			strcpy(dmil,strcat(dmil,cen));
			aux=2;
			}
		}

		if(num[m]=='2' && num[dm]=='1')
		{
			if(num[c]=='0' && num[d]=='0' && num[u]=='0')
			{
			strcpy(dmil,"doce mil");
			aux=2;
			}
			else
			strcpy(dmil,"doce mil ");
			if(num[c]=='0' && num[d]=='0' && aux==1)
			{
			unidades(num,uni,u);
			strcpy(dmil,strcat(dmil,uni));
			aux=2;
			}
			if(num[c]=='0' && aux==1)
			{
			decenas(num,uni,dec,u,u2,d);
			strcpy(dmil,strcat(dmil,dec));
			aux=2;
			}
			if(aux==1)
			{
			centenas(num,uni,dec,cen,u,u2,d,c);
			strcpy(dmil,strcat(dmil,cen));
			aux=2;
			}
		}

		if(num[m]=='3' && num[dm]=='1')
		{
			if(num[c]=='0' && num[d]=='0' && num[u]=='0')
			{
			strcpy(dmil,"trece mil");
			aux=2;
			}
			else
			strcpy(dmil,"trece mil ");
			if(num[c]=='0' && num[d]=='0' && aux==1)
			{
			unidades(num,uni,u);
			strcpy(dmil,strcat(dmil,uni));
			aux=2;
			}
			if(num[c]=='0' && aux==1)
			{
			decenas(num,uni,dec,u,u2,d);
			strcpy(dmil,strcat(dmil,dec));
			aux=2;
			}
			if(aux==1)
			{
			centenas(num,uni,dec,cen,u,u2,d,c);
			strcpy(dmil,strcat(dmil,cen));
			aux=2;
			}
		}

		if(num[m]=='4' && num[dm]=='1')
		{
			if(num[c]=='0' && num[d]=='0' && num[u]=='0')
			{
			strcpy(dmil,"catorce mil");
			aux=2;
			}
			else
			strcpy(dmil,"catorce mil ");
			if(num[c]=='0' && num[d]=='0' && aux==1)
			{
			unidades(num,uni,u);
			strcpy(dmil,strcat(dmil,uni));
			aux=2;
			}
			if(num[c]=='0' && aux==1)
			{
			decenas(num,uni,dec,u,u2,d);
			strcpy(dmil,strcat(dmil,dec));
			aux=2;
			}
			if(aux==1)
			{
			centenas(num,uni,dec,cen,u,u2,d,c);
			strcpy(dmil,strcat(dmil,cen));
			aux=2;
			}
		}

		if(num[m]=='5' && num[dm]=='1')
		{
			if(num[c]=='0' && num[d]=='0' && num[u]=='0')
			{
			strcpy(dmil,"quince mil");
			aux=2;
			}
			else
			strcpy(dmil,"quince mil ");
			if(num[c]=='0' && num[d]=='0' && aux==1)
			{
			unidades(num,uni,u);
			strcpy(dmil,strcat(dmil,uni));
			aux=2;
			}
			if(num[c]=='0' && aux==1)
			{
			decenas(num,uni,dec,u,u2,d);
			strcpy(dmil,strcat(dmil,dec));
			aux=2;
			}
			if(aux==1)
			{
			centenas(num,uni,dec,cen,u,u2,d,c);
			strcpy(dmil,strcat(dmil,cen));
			aux=2;
			}
		}
			if(aux==1)
			{
				if(num[dm]=='1')
				strcpy(dmil,"dieci");
				miles(num,uni,dec,cen,mil,u,u2,d,c,m);
				strcpy(dmil,strcat(dmil,mil));
				aux=2;
			}
	}
	if(aux==1)
	{
		if(num[dm]=='2')
		{
			if(aux==1)
			{
				if(num[u]=='0' && num[d]=='0' && num[c]=='0' && num[m]=='0')
				{
				strcpy(dmil,"veinte mil");
				aux=2;
				}
				if(num[d]=='0' && num[c]=='0' && num[m]=='0' && aux==1)
				{
				strcpy(dmil,"veinte mil ");
				unidades(num,uni,u);
				strcpy(dmil,strcat(dmil,uni));
				aux=2;
				}
				if(num[c]=='0' && num[m]=='0' && aux==1)
				{
				strcpy(dmil,"veinte mil ");
				decenas(num,uni,dec,u,u2,d);
				strcpy(dmil,strcat(dmil,dec));
				aux=2;
				}
				if(num[m]=='0' && aux==1)
				{
				strcpy(dmil,"veinte mil ");
				centenas(num,uni,dec,cen,u,u2,d,c);
				strcpy(dmil,strcat(dmil,cen));
				aux=2;
				}
				if(num[u]=='0' && num[d]=='0' && num[c]=='0' && num[m]=='1' && aux==1)
				{
				strcpy(dmil,"veintiun mil ");
				aux=2;
				}
				if(num[d]=='0' && num[c]=='0' && num[m]=='1' && aux==1)
				{
				strcpy(dmil,"veintiun mil ");
				unidades(num,uni,u);
				strcpy(dmil,strcat(dmil,uni));
				aux=2;
				}
				if(num[c]=='0' && num[m]=='1' && aux==1)
				{
				strcpy(dmil,"veintiun mil ");
				decenas(num,uni,dec,u,u2,d);
				strcpy(dmil,strcat(dmil,dec));
				aux=2;
				}
				if(num[m]=='1' && aux==1)
				{
				strcpy(dmil,"veintiun mil ");
				centenas(num,uni,dec,cen,u,u2,d,c);
				strcpy(dmil,strcat(dmil,cen));
				aux=2;
				}
				if(aux==1)
				{
				strcpy(dmil,"veinti");
				miles(num,uni,dec,cen,mil,u,u2,d,c,m);
				strcpy(dmil,strcat(dmil,mil));
				aux=2;
				}
			}
		}
	}

	if(aux==1)
	{
		if(num[dm]=='3')
		{
			if(aux==1)
			{
				if(num[u]=='0' && num[d]=='0' && num[c]=='0' && num[m]=='0')
				{
				strcpy(dmil,"treinta mil");
				aux=2;
				}
				if(num[d]=='0' && num[c]=='0' && num[m]=='0' && aux==1)
				{
				strcpy(dmil,"treinta mil ");
				unidades(num,uni,u);
				strcpy(dmil,strcat(dmil,uni));
				aux=2;
				}
				if(num[c]=='0' && num[m]=='0' && aux==1)
				{
				strcpy(dmil,"treinta mil ");
				decenas(num,uni,dec,u,u2,d);
				strcpy(dmil,strcat(dmil,dec));
				aux=2;
				}
				if(num[m]=='0' && aux==1)
				{
				strcpy(dmil,"treinta mil ");
				centenas(num,uni,dec,cen,u,u2,d,c);
				strcpy(dmil,strcat(dmil,cen));
				aux=2;
				}
				if(num[u]=='0' && num[d]=='0' && num[c]=='0' && num[m]=='1' && aux==1)
				{
				strcpy(dmil,"treinta y un mil ");
				aux=2;
				}
				if(num[d]=='0' && num[c]=='0' && num[m]=='1' && aux==1)
				{
				strcpy(dmil,"treinta y un mil ");
				unidades(num,uni,u);
				strcpy(dmil,strcat(dmil,uni));
				aux=2;
				}
				if(num[c]=='0' && num[m]=='1' && aux==1)
				{
				strcpy(dmil,"treinta y un mil ");
				decenas(num,uni,dec,u,u2,d);
				strcpy(dmil,strcat(dmil,dec));
				aux=2;
				}
				if(num[m]=='1' && aux==1)
				{
				strcpy(dmil,"treinta y un mil ");
				centenas(num,uni,dec,cen,u,u2,d,c);
				strcpy(dmil,strcat(dmil,cen));
				aux=2;
				}
				if(aux==1)
				{
				strcpy(dmil,"treinta y ");
				miles(num,uni,dec,cen,mil,u,u2,d,c,m);
				strcpy(dmil,strcat(dmil,mil));
				aux=2;
				}
			}
		}
	}

	if(aux==1)
	{
		if(num[dm]=='4')
		{
			if(aux==1)
			{
				if(num[u]=='0' && num[d]=='0' && num[c]=='0' && num[m]=='0')
				{
				strcpy(dmil,"cuarenta mil");
				aux=2;
				}
				if(num[d]=='0' && num[c]=='0' && num[m]=='0' && aux==1)
				{
				strcpy(dmil,"cuarenta mil ");
				unidades(num,uni,u);
				strcpy(dmil,strcat(dmil,uni));
				aux=2;
				}
				if(num[c]=='0' && num[m]=='0' && aux==1)
				{
				strcpy(dmil,"cuarenta mil ");
				decenas(num,uni,dec,u,u2,d);
				strcpy(dmil,strcat(dmil,dec));
				aux=2;
				}
				if(num[m]=='0' && aux==1)
				{
				strcpy(dmil,"cuarenta mil ");
				centenas(num,uni,dec,cen,u,u2,d,c);
				strcpy(dmil,strcat(dmil,cen));
				aux=2;
				}
				if(num[u]=='0' && num[d]=='0' && num[c]=='0' && num[m]=='1' && aux==1)
				{
				strcpy(dmil,"cuarenta y un mil ");
				aux=2;
				}
				if(num[d]=='0' && num[c]=='0' && num[m]=='1' && aux==1)
				{
				strcpy(dmil,"cuarenta y un mil ");
				unidades(num,uni,u);
				strcpy(dmil,strcat(dmil,uni));
				aux=2;
				}
				if(num[c]=='0' && num[m]=='1' && aux==1)
				{
				strcpy(dmil,"cuarenta y un mil ");
				decenas(num,uni,dec,u,u2,d);
				strcpy(dmil,strcat(dmil,dec));
				aux=2;
				}
				if(num[m]=='1' && aux==1)
				{
				strcpy(dmil,"cuarenta y un mil ");
				centenas(num,uni,dec,cen,u,u2,d,c);
				strcpy(dmil,strcat(dmil,cen));
				aux=2;
				}
				if(aux==1)
				{
				strcpy(dmil,"cuarenta y ");
				miles(num,uni,dec,cen,mil,u,u2,d,c,m);
				strcpy(dmil,strcat(dmil,mil));
				aux=2;
				}
			}
		}
	}

	if(aux==1)
	{
		if(num[dm]=='5')
		{
			if(aux==1)
			{
				if(num[u]=='0' && num[d]=='0' && num[c]=='0' && num[m]=='0')
				{
				strcpy(dmil,"cincuenta mil");
				aux=2;
				}
				if(num[d]=='0' && num[c]=='0' && num[m]=='0' && aux==1)
				{
				strcpy(dmil,"cincuenta mil ");
				unidades(num,uni,u);
				strcpy(dmil,strcat(dmil,uni));
				aux=2;
				}
				if(num[c]=='0' && num[m]=='0' && aux==1)
				{
				strcpy(dmil,"cincuenta mil ");
				decenas(num,uni,dec,u,u2,d);
				strcpy(dmil,strcat(dmil,dec));
				aux=2;
				}
				if(num[m]=='0' && aux==1)
				{
				strcpy(dmil,"cincuenta mil ");
				centenas(num,uni,dec,cen,u,u2,d,c);
				strcpy(dmil,strcat(dmil,cen));
				aux=2;
				}
				if(num[u]=='0' && num[d]=='0' && num[c]=='0' && num[m]=='1' && aux==1)
				{
				strcpy(dmil,"cincuenta y un mil");
				aux=2;
				}
				if(num[d]=='0' && num[c]=='0' && num[m]=='1' && aux==1)
				{
				strcpy(dmil,"cincuenta y un mil ");
				unidades(num,uni,u);
				strcpy(dmil,strcat(dmil,uni));
				aux=2;
				}
				if(num[c]=='0' && num[m]=='1' && aux==1)
				{
				strcpy(dmil,"cincuenta y un mil ");
				decenas(num,uni,dec,u,u2,d);
				strcpy(dmil,strcat(dmil,dec));
				aux=2;
				}
				if(num[m]=='1' && aux==1)
				{
				strcpy(dmil,"cincuenta y un mil ");
				centenas(num,uni,dec,cen,u,u2,d,c);
				strcpy(dmil,strcat(dmil,cen));
				aux=2;
				}
				if(aux==1)
				{
				strcpy(dmil,"cincuenta y ");
				miles(num,uni,dec,cen,mil,u,u2,d,c,m);
				strcpy(dmil,strcat(dmil,mil));
				aux=2;
				}
			}
		}
	}

	if(aux==1)
	{
		if(num[dm]=='6')
		{
			if(aux==1)
			{
				if(num[u]=='0' && num[d]=='0' && num[c]=='0' && num[m]=='0')
				{
				strcpy(dmil,"sesenta mil");
				aux=2;
				}
				if(num[d]=='0' && num[c]=='0' && num[m]=='0' && aux==1)
				{
				strcpy(dmil,"sesenta mil ");
				unidades(num,uni,u);
				strcpy(dmil,strcat(dmil,uni));
				aux=2;
				}
				if(num[c]=='0' && num[m]=='0' && aux==1)
				{
				strcpy(dmil,"sesenta mil ");
				decenas(num,uni,dec,u,u2,d);
				strcpy(dmil,strcat(dmil,dec));
				aux=2;
				}
				if(num[m]=='0' && aux==1)
				{
				strcpy(dmil,"sesenta mil ");
				centenas(num,uni,dec,cen,u,u2,d,c);
				strcpy(dmil,strcat(dmil,cen));
				aux=2;
				}
				if(num[u]=='0' && num[d]=='0' && num[c]=='0' && num[m]=='1' && aux==1)
				{
				strcpy(dmil,"sesenta y un mil");
				aux=2;
				}
				if(num[d]=='0' && num[c]=='0' && num[m]=='1' && aux==1)
				{
				strcpy(dmil,"sesenta y un mil ");
				unidades(num,uni,u);
				strcpy(dmil,strcat(dmil,uni));
				aux=2;
				}
				if(num[c]=='0' && num[m]=='1' && aux==1)
				{
				strcpy(dmil,"sesenta y un mil ");
				decenas(num,uni,dec,u,u2,d);
				strcpy(dmil,strcat(dmil,dec));
				aux=2;
				}
				if(num[m]=='1' && aux==1)
				{
				strcpy(dmil,"sesenta y un mil ");
				centenas(num,uni,dec,cen,u,u2,d,c);
				strcpy(dmil,strcat(dmil,cen));
				aux=2;
				}
				if(aux==1)
				{
				strcpy(dmil,"sesenta y ");
				miles(num,uni,dec,cen,mil,u,u2,d,c,m);
				strcpy(dmil,strcat(dmil,mil));
				aux=2;
				}
			}
		}
	}

	if(aux==1)
	{
		if(num[dm]=='7')
		{
			if(aux==1)
			{
				if(num[u]=='0' && num[d]=='0' && num[c]=='0' && num[m]=='0')
				{
				strcpy(dmil,"setenta mil");
				aux=2;
				}
				if(num[d]=='0' && num[c]=='0' && num[m]=='0' && aux==1)
				{
				strcpy(dmil,"setenta mil ");
				unidades(num,uni,u);
				strcpy(dmil,strcat(dmil,uni));
				aux=2;
				}
				if(num[c]=='0' && num[m]=='0' && aux==1)
				{
				strcpy(dmil,"setenta mil ");
				decenas(num,uni,dec,u,u2,d);
				strcpy(dmil,strcat(dmil,dec));
				aux=2;
				}
				if(num[m]=='0' && aux==1)
				{
				strcpy(dmil,"setenta mil ");
				centenas(num,uni,dec,cen,u,u2,d,c);
				strcpy(dmil,strcat(dmil,cen));
				aux=2;
				}
				if(num[u]=='0' && num[d]=='0' && num[c]=='0' && num[m]=='1' && aux==1)
				{
				strcpy(dmil,"setenta y un mil ");
				aux=2;
				}
				if(num[d]=='0' && num[c]=='0' && num[m]=='1' && aux==1)
				{
				strcpy(dmil,"setenta y un mil ");
				unidades(num,uni,u);
				strcpy(dmil,strcat(dmil,uni));
				aux=2;
				}
				if(num[c]=='0' && num[m]=='1' && aux==1)
				{
				strcpy(dmil,"setenta y un mil ");
				decenas(num,uni,dec,u,u2,d);
				strcpy(dmil,strcat(dmil,dec));
				aux=2;
				}
				if(num[m]=='1' && aux==1)
				{
				strcpy(dmil,"setenta y un mil ");
				centenas(num,uni,dec,cen,u,u2,d,c);
				strcpy(dmil,strcat(dmil,cen));
				aux=2;
				}
				if(aux==1)
				{
				strcpy(dmil,"setenta y ");
				miles(num,uni,dec,cen,mil,u,u2,d,c,m);
				strcpy(dmil,strcat(dmil,mil));
				aux=2;
				}
			}
		}
	}

	if(aux==1)
	{
		if(num[dm]=='8')
		{
			if(aux==1)
			{
				if(num[u]=='0' && num[d]=='0' && num[c]=='0' && num[m]=='0')
				{
				strcpy(dmil,"ochenta mil");
				aux=2;
				}
				if(num[d]=='0' && num[c]=='0' && num[m]=='0' && aux==1)
				{
				strcpy(dmil,"ochenta mil ");
				unidades(num,uni,u);
				strcpy(dmil,strcat(dmil,uni));
				aux=2;
				}
				if(num[c]=='0' && num[m]=='0' && aux==1)
				{
				strcpy(dmil,"ochenta mil ");
				decenas(num,uni,dec,u,u2,d);
				strcpy(dmil,strcat(dmil,dec));
				aux=2;
				}
				if(num[m]=='0' && aux==1)
				{
				strcpy(dmil,"ochenta mil ");
				centenas(num,uni,dec,cen,u,u2,d,c);
				strcpy(dmil,strcat(dmil,cen));
				aux=2;
				}
				if(num[u]=='0' && num[d]=='0' && num[c]=='0' && num[m]=='1' && aux==1)
				{
				strcpy(dmil,"ochenta y un mil ");
				aux=2;
				}
				if(num[d]=='0' && num[c]=='0' && num[m]=='1' && aux==1)
				{
				strcpy(dmil,"ochenta y un mil ");
				unidades(num,uni,u);
				strcpy(dmil,strcat(dmil,uni));
				aux=2;
				}
				if(num[c]=='0' && num[m]=='1' && aux==1)
				{
				strcpy(dmil,"ochenta y un mil ");
				decenas(num,uni,dec,u,u2,d);
				strcpy(dmil,strcat(dmil,dec));
				aux=2;
				}
				if(num[m]=='1' && aux==1)
				{
				strcpy(dmil,"ochenta y un mil ");
				centenas(num,uni,dec,cen,u,u2,d,c);
				strcpy(dmil,strcat(dmil,cen));
				aux=2;
				}
				if(aux==1)
				{
				strcpy(dmil,"ochenta y ");
				miles(num,uni,dec,cen,mil,u,u2,d,c,m);
				strcpy(dmil,strcat(dmil,mil));
				aux=2;
				}
			}
		}
	}

	if(aux==1)
	{
		if(num[dm]=='9')
		{
			if(aux==1)
			{
				if(num[u]=='0' && num[d]=='0' && num[c]=='0' && num[m]=='0')
				{
				strcpy(dmil,"noventa mil");
				aux=2;
				}
				if(num[d]=='0' && num[c]=='0' && num[m]=='0' && aux==1)
				{
				strcpy(dmil,"noventa mil ");
				unidades(num,uni,u);
				strcpy(dmil,strcat(dmil,uni));
				aux=2;
				}
				if(num[c]=='0' && num[m]=='0' && aux==1)
				{
				strcpy(dmil,"noventa mil ");
				decenas(num,uni,dec,u,u2,d);
				strcpy(dmil,strcat(dmil,dec));
				aux=2;
				}
				if(num[m]=='0' && aux==1)
				{
				strcpy(dmil,"noventa mil ");
				centenas(num,uni,dec,cen,u,u2,d,c);
				strcpy(dmil,strcat(dmil,cen));
				aux=2;
				}
				if(num[u]=='0' && num[d]=='0' && num[c]=='0' && num[m]=='1' && aux==1)
				{
				strcpy(dmil,"noventa y un mil ");
				aux=2;
				}
				if(num[d]=='0' && num[c]=='0' && num[m]=='1' && aux==1)
				{
				strcpy(dmil,"noventa y un mil ");
				unidades(num,uni,u);
				strcpy(dmil,strcat(dmil,uni));
				aux=2;
				}
				if(num[c]=='0' && num[m]=='1' && aux==1)
				{
				strcpy(dmil,"noventa y un mil ");
				decenas(num,uni,dec,u,u2,d);
				strcpy(dmil,strcat(dmil,dec));
				aux=2;
				}
				if(num[m]=='1' && aux==1)
				{
				strcpy(dmil,"no venta y un mil ");
				centenas(num,uni,dec,cen,u,u2,d,c);
				strcpy(dmil,strcat(dmil,cen));
				aux=2;
				}
				if(aux==1)
				{
				strcpy(dmil,"noventa y ");
				miles(num,uni,dec,cen,mil,u,u2,d,c,m);
				strcpy(dmil,strcat(dmil,mil));
				aux=2;
				}
			}
		}
	}

return dmil[100];
}

centenasmil(char num[6],char uni[100],char dec[100],char cen[100],char mil[100], char dmil[100],char cmil[100],int u,int u2,int d,int c,int m,int dm,int cm)
//Funcion que convierte del 100 000 al 999 999
{
int aux=1;
	if(num[cm]=='1')
	{
		if(num[dm]=='0' && num[m]=='0')
		{
			if(num[dm]=='0' && num[m]=='0' && num[c]=='0' && num[d]=='0' && num[u]=='0')
			{
			strcpy(cmil,"cien mil");
			aux=2;
			}
			else
			strcpy(cmil,"cien mil ");
			if(num[dm]=='0' && num[m]=='0' && num[c]=='0' && num[d]=='0' && aux==1)
			{
			unidades(num,uni,u);
			strcpy(cmil,strcat(cmil,uni));
			aux=2;
			}
			if(num[dm]=='0' && num[m]=='0' && num[c]=='0' && aux==1)
			{
			decenas(num,uni,dec,u,u2,d);
			strcpy(cmil,strcat(cmil,dec));
			aux=2;
			}
			if(num[dm]=='0' && num[m]=='0' && aux==1)
			{
			centenas(num,uni,dec,cen,u,u2,d,c);
			strcpy(cmil,strcat(cmil,cen));
			aux=2;
			}
		}
	if(num[dm]=='0' && num[m]=='1' && aux==1)
	{
		strcpy(cmil,"ciento un mil ");
		if(num[dm]=='0' && num[m]=='1' && num[c]=='0' && num[d]=='0' && num[u]=='0' && aux==1)
		{
			strcpy(cmil,"ciento un mil");
			aux=2;
		}
		if(num[dm]=='0' && num[m]=='1' && num[c]=='0' && num[d]=='0' && aux==1)
		{
			strcpy(cmil,"ciento un mil ");
			unidades(num,uni,u);
			strcpy(cmil,strcat(cmil,uni));
			aux=2;
		}
		if(num[dm]=='0' && num[m]=='1' && num[c]=='0' && aux==1)
		{
			strcpy(cmil,"ciento un mil ");
			decenas(num,uni,dec,u,u2,d);
			strcpy(cmil,strcat(cmil,dec));
			aux=2;
		}
		if(num[dm]=='0' && num[m]=='1' && aux==1)
		{
			strcpy(cmil,"ciento un mil ");
			centenas(num,uni,dec,cen,u,u2,d,c);
			strcpy(cmil,strcat(cmil,cen));
			aux=2;
		}
	}
		if(num[dm]=='0' && aux==1)
		{
			strcpy(cmil,"ciento ");
			miles(num,uni,dec,cen,mil,u,u2,d,c,m);
			strcpy(cmil,strcat(cmil,mil));
			aux=2;
		}
		if(aux==1)
		{
		strcpy(cmil,"ciento ");
		decenasmil(num,uni,dec,cen,mil,dmil,u,u2,d,c,m,dm);
		strcpy(cmil,strcat(cmil,dmil));
		aux=2;
		}
	}

	if(num[cm]=='2')
	{
		if(num[dm]=='0' && num[m]=='0')
		{
			if(num[dm]=='0' && num[m]=='0' && num[c]=='0' && num[d]=='0' && num[u]=='0')
			{
			strcpy(cmil,"doscientos mil");
			aux=2;
			}
			else
			strcpy(cmil,"doscientos mil ");
			if(num[dm]=='0' && num[m]=='0' && num[c]=='0' && num[d]=='0' && aux==1)
			{
			unidades(num,uni,u);
			strcpy(cmil,strcat(cmil,uni));
			aux=2;
			}
			if(num[dm]=='0' && num[m]=='0' && num[c]=='0' && aux==1)
			{
			decenas(num,uni,dec,u,u2,d);
			strcpy(cmil,strcat(cmil,dec));
			aux=2;
			}
			if(num[dm]=='0' && num[m]=='0' && aux==1)
			{
			centenas(num,uni,dec,cen,u,u2,d,c);
			strcpy(cmil,strcat(cmil,cen));
			aux=2;
			}
		}
	if(num[dm]=='0' && num[m]=='1' && aux==1)
	{
		strcpy(cmil,"doscientos un mil ");
		if(num[dm]=='0' && num[m]=='1' && num[c]=='0' && num[d]=='0' && num[u]=='0' && aux==1)
		{
			strcpy(cmil,"doscientos un mil");
			aux=2;
		}

		if(num[dm]=='0' && num[m]=='1' && num[c]=='0' && num[d]=='0' && aux==1)
		{
			strcpy(cmil,"doscientos un mil ");
			unidades(num,uni,u);
			strcpy(cmil,strcat(cmil,uni));
			aux=2;
		}
		if(num[dm]=='0' && num[m]=='1' && num[c]=='0' && aux==1)
		{
			strcpy(cmil,"doscientos un mil ");
			decenas(num,uni,dec,u,u2,d);
			strcpy(cmil,strcat(cmil,dec));
			aux=2;
		}
		if(num[dm]=='0' && num[m]=='1' && aux==1)
		{
			strcpy(cmil,"doscientos un mil ");
			centenas(num,uni,dec,cen,u,u2,d,c);
			strcpy(cmil,strcat(cmil,cen));
			aux=2;
		}
	}
		if(num[dm]=='0' && aux==1)
		{
			strcpy(cmil,"doscientos ");
			miles(num,uni,dec,cen,mil,u,u2,d,c,m);
			strcpy(cmil,strcat(cmil,mil));
			aux=2;
		}
		if(aux==1)
		{
		strcpy(cmil,"doscientos ");
		decenasmil(num,uni,dec,cen,mil,dmil,u,u2,d,c,m,dm);
		strcpy(cmil,strcat(cmil,dmil));
		aux=2;
		}
	}

	if(num[cm]=='3')
	{
		if(num[dm]=='0' && num[m]=='0')
		{
			if(num[dm]=='0' && num[m]=='0' && num[c]=='0' && num[d]=='0' && num[u]=='0')
			{
			strcpy(cmil,"trescientos mil");
			aux=2;
			}
			else
			strcpy(cmil,"trescientos mil ");
			if(num[dm]=='0' && num[m]=='0' && num[c]=='0' && num[d]=='0' && aux==1)
			{
			unidades(num,uni,u);
			strcpy(cmil,strcat(cmil,uni));
			aux=2;
			}
			if(num[dm]=='0' && num[m]=='0' && num[c]=='0' && aux==1)
			{
			decenas(num,uni,dec,u,u2,d);
			strcpy(cmil,strcat(cmil,dec));
			aux=2;
			}
			if(num[dm]=='0' && num[m]=='0' && aux==1)
			{
			centenas(num,uni,dec,cen,u,u2,d,c);
			strcpy(cmil,strcat(cmil,cen));
			aux=2;
			}
		}
	if(num[dm]=='0' && num[m]=='1' && aux==1)
	{
		strcpy(cmil,"trescientos un mil ");
		if(num[dm]=='0' && num[m]=='1' && num[c]=='0' && num[d]=='0' && num[u]=='0' && aux==1)
		{
			strcpy(cmil,"trescientos un mil");
			aux=2;
		}

		if(num[dm]=='0' && num[m]=='1' && num[c]=='0' && num[d]=='0' && aux==1)
		{
			strcpy(cmil,"trescientos un mil ");
			unidades(num,uni,u);
			strcpy(cmil,strcat(cmil,uni));
			aux=2;
		}
		if(num[dm]=='0' && num[m]=='1' && num[c]=='0' && aux==1)
		{
			strcpy(cmil,"trescientos un mil ");
			decenas(num,uni,dec,u,u2,d);
			strcpy(cmil,strcat(cmil,dec));
			aux=2;
		}
		if(num[dm]=='0' && num[m]=='1' && aux==1)
		{
			strcpy(cmil,"trescientos un mil ");
			centenas(num,uni,dec,cen,u,u2,d,c);
			strcpy(cmil,strcat(cmil,cen));
			aux=2;
		}
	}
		if(num[dm]=='0' && aux==1)
		{
			strcpy(cmil,"trescientos ");
			miles(num,uni,dec,cen,mil,u,u2,d,c,m);
			strcpy(cmil,strcat(cmil,mil));
			aux=2;
		}
		if(aux==1)
		{
		strcpy(cmil,"trescientos ");
		decenasmil(num,uni,dec,cen,mil,dmil,u,u2,d,c,m,dm);
		strcpy(cmil,strcat(cmil,dmil));
		aux=2;
		}
	}

	if(num[cm]=='4')
	{
		if(num[dm]=='0' && num[m]=='0')
		{
			if(num[dm]=='0' && num[m]=='0' && num[c]=='0' && num[d]=='0' && num[u]=='0')
			{
			strcpy(cmil,"cuatrocientos mil");
			aux=2;
			}
			else
			strcpy(cmil,"cuatrocientos mil ");
			if(num[dm]=='0' && num[m]=='0' && num[c]=='0' && num[d]=='0' && aux==1)
			{
			unidades(num,uni,u);
			strcpy(cmil,strcat(cmil,uni));
			aux=2;
			}
			if(num[dm]=='0' && num[m]=='0' && num[c]=='0' && aux==1)
			{
			decenas(num,uni,dec,u,u2,d);
			strcpy(cmil,strcat(cmil,dec));
			aux=2;
			}
			if(num[dm]=='0' && num[m]=='0' && aux==1)
			{
			centenas(num,uni,dec,cen,u,u2,d,c);
			strcpy(cmil,strcat(cmil,cen));
			aux=2;
			}
		}
	if(num[dm]=='0' && num[m]=='1' && aux==1)
	{
		strcpy(cmil,"cuatrocientos un mil ");
		if(num[dm]=='0' && num[m]=='1' && num[c]=='0' && num[d]=='0' && num[u]=='0' && aux==1)
		{
			strcpy(cmil,"cuatrocientos un mil");
			aux=2;
		}

		if(num[dm]=='0' && num[m]=='1' && num[c]=='0' && num[d]=='0' && aux==1)
		{
			strcpy(cmil,"cuatrocientos un mil ");
			unidades(num,uni,u);
			strcpy(cmil,strcat(cmil,uni));
			aux=2;
		}
		if(num[dm]=='0' && num[m]=='1' && num[c]=='0' && aux==1)
		{
			strcpy(cmil,"cuatrocientos un mil ");
			decenas(num,uni,dec,u,u2,d);
			strcpy(cmil,strcat(cmil,dec));
			aux=2;
		}
		if(num[dm]=='0' && num[m]=='1' && aux==1)
		{
			strcpy(cmil,"cuatrocientos un mil ");
			centenas(num,uni,dec,cen,u,u2,d,c);
			strcpy(cmil,strcat(cmil,cen));
			aux=2;
		}
	}
		if(num[dm]=='0' && aux==1)
		{
			strcpy(cmil,"cuatrocientos ");
			miles(num,uni,dec,cen,mil,u,u2,d,c,m);
			strcpy(cmil,strcat(cmil,mil));
			aux=2;
		}
		if(aux==1)
		{
		strcpy(cmil,"cuatrocientos ");
		decenasmil(num,uni,dec,cen,mil,dmil,u,u2,d,c,m,dm);
		strcpy(cmil,strcat(cmil,dmil));
		aux=2;
		}
	}

	if(num[cm]=='5')
	{
		if(num[dm]=='0' && num[m]=='0')
		{
			if(num[dm]=='0' && num[m]=='0' && num[c]=='0' && num[d]=='0' && num[u]=='0')
			{
			strcpy(cmil,"quinientos mil");
			aux=2;
			}
			else
			strcpy(cmil,"quinientos mil ");
			if(num[dm]=='0' && num[m]=='0' && num[c]=='0' && num[d]=='0' && aux==1)
			{
			unidades(num,uni,u);
			strcpy(cmil,strcat(cmil,uni));
			aux=2;
			}
			if(num[dm]=='0' && num[m]=='0' && num[c]=='0' && aux==1)
			{
			decenas(num,uni,dec,u,u2,d);
			strcpy(cmil,strcat(cmil,dec));
			aux=2;
			}
			if(num[dm]=='0' && num[m]=='0' && aux==1)
			{
			centenas(num,uni,dec,cen,u,u2,d,c);
			strcpy(cmil,strcat(cmil,cen));
			aux=2;
			}
		}
	if(num[dm]=='0' && num[m]=='1' && aux==1)
	{
		strcpy(cmil,"quinientos un mil ");
		if(num[dm]=='0' && num[m]=='1' && num[c]=='0' && num[d]=='0' && num[u]=='0' && aux==1)
		{
			strcpy(cmil,"quinientos un mil");
			aux=2;
		}

		if(num[dm]=='0' && num[m]=='1' && num[c]=='0' && num[d]=='0' && aux==1)
		{
			strcpy(cmil,"quinientos un mil ");
			unidades(num,uni,u);
			strcpy(cmil,strcat(cmil,uni));
			aux=2;
		}
		if(num[dm]=='0' && num[m]=='1' && num[c]=='0' && aux==1)
		{
			strcpy(cmil,"quinientos un mil ");
			decenas(num,uni,dec,u,u2,d);
			strcpy(cmil,strcat(cmil,dec));
			aux=2;
		}
		if(num[dm]=='0' && num[m]=='1' && aux==1)
		{
			strcpy(cmil,"quinientos un mil ");
			centenas(num,uni,dec,cen,u,u2,d,c);
			strcpy(cmil,strcat(cmil,cen));
			aux=2;
		}
	}
		if(num[dm]=='0' && aux==1)
		{
			strcpy(cmil,"quinientos ");
			miles(num,uni,dec,cen,mil,u,u2,d,c,m);
			strcpy(cmil,strcat(cmil,mil));
			aux=2;
		}
		if(aux==1)
		{
		strcpy(cmil,"quinientos ");
		decenasmil(num,uni,dec,cen,mil,dmil,u,u2,d,c,m,dm);
		strcpy(cmil,strcat(cmil,dmil));
		aux=2;
		}
	}

	if(num[cm]=='6')
	{
		if(num[dm]=='0' && num[m]=='0')
		{
			if(num[dm]=='0' && num[m]=='0' && num[c]=='0' && num[d]=='0' && num[u]=='0')
			{
			strcpy(cmil,"seiscientos mil");
			aux=2;
			}
			else
			strcpy(cmil,"seiscientos mil ");
			if(num[dm]=='0' && num[m]=='0' && num[c]=='0' && num[d]=='0' && aux==1)
			{
			unidades(num,uni,u);
			strcpy(cmil,strcat(cmil,uni));
			aux=2;
			}
			if(num[dm]=='0' && num[m]=='0' && num[c]=='0' && aux==1)
			{
			decenas(num,uni,dec,u,u2,d);
			strcpy(cmil,strcat(cmil,dec));
			aux=2;
			}
			if(num[dm]=='0' && num[m]=='0' && aux==1)
			{
			centenas(num,uni,dec,cen,u,u2,d,c);
			strcpy(cmil,strcat(cmil,cen));
			aux=2;
			}
		}
	if(num[dm]=='0' && num[m]=='1' && aux==1)
	{
		strcpy(cmil,"seiscientos un mil ");
		if(num[dm]=='0' && num[m]=='1' && num[c]=='0' && num[d]=='0' && num[u]=='0' && aux==1)
		{
			strcpy(cmil,"seiscientos un mil");
			aux=2;
		}

		if(num[dm]=='0' && num[m]=='1' && num[c]=='0' && num[d]=='0' && aux==1)
		{
			strcpy(cmil,"seiscientos un mil ");
			unidades(num,uni,u);
			strcpy(cmil,strcat(cmil,uni));
			aux=2;
		}
		if(num[dm]=='0' && num[m]=='1' && num[c]=='0' && aux==1)
		{
			strcpy(cmil,"seiscientos un mil ");
			decenas(num,uni,dec,u,u2,d);
			strcpy(cmil,strcat(cmil,dec));
			aux=2;
		}
		if(num[dm]=='0' && num[m]=='1' && aux==1)
		{
			strcpy(cmil,"seiscientos un mil ");
			centenas(num,uni,dec,cen,u,u2,d,c);
			strcpy(cmil,strcat(cmil,cen));
			aux=2;
		}
	}
		if(num[dm]=='0' && aux==1)
		{
			strcpy(cmil,"seiscientos ");
			miles(num,uni,dec,cen,mil,u,u2,d,c,m);
			strcpy(cmil,strcat(cmil,mil));
			aux=2;
		}
		if(aux==1)
		{
		strcpy(cmil,"seiscientos ");
		decenasmil(num,uni,dec,cen,mil,dmil,u,u2,d,c,m,dm);
		strcpy(cmil,strcat(cmil,dmil));
		aux=2;
		}
	}

	if(num[cm]=='7')
	{
		if(num[dm]=='0' && num[m]=='0')
		{
			if(num[dm]=='0' && num[m]=='0' && num[c]=='0' && num[d]=='0' && num[u]=='0')
			{
			strcpy(cmil,"setecientos mil");
			aux=2;
			}
			else
			strcpy(cmil,"setecientos mil ");
			if(num[dm]=='0' && num[m]=='0' && num[c]=='0' && num[d]=='0' && aux==1)
			{
			unidades(num,uni,u);
			strcpy(cmil,strcat(cmil,uni));
			aux=2;
			}
			if(num[dm]=='0' && num[m]=='0' && num[c]=='0' && aux==1)
			{
			decenas(num,uni,dec,u,u2,d);
			strcpy(cmil,strcat(cmil,dec));
			aux=2;
			}
			if(num[dm]=='0' && num[m]=='0' && aux==1)
			{
			centenas(num,uni,dec,cen,u,u2,d,c);
			strcpy(cmil,strcat(cmil,cen));
			aux=2;
			}
		}
	if(num[dm]=='0' && num[m]=='1' && aux==1)
	{
		strcpy(cmil,"setecientos un mil ");
		if(num[dm]=='0' && num[m]=='1' && num[c]=='0' && num[d]=='0' && num[u]=='0' && aux==1)
		{
			strcpy(cmil,"setecientos un mil");
			aux=2;
		}

		if(num[dm]=='0' && num[m]=='1' && num[c]=='0' && num[d]=='0' && aux==1)
		{
			strcpy(cmil,"setecientos un mil ");
			unidades(num,uni,u);
			strcpy(cmil,strcat(cmil,uni));
			aux=2;
		}
		if(num[dm]=='0' && num[m]=='1' && num[c]=='0' && aux==1)
		{
			strcpy(cmil,"setecientos un mil ");
			decenas(num,uni,dec,u,u2,d);
			strcpy(cmil,strcat(cmil,dec));
			aux=2;
		}
		if(num[dm]=='0' && num[m]=='1' && aux==1)
		{
			strcpy(cmil,"setecientos un mil ");
			centenas(num,uni,dec,cen,u,u2,d,c);
			strcpy(cmil,strcat(cmil,cen));
			aux=2;
		}
	}
		if(num[dm]=='0' && aux==1)
		{
			strcpy(cmil,"setecientos ");
			miles(num,uni,dec,cen,mil,u,u2,d,c,m);
			strcpy(cmil,strcat(cmil,mil));
			aux=2;
		}
		if(aux==1)
		{
		strcpy(cmil,"setecientos ");
		decenasmil(num,uni,dec,cen,mil,dmil,u,u2,d,c,m,dm);
		strcpy(cmil,strcat(cmil,dmil));
		aux=2;
		}
	}

	if(num[cm]=='8')
	{
		if(num[dm]=='0' && num[m]=='0')
		{
			if(num[dm]=='0' && num[m]=='0' && num[c]=='0' && num[d]=='0' && num[u]=='0')
			{
			strcpy(cmil,"ochocientos mil");
			aux=2;
			}
			else
			strcpy(cmil,"ochocientos mil ");
			if(num[dm]=='0' && num[m]=='0' && num[c]=='0' && num[d]=='0' && aux==1)
			{
			unidades(num,uni,u);
			strcpy(cmil,strcat(cmil,uni));
			aux=2;
			}
			if(num[dm]=='0' && num[m]=='0' && num[c]=='0' && aux==1)
			{
			decenas(num,uni,dec,u,u2,d);
			strcpy(cmil,strcat(cmil,dec));
			aux=2;
			}
			if(num[dm]=='0' && num[m]=='0' && aux==1)
			{
			centenas(num,uni,dec,cen,u,u2,d,c);
			strcpy(cmil,strcat(cmil,cen));
			aux=2;
			}
		}
	if(num[dm]=='0' && num[m]=='1' && aux==1)
	{
		strcpy(cmil,"ochocientos un mil ");
		if(num[dm]=='0' && num[m]=='1' && num[c]=='0' && num[d]=='0' && num[u]=='0' && aux==1)
		{
			strcpy(cmil,"ochocientos un mil");
			aux=2;
		}

		if(num[dm]=='0' && num[m]=='1' && num[c]=='0' && num[d]=='0' && aux==1)
		{
			strcpy(cmil,"ochocientos un mil ");
			unidades(num,uni,u);
			strcpy(cmil,strcat(cmil,uni));
			aux=2;
		}
		if(num[dm]=='0' && num[m]=='1' && num[c]=='0' && aux==1)
		{
			strcpy(cmil,"ochocientos un mil ");
			decenas(num,uni,dec,u,u2,d);
			strcpy(cmil,strcat(cmil,dec));
			aux=2;
		}
		if(num[dm]=='0' && num[m]=='1' && aux==1)
		{
			strcpy(cmil,"ochocientos un mil ");
			centenas(num,uni,dec,cen,u,u2,d,c);
			strcpy(cmil,strcat(cmil,cen));
			aux=2;
		}
	}
		if(num[dm]=='0' && aux==1)
		{
			strcpy(cmil,"ochocientos ");
			miles(num,uni,dec,cen,mil,u,u2,d,c,m);
			strcpy(cmil,strcat(cmil,mil));
			aux=2;
		}
		if(aux==1)
		{
		strcpy(cmil,"ochocientos ");
		decenasmil(num,uni,dec,cen,mil,dmil,u,u2,d,c,m,dm);
		strcpy(cmil,strcat(cmil,dmil));
		aux=2;
		}
	}

	if(num[cm]=='9')
	{
		if(num[dm]=='0' && num[m]=='0')
		{
			if(num[dm]=='0' && num[m]=='0' && num[c]=='0' && num[d]=='0' && num[u]=='0')
			{
			strcpy(cmil,"novecientos mil");
			aux=2;
			}
			else
			strcpy(cmil,"novecientos mil ");
			if(num[dm]=='0' && num[m]=='0' && num[c]=='0' && num[d]=='0' && aux==1)
			{
			unidades(num,uni,u);
			strcpy(cmil,strcat(cmil,uni));
			aux=2;
			}
			if(num[dm]=='0' && num[m]=='0' && num[c]=='0' && aux==1)
			{
			decenas(num,uni,dec,u,u2,d);
			strcpy(cmil,strcat(cmil,dec));
			aux=2;
			}
			if(num[dm]=='0' && num[m]=='0' && aux==1)
			{
			centenas(num,uni,dec,cen,u,u2,d,c);
			strcpy(cmil,strcat(cmil,cen));
			aux=2;
			}
		}
	if(num[dm]=='0' && num[m]=='1' && aux==1)
	{
		strcpy(cmil,"novecientos un mil ");
		if(num[dm]=='0' && num[m]=='1' && num[c]=='0' && num[d]=='0' && num[u]=='0' && aux==1)
		{
			strcpy(cmil,"novecientos un mil");
			aux=2;
		}

		if(num[dm]=='0' && num[m]=='1' && num[c]=='0' && num[d]=='0' && aux==1)
		{
			strcpy(cmil,"novecientos un mil ");
			unidades(num,uni,u);
			strcpy(cmil,strcat(cmil,uni));
			aux=2;
		}
		if(num[dm]=='0' && num[m]=='1' && num[c]=='0' && aux==1)
		{
			strcpy(cmil,"novecientos un mil ");
			decenas(num,uni,dec,u,u2,d);
			strcpy(cmil,strcat(cmil,dec));
			aux=2;
		}
		if(num[dm]=='0' && num[m]=='1' && aux==1)
		{
			strcpy(cmil,"novecientos un mil ");
			centenas(num,uni,dec,cen,u,u2,d,c);
			strcpy(cmil,strcat(cmil,cen));
			aux=2;
		}
	}
		if(num[dm]=='0' && aux==1)
		{
			strcpy(cmil,"novecientos ");
			miles(num,uni,dec,cen,mil,u,u2,d,c,m);
			strcpy(cmil,strcat(cmil,mil));
			aux=2;
		}
		if(aux==1)
		{
		strcpy(cmil,"novecientos ");
		decenasmil(num,uni,dec,cen,mil,dmil,u,u2,d,c,m,dm);
		strcpy(cmil,strcat(cmil,dmil));
		aux=2;
		}
	}


return cmil[100];
}

millar(char num[6],char uni[100],char dec[100],char cen[100],char mil[100],char dmil[100],char cmil[100],char mill[100],int u,int u2,int d,int c,int m,int dm,int cm,int ml)
//Funcion que convierte del 1 000 000 al 9 999 999
{
int aux=1;
	if(num[ml]=='1')
	{
		if(num[cm]=='0' && num[dm]=='0' && num[m]=='0' && num[c]=='0' && num[d]=='0' && num[u]=='0' && aux==1)
		{
		strcpy(mill,"Un millon");
		aux=2;
		}
		else
		strcpy(mill,"Un millon ");
		if(num[cm]=='0' && num[dm]=='0' && num[m]=='0' && num[c]=='0' && num[d]=='0' && aux==1)
		{
		unidades(num,uni,u);
		strcpy(mill,strcat(mill,uni));
		aux=2;
		}
		if(num[cm]=='0' && num[dm]=='0' && num[m]=='0' && num[c]=='0' && aux==1)
		{
		decenas(num,uni,dec,u,u2,d);
		strcpy(mill,strcat(mill,dec));
		aux=2;
		}
		if(num[cm]=='0' && num[dm]=='0' && num[m]=='0' && aux==1)
		{
		centenas(num,uni,dec,cen,u,u2,d,c);
		strcpy(mill,strcat(mill,cen));
		aux=2;
		}
		if(num[cm]=='0' && num[dm]=='0' && aux==1)
		{
		miles(num,uni,dec,cen,mil,u,u2,d,c,m);
		strcpy(mill,strcat(mill,mil));
		aux=2;
		}
		if(num[cm]=='0' && aux==1)
		{
		decenasmil(num,uni,dec,cen,mil,dmil,u,u2,d,c,m,dm);
		strcpy(mill,strcat(mill,dmil));
		aux=2;
		}
		if(aux==1)
		{
		centenasmil(num,uni,dec,cen,mil,dmil,cmil,u,u2,d,c,m,dm,cm);
		strcpy(mill,strcat(mill,cmil));
		aux=2;
		}
	}



	if(num[ml]=='2')
	{
		if(num[cm]=='0' && num[dm]=='0' && num[m]=='0' && num[c]=='0' && num[d]=='0' && num[u]=='0' && aux==1)
		{
		strcpy(mill,"Dos millones");
		aux=2;
		}
		else
		strcpy(mill,"Dos millones ");
		if(num[cm]=='0' && num[dm]=='0' && num[m]=='0' && num[c]=='0' && num[d]=='0' && aux==1)
		{
		unidades(num,uni,u);
		strcpy(mill,strcat(mill,uni));
		aux=2;
		}
		if(num[cm]=='0' && num[dm]=='0' && num[m]=='0' && num[c]=='0' && aux==1)
		{
		decenas(num,uni,dec,u,u2,d);
		strcpy(mill,strcat(mill,dec));
		aux=2;
		}
		if(num[cm]=='0' && num[dm]=='0' && num[m]=='0' && aux==1)
		{
		centenas(num,uni,dec,cen,u,u2,d,c);
		strcpy(mill,strcat(mill,cen));
		aux=2;
		}
		if(num[cm]=='0' && num[dm]=='0' && aux==1)
		{
		miles(num,uni,dec,cen,mil,u,u2,d,c,m);
		strcpy(mill,strcat(mill,mil));
		aux=2;
		}
		if(num[cm]=='0' && aux==1)
		{
		decenasmil(num,uni,dec,cen,mil,dmil,u,u2,d,c,m,dm);
		strcpy(mill,strcat(mill,dmil));
		aux=2;
		}
		if(aux==1)
		{
		centenasmil(num,uni,dec,cen,mil,dmil,cmil,u,u2,d,c,m,dm,cm);
		strcpy(mill,strcat(mill,cmil));
		aux=2;
		}
	}

	if(num[ml]=='3')
	{
		if(num[cm]=='0' && num[dm]=='0' && num[m]=='0' && num[c]=='0' && num[d]=='0' && num[u]=='0' && aux==1)
		{
		strcpy(mill,"Tres millones");
		aux=2;
		}
		else
		strcpy(mill,"Tres millones ");
		if(num[cm]=='0' && num[dm]=='0' && num[m]=='0' && num[c]=='0' && num[d]=='0' && aux==1)
		{
		unidades(num,uni,u);
		strcpy(mill,strcat(mill,uni));
		aux=2;
		}
		if(num[cm]=='0' && num[dm]=='0' && num[m]=='0' && num[c]=='0' && aux==1)
		{
		decenas(num,uni,dec,u,u2,d);
		strcpy(mill,strcat(mill,dec));
		aux=2;
		}
		if(num[cm]=='0' && num[dm]=='0' && num[m]=='0' && aux==1)
		{
		centenas(num,uni,dec,cen,u,u2,d,c);
		strcpy(mill,strcat(mill,cen));
		aux=2;
		}
		if(num[cm]=='0' && num[dm]=='0' && aux==1)
		{
		miles(num,uni,dec,cen,mil,u,u2,d,c,m);
		strcpy(mill,strcat(mill,mil));
		aux=2;
		}
		if(num[cm]=='0' && aux==1)
		{
		decenasmil(num,uni,dec,cen,mil,dmil,u,u2,d,c,m,dm);
		strcpy(mill,strcat(mill,dmil));
		aux=2;
		}
		if(aux==1)
		{
		centenasmil(num,uni,dec,cen,mil,dmil,cmil,u,u2,d,c,m,dm,cm);
		strcpy(mill,strcat(mill,cmil));
		aux=2;
		}
	}

	if(num[ml]=='4')
	{
		if(num[cm]=='0' && num[dm]=='0' && num[m]=='0' && num[c]=='0' && num[d]=='0' && num[u]=='0' && aux==1)
		{
		strcpy(mill,"Cuatro millones");
		aux=2;
		}
		else
		strcpy(mill,"Cuatro millones ");
		if(num[cm]=='0' && num[dm]=='0' && num[m]=='0' && num[c]=='0' && num[d]=='0' && aux==1)
		{
		unidades(num,uni,u);
		strcpy(mill,strcat(mill,uni));
		aux=2;
		}
		if(num[cm]=='0' && num[dm]=='0' && num[m]=='0' && num[c]=='0' && aux==1)
		{
		decenas(num,uni,dec,u,u2,d);
		strcpy(mill,strcat(mill,dec));
		aux=2;
		}
		if(num[cm]=='0' && num[dm]=='0' && num[m]=='0' && aux==1)
		{
		centenas(num,uni,dec,cen,u,u2,d,c);
		strcpy(mill,strcat(mill,cen));
		aux=2;
		}
		if(num[cm]=='0' && num[dm]=='0' && aux==1)
		{
		miles(num,uni,dec,cen,mil,u,u2,d,c,m);
		strcpy(mill,strcat(mill,mil));
		aux=2;
		}
		if(num[cm]=='0' && aux==1)
		{
		decenasmil(num,uni,dec,cen,mil,dmil,u,u2,d,c,m,dm);
		strcpy(mill,strcat(mill,dmil));
		aux=2;
		}
		if(aux==1)
		{
		centenasmil(num,uni,dec,cen,mil,dmil,cmil,u,u2,d,c,m,dm,cm);
		strcpy(mill,strcat(mill,cmil));
		aux=2;
		}
	}

	if(num[ml]=='5')
	{
		if(num[cm]=='0' && num[dm]=='0' && num[m]=='0' && num[c]=='0' && num[d]=='0' && num[u]=='0' && aux==1)
		{
		strcpy(mill,"Cinco millones");
		aux=2;
		}
		else
		strcpy(mill,"Cinco millones ");
		if(num[cm]=='0' && num[dm]=='0' && num[m]=='0' && num[c]=='0' && num[d]=='0' && aux==1)
		{
		unidades(num,uni,u);
		strcpy(mill,strcat(mill,uni));
		aux=2;
		}
		if(num[cm]=='0' && num[dm]=='0' && num[m]=='0' && num[c]=='0' && aux==1)
		{
		decenas(num,uni,dec,u,u2,d);
		strcpy(mill,strcat(mill,dec));
		aux=2;
		}
		if(num[cm]=='0' && num[dm]=='0' && num[m]=='0' && aux==1)
		{
		centenas(num,uni,dec,cen,u,u2,d,c);
		strcpy(mill,strcat(mill,cen));
		aux=2;
		}
		if(num[cm]=='0' && num[dm]=='0' && aux==1)
		{
		miles(num,uni,dec,cen,mil,u,u2,d,c,m);
		strcpy(mill,strcat(mill,mil));
		aux=2;
		}
		if(num[cm]=='0' && aux==1)
		{
		decenasmil(num,uni,dec,cen,mil,dmil,u,u2,d,c,m,dm);
		strcpy(mill,strcat(mill,dmil));
		aux=2;
		}
		if(aux==1)
		{
		centenasmil(num,uni,dec,cen,mil,dmil,cmil,u,u2,d,c,m,dm,cm);
		strcpy(mill,strcat(mill,cmil));
		aux=2;
		}
	}

	if(num[ml]=='6')
	{
		if(num[cm]=='0' && num[dm]=='0' && num[m]=='0' && num[c]=='0' && num[d]=='0' && num[u]=='0' && aux==1)
		{
		strcpy(mill,"Seis millones");
		aux=2;
		}
		else
		strcpy(mill,"Seis millones ");
		if(num[cm]=='0' && num[dm]=='0' && num[m]=='0' && num[c]=='0' && num[d]=='0' && aux==1)
		{
		unidades(num,uni,u);
		strcpy(mill,strcat(mill,uni));
		aux=2;
		}
		if(num[cm]=='0' && num[dm]=='0' && num[m]=='0' && num[c]=='0' && aux==1)
		{
		decenas(num,uni,dec,u,u2,d);
		strcpy(mill,strcat(mill,dec));
		aux=2;
		}
		if(num[cm]=='0' && num[dm]=='0' && num[m]=='0' && aux==1)
		{
		centenas(num,uni,dec,cen,u,u2,d,c);
		strcpy(mill,strcat(mill,cen));
		aux=2;
		}
		if(num[cm]=='0' && num[dm]=='0' && aux==1)
		{
		miles(num,uni,dec,cen,mil,u,u2,d,c,m);
		strcpy(mill,strcat(mill,mil));
		aux=2;
		}
		if(num[cm]=='0' && aux==1)
		{
		decenasmil(num,uni,dec,cen,mil,dmil,u,u2,d,c,m,dm);
		strcpy(mill,strcat(mill,dmil));
		aux=2;
		}
		if(aux==1)
		{
		centenasmil(num,uni,dec,cen,mil,dmil,cmil,u,u2,d,c,m,dm,cm);
		strcpy(mill,strcat(mill,cmil));
		aux=2;
		}
	}

	if(num[ml]=='7')
	{
		if(num[cm]=='0' && num[dm]=='0' && num[m]=='0' && num[c]=='0' && num[d]=='0' && num[u]=='0' && aux==1)
		{
		strcpy(mill,"Siete millones");
		aux=2;
		}
		else
		strcpy(mill,"Siete millones ");
		if(num[cm]=='0' && num[dm]=='0' && num[m]=='0' && num[c]=='0' && num[d]=='0' && aux==1)
		{
		unidades(num,uni,u);
		strcpy(mill,strcat(mill,uni));
		aux=2;
		}
		if(num[cm]=='0' && num[dm]=='0' && num[m]=='0' && num[c]=='0' && aux==1)
		{
		decenas(num,uni,dec,u,u2,d);
		strcpy(mill,strcat(mill,dec));
		aux=2;
		}
		if(num[cm]=='0' && num[dm]=='0' && num[m]=='0' && aux==1)
		{
		centenas(num,uni,dec,cen,u,u2,d,c);
		strcpy(mill,strcat(mill,cen));
		aux=2;
		}
		if(num[cm]=='0' && num[dm]=='0' && aux==1)
		{
		miles(num,uni,dec,cen,mil,u,u2,d,c,m);
		strcpy(mill,strcat(mill,mil));
		aux=2;
		}
		if(num[cm]=='0' && aux==1)
		{
		decenasmil(num,uni,dec,cen,mil,dmil,u,u2,d,c,m,dm);
		strcpy(mill,strcat(mill,dmil));
		aux=2;
		}
		if(aux==1)
		{
		centenasmil(num,uni,dec,cen,mil,dmil,cmil,u,u2,d,c,m,dm,cm);
		strcpy(mill,strcat(mill,cmil));
		aux=2;
		}
	}

	if(num[ml]=='8')
	{
		if(num[cm]=='0' && num[dm]=='0' && num[m]=='0' && num[c]=='0' && num[d]=='0' && num[u]=='0' && aux==1)
		{
		strcpy(mill,"Ocho millones");
		aux=2;
		}
		else
		strcpy(mill,"Ocho millones ");
		if(num[cm]=='0' && num[dm]=='0' && num[m]=='0' && num[c]=='0' && num[d]=='0' && aux==1)
		{
		unidades(num,uni,u);
		strcpy(mill,strcat(mill,uni));
		aux=2;
		}
		if(num[cm]=='0' && num[dm]=='0' && num[m]=='0' && num[c]=='0' && aux==1)
		{
		decenas(num,uni,dec,u,u2,d);
		strcpy(mill,strcat(mill,dec));
		aux=2;
		}
		if(num[cm]=='0' && num[dm]=='0' && num[m]=='0' && aux==1)
		{
		centenas(num,uni,dec,cen,u,u2,d,c);
		strcpy(mill,strcat(mill,cen));
		aux=2;
		}
		if(num[cm]=='0' && num[dm]=='0' && aux==1)
		{
		miles(num,uni,dec,cen,mil,u,u2,d,c,m);
		strcpy(mill,strcat(mill,mil));
		aux=2;
		}
		if(num[cm]=='0' && aux==1)
		{
		decenasmil(num,uni,dec,cen,mil,dmil,u,u2,d,c,m,dm);
		strcpy(mill,strcat(mill,dmil));
		aux=2;
		}
		if(aux==1)
		{
		centenasmil(num,uni,dec,cen,mil,dmil,cmil,u,u2,d,c,m,dm,cm);
		strcpy(mill,strcat(mill,cmil));
		aux=2;
		}
	}

	if(num[ml]=='9')
	{
		if(num[cm]=='0' && num[dm]=='0' && num[m]=='0' && num[c]=='0' && num[d]=='0' && num[u]=='0' && aux==1)
		{
		strcpy(mill,"Nueve millones");
		aux=2;
		}
		else
		strcpy(mill,"Nueve millones ");
		if(num[cm]=='0' && num[dm]=='0' && num[m]=='0' && num[c]=='0' && num[d]=='0' && aux==1)
		{
		unidades(num,uni,u);
		strcpy(mill,strcat(mill,uni));
		aux=2;
		}
		if(num[cm]=='0' && num[dm]=='0' && num[m]=='0' && num[c]=='0' && aux==1)
		{
		decenas(num,uni,dec,u,u2,d);
		strcpy(mill,strcat(mill,dec));
		aux=2;
		}
		if(num[cm]=='0' && num[dm]=='0' && num[m]=='0' && aux==1)
		{
		centenas(num,uni,dec,cen,u,u2,d,c);
		strcpy(mill,strcat(mill,cen));
		aux=2;
		}
		if(num[cm]=='0' && num[dm]=='0' && aux==1)
		{
		miles(num,uni,dec,cen,mil,u,u2,d,c,m);
		strcpy(mill,strcat(mill,mil));
		aux=2;
		}
		if(num[cm]=='0' && aux==1)
		{
		decenasmil(num,uni,dec,cen,mil,dmil,u,u2,d,c,m,dm);
		strcpy(mill,strcat(mill,dmil));
		aux=2;
		}
		if(aux==1)
		{
		centenasmil(num,uni,dec,cen,mil,dmil,cmil,u,u2,d,c,m,dm,cm);
		strcpy(mill,strcat(mill,cmil));
		aux=2;
		}
	}
return mill[100];
}

void alfanumerico()			// funcion principal
{
char num[6],uni[100],dec[100],cen[100],mil[100],dmil[100],cmil[100],mill[100];
int u,u2,d,c,m,dm,cm,ml,longitud=1,resp;
resp=1;
u=0;u2=0;d=0;c=0;m=0;dm=0;cm=0;ml=0;longitud=0;
clrscr();
textbackground(1);
textcolor(15);
do
{
textbackground(1);
textcolor(15);
switch(resp)
{
case 1:
clrscr();
textbackground(0);
textcolor(WHITE);
cprintf("                                                 Francisco Javier Herrera Vargas");		//nombre programa
cprintf("Cambiar un numero a letra                                                       ");
cprintf("                                                                                ");

	textbackground(1);
	textcolor(15);
	gotoxy(3,25);cprintf("Escriba el numero aqui: ");
	scanf("%s",&num);
	longitud=strlen(num);
	if(longitud>=8)
	printf("\n\n  Muchos millones el maximo es el 9 999 999");
	else
	{
	if(longitud==1)
	{
		u=0;
		unidades(num,uni,u);
		textbackground(1);
		textcolor(14);
		gotoxy(3,46);cprintf("%s",uni);
		printf("\n                                                                                ");
	}
	if(longitud==2)
	{
		u=1;u2=1;d=0;
		decenas(num,uni,dec,u,u2,d);
		textbackground(1);
		textcolor(14);
		gotoxy(3,46);cprintf("%s",dec);
		printf("\n                                                                                ");
	}
	if(longitud==3)
	{
		u=2;u2=2;d=1;c=0;
		centenas(num,uni,dec,cen,u,u2,d,c);
		textbackground(1);
		textcolor(14);
		gotoxy(3,46);cprintf("%s",cen);
		printf("\n                                                                                ");
	}
	if(longitud==4)
	{
		u=3;u2=3;d=2;c=1;m=0;
		miles(num,uni,dec,cen,mil,u,u2,d,c,m);
		textbackground(1);
		textcolor(14);
		gotoxy(3,46);cprintf("%s",mil);
		printf("\n                                                                                ");
	}
	if(longitud==5)
	{
		u=4;u2=4;d=3;c=2;m=1;dm=0;
		decenasmil(num,uni,dec,cen,mil,dmil,u,u2,d,c,m,dm);
		textbackground(1);
		textcolor(14);
		gotoxy(3,46);cprintf("%s",dmil);
		printf("\n                                                                                ");
	}
	if(longitud==6)
	{
		u=5;u2=5;d=4;c=3;m=2;dm=1;cm=0;
		centenasmil(num,uni,dec,cen,mil,dmil,cmil,u,u2,d,c,m,dm,cm);
		textbackground(1);
		textcolor(14);
		gotoxy(3,46);cprintf("%s",cmil);
		printf("\n                                                                                ");
	}
	if(longitud==7)
	{
		u=6;u2=6;d=5;c=4;m=3;dm=2;cm=1;ml=0;
		millar(num,uni,dec,cen,mil,dmil,cmil,mill,u,u2,d,c,m,dm,cm,ml);
		textbackground(1);
		textcolor(14);
		gotoxy(3,46);cprintf("%s",mill);
		printf("\n                                                                                ");
	}
	}

textbackground(0);
textcolor(WHITE);
gotoxy(1,48);cprintf("                                                                                ");
gotoxy(1,49);cprintf("Quiere escribir otro numero Si (1) No (2)                                       ");
cprintf("                                                            Elije una opcion: ");
scanf("%d",&resp);
cprintf("                                                                                             ");
textbackground(1);
textcolor(15);
break;
case 2:
break;
default:
gotoxy(1,50);printf("\nSolo 1 o 2: ");
scanf("%d",&resp);
}
}
while(resp!=2);
}

void suma()  					//funcion suma n=numero de numeros
{                       			//principio suma
int res=0,cont,num,n,sn;			//variables reslutado, contador,numero
  sn=1;
clrscr();
textbackground(1);
textcolor(15);

  do
  {
  res=0;
  switch(sn)
  {
  case 1:
  clrscr();                             	//limpia pantalla
  textbackground(0);
  textcolor(WHITE);
  cprintf("                                                 Francisco Javier Herrera Vargas");		//nombre programa
  cprintf("La suma de n numeros                                                            ");
  textbackground(1);
  textcolor(15);
  gotoxy(3,10);cprintf("Cuantos numeros quiere sumar: "); //cantidad de numeros
  scanf("%d",&n);                      		//captura cantidad de numeros
  for(cont=0;cont<n;cont++)    			//ciclo para la cantidad de numeros
  {                            			//principio for
  cprintf("\n  Numero %d: ",cont+1);   		//imprime el numero de los numeros
  scanf("%d",&num);           			//captura el numero
  res=res+num;                			//realiza la suma
  }                           			//fin for
gotoxy(3,46);cprintf("El resultado es: "); 		//imprime el resultado de la suma
textbackground(1);
textcolor(14);
cprintf("%d",res);
textbackground(0);
textcolor(15);
gotoxy(1,48);cprintf("                                                                                 ");
gotoxy(1,49);cprintf("Deseas hacer otra suma Si (1) No (2)                         ");
cprintf("                                                                             Elije una opcion: ");
scanf("%d",&sn);
textbackground(1);
textcolor(15);
break;
case 2:
break;
default:
printf("\n\nSolo 1 o 2: ");
scanf("%d",&sn);
}
}
while(sn!=2);
}          			 		//fin suma

void resta() 					//funcion resta  primer num. y segundo num.
{                             			//principio resta
int res,num1,num2,sn;		      		//variables resultado
sn=1;
clrscr();
textbackground(1);
textcolor(15);

do
{
switch(sn)
{
case 1:
clrscr();                             		//limpia pantalla
textbackground(0);
textcolor(WHITE);
cprintf("                                                 Francisco Javier Herrera Vargas");		//nombre programa
cprintf("La resta de dos numeros                                                         ");    		//nombre del programa
res=0;
textbackground(1);
textcolor(15);
gotoxy(3,10);cprintf("Numero 1: ");scanf("%d",&num1);	//imprime y captura primer numero
gotoxy(3,12);cprintf("Numero 2: ");scanf("%d",&num2);    	//imprime y captura segundo numero
res=num1-num2;                			//realiza la resta
gotoxy(3,46);cprintf("El resultado es: ");  		//imprime el resultado
textbackground(1);
textcolor(14);
cprintf("%d",res);
textbackground(0);
textcolor(15);
gotoxy(1,48);cprintf("                                                                                 ");
gotoxy(1,49);cprintf("Deseas hacer otra resta Si (1) No (2)                         ");
cprintf("                                                                            Elije una opcion: ");
scanf("%d",&sn);
textbackground(1);
textcolor(15);
break;
case 2:
break;
default:
printf("\n\nSolo 1 o 2: ");
scanf("%d",&sn);
}
}
while(sn!=2);
}                              			//fin resta

void multi()              			//funcion multi n es el numero de numeros
{                              //principio multi
float res,num;               //varianles flotantes resultado, numero
int cont,sn,n;                      //variable entero contador
sn=1;
clrscr();
textbackground(1);
textcolor(15);

do
{
res=1;
switch(sn)
{
case 1:
clrscr();                             		//limpia pantalla
  textbackground(0);
  textcolor(WHITE);
  cprintf("                                                 Francisco Javier Herrera Vargas");		//nombre programa
  cprintf("La multiplicacion de n numeros                                                  ");   		//nombre del programa
textbackground(1);
textcolor(15);
gotoxy(3,10);cprintf("\n\nCuantos numeros quieres multiplicar: ");  //cantidad de numeros
scanf("%d",&n);			      //captura esa cantidad
  for(cont=0;cont<n;cont++)      //ciclo para la cantidad de numeros
  {                              //principio for
  printf("\n  Numero %d: ",cont+1);     //imprime el numero de numeros
  scanf("%f",&num);              //captura el numero que se va a multiplicar
  res=res*num;                   //hace la multiplicacion
  }                              //end for
gotoxy(3,46);cprintf("El resultado es: ");    //imprime el resultado
textbackground(1);
textcolor(14);
cprintf("%f",res);
textbackground(0);
textcolor(15);
gotoxy(1,48);cprintf("                                                                                 ");
gotoxy(1,49);cprintf("Deseas hacer otra multiplicacion Si (1) No (2)                         ");
cprintf("                                                                    Elije una opcion: ");
scanf("%d",&sn);
textbackground(1);
textcolor(15);
break;
case 2:
break;
default:
printf("\n\nSolo 1 o 2");
scanf("%d",&sn);
}
}
while(sn!=2);
}                              //fin multi

void division()  //funcion division  numeros flotantes
{                             //principio division
float num,denom,res;                        //variables flotantes numerador, denominador
int sn;
sn=1;
clrscr();
textbackground(1);
textcolor(15);

do
{
res=1;
switch(sn)
{
case 1:
clrscr();						//limpia pantalla
textbackground(0);
textcolor(WHITE);
cprintf("                                                 Francisco Javier Herrera Vargas");		//nombre programa
cprintf("La division de dos numeros                                                      ");   		//nombre del programa
textbackground(1);
textcolor(WHITE);
gotoxy(3,10);cprintf("Numero 1: ");scanf("%f",&num); //imprime y captura el numerador
gotoxy(3,12);cprintf("Numero 2: ");scanf("%f",&denom);   //imprime y captura el denominador
if(denom==0)                  // condicion por si el denominador es 0
{
textbackground(1);
textcolor(14);
gotoxy(3,46);cprintf("Imposible resolver la division"); //mensaje de error
}
  else                          //si no cumple la condicion
  {                             //principio else
  res=num/denom;                //realiza la divison
  textbackground(1);
  textcolor(15);
  gotoxy(3,46);cprintf("El resultado es: ");   //imprime el resultado
  textbackground(1);
  textcolor(14);
  cprintf("%f",res);
  }                             //fin else
textbackground(0);
textcolor(15);
gotoxy(1,48);cprintf("                                                                                 ");
gotoxy(1,49);cprintf("Deseas hacer otra division Si (1) No (2)                         ");
cprintf("                                                                         Elije una opcion: ");
scanf("%d",&sn);
textbackground(1);
textcolor(15);

break;
case 2:
break;
default:
printf("\n\nSolo 1 o 2: ");
scanf("%d",&sn);
}
}
while(sn!=2);
}                             //fin division

void tabla()           //funcion tabla, numero
{                             //principio tabla
int cont,num,sn;                     //variable cont contador
sn=1;
clrscr();
textbackground(1);
textcolor(15);
do
{
switch(sn)
{
case 1:
clrscr();                               		//limpia pantalla
textbackground(0);
textcolor(WHITE);
cprintf("                                                 Francisco Javier Herrera Vargas");		//nombre programa
cprintf("Tablas de multiplicar                                                           ");
textbackground(1);
textcolor(WHITE);
gotoxy(3,10);cprintf("De que numero la quieres: ");   		//nombre del programa
scanf("%d",&num);             //captura el numero a calcular
for(cont=0;cont<=10;cont++)   //ciclo que imprime la tabla
{
printf("\n  %d x %d= ",num,cont); //imprime la tabla
textbackground(1);
textcolor(14);
cprintf("%d",num*cont);
}
textbackground(0);
textcolor(15);
gotoxy(1,48);cprintf("                                                                                 ");
gotoxy(1,49);cprintf("Deseas imprimir otra tabla Si (1) No (2)                         ");
cprintf("                                                                         Elije una opcion: ");
scanf("%d",&sn);
textbackground(1);
textcolor(15);

break;
case 2:
break;
default:
printf("\n\nSolo 1 o 2: ");
scanf("%d",&sn);
}
}
while(sn!=2);
}                             //fin tabla

void factorial()     //funcion factorial
{                             //principio factorial
int cont,sn;
long float num;
sn=1;
clrscr();
textbackground(1);
textcolor(15);
do
{
switch(sn)
{
case 1:
clrscr();                              		//limpia pantalla
textbackground(0);
textcolor(WHITE);
cprintf("                                                 Francisco Javier Herrera Vargas");		//nombre programa
cprintf("Factorial                                                                       ");
textbackground(1);
textcolor(WHITE);
gotoxy(3,10);cprintf("Que numero quieres saber: ");   		//nombre del programa
scanf("%lf",&num);		      //captura el numero
long float res=num;             //variable entero contador, resultado se iguala al numero
if(num==0)                    //si el numero es igual a 0
{
gotoxy(3,46);printf("El factorial es ");
textbackground(1);
textcolor(14);
gotoxy(19,46);cprintf("1");
}  //imprime que su factorial es 1
 else                          //sino es iagual a 0 el numero
  {                             //principio else
  for(cont=num-1;cont>1;cont--)  //ciclo para ir multi. desde el numero hasta 1
  res=res*cont;                 //realiza las multiplicaciones
  textbackground(1);
  textcolor(15);
  gotoxy(3,46);cprintf("El factorial es: ");  //imprime el resultado
  textbackground(1);
  textcolor(14);
  cprintf("%lf",res);
  }                             //fin else
textbackground(0);
textcolor(15);
gotoxy(1,48);cprintf("                                                                                 ");
gotoxy(1,49);cprintf("Deseas calcular otro factorial Si (1) No (2)                       ");
cprintf("                                                                         Elije una opcion: ");
scanf("%d",&sn);
textbackground(1);
textcolor(15);

break;
case 2:
break;
default:
printf("\n\nSolo 1 o 2: ");
scanf("%d",&sn);
}
}
while(sn!=2);
}                             //fin factorial

void par()	      //funcion par numero a comparar
{                             //principio par
int num,sn;
sn=1;
clrscr();
textbackground(1);
textcolor(15);
do
{
switch(sn)
{
case 1:
clrscr();
textbackground(0);
textcolor(WHITE);
cprintf("                                                 Francisco Javier Herrera Vargas");		//nombre programa
cprintf("Par o impar                                                                     ");
gotoxy(3,10);printf("Numero: ");scanf("%d",&num);    //imprime y captura el numero a saber
if(num%2==0)                  //si el modulo 2 del num es 0
{
textbackground(1);
textcolor(14);
gotoxy(3,46);cprintf("El numero es par"); // si se cumple el if imprime par
}
else                          //sino se cumple
{
textbackground(1);
textcolor(14);
gotoxy(3,46);cprintf("El numero es impar");  //imprime impar
}
textbackground(0);
textcolor(15);
gotoxy(1,48);cprintf("                                                                                 ");
gotoxy(1,49);cprintf("Deseas revisar otro numero Si (1) No (2)                          ");
cprintf("                                                                         Elije una opcion: ");
scanf("%d",&sn);
textbackground(1);
textcolor(15);

break;
case 2:
break;
default:
printf("\n\nSolo 1 o 2: ");
scanf("%d",&sn);
}
}
while(sn!=2);
}			      //fin par

void promedio()	      //funcion promedio n=numero de numeros
{                             //inicio promedio
int cont,n,sn;                 //variable enteros numero, contador
float res,suma,num;               //variable flotante resultado suma
sn=1;
clrscr();
textbackground(1);
textcolor(15);
do
{
switch(sn)
{
case 1:
clrscr();
textbackground(0);
textcolor(WHITE);
cprintf("                                                 Francisco Javier Herrera Vargas");		//nombre programa
cprintf("Promedio                                                                        ");
textbackground(1);
textcolor(WHITE);
gotoxy(3,10);cprintf("Cantidad de numeros: ");scanf("%d",&n); //imprime y captura la cantidad de numeros
suma=0;
 for(cont=0;cont<n;cont++)     //ciclo numero de numeros
 {                             //incio for
 printf("\n  Numero %d:",cont+1); //imprime el numero de numeros
 scanf("%f",&num);            //captura los numeros
 suma=suma+num;               //realiza la suma de los numeros
 }                            //fin for
res=suma/cont;              //realiza la division entre la suma y la cantidad
gotoxy(3,46);cprintf("El promedio es: "); //imprime el promedio
textbackground(1);
textcolor(14);
cprintf("%f",res);
textbackground(0);
textcolor(15);
gotoxy(1,48);cprintf("                                                                                 ");
gotoxy(1,49);cprintf("Deseas calcular otro promedio Si (1) No (2)                           ");
cprintf("                                                                      Elije una opcion: ");
scanf("%d",&sn);
textbackground(1);
textcolor(15);

break;
case 2:
break;
default:
printf("\n\nSolo 1 o 2: ");
scanf("%d",&sn);
}
}
while(sn!=2);
}                            //fin promedio

void ordena()	//funcion ordena
{                                       //inicia ordena
int i,j,cambio=1,aux,arreglo[100],n,sn=1;   //variables contadores 1 y 2 si hay cambio o no y auxiliar
clrscr();
textbackground(1);
textcolor(15);
do
{
switch(sn)
{
case 1:
clrscr();
textbackground(0);
textcolor(WHITE);
cprintf("                                                 Francisco Javier Herrera Vargas");		//nombre programa
cprintf("Ordenar un arreglo de menor a mayor                                             ");
textbackground(1);
textcolor(WHITE);
gotoxy(3,10);cprintf("De que longitud es el arreglo: ");
scanf("%d",&n);
cambio=1;
gotoxy(3,12);printf("El arreglo desordenado es: \n\n  ");
   for(i=0;i<n;i++)
   {
   scanf("%d",&arreglo[i]);
   printf("  ");
   }
   for(i=0;i<n && cambio==1;i++)
  {
  cambio=0;
    for(j=0;j<n-1;j++)
      {
      if(arreglo[j]>arreglo[j+1])
	{
	cambio=1;
	aux=arreglo[j];
	arreglo[j]=arreglo[j+1];
	arreglo[j+1]=aux;
	}
      }
    }
gotoxy(3,35);cprintf("El arreglo ordenado es: ");
for(i=0;i<n;i++)
{
textbackground(1);
textcolor(14);
gotoxy(3,36+i);cprintf("\n%d",arreglo[i]);
}
textbackground(0);
textcolor(15);
gotoxy(1,48);cprintf("                                                                                 ");
gotoxy(1,49);cprintf("Deseas ordenar otro numero Si (1) No (2)                              ");
cprintf("                                                                      Elije una opcion: ");
scanf("%d",&sn);
textbackground(1);
textcolor(15);
break;
case 2:
break;
default:
printf("\n\nSolo 1 o 2: ");
scanf("%d",&sn);
}
}
while(sn!=2);
}

void piramide()
    {
      const char espacio=' ';
      int altura, fila, blancos, mitad1, mitad2,sn;
      sn=1;
      clrscr();
      textbackground(1);
      textcolor(15);
      do
      {
      switch(sn)
      {
      case 1:
      clrscr();
	textbackground(0);
	textcolor(WHITE);
	cprintf("                                                 Francisco Javier Herrera Vargas");		//nombre programa
	cprintf("Imprimir una piramide de asteriscos                                             ");
      textbackground(1);
      textcolor(WHITE);
      gotoxy(3,10);cprintf("Introduzca la altura de la piramide: ");
      scanf("%d",&altura);
      printf("\n");
      for(fila=1;fila<=altura;fila++)
      {
      for(blancos=1;blancos<=altura-fila;blancos++)
      printf("%c",espacio);
      for(mitad1=1;mitad1<=fila;mitad1++)
      printf("*");
      for(mitad2=fila-1;mitad2>=1;mitad2--)
      printf("*");
      printf("\n");
      }
      textbackground(0);
      textcolor(15);
      gotoxy(1,48);cprintf("                                                                                 ");
      gotoxy(1,49);cprintf("Deseas imprimir otro tabla Si (1) No (2)                              ");
      cprintf("                                                                      Elije una opcion: ");
      scanf("%d",&sn);
      textbackground(1);
      textcolor(15);
break;
case 2:
break;
default:
printf("\n\nSolo 1 o 2: ");
scanf("%d",&sn);
}
}
while(sn!=2);
}

void mayor()
{
int cont,limit=0,num=0,may=0,men=100,sn=1;
sn=1;
clrscr();
textbackground(1);
textcolor(15);
do
{
switch(sn)
{
case 1:
clrscr();
textbackground(0);
textcolor(WHITE);
cprintf("                                                 Francisco Javier Herrera Vargas");		//nombre programa
cprintf("Saber cual numero es mayor o menor                                              ");
gotoxy(3,10);printf("Cantidad de numeros: ");
scanf("%d",&limit);
for(cont=1;cont<=limit;cont++)
 {
  printf("\n");
  printf("  Numero %d: ",cont);
  scanf("%d",&num);
   if(may<num){may=num;}
   if(men>num){men=num;}
 }
gotoxy(3,44);printf("El mayor es: ");
textbackground(1);
textcolor(14);
cprintf("%d",may);
gotoxy(3,46);printf("El menor es: ");
textbackground(1);
textcolor(14);
cprintf("%d",men);
textbackground(0);
textcolor(15);
gotoxy(1,48);cprintf("                                                                                 ");
gotoxy(1,49);cprintf("Deseas revisar mas numeros Si (1) No (2)                                  ");
cprintf("                                                                  Elije una opcion: ");
scanf("%d",&sn);
textbackground(1);
textcolor(15);

break;
case 2:
break;
default:
printf("\n\nSolo 1 o 2: ");
scanf("%d",&sn);
}
}
while(sn!=2);
}

void espacios()
{
int caracter,space,sn;
sn=1;
clrscr();
textbackground(1);
textcolor(15);
do
{
switch(sn)
{
case 1:
clrscr();
textbackground(0);
textcolor(WHITE);
cprintf("                                                 Francisco Javier Herrera Vargas");		//nombre programa
cprintf("Contar espacios hasta teclear una s                                              ");
space=0;

   gotoxy(3,10);printf("Escriba a partir de aqui: ");
   do
   {
   caracter=getch();
   printf("%c",caracter);
   if(caracter==13)
      {
      printf("\n");
      }
   if(caracter==' ')
      {
      space++;
      }
   }
while(caracter!='s');
gotoxy(3,46);printf("Espacios: ");
textbackground(1);
textcolor(14);
cprintf("%d",space);
textbackground(0);
textcolor(15);
gotoxy(1,48);cprintf("                                                                                 ");
gotoxy(1,49);cprintf("Deseas escribir otra cadena Si (1) No (2)                                  ");
cprintf("                                                                 Elije una opcion: ");
scanf("%d",&sn);
textbackground(1);
textcolor(15);
break;
case 2:
break;
default:
printf("\n\nSolo 1 o 2: ");
scanf("%d",&sn);
}
}
while(sn!=2);
}

void compara()
{
int sn;
char cadena1[100],cadena2[100];
sn=1;
clrscr();
textbackground(1);
textcolor(15);
do
{
switch(sn)
{
case 1:
clrscr();
textbackground(0);
textcolor(WHITE);
cprintf("                                                 Francisco Javier Herrera Vargas");		//nombre programa
cprintf("Compara dos cadenas                                                             ");
gotoxy(3,10);printf("Cadena 1: ");scanf("%s",cadena1);	//imprime y captura la cadena 1
gotoxy(3,12);printf("Cadena 2: ");scanf("%s",cadena2);     //imprime y captura la cadena 2
if(strcmp(cadena1,cadena2)==0)			//condicon para saber si son iguales
{
textbackground(1);
textcolor(14);
gotoxy(3,46);cprintf("Las cadenas son iguales");		//si se cumple la condicion son iguales
}
else						//sino
{
textbackground(1);
textcolor(14);
gotoxy(3,46);cprintf("Las cadenas no son iguales");         //no son iguales
}
textbackground(0);
textcolor(15);
gotoxy(1,48);cprintf("                                                                                 ");
gotoxy(1,49);cprintf("Deseas escribir otra cadena Si (1) No (2)                                  ");
cprintf("                                                                 Elije una opcion: ");
scanf("%d",&sn);
textbackground(1);
textcolor(15);

break;
case 2:
break;
default:
printf("\n\nSolo 1 o 2: ");
scanf("%d",&sn);
}
}
while(sn!=2);
}

void aleatorio()
{
int arre[100],n,cont,sn;
sn=1;
clrscr();
textbackground(1);
textcolor(15);
do
{
switch(sn)
{
case 1:
clrscr();
textbackground(0);
textcolor(WHITE);
cprintf("                                                 Francisco Javier Herrera Vargas");		//nombre programa
cprintf("Imprime un arreglo aleatorio                                                    ");
   randomize();
   gotoxy(3,10);printf("De que tamano va ser el arreglo:");scanf("%d",&n);
   for(cont=0;cont<n;cont++)
   arre[cont]=rand()%100;
   gotoxy(3,12);printf("El arreglo aleatorio es: \n\n");
   for(cont=0;cont<n;cont++)
   {
   textbackground(1);
   textcolor(14);
   gotoxy(3,14+cont);cprintf("%d\n",arre[cont]);
   }
textbackground(0);
textcolor(15);
gotoxy(1,48);cprintf("                                                                                 ");
gotoxy(1,49);cprintf("Deseas imprimir otro arreglo Si (1) No (2)                                  ");
cprintf("                                                                Elije una opcion: ");
scanf("%d",&sn);
textbackground(1);
textcolor(15);
break;
case 2:
break;
default:
printf("\n\nSolo 1 o 2: ");
scanf("%d",&sn);
}
}
while(sn!=2);
}

void inversa()
{
int cont1,cont2,sn;
sn=1;
clrscr();
textbackground(1);
textcolor(15);
do
{
switch(sn)
{
case 1:
clrscr();
char cadena1[100]={0},cadena2[100]={0};   		//se incializanlas cadenas en 0
textbackground(0);
textcolor(WHITE);
cprintf("                                                 Francisco Javier Herrera Vargas");		//nombre programa
cprintf("Imprimir una palabra al reves                                                   ");
   gotoxy(3,10);printf("Cadena 1: ");scanf("%s",cadena1); 	//imprime y captura la cadena a copiar
   cont2=0;						//contador de la cadena donde de va a copiar y se incializa en 0
   for(cont1=strlen(cadena1)-1;cont1>=0;cont1--)	//ciclo del contador de la cadena a copiar
     {							//incio for
     cadena2[cont2]=cadena1[cont1];            		//se copia la cadena 1 en la 2 pero invertida
     cont2++;                                 		//se agrega uno al contador de la cadena 2
     }							//fin for
   gotoxy(3,46);printf("Cadena invertida: ");       		//imprime la cadena 2 ya copiada e invertida
   textbackground(1);
   textcolor(14);
   cprintf("%s",cadena2);
  textbackground(0);
textcolor(15);
gotoxy(1,48);cprintf("                                                                                 ");
gotoxy(1,49);cprintf("Deseas escribir otra palabra Si (1) No (2)                                  ");
cprintf("                                                                Elije una opcion: ");
scanf("%d",&sn);
textbackground(1);
textcolor(15);

break;
case 2:
break;
default:
printf("\n\nSolo 1 o 2: ");
scanf("%d",&sn);
}
}
while(sn!=2);
}

void juntar()
{
char cadena1[100]={0},cadena2[100]={0};
int sn=1;
clrscr();
textbackground(1);
textcolor(15);
do
{
switch(sn)
{
case 1:
clrscr();
textbackground(0);
textcolor(WHITE);
cprintf("                                                 Francisco Javier Herrera Vargas");		//nombre programa
cprintf("Junta dos cadenas                                                               ");
gotoxy(3,10);printf("Cadena 1: ");scanf("%s",cadena1); 		//imprime y captura la cadena 1
gotoxy(3,12);printf("Cadena 2: ");scanf("%s",cadena2);   		//imprime y captura la cadena 2
gotoxy(3,46);printf("La cadena resultante: "); //imprime las cadenas juntas
textbackground(1);
textcolor(14);
cprintf("%s",strcat(cadena1,cadena2));
textbackground(0);
textcolor(15);
gotoxy(1,48);cprintf("                                                                                 ");
gotoxy(1,49);cprintf("Deseas juntar otras cadenas Si (1) No (2)                                  ");
cprintf("                                                                 Elije una opcion: ");
scanf("%d",&sn);
textbackground(1);
textcolor(15);

break;
case 2:
break;
default:
printf("\n\nSolo 1 o 2: ");
scanf("%d",&sn);
}
}
while(sn!=2);
}

void copiar()
{
char cadena1[100],cadena2[100];
int sn=1;
clrscr();
textbackground(1);
textcolor(15);
do
{
switch(sn)
{
case 1:
clrscr();
textbackground(0);
textcolor(WHITE);
cprintf("                                                 Francisco Javier Herrera Vargas");		//nombre programa
cprintf("Copiar una cadena en otra                                                       ");
gotoxy(3,10);printf("Cadena 1: ");scanf("%s",cadena1);		//imprime y captura la cadena a copiar
strcpy(cadena2,cadena1);				//copia la cadena
gotoxy(3,12);printf("Cadena 2: ");			//imprime la cadena copiada
textbackground(1);
textcolor(14);
cprintf("%s",cadena2);
textbackground(0);
textcolor(15);
gotoxy(1,48);cprintf("                                                                                 ");
gotoxy(1,49);cprintf("Deseas copiar otras cadenas Si (1) No (2)                                  ");
cprintf("                                                                 Elije una opcion: ");
scanf("%d",&sn);
textbackground(1);
textcolor(15);

break;
case 2:
break;
default:
printf("\n\nSolo 1 o 2: ");
scanf("%d",&sn);
}
}
while(sn!=2);
}

void longitud()
{
char cadena[100];
int sn;
sn=1;
clrscr();
textbackground(1);
textcolor(15);
do
{
switch(sn)
{
case 1:
clrscr();
textbackground(0);
textcolor(WHITE);
cprintf("                                                 Francisco Javier Herrera Vargas");		//nombre programa
cprintf("Longitud de una cadena                                                          ");
gotoxy(3,10);printf("Cadena: ");scanf("%s",cadena);		//imprime y captura la cadena
textbackground(1);
textcolor(14);
gotoxy(3,46);cprintf("La longitud es %d",strlen(cadena));  		//imprime la longitud de la cadena
textbackground(0);
textcolor(15);
gotoxy(1,48);cprintf("                                                                                 ");
gotoxy(1,49);cprintf("Deseas medir la longitud Si (1) No (2)                                    ");
cprintf("                                                                  Elije una opcion: ");
scanf("%d",&sn);
textbackground(1);
textcolor(15);

break;
case 2:
break;
default:
printf("\n\nSolo 1 o 2: ");
scanf("%d",&sn);
}
}
while(sn!=2);

}

void main()						//funcion  principal
{                               			//inicio main
int opcion;						//variable opcion
clrscr();                       			//limpia la pantalla
textbackground(BLUE);
textcolor(WHITE);
 do                              			//se repite todo mientras se cumpla el while
  {							//incio do
  clrscr();                       			//limpia pantalla
  textbackground(0);
  textcolor(WHITE);
  cprintf("                                                 Francisco Javier Herrera Vargas");		//nombre programa
  cprintf("Programas que hecho en clase                                            Pagina 1");
  printf("\n\n 1.- Suma");        			//Opcion del menu
  printf("\n\n\n\n\n 2.- Resta");        			//Opcion del menu
  printf("\n\n\n\n\n 3.- Multiplicacion"); 			//Opcion del menu
  printf("\n\n\n\n\n 4.- Division");           			//Opcion del menu
  printf("\n\n\n\n\n 5.- Tabla de multiplicar");        	//Opcion del menu
  printf("\n\n\n\n\n 6.- Factorial");          		//Opcion del menu
  printf("\n\n\n\n\n 7.- Par o impar");         		//Opcion del menu
  printf("\n\n\n\n\n 8.- Longitud de una cadena"); 		//Opcion del menu
  printf("\n\n\n\n\n 9.- Copiar una cadena a otra                                                   \n");    	//Opcion del menu
  textbackground(0);
  textcolor(15);
  cprintf("\n                                                                                ");
  cprintf("Salir (0) Pagina siguiente (10)                                                   ");
  cprintf("                                                         Elija una opcion: ");              	//elejir una opcion
  scanf("%d",&opcion);                  		//captura la opcion
  switch(opcion)                        		//funcion switch
   {                                     		//incio switch
	case 1:                               		//opcion 1
	suma();                              		//llama a la funcion suma
	break;                                		//va al while
	case 2:				      		//opcion 2
	resta();                     			//llama a la funcion resta
	break;				      		//va al while
	case 3:				      		//opcion 3
	multi();                             		//llama a la funcion multi
	break;                                		//va al while
	case 4:						//opcion 4
	division();					//llama a la funcion division
	break;                                 		//va al while
	case 5:						//opcion 5
	tabla();					//llama a la funcion tabla
	break;                                 		//va al while
	case 6:						//opcion 6
	factorial();                        		//llama a la funcion factorial
	break;                                 		//va al while
	case 7:						//opcion 7
	par();                 				//llama a la funcion par
	break;						//va al while
	case 8:						//opcion 8
	longitud();						//llama funcion longitud
	break;						//va al while
	case 9:
	copiar();						//llama funcion copiar
	break;

	case 10:						//opcion 9
	clrscr();
	textbackground(BLUE);
	textcolor(WHITE);
	do
	{
	clrscr();
	textbackground(0);
	textcolor(WHITE);
	cprintf("                                                 Francisco Javier Herrera Vargas");		//nombre programa
	cprintf("Programas que hecho en clase                                            Pagina 2");
	printf("\n\n 1.- Comparar dos cadenas");         	//Opcion del menu
	printf("\n\n\n\n\n 2.- Juntar una cadena con otra");    	//Opcion del menu
	printf("\n\n\n\n\n 3.- Invertir una cadena");           	//Opcion del menu
	printf("\n\n\n\n\n 4.- Promedio");                     	//Opcion del menu
	printf("\n\n\n\n\n 5.- Ordenar un arreglo");           	//Opcion del menu
	printf("\n\n\n\n\n 6.- Arreglo con valores aleatorios");	//Opcion del menu
	printf("\n\n\n\n\n 7.- Piramide");				//Opcion del menu
	printf("\n\n\n\n\n 8.- Numero mayor o menor");		//Opcion del menu
	printf("\n\n\n\n\n 9.- Contar espacios                                                            ");			//Opcion del menu
	textbackground(0);
	textcolor(15);
	cprintf("\n\n                                                                                ");
	cprintf("Salir (0) Pagina siguiente (10)                                                   ");
	cprintf("                                                         Elija una opcion: ");              	//elejir una opcion
	scanf("%d",&opcion);                  		//captura la opcion
	switch(opcion)                        		//funcion switch
	{                                     		//incio switch
	case 1:						//opcion 10
	compara();						//llama funcion compara
	break;                                         	//va al while
	case 2:						//opcion 11
	juntar();						//llama funcion juntar
	break;                                  		//va al while
	case 3:						//opcion 12
	inversa();						//llama funcion inversa
	break;						//va al while
	case 4:						//opcion 13
	promedio();						//llama a la funcion promedio
	break;						//va al while
	case 5:						//opcion 14
	ordena();						//llama funcion ordena
	break;						//va al while
	case 6:						//opcion15
	aleatorio();						//llama funcion aleatorio
	break;						//va al while
	case 7:						//opcion 16
	piramide();						//llama funcion piramide
	break;						//va al while
	case 8:						//opcion 17
	mayor();						//llama funcion mayor
	break;						//va al while
	case 9:						//opcion 18
	espacios();						//llama funcion espacios
	break;						//va al while
	case 10:
		clrscr();
		textbackground(BLUE);
		textcolor(WHITE);
		do
		{
		clrscr();                       			//limpia pantalla
		textbackground(0);
		textcolor(WHITE);
		cprintf("                                                 Francisco Javier Herrera Vargas");		//nombre programa
		cprintf("Programas que hecho en clase                                            Pagina 3");
		textbackground(1);
		textcolor(WHITE);
		printf("\n\n 1.- Cambiar numeros por letras");       	//Opcion del menu
		printf("\n\n\n\n\n 2.- Saber si una palabra es palindromo");
		printf("\n\n\n\n\n 3.- Agenda");
		printf("\n\n\n\n\n 4.- Volumen de un cubo");
		printf("\n\n\n\n\n 4.- Volumen de un cubo");
		printf("\n\n\n\n\n 4.- Volumen de un cubo");
		printf("\n\n\n\n\n 4.- Volumen de un cubo");
		printf("\n\n\n\n\n 4.- Volumen de un cubo");
		printf("\n\n\n\n\n 4.- Volumen de un cubo                                                         ");
		textbackground(0);
		textcolor(15);
		cprintf("\n\n                                                                                ");
		cprintf("Salir (0) Pagina siguiente (10)                                                   ");
		cprintf("                                                         Elija una opcion: ");              	//elejir una opcion
		scanf("%d",&opcion);                  		//captura la opcion
		switch(opcion)                        		//funcion switch
		{
		case 1:    						//opcion 19
		alfanumerico();                                      //llama funcion alfanumerico
		break;						//va al while
		case 2:
		palindromo();
		break;
		case 3:
		agenda();
		break;
		case 4:
		cubo();
		break;
		case 0:
		exit(0);
		default :						//sino se escoje una opcion valida
		printf("\nOpcion no disponible elija otra ");  	//imprime que lo intente de nuevo
		getche();
		}
		}
		while(opcion!=0 || opcion!=11);
		break;

	case 0:
	exit(0);
	default:						//sino se escoje una opcion valida
	printf("\nOpcion no disponible elija otra ");  	//imprime que lo intente de nuevo
	getche();
	}
	}
	while(opcion!=0);
	break;

	case 0:
	exit(0);
	default:						//sino se escoje una opcion valida
	printf("\nOpcion no disponible elija otra ");  	//imprime que lo intente de nuevo
	getche();
	}
}                      		                //fin do
while(opcion!=0);					//se repite todo mientras se cumpla esto
}							//fin de la funcion main