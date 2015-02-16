#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<DOS.H>
typedef struct
			 {
			  int numcliente;
			  char nombre[80];
			  char direccion[80];
			  char telefono[10];
			  char fechapertura[20];
			  char status[8];
			 }REGISTRO;

void main()
		 {
		  FILE *arch;
		  REGISTRO lista_clientes;
		  int opc1,opc2,numcontr,ban;
		  char tecla;
		  clrscr();
		  gotoxy(25,2);
		  printf("Comite de Antenas No Lucrativo");
		  gotoxy(25,3);
		  printf("Infonavit Constituyentes S.A. de C.V.");
		  gotoxy(30,24);
		  printf("!!!!!!BIENVENIDO­­­­­­");
		  gotoxy(25,12);
		  printf("Espere por favor");
		  delay(5000);
		  clrscr();
		  do
		  {
			clrscr();
			gotoxy(30,8);
			printf("Men£ Principal.");
			gotoxy(30,10);
			printf("Que desea Hacer?");
			gotoxy(35,14);
			printf("1. Clientes");
			gotoxy(35,16);
			printf("2. Pagos.");
			gotoxy(35,18);
			printf("3. Salir.");
			scanf("%d", &opc1);
			clrscr();
			switch (opc1)
				   {
					case 1:
						   gotoxy(35,8);
						   printf("Que desea hacer?");
						   gotoxy(35,10);
						   printf("1. Altas.");
						   gotoxy(35,12);
						   printf("2. Mostrar lista de clientes.");
						   scanf("%d", &opc2);
						   switch (opc2)
								 {
								  case 1:
										 clrscr();
										 arch=fopen("c:\\copropietarios.txt","a");
										 if (arch==NULL)
											 printf("Error de apertura");
										 else
											 {
												 do
												  {
												   fflush(stdin);
												   printf("Escribe los datos del cliente \n");
												   printf("Teclea el numero de contrato:\n");
												   scanf("%d", &lista_clientes.numcliente);
												   fflush(stdin);
												   printf("Teclea el nombre del cliente: \n");
												   gets(lista_clientes.nombre);
												   fflush(stdin);
												   printf("Teclea la direcci¢n del cliente: \n");
												   gets(lista_clientes.direccion);
												   fflush(stdin);
												   printf("Teclea el telefono del cliente: \n");
												   gets(lista_clientes.telefono);
												   fflush(stdin);
												   printf("Teclea la fecha de apertura del contrato: \n");
												   gets(lista_clientes.fechapertura);
												   fflush(stdin);
												   printf("Si el cliente hiso su primer pago, escribe la palabra pagado, de lo contrario escribe adeuda A \n");
												   gets(lista_clientes.status);
												   fflush(stdin);
												   fwrite(&lista_clientes,sizeof(lista_clientes),1,arch);
												   printf("Deseas anexar otro registro al archivo Y/N \n");
												   tecla=getch();
												  }while (tecla==121);
											  fclose(arch);
											 }
												   break;
								  case 2:
										 clrscr();
										 arch=fopen("c:\\copropietarios.txt","r");
										 if (arch==NULL)
											printf("Error al buscar el archivo");
										 else
											 {
											  fread(&lista_clientes,sizeof(lista_clientes),1,arch);
											  while (!feof(arch))
													{
													 delay(2000);
													 printf("Numero de contrato: %d Nombre del cliente: %s\n", lista_clientes.numcliente,lista_clientes.nombre);
													 printf("Direccion: %s \n", lista_clientes.direccion);
													 printf("Telefono: %s \n", lista_clientes.telefono);
													 printf("Fecha de apertura del contrato: %s \n", lista_clientes.fechapertura);
													 printf("Status: %s \n", lista_clientes.status);
													 fread(&lista_clientes,sizeof(lista_clientes),1,arch);
													 getch();
													}
											  getch();
											 }
										 fclose(arch);
										 break;
								  default:
										  clrscr();
										  gotoxy(30,14);
										  printf("Opcion no valida");
										  getch();
										  break;
								 }
						   break;
					case 2:
						   gotoxy(30,10);
						   printf("1. Consultas.");
						   gotoxy(30,12);
						   printf("2. Modificaciones.");
						   gotoxy(30,14);
						   printf("3. Reportes.");
						   scanf("%d", &opc2);
						   switch (opc2)
								 {
								  case 1:
										  do
											{
											 clrscr();
											 arch=fopen("c:\\copropietarios.txt","r");
											 if (arch==NULL)
												 printf("Error al buscar el archivo");
											 else
												{
												 printf("Teclea el numero de contrato a buscar");
												 scanf("%d", &numcontr);
												 fread(&lista_clientes,sizeof(lista_clientes),1,arch);
												 ban=0;
												 while (!feof(arch)&&(!ban))
													   {
														if (lista_clientes.numcliente==numcontr)
															ban=1;
														else
															fread(&lista_clientes,sizeof(lista_clientes),1,arch);
													   }
												 if (!ban)
													printf("Registro no encontrado");
												 else
													 {
													  printf("Numero de contrato: %d Nombre del cliente: %s\n", lista_clientes.numcliente,lista_clientes.nombre);
													  printf("Direccion: %s\n", lista_clientes.direccion);
													  printf("Telefono: %s\n", lista_clientes.telefono);
													  printf("Fecha de apertura del contrato: %s\n", lista_clientes.fechapertura);
													  printf("Status: %s\n", lista_clientes.status);
													  fread(&lista_clientes,sizeof(lista_clientes),1,arch);
													  getch();
													 }
												 printf("Deseas buscar otro contrato Y/N?");
												 tecla=getch();
												 getch();
												}
											}while (tecla==121);
										  fclose(arch);
										  break;
								  case 2:
												/* do
												   {
													clrscr();
                                                                                                        printf("sitio en construccion");
													arch=fopen("c:\\copropietarios.txt","r+t");
													if (arch==NULL)
													printf("Error de apertura");
													else
													   {
														printf("Teclea el numero de contrato a modificar");
														scanf("%d", &numcontr);
														fread(&lista_clientes,sizeof(lista_clientes),1,arch);
														ban=0;
														while (!feof(arch)&&(!ban))
															  {
															   if (lista_clientes.numcliente==numcontr)
																   ban=1;
															   else
																   fread(&lista_clientes,sizeof(lista_clientes),1,arch);
															  }
														if (!ban)
														printf("Registro no encontrado");
														else
														   {
															printf("Numero de contrato: %d Nombre del cliente: %s\n", lista_clientes.numcliente,lista_clientes.nombre);
															printf("Direccion: %s\n", lista_clientes.direccion);
															printf("Telefono: %s\n", lista_clientes.telefono);
															printf("Fecha de apertura del contrato: %s\n", lista_clientes.fechapertura);
															printf("Status: %s\n", lista_clientes.status);
															fread(&lista_clientes,sizeof(lista_clientes),1,arch);
															getch();
														   }
													   }
												   printf("Deseas buscar otro contrato Y/N?");
												   tecla=getch();
												   }while (tecla==121);
										 getch(); 
										 fclose(arch);*/
										 break;
								  case 3:
										 clrscr();
										 printf("No.contrato               Nombre.            status.");
										 arch=fopen("c:\\copropietarios.txt","r");
										 if (arch==NULL)
											printf("Error al buscar el archivo");
										 else
											 {
											  fread(&lista_clientes,sizeof(lista_clientes),1,arch);
											  while (!feof(arch))
													{
													 delay(2000);
													 printf("Numero de contrato: \n%d        Nombre del cliente: \n%s        Estatus de la cuenta: %s\n", lista_clientes.numcliente,lista_clientes.nombre,lista_clientes.status);
													 fread(&lista_clientes,sizeof(lista_clientes),1,arch);
													}
											  getch();
											 }
										 fclose (arch);
										 getch();
										 break;
								  default:
										  clrscr();
										  gotoxy(30,14);
										  printf("Opcion no valida");
										  getch();
										  break;
								 }
						   break;
					case 3:
						   gotoxy(20,2);
						   printf("Comite de Antenas No Lucrativo");
						   gotoxy(20,3);
						   printf("Infonavit Constituyentes S.A. de C.V.");
						   gotoxy(20,20);
						   printf("!!!!!!GRACIAS POR SU VISITA­­­­­­");
						   gotoxy(20,10);
						   printf("Para salir del programa, precione cualquier tacla.");
						   getch();
						   break;
					default:
							gotoxy(20,10);
							printf("Opcion no valida, precione cualquier tecla.");
							break;
				   }
		  }while(opc1!=3);
		 }