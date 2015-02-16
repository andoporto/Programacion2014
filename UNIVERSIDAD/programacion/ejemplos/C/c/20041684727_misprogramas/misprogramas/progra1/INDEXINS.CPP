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

struct itsu
{
  unsigned ncontrol;
  int sem;
  char carrera[3];
  float promedio;
  char nombre[9];
  struct itsu *s;
};

FILE *archivo_gene;
FILE *i;
struct itsu *inicio;
struct itsu *aux;
struct itsu *p=NULL;
char n[20],n2[30];
int cont=0;
int band;
void menu(void);
void altas(void);
void bajas(void);
void deshacer(void);
void guardar(struct itsu *inicio);
void busqueda_ncontrol(void);
void carga_datos(void);
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
 carga_datos();
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
  gotoxy(11,9); printf("    F3.-Estadistica");
  gotoxy(11,10);printf("    F4.-Deshacer");
 gotoxy(11,10); printf("    F5.-Consultas por Nøcontrol");
 gotoxy(11,15); printf("    F6.-Salir\n ");
 gotoxy(11,16); printf("    Opcion: ");
 fflush(stdin);
 opc=fnc_key();

 switch(opc)
  {
   case _KB_F1:
		   altas();
		   break;
   case _KB_F2:
		   bajas();
		   break;
   case _KB_F3:
		   estadistica();
		   break;
   case _KB_F4:
		   busqueda_ncontrol();
		   break;
   case _KB_F5:
		   deshacer();
		   break;
   case _KB_F6:
		   fclose(archivo_gene);
		   exit(0);
		   break;
  }
  }while(opc!=10);
}

void carga_datos(void)
{
 unsigned ncontrol;
 int semestre;
 char carrera[3];
 float promedio;
 char nombre[9];
 cont=0;
 int band;
  repetir:
while(!feof(archivo_gene))
 {
  while(!feof(archivo_gene))
  {
  fgets(clasif,6,archivo_gene);
  fgets(tit,40,archivo_gene);
  fgets(au,30,archivo_gene);
  fgets(edi,7,archivo_gene);
  fgets(edito,15,archivo_gene);

 if(cont>=1)
   {
	p=new(struct itsu);
	aux->s=p;
	aux=p;
	p->s=NULL;
	cont++;
	goto repetir;
   }
 else
   {
	p=new(struct itsu);
	cont++;
	aux=p;
	inicio=p;
	p->s=NULL;
	band=0;
	goto repetir;
   }
  }
 }
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
	p=new(struct itsu);
	if(band==0)
	aux->s=p;
	aux=p;
	p->s=NULL;
	cont++;
   }
 else
   {
	p=new(struct itsu);
	cont++;
	if(band==0)
	  {
	   aux->s=p;
	  }
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
void bajas()
{
 char z[20];
 printf("Dame el nombre la clasificacion ");
 gets(z);

 printf("Esta opcion no esta habilitada ");
}
void deshacer()
{

}

void guardar(struct itsu *ini)
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
 struct itsu *compara;
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
 struct itsu *compara;
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
 struct itsu *compara;
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
 struct itsu *compara;
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
 struct itsu *compara;
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