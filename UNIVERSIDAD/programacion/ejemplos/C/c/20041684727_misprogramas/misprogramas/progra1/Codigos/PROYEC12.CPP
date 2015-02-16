# include <stdio.h>
# include <conio.h>
# include <ctype.h>
# include <string.h>

typedef struct{
	char	clave[15];
	char	producto[20];
	char	provedor[20];
	float	pc;
	float	pp;
	}inven;

typedef struct{
	char	clave2[10];
	char	fecha[15];
	char	producto[20];
	int 	cantidad;
	float	total;
	char	nombre[70];
	char    rfc[20];
	char	direccion[50];
	char	tel[15];
	}ventas;

typedef struct{
	char	nombre[70];
	char    rfc[20];
	char	direccion[50];
	char	tel[15];
	}clientes;

void paint();
void bajas(int x);
void venta();
void buscar(int x);
void altas(int x);
void main()
{
	char opc;
	for(;;){
	clrscr();
	paint();
	gotoxy(33,3);printf("ElectroTrขnica");
	textcolor(0);textbackground(7);
	gotoxy(10,10);cprintf("Inventario");
	gotoxy(10,14);cprintf("Ventas");
	gotoxy(10,18);cprintf("Clientes");
	textbackground(1);textcolor(7);
	gotoxy(10,23);cprintf("Seleccione una Opciขn");
	gotoxy(50,23);cprintf("S - Salir");
	opc=getch();opc=tolower(opc);
	switch(opc){
		case 'i':
				clrscr();
				paint();
				gotoxy(33,3);printf("Inventario");
				textcolor(0);textbackground(7);
				gotoxy(10,10);cprintf("Altas");
				gotoxy(10,14);cprintf("Bajas");
				gotoxy(10,18);cprintf("Consulta");
			   //	gotoxy(10,18);printf("Menu Principal");
				opc=getch();opc=tolower(opc);
				switch(opc){
					case 'a':	altas(1);
					break;
					case 'b':	bajas(1);
					break;
					case 'c':   buscar(1);
					break;
					default:        gotoxy(40,20);
							printf("Opciขn Incorrecta");
					break;

						}

		break;
		case 'v':	clrscr();
					venta();
		break;
		case 'c':  	clrscr();
				paint();
				gotoxy(33,3);printf("Clientes");
				textcolor(0);textbackground(7);
				gotoxy(10,10);cprintf("Altas");
				gotoxy(10,14);cprintf("Bajas");
				gotoxy(10,18);cprintf("Consulta");
			    //	gotoxy(10,18);printf("Menu Principal");
				opc=getch();opc=tolower(opc);
				switch(opc){
					case 'a':	altas(2);
					break;
					case 'b':	bajas(2);
					break;
					case 'c':   buscar(2);
					break;
					default:    gotoxy(40,20);
							printf("Opciขn Incorrecta");
					break;
					}
		break;
		default:        gotoxy(40,20);
				printf("Opciขn Incorrecta");
		break;

	}
	  if(opc=='s')
	break;
	  getch(); }
}

void altas(int x)
{
	FILE *a;
	int ban=0;
	char cad[20], cad2[20];
	if(x==1){
	inven altas;

	clrscr();
	paint();
	gotoxy(34,3);printf("Altas");textcolor(0);textbackground(7);
	gotoxy(10,9);cprintf("Clave:     ");gets(cad);strupr(cad);
	a=fopen("c:\\altas.txt", "rb");
	fseek(a, SEEK_SET, 0);
	fread(&altas, sizeof(altas), 1, a);
	while(!feof(a)){
		if(strcmp(cad, altas.clave)==0)
			ban=1;
			printf("%i", ban);
		fread(&altas, sizeof(altas), 1, a);
	}fclose(a);

	if(ban==0){
	clrscr();
	paint();
	gotoxy(34,3);printf("Nuevo Registro");
	gotoxy(10,8);textcolor(0);textbackground(7);
	cprintf("Clave:       ");gets(altas.clave);strupr(altas.clave);
	gotoxy(10,11);cprintf("Producto:   ");gets(altas.producto);strupr(altas.producto);
	gotoxy(10,14);cprintf("Provedor:   ");gets(altas.provedor);strupr(altas.provedor);
	gotoxy(10,17);cprintf("P. Costo:   $ ");scanf("%f", &altas.pc);fflush(stdin);
	gotoxy(10,20);cprintf("P. Pฃblico: $ ");scanf("%f", &altas.pp);fflush(stdin);
	a=fopen("c:\\altas.txt", "ab");
	fwrite(&altas, sizeof(altas), 1, a);
	fclose(a);
	gotoxy(10,23);printf("Presione cualquier tecla para continuar...   Registro Actualizado");
	}
	else    {
		gotoxy(10,23);printf("EL registro ya existe\n");}
	}

	if(x==2){
	clientes	cliente;


	clrscr();
	paint();gotoxy(34,3);printf("Altas");textcolor(0);textbackground(7);
	gotoxy(10,9);
	printf("Nombre: ");gets(cad);strupr(cad);
	gotoxy(10,12);
	printf("R.F.C.: ");gets(cad2);strupr(cad2);
	a=fopen("c:\\clientes.txt", "rb");
	fseek(a, SEEK_SET, 0);
	fread(&cliente, sizeof(cliente), 1, a);
	while(!feof(a)){
		if((strcmp(cad, cliente.nombre)==0)&&(strcmp(cad2, cliente.rfc)==0))
			ban=1;
		fread(&cliente, sizeof(cliente), 1, a);
	}fclose(a);
	if(ban==0){
	clrscr();
	paint();
	gotoxy(32,3);printf("Nuevo Registro");textcolor(0);textbackground(7);
	gotoxy(10,8);cprintf("R.F.C.:     ");gets(cliente.rfc);strupr(cliente.rfc);
	gotoxy(10,12);cprintf("Nombre:     ");gets(cliente.nombre);strupr(cliente.nombre);
	gotoxy(10,16);cprintf("Direcciขn:  ");gets(cliente.direccion);strupr(cliente.direccion);
	gotoxy(10,20);cprintf("Telfono:   ");gets(cliente.tel);strupr(cliente.tel);
	a=fopen("c:\\clientes.txt", "ab");
	fwrite(&cliente, sizeof(cliente), 1, a);
	fclose(a);
	gotoxy(10,23);printf("Presione cualquier tecla para continuar...   Cliente Actualizado");
	}
	else   {
		gotoxy(10,23);printf("El Cliente ya existe\n");}
	}

 }
void buscar(int x)
{
	FILE *a;
	if(x==1){
	char cad[15];
	inven  altas;


	clrscr();
	paint();gotoxy(36,3);printf("Consulta");textcolor(0);textbackground(7);
	gotoxy(10,8);cprintf("Clave:        ");gets(cad);strupr(cad);
	a=fopen("c:\\altas.txt", "rb");
	fseek(a, SEEK_SET, 0);
	fread(&altas, sizeof(altas), 1, a);
	while(!feof(a)){
		if(strcmp(cad, altas.clave)==0){
			gotoxy(10,11);cprintf("Producto:     %s", altas.producto);
			gotoxy(10,14);cprintf("Provedor:     %s", altas.provedor);
			gotoxy(10,17);cprintf("P. Costo:     $ %.2f", altas.pc);
			gotoxy(10,20);cprintf("P. Pฃblico:   $ %.2f", altas.pp);
			}
		fread(&altas, sizeof(altas), 1, a);
	}fclose(a);
	gotoxy(10,23);printf("Presione cualquier tecla para continuar...");
	}
	if(x==2){
	char cad[20];
	clientes cliente;

	clrscr();
	paint();gotoxy(36,3);printf("Consulta");textcolor(0);textbackground(7);
	gotoxy(10,8);cprintf("Nombre:       ");gets(cad);strupr(cad);
	a=fopen("c:\\clientes.txt", "rb");
	fseek(a, SEEK_SET, 0);
	fread(&cliente, sizeof(cliente), 1, a);
	while(!feof(a)){
		if(strcmp(cad, cliente.nombre)==0){
			gotoxy(10,12);cprintf("R.F.C.:       %s", cliente.rfc);
			gotoxy(10,16);cprintf("Direcciขn:    %s", cliente.direccion);
			gotoxy(10,20);cprintf("Telfono:     %s", cliente.tel);
			}
		fread(&cliente, sizeof(cliente), 1, a);
	}fclose(a);
	gotoxy(10,23);printf("Presione cualquier tecla para continuar...");
	}

}
void venta()
{
	FILE *a;
	inven	altas;
	clientes cliente;
	ventas	venta;

	clrscr();
	paint();gotoxy(35,3);printf("Ventas");textcolor(0);textbackground(7);
	gotoxy(10,8);cprintf("Clave:    ");gets(venta.clave2);strupr(venta.clave2);
	gotoxy(10,12);cprintf("Nombre:   ");gets(venta.nombre);strupr(venta.nombre);
	a=fopen("c:\\altas.txt", "rb");
	fseek(a, SEEK_SET, 0);
	fread(&altas, sizeof(altas), 1, a);
	while(!feof(a)){
		if(strcmp(venta.clave2, altas.clave)==0){
			strcpy(venta.producto, altas.producto);
			venta.total=altas.pp;
		}fread(&altas, sizeof(altas), 1, a);
	}fclose(a);
	a=fopen("c:\\clientes.txt", "rb");
	fseek(a, SEEK_SET, 0);
	fread(&cliente, sizeof(cliente), 1, a);
	while(!feof(a)){
		if(strcmp(venta.nombre, cliente.nombre)==0){
			strcpy(venta.rfc, cliente.rfc);
			strcpy(venta.direccion, cliente.direccion);
			strcpy(venta.tel, cliente.tel);

		}fread(&cliente, sizeof(cliente), 1, a);
	}fclose(a);
	clrscr();
	paint();
	gotoxy(4,3);printf("Nombre:    %s", venta.nombre);
	gotoxy(45,3);printf("R.F.C.:   %s", venta.rfc);
	gotoxy(4,4);printf("Direcciขn: %s", venta.direccion);
	gotoxy(45,4);printf("Telfono: %s", venta.tel);
	textcolor(0);textbackground(7);
	gotoxy(10,8);cprintf("Fecha:     ");gets(venta.fecha);
	gotoxy(5,10);cprintf("-----------------------------------------------------------------------");
	gotoxy(10,11);cprintf("Cantidad");gotoxy(70,11);printf("Total");gotoxy(25,11);printf("Clave");gotoxy(42,11);printf("Producto");
	gotoxy(5,12);cprintf("-----------------------------------------------------------------------");
	gotoxy(14,16);scanf("%i", &venta.cantidad);fflush(stdin);
	gotoxy(23,16);cprintf("%s", venta.clave2);
	gotoxy(42,16);cprintf("%s", venta.producto);
	venta.total=venta.total*venta.cantidad;
	gotoxy(68,16);printf("$ %.2f", venta.total);
	gotoxy(5,20);printf("-----------------------------------------------------------------------");
	a=fopen("c:\\ventas.txt", "a");
	fwrite(&venta, sizeof(venta), 1, a);
	fclose(a);
	gotoxy(10,23);printf("Presione cualquier tecla para continuar...");

}

void bajas(int x)
{   int z;
	FILE *b, *a;
	clrscr();
	if(x==1)
	{

	  inven altas;
	  char cad[20];

	  clrscr();
	  paint();gotoxy(34,3);printf("Consulta");textcolor(0);textbackground(7);
	  gotoxy(10,8);cprintf("Clave:");
	  gets(cad);strupr(cad);
	  b=fopen("c:\\altas1.txt","ab");
	  a=fopen("c:\\altas.txt","rb");
	  fseek(a,SEEK_SET,0);
	  fread(&altas,sizeof(altas),1,a);
	  while(!feof(a))
		{
		z=strcmp(cad,altas.clave);
		if(z!=0)
		  fwrite(&altas ,sizeof(altas),1, b);
		fread(&altas ,sizeof (altas), 1, a);
		}
	  fclose(b);
	  fclose(a);
	  remove("c:\\altas.txt");
	  rename("c:\\altas1.txt","c:\\altas.txt");

	}
	 if(x==2)
	{

	  clientes cliente;
	  char cad[20];

	  printf("R.F.C:");
	  gets(cad);strupr(cad);
	  b=fopen("c:\\clientes1.txt","ab");
	  a=fopen("c:\\clientes.txt","rb");
	  fseek(a ,SEEK_SET, 0);
	  fread(&cliente,sizeof(cliente),1,a);
	  while(!feof(a))
		{
		z=strcmp(cad, cliente.rfc);
		if(z!=0)
		  fwrite(&cliente ,sizeof(cliente),1, b);
		fread(&cliente ,sizeof (cliente), 1, a);
		}
	  fclose(b);
	  fclose(a);
	  remove("c:\\clientes.txt");
	  rename("c:\\clientes1.txt","c:\\clientes.txt");
	}
	if(z==0) {
		gotoxy(10,23);printf("Presione cualquier tecla para Continuar...   Archivo Eliminado");}

}
void paint()
{       int y=1;

	for(int x=1;x<=25;x++)
	       for(int i=1;i<=80;i++){
		textbackground(y);
		gotoxy(i,x);
		cprintf(" ");}


	for( x=2;x<25;x++){
		if(x==2)
			y=0;
		if(x==6)
			y=7;
		if(x==22)
			y=1;
		textbackground(y);
		for( i=2;i<80;i++){
			gotoxy(i,x);
			cprintf(" ");}
	       }
	textbackground(0);textcolor(14);
	gotoxy(2,2);
	cprintf("ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป");
	gotoxy(2,3);
	cprintf("บ                                                                            บ");
	gotoxy(2,4);
	cprintf("บ                                                                            บ");
	gotoxy(2,5);
	cprintf("ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ");
	textbackground(1);textcolor(3);
	gotoxy(2,22);
	cprintf("ษออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป");
	gotoxy(2,23);
	cprintf("บ                                                                            บ");
	gotoxy(2,24);
	cprintf("บ                                                                            บ");
	gotoxy(2,25);
	cprintf("ศออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ");
}


