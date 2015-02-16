#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* estructura global de un nombre*/
struct listaDeCorreo
	{ char nombre[25]; /*el nombre almacenado  aqui debe listar en primer termino el apellido*/
	  char direccion[25];
	  char cuidad[12];
	  char provincia [3]; /*deja espacio para el cero de terminacion*/
	  char codigoPostal[6];
	  char codigo[7]; /*para expansion futura*/
	  };

	/*puntero de archivo declarado como global*/
	FILE *punteroDeArchivo;

	/*constantes definidas*/
	#define MAX 	250 /* MAX es el numero total de nombres permitidos en memoria para leer la lista de correo*/
	#define	ALARMA '\x07'
	#define ARCHIVO "DIRECCION.DAT"

/*prototipado de todas las funciones de este programa*/

void main( );
void mostrarMenu();
void borrarPantalla();
void ingresarNombre();
void editarNombre();
void imprimirNombre();
void mensajeDeError(char mensajeDeError[]);
void anadirAArchivo(struct listaDeCorreo item);
void congelarPantalla();
void imprimirDatos(struct listaDeCorreo item);
void obtenerNuevoItem(struct listaDeCorreo *item);
void obtenerCodigoPostal(char codigoPostal[]);
/**************************************************************/

void main()
{
 struct listaDeCorreo lista[MAX];
 char respuesta;
 do
 	{ mostrarMenu(); /*exhibe menu para el usuario*/
 	  scanf("%d",&respuesta);
 	  switch (respuesta)
 	  { case (1) :{ ingresarNombre();
 	  				break; }
	  { case
	   (2) :{ editarNombre();
 	  				break; }
 	  { case (3) :{ imprimirNombre();
 	  				break; }
 	  case (4) :{ break; }
	  default : { mensajeDeError("******** Se requiere ingresar un numero comprendido entre 1 y 4 ********"); break; }
	  }

 	 } while (respuesta!=4);
	 }

	/******************************************************************/
	void mostrarMenu(); /*exhibe em pantalla el menu principal de este programa*/
	{
	  borrarPantalla(); /*borra ya sea la pantalla o la ventana de texto*/
	  printf("\t\t*** Administrador de listas de correo***\n");
	  printf("\t\t  ----\n\n\n\n");
	  printf("Las opciones de edicion de nombres y direcciones de esta lista de correo son:\n\n\n");
	  printf("\t1. Anadir \n\n\n");
	  printf("\t2. Modificar \n\n\n");
	  printf("\t3. Imprimir \n\n\n");
	  printf("\t4. Terminar \n\n\n");
	  printf("Ingrese su opcion:");
     }

	/**************************************************************************/
	void borrarPantalla() /* borra la pantalla imprimiendo en la misma 25 lineas en blanco*/
	{
	  int contador /*contador para las 25 lineas en blanco*/
		for (contador=0;contador<25;contador++)
		{ printf("\n"); }
		return 0;
    }
   /**************************************************************************/
   void ingresarNombre()
   {
	  struct listaDeCorreo item;
	  char respuesta;
	  do
	  { fflush (stdin); /*vaciar buffer de entrada antes de ingresar cadenas*/
	   	printf("\n\n\n\n\n¿Nombre? ");
	   	gets(item.nombre);
	   	printf("¿Direccion?");
	   	gets(item.direccion);
	   	printf("¿Cuidad?");
	   	gets(item.cuidad);
	   	printf("¿Provincia?(abreviada a solo 2 letras");
	   	gets(item.provincia);

	   	/*ingresa el codigo postal y verifica que el mismo conste unicamente de digitos*/
	   	obtenerCodigoPostal(item codigoPostal);

	   	strcpy(item.codigo, " "); /*pone en cero todos los miembros*/
	   	anadirAArchivo(item); /*guarda nueva informacion en disco*/
	   	printf("\n\n¿Desea ingresar un mombre?");
   		printf("y direccion adicionales (S/N)");
   		respuesta=getchar();
   		getchar(); /*descarta el subsiguiente retorno de carro*/
   	  } while (toupper(respuesta)=="Y");
   }
    /**************************************************************************/
    void editarNombre()
    {
	 struct listaDeCorreo item;
	 int respuesta, longitudCadena; /*almacena el tamaño de la estructura*/
	 int editado_afirmativo=0; /*evaluara a Verdadero si el programa encuentra un  nombre pedido y el usuario lo modifica*/
	 char nombreAComprobar[25];
	 printf("\n¿Que nombre desea modificar?");
	 fflush(stdin); /*vacia de caracteres el buffer de entrada*/
	 gets(nombreAComprobar);
	 fflush(stdin);

	 longitudCadena=sizeof(struct listaDeCorreo); /*garantiza que fread() lea la cantidad precisa de bytes*/

	 if (punteroDeArchivo=fopen(ARCHIVO, "r+"))==NULL)
	 	{ mensajeDeError("***Error de acceso a disco - Verifique que el archivo exista***");
	 	return 0; }

	 do
	 	{ if (fread(&item, sizeof(struct listaDeCorreo), 1,punteroDeArchivo)!=longitud)
	 	{ if (feof(punteroDeArchivo)) /*si se llego al final de archivo deje de leer*/
	 		{break;}
 		}
 		if (strcmp(item.nombre, nombreAComprobar)==0)
 		{ imprimirDatos(item) /*imprime el nombre y la direccion*/
 		  printf("\n¨Son estos el nombre y la direccion a modificar? (S/N)");
   		respuesta=getchar();
   		getchar(); /*descarta el retorno de carro superfluo*/
		if (toupper(respuesta)=="N")
			{continue;}  /*Obtener otro nombre*/
			obtenerNuevoItem(&item); /*permitir al usuario tipear nueva informacion*/
			fseek(punteroDeArchivo, (long)-longitud, SEEK_CUR); /*retrocede una estructura*/
			fwrite(&item, longitud, 1, punteroDeArchivo); /*guarda en disco la informacion modificada*/
			editado_afirmativo=1;  /*la edicion tuvo lugar*/
			break; /*finaliza lazo*/
		 }
	   } while ( !feof(punteroDeArchivo));
	   fclose(punteroDeArchivo);

	   if (!editado_afirmativo)
	    { mensajeDeError("***Se ha arribado al final de la lista - no se pudo encontar nombre***"); }
	 	return 0;
  	   }
/**********************************************************************/
void imprimirNombre()
{
  struct listaDeCorreo item;
  int longitud, contadorDelineas=0;
  longitud=sizeof(struct listaDeCorreo); /*Garantiza que fread() lea la cantidad precisa de bytes*/
    if ((punteroDeArchivo=fopen(ARCHIVO, "r"))==NULL)
     {  mensajeDeError("***Error de lectura - Verique que el archivo exista***"); }
    return 0; }

    do
       { if(fread(&item, sizeof(struct ListaDeCorreo); 1,
                             punteroDeArchivo)!=longitud)
		 { if(feof(punteroDeArchivo))  /*Si se llego al final del archivo, deje de leer*/
		 {break}

	     }
	       if (contadorDelineas>20)  /*Los datos ocupan toda la pantalla*/
	       { congelarPantalla();
	         contadorDelineas=0;
	         imprimirDatos(item);  /*Imprime el nombre y la dirección*/
	         contadorDelineas+=4;
            } while (!=foef(punteroDeArchivo));

            fclose(punteroDeArchivo);
            printf("\n -Fin de lista-");
            congelarPantalla();  /*Brinda al usuario la oportunidad
            						de ver el resto de los nombres presentes en la pantalla*/

		}
		/**********************************************************************/
		void congelarPantalla()
		{
		 char respuesta;
		 fflush(stdin);  /*Vaciar el buffer de entrada de caracteres superfluos*/
		 printf("\nPulse la tecla INTRO para continuar....");
		 respuesta=getchar();
		 fflush(stdin);  /*Vaciar el buffer de entrada de caracteres superfluos*/

	    }

	    /**********************************************************************/
	     void imprimirDatos(struct listaDeCorreo item)
	     {
		    /*Imprime el nombre y la direccion que le hayan sido transferidos*/
		    printf("\nNombre : %-25s\n",item.nombre);
		    printf("Direccion: %-25s\n",item.direccion);
		    printf("Cuidad: %-12s\t Provincia: %-2s Codigo Postal: %-5s\n",item.cuidad, item.provincia, item.codigoPostal);

	     }
	     /**********************************************************************/
		 void obtenerNuevoItem(struct listaDeCorreo *item);
		 {
		   struct listaDeCorreo item_temporario;  /*Almacena sucesivamente la estructura
		   recibida y su eventual modificacion*/
		   printf("\nIngrese debajo el nuevo nombre y la ");
		   printf("correspondiente direccion.\n(Pulse solo la tecla");
		   printf("intro para retener la informacion existente.)\n\n");
		   printf("¨cual es el nuevo nombre?");
		     if (strlen(gets(item_temporario.nombre))>0) /*Guarda los datos al disco solamente*/
		     { strcpy((*item).nombre, item_temporario.nombre); } /*cuando el usuario pulsa Intro*/
		       printf("¨La direccion?");
		if (strlen(gets(item_temporario.direccion))>0) /*Guarda los datos al disco solamente*/
		     { strcpy((*item).direccion, item_temporario.direccion); } /*cuando el usuario pulsa Intro*/
		       printf("¨La cuidad?");
		if (strlen(gets(item_temporario.cuidad))>0) /*Guarda los datos al disco solamente*/
		     { strcpy((*item).direccion, item_temporario.cuidad); } /*cuando el usuario pulsa Intro*/
		       printf("¨La provincia? (abreviada a solo 2 letras)");
		    if (strlen(gets(item_temporario.provincia))>0) /*Guarda los datos al disco solamente*/
		     { strcpy((*item).direccion, item_temporario.provincia); } /*cuando el usuario pulsa Intro*/
			  printf("¨El codigo postal?");
			if (strlen(gets(item_temporario.codigoPostal))>0) /*Guarda los datos al disco solamente*/
		     { strcpy((*item).direccion, item_temporario.codigoPostal); } /*cuando el usuario pulsa Intro*/

		     (*item),codigo[0]=0; /*inicializar a cero el miembro codigo*/
	       }


		    /*************************************************************/
		       void obtenerCodigoPostal(char codigoPostal[]);
		       /*garantiza que el codigo postal conste solo de digitos*/
		       {
			     int contador, codigoPostalIncorrecto;
			     do
			      { codigoPostalIncorrecto=0;
				printf("¿Codigo postal?");
				gets(codigoPostal);
				   for (contador=0; contador<5;contador++)
				     { if (isdigit(codigoPostal[contador]))
							{ continue; }
					  else
					   { mensajeDeError("***El codigo postal debe constar unicamente de numeros***");
					     codigoPostalIncorrecto=1;
					     break; }
				      }
			} while (codigoPostalIncorrecto);
                }






