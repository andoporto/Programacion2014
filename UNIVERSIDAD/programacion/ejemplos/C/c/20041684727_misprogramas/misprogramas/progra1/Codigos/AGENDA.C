#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <dos.h>

 typedef /* estructura que se utiliza para almacenar los registros */
  struct dato {
   char nombre[50];
   char apellido[50];
   char edad[3];
   char telf[20];
   char direccion[80];
   struct dato *sig;
   struct dato *ant;
  };

 /* Variables Globales */
 struct dato *p;  /* puntero auxiliar */
 struct dato *final;  /* puntero al final de la lista */
 struct dato *inicio; /* puntero al inicio de la lista */
 int guardado = 0; /* revisa si se ha modificado la lista */
 int nleidos = 0; /* cantidad de elementos en la lista */
 int elimina_sm = 0; /* elimina el archivo creado si no se han hecho modificaciones */

 /* -----------------------PROTOTIPO DE LAS FUNCIONES----------------------*/

 struct dato *localiza(char nombre[]); /* localiza el nombre a buscar si existe */
 void modifica(struct dato *aux); /* modifica el registro buscado */
 void buscar(void); /* pide el nombre a buscar e imprime el registro si existe */
 void inserta_reg(struct dato *p); /* inserta registros ordenadamente en la lista */
 void guardar(char *fname); /* guarda la lista en el archivo */
 void cargar(int clave); /* menu en donde se introduce el nombre de archivo */
 void agregar(void); /* pide los datos del registro nuevo */
 void listar(void); /* busca que se han creado o leido */
 void menu_prin(void); /* menu principal crear o cargar archivo */
 void carga(char *fname); /* lee el archivo y crea la lista enlazada si existen registros guardados */
 void menu(char *fname); /* menu para crear,modificar,listar y eliminar registros */
 void revisa(char *fname); /* revisa si los registros de un archivo se han modificado */
 char *minus(char nombre[]); /* convierte las mayusculas en minusculas */

 /* ---------------CONVIERTE LAS MAYUSCULAS A MINUSCULAS-------------------*/
 char *minus(char nombre[])
 {
 register int i;
 register char *temp;

 for (i = 0; i <= strlen(nombre) + 1; i++)
   temp[i] = tolower(nombre[i]);
  return(temp);
 }

 /* -------------------LIBERA LA MEMORIA UTILIZADA------------------------ */

 void libera(void)
 {
 struct dato *aux;

 if (inicio != NULL) /* si realmente existe lista que ocupa espacio */
  {
   final->sig = NULL;
   p = inicio;
   do /* mientras que exista memoria ocupada */
	{
	 aux = p->sig;
	 free(p); /* se libera la memoria ocupada */
	 p = aux; /* pasa a la siguiente estructura */
	} while (p); /* fin de while */
  } /* fin de if */
 } /* fin de la funcion libera() */

 /* ------------INSERTA REGISTROS ORDENADAMENTE EN LA LISTA--------------- */

 void inserta_reg(struct dato *p /* nuevo registro a insertar */)
 {
 struct dato *aux; /* puntero auxiliar */

 aux = inicio;
 if (inicio == NULL) /* insertar el primer registro de una lista */
  {
   inicio = p;
   inicio->ant = inicio;
   final = p;
   final->sig = inicio;
  } else
  for (;;)
   {
	if (strcmp(p->nombre, aux->nombre) < 0)
	 {
	  if (aux == inicio) /* insertar registro al principio de la lista */
	   {
	p->sig = aux;
	p->ant = final;
	aux->ant = p;
	inicio = p;
	final->sig = p;
	return;
	   }
	  else
	   {
	p->ant = aux->ant; /* insertar registros en el medio de la lista */
	p->sig = aux;
	aux->ant->sig = p;
	aux->ant = p;
	return;
	   }
	 } else
	if (aux->sig == inicio) /* insertar registros al final de la lista */
	 {
	  aux->sig = p;
	  p->sig = inicio;
      inicio->ant = p;
      p->ant = aux;
      final = p;
      return;
     }
    aux = aux->sig;
   } /* fin de for(;;) */
 } /* fin de la funci¢n */

 /* ------REVISA SI SE HAN HECHO CAMBIOS EN LOS REGISTROS DE LA LISTA----- */

 void revisa(char *fname)
 {
 char op;

 for (;;) {
  if (guardado == 1)
   {
    clrscr();
    gotoxy(4,5);
    printf("LA LISTA SE HA MODIFICADO, DESEA GUARDAR LOS CAMBIOS ? s/n: ");
    op = tolower(getch());
    if (op == 's')
     guardar(fname); else
    if (op == 'n')
     {
      if (elimina_sm == 1)
       remove(fname);
      return;
     }
   }
  else
   {
    if (elimina_sm == 1)
     remove(fname);
    return;
   }
  } /* fin de bucle infinito (for(;;)) */
 } /* fin de revisar(char *fname) */

 /* -----LEE LOS REGISTROS DEL ARCHIVO Y CREA UNA LISTA DOBLE ENLAZADA---- */

 void carga(char *fname)
 {
 FILE *f;
 int tam;
 struct dato *aux;

 p = final = inicio = NULL;
 f = fopen(fname,"rb");
 rewind(f);
 nleidos = 0;
  for (;;)
  {
   aux = (struct dato *) malloc (sizeof(struct dato));
   if (fread(aux,sizeof(struct dato),1,f) != 1)
    break;
   nleidos++;
   inserta_reg(aux);
  } /* termina for */
  fclose(f);
  if (nleidos == 0)
	p = final = inicio = NULL;
 }

 /* --------------------PIDE LOS DATOS DEL REGISTRO NUEVO----------------- */

 void agregar(void)
 {
  int y,x;

  y = 7;
  x = y + 2;

  guardado = 1;
  nleidos++;
  p = malloc (sizeof(struct dato));
  fflush(stdin); /* vac¡a el buffer del archivo stdin */
  clrscr();
  textcolor(14);
  gotoxy(30,1);
  cprintf("INSERTAR REGISTROS");
  gotoxy(x,3);
  cprintf("Primer nombre: ");  gotoxy(x,6);
  cprintf("Apellidos: "); gotoxy(x,9);
  cprintf("Edad: "); gotoxy(x,12);
  cprintf("Telef¢no: "); gotoxy(x,15);
  cprintf("Direcci¢n: ");
  gotoxy(x + 15,3);
  gets(p->nombre); gotoxy(x + 11,6);
  gets(p->apellido); gotoxy(x + 6,9);
  gets(p->edad); gotoxy(x + 10,12);
  gets(p->telf); gotoxy(x+ 11,15);
  gets(p->direccion);
  inserta_reg(p);
 } /* fin de la funcion */

 /* -----------------ELIMINA UN REGISTRO DE LA LISTA---------------------- */

 void elimina(struct dato *aux)
 {
  struct dato *q;

  q = aux->ant;
  q->sig = aux->sig;
  aux->sig->ant = q;
  free(aux);
 }

 /*LOCALIZA EL NOMBRE A BUSCAR SI SE ENCUENTRA EN LA LISTA, SINO DEVUELVE NULL*/

 struct dato *localiza(char pnombre[])
 {
 struct dato *aux;
 register char temp2[50];
 char temp1[50];

 aux = inicio;
 strcpy(temp1,minus(pnombre));

 do
  {
   strcpy(temp2,minus(aux->nombre));
   if (!strcmp(temp1,temp2))
	return (aux);
   else
	aux = aux->sig;
  } while (aux != inicio);
 return (aux = NULL);
 }

 /* ------------------BUSQUEDA DE REGISTROS DIRECTAMENTE-------------------*/

 void buscar(void)
 {
 char op;
 char nombre[50];
 struct dato *aux;
 int i;
 int color1 = WHITE;
 int color2 = RED;

 if (nleidos == 0) /* comprueba que realemnte existe registros */
 {
  clrscr();
  gotoxy(23,5);
  printf("NO SE ENCUENTRAN REGISTROS GUARDADOS");
  gotoxy(80,25);
  getch();
  return;
 }

 for(;;)
  {
   clrscr();
   gotoxy(30,1);
   textcolor(9);
   cprintf("BUSQUEDA DE REGISTROS");
   textcolor(WHITE);
   gotoxy(12,6);
   textcolor(WHITE);
   cprintf("Introduzca el nombre de la persona: ");
   textcolor(RED);
   gets(nombre);
   textcolor(WHITE);
   if (!nombre[0])
	return;
	clrscr();
  /* bloque de busqueda */
	 aux = localiza(nombre); /* busca el nombre en la lista */
	 if (aux) /* si coinciden los nombres */
	  {
	gotoxy(4,2); textcolor(2);
	cprintf("Nombre: "); textcolor(1);
	cprintf("%s",aux->nombre);
	gotoxy(4,4); textcolor(2);
	cprintf("Apellido: "); textcolor(1);
	cprintf("%s",aux->apellido);
	gotoxy(4,6); textcolor(2);
	cprintf("Edad: "); textcolor(1);
	cprintf("%s",aux->edad);
	gotoxy(4,8); textcolor(2);
	cprintf("Telef¢no: "); textcolor(color1);
	cprintf("%s",aux->telf);
	gotoxy(4,10); textcolor(1);
	cprintf("Direcci¢n: "); textcolor(1);
	cprintf("%s",aux->direccion);
	for (;;)
	 {
	  gotoxy(2,24);
	  cprintf("Presione (M) para modificar (Q) para salir u otra tecla para continuar ");
	  op = toupper(getch());
	  if (op == 'M')
	   {
		modifica(aux);
		break;
	   } else
	  if (op == 'Q')
	   return;
	  else
	  break;
	 }
	  }
	 else /* si no se encontr¢ el nombre */
	  {
	gotoxy(19,11);
	printf("NO SE ENCONTRO REGISTROS CON ESE NOMBRE");
	getch();
	return;
	  } /* termina if */
  } /* termina for(;;) */
 } /* termina la busqueda busqueda */

 /* --BUSCA LOS REGISTROS PARA VER, MODIFICAR, ELIMINAR O VER EL LISTADO-- */

 void listar(void)
 {
 char op,resp;
 struct dato *p;
 int i = 10;
 int c = 11;

 if (nleidos == 0) {
  clrscr();
  gotoxy(23,5);
  printf("NO SE ENCUENTRAN REGISTROS GUARDADOS");
  gotoxy(80,25);
  getch();
  return;
  }

 p = inicio;
 for (;;)
 {
  clrscr();
  if (nleidos == 0)
   {
	gotoxy(18,10);
	printf(" SE HAN ELIMINADO TODOS LOS REGISTROS ");
	gotoxy(80,25);
	getch();
	inicio = p = final = NULL;
	return;
   }
  textcolor(WHITE);
  gotoxy(15,5);
  cprintf("Nombre: %s",p->nombre);
  gotoxy(15,7);
  cprintf("Apellidos: %s",p->apellido);
  gotoxy(15,9);
  cprintf("Edad: %s",p->edad);
  gotoxy(15,11);
  cprintf("Tel‚fono: %s",p->telf);
  gotoxy(15,13);
  cprintf("Direcci¢n: %s",p->direccion);
  gotoxy(30,1);
  textcolor(RED);
  cprintf("LISTADO DE REGISTROS");
  gotoxy(i + 6,20);
  textcolor(c); cprintf("(S)");
  gotoxy(i+20,20); cprintf("(A)");
  gotoxy(i+33,20); cprintf("(D)");
  gotoxy(i+46,20); cprintf("(E)");
  textcolor(15);
  gotoxy(i+10,20); cprintf("SIGUIENTE");
  gotoxy(i+24,20); cprintf("ANTERIOR");
  gotoxy(i+37,20); cprintf("ELIMINAR");
  gotoxy(i+50,20); cprintf("SALIR");
  op = toupper(getch());
  switch (op)
   {
	case 'A': p = p->ant; break;
	case 'S': p = p->sig; break;
	case 'D': {
		  for (;;)
		   {
		gotoxy(20,22);
		cprintf("Seguro que desea eliminar s/n ");
		resp = tolower(getch());
		 if (resp == 's')
		  {
		   guardado = 1;
		   elimina(p);
		   nleidos--;
		   p = p->sig;
		   break;
		  } else
		 if (resp == 'n')
		  break;
		   }
		  } break;
	case 'E': return;
   } /* fin de switch */
  } /* fin de while */
 } /* fin de listar() */

 /* --------------------MODIFICAR REGISTROS DE LA LISTA--------------------*/

 void modifica(struct dato *aux)
 {
 struct dato info;
 int tcolor1 = RED;
 int tcolor2 = WHITE;
 char op;

   fflush(stdin);
   clrscr();
   gotoxy(6,5); textcolor(tcolor1);
   cprintf("Nombre: "); textcolor(tcolor2);
   gets(info.nombre);
   gotoxy(6,6); textcolor(tcolor1);
   cprintf("Apellidos: "); textcolor(tcolor2);
   gets(info.apellido);
   gotoxy(6,7); textcolor(tcolor1);
   cprintf("Edad: "); textcolor(tcolor2);
   gets(info.edad);
   gotoxy(6,8); textcolor(tcolor1);
   cprintf("Telef¢no: "); textcolor(tcolor2);
   gets(info.telf);
   gotoxy(6,9); textcolor(tcolor1);
   cprintf("Direccion: "); textcolor(tcolor2);
   gets(info.direccion);
   for (;;)
	{
	 gotoxy(6,14);
	 cprintf("Seguro que desea realizar los cambios s/n ");
	 op = tolower(getch());
	 if (op == 's')
	  {
	   guardado = 1;
	   strcpy(aux->nombre,info.nombre);
	   strcpy(aux->apellido,info.apellido);
	   strcpy(aux->edad,info.edad);
	   strcpy(aux->telf,info.telf);
	   strcpy(aux->direccion,info.direccion);
	   return;
	  } else
	 if (op == 'n')
	  return;
	} /* fin de for(;;) */
 } /* fin de la funcion */
 /* ------------MENU PARA MANIPULAR LOS REGISTROS DEL ARCHIVO--------------*/

 void menu(char *fname)
 {
 char op;

 do {
  clrscr();
  textcolor(15);
  gotoxy(4,2);
  cprintf("   ARCHIVO: %s  ------>  Nø DE PERSONAS REGISTRADAS: %d",fname,nleidos);
  gotoxy(4,5);
  cprintf("            (1) ------------> INSERTAR REGISTROS"); gotoxy(4,7);
  cprintf("            (2) ------------> EXAMINAR REGISTROS"); gotoxy(4,9);
  cprintf("            (3) ------------> BUSCAR REGISTROS"); gotoxy(4,11);
  cprintf("            (4) ------------> GUARDAR REGISTROS "); gotoxy(4,13);
  cprintf("            (5) ------------> SALIR A MENU PRINCIPAL"); gotoxy(4,15);
  cprintf("            SELECCIONE OPCION [ ]");
  gotoxy(35,15);
  op = getch();
  switch(op) {
   case '1': agregar(); break;
   case '2': listar(); break;
   case '3': buscar(); break;
   case '4': guardar(fname); break;
		 }
  } while (op != '5');
	revisa(fname);
  libera();
 }

 /* -------------PIDE EL NOMBRE DEL ARCHIVO A CREAR O CARGAR---------------*/

 void cargar(int clave)
 {
 char fname[20];
 char *cadena;
 FILE *f;
 char eleccion;

 cadena = malloc (20 * sizeof(char));

  if (clave)
  cadena = "cargar"; else
 if (!clave)
  cadena = "crear";

 elimina_sm = 0;
 for (;;) {
  clrscr();
  textcolor(WHITE);
  gotoxy(4,5);
  printf("Introduzca el nombre del archivo a %s: ",cadena);
  gets(fname);
  strcat(fname,".txt");
  f = fopen(fname,"rb");
  if (f == NULL) /* el archivo no existe */
   {
	if (!clave) /* si el archivo no existe y se desea crear */
	 {
	  f = fopen(fname,"wb");
	  fclose(f);
	  elimina_sm = 1;
	  carga(fname);
	  menu(fname);
	  return;
	 } else
	if (clave) /* si el archivo no existe y se desea a cargar */
	 {
	  gotoxy(4,10);
	  printf("El archivo no existe, verifique el nombre . . .");
	  gotoxy(4,11);
	  printf("Presione (e) para salir o cualquier tecla para continuar");
	  eleccion = tolower(getch());
	  if (eleccion == 'e')
	   return;
	 }
   } else
  if (f != NULL) /* el archivo ya existe */
   {
	if (!clave) /* si se desea crear archivo y ya existe */
	 {
	  do {
	   gotoxy(4,10);
	   printf("El archivo ya existe, desea sobreescribirlo s/n: ");
	   gotoxy(4,11);
	   printf("Presione (e) si quiere salir");
	   eleccion = tolower(getch());
	   if (eleccion == 'e')
	return; else
	   if (eleccion == 's')
	   {
	f = fopen(fname,"wb");
	fclose(f);
	elimina_sm = 1;
	carga(fname);
	menu(fname);
	return;
	   } else
	   if (eleccion == 'n')
	break;
	 } while (eleccion != 's');
	 } else
	if (clave) /* si se desea cargar archivo y el archivo existe */
	 {
	  carga(fname);
	  menu(fname);
	  return;
	 }
   }
  } /* finaliza for (;;) */
 } /* finaliza carga() */
 void bandera()
 {
  gotoxy(23,23);
  cprintf("Pedro Alejandro Martinez Santos");
 }

 /* ----------------------------MENU PRINCIPAL-----------------------------*/

 void menu_prin(void)
 {
 char op;

 for (;;) {
  clrscr();
  gotoxy(33,5);
  textcolor(3);
  cprintf("A G E N D A");
  textcolor(13);
  elimina_sm = 0;
  gotoxy(28,8);
  textcolor (10);
  cprintf("(1) NUEVO REGISTRO"); gotoxy(28,10);
  cprintf("(2) CARGAR REGISTRO"); gotoxy(28,12);
  cprintf("(3) SALIR"); gotoxy(28,16);
  cprintf("Seleccione una opci¢n: ");
  op=tolower(getch());
  switch (op) {
   case '1': cargar(0); break;
   case '2': cargar(1); break;
   case '3': return;
   default: {
		}
  };
 }
 }

 /* ------ESCRIBE LOS REGISTROS EN EL ARCHIVO PARA SU POSTERIOR USO------- */

 void guardar(char *fname)
 {
 FILE *f;
 struct dato *p;
 int tam;

 tam = sizeof(struct dato);
 f = fopen(fname,"wb");
 p = inicio;
 for (;;)
  {
   fwrite(p,tam,1,f);
   p = p->sig;
   if (p == inicio)
	break;
  }
 fclose(f);
 clrscr();
 gotoxy(25,5);
 textcolor(WHITE);
 cprintf(" SE HAN GUARDADO LOS REGISTROS ");
 gotoxy(80,25);
 getch();
 guardado = 0;
 elimina_sm = 0;
 }

 /* --------------------------FUNCION MAIN()-------------------------------*/

 int main()
 {
 textbackground(8);
 clrscr();
 menu_prin();
 textbackground(BLACK);
 clrscr();
 return 1;
 }