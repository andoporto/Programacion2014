//checar los punteros y la funcion altas no guarda bien los datos
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include <dos.h>
#include<iostream.h>
#define _KB_F1 59
#define _KB_F2 60
#define _KB_F3 61
#define _KB_F4 62
#define _KB_F5 63
#define _KB_F6 64
#define _KB_F7 65
#define _KB_F8 66
#define _KB_F9 67

struct libro
{
  char clasifica[6];
  char titulo[40];
  char autor[30];
  char edicion[7];
  char editorial[15];
  struct libro *s;
};

FILE *archivo_gene;
FILE *i;
struct libro *inicio;
struct libro *aux;
struct libro *p;
char n[20],n2[30];
int cont=0;
int cont2=0;
int band=1;
void menu(void);
void altas(void);
void guardar(struct libro *inicio);
void busqueda_edit(void);
void busqueda_cla(void);
void busqueda_tit(void);
void busqueda_aut(void);
void busqueda_edicion(void);
void ventana(int a,int b,int c,int d);
int fnc_key(void);

void main()
{
 clrscr();
 ventana(10,3,68,20);
 gotoxy(20,1);printf("\n ESCRIBE EL NOMBRE DEL ARCHIVO: ");
 fflush(stdin);
 gets(n);
 strcat(n,".txt");
 strcpy(n2,"c:\\");
 strcat(n2,n);
 clrscr();
 printf("\n    Archivo generado:  %s",n2);
 archivo_gene=fopen(n2,"a+");
 if (archivo_gene==NULL)
 {
   printf("Imposible generar el archivo");
   getch();
   exit(0);
  }
 fclose(archivo_gene);
 menu();
}

void menu()
{
 int opc;
 do
 {
 clrscr();
 ventana(10,3,68,20);
  gotoxy(11,7); printf("    F1.-Altas");
  gotoxy(11,8); printf("    F2.-Bajas");
  gotoxy(11,9); printf("    F3.-Consultas por clasificacion");
 gotoxy(11,10); printf("    F4.-Consultas por titulo");
 gotoxy(11,11); printf("    F5.-Consultas por autor");
 gotoxy(11,12); printf("    F6.-Consultas por edicion");
 gotoxy(11,13); printf("    F7.-Consultas por editorial");
  gotoxy(11,14);printf("    F8.-Deshacer");
 gotoxy(11,15); printf("    F9.-Salir\n ");
 gotoxy(11,16); printf("    Opcion: ");
 fflush(stdin);
 opc=fnc_key();

 switch(opc)
  {
   case _KB_F1:
		   altas();
		   break;
   case _KB_F2:
		   break;
   case _KB_F3:
		   busqueda_cla();
		   break;
   case _KB_F4:
		   busqueda_tit();
		   break;
   case _KB_F5:
		   busqueda_aut();
		   break;
   case _KB_F6:
		   busqueda_edicion();
		   break;
   case _KB_F7:
		   busqueda_edit();
		   break;
   case _KB_F8:
		   break;
   case _KB_F9:
		   fclose(archivo_gene);
		   exit(0);
		   break;
  }
  }while(opc!=10);
}

void altas()
{
 clrscr();
 archivo_gene=fopen(n2,"w");
 char clasif[6];
 char tit[40];
 char au[30];
 char edi[7];
 char edito[15];
 gotoxy(5,7);printf("clasificacion: ");
 fflush(stdin);
 gets(clasif);
 gotoxy(5,9);printf("titulo: ");
 fflush(stdin);
 gets(tit);
 gotoxy(5,11);printf("autor: ");
 fflush(stdin);
 gets(au);
 gotoxy(5,13);printf("edicion: ");
 fflush(stdin);
 gets(edi);
 gotoxy(5,15);printf("editorial: ");
 fflush(stdin);
 gets(edito);
 if(cont>=1)
   {
	p=new(struct libro);
	if(band==0)
	aux->s=p;
	aux=p;
	p->s=NULL;
	cont++;
   }
 else
   {
	p=new(struct libro);
	cont++;
	aux=p;
	inicio=p;
	p->s=NULL;
   }
 strcpy(p->clasifica,clasif);
 strcpy(p->titulo,tit);
 strcpy(p->autor,au);
 strcpy(p->edicion,edi);
 strcpy(p->editorial,edito);
 guardar(inicio);
}

void guardar(struct libro *ini)
{
 if(ini!=NULL)
   {
	fprintf(archivo_gene,"%s\n",ini->clasifica);
	fprintf(archivo_gene,"%s\n",ini->titulo);
	fprintf(archivo_gene,"%s\n",ini->autor);
	fprintf(archivo_gene,"%s\n",ini->edicion);
	fprintf(archivo_gene,"%s\n",ini->editorial);
	guardar(ini->s);
   }
 else
  {
   fclose(archivo_gene);
  }
}

int fnc_key(void)
{
 int ch;
 while(1)
	  {
	  gotoxy(18,28);
	   /* espera hasta que llegue un byte cero. */
	   while((ch=getch()) != 0)
		;
	   /* Obtiene el siguiente caracter. */
	   ch=getch();
	   /* ¨Es tecla de funcion? */
	   if(ch >= _KB_F1 && ch <= _KB_F9)
	 {
	  return ch;
	 }
	  }
}

void busqueda_edit(void)
{
 clrscr();
 struct libro *compara;
 compara=inicio;
 char f[15];
 gotoxy(5,5);printf("dame la editorial: ");
 fflush(stdin);
 gets(f);
 otravez:
if (compara!=NULL)
{
 if (stricmp(f,compara->editorial)==0)
 {
  clrscr();
  gotoxy(5,5);printf(" %s",compara->clasifica);
  gotoxy(5,6);printf(" %s",compara->titulo);
  gotoxy(5,7);printf(" %s",compara->autor);
  gotoxy(5,8);printf(" %s",compara->edicion);
  gotoxy(5,9);printf(" %s",compara->editorial);
  compara=compara->s;
   getch();
  goto otravez;
 }
 else
 {
  compara=compara->s;
  goto otravez;
 }
}

}
void busqueda_cla()
{
 struct libro *compara;
 compara=inicio;
 clrscr();
 char c[6];
 gotoxy(5,5);printf("dame la clasificacion: ");
 fflush(stdin);
 gets(c);
otravez:
if (compara!=NULL)
{
 if (stricmp(c,compara->clasifica)==0)
 {
  clrscr();
  gotoxy(5,5);printf(" %s",compara->clasifica);
  gotoxy(5,6);printf(" %s",compara->titulo);
  gotoxy(5,7);printf(" %s",compara->autor);
  gotoxy(5,8);printf(" %s",compara->edicion);
  gotoxy(5,9);printf(" %s",compara->editorial);
  compara=compara->s;
  getch();
  goto otravez;
 }
 else
 {
  compara=compara->s;
  goto otravez;
 }
 }
}

void busqueda_tit()
{
 clrscr();
 struct libro *compara;
 compara=inicio;
 char d[40];
 gotoxy(5,5);printf("dame el titulo: ");
 fflush(stdin);
 gets(d);
 otravez:
if (compara!=NULL)
{
 if (stricmp(d,compara->titulo)==0)
 {
  clrscr();
  gotoxy(5,5);printf(" %s",compara->clasifica);
  gotoxy(5,6);printf(" %s",compara->titulo);
  gotoxy(5,7);printf(" %s",compara->autor);
  gotoxy(5,8);printf(" %s",compara->edicion);
  gotoxy(5,9);printf(" %s",compara->editorial);
  compara=compara->s;
  getch();
  goto otravez;
 }
 else
 {
  compara=compara->s;
  goto otravez;
 }
}
}

void busqueda_aut()
{
 clrscr();
 struct libro *compara;
 compara=inicio;
 char e[30];
 gotoxy(5,5);printf("dame el autor: ");
 fflush(stdin);
 gets(e);
 otravez:
if (compara!=NULL)
{
 if (stricmp(e,compara->autor)==0)
 {
  clrscr();
  gotoxy(5,5);printf(" %s",compara->clasifica);
  gotoxy(5,6);printf(" %s",compara->titulo);
  gotoxy(5,7);printf(" %s",compara->autor);
  gotoxy(5,8);printf(" %s",compara->edicion);
  gotoxy(5,9);printf(" %s",compara->editorial);
  compara=compara->s;
  getch();
  goto otravez;
 }
 else
 {
  compara=compara->s;
  goto otravez;
 }
}
}

void busqueda_edicion()
{
 clrscr();
 struct libro *compara;
 compara=inicio;
 char g[30];
 gotoxy(5,5);printf("dame la edicion: ");
 fflush(stdin);
 gets(g);
 otravez:
if (compara!=NULL)
{
 if (stricmp(g,compara->edicion)==0)
 {
  clrscr();
  gotoxy(5,5);printf(" %s",compara->clasifica);
  gotoxy(5,6);printf(" %s",compara->titulo);
  gotoxy(5,7);printf(" %s",compara->autor);
  gotoxy(5,8);printf(" %s",compara->edicion);
  gotoxy(5,9);printf(" %s",compara->editorial);
  compara=compara->s;
  getch();
  goto otravez;
 }
 else
 {
  compara=compara->s;
  goto otravez;
 }
}
}

void ventana(int a,int b,int c,int d)
{
char h='Ü',f='ß',g='Û';
int cont;
struct date fec;struct  time t;
textcolor(9);
for (cont=a;cont<=c;cont++)
{
	gotoxy(cont,b);cprintf("%c",f);
	gotoxy(cont,d);cprintf("%c",h);
}
for (cont=b;cont<=d;cont++)
{
	gotoxy(a,cont);cprintf("%c",g);
	gotoxy(c,cont);cprintf("%c",g);
}
textcolor(9);
gotoxy(16,21);cputs("Esquivel Aguilar Juan Alvaro");
textcolor (6);
gotoxy(13,21);cputs("1.-");
textcolor(7);
  getdate(&fec);gotoxy(10,24);
  cprintf("FECHA D/M/A: %d/%d/%d",fec.da_day,fec.da_mon,fec.da_year);
  gettime(&t);gotoxy(50,24);
  cprintf("HORA: %2d:%02d:%02d.%02d",t.ti_hour,t.ti_min,t.ti_sec);

}