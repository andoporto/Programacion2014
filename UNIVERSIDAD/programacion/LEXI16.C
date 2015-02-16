
# line 7 "lexi16.y"
#include <dos.h>
#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <errno.h>
#include <ctype.h>
#include <values.h>

/* Cantidad de Filas y Cols de las matrices*/
#define FILA  15
#define COL   22

#define F  	  999
#define FINA  -1

#define MAXTAMID 52
#define MAXTAMCTE 12
#define LETRA 257
#define MISTRING 258
#define DIGITO 259
#define SI 260
#define HACER 261
#define SINO 262
#define FINSI 263
#define REPETIR 264
#define AS 265
#define REAL 266
#define OR 267
#define AND 268
#define NOT 269
#define PRINT 270
#define MIREAL 271
#define MAYOR 272
#define MENOR 273
#define IGUAL 274
#define MENIGU 275
#define MAYIGU 276
#define DISTINTO 277
#define ASIGMAS 278
#define ASIGMENOS 279
#define ASIGMULT 280
#define ASIGCOCIENTE 281
#define COMA 282
#define COMILLA 283
#define PUNTO 284
#define ERROR 285
#define INICIO 286
#define DIM 287
#define ID 288
#define FIN 289
#define ASIG 290
#define ABREPAREN 291
#define CIERRAPAREN 292
#define ABRELLAVE 293
#define CIERRALLAVE 294
#define ABRECORCH 295
#define CIERRACORCH 296
#define CADENA 297
#define MAS 298
#define MENOS 299
#define MULTIP 300
#define COCIENTE 301
#ifndef YYSTYPE
#define YYSTYPE int
#endif
YYSTYPE yylval, yyval;
#define YYERRCODE 256

# line 119 "lexi16.y"



typedef struct {
       		    char nombre[53]; 			// Nombre del token
			  		 int tipo;  					// Codigo asociado al token leido
					 int flag;  					// Para saber si la variable fue declarada con DIM
			  		 int value; 					// Valor de la variable
                int limite;
                float valor;
                int indice;
	            } tsimbolo; 					// tabla de simbolos

typedef struct {
					char op1[MAXTAMCTE];
					char op2[MAXTAMCTE];
					char op3[MAXTAMCTE];
	            } terceto; // tabla de simbolos

// Tabla de simbolos
tsimbolo simbolo[100];

// Columna a posicionarse en la tabla de estados
int getevent(void);

// Token reconocido
int yylex(void);

// Tabla de palabras reservadas
char reservadas[15][53]={"INICIO","FIN","SI","HACER","SINO","FINSI",
			                "DIM","AS","REPETIR","OR","AND","NOT","REAL","PRINT","CADENA"};
int tokenreservadas[15]={INICIO,FIN,SI,HACER,SINO,FINSI,
			                DIM,AS,REPETIR,OR,AND,NOT,REAL,PRINT,CADENA};

// Para errores: en que linea estoy
int line;

int cantSimbolos=0;
extern int yyparse();

// Identificadores
void inId();
void adId();
void finId();

// Constantes
void inRea();
void adRea();
void finRea();

void inStr();
void adStr();
void finStr();

// Comparadores
void inCo1();
void inCo2();
void inCo3();
void finCo1();
void finCo2();
void finCo3();

// Asignadores especiales
void inOp1();
void inOp2();
void inOp3();
void inOp4();
void finOp1();
void finOp2();
void finOp3();
void finOp4();

// Caracteres TERMINALES
void termi();

// Espacios en blanco
void nada();
void error();

// Agrega un token en la tabla de simbolos
int agregar(char *, int);
void muestraTS();
int setFlag (char *, int);
int setLimite(char *, char*);
void limpiaTS();

// Devuelve la posicion en la tabla de simbolos
int yylval;

// Almacena token reconocido
int token;

// Almacena el caracter leido del archivo
char caracter;

// Testea el estado actual
int estado;

// Para saber si existe o no algo almacenado en el
// buffer que aun no fue reconocido
int pendiente=0;

// Maneja las posiciones dentro de buffer
int cont_buff;

// Almacena lo leido desde el archivo
char buffer[53];


//******************** FUNCIONES PARA ARMAR TERCETOS **********************

//Apila Id , Cte o nro de tercetos (OPERANDOS)
void ApilarOperando(char *);

//Desapila Id , Cte o nro de tercetos (OPERANDOS)
char * desapilarOperando();

//Apila Operadores
void ApilarOperador(char *);

//Desapila Operadores
char * desapilarOperador();

//Apila Terceto
void ApilarTerceto();

//Desapila Terceto
int desapilarTerceto();

//Apila AND u OR
void ApilarLogicos(int );

//Desapila AND u OR
int desapilarLogicos();

//Finaliza Operador
void FinOperador();

void ReglaFinal();

void ArmaTerBranch(int);

void CompletaFaltante(int);

void FinPrint();

char * ObtenerBranch();

char NomArray[MAXTAMID];
char IndiceArray[MAXTAMCTE];
int EsOr;

//******************** FIN FUNCIONES PARA ARMAR TERCETOS **********************

//******************** FUNCIONES PARA ARMAR ASM *******************************
void generaASM( );
void generaVariables();
void generaMAS( );
void generaMENOS( );
void generaPOR( );
void generaDIV( );
void generaASIG( );
void generaBI( );
void generaCOMP(int );
void generaPRINT();
void imprimir_etiqueta( );
void generaEncabezado();
int buscar_variable(char[]);
int sacar_operando(char *);


int printReal, condicionReal=0;

FILE * cod_fuente;
int vec_auxi[101]; /* Vector que guarda las variables auxiliares que se van utilizando */
int indice_auxi;
int cont_terc;
int cant_etq_cond;
int indice_tercetos = 10;

//******************** FIN FUNCIONES PARA ARMAR ASM ***************************

//estados posibles
int nuevoestado[FILA][COL]={	1,2,4,5,F,2,F,F,F,F,F,F,F,11,12,13,14,8,9,10,0,21,
		  	 							1,1,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,
			      					F,2,F,F,F,3,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,
			      					F,3,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,
			      					4,4,F,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,F,
			      					F,F,F,F,6,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,
			      					6,6,6,6,7,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,F,
			      					6,6,6,0,7,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,F,
			      					F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,
                              F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,
                              F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,
                              F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,
                              F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,
                              F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,
                              F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,F,
								};

//------------------------------------------------------------------------------------------
// Rutinas para tratar los diferentes estados
//------------------------------------------------------------------------------------------
typedef void (*rutinas) ();
rutinas VVALE[FILA][COL] = {
/*       letra	   Digito	"			$			#			.			(			)			{			}			[			]			,			+			-			*			/			<			>			=			esp		EOF */
/*00*/	inId,		inRea,	inStr,	nada,		termi,	inRea,	termi,	termi,	termi,	termi,	termi,	termi,	termi,	inOp1,	inOp2,	inOp3,	inOp4,	inCo1,	inCo2,	inCo3,	nada,		nada,
/*01*/	adId,		adId,		finId,	finId,	finId,	finId,	finId,	finId,	finId,	finId,	finId,	finId,	finId,	finId,	finId,	finId,	finId,	finId,	finId,	finId,	finId,	finId,
/*02*/	error,	adRea,	finRea,	finRea,	finRea,	adRea,	finRea,	finRea,	finRea,	finRea,	finRea,	finRea,	finRea,	finRea,	finRea,	finRea,	finRea,	finRea,	finRea,	finRea,	finRea,	finRea,
/*03*/	finRea,	adRea,	finRea,	finRea,	finRea,	adRea,	finRea,	finRea,	finRea,	finRea,	finRea,	finRea,	finRea,	finRea,	finRea,	finRea,	finRea,	finRea,	finRea,	finRea,	finRea,	finRea,
/*04*/	adStr,	adStr,	finStr,	adStr,	adStr,	adStr,	adStr,	adStr,	adStr,	adStr,	adStr,	adStr,	adStr,	adStr,	adStr,	adStr,	adStr,	adStr,	adStr,	adStr,	adStr,	error,
/*05*/	nada,		nada,		nada,		nada,		nada,		nada,		nada,		nada,		nada,		nada,		nada,		nada,		nada,		nada,		nada,		nada,		nada,		nada,		nada,		nada,		nada,		nada,
/*06*/	nada,		nada,		nada,		nada,		nada,		nada,		nada,		nada,		nada,		nada,		nada,		nada,		nada,		nada,		nada,		nada,		nada,		nada,		nada,		nada,		nada,		nada,
/*07*/	nada,		nada,		nada,		nada,		nada,		nada,		nada,		nada,		nada,		nada,		nada,		nada,		nada,		nada,		nada,		nada,		nada,		nada,		nada,		nada,		nada,		nada,
/*08*/	finCo1,	finCo1,	finCo1,	finCo1,	finCo1,	finCo1,	finCo1,	finCo1,	finCo1,	finCo1,	finCo1,	finCo1,	finCo1,	finCo1,	finCo1,	finCo1,	finCo1,	finCo1,	finCo1,	finCo1,	finCo1,	finCo1,
/*09*/	finCo2,	finCo2,	finCo2,	finCo2,	finCo2,	finCo2,	finCo2,	finCo2,	finCo2,	finCo2,	finCo2,	finCo2,	finCo2,	finCo2,	finCo2,	finCo2,	finCo2,	finCo2,	finCo2,	finCo2,	finCo2,	finCo2,
/*10*/	finCo3,	finCo3,	finCo3,	finCo3,	finCo3,	finCo3,	finCo3,	finCo3,	finCo3,	finCo3,	finCo3,	finCo3,	finCo3,	finCo3,	finCo3,	finCo3,	finCo3,	finCo3,	finCo3,	finCo3,	finCo3,	finCo3,
/*11*/	finOp1,	finOp1,	finOp1,	finOp1,	finOp1,	finOp1,	finOp1,	finOp1,	finOp1,	finOp1,	finOp1,	finOp1,	finOp1,	finOp1,	finOp1,	finOp1,	finOp1,	finOp1,	finOp1,	finOp1,	finOp1,	finOp1,
/*12*/	finOp2,	finOp2,	finOp2,	finOp2,	finOp2,	finOp2,	finOp2,	finOp2,	finOp2,	finOp2,	finOp2,	finOp2,	finOp2,	finOp2,	finOp2,	finOp2,	finOp2,	finOp2,	finOp2,	finOp2,	finOp2,	finOp2,
/*13*/	finOp3,	finOp3,	finOp3,	finOp3,	finOp3,	finOp3,	finOp3,	finOp3,	finOp3,	finOp3,	finOp3,	finOp3,	finOp3,	finOp3,	finOp3,	finOp3,	finOp3,	finOp3,	finOp3,	finOp3,	finOp3,	finOp3,
/*14*/	finOp4,	finOp4,	finOp4,	finOp4,	finOp4,	finOp4,	finOp4,	finOp4,	finOp4,	finOp4,	finOp4,	finOp4,	finOp4,	finOp4,	finOp4,	finOp4,	finOp4,	finOp4,	finOp4,	finOp4,	finOp4,	finOp4};

//------------------------------------------------------------------------------------------

// Archivo que contiene el programa que se examina
FILE *archi;
FILE *stream;
FILE *tercetos;

//para tercetos
int UltVecIdValor, UltVecOperador, UltVecTer, UltVecAndOr;
char *VecIdValor[200];
char *VecOperador[200];
char *VecTer[200];
int  *VecAndOr[50];
char *declaraArray[MAXTAMID];

terceto Ter[200];

char NomID[MAXTAMID];
int NroTerceto;


/******************************************************************************/
/************************* PROGRAMA PRINCIPAL*********************************/
/******************************************************************************/

int main ()
{
	// Almacena token retornado por yylex
	//int resultado;
	line = 0;
	UltVecIdValor = 0;
	UltVecOperador = 0;
   UltVecTer = 0;
   UltVecAndOr = 0;
   limpiaTS();
   strcpy(IndiceArray,"");

	NroTerceto = 0;
  	stream = fopen("resultado.txt", "w+");
   tercetos = fopen("tercetos.txt", "w+");

	// Apertura del archivo, tratamiento de error
	if ( (archi=fopen("miprograma.txt","rt")) == NULL )
	{
		printf("\nERROR: El archivo no pudo abrirse. Verifique que exista (miprograma.txt)");
	   printf("\nPresione una tecla para continuar...");
	   getch();
      fprintf(stream,"%s","\No se pudo abrir el archivo!\n");
		exit(0);
	}

	// Exito en la apertura
	printf("\nEl Archivo miprograma.txt fue abierto OK.-");
	printf("\nPresione una tecla para continuar...\n");
	getch();
   fprintf (stream,"%s","------------------------ Gramática ------------------------\n");
   yyparse();
	// Cierro el archivo
	fclose(archi);
   fclose(stream);
   return 1;
}//fin main
/******************************************************************************/

//------------------------------------------------------------------------------
//											FUNCIONES
//------------------------------------------------------------------------------

/******************************************************************************/
//----------------------------------  YYLEX ----------------------------------
/******************************************************************************/
int yylex ()
{
	int evento;  // es la columna de la tabla de estados
	int nestado; // nuevo estado, se obtiene de la tabla de estados
	estado=0;    // siempre que entre a yylex, estado se resetea a cero

   if ( pendiente==0 )
	  caracter=fgetc(archi);//leo el 1er caracter del archivo

	while ( caracter!=EOF ) 	// mientras no sea el final de la linea
	{
      //printf(" %c",caracter);
		// Para saber en que linea estoy del archivo!
		if (caracter == '\n')
			line = line + 1;
		evento  = getevent();    // veo en que columna me posiciono
		VVALE[estado][evento](); // obtener la rutina asociada al estado y  ejecutarla
		nestado = nuevoestado[estado][evento]; // nuevo estado
	   estado  = nestado;
		if(estado == F)  // F=999 --> term
		{
			estado = 0;
			return token; // retorna token reconocido
		}
	   if (pendiente==0) // si no hay caracteres pendientes por reconocer
			caracter = fgetc(archi); //lee otro caracter del archivo

      if(caracter==EOF)
      {
       token = FINA;
       return -1;
      }

	} // fin while de lectura de archivo
	return token;
}//fin yylex
/******************************************************************************/


/******************************************************************************/
//----------------------------- TESTEO DE CARACTERES LEIDOS-------------------
/******************************************************************************/
int getevent()
{
	// ------------------------------------------------------------------
	// NOTA: GetEvent devuelve 1 número menos que lo que esta en la
	//			tabla, dado que el array comienza de cero!!!
	// ------------------------------------------------------------------

	pendiente=0;

   if(caracter==EOF)
    {
     printf("Fin de archivo");
     getch();
     token = FINA;
     return (21);
    }

	if (isalpha(caracter)) // testea si es caracter
	{
		return 0; //es id
   }

	if (isdigit(caracter)) // testea si es un numero
	{
   	switch(estado)
		{
   		case 1:	return 0; // es id
         case 2:	return 1; // es cte_real (parte entera)
         case 3:	return 1; // es cte_real (parte real)
   		default: return 1; // es cte_real
   	}
	}

	if(caracter=='"') return 2;
   if(caracter=='$') return 3;
   if(caracter=='#') return 4;
   if(caracter=='.') return 5;
	if(caracter=='(') return 6;
	if(caracter==')') return 7;
	if(caracter=='{') return 8;
	if(caracter=='}') return 9;
	if(caracter=='[') return 10;
	if(caracter==']') return 11;
   if(caracter==',') return 12;
	if(caracter=='+') return 13;
	if(caracter=='-') return 14;
	if(caracter=='*') return 15;
	if(caracter=='/') return 16;
	if(caracter=='<') return 17;
	if(caracter=='>') return 18;
	if(caracter=='=') return 19;
   if(caracter=='\n')return 20;
	if(isspace(caracter))return 20;
	return 1;
} // fin GetEvent
/******************************************************************************/

/******************************************************************************/
//-------------------------------- ID ------------------------------------------
/******************************************************************************/
void inId() //inicializa identificador
{
	cont_buff = 0;
	buffer[cont_buff] = caracter; // almacena 1er caracter valido como id
}

void adId() // almacena los siguientes caracteres validos como id
{
	buffer[++cont_buff] = caracter;
}

void finId() // finaliza id
{
   int i;
	char *cad;
	pendiente=1; // porque hay en buffer caracteres que deben ser reconocidos
	buffer[++cont_buff] = '\0'; // para señalar el fin de lo almacenado

   if((cont_buff-1) > MAXTAMCTE)
    {
    token = ERROR;
    printf ("Desbordamiento en ID / Error");
    getch();
    }
   else
    {
    token = ID;

   // verificacion de lo almacenado en buffer para reconocer palabras reservadas
   for (i=0;i<15;i++) // se recorre palabra por palabra del array de palabras reserv.
	{
		if (strcmp(buffer,reservadas[i])==0) // comparacion del contenido del buffer
													    // con la palabra reservada leida
      {
			token  = tokenreservadas[i]; // reconociemiento de la palabra reservada
			yylval = -1; // no se almacena en la tabla de simbolos
			break;
      }
	};

  	if (token==ID) // si el contenido no es palabra reservada
   {
		cad = malloc(sizeof(char [MAXTAMID])); // Reserva memoria para una cadena donde se
			              						// almacenará lo que se guardará en la tabla de simbolos
		strcpy(cad, "ID_");   // los identificadores se almacenaran con un ID_
						  	       // para reconocerlos dentro de la tabla de simbolos
		strcat (cad, (char *)&buffer);
      strcpy (NomID, "");
      strcat (NomID, cad);
		yylval = agregar(cad , token); // posicion donde fue almacenado el id
	};
  };
}//id agregado a la tabla de simbolos
/******************************************************************************/

/******************************************************************************/
//-----------------------------CTES--------------------------------------------
/******************************************************************************/
void inRea() // inicializa constante real
{
	cont_buff=0;
   if(caracter == '.')
   {
     buffer[cont_buff] = '0';
     cont_buff++;
   }
	buffer[cont_buff] = caracter; // almacena 1er caracter valido como cte.
}

void adRea () // almacena los siguientes caracteres válidos como cte.
{
	buffer[++cont_buff] = caracter;
}

void finRea() // Finaliza cte.
{
	pendiente = 1; // porque hay en buffer caracteres que deben ser reconocidos

   //if(buffer[++cont_buff])
	buffer[++cont_buff] = '\0'; // para señalar el fin de lo almacenado

   if((cont_buff-1) > 10)
    {
    token = ERROR;
    printf ("Desbordamiento en Real / Error");
    getch();
    }
   else
    {
    token = MIREAL;
    strcpy (NomID,"");
    strcat (NomID, (char *)&buffer);

    yylval = agregar(buffer,token);
    // posicion donde fue almacenada la
   }										  //cteReal agregada en la tabla de simbolos
}


void inStr() // inicializa constante string
{
	cont_buff=0;
	buffer[cont_buff] = caracter; // almacena 1er caracter valido como cte.
}

void adStr () // almacena los siguientes caracteres validos como cte.
{
   if(cont_buff<MAXTAMID)
	    buffer[++cont_buff] = caracter;
   else
   	token = ERROR;
}

void finStr() // Finaliza cte.
{
	pendiente = 0; // porque hay en buffer caracteres que deben ser reconocidos
   buffer[++cont_buff] = caracter;
	buffer[++cont_buff] = '\0'; // para señalar el fin de lo almacenado

   if((cont_buff-1) > MAXTAMID)
    {
    token = ERROR;
    printf ("Desbordamiento en String / Error");
    getch();
    }
   else
    {
       token = MISTRING;
	    strcpy (NomID, (char *)&buffer);
       yylval = agregar(buffer,token);
    }
} // posicion donde fue almacenada la cte  - cteString agregado en la tabla de simbolos
/******************************************************************************/

/******************************************************************************/
//---------------------------- TERMINALES--------------------------------------
/******************************************************************************/
void termi () // identifica caracteres terminales y los almacena
{
   if(caracter=='(')  token=ABREPAREN;
   if(caracter==')')  token=CIERRAPAREN;
   if(caracter=='{')  token=ABRELLAVE;
   if(caracter=='}')  token=CIERRALLAVE;
   if(caracter=='[')  token=ABRECORCH;
   if(caracter==']')  token=CIERRACORCH;
   if(caracter=='+')  token=MAS;
   if(caracter=='-')  token=MENOS;
   if(caracter=='*')  token=MULTIP;
   if(caracter=='/')  token=COCIENTE;
   if(caracter=='.')  token=PUNTO;
   if(caracter==',')  token=COMA;
   if(caracter==EOF)  token=FINA;
	yylval=-1;  //indica que no se guarda en la tabla de simbolos
}
/******************************************************************************/

/******************************************************************************/
//-------------------------- COMPARADORES--------------------------------------
/******************************************************************************/
void inCo1() // inicializa comparador  <=, <> o <
{
	cont_buff = 0;
	buffer[cont_buff] = caracter; // almacena 1er carac. valido como comparador(<)
}

void finCo1 ()
{
	pendiente=1; // porque tiene almacenado un <

	if(caracter=='=') // si leyo un =
	{
   	token = MENIGU; // almacena lo reconocido
		pendiente = 0;		// ya no hay caracteres pendientes
   }
	else
   {

		if (caracter=='>') 	//	si se leyo un >
		{
			token = DISTINTO;	//	almacena lo leido
			pendiente = 0;		//ya no hay caracteres pendientes
		}
		else
			token  = MENOR;	// si se leyo otra cosa, se almacena solo <
  	}
  	yylval = -1;		// no se guarda en la tabla de simbolos
}


void inCo2() //inicializa comparador >=
{
	cont_buff=0;
	buffer[cont_buff]=caracter;  // almacena 1er caracter valido como comparador
}

void finCo2()
{
	pendiente=1; // porque tiene almacenado un >
	if(caracter=='=') // si se lee un =
	{
		token = MAYIGU; // almacena lo reconocido
		pendiente = 0;	 	// ya no tiene caracteres pendientes
	}
	else // si leyo otra cosa
		token = MAYOR; // almacena lo reconocido

	yylval = -1; // no almacena en la tabla de simbolos
}

void inCo3() //inicializa comparador ==
{
	cont_buff = 0;
	buffer[cont_buff] = caracter; // almacena 1er caracter valido como comparador
}

void finCo3()
{
	pendiente = 1; // porque tiene almacenada un =
	if(caracter=='=') // si lee otro =
	{
		token=IGUAL; // almacena lo reconocido
		pendiente=0; // ya no hay caracteres pendientes
   }
	else // si lee otra cosa
		token=ASIG; // almacena lo reconocido

	yylval=-1; // no se guarda en la tabla de simbolos
}
/******************************************************************************/


/******************************************************************************/
//----------------------------------- ASIG.ESPECIALES------------------------
/******************************************************************************/

void inOp1() //inicializa asignación  +=
{
	cont_buff = 0;
	buffer[cont_buff] = caracter; // almacena 1er caracter valido como comparador
}

void finOp1()
{
	pendiente = 1; // porque tiene almacenada un +
	if(caracter=='=') // si lee un =
	{
		token=ASIGMAS; // almacena lo reconocido
		pendiente=0; // ya no hay caracteres pendientes
   }
	else // si lee otra cosa
		token=MAS; // almacena lo reconocido

	yylval=-1; // no se guarda en la tabla de simbolos
}

void inOp2() //inicializa asignación  -=
{
	cont_buff = 0;
	buffer[cont_buff] = caracter; // almacena 1er caracter valido como comparador
}

void finOp2()
{
	pendiente = 1; // porque tiene almacenada un -
	if(caracter=='=') // si lee un =
	{
		token=ASIGMENOS; // almacena lo reconocido
		pendiente=0; // ya no hay caracteres pendientes
   }
	else // si lee otra cosa
		token=MENOS; // almacena lo reconocido

	yylval=-1; // no se guarda en la tabla de simbolos
}

void inOp3() //inicializa asignación  *=
{
	cont_buff = 0;
	buffer[cont_buff] = caracter; // almacena 1er caracter valido como comparador
}

void finOp3()
{
	pendiente = 1; // porque tiene almacenada un *
	if(caracter=='=') // si lee un =
	{
		token=ASIGMULT; // almacena lo reconocido
		pendiente=0; // ya no hay caracteres pendientes
   }
	else // si lee otra cosa
		token=MULTIP; // almacena lo reconocido

	yylval=-1; // no se guarda en la tabla de simbolos
}

void inOp4() //inicializa asignación  /=
{
	cont_buff = 0;
	buffer[cont_buff] = caracter; // almacena 1er caracter valido como comparador
}

void finOp4()
{
	pendiente = 1; // porque tiene almacenada un /
	if(caracter=='=') // si lee un =
	{
		token=ASIGCOCIENTE; // almacena lo reconocido
		pendiente=0; // ya no hay caracteres pendientes
   }
	else // si lee otra cosa
		token=COCIENTE; // almacena lo reconocido

	yylval=-1; // no se guarda en la tabla de simbolos
}

/******************************************************************************/
//----------------------------------- ESPACIOS---------------------------------
/******************************************************************************/
void nada ()
{
	//buffer[0] = '\0';
   //pendiente = 1;
}
/******************************************************************************/

void error()
{
// flag=0;
token = ERROR;
printf("\n No se esperaba '%c' \n",caracter);
}

/******************************************************************************/
//------------------ 		TABLA DE SIMBOLOS			----------------------------
/******************************************************************************/
int agregar ( char *nombre, int val )
{
	int x;
	for (x=0; x<cantSimbolos; x++ )
		if (simbolo[x].flag==1 || simbolo[x].flag==2)//para saber si el token ya esta en la tabla
	       if (strcmp (nombre,simbolo[x].nombre)==0)
           {
            return x;
           }
	for (x=0; x<100 ; x++)
	if (simbolo[x].flag==0)
	 {
		strcpy(simbolo[x].nombre,nombre);    //token reconocido
		simbolo[x].tipo=val;
		simbolo[x].flag=1;					   //para indicar que ya se almaceno en la tabla
      simbolo[x].limite=0;                //por defecto le asigno 0 a todos.
      if(val==271)
       simbolo[x].valor=atoi(nombre);
      else
       simbolo[x].valor=0;
      simbolo[x].indice=0;
      cantSimbolos++;
		return x;
	 }
   return x;
}//retorna posicion en la tabla de simbolos

//---------------------------------------------------------------------------------

int setFlag (char *nombre, int tipo) // cambia de estado a la variable despues de un DIM
{
	int x;
   for (x=0; x<cantSimbolos; x++)
	 if (strcmp(nombre,simbolo[x].nombre)==0)
     {
      simbolo[x].flag=2;
      simbolo[x].value=tipo;
      return 1;
	  }
   return 0;
}


int setLimite (char *nombre, char* elLimite) // asigna el tamaño del indice de un array en el DIM
{
	int x,nn;
   int a=strlen(elLimite);
   char aux[MAXTAMCTE];
   a--;
   x=0;
	for(x=0; x<a; x++)
    {
     aux[x]= elLimite[x];
    }
   aux[x++]= '\0';
   //nn=atoi(aux);
   nn=atoi(elLimite);
   for (x=0; x<cantSimbolos; x++)
	 if (strcmp(nombre,simbolo[x].nombre)==0)
     {
       simbolo[x].limite=nn;
       simbolo[x].tipo= 350;
       simbolo[x].indice=-1;
       return 1;
	  }
   nn=x;  
   return 0;
}


void verificaVariable(char *nombre)
{
	int x;
   for (x=0; x<cantSimbolos; x++)
	 if (strcmp(nombre,simbolo[x].nombre)==0)
     {
      if(simbolo[x].flag!=2)
 			{
         printf ("\nLa variable %s no fue declarada. El proceso se cancelara.-", nombre);
         getch();
      	exit(0);
      	}
      }
}

char * verificaArray(char *nombre, char * elLimite)
{
	int x1;
   char * ret[50];
   char * auxitoa;
   strcpy(auxitoa,"");
   for (x1=0; x1<cantSimbolos; x1++)
	 if (strcmp(nombre,simbolo[x1].nombre)==0)
     {
      if(simbolo[x1].flag!=2)
 			{
         printf ("\nLa variable %s no fue declarada. El proceso se cancelara.-", nombre);
         getch();
      	exit(0);
      	}
      else
         {
          int nn=atoi(elLimite);
          //muestraTS();
          if(nn >= simbolo[x1].limite)
          {
          	printf ("\nEl indice es incorrecto");
         	getch();
      	   exit(0);
          }
          strcpy(ret,"[");
          strcat(ret,itoa(nn,auxitoa,10));
          strcat(ret,"]");
          return ret;
         }
      }
      return NULL;
}

/******************************************************************************/

int yyerror(msg)
char *msg;
{
(void)fprintf(stderr, "%s\n", msg);
return(0);
}

/******************************************************************************/

void ApilarOperando(char * nombre)
{
	VecIdValor[UltVecIdValor] = malloc(sizeof(char [MAXTAMCTE]));
   	//if(strchr(nombre,'\"'))
      //	nombre="nada";
	strcpy(VecIdValor[UltVecIdValor],nombre);
	UltVecIdValor++;
}

//Apila Operadores
void ApilarOperador(char * nombre)
{
	VecOperador[UltVecOperador] =  malloc(sizeof(char [MAXTAMCTE]));
	strcpy(VecOperador[UltVecOperador],nombre);
	UltVecOperador++;
}

//Desapila Id , Cte o nro de tercetos (OPERANDOS)
char * desapilarOperando()
{
	//char aux[MAXTAMCTE];
	UltVecIdValor--;
   //strcpy(aux,VecIdValor[UltVecIdValor]);
   //free(VecIdValor[UltVecIdValor]);
	//return aux;
   return VecIdValor[UltVecIdValor];
}

//Desapila Operadores
char * desapilarOperador()
{
	//char aux[MAXTAMCTE];
	UltVecOperador--;
   //strcpy(aux,VecOperador[UltVecOperador]);
   //free(VecOperador[UltVecOperador]);
   //return aux ;
   return VecOperador[UltVecOperador];
}

//Finaliza Operador
void FinOperador()
{
	char * nomb[3];
   char str[MAXTAMCTE];
   char * auxi;

	nomb[0] = desapilarOperando();
	nomb[1] = desapilarOperando();
   nomb[2] = desapilarOperador();

	auxi = malloc(sizeof(char[50]));
   strcpy(auxi,"[");
   strcat(auxi,itoa(NroTerceto,str,10));
   strcat(auxi,"]");

   ApilarOperando(auxi);

   strcpy(Ter[NroTerceto].op1,nomb[2]);
   strcpy(Ter[NroTerceto].op2,nomb[1]);
   strcpy(Ter[NroTerceto].op3,nomb[0]);

   NroTerceto++;
}

void ReglaFinal(){
	int i;

   fprintf(tercetos,"\nCantidad de tercetos: %d\n",NroTerceto);
   fprintf(tercetos,"----------------------------------------\n");
   printf("\n\nCantidad de tercetos: %d\n",NroTerceto);
   printf("----------------------------------------\n");
	for(i=0; i<NroTerceto; i++){
     printf( "\n\n %d ( %s, %s, %s) " , i, Ter[i].op1, Ter[i].op2, Ter[i].op3);
     fprintf(tercetos,"%d\t(%s, %s, %s)\n", i, Ter[i].op1, Ter[i].op2, Ter[i].op3);
	}
   fclose(tercetos);
   muestraTS();
   generaASM();
}

void ArmaTerBranch(int EsWhile)
{
   char str[MAXTAMCTE];
   if(UltVecAndOr > 0 )
	 	if(desapilarLogicos() == 0)
		    CompletaFaltante(1);
      else
      	UltVecAndOr++;

   strcpy(Ter[NroTerceto].op1,ObtenerBranch());
   if (EsWhile == 1)
   	{
		strcpy(Ter[NroTerceto].op2,"[");
		strcat(Ter[NroTerceto].op2,itoa(desapilarTerceto(),str,10));
      strcat(Ter[NroTerceto].op2,"]");
      }
   else
	  {
     	ApilarTerceto();
	   strcpy(Ter[NroTerceto].op2,"");
     }

   strcpy(Ter[NroTerceto].op3,"@");
   NroTerceto++;

   if(UltVecAndOr > 0 )
   	if(desapilarLogicos() == 0)
	      CompletaFaltante(1);
      else
      	UltVecAndOr++;
}

//Apila Terceto
void ApilarTerceto(){
	VecTer[UltVecTer] = NroTerceto;
   UltVecTer++;
}

//Desapila Terceto
int desapilarTerceto(){
	UltVecTer--;
   return VecTer[UltVecTer];
}

void CompletaFaltante(int op)
{
	int aux;
   char * aux2[5];

   char str[MAXTAMCTE];
	aux = desapilarTerceto();

      strcpy(aux2,"[");
      strcat(aux2,itoa(NroTerceto + op,str,10));
      strcat(aux2,"]");
  		strcpy(Ter[aux].op2,aux2);

	if(UltVecAndOr > 0 )
	 	if(desapilarLogicos() == 1)
		    CompletaFaltante(op);
      else
      	UltVecAndOr++;

}

//Apila AND u OR
void ApilarLogicos(int aux){

	VecAndOr[UltVecAndOr] = aux;
   UltVecAndOr++;
}

//Desapila AND u OR
int desapilarLogicos(){
   UltVecAndOr--;
	return VecAndOr[UltVecAndOr];
}

void FinPrint()
{
	char * nomb[2];

	nomb[0] = desapilarOperando();
   nomb[1] = desapilarOperador();

   strcpy(Ter[NroTerceto].op1,nomb[1]);
   strcpy(Ter[NroTerceto].op2,nomb[0]);
   strcpy(Ter[NroTerceto].op3,"@");

   NroTerceto++;
}

void muestraTS()
{
	FILE * tabla;
	if ( (tabla=fopen("tablasimbolo.txt","w+")) == NULL )
	{
		printf("\nERROR: El archivo no pudo abrirse. Verifique que exista (tablasimbolo.txt)");
	   printf("\nPresione una tecla para continuar...");
	   getch();
 	}
   else
   {
		if(cantSimbolos==0)
 			{
				fprintf (tabla,"%s"," no se encontraron elementos en la Tabla de simbolos. \n");
 			}
		else
 			{
 				int x;
  				fprintf (tabla,"%s"," Var Nombre - Token - flag - Tipo dato - Limite - Valor - Indice\n");
      		fprintf (tabla,"%s"," -------------------------------- \n");
		 		for (x=0; x<cantSimbolos; x++)
         	 fprintf (tabla,  " %s        - %d      - %d   - %d    - %d     - %f    - %d\n", simbolo[x].nombre, simbolo[x].tipo, simbolo[x].flag, simbolo[x].value, simbolo[x].limite, simbolo[x].valor, simbolo[x].indice);
   		}
      fclose(tabla);
 	}
}

void limpiaTS()
{
   int x;
  	for (x=0; x<100; x++)
     {
    	  strcpy(simbolo[x].nombre,"");
        simbolo[x].tipo=0;
        simbolo[x].flag=0;
        simbolo[x].value=0;
        simbolo[x].valor=0;
        simbolo[x].indice=0;
        simbolo[x].limite=0;
     }
}


char* ObtenerBranch() {
	char aux[20];
	strcpy(aux, Ter[NroTerceto-1].op1);

	if(InvierteCondicion()==1)
	{
		if (strcmp(aux,"<") == 0 )
			return "Bmayig";
		if (strcmp(aux,"<=") == 0 )
			return "Bmayor";
		if (strcmp(aux,">") == 0 )
			return "Bmenig";
		if (strcmp(aux,">=") == 0 )
			return "Bmenor";
		if (strcmp(aux,"<>") == 0 )
			return "Bigual";
		if (strcmp(aux,"==") == 0 )
			return "Bdistin";
		else
			return "BI";
	}
	else
	{
		if (strcmp(aux,"<") == 0 )
			return "Bmenor";
		if (strcmp(aux,"<=") == 0 )
			return "Bmenig";
		if (strcmp(aux,">") == 0 )
			return "Bmayor";
		if (strcmp(aux,">=") == 0 )
			return "Bmayig";
		if (strcmp(aux,"<>") == 0 )
			return "Bdistin";
		if (strcmp(aux,"==") == 0 )
			return "Bigual";
		else
			return "BI";
	}
}

int InvierteCondicion()
{
	int aux;
	int flag;

	if (UltVecAndOr > 0)
		aux = desapilarLogicos();
	else
	{
		aux=0;
		flag = 1;
	}

	if(aux == 1 )
		{
			ApilarLogicos(1);
			return 1;
		}
	else
		if(aux==2)
			return 1;

	if (flag == 0) ApilarLogicos(0);

  	if(EsOr==0)
		return 1;

	EsOr=0;
   return 0;

}

/******************************************************************************/
//----------------------------------  ASM -------------------------------------
/******************************************************************************/

void generaASM ()
{
   cont_terc = 0;

	if ( (cod_fuente = fopen ("fuente.asm", "w") ) == NULL)
   {
     	printf ("\n\nNo se pudo generar el archivo Assembler...\n");
      printf ("Presione una tecla para salir del programa...\n");
      getch ();
      exit (1);
   }
//   InicializaVec_aux( );
//   modificaTSyMAT();

   generaEncabezado(); //pone el encabezado con los parametros adecuados

   indice_auxi=0;
   cant_etq_cond =1;

	while(cont_terc < indice_tercetos)
   {
		if(!(strcmp(Ter[cont_terc].op1,"+"))) 	  {generaMAS();	}
      if(!(strcmp(Ter[cont_terc].op1,"-"))) 	  {generaMENOS(); }
      if(!(strcmp(Ter[cont_terc].op1,"*"))) 	  {generaPOR();   }
	 	if(!(strcmp(Ter[cont_terc].op1,"/")))    {generaDIV();   }
	 	if(!(strcmp(Ter[cont_terc].op1,"=")))    {generaASIG();  }

      if(!(strcmp(Ter[cont_terc].op1,"Bdistin")))   {generaCOMP(1); }
    	if(!(strcmp(Ter[cont_terc].op1,"Bmayig")))    {generaCOMP(2); }
      if(!(strcmp(Ter[cont_terc].op1,"Bmayor")))    {generaCOMP(3); }
    	if(!(strcmp(Ter[cont_terc].op1,"Bmenig")))    {generaCOMP(4); }
    	if(!(strcmp(Ter[cont_terc].op1,"Bmenor")))    {generaCOMP(5); }
    	if(!(strcmp(Ter[cont_terc].op1,"Bigual")))    {generaCOMP(6); }
      
	 	if(!(strcmp(Ter[cont_terc].op1,"BI"))) 		 {generaBI();    }

   	/*
      if(!(strcmp(Ter[cont_terc].op1,"PRINT"))) 	 {generaPRINT(); }
	 	if(!(strcmp(Ter[cont_terc].op1,"BF"))) { /*printf("BF\n")* /;generaBF(); }
    	if(!(strcmp(Ter[cont_terc].op1,"BV"))) {  /*printf("BV\n")* /;generaBV();}
    	if(!(strcmp(Ter[cont_terc].op1,"E"))) { /*printf("ETIQUETA\n")* /;generaETIQUETA(); }
*/

    	cont_terc +=1;
   }

   fprintf(cod_fuente, "\n\tmov dx,OFFSET msgPRESIONE\t;imprimir mensaje de espera\n");
   fprintf(cod_fuente, "\tmov ah,09\n");
   fprintf(cod_fuente, "\tint 21h\n");
   fprintf(cod_fuente, "\tmov ah,1\t;pausa, espera que oprima una tecla\n");
   fprintf(cod_fuente, "\tint 21h\n"); //fin de ejecucion
   fprintf(cod_fuente, "\tmov ax, 4C00h\t\t\t;fin de ejecucion\n");
   fprintf(cod_fuente, "\tint 21h\n");

   generaVariables();
   printf("\n\nSE GENERO EL CODIGO ASM en fuente.asm\n");
}


//------------------------------------------------------------------------------------------------------------------
//---------------------------------------- GENERA ENCABEZADOS ------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------

void generaEncabezado( )
{
	fprintf(cod_fuente,";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n");
	fprintf(cod_fuente,"; \t       LENGUAJES Y COMPILADORES\t             \n");
	fprintf(cod_fuente,";    Generacion de Assembler a partir de Tercetos    \n");
	fprintf(cod_fuente,"; \t\t         2006                        \n");
	fprintf(cod_fuente,";\tCasielles Martin - Mazur Christian - Perez Sebastián\t \n");
   fprintf(cod_fuente,";;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;\n");
   fprintf(cod_fuente,"\n.MODEL\tLARGE\n");
   fprintf(cod_fuente,".386\n");
   fprintf(cod_fuente,".STACK 200h\n");
   fprintf(cod_fuente,"\n.CODE\n");
   fprintf(cod_fuente,"\n;Codigo Assembler:\n");
   fprintf(cod_fuente,";-------------------\n");
   fprintf(cod_fuente,"\n\tmov ax,@DATA	;limpia buffer\n");
   fprintf(cod_fuente,"\tmov ds,ax\n");
   fprintf(cod_fuente,"\tmov es,ax\n\n");
}

//------------------------------------------------------------------------------------------------------------------
//------------------------------------------------ MAS -------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------
void generaMAS( )
{
	int flag_op1 = 0;
   int flag_op2 = 0;
   int op1, op2;
	if( strnicmp(Ter[cont_terc].op2, "[", 1) == 0)
   {
   	flag_op1 = 1;
      op1=sacar_operando(Ter[cont_terc].op2);
   }
	if( strnicmp( Ter[cont_terc].op3, "[", 1) == 0)
   {
   	flag_op2 = 1;
      op2=sacar_operando(Ter[cont_terc].op3);
	}
   if (flag_op1 == 1 && flag_op2 == 1)
   {
      indice_auxi -=1;
      vec_auxi[cont_terc+1] = vec_auxi[op1];
      fprintf(cod_fuente, "\tFLD _aux_%d\n", vec_auxi[op1]);
      fprintf(cod_fuente, "\t;---Se va a efectuar una suma---\n");
   	fprintf(cod_fuente, "\t\tFADD _aux_%d\n", vec_auxi[op2]);
      fprintf(cod_fuente, "\t\tFSTP _aux_%d, ax\n", vec_auxi[op1]);
   }
   if (flag_op1 == 0 && flag_op2 == 0)
   {
      indice_auxi +=1;
      vec_auxi[cont_terc+1] = indice_auxi;
      fprintf(cod_fuente, "\t\tFLD %s\n",Ter[cont_terc].op2);
      fprintf(cod_fuente, "\t;---Se va a efectuar una suma---\n");
      fprintf(cod_fuente, "\t\tFADD %s\n",Ter[cont_terc].op3);
      fprintf(cod_fuente, "\t\tFSTP _aux_%d\n", indice_auxi);
	}
	if (flag_op1 == 1 && flag_op2 == 0)
   {
      vec_auxi[cont_terc+1] = vec_auxi[op1];
      fprintf(cod_fuente, "\tFLD _aux_%d\n",vec_auxi[op1]);
      fprintf(cod_fuente, "\t;---Se va a efectuar una suma---\n");
      fprintf(cod_fuente, "\t\tFADD %s\n",Ter[cont_terc].op3);
      fprintf(cod_fuente, "\t\tFSTP _aux_%d\n", vec_auxi[op1]);
   }
	if (flag_op1 == 0 && flag_op2 == 1)
   {
      vec_auxi[cont_terc+1] = vec_auxi[op2];
      if (buscar_variable (Ter[cont_terc].op2)==2)
      fprintf(cod_fuente, "\t\tFLD %s\n",Ter[cont_terc].op2);
      fprintf(cod_fuente, "\t;---Se va a efectuar una suma---\n");
   	fprintf(cod_fuente, "\t\tFADD _aux_%d\n",vec_auxi[op2]);
      fprintf(cod_fuente, "\t\tFSTP _aux_%d\n", vec_auxi[op2]);

    }
    fflush(cod_fuente);
}

//-------------------------------- MENOS ---------------------------------------
void generaMENOS( )
{
	int flag_op1 = 0;
   int flag_op2 = 0;
   int op1, op2;

	if( strnicmp(Ter[cont_terc].op2, "[", 1) == 0)
   {
   	flag_op1 = 1;
      op1=sacar_operando(Ter[cont_terc].op2);
   }

	if( strnicmp( Ter[cont_terc].op3, "[", 1) == 0)
   {
   	flag_op2 = 1;
   	op2 = sacar_operando(Ter[cont_terc].op3);
	}

   if (flag_op1 == 1 && flag_op2 == 1)
   {
      indice_auxi -=1;
      vec_auxi[cont_terc+1] = vec_auxi[op1];
      fprintf(cod_fuente, "\tFLD _aux_%d\n", vec_auxi[op1]);
      fprintf(cod_fuente, "\t;---Se va a efectuar una resta---\n");
   	fprintf(cod_fuente, "\t\tFSUB _aux_%d\n", vec_auxi[op2]);
      fprintf(cod_fuente, "\t\tFSTP _aux_%d\n", vec_auxi[op1]);
   }

   if (flag_op1 == 0 && flag_op2 == 0)
   {
      indice_auxi +=1;
      vec_auxi[cont_terc+1] = indice_auxi;
      fprintf(cod_fuente, "\tFLD  %s\n",Ter[cont_terc].op2);
      fprintf(cod_fuente, "\t;---Se va a efectuar una resta---\n");
      fprintf(cod_fuente, "\t\tFSUB %s\n",Ter[cont_terc].op3);
      fprintf(cod_fuente, "\t\tFSTP _aux_%d\n", indice_auxi);
   }

	if (flag_op1 == 1 && flag_op2 == 0)
   {
      vec_auxi[cont_terc+1] = vec_auxi[op1];
      fprintf(cod_fuente, "\tFLD _aux_%d\n",vec_auxi[op1]);
      fprintf(cod_fuente, "\t;---Se va a efectuar una resta---\n");
      fprintf(cod_fuente, "\t\tFSUB %s\n",Ter[cont_terc].op3);
      fprintf(cod_fuente, "\t\tFSTP _aux_%d\n", vec_auxi[op1]);
   }

	if (flag_op1 == 0 && flag_op2 == 1)
   {
      vec_auxi[cont_terc+1] = vec_auxi[op2];
      fprintf(cod_fuente, "\tFLD %s\n",Ter[cont_terc].op2);
      fprintf(cod_fuente, "\t;---Se va a efectuar una resta---\n");
   	fprintf(cod_fuente, "\t\tFSUB _aux_%d\n",vec_auxi[op2]);
      fprintf(cod_fuente, "\t\tFSTP _aux_%d\n", vec_auxi[op2]);

   }
}

//----------------------------- PRODUCTO --------------------------------------------
void generaPOR( )
{
   int flag_op1 = 0;
   int flag_op2 = 0;
   int op1, op2;

	if( strnicmp(Ter[cont_terc].op2, "[", 1) == 0)
   {
   	flag_op1 = 1;
      op1=sacar_operando(Ter[cont_terc].op2);
   }
	if( strnicmp( Ter[cont_terc].op3, "[", 1) == 0)
   {
   	flag_op2 = 1;
      op2=sacar_operando(Ter[cont_terc].op3);
	}

   if (flag_op1 == 1 && flag_op2 == 1)
   {
      indice_auxi -=1;
      vec_auxi[cont_terc+1] = vec_auxi[op1];
      fprintf(cod_fuente, "\tFLD _aux_%d\n", vec_auxi[op1]);
      fprintf(cod_fuente, "\t;---Se va a efectuar un producto---\n");
      fprintf(cod_fuente, "\t\tFMUL _aux_%d\n", vec_auxi[op2]);
      fprintf(cod_fuente, "\t\tFSTP _aux_%d\n", vec_auxi[op1]);
   }

   if (flag_op1 == 0 && flag_op2 == 0)
   {
      indice_auxi +=1;
      vec_auxi[cont_terc+1] = indice_auxi;
      fprintf(cod_fuente, "\tFLD %s\n",Ter[cont_terc].op2);
      fprintf(cod_fuente, "\t;---Se va a efectuar un producto---\n");
      fprintf(cod_fuente, "\t\tFMUL %s\n",Ter[cont_terc].op3);
      fprintf(cod_fuente, "\t\tFSTP _aux_%d\n", indice_auxi);
   }

	if (flag_op1 == 1 && flag_op2 == 0)
   {
      vec_auxi[cont_terc+1] = vec_auxi[op1];
      fprintf(cod_fuente, "\tFLD _aux_%d\n",vec_auxi[op1]);
      fprintf(cod_fuente, "\t;---Se va a efectuar un producto---\n");
      fprintf(cod_fuente, "\t\tFMUL %s\n",Ter[cont_terc].op3);
      fprintf(cod_fuente, "\t\tFSTP _aux_%d\n", vec_auxi[op1]);
   }

	if (flag_op1 == 0 && flag_op2 == 1)
   {
      vec_auxi[cont_terc+1] = vec_auxi[op2];
      fprintf(cod_fuente, "\tFLD %s\n",Ter[cont_terc].op2);
      fprintf(cod_fuente, "\t;---Se va a efectuar un producto---\n");
   	fprintf(cod_fuente, "\t\tFMUL _aux_%d\n",vec_auxi[op2]);
      fprintf(cod_fuente, "\t\tFSTP _aux_%d\n", vec_auxi[op2]);
   }
}

//-------------------------------- COCIENTE ------------------------------------
void generaDIV( )
{
	int flag_op1 = 0;
   int flag_op2 = 0;
   int op1, op2;

	if( strnicmp( Ter[cont_terc].op2, "[", 1) == 0)
   {
   	flag_op1 = 1;
      op1=sacar_operando(Ter[cont_terc].op2);
   }
	if( strnicmp( Ter[cont_terc].op3, "[", 1) == 0)
   {
   	flag_op2 = 1;
      op2=sacar_operando(Ter[cont_terc].op3);
	}

   if (flag_op1 == 1 && flag_op2 == 1)
   {
      indice_auxi -=1;
      vec_auxi[cont_terc+1] = vec_auxi[op1];
      fprintf(cod_fuente, "\tFLD _aux_%d\n", vec_auxi[op1]);
      fprintf(cod_fuente, "\t;---Se va a efectuar una division---\n");
      fprintf(cod_fuente, "\t\tFDIV _aux_%d\n", vec_auxi[op2]);
      fprintf(cod_fuente, "\t\tFSTP _aux_%d\n", vec_auxi[op1]);
    }

   if (flag_op1 == 0 && flag_op2 == 0)
   {
      indice_auxi +=1;
      vec_auxi[cont_terc+1] = indice_auxi;
      fprintf(cod_fuente, "\tFLD %s\n",Ter[cont_terc].op2);
      fprintf(cod_fuente, "\t;---Se va a efectuar una division---\n");
      fprintf(cod_fuente, "\t\FDIV %s\n",Ter[cont_terc].op3);
      fprintf(cod_fuente, "\t\tFSTP _aux_%d\n", indice_auxi);
	}

	if (flag_op1 == 1 && flag_op2 == 0)
   {
      vec_auxi[cont_terc+1] = vec_auxi[op1];
      fprintf(cod_fuente, "\tFLD _aux_%d\n",vec_auxi[op1]);
      fprintf(cod_fuente, "\t;---Se va a efectuar una division---\n");
      fprintf(cod_fuente, "\t\tFDIV %s\n",Ter[cont_terc].op3);
      fprintf(cod_fuente, "\t\tFSTP _aux_%d\n", vec_auxi[op1]);
   }

	if (flag_op1 == 0 && flag_op2 == 1)
   {
      vec_auxi[cont_terc+1] = vec_auxi[op2];
      fprintf(cod_fuente, "\tFLD %s\n",Ter[cont_terc].op2);
      fprintf(cod_fuente, "\t;---Se va a efectuar una division---\n");
   	fprintf(cod_fuente, "\t\tFDIV _aux_%d\n",vec_auxi[op2]);
      fprintf(cod_fuente, "\t\tFSTP _aux_%d\n", vec_auxi[op2]);
   }
}

//------------------------------- ASIGNACION -----------------------------------
void generaASIG( )
{
   int flag_op2 = 0;
   int op2;
   fprintf(cod_fuente, "\t;---asignacion---\n");
   if( strnicmp( Ter[cont_terc].op3, "[", 1) == 0)
   {
   	flag_op2 = 1;
      op2=sacar_operando(Ter[cont_terc].op3);
	}

   if (flag_op2 == 1)
   {
      fprintf(cod_fuente, "\tFLD _aux_%d\n", vec_auxi[op2]);
      fprintf(cod_fuente, "\t\tFSTP %s\n", Ter[cont_terc].op2);
		indice_auxi-=1;
   }
   else
   {
      if (strcmp(Ter[cont_terc].op3, "true")==0 )
        	fprintf(cod_fuente, "\tmov al, 1\n");
      else
      	if (strcmp(Ter[cont_terc].op3, "false" )==0)
             fprintf(cod_fuente, "\tmov al, 0\n");
         else
            if (buscar_variable(Ter[cont_terc].op3)==1)
                fprintf(cod_fuente, "\tmov al, %s\n",Ter[cont_terc].op3);
            else
            	fprintf(cod_fuente, "\tFLD %s\n",Ter[cont_terc].op3);
      if (buscar_variable(Ter[cont_terc].op2)==1)
      	fprintf(cod_fuente, "\t\tmov %s, al\n", Ter[cont_terc].op2);
      else
      	fprintf(cod_fuente, "\t\tFSTP %s\n", Ter[cont_terc].op2);
	 }
    fflush(cod_fuente);
}

//-------------------------- GENERA COMPARACION --------------------------------
void generaCOMP(int simbolo)
{
   int flag_op1 = 0;
   int flag_op2 = 0;
   int op1, op2;

	fprintf(cod_fuente,"\tmov al, 1\n");
	fprintf(cod_fuente,"\t\tmov _aux_b, al\n");

   if(strnicmp(Ter[cont_terc].op2, "@", 1) == 0)
     strcpy(Ter[cont_terc].op2," ");

   if(strnicmp(Ter[cont_terc].op3, "@", 1) == 0)
     strcpy(Ter[cont_terc].op2," ");

	if( strnicmp(Ter[cont_terc].op2, "[", 1) == 0)
   {
   	flag_op1 = 1;
      op1=sacar_operando(Ter[cont_terc].op2);
   }
	if( strnicmp(Ter[cont_terc].op3, "[", 1) == 0)
   {
   	flag_op2 = 1;
      op2=sacar_operando(Ter[cont_terc].op3);
	}
   if (flag_op1 == 1 && flag_op2 == 1)
   {
      fprintf(cod_fuente,"\t\tFLD _aux_%d\n",vec_auxi[op1]);
		fprintf(cod_fuente,"\t\t\FCOMP _aux_%d\n",vec_auxi[op2]);
	   fprintf(cod_fuente,"\t\tFSTSW AX\n");
   	fprintf(cod_fuente,"\t\tFWAIT\n");
   	fprintf(cod_fuente,"\t\tSAHF\n");
      condicionReal=1;
      indice_auxi-=2;
   }

   if (flag_op1 == 0 && flag_op2 == 0)
   {
      if (strcmp(Ter[cont_terc].op2, "true")==0 )
			fprintf(cod_fuente,"\t\tmov al, 1\n");
      else
      	if (strcmp(Ter[cont_terc].op2, "false" ) ==0)
             fprintf(cod_fuente, "\t\tmov al, 0\n");
         else
            if (buscar_variable(Ter[cont_terc].op2)==1)
               fprintf(cod_fuente,"\t\tmov al, %s\n", Ter[cont_terc].op2);
            else
      			fprintf(cod_fuente,"\t\tFLD %s\n", Ter[cont_terc].op2);

      if (strcmp(Ter[cont_terc].op3, "true")==0 )
			fprintf(cod_fuente,"\t\tcmp al, 1\n");
      else
      	if (strcmp(Ter[cont_terc].op3, "false" ) ==0)
             fprintf(cod_fuente, "\t\tcmp al, 0\n");
         else
           if (buscar_variable(Ter[cont_terc].op3)==1)
	        		fprintf(cod_fuente,"\t\tcmp al, %s\n", Ter[cont_terc].op3);
           else{
					fprintf(cod_fuente,"\t\t\FCOMP %s\n", Ter[cont_terc].op3);
			   	fprintf(cod_fuente,"\t\tFSTSW AX\n");
   				fprintf(cod_fuente,"\t\tFWAIT\n");
               fprintf(cod_fuente,"\t\tSAHF\n");
               condicionReal=1;
            }
   }

	if (flag_op1 == 1 && flag_op2 == 0)
   {
      fprintf(cod_fuente,"\t\tFLD _aux_%d\n", vec_auxi[op1]);
      if (strcmp(Ter[cont_terc].op3, "true")==0 )
			fprintf(cod_fuente,"\t\tcmp al, 1\n");
      else
      	if (strcmp(Ter[cont_terc].op3, "false" ) ==0)
             fprintf(cod_fuente, "\tcmp al, 0\n");
         else
          {
           		fprintf(cod_fuente,"\t\t\FCOMP %s\n",Ter[cont_terc].op3);
			   	fprintf(cod_fuente,"\t\tFSTSW AX\n");
   				fprintf(cod_fuente,"\t\tFWAIT\n");
					fprintf(cod_fuente,"\t\tSAHF\n");
               condicionReal=1;
          }
     indice_auxi-=1;
   }

	if (flag_op1 == 0 && flag_op2 == 1)
   {
      if (strcmp(Ter[cont_terc].op2, "true")==0 )
			fprintf(cod_fuente,"\t\tmov al, 1\n");
      else
      	if (strcmp(Ter[cont_terc].op2, "false" ) ==0)
             fprintf(cod_fuente, "\tmov al, 0\n");
         else {
	         	fprintf(cod_fuente,"\t\tFLD %s\n", Ter[cont_terc].op2);
      			fprintf(cod_fuente,"\t\t\FCOMP _aux_%d\n", vec_auxi[op2]);
			   	fprintf(cod_fuente,"\t\tFSTSW AX\n");
   				fprintf(cod_fuente,"\t\tFWAIT\n");
               fprintf(cod_fuente,"\t\tSAHF\n");
               condicionReal=1;
         }
      indice_auxi-=1;
   }

   //etiqueta para saltar segun la condicion
   if (condicionReal){
   	switch (simbolo)
   	{
   		case 1: fprintf(cod_fuente,"\t\tJZ etq_cnd_%d\n",cant_etq_cond);
      			break;
     		case 2: fprintf(cod_fuente,"\t\tJB etq_cnd_%d\n",cant_etq_cond);
      			break;
      	case 3: fprintf(cod_fuente,"\t\tJBE etq_cnd_%d\n",cant_etq_cond);
      			break;
      	case 4: fprintf(cod_fuente,"\t\tJA etq_cnd_%d\n",cant_etq_cond);
      			break;
      	case 5: fprintf(cod_fuente,"\t\tJAE etq_cnd_%d\n",cant_etq_cond);
      			break;
      	case 6: fprintf(cod_fuente,"\t\tJNZ etq_cnd_%d\n",cant_etq_cond);
      			break;
   	}
      condicionReal=0;
	}else{
   	switch (simbolo)
   	{
   		case 1: fprintf(cod_fuente,"\t\tJE etq_cnd_%d\n",cant_etq_cond);
      			break;
     		case 2: fprintf(cod_fuente,"\t\tJL etq_cnd_%d\n",cant_etq_cond);
      			break;
      	case 3: fprintf(cod_fuente,"\t\tJLE etq_cnd_%d\n",cant_etq_cond);
      			break;
      	case 4: fprintf(cod_fuente,"\t\tJG etq_cnd_%d\n",cant_etq_cond);
      			break;
      	case 5: fprintf(cod_fuente,"\t\tJGE etq_cnd_%d\n",cant_etq_cond);
      			break;
      	case 6: fprintf(cod_fuente,"\t\tJNE etq_cnd_%d\n",cant_etq_cond);
      			break;
   	}
   }


   fprintf(cod_fuente,"\t\tmov al, 0\n");
	fprintf(cod_fuente,"\t\tmov _aux_b, al\n");
   fprintf(cod_fuente,"\netq_cnd_%d:",cant_etq_cond);
   cant_etq_cond +=1;

   fflush(cod_fuente);
}

//------------------------------------------------- BI -------------------------------------------------------------
void generaBI( )
{
  char * op1;
  op1=sacar_operando(Ter[cont_terc].op1);
  fprintf(cod_fuente,"\t\tjmp etiqueta_%s\n",op1);

   fflush(cod_fuente);
}

//------------------------------------------------ SACAR OPERANDO --------------------------------------------------

int sacar_operando(char * operando)
{
	int a=0;
   int j=0;
   char * aux[10];

	while(a!=1){
   	operando++;
      if(*operando!=']'){
      	aux[j]=*operando;
         j++;
      }else{
      	aux[j]='\0';
         a=1;
      }
	}
   //printf("\n SAQUE OPERANDO: %d\n",atoi(aux));
	return atoi(aux);
}

//----------------------------BUSCAR VARIABLE ----------------------------------
int buscar_variable(char operando [])
{
   int h;
   for (h=0;h < cantSimbolos;h+=1)
     	if( strcmpi(simbolo[h].nombre,operando)==0)
      	return simbolo[h].tipo;
   return -1;      
}

//------------------------- GENERA VARIABLES -----------------------------------
// carga en fuente.asm las variables de la Tabla de simbolos.-
void generaVariables( )
{
   int i;
   char * sinvalor = "?";
   fprintf(cod_fuente,"\n.DATA\n");
   fprintf(cod_fuente,"\n;Definicion de Variables (from TS):\n");
   fprintf(cod_fuente,";-----------------------------------\n\n");
 	for (i = 0; i < cantSimbolos; i +=1)
   {
   	if( simbolo[i].tipo == 288 )   // agrega los ID = Token 288
       {
        if(simbolo[i].valor!=0)
         fprintf(cod_fuente,"%s dd %f\n",simbolo[i].nombre,simbolo[i].valor);
        else
         fprintf(cod_fuente,"%s dd %s\n",simbolo[i].nombre,sinvalor);
       }

   	if( simbolo[i].tipo == 271	 )   // agrega los MIREAL = Token 271
       {
        if(simbolo[i].valor!=0)
         fprintf(cod_fuente,"%s equ %f\n",simbolo[i].nombre,simbolo[i].valor);
        else
         fprintf(cod_fuente,"%s dd %s\n",simbolo[i].nombre,sinvalor);
       }

   	if( simbolo[i].tipo == 350	 )   // agrega los ARRAY = Token 350 (inventado x mi)
       {
			fprintf(cod_fuente,"%s dw %d dup(0)\n",simbolo[i].nombre,simbolo[i].limite);
       }

   	if( simbolo[i].tipo == 258	 )   // agrega los MISTRING = Token 258 (inventado x mi)
        fprintf(cod_fuente,"%s db %s, %d dup (?),'$'\n","pepe",simbolo[i].nombre,57);
      	//fprintf(cod_fuente,"%s dw %d dup(0)\n",simbolo[i].nombre,simbolo[i].limite);

   }

   //para imprimir reales
   if (printReal)
   {
      fprintf(cod_fuente,"printBuffer db 14 dup (0)\n");
      fprintf(cod_fuente,"_BUFFER db 50 dup (?),'$'\n");
      fprintf(cod_fuente,"msgPRESIONE db %s, 41 dup (?),'$'\n", "continuar");
      fprintf(cod_fuente,"FRBUFFLEN equ 13\n");
		fprintf(cod_fuente,"FRBUFFPTO equ 9\n");
   }


   fprintf(cod_fuente,"\n; Fin de Definicion de Variables\n");
	fprintf(cod_fuente,"\n");
   fprintf(cod_fuente,"\nEND\n");
}


/******************************************************************************/
//---------------------------------- FIN ASM ---------------------------------
/******************************************************************************/

FILE *yytfilep;
char *yytfilen;
int yytflag = 0;
int svdprd[2];
char svdnams[2][2];

short yyexca[] = {
  -1, 1,
  0, -1,
  -2, 0,
  -1, 12,
  295, 63,
  -2, 17,
  -1, 24,
  295, 63,
  -2, 48,
  -1, 34,
  295, 63,
  -2, 23,
  -1, 82,
  295, 63,
  -2, 22,
  0,
};

#define YYNPROD 66
#define YYLAST 209

short yyact[] = {
      43,      44,      47,      46,      45,      48,      49,      50,
      74,      41,      42,      97,      10,      59,      41,      42,
      11,      55,      56,      57,      58,      10,      14,      94,
      95,      11,      41,      42,      20,      54,      25,      14,
      10,     100,      98,      25,      11,      96,      61,      15,
      12,      10,      14,      82,     103,      11,     104,      24,
      15,      12,      27,      14,      24,      10,      52,      27,
      34,      11,      77,      15,      12,      16,       2,      14,
      81,      62,      37,      38,      15,      12,      65,      79,
      26,      18,       4,      13,      13,      23,      17,       3,
      15,      12,      63,      21,      92,      53,      26,      30,
      35,      73,      72,      71,       4,      70,      93,      32,
      40,      39,      22,      67,      66,      80,      33,      31,
      29,      91,      28,      99,      63,      64,      36,      51,
       9,       8,       7,       6,       5,      60,       1,       0,
       0,      19,       0,       0,      69,       0,      75,       0,
       0,       0,       0,       0,       0,       0,       0,      40,
      83,      76,      13,       0,       0,       0,       0,       0,
      78,      84,      53,       0,       0,      18,      89,      90,
       0,      53,       0,       0,      65,      13,       0,      17,
      60,      68,      21,       0,      99,       0,       0,      73,
      23,      87,      88,       0,      13,      13,      13,      13,
      17,      17,       0,     101,     102,     100,       3,       0,
       0,       0,      71,      22,      85,      86,      66,       0,
       0,       0,       0,       0,       0,       0,       0,       0,
       0,       0,       0,       0,       0,       0,       0,      67,
      19,
};

short yypact[] = {
    -224,   -1000,    -207,    -228,   -1000,   -1000,   -1000,   -1000,
   -1000,   -1000,    -241,   -1000,   -1000,   -1000,   -1000,    -232,
   -1000,   -1000,   -1000,    -201,   -1000,    -272,    -294,   -1000,
   -1000,   -1000,   -1000,    -236,    -237,    -261,    -282,    -261,
    -253,    -200,   -1000,   -1000,    -191,   -1000,   -1000,    -236,
    -236,   -1000,   -1000,   -1000,   -1000,   -1000,   -1000,   -1000,
   -1000,   -1000,   -1000,    -284,    -241,    -236,   -1000,   -1000,
   -1000,   -1000,   -1000,    -213,    -236,    -187,    -202,    -245,
   -1000,    -207,    -236,    -236,   -1000,    -289,    -236,    -236,
    -236,    -236,   -1000,   -1000,    -289,   -1000,    -289,   -1000,
   -1000,   -1000,   -1000,   -1000,    -239,   -1000,   -1000,    -294,
    -294,   -1000,   -1000,    -255,    -285,    -258,   -1000,   -1000,
    -260,   -1000,   -1000,    -207,    -207,    -219,    -248,   -1000,
   -1000,
};

short yypgo[] = {
       0,     118,      79,      74,     116,     115,     114,     113,
     112,      73,     110,     109,     107,     106,     105,     104,
      85,      83,      72,     103,     102,     101,     121,     100,
      99,      97,      96,      95,      94,      93,      98,      91,
      90,      77,      89,      87,      84,
};

short yyr1[] = {
       0,       1,       2,       2,       3,       3,       3,       3,
       3,      10,       4,      12,      11,      11,      13,      14,
       5,      15,       6,      19,       6,       8,      20,      20,
      20,      20,      23,       9,      24,       9,       9,      25,
       9,      22,      27,      28,       7,      29,      17,      31,
      17,      17,      32,      30,      34,      30,      30,      21,
      33,      33,      33,      33,      26,      26,      26,      26,
      26,      26,      16,      16,      16,      16,      16,      35,
      36,      18,
};

short yyr2[] = {
       2,       3,       1,       2,       1,       1,       1,       1,
       1,       0,       4,       0,       6,       3,       0,       0,
       9,       0,       4,       0,       4,       4,       3,       1,
       3,       1,       0,       4,       0,       4,       1,       0,
       3,       3,       0,       0,       6,       0,       4,       0,
       4,       1,       0,       4,       0,       4,       1,       1,
       1,       1,       1,       3,       1,       1,       1,       1,
       1,       1,       1,       1,       1,       1,       1,       0,
       0,       6,
};

short yychk[] = {
   -1000,      -1,     286,      -2,      -3,      -4,      -5,      -6,
      -7,      -8,     260,     264,     288,     -18,     270,     287,
     289,      -3,      -9,     -22,     269,     -17,     -30,     -33,
     288,     271,     -18,     291,     -13,     -15,     -35,     -19,
     -27,     -20,     288,     -18,     -10,     267,     268,     -25,
     -26,     298,     299,     272,     273,     276,     275,     274,
     277,     300,     301,     -17,     291,     -16,     290,     278,
     279,     280,     281,     295,     -16,     291,     265,     282,
     -11,     261,     -23,     -24,     -22,     -17,     -29,     -31,
     -32,     -34,     292,      -9,     -17,     271,     -17,     258,
     -21,     266,     288,     -18,      -2,     -22,     -22,     -30,
     -30,     -33,     -33,     -14,     -36,     -28,     262,     263,
     292,     296,     292,     -12,     293,      -2,      -2,     263,
     294,
};

short yydef[] = {
       0,      -2,       0,       0,       2,       4,       5,       6,
       7,       8,       0,      14,      -2,      19,      34,       0,
       1,       3,       9,      30,      31,       0,      41,      46,
      -2,      49,      50,       0,       0,       0,       0,       0,
       0,       0,      -2,      25,       0,      26,      28,       0,
       0,      37,      39,      52,      53,      54,      55,      56,
      57,      42,      44,       0,       0,       0,      58,      59,
      60,      61,      62,       0,       0,       0,       0,       0,
      10,       0,       0,       0,      32,      33,       0,       0,
       0,       0,      51,      15,      18,      64,      20,      35,
      21,      47,      -2,      24,       0,      27,      29,      38,
      40,      43,      45,       0,       0,       0,      11,      13,
       0,      65,      36,       0,       0,       0,       0,      12,
      16,
};

short *yyxi;


/*****************************************************************/
/* PCYACC LALR parser driver routine -- a table driven procedure */
/* for recognizing sentences of a language defined by the        */
/* grammar that PCYACC analyzes. An LALR parsing table is then   */
/* constructed for the grammar and the skeletal parser uses the  */
/* table when performing syntactical analysis on input source    */
/* programs. The actions associated with grammar rules are       */
/* inserted into a switch statement for execution.               */
/*****************************************************************/


#ifndef YYMAXDEPTH
#define YYMAXDEPTH 200
#endif
#ifndef YYREDMAX
#define YYREDMAX 1000
#endif
#define PCYYFLAG -1000
#define WAS0ERR 0
#define WAS1ERR 1
#define WAS2ERR 2
#define WAS3ERR 3
#define yyclearin pcyytoken = -1
#define yyerrok   pcyyerrfl = 0
YYSTYPE yyv[YYMAXDEPTH];     /* value stack */
int pcyyerrct = 0;           /* error count */
int pcyyerrfl = 0;           /* error flag */
int redseq[YYREDMAX];
int redcnt = 0;
int pcyytoken = -1;          /* input token */


yyparse()
{
  int statestack[YYMAXDEPTH]; /* state stack */
  int      j, m;              /* working index */
  YYSTYPE *yypvt;
  int      tmpstate, tmptoken, *yyps, n;
  YYSTYPE *yypv;


  tmpstate = 0;
  pcyytoken = -1;
#ifdef YYDEBUG
  tmptoken = -1;
#endif
  pcyyerrct = 0;
  pcyyerrfl = 0;
  yyps = &statestack[-1];
  yypv = &yyv[-1];


  enstack:    /* push stack */
#ifdef YYDEBUG
    printf("at state %d, next token %d\n", tmpstate, tmptoken);
#endif
    if (++yyps - &statestack[YYMAXDEPTH] > 0) {
      yyerror("pcyacc internal stack overflow");
      return(1);
    }
    *yyps = tmpstate;
    ++yypv;
    *yypv = yyval;


  newstate:
    n = yypact[tmpstate];
    if (n <= PCYYFLAG) goto defaultact; /*  a simple state */


    if (pcyytoken < 0) if ((pcyytoken=yylex()) < 0) pcyytoken = 0;
    if ((n += pcyytoken) < 0 || n >= YYLAST) goto defaultact;


    if (yychk[n=yyact[n]] == pcyytoken) { /* a shift */
#ifdef YYDEBUG
      tmptoken  = pcyytoken;
#endif
      pcyytoken = -1;
      yyval = yylval;
      tmpstate = n;
      if (pcyyerrfl > 0) --pcyyerrfl;
      goto enstack;
    }


  defaultact:


    if ((n=yydef[tmpstate]) == -2) {
      if (pcyytoken < 0) if ((pcyytoken=yylex())<0) pcyytoken = 0;
      for (yyxi=yyexca; (*yyxi!= (-1)) || (yyxi[1]!=tmpstate); yyxi += 2);
      while (*(yyxi+=2) >= 0) if (*yyxi == pcyytoken) break;
      if ((n=yyxi[1]) < 0) { /* an accept action */
        if (yytflag) {
          int ti; int tj;
          yytfilep = fopen(yytfilen, "w");
          if (yytfilep == NULL) {
            fprintf(stderr, "Can't open t file: %s\n", yytfilen);
            return(0);          }
          for (ti=redcnt-1; ti>=0; ti--) {
            tj = svdprd[redseq[ti]];
            while (strcmp(svdnams[tj], "$EOP"))
              fprintf(yytfilep, "%s ", svdnams[tj++]);
            fprintf(yytfilep, "\n");
          }
          fclose(yytfilep);
        }
        return (0);
      }
    }


    if (n == 0) {        /* error situation */
      switch (pcyyerrfl) {
        case WAS0ERR:          /* an error just occurred */
          yyerror("syntax error");
          yyerrlab:
            ++pcyyerrct;
        case WAS1ERR:
        case WAS2ERR:           /* try again */
          pcyyerrfl = 3;
	   /* find a state for a legal shift action */
          while (yyps >= statestack) {
	     n = yypact[*yyps] + YYERRCODE;
	     if (n >= 0 && n < YYLAST && yychk[yyact[n]] == YYERRCODE) {
	       tmpstate = yyact[n];  /* simulate a shift of "error" */
	       goto enstack;
            }
	     n = yypact[*yyps];


	     /* the current yyps has no shift on "error", pop stack */
#ifdef YYDEBUG
            printf("error: pop state %d, recover state %d\n", *yyps, yyps[-1]);
#endif
	     --yyps;
	     --yypv;
	   }


	   yyabort:
            if (yytflag) {
              int ti; int tj;
              yytfilep = fopen(yytfilen, "w");
              if (yytfilep == NULL) {
                fprintf(stderr, "Can't open t file: %s\n", yytfilen);
                return(1);              }
              for (ti=1; ti<redcnt; ti++) {
                tj = svdprd[redseq[ti]];
                while (strcmp(svdnams[tj], "$EOP"))
                  fprintf(yytfilep, "%s ", svdnams[tj++]);
                fprintf(yytfilep, "\n");
              }
              fclose(yytfilep);
            }
	     return(1);


	 case WAS3ERR:  /* clobber input char */
#ifdef YYDEBUG
          printf("error: discard token %d\n", pcyytoken);
#endif
          if (pcyytoken == 0) goto yyabort; /* quit */
	   pcyytoken = -1;
	   goto newstate;      } /* switch */
    } /* if */


    /* reduction, given a production n */
#ifdef YYDEBUG
    printf("reduce with rule %d\n", n);
#endif
    if (yytflag && redcnt<YYREDMAX) redseq[redcnt++] = n;
    yyps -= yyr2[n];
    yypvt = yypv;
    yypv -= yyr2[n];
    yyval = yypv[1];
    m = n;
    /* find next state from goto table */
    n = yyr1[n];
    j = yypgo[n] + *yyps + 1;
    if (j>=YYLAST || yychk[ tmpstate = yyact[j] ] != -n) tmpstate = yyact[yypgo[n]];
    switch (m) { /* actions associated with grammar rules */
      
      case 1:
# line 36 "lexi16.y"
      {ReglaFinal(); fprintf(stream,"%s","\n Regla de Programa");} break;
      case 2:
# line 39 "lexi16.y"
      {} break;
      case 3:
# line 40 "lexi16.y"
      {} break;
      case 4:
# line 43 "lexi16.y"
      {} break;
      case 5:
# line 44 "lexi16.y"
      {} break;
      case 6:
# line 45 "lexi16.y"
      {} break;
      case 7:
# line 46 "lexi16.y"
      {} break;
      case 8:
# line 47 "lexi16.y"
      {} break;
      case 9:
# line 50 "lexi16.y"
      {ArmaTerBranch(0);} break;
      case 10:
# line 50 "lexi16.y"
      {CompletaFaltante(0);} break;
      case 11:
# line 53 "lexi16.y"
      {CompletaFaltante(1);ArmaTerBranch(0);} break;
      case 12:
# line 53 "lexi16.y"
      {fprintf(stream,"%s","\n Si con SINO");} break;
      case 13:
# line 54 "lexi16.y"
      {} break;
      case 14:
# line 57 "lexi16.y"
      {ApilarTerceto();} break;
      case 15:
# line 57 "lexi16.y"
      {ArmaTerBranch(0);} break;
      case 16:
# line 57 "lexi16.y"
      {CompletaFaltante(1); ArmaTerBranch(1); fprintf(stream,"%s","\n Iteración");} break;
      case 17:
# line 60 "lexi16.y"
      {ApilarOperando(NomID);verificaVariable(NomID);} break;
      case 18:
# line 60 "lexi16.y"
      {FinOperador();} break;
      case 19:
# line 61 "lexi16.y"
      {ApilarOperando(strcat(NomArray,verificaArray(declaraArray,IndiceArray)));} break;
      case 20:
# line 61 "lexi16.y"
      {FinOperador();} break;
      case 21:
# line 64 "lexi16.y"
      {} break;
      case 22:
# line 67 "lexi16.y"
      {setFlag(NomID,1);} break;
      case 23:
# line 68 "lexi16.y"
      {setFlag(NomID,1);} break;
      case 24:
# line 69 "lexi16.y"
      {setFlag(declaraArray,2); setLimite(declaraArray,IndiceArray);} break;
      case 25:
# line 70 "lexi16.y"
      {setFlag(declaraArray,2); setLimite(declaraArray,IndiceArray);} break;
      case 26:
# line 73 "lexi16.y"
      {EsOr=1; FinOperador();ArmaTerBranch(0);ApilarLogicos(0);} break;
      case 27:
# line 73 "lexi16.y"
      {FinOperador();fprintf(stream,"%s","\n OR");} break;
      case 28:
# line 74 "lexi16.y"
      {FinOperador();ApilarLogicos(1);ArmaTerBranch(0);} break;
      case 29:
# line 74 "lexi16.y"
      {FinOperador();fprintf(stream,"%s","\n AND");} break;
      case 30:
# line 75 "lexi16.y"
      {FinOperador();} break;
      case 31:
# line 76 "lexi16.y"
      {ApilarLogicos(2);} break;
      case 33:
# line 79 "lexi16.y"
      {fprintf(stream,"%s","\n Comparación");} break;
      case 34:
# line 82 "lexi16.y"
      {ApilarOperador("PRINT");} break;
      case 35:
# line 82 "lexi16.y"
      {ApilarOperando(NomID);} break;
      case 36:
# line 82 "lexi16.y"
      {FinPrint();} break;
      case 37:
# line 85 "lexi16.y"
      {ApilarOperador("+"); printf(" + ");} break;
      case 38:
# line 85 "lexi16.y"
      {FinOperador();} break;
      case 39:
# line 86 "lexi16.y"
      {ApilarOperador("-"); printf(" - ");} break;
      case 40:
# line 86 "lexi16.y"
      {FinOperador();} break;
      case 41:
# line 87 "lexi16.y"
      {} break;
      case 42:
# line 90 "lexi16.y"
      {ApilarOperador("*"); printf(" * ");} break;
      case 43:
# line 90 "lexi16.y"
      {FinOperador();} break;
      case 44:
# line 91 "lexi16.y"
      {ApilarOperador("/"); printf(" / ");} break;
      case 45:
# line 91 "lexi16.y"
      {FinOperador();} break;
      case 46:
# line 92 "lexi16.y"
      {} break;
      case 47:
# line 94 "lexi16.y"
      {} break;
      case 48:
# line 96 "lexi16.y"
      {ApilarOperando(NomID);verificaVariable(NomID);} break;
      case 49:
# line 97 "lexi16.y"
      {ApilarOperando(NomID);} break;
      case 50:
# line 98 "lexi16.y"
      {ApilarOperando(strcat(NomArray,verificaArray(declaraArray,IndiceArray)));} break;
      case 51:
# line 99 "lexi16.y"
      {fprintf(stream,"%s","\n Expr entre parentesis");} break;
      case 52:
# line 102 "lexi16.y"
      {ApilarOperador(">");fprintf(stream,"%s","\n Mayor");} break;
      case 53:
# line 103 "lexi16.y"
      {ApilarOperador("<");fprintf(stream,"%s","\n Menor");} break;
      case 54:
# line 104 "lexi16.y"
      {ApilarOperador(">=");fprintf(stream,"%s","\n Mayor Igual");} break;
      case 55:
# line 105 "lexi16.y"
      {ApilarOperador("<=");fprintf(stream,"%s","\n Menor Igual");} break;
      case 56:
# line 106 "lexi16.y"
      {ApilarOperador("==");fprintf(stream,"%s","\n Igual");} break;
      case 57:
# line 107 "lexi16.y"
      {ApilarOperador("<>");fprintf(stream,"%s","\n Distinto");} break;
      case 58:
# line 110 "lexi16.y"
      {ApilarOperador("=");  printf(" = ");} break;
      case 59:
# line 111 "lexi16.y"
      {ApilarOperador("+="); printf(" += ");} break;
      case 60:
# line 112 "lexi16.y"
      {ApilarOperador("-="); printf(" -= ");} break;
      case 61:
# line 113 "lexi16.y"
      {ApilarOperador("*="); printf(" *= ");} break;
      case 62:
# line 114 "lexi16.y"
      {ApilarOperador("/="); printf(" /= ");} break;
      case 63:
# line 117 "lexi16.y"
      {strcpy(NomArray,NomID);strcpy(declaraArray,NomID);} break;
      case 64:
# line 117 "lexi16.y"
      {strcpy(IndiceArray,NomID);} break;    }
    goto enstack;
}
