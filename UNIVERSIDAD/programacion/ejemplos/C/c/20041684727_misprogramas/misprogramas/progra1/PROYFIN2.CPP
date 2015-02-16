#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<DOS.H>
typedef struct
			 {
			  int numcontr1;
			  char nombre[80];
			  char direc[80];
			  char tel[10];
			  char fech_apert1[10];
			 }CLIENTES;
typedef struct
			 {
			  int numcontr2;
			  char fech_apert2[12];
			  char tipserv[10];
			  char status[10];
			 }PAGOS;
typedef struct
			 {
			  int numcontr3;
			  char status2[10];
			  char motivo[20];
			  char fechcorte[12];
			  char observ[50];
			 }CORTES;
void main()
		 {
		  int opc1,opc2,contrato,ban;
		  char tecla;
		  FILE *arch1,*arch2,*arch3,*borrados;
		  CLIENTES clientes;
		  PAGOS pagos;
		  CORTES cortes;
		  clrscr();
		  clientes.numcontr1=clientes.numcontr1;
		  gotoxy(28,2);
		  printf("Comite de Antenas No Lucrativo");
		  gotoxy(28,3);
		  printf("Infonavit Constituyentes S.A. de C.V.");
		  gotoxy(30,12);
		  printf("Espere por favor");
		  gotoxy(25,24);
		  printf("!!!!!!BIENVENIDO­­­­­­");
		  delay(3000);
		  clrscr();
		  do
		   {
			clrscr();
			fflush(stdin);
			gotoxy(30,8);
			printf("Men£ Principal.");
			gotoxy(10,2);
			printf("Teclee el numero de la opcion ha ejecutar y precione enter");
			gotoxy(30,12);
			printf("1. Altas.");
			gotoxy(30,14);
			printf("2. Bajas.");
			gotoxy(30,16);
			printf("3. Modificaciones.");
			gotoxy(30,18);
			printf("4. Consultas.");
			gotoxy(30,20);
			printf("5. Reportes.");
			gotoxy(30,22);
			printf("6. Salir.");
			scanf("%d", &opc1);
			switch (opc1)
				  {
				   case 1:
						  clrscr();
						  arch1=fopen("c:\\copropietarios.txt","a");
						  if (arch1==NULL)
						  printf("Error de apertura");
						  else
							 {
							 do
							   {
								printf("Teclea el numero de contrato: ");
								scanf("%d",&contrato);
								while(!feof(arch1))
									 {
									  fread(&clientes.numcontr1,sizeof(clientes.numcontr1),1,arch1);
									  if (clientes.numcontr1==contrato)
										  printf("El numero de contrato que tecleo ya existe, trate con otro numero");
									 }
								fread(&clientes.numcontr1,sizeof(clientes.numcontr1),1,arch1);
								fseek(arch1,clientes.numcontr1*sizeof(clientes.numcontr1),SEEK_END);
								clientes.numcontr1=contrato;
								fflush(stdin);
								printf("Teclea el nombre del cliente: ");
								gets(clientes.nombre);
								fflush(stdin);
								printf("Teclea la direccion del cliente: ");
								gets(clientes.direc);
								fflush(stdin);
								printf("teclea el telefono del cliente: ");
								gets(clientes.tel);
								fflush(stdin);
								printf("Teclea la fecha de apertura del contrato");
								gets(clientes.fech_apert1);
								fwrite(&clientes,sizeof(clientes),1,arch1);
								fflush(stdin);
								printf("deseas dar de alta otro cliente Y/N?");
								tecla=getch();
							   }while(tecla==121);
							 }
						  fclose(arch1);
						  break;
				   case 2:
						  clrscr();
						  printf("sitio en construccion");

						  getch();
						  break;
				   case 3:
						  clrscr();
						  gotoxy(30,12);
						  printf("Que Desea modificar?");
						  gotoxy(30,14);
						  printf("1. Pagos.");
						  gotoxy(30,15);
						  printf("2. Cortes.");
						  scanf("%d", &opc2);
						  switch (opc2)
								{
								 case 1:
										clrscr();
										arch1=fopen("c:\\copropietarios.txt","ab");
										arch2=fopen("c:\\pagos.txt","ab");
										if ((arch1==NULL)&&(arch2==NULL))
											printf("Error de apertura");
										else
											{
											 printf("Teclesa el numero de contrato a modificar");
											 scanf("%d",&contrato);
											 fread(&clientes.numcontr1,sizeof(clientes.numcontr1),1,arch1);
											 ban=0;
											 while(!feof(arch1)&&(!ban))
												  {
												   if (clientes.numcontr1==contrato)
													  {
													   ban=1;
													   fwrite(arch2,sizeof(pagos.numcontr2),1,arch2);
													   pagos.numcontr2=clientes.numcontr1;
													  }
												   else
													   fread(&pagos.numcontr2,sizeof(pagos.numcontr2),1,arch2);
												   if (!ban)
												   printf("Contrato no existe");
												  }
											 printf("El numero de contrato es: %d", pagos.numcontr2);
											}
										fcloseall();
										getch();
										break;
								 case 2:
										clrscr();
										getch();
										break;
								}

						  getch();
						  break;
				   case 4:
						  clrscr();
						  printf("sitio en construccion");
						  getch;
						  break;
				   case 5:
						  clrscr();
						  arch1=fopen("c:\\copropietarios.txt","rb");
						  if (arch1==NULL)
							  printf("Error de apertura");
						   else
							   {
								fread(&clientes,sizeof(CLIENTES),1,arch1);
								printf("Acontinuacion se mostrara una lista de los clientes registrados actuelmente.\n");
								fread(&clientes,sizeof(CLIENTES),1,arch1);
								while (!feof(arch1))
									 {
									  printf("Numero de contrato: %d\n", clientes.numcontr1);
									  printf("Nombre del cliente: %s\n", clientes.nombre);
									  printf("Direccion: %s\n",clientes.direc);
									  printf("Telefono: %s\n", clientes.tel);
									  fread(&clientes,sizeof(CLIENTES),1,arch1);
									  getch();
									 }
								fclose(arch1);
							   }
						  getch();
						  break;
				   case 6:
						  clrscr();
						  gotoxy(20,20);
						  printf("Para salir del programa, presione cualquier tecla");
						  fflush(stdin);
						  break;
				   default:
						   clrscr();
						   printf("Opcion no valida, intente de nuevo");
						   getch;
						   break;
				  }
		   }while (opc1!=6);
		  getch();
		 }