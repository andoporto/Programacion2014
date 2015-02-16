/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
			   CALCULADORA POLACA POSFIJA

  Version: 2.0.
  Autor: Juan Carlos Reyes Martinez.
  Centro Universitario De Ciencias Exactas E Ingenierias. (CUCEI).

Esta calculadora tiene la capacidad de resolver integrales por el
metodo de simpson 1/3, ademas que tambien saca el 0 o raiz de una
ecuacion por el metodo de newton y grafica una ecuacion... ademas
con todas las funciones basicas de una calculadora cientifica
:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/



#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <graphics.h>
#include <iostream.h>
#define tamano 50

# define  N        100
# define error     -99
#define aceptacion 110
#define FDC  '\0'

/*  clases que seran las pilas necesarias para la transformacion a forma
	polaca y la cola que contendra la forma polaca */
class Pila_val
{
	private:
		double *valores;
		int tope;
	public:
		Pila_val(int n){ valores = (double*)calloc(n,sizeof(double));
		tope = -1;}
		~Pila_val(){ free(valores);}
		void push(double val)
		{ valores[++tope] = val;}
		double pop()
		{  return valores[tope--];}
		int vacia()
		{return tope == -1;}
		void clean()
		{ tope = -1;}
};
struct pila_cola {
		char token[30];  // Tendra el operando de la formula o el numero
		int prioridad;   // tendra la prioridad del operando
		char tipo[10];   // sera el tipo: unario o binario
	  } ;

class Pila_opers
{
	private:
	  pila_cola *opers;

		int tope;
	public:
		Pila_opers(int n){ opers = (struct pila_cola*)calloc(n,sizeof(pila_cola));
		tope = -1;}
		~Pila_opers(){ free(opers);}
		void push(struct pila_cola val)
		{ opers[++tope] = val;}
		struct pila_cola pop()
		{return opers[tope--];}
		struct pila_cola cima()
		{return opers[tope];}
		int vacia()
		{	return tope == -1; }
		void clean()
		{ tope = -1; }
};

// La clase Cola contendra la forma polaca, y la formula ya separada ademas de colas
// auxiliares de la grafica , la integral y la de newton.

class Cola
{
	private:
	pila_cola *oper;

	public:

		int frente,fin;
		Cola(int n){ oper = (struct pila_cola*)calloc(n,sizeof(struct pila_cola));
		frente = 0; fin = 0;}

		~Cola(){ free(oper);}
		void meter(char *opera,char *prioridad,char *tipo)
		{
			strcpy(oper[fin].token,opera);
			oper[fin].prioridad = atoi(prioridad);
			strcpy(oper[fin++].tipo,tipo);
		}
		void meter(struct pila_cola operad)
		{oper[fin++] =	operad;}
		struct pila_cola sacar()
		{  return oper[frente++];}
		void back()
		{ frente = 0;}
		int vacia()
		{ return frente == fin;}
		void clean()
		{ frente = fin = 0x00;}
};
typedef Cola	     *COLA;
typedef Pila_val     *Pila_Val;
typedef Pila_opers	 *Pila_Opers;

enum entradas{
	punto,   //0
	signos,  //1
	digito,  //2
	opers,   //3
	fact,    //4
	a,       //5
	c,       //6
	e,       //7
	f,       //8
	g,       //9
	i,       //10
	l,       //11
	n,       //12
	o,       //13
	p,       //14
	r,       //15
	s,       //16
	t,       //17
	w,       //18
	x,       //19
	z,       //20
	coma,    //21
	apertura,//22
	cierre,  //23
	fdc,     //24
	otro,    //25
	};

// estas banderas se utilizaran solo para las funciones trigonometricas
int esIntegral = 0,esNewton = 0,Variable_x = 0;
int esGrafica = 0, radianes = 1, grados = 0;   // radianes por default
// la bandera esGrafica indicara que si se utiliza el comando 'grafica('
// y se estan utilizando funciones trigonometricas, aumente el zoom
// multiplicado por 100, dado que estas funciones sus valores oscilan
// entre 1 y 0; y el zoom por default es el mismo que la pantalla
// una coordenadoa por pixel de la pantalla.
int errorc = 0,puntos = 0;
char form[100];
char *tokens [][50] =
{
// lenguaje para introducir las formulas
 ","         ,  "-1"  , "util",
 "ans"       ,  "-1"  , "util",
 "pi"        ,  "-1"  , "util",
 "x"         ,  "-1"  , "util",   // variable x para calcular
 "integral(" ,  "-1"  , "util",
 "newton("   ,  "-1"  , "util",
 "grafica("  ,  "-1"  , "util",
 "("		    ,  "-1"  , "util",
 ")"		    ,  "-1"  , "util",
 "ñ"		 	 ,	  "5"	 , "unario",	/* signo menos [Alt-241] */
 "^"		    ,	  "5"  , "binario",     	/* potencia [Alt-94] */
 "ý"	       ,   "6"	 , "unariopos",  /* cuadrado  [Alt-252] */
// unariopos; tiene mayor  priorodad que le unario normal
 "!"		    ,	  "6"	 , "unariopos",
  "©"		    ,	  "4"	 , "binario",		/* raiz universal [Alt-169] */
 "ln"		    ,	  "4"	 , "unario",     // unario antes del numero
 "log"	    ,	  "4"  , "unario",		/* logaritmo base 10 */
 "e"	       ,	  "4"	 , "unario",		/* antilogaritmo natural */
 "sen"	    ,   "4"	  , "unario",
 "cos"	    ,	  "4"	  , "unario",
 "tan"	    ,	  "4"	  , "unario",
 "asen"	    ,	  "4"	  , "unario",
 "acos"	    ,	  "4"	  , "unario",
 "atan"	    ,	  "4"	  , "unario",
 "raiz"		 ,	  "4"	  , "unario",
 "*"		    ,	  "3"	  , "binario",
 "/"		    ,	  "3"	  , "binario",
 "%"         ,   "3"   , "binario",
 "+"		    ,	  "2"	  , "binario",
 "-"		    ,	  "2"	  , "binario",

};

int compilaExpresion(char *expresion);
void separa_tokens(void);
void error1(void);
void formaPolaca(Cola&,Cola&);
double Evalua(Cola&,double);
char* integral(Cola &integral);
char* newtonRapson(Cola &raiz);
void GraficaEcuacion(Cola &grafica);
double Derivada(Cola &,double);
void planoCartesiano(void);
void seno(void),coseno(void),tangente(void),arcoseno(void),arcocoseno(void),
arcotan(void),logaritmo10(void),l_natural(void),factorial(void),cuad(void),
potencia(void),exponencial(void),menos(void),universal(void),raiz(void),
suma(void),resta(void),multi(void),division(void),modulo(void);
int isdigito(char );
void windows(int x1,int y1,int x2,int y2,int color);
void cuadro(int x1,int y1,int x2,int y2,int color);
void Funciones( void );
void clear( void );
void Graphic_User_Interface( void);
void pal(char *p,int c1,int c2);

Cola cola(50);    // crea una cola para todos los elementos ya separados
Cola cola2(50);   // esta cola contendra la forma polaca sufija (sufix)
Cola cola3(30);   // esta es una coma auxiliar para las integrales y las raices
Pila_val valores(30); // pila donde se guardaran todos los valores
double ans = 0.000, X = 0.0;  // valor de ans y de la varible x
int ERROR_DE_COMPILACION = 0;
char  caden[100] = "",variable[50] = "";
void main()
{

	int i,L,color = 10;
	char opcion ;
	int conta=0;
	Graphic_User_Interface();
	while(1)
	{
		_setcursortype(_SOLIDCURSOR);
		clrscr();
		if(radianes){gotoxy(70,5);textcolor(15); cprintf("R");}
		if(grados){gotoxy(70,5); textcolor(15);cprintf("G");}
		fflush(stdin);
		gotoxy(1,1);
		gets(form);
		strlwr(form);
		L = strlen(form);
		for( i=0 ; i<L; i++ )
		{
			if ( form[i]!=' ')     // quita los espacios
				caden[conta++] = form[i];
		}
		caden[conta] = '\0';
		strcpy(form,caden);
		strlwr(form);
		if(!strcmp(form,"exit"))
			exit(0);
		if(!strcmp(form,"rad"))
		{
			radianes = 1;
			grados = 0;
			conta = 0;
			continue;

		}
		else if(!strcmp(form,"gra"))
		{
			grados = 1;
			radianes = 0;
			conta = 0;
			continue;
		}

		if(strcmp(form,"rad")!=0 && strcmp(form,"gra")!=0)
			ERROR_DE_COMPILACION = compilaExpresion(form);
		if(ERROR_DE_COMPILACION != 0)
		{
			separa_tokens();
			formaPolaca(cola,cola2);
			pila_cola aux;
			ans = Evalua(cola2,X);
			gotoxy(1,2);
			for(; !cola2.vacia(); )
			{
				aux = cola2.sacar();
				clreol();
				textcolor(color++);
				if(color>15) color = 10;
				cprintf("%s ",aux.token);
			}
			if(!esGrafica)
			{
				gotoxy(9,3);
				clreol();
				cprintf("= %2.12G",ans);
			}
			else{
				Graphic_User_Interface ();
				clear(); conta = 0; continue;

			}
		   opcion = tolower(getch());
		   if(opcion == 13)
		   {
				clear();
				conta = 0;
			}
			else if(opcion == 'c' && !esIntegral && !esNewton && !esGrafica &&
		   Variable_x)
		   {
				cola2.back();     // reestablece el puntero de la cola.
				do{
					if(Variable_x)
					{
						do{
						puntos = errorc = 0;
						gotoxy(1,4);
						clreol();
						printf("X? "); gets(variable);
						strupr(variable);
						for(int i=0; i<strlen(variable); i++)
						if(variable[i] == '.') puntos++;
						if(puntos > 1) errorc = 1;
						if(!strcmp(variable,"PI")) X = M_PI;
						else if(!strcmp(variable,"ANS")) X = ans;
						else X = atof(variable);
					}while(errorc);

						gotoxy(1,5);
						printf("Presiona \"C\" si deseas volver a calcular.");
					}
					ans = Evalua(cola2,X);
					gotoxy(9,3);
					clreol();
					cprintf("= %2.12G",ans);
					opcion = tolower(getch());
				}while(opcion == 'c');
				clear();
				conta = 0;
		   }
		}
		else{
			opcion = tolower(getch());
			if(opcion == 13)
			{
				clear();
				conta = 0;
		   }
		}
		clear();
		conta = 0;
	} // while infinito
}
void Graphic_User_Interface()
{
	window(1,1,80,25);
	textbackground(3);
	clrscr();
	windows(1,1,79,25,0);
	gotoxy(24,2);textcolor(1);cprintf("SUPER CALCULADORA POLACA KINGS");
	textbackground(1);
	cuadro(4,11,76,24,14);
	gotoxy(27,11); cprintf("Funciones y Comandos");
	window(5,12,75,23);
	clrscr();

	Funciones();
	window(1,1,80,25);
	textbackground(0);
	cuadro(4,3,76,9,14);
	gotoxy(31,3); cprintf("Linea de Comandos");
	textbackground(0);
	window(5,4,75,8);
	clrscr();

}

void clear()
{
	caden[0] = form[0] = '\0';
	valores.clean();
	cola.clean();
	cola2.clean();
	cola3.clean();
	ERROR_DE_COMPILACION = 0;
	Variable_x = esIntegral = esNewton = esGrafica = 0;
}
int isdigito(char c)
{ return (c=='0'||c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7'||
	c=='8'||c=='9');}
int operando(struct pila_cola elem)
{
	if(!strcmp(elem.token,"x") || !strcmp(elem.token,"pi") || !strcmp(elem.token,"ans") ||
	isdigito(elem.token[0]) || elem.token[0] == '.' ||
	//esto es para ya en la evalucion no en la forma polaca
	(elem.token[0] == '-' && isdigito(elem.token[1]))||
	(elem.token[0] == '+' && isdigito(elem.token[1])))
		return 1;
	else return 0;
}
int operador(struct pila_cola elem)
{
	if(!strcmp(elem.token,"sen") || !strcmp(elem.token,"cos") ||!strcmp(elem.token,"tan") ||!strcmp(elem.token,"asen") ||
	!strcmp(elem.token,"acos") ||!strcmp(elem.token,"atan") ||!strcmp(elem.token,"!") ||!strcmp(elem.token,"log") ||
	!strcmp(elem.token,"ln") ||!strcmp(elem.token,"e") ||!strcmp(elem.token,"raiz") ||!strcmp(elem.token,"*") ||
	!strcmp(elem.token,"/") ||!strcmp(elem.token,"%") ||!strcmp(elem.token,"+") ||!strcmp(elem.token,"-")||
	!strcmp(elem.token,"ñ") ||!strcmp(elem.token,"^")||!strcmp(elem.token,"©")
	|| !strcmp(elem.token,"ý"))
		return 1;
	else return 0;
}
void GraficaEcuacion(Cola &grafica)
{
	Cola auxiliar(30),polaca(30);
	pila_cola aux;
	const int puntos = 1000; // el valor de N es constante de NN intervalos
	double Xinicio = 0.0,Xfin = 0.0,incremento = 0.0;
	int signo = 0,modografico = DETECT,modo;
	int cord_x, cord_y,primervalor = 0;
	grafica.sacar(); // quita el simbolo de la integral 'integral('
	aux = grafica.sacar();  // obtiene el primer elemento
	while(strcmp(aux.token,",")!=0)
	{
		auxiliar.meter(aux);
		aux = grafica.sacar();
	}
	formaPolaca(auxiliar,polaca); // transforma a forma polaca
	aux = grafica.sacar();
	if(!strcmp(aux.token,"+") || !strcmp(aux.token,"-") || !strcmp(aux.token,"ñ"))
	{
		if(!strcmp(aux.token,"-") || !strcmp(aux.token,"ñ"))
			signo = 1;
		aux = grafica.sacar();
	}
	Xinicio = atof(aux.token);
	if(signo) Xinicio*= -1;
	signo = 0;
	aux = grafica.sacar();// la coma
	aux = grafica.sacar(); // valor de b
	if(!strcmp(aux.token,"+") ||  !strcmp(aux.token,"-") || !strcmp(aux.token,"ñ"))
	{
		if(!strcmp(aux.token,"-") || !strcmp(aux.token,"ñ"))
			signo = 1;
		aux = grafica.sacar();
	}

	Xfin = atof(aux.token);
	if(signo) Xfin*= -1;
	incremento = (Xfin - Xinicio)/puntos;
	initgraph(&modografico,&modo,"c:\\tc\\bgi");
	// se mueve al primer punto de la grafica
	cord_x = Xinicio;
	cord_y = Evalua(polaca,cord_x); // zoom
	//setbkcolor(1);
	planoCartesiano();
	if(abs(cord_x) < 319 && abs(cord_y)< 239)
	{
		moveto(cord_x+320,abs(cord_y-240));
		primervalor = 1;
	}
	setcolor(14);
	// Grafica la Ecuacion
	while(Xinicio <= Xfin + incremento)
	{
		cord_x = Xinicio;
		cord_y = Evalua(polaca,cord_x);
		if(abs(cord_x) < 319 && abs(cord_y)< 239)
		{
			if(!primervalor)
			{
				moveto(cord_x+320,abs(cord_y-240));
				primervalor = 1;
			}
			lineto(cord_x+320,abs(cord_y-240)); // valores de la mitad de la pantalla
		}
		Xinicio = Xinicio + incremento;
	}
	getch();
	closegraph();
}
double Derivada(Cola &derivada,double X0)
{
	////////////////////////////////////////////
	// formula de derivacion numerica         //
	// para 5 puntos faires                   //
	////////////////////////////////////////////

	double valor1,valor2,valor3,valor4,DERIVADA;
	double h = 0.01;
	//////////////////////////////////////////
	valor1 = Evalua(derivada,(X0-2*h));     //
	valor2 = 8 * Evalua(derivada,(X0-h));   //
	valor3 = 8 * Evalua(derivada,(X0+h));   //
	valor4 = Evalua(derivada,(X0+2*h));     //
	//////////////////////////////////////////
	DERIVADA = valor1 - valor2 + valor3 - valor4;
	DERIVADA = DERIVADA/(12*h);
	return DERIVADA;

}
char* newtonRapson(Cola &raiz)
{
	Cola auxiliar(30),polaca(30);
	pila_cola aux;
	double x0 = 0.0,h = 0.0,tolerancia = 0.0000001,valor_final = 0.0;
	double fx = 0.0,derivada = -0.1;
	int signo = 0,no_Iteraciones = 0;
	char string[40];
	raiz.sacar(); // quita el simbolo de la raix_cero 'newton('
	aux = raiz.sacar();  // obtiene el primer elemento
	while(strcmp(aux.token,",")!=0)
	{
		auxiliar.meter(aux);
		aux = raiz.sacar();
	}
	formaPolaca(auxiliar,polaca); // transforma a forma polaca
	aux = raiz.sacar();
	if(!strcmp(aux.token,"+") || !strcmp(aux.token,"-") || !strcmp(aux.token,"ñ"))
	{
		if(!strcmp(aux.token,"-") || !strcmp(aux.token,"ñ"))
			signo = 1;
		aux = raiz.sacar();
	}
	x0 = atof(aux.token);
	if(signo) x0*= -1;
	signo = 0;
	aux = raiz.sacar();// la coma
	aux = raiz.sacar(); // valor de b
	if(!strcmp(aux.token,"+") ||  !strcmp(aux.token,"-")|| !strcmp(aux.token,"ñ"))
	{
		if(!strcmp(aux.token,"-")|| !strcmp(aux.token,"ñ"))
			signo = 1;
		aux = raiz.sacar();
	}

	h = atof(aux.token);
	if(signo) h*= -1;
	if(h > 0.15 || h <= 0.0)
		h = 0.1;
	//////////////////////////////////////////////
	// formula numerica de obtencion de raices  //
	// del metodo de Newton-Rapson.              //
	//////////////////////////////////////////////
	fx = Evalua(polaca,x0);
	// maximo 500 itraciones para encontrar la raiz
	while(fabs(fx) > tolerancia && no_Iteraciones <= 500)
	{
		derivada = Derivada(polaca,x0);
		if(fabs(derivada) > 0.0)
		{
			x0 = x0 - (Evalua(polaca,x0)/derivada);
			fx = Evalua(polaca,x0);
			no_Iteraciones ++;
		}
		else break; // la derivada en alguna iteracion dio 0.
	}
	if(no_Iteraciones > 500)
		{gotoxy(1,4);printf("No se Encontro una raiz para esta Ecuaci¢n con 500 iteraciones.\n");
		x0 = 0;
		}
	if(derivada == 0.0)
		{gotoxy(1,4);printf("Error. La Derivada dio 0.0.");
		gotoxy(1,5);printf("Si el error persiste, modificar el valor inicial.");
		}
	valor_final = x0;
	gcvt(valor_final,6,string);
	return string;

}
char* integral(Cola &integral)
{
	Cola auxiliar(30),polaca(30);
	pila_cola aux;
	const int NN = 4096; // el valor de N es constante de NN intervalos
	double a = 0.0,b = 0.0,deltax = 0.0,valor_final = 0.0;
	double valor_pares = 0.0, valor_inpares = 0.0,auxi;
	int contador = 1,signo = 0,reves = 0;
	char string[30];
	integral.sacar(); // quita el simbolo de la integral 'integral('
	aux = integral.sacar();  // obtiene el primer elemento
	while(strcmp(aux.token,",")!=0)
	{
		auxiliar.meter(aux);
		aux = integral.sacar();
	}
	formaPolaca(auxiliar,polaca); // transforma a forma polaca
	aux = integral.sacar();
	if(!strcmp(aux.token,"+") || !strcmp(aux.token,"-")|| !strcmp(aux.token,"ñ"))
	{
		if(!strcmp(aux.token,"-")|| !strcmp(aux.token,"ñ"))
			signo = 1;
		aux = integral.sacar();
	}
	a = atof(aux.token);
	if(signo) a*= -1;
	signo = 0;
	aux = integral.sacar();// la coma
	aux = integral.sacar(); // valor de b
	if(!strcmp(aux.token,"+") ||  !strcmp(aux.token,"-")|| !strcmp(aux.token,"ñ"))
	{
		if(!strcmp(aux.token,"-")|| !strcmp(aux.token,"ñ"))
			signo = 1;
		aux = integral.sacar();
	}

	b = atof(aux.token);
	if(signo) b*= -1;
	// por si el valor de a es mayor al de b
	if (a > b)
	{
		auxi = a;
		a = b;
		b = auxi;
		reves = 1;
	}
	else if(a == b) return "0"; // los dos valores son iguales no hay area

	deltax = (b - a)/NN;
	/***** formula de simpson 1/3 ***************/
	valor_final = Evalua(polaca,a);
	valor_final = valor_final + Evalua(polaca,b);
	a = a + deltax; // incremento
	while(a <=(b-deltax))
	{
		if((contador % 2) == 0)   // valores pares
			valor_pares = valor_pares + Evalua(polaca,a);
		else if((contador % 2) != 0) // valores impares
			valor_inpares = valor_inpares + Evalua(polaca,a);
		a = a + deltax; // incremento
		contador++;
	}
	valor_pares = valor_pares * 2.0;
	valor_inpares = valor_inpares * 4.0;
	valor_final = valor_final + valor_pares + valor_inpares;
	valor_final = (valor_final * deltax) / 3 ;  // regla de sipson 1/3
	if (reves) valor_final*=-1;
	gcvt(valor_final,6,string);
	return string;

}
void formaPolaca(Cola &origen,Cola &sufija)
{
	pila_cola aux,aux2,anterior; // valor anterior
	Pila_Opers pila = new Pila_opers(30);
	int paso3 = 0,parentesis = 1;// para contar los parentesis
	char valor[15],tipo[10],puesto = 0;
	Cola simpson(30);
	while(!origen.vacia())
	{
		aux = origen.sacar();
		// si es operando se extrae como salida
		if(operando(aux) || !strcmp(aux.token,"integral(") ||
		!strcmp(aux.token,"newton(") || !strcmp(aux.token,"grafica("))
		{
			if(!strcmp(aux.token,"integral(") || !strcmp(aux.token,"newton(")
			|| !strcmp(aux.token,"grafica("))
			{
				strcpy(tipo,aux.token);
				while(parentesis != 0)
				{
					simpson.meter(aux);
					aux = origen.sacar();
					if(!strcmp(aux.token,")"))
						parentesis--;
					if(!strcmp(aux.token,"("))
						parentesis++;

				}
				simpson.meter(aux); // mete el parentesis
				if(!strcmp(tipo,"integral("))
				{
					esIntegral = 1;
					strcpy(aux.token,integral(simpson));
				}
				if(!strcmp(tipo,"newton("))
				{
					esNewton = 1;
					strcpy(aux.token,newtonRapson(simpson));
				}
				if(!strcmp(tipo,"grafica("))
				{
					esGrafica = 1; // es grafica
					GraficaEcuacion(simpson);
					break;
				}
			}
			if(!strcmp(aux.token,"x") && !esGrafica && !esNewton &&
			!esIntegral && !puesto)
			{
				do{
					puntos = errorc = 0;
					gotoxy(1,4);
					clreol();
					printf("X? "); gets(variable);
					strupr(variable);
					for(int i=0; i<strlen(variable); i++)
						if(variable[i] == '.') puntos++;
					if(puntos > 1) errorc = 1;
					 if(!strcmp(variable,"PI")) X = M_PI;
					 else if(!strcmp(variable,"ANS")) X = ans;
					 else X = atof(variable);
				  }while(errorc);
				gotoxy(1,5);
				printf("Presiona \"C\" si deseas volver a calcular.");
				puesto = Variable_x = 1; // hay una varible
			}
			sufija.meter(aux);  // esta es la cola polaca
		}
		else if(strcmp(aux.token,"(")==0)
			pila->push(aux);   // mete a la pila de operadores
		else if(operador(aux))
		{
			do
			{
				paso3 = 0;
				if(!pila->vacia())aux2 = pila->cima();
				//NOTA:la siguiente condicion es solo para cuando el usuario mete
				// el operador "-" en vez del "ñ" que uno es binario y el
				// otro unario y no haga mal la operacion en si los dos van
				// a hacer lo mismo.
				if( !strcmp(aux.token,"-") && ((operador(anterior) ||
				!strcmp(anterior.token,"(")) || (pila->vacia() && sufija.vacia()))
				&& ( strcmp(anterior.token,"!")!=0 && strcmp(anterior.token,"ý")!=0))
				{
					strcpy(aux.tipo,"unario");
					strcpy(aux.token,"ñ");
					aux.prioridad = 5;
					pila->push(aux);
				}
				// si la prioridad del operador es mas alta que el que esta
				// en la cima de la pila, simplemente se apila
				else if((aux.prioridad > aux2.prioridad) || pila->vacia())
					pila->push(aux);
				// si el de la cima de la pila es de mayor prioridad, y el
				// operador de la cima de la pila es binario y el operador
				// siguiente es binario se extrae a la salida
				else if((aux.prioridad <= aux2.prioridad) && (strcmp(aux.tipo,"unario")!=0
				|| strcmp(aux2.tipo,"unario")!=0 ) && !sufija.vacia())
				{
					sufija.meter(pila->pop()); // desapila el operador com mayor prioriodad
					paso3 = 1;
				}
				// si alguna de los dos fue unario se mete a la pila no
				// importa que sea de mayor prioridad.  eje: sen sen 45
				// deve de quedar 45 sen sen en forma polaca
				else
					pila->push(aux);  // para los operadores unarios
			}while(paso3);
		}
		// si es cierre de parentesis, desapilar todos los operadores
		// hasta que se encuentre el parentesis de apertura, descartar
		// el parentesis de apertura
		else if(strcmp(aux.token,")")==0)
		{
			aux2 = pila->cima();
			while(strcmp(aux2.token,"(")!=0 && !pila->vacia())
			{
				sufija.meter(pila->pop());
				aux2 = pila->cima();
			}
			pila->pop();  // descarta el parentesis de apertura.
		}
		// para la condicion del signo menos !!!!!!
		anterior = aux;

	}
	// si quedaron operadores, meterlos a la salida
	while(!pila -> vacia())
		sufija.meter(pila->pop());

	free(pila);
}
double Evalua(Cola &origen,double Valor_x)
{
	pila_cola aux;
	while(!origen.vacia())
	{
		aux = origen.sacar();
		if(operando(aux))
		{
			if(strcmp(aux.token,"pi")==0)
				valores.push(M_PI);
			else if(strcmp(aux.token,"ans")==0)
				valores.push(ans);
			else if(strcmp(aux.token,"x")==0)
				valores.push(Valor_x);

			else valores.push(atof(aux.token));
		}
		else
		{
			if(strcmp(aux.token,"acos")==0)  arcocoseno();
			  if(strcmp(aux.token,"asen")==0) arcoseno();
				if(strcmp(aux.token,"atan")==0) arcotan();
				  if(strcmp(aux.token,"sen")==0) seno();
					if(strcmp(aux.token,"cos")==0) coseno();
					  if(strcmp(aux.token,"tan")==0) tangente();
						if(strcmp(aux.token,"!")==0)  factorial();
						  if(strcmp(aux.token,"ý")==0)  cuad();
							if(strcmp(aux.token,"^")==0)  potencia();
							  if(strcmp(aux.token,"ñ")==0) menos();
								if(strcmp(aux.token,"©")==0) universal();
								  if(strcmp(aux.token,"raiz")==0) raiz();
									if(strcmp(aux.token,"%")==0)  modulo();
									  if(strcmp(aux.token,"*")==0) multi();
										if(strcmp(aux.token,"/")==0) division();
										  if(strcmp(aux.token,"+")==0) suma();
											if(strcmp(aux.token,"-")==0) resta();
											  if(strcmp(aux.token,"log")==0)  logaritmo10();
												if(strcmp(aux.token,"ln")==0) l_natural();
												  if(strcmp(aux.token,"e")==0) exponencial();

		}
	}
	origen.back();
	if(!valores.vacia()) return valores.pop();
	else return 0.0;
}
void seno()
{
	double v;
	if(!valores.vacia())
	{
		if(esGrafica || grados)
		{
			v = sin(valores.pop()*M_PI/180.0);
			if(esGrafica)
				v = v * 100; //100 de zoom
		   valores.push(v);
		}
		else if(radianes)
			valores.push(sin(valores.pop()));
	}
   else
		{gotoxy(1,5);printf("Err¢r de la pila.");}
}
void coseno()
{
	double v;
	if(!valores.vacia())
	{
		if(esGrafica || grados)
		{
			v = cos(valores.pop()*M_PI/180.0);
			if(esGrafica)
				v = v * 100; //100 de zoom
		   valores.push(v);
		}
		else if(radianes)
			valores.push(cos(valores.pop()));
	}
   else
		{gotoxy(1,5);printf("Err¢r de la pila.");}

}
void tangente()
{
	double v;
	if(!valores.vacia())
	{
		if(esGrafica || grados)
		{
			v = tan(valores.pop()*M_PI/180.0);
			 if (v==M_PI/2||v==3/2*M_PI) {
				gotoxy(1,4);printf("Tan   Pi/2 : infinito.");
				valores.push(0.0);
				return;
			}
			if(esGrafica)
				v = v * 100; //100 de zoom
		   valores.push(v);
		}
		else if(radianes)
			valores.push(tan(valores.pop()));
	}
   else
		{gotoxy(1,5);printf("Err¢r de la pila.");}

}
void arcoseno()
{
	double v,resultado = 0.0;
	if(!valores.vacia())
	{
		if(esGrafica || grados)
		{
			v = valores.pop();
			 if(fabs(v)<0||fabs(v)>1) {
				gotoxy(1,4);cprintf("Argumento de Asen fuera de rango [0,1].");
				valores.push(0.0);
				return;
			}
		else if(v==1) resultado=M_PI/2;
			else if(v==-1) resultado= - M_PI/2;
			  else resultado=asin(v);
			  resultado =180.0*resultado/M_PI;
			if(esGrafica)
				resultado = resultado / 2; //100 de zoom
		   valores.push(resultado);
		}
		else if(radianes)
		{
			v =  valores.pop();
			if(fabs(v)<0||fabs(v)>1) {
				gotoxy(1,4);cprintf("Argumento de Asen fuera de rango [0,1].");
				valores.push(0.0);
				return;
			}
			else if(v==1) resultado=M_PI/2;
			else if(v==-1) resultado=-M_PI/2;
			  else resultado=asin(v);

			valores.push(resultado);
		}
	}
   else
		{gotoxy(1,5);printf("Err¢r de la pila.");}

}
void arcocoseno()
{
	double v,resultado = 0.0;
	if(!valores.vacia())
	{
		if(esGrafica || grados)
		{
			v = valores.pop();
			 if(fabs(v)<0||fabs(v)>1) {
				gotoxy(1,4);cprintf("Argumento de Acos fuera de rango [0,1].");
				valores.push(0.0);
				return;
			}
		else if(v==0) resultado=M_PI/2;
			else if(v==-1) resultado=M_PI;
			  else resultado=acos(v);
			  resultado = 180.0*resultado/M_PI;
			if(esGrafica)
				resultado = resultado /2; //100 de zoom
		   valores.push(resultado);
		}
		else if(radianes)
		{
			v =  valores.pop();

			if(fabs(v)<0||fabs(v)>1) {
				gotoxy(1,4);cprintf("Argumento de Acos fuera de rango [0,1].");
				valores.push(0.0);
			}
			else if(v==0) resultado=M_PI/2;
			else if(v==-1) resultado=M_PI;
			  else resultado=acos(v);

			valores.push(resultado);
		}
	}
   else
		{gotoxy(1,5);printf("Err¢r de la pila.");}


}
void arcotan()
{
	double v;
	if(!valores.vacia())
	{
		if(esGrafica || grados)
		{
			v = atan(valores.pop());
			v = v*180.0/M_PI;
			if(esGrafica)
				v = v * 100; //100 de zoom
		   valores.push(v);
		}
		else if(radianes)
			valores.push(atan(valores.pop()));
	}
   else
		{gotoxy(1,5);printf("Err¢r de la pila.");}

}
void logaritmo10()
{
	double a;
	if(!valores.vacia())
	{
		a = valores.pop();
		if(a > 0) // no hay logaritmos menores de 0
		valores.push(log10(a));
		else
		{gotoxy(1,4);printf("Logar¡tmo no definido.");}
	}
	   else
		{gotoxy(1,5);printf("Err¢r de la pila.");}

}
void l_natural()
{
	double a;
	if(!valores.vacia())
	{
		a = valores.pop();
		if(a > 0) // no hay logaritmos menores de 0
		valores.push(log(a));
		else
		{gotoxy(1,4);printf("Logar¡tmo no definido.");}
	}
	   else
		{gotoxy(1,5);printf("Err¢r de la pila.");}

}
void factorial()
{
	int i,val;
	long double res = 1;
	if(!valores.vacia())
	{
		val = (int)valores.pop();
		if(val <=170){
		for(i=val; i>=1; i--)
			res = res*i;
		valores.push((double)res);
	   }
	   else{
		valores.push(-1.0);
		gotoxy(1,5);printf("Valor Exced¡do de rango.");}

	}
	else
		{gotoxy(1,5);printf("Err¢r de la pila.");}
}
void cuad()
{
	if(!valores.vacia())
	valores.push(pow(valores.pop(),2));
		else
		{gotoxy(1,5);printf("Err¢r de la pila.");}

}
void potencia()
{
		double a,b;
	if(!valores.vacia())a = valores.pop();
		else
		{gotoxy(1,5);printf("Err¢r de la pila.");}

	if(!valores.vacia())b = valores.pop();
	else
	   {gotoxy(1,5);printf("Err¢r de la pila.");}

		valores.push(pow(b ,a));

}
void exponencial()
{
	gotoxy(1,4);
	if(!valores.vacia())
	valores.push(exp(valores.pop()));
	else
		{gotoxy(1,5);printf("Err¢r de la pila.");}

}
void menos()
{
	if(!valores.vacia())
	valores.push(valores.pop() * -1 );
	else
		{gotoxy(1,5);printf("Err¢r de la pila.");}

}
void universal()
{
	double a,b,resultado = 0.0;
	double yabs, xint, xfrac, xpar;
	char ban=0;
	if(!valores.vacia())
	{
		b = valores.pop();
		a = valores.pop();
		xfrac=modf(a, &xint);
		xpar=fmod(xint,2);
		yabs=fabs(b);

		if(b<0&&(xfrac!=0||xpar==0)) {
			gotoxy(1,4);cprintf("© Ra¡z no definida...   ");
			valores.push(0.0);
		return;
	}
	if(b<0&&(xfrac!=0||xpar!=0)) { b=yabs;ban=1; }

	resultado=1/a;
	resultado=pow(b,resultado);
	if (ban) resultado=-resultado;
	valores.push(resultado);

	}
	else
		{gotoxy(1,5);printf("Err¢r de la pila.");}

}
void raiz()
{
	double a;
	if(!valores.vacia())
	{
		a = valores.pop();
		if(a < 0) // Error en el numero
		{
			gotoxy(1,4);printf("Ra¡z de n£mero negat¡vo no definida.");
			valores.push(0.0);
		}

		else valores.push(sqrt(a));
	}
	else
	{gotoxy(1,5);printf("Err¢r de la pila.");}

}
void suma()
{
	double a = NULL, b = NULL,ax = 0,bx = 0;
	if(!valores.vacia()){a = valores.pop(); ax = 1;}
	if(!valores.vacia()){b = valores.pop(); bx = 1;}
	if(bx == 0)
			valores.push(a);
	else if(bx!=0 && ax!= 0)
		valores.push(a + b);
	else
		{gotoxy(1,5);printf("Err¢r de la pila.");}


}
void resta()
{
	static int unario = 0;
	double a = NULL, b = NULL,ax = 0,bx = 0;
	if(!valores.vacia()) {a = valores.pop(); ax = 1;}
	if(!valores.vacia()) {b = valores.pop(); bx = 1;}
	if(bx == 0)
		{valores.push(a * -1); unario ++;}
	else if(bx!= 0 && ax!= 0 && (unario % 2)==0)
		valores.push(b - a);
	else
		{valores.push(a - b);  unario = 0;}
}
void multi()
{
	double a,b;
	if(!valores.vacia())a = valores.pop();
		else
		{gotoxy(1,5);printf("Err¢r de la pila.");}

	if(!valores.vacia())b = valores.pop();
	else
	   {gotoxy(1,5);printf("Err¢r de la pila.");}

		valores.push(a * b);

}
void division()
{
	double a,b;
	if(!valores.vacia())a = valores.pop();
		else
		{gotoxy(1,5);printf("Err¢r de la pila.");}

	if(!valores.vacia())b = valores.pop();
	else
	   {gotoxy(1,5);printf("Err¢r de la pila.");}

		if(a == 0.0)
		   {gotoxy(1,4);printf("Err¢r. divisi¢n entre 0.");}
		else
		valores.push(b / a);
}
void modulo()
{
	double a,b;
	if(!valores.vacia())a = valores.pop();
		else
		{gotoxy(1,5);printf("Err¢r de la pila.");}

	if(!valores.vacia())b = valores.pop();
	else
	   {gotoxy(1,5);printf("Err¢r de la pila.");}

		valores.push(fmod(b ,a));

}
void planoCartesiano()
{
	int x,y;
	char numero[10];
	clearviewport();
	setcolor(10);
	moveto(0,0);
	lineto(639,0);
	lineto(639,479);
	lineto(0,479);
	lineto(0,0);
	setcolor(15);
	outtextxy(10,10,"Zoom: pixel por cooredenada.");
	x = getmaxx()/2;
	moveto(x,0);
	lineto(x,479);
	outtextxy(x+5,5,"[X]");
	y = getmaxy()/2;
	moveto(0,y);
	lineto(639,y);
	outtextxy(5,y-12,"[Y]");
	moveto(getmaxx()/2,getmaxy()/2);
	settextstyle(2,HORIZ_DIR,4);
	for(int i = -320; i<=280; i+=40)
	{
		itoa(i,numero,10);
		outtextxy(i + getmaxx()/2,getmaxy()/2,numero);
	}
	moveto(getmaxx()/2,5);
	for(int j = 220; j>=-220; j-=40)
	{
		itoa(j,numero,10);
		outtextxy(getmaxx()/2,getmaxy()/2-j,numero);
	}

}
void separa_tokens(){

	char cadena[100]="",caden[100]="",**p;
	int j,L,existe=0;
	int cont=0,k=0,cont1=0;
	L=strlen(form);
	for(j=0; k<L;j++)
	{
		while(isdigito(form[k]) ||form[k]=='.')
		{
			caden[cont1]=form[k];caden[cont1+1]='\0';
			k++; cont1++;
			existe=1;
		}
		cadena[cont]=form[k]; cadena[cont+1]='\0';
		cont++;k++;
		p = (char **)tokens;
		do
		{
			if(!strcmp(*p,cadena)||cadena[0]=='\0' )
			{
				if(existe)
					cola.meter(caden,"0","numero");
				if(cadena[0]!='\0') cola.meter(cadena,*(p+1),*(p+2));
				cont=0;cont1=0;
				existe=0;
				cadena[0] = '\0';
				break;
			}
			p = p + 3;
		}while(*p);
	}
	if(cadena [0] != '\0') error1(); // quedaron residuos en la pila.
}

int compilaExpresion(char *expresion)
{

	// La variable parentesis se utiliza como u automata de pila, solo que
	// un poco burdo, pues solo los contar , y marcara error si la variable
	// es diferente de 0.

	int estado = 0, entrada = 0,parentesis = 0;
	int y1 = wherey(), x1 = wherex();
	int Automata[101][25] =
	// automata de 100 estados y uno de Error
/*
		 .  +-ñ  0.9 *../ !   a   c   e   f   g  i   l  n   o  p   r   s   t   w   x  z  ,  (  )  FDC  */
/*0*/ {{1 , 3 , 4 , N , N , 16, 20, 12, N, 47, 32, 8, 41, N, 27, 23, 17, 13, N, 29, N, N, 0, N, error},
/*1*/  {N , N , 2 , N , N , N , N , N , N, N , N , N, N , N, N , N , N , N , N, N , N, N, N, N, error},
/*2*/  {5 , 0 , 2 , 0 , 7 , N , N , N , N, N , N , N, N , N, N , N , N , N , N, N , N, N, N, 2, aceptacion},
/*3*/  {1 , 3 , 2 , N , N , 16, 20, 12, N, 47, 32, 8, 41, N, 27, 23, 17, 13, N, 29, N, N, 0, 0, error},
/*4*/  {5 , 0 , 4 , 0 , 7 , N , N , N , N, N , N , N, N , N, N , N , N , N , N, N , N, N, N, 4, aceptacion},
/*5*/  {N , N,  6 , N , N , N , N , N , N, N , N , N, N , N, N , N , N , N , N, N , N, N, N, N, error },
/*6*/  {N , 0,  6 , 0 , 7, N , N , N , N, N , N , N, N , N, N , N , N , N , N, N , N, N, N, 6, aceptacion},
/*7*/  {N , 0 , N , 0 , 7 , N , N , N , N, N , N , N, N , N, N , N , N , N , N, N , N, N, N, 7, aceptacion},
/*8*/  {N , N , N , N , N , N , N , N , N, N , N , N, 9 , 10, N, N , N , N , N, N , N, N, N, N, error},
/*9*/  {1 , 3 , 4 , N , N , 16, 20, 12, N, 47, 32, 8, 41, N, 27, 23, 17, 13, N, 29, N, N, 9, N,  error},
/*10*/ {N , N , N , N , N , N , N , N , N, 11, N , N, N , N, N , N , N , N , N, N , N, N, N, N, error},
/*11*/ {1 , 3 , 4 , N , N , 16, 20, 12, N, 47, 32, 8, 41, N, 27, 23, 17, 13, N, 29, N, N, 11, N,  error},
/*12*/ {1 , 3 , 4 , N , N , 16, 20, 12, N, 47, 32, 8, 41, N, 27, 23, 17, 13, N, 29, N, N, 12, N, error},
/*13*/ {N , N , N , N , N , 14, N , N , N, N , N , N, N , N, N , N , N , N , N, N , N, N, N, N, error},
/*14*/ {N , N , N , N , N , N , N , N , N, N , N , N, 15, N, N , N , N , N , N, N , N, N, N, N, error},
/*15*/ {1 , 3 , 4 , N , N , 16, 20, 12, N, 47, 32, 8, 41, N, 27, 23, 17, 13, N, 29, N, N, 15, N, error},
/*16*/ {N , N , N , N , N , N , 20, N , N, N , N , N, 30, N, N , N , 17, 13, N, N , N, N, N, N, error},
/*17*/ {N , N , N , N , N , N , N , 18, N, N , N , N, N , N, N , N , N , N , N, N , N, N, N, N, error},
/*18*/ {N , N , N , N , N , N , N , N , N, N , N , N, 19, N, N , N , N , N , N, N , N, N, N, N, error},
/*19*/ {1 , 3 , 4 , N , N , 16, 20, 12, N, 47, 32, 8, 41, N, 27, 23, 17, 13, N, 29, N, N, 19, N,  error},
/*20*/ {N , N , N , N , N , N , N , N , N, N , N , N, N , 21, N, N , N , N , N, N , N, N, N, N, error},
/*21*/ {N , N , N , N , N , N , N , N , N, N , N , N, N , N , N, N , 22, N , N, N , N, N, N, N, error},
/*22*/ {1 , 3 , 4 , N , N , 16, 20, 12, N, 47, 32, 8, 41, N, 27, 23, 17, 13, N, 29, N, N, 22, N,  error},
/*23*/ {N , N , N , N , N , 24, N , N , N, N , N , N, N , N , N, N , N , N , N, N , N, N, N, N, error},
/*24*/ {N , N , N , N , N , N , N , N , N, N , 25, N, N , N , N, N , N , N , N, N , N, N, N, N, error},
/*25*/ {N , N , N , N , N , N , N , N , N, N , N , N, N , N , N, N , N , N , N, N , 26, N, N, N, error},
/*26*/ {1 , 3 , 4 , N , N , 16, 20, 12, N, 47, 32, 8, 41, N, 27, 23, 17, 13, N, 29, N, N, 26, N,  error},
/*27*/ {N , N , N , N , N , N , N , N , N, N , 28, N, N , N , N, N , N , N , N, N , N, N, N, N, error},
/*28*/ {N , 0 , N , 0 , 7 , N , N , N , N, N , N , N, N , N , N, N , N , N , N, N , N, N, N, 28, aceptacion},
/*29*/ {N , 0 , N , 0 , 7 , N , N , N , N, N , N , N, N , N , N, N , N , N , N, N , N, N, N, 29, aceptacion},
/*30*/ {N , N , N , N , N , N , N , N , N, N , N , N, N , N , N, N , 31, N , N, N , N, N, N, N, error},
/*31*/ {N , 0 , N , 0 , 7 , N , N , N , N, N , N , N, N , N , N, N , N , N , N, N , N, N, N, N, aceptacion},
/*	    .   +-  0.9 *../ !   a   c   e   f  g   i   l  n   o  p   r   s   t   w   x  z  ,  (  )  FDC  */
/*32*/ {N , N , N , N , N , N , N , N , N, N , N , N, 33, N , N, N , N , N , N, N , N, N, N, N, error},
/*33*/ {N , N , N , N , N , N , N , N , N, N , N , N, N , N , N, N , N , 34, N, N , N, N, N, N, error},
/*34*/ {N , N , N , N , N , N , N , 35, N, N , N , N, N , N , N, N , N , N , N, N , N, N, N, N, error},
/*35*/ {N , N , N , N , N , N , N , N , N, 36, N , N, N , N , N, N , N , N , N, N , N, N, N, N, error},
/*36*/ {N , N , N , N , N , N , N , N , N, N , N , N, N , N , N, 37, N , N , N, N , N, N, N, N, error},
/*37*/ {N , N , N , N , N , 38, N , N , N, N , N , N, N , N , N, N , N , N , N, N , N, N, N, N, error},
/*38*/ {N , N , N , N , N , N , N , N , N, N , N , 39, N , N , N, N , N, N , N, N , N, N, N, N, error},
/*39*/ {N , N , N , N , N , N , N , N , N, N , N , N , N , N , N, N , N, N , N, N , N, N, 40, N, error},
/*40*/ {54, 56, 57, N , N , 69, 75, 65, N, N , N , 61, N , N , 82, 78,72,66, N, 84, N, N, 40, N,error},
/*41*/ {N , N , N , N , N , N , N , 42, N, N , N , N , N , N , N, N , N, N , N, N , N, N, N , N, error},
/*42*/ {N , N , N , N , N , N , N , N , N, N , N , N , N , N , N, N , N, N , 43, N , N, N, N, N, error},
/*43*/ {N , N , N , N , N , N , N , N , N, N , N , N , N , N , N, N , N, 44, N, N , N, N, N, N, error},
/*44*/ {N , N , N , N , N , N , N , N , N, N , N , N , N , 45, N, N , N, N , N, N , N, N, N, N, error},
/*45*/ {N , N , N , N , N , N , N , N , N, N , N , N , 46, N , N, N , N, N , N, N , N, N, N, N, error},
/*46*/ {N , N , N , N , N , N , N , N , N, N , N , N , N , N , N, N , N, N , N, N , N, N, 40, N, error},
/*47*/ {N , N , N , N , N , N , N , N , N, N , N , N , N , N , N, 48, N, N , N, N , N, N, N, N, error},
/*48*/ {N , N , N , N , N , 49, N , N , N, N , N , N , N , N , N, N , N, N , N, N , N, N, N, N, error},
/*49*/ {N , N , N , N , N , N , N , N , 50, N, N , N , N , N , N, N , N, N , N, N , N, N, N, N, error},
/*50*/ {N , N , N , N , N , N , N , N , N , N, 51, N , N , N , N, N , N, N , N, N , N, N, N, N, error},
/*51*/ {N , N , N , N , N , N , 52, N , N , N, N , N , N , N , N, N , N, N , N, N , N, N, N, N, error},
/*52*/ {N , N , N , N , N , 53, N , N , N , N, N , N , N , N , N, N , N, N , N, N , N, N, N, N, error},
/*53*/ {N , N , N , N , N , N , N , N , N , N, N , N , N , N , N, N , N, N , N, N , N, N, 40, N, error},
/*54*/ {N , N , 55, N , N , N , N , N , N , N, N , N , N , N , N, N , N, N , N, N , N, N, N, N, error},
/*55*/ {58, 40, 55, 40, 60, N , N , N , N , N, N , N , N , N , N, N , N, N , N, N , N, 85,N, 55, error},
/*56*/ {54, 56, 55, N , N , 69, 75, 65, N , N , N , 61, N, N , 82, 78,72,66, N, 84, N, N, 40, N,error},
/*57*/ {58, 40, 57, 40, 60, N , N , N , N , N, N , N , N , N , N, N , N, N , N, N , N, 85,N, 57, error},
/*58*/ {N , N , 59, N , N , N , N , N , N , N, N , N , N , N , N, N , N, N , N, N , N, N, N, N, error},
/*59*/ {N , 40, 59, 40, 60, N , N , N , N , N, N , N , N , N , N, N , N, N , N, N , N, 85, N, 59, error},
/*60*/ {N , 40, N , 40, 60, N , N , N , N , N, N , N , N , N , N, N , N, N , N, N , N, 85, N, 60, error},
/*61*/ {N , N , N , N , N , N , N , N , N , N, N , N , 62, 63, N, N , N, N , N, N , N, N, N, N, error},
/*62*/ {54, 56, 57, N , N , 69, 75, 65, N , N, N , 61, N , N , 82,78,72,66, N, 84, N, N, 40, N,error},
/*63*/ {N , N , N , N , N , N , N , N , N , 64, N , N , N , N , N,N , N, N , N, N , N, N, N, N, error},
/*64*/ {54, 56, 57, N , N , 69, 75, 65, N , N, N , 61, N , N , 82,78, 72,66, N, 84, N, N, 40, N,error},
/*65*/ {54, 56, 57, N , N , 69, 75, 65, N , N, N , 61, N , N , 82,78, 72,66, N, 84, N, N, 40, N,error},
/*66*/ {N , N , N , N , N , 67, N , N , N , N, N , N , N , N , N, N , N, N , N, N , N, N, N, N, error},
/*67*/ {N , N , N , N , N , N , N , N , N , N, N , N , 68, N , N, N , N, N , N, N , N, N, N, N, error},
/*68*/ {54, 56, 57, N , N , 69, 75, 65, N , N, N , 61, N , N , 82,78, 72,66, N, 84, N, N, 40, N,error},
/*69*/ {N , N , N , N , N , N , 75, N , N , N, N , N , 70, N , N, N , 72,66, N, N , N, N, N, N, error},
/*70*/ {N , N , N , N , N , N , N , N , N , N, N , N , N , N , N, N , 71,N , N, N , N, N, N, N, error},
/*71*/ {N , 40, N , 40, 60, N , N , N , N , N, N , N , N , N , N, N , N ,N , N, N , N, 85, N, 71, error},
/*	    .   +-  0.9 *../ !   a   c   e   f   g   i   l  n   o  p   r   s  t   w   x  z  ,  (   )  FDC  */
/*72*/ {N , N , N , N , N , N , N , 73, N , N, N , N , N , N , N, N , N ,N , N, N , N, N , N, N, error},
/*73*/ {N , N , N , N , N , N , N , N , N , N, N , N , 74, N , N, N , N ,N , N, N , N, N , N, N, error},
/*74*/ {54, 56, 57, N , N , 69, 75, 65, N , N, N , 61, N , N , 82,78, 72,66, N, 84, N, N, 40, N,error},
/*75*/ {N , N , N , N , N , N , N , N , N , N, N , N , N , 76, N, N , N ,N , N, N , N, N , N, N, error},
/*76*/ {N , N , N , N , N , N , N , N , N , N, N , N , N , N , N, N , 77,N , N, N , N, N , N, N, error},
/*77*/ {54, 56, 57, N , N , 69, 75, 65, N , N, N , 61, N , N , 82,78, 72,66, N, 84, N, N, 40, N,error},
/*78*/ {N , N , N , N , N , 79, N , N , N , N, N , N , N , N , N, N , N ,N , N, N , N, N , N, N, error},
/*79*/ {N , N , N , N , N , N , N , N , N , N, 80, N , N , N , N, N , N ,N , N, N , N, N , N, N, error},
/*80*/ {N , N , N , N , N , N , N , N , N , N, N , N , N , N , N, N , N ,N , N, N , 81,N , N, N, error},
/*81*/ {54, 56, 57, N , N , 69, 75, 65, N , N, N , 61, N , N , 82,78, 72,66, N, 84, N, N, 40, N,error},
/*82*/ {N , N , N , N , N , N , N , N , N , N, 83, N , N , N , N, N , N ,N , N, N , N, N , N, N, error},
/*83*/ {N , 40, N , 40, 60, N , N , N , N , N, N , N , N , N , N, N , N ,N , N, N , N, 85, N, 83, error},
/*84*/ {N , 40, N , 40, 60, N , N , N , N , N, N , N , N , N , N, N , N ,N , N, N , N, 85, N, 84, error},
/*85*/ {86, 88, 89, N , N , N , N , N , N , N, N , N , N , N , N, N , N ,N , N, N , N, N , N, N, error},
/*86*/ {N , N , 87, N , N , N , N , N , N , N, N , N , N , N , N, N , N ,N , N, N , N, N , N, N, error},
/*87*/ {90, N , 87, N , N , N , N , N , N , N, N , N , N , N , N, N , N ,N , N, N , N, 92, N, N, error},
/*88*/ {86, N , 87, N , N , N , N , N , N , N, N , N , N , N , N, N , N ,N , N, N , N, N , N, N, error},
/*89*/ {90, N , 89, N , N , N , N , N , N , N, N , N , N , N , N, N , N ,N , N, N , N, 92, N, N, error},
/*90*/ {N , N , 91, N , N , N , N , N , N , N, N , N , N , N , N, N , N ,N , N, N , N, N , N, N, error},
/*91*/ {N , N , 91, N , N , N , N , N , N , N, N , N , N , N , N, N , N ,N , N, N , N, 92, N, N, error},
/*92*/ {93, 95, 96, N , N , N , N , N , N , N, N , N , N , N , N, N , N ,N , N, N , N, N , N, N, error},
/*93*/ {N , N , 94, N , N , N , N , N , N , N, N , N , N , N , N, N , N ,N , N, N , N, N , N, N, error},
/*94*/ {97, N , 94, N , N , N , N , N , N , N, N , N , N , N , N, N , N ,N , N, N , N, N , N, 99, error},
/*95*/ {93, N , 94, N , N , N , N , N , N , N, N , N , N , N , N, N , N ,N , N, N , N, N , N, N, error},
/*96*/ {97, N , 96, N , N , N , N , N , N , N, N , N , N , N , N, N , N ,N , N, N , N, N , N, 99, error},
/*97*/ {N , N , 98, N , N , N , N , N , N , N, N , N , N , N , N, N , N ,N , N, N , N, N , N, N, error},
/*98*/ {N , N , 98, N , N , N , N , N , N , N, N , N , N , N , N, N , N ,N , N, N , N, N , N, 99, error},
/*99*/ {N , 0 , N , 0 , N , N , N , N , N , N, N , N , N , N , N, N , N ,N , N, N , N, N , N, N, aceptacion},
/*100*/{N , N , N , N , N , N , N , N , N , N, N , N , N , N , N, N , N ,N , N, N , N, N , N, N, error}};

	for(int j = 0; j<=strlen(expresion); j++)
	{
		switch(expresion[j])
		{
		////////////////////////////////////////////////////////////////////
		// ESTAS SON TODAS LAS POSIBLES ENTRADAS PARA EL AUTOMATA Y SOLO   //
		// PODRA COMPILAR EXPRESIONES QUE ESTEN EN EL AUTOMATA NI UNA MAS  //
		// NI UNA MENOS, Y CARACTERES EXTRA¥OS MARCARA UN ERROR.           //
	   /////////////////////////////////////////////////////////////////////
			case '.':         entrada = punto; break;
			case '+':case '-':case'ñ':
							  entrada = signos; break;
			case '0':case '1':case'2':
			case '3':case '4':case'5':
			case '6':case '7':case'8':
			case '9':         entrada = digito; break;

			case '/': case'*':
			case '%': case'^':
			case '©':     	  entrada = opers; break;

			case '!':case'ý': entrada = fact; break;
			case 'a': 		  entrada = a; break;
			case 'c': 		  entrada = c; break;
			case 'e': 		  entrada = e; break;
			case 'f': 		  entrada = f; break;
			case 'g': 		  entrada = g; break;
			case 'i': 		  entrada = i; break;
			case 'l': 		  entrada = l; break;
			case 'n': 		  entrada = n; break;
			case 'o': 		  entrada = o; break;
			case 'p': 		  entrada = p; break;
			case 'r': 		  entrada = r; break;
			case 's': 		  entrada = s; break;
			case 't': 		  entrada = t; break;
			case 'w': 		  entrada = w; break;
			case 'x': 		  entrada = x; break;
			case 'z': 		  entrada = z; break;
			case ',': 		  entrada = coma; break;
			case '(': 		  entrada = apertura; parentesis++; break;
			case ')': 		  entrada = cierre; parentesis --;  break;
			case FDC:         entrada = fdc; break;
			case ' ': continue;
			default :
				entrada =  otro; break;
			}
			if(entrada != otro)
				estado = Automata[estado][entrada];
			if(estado==error || estado== aceptacion || entrada == otro||
			estado == N)
				break;

		}
		if(estado == error || entrada == otro || estado == N)
		{
			   gotoxy(x1+4+j,y1);
			   printf("^");
			   printf(" !Error.");
			   return 0;
		}
		if(estado == aceptacion && parentesis == 0)
		{ return 1;}
		else if(parentesis != 0)
		{
			if(parentesis > 0) {
				gotoxy(1,2);
				printf("Falt¢ cerrar un parentesis.");
			}
			else{
				gotoxy(1,2);
				printf("Falt¢ abrir un parentesis.");
			}
			return 0;
		}

	  return 0;
}
void error1()
{
	printf(" Error:\n");
	printf(" Palabra del lenguaje no reconocida por favor verificar.\n");
	printf(" Token no valido..... Error de sintaxis.");
	getch();
}

void cuadro(int x1,int y1,int x2,int y2,int color)
{
	int i;
	textcolor(color);
	 gotoxy(x1,y1); cprintf("Ú");
	 gotoxy(x2,y1); cprintf("¿");
	 gotoxy(x1,y2); cprintf("À");
	 gotoxy(x2,y2); cprintf("Ù");

	for(i=x1+1; i<=x2-1; i++)
	{
		gotoxy(i,y1); cprintf("Ä");
		gotoxy(i,y2); cprintf("Ä");

	}
	for(i=y1+1; i<=y2-1; i++)
	{
		gotoxy(x1,i); cprintf("³");
		gotoxy(x2,i); cprintf("³");

	}

}


 void windows(int x1,int y1,int x2,int y2,int color)
{
	int i;
	textcolor(color);
	 gotoxy(x1,y1); cprintf("É");
	 gotoxy(x2,y1); cprintf("»");
	 gotoxy(x1,y2); cprintf("È");
	 gotoxy(x2,y2); cprintf("¼");

	for(i=x1+1; i<=x2-1; i++)
	{
		gotoxy(i,y1); cprintf("Í");
		gotoxy(i,y2); cprintf("Í");

	}
	for(i=y1+1; i<=y2-1; i++)
	{
		gotoxy(x1,i); cprintf("º");
		gotoxy(x2,i); cprintf("º");

	}

}
void pal(char *p,int c1,int c2){

	int i,res;
	res=strlen(p);
	for(i = 0; i<res; i++){
		if(i==0){
		textcolor(c1);
		cprintf("%c",toupper(p[i]));
		continue;
		}
		textcolor(c2);
		cprintf("%c",p[i]);
	}
}

void Funciones()
{
	textcolor(15);
	gotoxy(1,1);cprintf("integral(<Expresi¢n> ,a,b)");
	textcolor(14);cprintf(" Obtiene la integral definida de una ecuaci¢n");
	gotoxy(1,2);cprintf("con sus valores, inferior a y el superior b.");
	textcolor(15);
	gotoxy(1,3);cprintf("newton(<Expresi¢n> ,x0,h)");
	textcolor(14);
	cprintf(" Obtiene la raiz  ¢ 0 de una ecuaci¢n, donde");
	gotoxy(1,4);cprintf("x0 es el valor inicial y h constante de newton deve ser 0.1.");
	textcolor(15);
	gotoxy(1,5);cprintf("grafica(<Expresi¢n> ,a,b) ");
	textcolor(14);
	cprintf("Graf¡ca una Ecuaci¢n, desde a hasta b.");
	textcolor(14);
	gotoxy(1,7);cprintf("sen");
	gotoxy(1,8);cprintf("cos");
	gotoxy(1,9);cprintf("tan");
	gotoxy(1,10);cprintf("asen");
	gotoxy(1,11);cprintf("acos");
	gotoxy(1,12);cprintf("atan");

	gotoxy(9,7);cprintf("ln");
	gotoxy(9,8);cprintf("log");
	gotoxy(9,9);cprintf("e");
	gotoxy(9,10);cprintf("raiz");
	gotoxy(9,11);cprintf("!");
	gotoxy(9,12);cprintf("ans");

	gotoxy(19,7);cprintf("pi");
	gotoxy(19,8);cprintf("(");
	gotoxy(19,9);cprintf(")");
	gotoxy(19,10);cprintf("ý Alt+253");
	gotoxy(19,11);cprintf("+");
	gotoxy(19,12);cprintf("-");

	gotoxy(31,7);cprintf("*");
	gotoxy(31,8);cprintf("/");
	gotoxy(31,9);cprintf("%");
	gotoxy(31,10);cprintf("rad.-");pal("Radianes",15,14);
	gotoxy(31,11);cprintf("gra.-");pal("Grados",15,14);
	gotoxy(31,12);cprintf("Exit.Salir");


	gotoxy(47,7);cprintf("X    Variable de c lculo");
	gotoxy(47,8);cprintf("^ Potencia.......Alt+ 94");
	gotoxy(47,9);cprintf("ñ Signo menos ...Alt+241");
	gotoxy(47,10);cprintf("© Raiz universal.Alt+169");

}
