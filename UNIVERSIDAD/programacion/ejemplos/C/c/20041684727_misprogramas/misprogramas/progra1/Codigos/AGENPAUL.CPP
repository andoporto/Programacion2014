#include<stdio.h>
#include<conio.h>
#include<iostream.h>
#define bool int
#define true 1
#define false 0


FILE *archivo, *temporal;

void AGREGAR_PERSONA()
{
	int cedula, registro;
	char apellido[20], nombre[20], telefono[15], resp;
	bool no_encontrado;
	do{
		if((archivo = fopen("Directorio.ang","r")) == NULL)
		{
			printf("\n No se Encuentra el Archivo!");
			printf("\n\n Pulse una tecla para continuar...");
			getch();
		}else{
			clrscr();
			no_encontrado = true;
			cout<<"\n Introduzca la Cedula: "; cin>> registro;
			while ((!feof(archivo)) && (no_encontrado))
			{
				fscanf(archivo,"%d %s %s %s", &cedula, &apellido, &nombre, &telefono);
				if(registro == cedula)
				{
					no_encontrado = false;
				}
			}
			fclose(archivo);
			if(no_encontrado)
			{
				archivo = fopen("Directorio.ang","a");
				cedula = registro;
				cout<<"\n Introduzca el Apellido: "; cin>> apellido;
				cout<<" Introduzca el Nombre: "; cin>> nombre;
				cout<<" Introduzca el Telefono: "; cin>> telefono;
				fprintf(archivo,"%d %s %s %s\n", cedula, apellido, nombre, telefono); // %f para los float, %d para los int.
			}else{
				printf("\n Esta Persona ya esta Registrada en la Agenda!");
			}
			cout<<"\n\n Desea Registrar Otra Persona? S/N: "; resp = getch();
			fclose(archivo);
		}
	}while((resp == 's') || (resp == 'S'));
} //Fin del procedimiento AGREGAR_PERSONA

void CONSULTAR_REGISTRO()
{
	int registro, cedula; // Se declaran enteros porque si se dejan como string luego no se puede hacer la comparacion normal sino por comparacion de cadenas.
	char apellido[20], nombre[20], telefono[15], resp;
	bool no_encontrado;
	do{
		if((archivo = fopen("Directorio.ang","r")) == NULL)
		{
			printf("\n No se Encuentra el Archivo!");
			printf("\n\n Pulse una tecla para continuar...");
			getch();
		}else{
			clrscr();
			no_encontrado = true;
			cout<<"\n Introduzca la Cedula a Consultar: "; cin>>registro;
			while((!feof(archivo)) && (no_encontrado))
			{
				fscanf(archivo,"%d %s %s %s", &cedula, &apellido, &nombre, &telefono);
				if(registro == cedula)
				{
					no_encontrado = false;
				}
			}
			if(no_encontrado)
			{
				cout<<"\n No Existe un Registro con esa Cedula!\n\n";
			}else{
				cout<<"\n Registro Encontrado!\n\n";
				cout<<" Cedula:   " <<cedula <<"\n";
				cout<<" Apellido: " <<apellido <<"\n";
				cout<<" Nombre:   " <<nombre <<"\n";
				cout<<" Telefono: " <<telefono <<"\n\n";
			}
			cout<<" Desea Realizar Otra Consulta? S/N: "; resp = getch();
			fclose(archivo);
		}
	}while((resp == 's') || (resp == 'S'));
} //Fin del procedimiento CONSULTAR_REGISTRO

void ELIMINAR_PERSONA()
{
	int registro, cedula;
	char resp, apellido[20], nombre[20], telefono[15], eliminar;
	bool no_encontrado;
	do{
		if ((archivo = fopen("Directorio.ang","r")) == NULL)
		{
			cout<<"\n No se Encuentra el Archivo!";
			cout<<"\n\n Pulse una tecla para continuar...";
			getch();
		}else{
			clrscr();
			no_encontrado = true;
			cout<<"\n Introduzca la Cedula del Registro a Eliminar: "; cin>>registro;
			while((!feof(archivo)) && (no_encontrado))
			{
				fscanf(archivo,"%d %s %s %s", &cedula, &apellido, &nombre, &telefono);
				if(registro == cedula)
				{
					no_encontrado = false;
				}
			}
			if(no_encontrado)
			{
				cout<<"\n No Existe un Registro con esa Cedula!\n\n";
			}else{
				cout<<"\n Registro Encontrado!\n\n";
				cout<<" Cedula:   " <<cedula <<"\n";
				cout<<" Apellido: " <<apellido <<"\n";
				cout<<" Nombre:   " <<nombre <<"\n";
				cout<<" Telefono: " <<telefono <<"\n\n";
				fclose(archivo);
				cout<<" Desea Eliminar este Registro? S/N: "; eliminar = getch();
			}
			if ((eliminar == 's') || (eliminar == 'S'))
			{
				if((archivo = fopen("Directorio.ang","r")) == NULL)
				{
					cout<<"\n No se Encuentra el Archivo!";
					cout<<"\n\n Pulse una tecla para continuar...";
					getch();
				}else{
					temporal = fopen("temporal.ang","w");
					while(!feof(archivo))
					{
						fscanf(archivo,"%d %s %s %s\n", &cedula, &apellido, &nombre, &telefono);
						if (registro != cedula)
						{
							fprintf(temporal,"%d %s %s %s\n", cedula, apellido, nombre, telefono);
						}
					}
					fclose(temporal);
					fclose(archivo);
					if((temporal = fopen("temporal.ang","r")) == NULL)
					{
						cout<<"\n No se Encuentra el Archivo, no se Pudo Eliminar!";
						cout<<"\n\n Pulse una tecla para continuar...";
						getch();
					}else{
						archivo = fopen("Directorio.ang","w");
						while(!feof(temporal))
						{
							fscanf(temporal,"%d %s %s %s\n", &cedula, &apellido, &nombre, &telefono);
							fprintf(archivo,"%d %s %s %s\n", cedula, apellido, nombre, telefono);
						}
						fclose(temporal);
						fclose(archivo);
						cout<<"\n\n Se ha Eliminado el Registro!";
						//Vaciamos el Archivo temporal
						temporal = fopen("temporal.ang","w");
						fclose(temporal);
					}
				}
			}
			cout<<"\n\n Desea eliminar Otro Registro? S/N: "; resp = getch();
		}
	}while((resp == 's') || (resp == 'S'));
} //Fin del procedimiento ELIMINAR_REGISTRO

void VACIAR_AGENDA()
{
	char resp;
	cout<<"\n\n Esta Seguro que Desea Vaciar la Agenda? S/N: "; cin>> resp;
	if ((resp == 's') || (resp == 'S'))
	{
		if((archivo = fopen("Directorio.ang","w")) == NULL)
		{
			cout<<"\n No se Encuentra el Archivo!";
			cout<<"\n\n Pulse una tecla para continuar...";
			getch();
		}else{
			fclose(archivo);
			cout<<"\n Se ha Vaciado la Agenda Satisfactoriamente!";
			cout<<"\n\n Pulse una tecla para continuar...";
			getch();
		}
	}
} //Fin del procedimiento VACIAR_AGENDA

void DESPLEGAR_AGENDA()
{
	char cedula[8], apellido[20], nombre[20], telefono[15];
	if((archivo = fopen("Directorio.ang","r")) == NULL)
	{
		cout<<"\n No se Encuentra el Archivo!";
		cout<<"\n\n Pulse una tecla para continuar...";
		getch();
	}else{
		clrscr();
		cout<<"  CEDULA        APELLIDO        NOMBRE        TELEFONO\n\n";
		while(!feof(archivo))
		{
			fscanf(archivo,"%s %s %s %s\n", &cedula, &apellido, &nombre, &telefono);
			cout<<" "<<cedula<<"     "<<apellido<<"         "<<nombre<<"          "<<telefono<<"\n";
		}
		fclose(archivo);
		cout<<"\n\n Pulse una tecla para continuar...";
		getch();
	}
} //Fin del procedimiento DESPLEGAR_AGENDA

void ACERCA_DE()
{
	clrscr();
	cout<<"\n    AGENDA ELECTRONICA --> Desarrollado por Paul Arriaga y Pedro Santos \n\n";
	cout<<"  La entrada de datos de la cedula no esta validada y se declaro como entero \n";
	cout<<"  para poder hacer las comparaciones entre cedulas (hay otras formas de\n";
	cout<<"  hacerlo, como la comparacion de strings etc, pero en fin este ejemplo es \n";
	cout<<"  dedicado a los Archivos.\n  Cualquier duda o comentario escribeme a agoncal@uc.edu.ve o krized@hotmail.com\n";
	cout<<"\n\n  Pulse una Tecla para Volver al Menu Principal...";
	getch();
} //Fin del procedimiento ACERCA_DE

void MENU()
{
	cout<<"\n    AGENDA ELECTRONICA --> Desarrollado por Paul Arriaga y Pedro Martinez <--\n";
	cout<<"          Implementacion de Archivos en C++\n\n";
	cout<<" 1- Agregar una Persona a la Agenda.\n";
	cout<<" 2- Consultar un Registro en la Agenda.\n";
	cout<<" 3- Desplegar todos los Datos de la Agenda.\n";
	cout<<" 4- Eliminar un Registro de la Agenda.\n";
	cout<<" 5- Vaciar la Agenda.\n\n";
	cout<<" A- Acerca de...\n";
	cout<<" S- Salir.\n";
} // Fin del procedimiento MENU

void main (void)
{
	char op;
	bool salir = false;
	do{
		clrscr();
		if ((archivo = fopen("Directorio.ang","r")) == NULL)
		{
			printf("\n Al parecer es la Primera Vez que inicias el Programa,\n");
			printf(" o el Archivo fue Borrado. Presiona una tecla para Crearlo...");
			getch();
			archivo = fopen("Directorio.ang","w");
			fclose(archivo);
			printf("\n\n El Archivo se ha Creado con Exito!!!\n\n");
			MENU();
			printf("\n Seleccione una Opcion: "); scanf("%c",&op);
		}else{
			MENU();
			printf("\n Seleccione una Opcion: "); scanf("%c",&op);
		}
		switch (op)
		{
			case '1':
				AGREGAR_PERSONA();
				break;
			case '2':
				CONSULTAR_REGISTRO();
				break;
			case '3':
				DESPLEGAR_AGENDA();
				break;
			case '4':
				ELIMINAR_PERSONA();
				break;
			case '5':
				VACIAR_AGENDA();
				break;
			case 'a': case 'A':
				ACERCA_DE();
				break;
			case 's': case 'S':
				salir = true;
				break;
		}
	}while(salir == false);
} // Fin del main (void)