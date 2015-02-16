#include<string.h>
#include<stdio.h>
#include<conio.h>
typedef struct
{
char ncontrol[50];
char clave[50];
char fechp[50];
char feche[50];
char status;
}registrop;
typedef struct
{
char ncontrol[50];
char nombre [50];
char direccion[50];
char carrera[50];
char telefono[50];
char status;
}registro;
typedef struct
{
char clave[50];
char titulo[50];
char autor[50];
char editorial[50];
char isbn[50];
char clas[50];
int cta;
}registrol;

int cursor();
int cursor1();
void altalumno();
void altalib();
void prestamo();
void bajas();
void bajasl();
void bajasp();
void modal ();
void modlib ();
void modp();
void consulta();
void consultal();
void consultap();
void reporte();
void reportel();
void reportep();
int cont=1,conta=1,n,a,b;
void msg(int a, int b, int c, int d, int e,int f);
void submenus();
void msg1(int a, int b, int c,int d);
void main()
{
conta=1;
clrscr();
int i,j;
	for(j=1;j<=80; j++)
	{
	for(i=1;i<=25;i++)
	{
		gotoxy(j,i);
		textbackground(12);
		cprintf(" ");
	}
	}
	textcolor(15);
	gotoxy(33,3);
	cprintf("Menu principal");
do{
switch(cont)
{
	case 1: msg(10,15,15,15,15,15);
					break;
	case 2: msg(15,10,15,15,15,15);
					break;
	case 3: msg(15,15,10,15,15,15);
					break;
	case 4: msg(15,15,15,10,15,15);
					break;
	case 5: msg(15,15,15,15,10,15);
					break;
	case 6: msg(15,15,15,15,15,10);
		break;
	}
cont=cursor();
}while(cont<7);
}
int cursor()
{
char x;
x=getche();

	if(!x){
	x=getche();
	}
	switch(x){
	case 72: if(cont==1)
			cont=6;
		else
			cont=cont-1;
	break;
	case 80: if(cont==6)
			cont=1;
		else
			cont=cont+1;
	break;
	case 13:if(cont==1||cont==2||cont==3||cont==4||cont==5)
					 {
							conta=1;
							submenus();
					 }
					if(cont==6)
						cont=7;
	break;
	}
	return cont;
	}

void msg(int a,int b,int c,int d,int e,int f)
{
clrscr();
		textcolor(15);
		gotoxy(33,3);
		cprintf("Menu principal");
		textcolor(a);
		gotoxy(33,8);
		cprintf("    Altas     ");
		gotoxy(33,9);
		textcolor(b);
		cprintf("    Bajas     ");
		gotoxy(33,10);
		textcolor(c);
		cprintf("Modificaciones");
		gotoxy(33,11);
		textcolor(d);
		cprintf("  Consultas   ");
		gotoxy(33,12);
		textcolor(e);
		cprintf("  Reportes     ");
		gotoxy(33,13);
		textcolor(f);
		cprintf("   Salir ");
}
void submenus()
{
if(cont==1||cont==2||cont==3||cont==4||cont==5)
 n=5; a=4;
do{
switch(conta)
{
	case 1: msg1(10,15,15,15);
					break;
	case 2: msg1(15,10,15,15);
					break;
	case 3: msg1(15,15,10,15);
					break;
	case 4: msg1(15,15,15,10);
					break;
	}
conta=cursor1();
}while(conta<n);
}

int cursor1()
{
if(cont==1||cont==2||cont==3||cont==4||cont==5)
n=5;
char x;
x=getche();
	if(!x){
	x=getche();
	}
	switch(x){
	case 72: if(conta==1)
			conta=n-1;
		else
			conta=conta-1;
	break;
	case 80: if(conta==n-1)
			conta=1;
		else
			conta=conta+1;
	break;
	case 13:if(cont==1)
					{
					if(conta==1)
						altalumno();
					if(conta==2)
						altalib();
					if(conta==3)
						prestamo();
					 }
				 if(cont==2)
				 {
					if(conta==1)
						bajas();
					if(conta==2)
						bajasl();
					if (conta==3)
						bajasp();
					}
				 if (cont==3)
					{
					if (conta==1)
						 modal ();
					if (conta==2)
						 modlib ();
					if (conta==3)
						 modp ();
					 }
				 if(cont==4)
				 {
				 if(conta==1)
					consulta();
				 if(conta==2)
					consultal();
				 if(conta==3)
					consultap();
				 }
				 if(cont==5)
				 {
					if(conta==1)
						reporte();
					if(conta==2)
						reportel();
					if(conta==3)
						reportep();
					}
				 if(cont==1||cont==2||cont==3||cont==4||cont==5)
					if(conta==n-1)
						conta=n;
	break;
	}
	return conta;
	}

void msg1(int a, int b, int c, int d)
{
clrscr();
switch(cont)
{
case 1:	textcolor(15);
	gotoxy(38,3);
	cprintf("ALTAS"); break;
case 2: textcolor(15);
	gotoxy(38,3);
	cprintf("BAJAS"); break;
case 3: textcolor(15);
	gotoxy(33,3);
	cprintf("MODIFICACIONES"); break;
case 4: textcolor(15);
	gotoxy(35,3);
	cprintf("CONSULTAS"); break;
case 5: textcolor(15);
	gotoxy(35,3);
	cprintf("REPORTES"); break;
}
	textcolor(a);
	gotoxy(34,8);
	cprintf("  A l u m n o s ");
	textcolor(b);
	gotoxy(34,9);
	cprintf("   L i b r o s  ");
	textcolor(c);
	gotoxy(34,10);
	cprintf("P r e s t a m o s");
	textcolor(d);
	gotoxy(34,11);
	cprintf(" R e g r e s a r");
}

void altalumno()
{
	int x;
	FILE *arch,*archa;
 registro alumno,alumno1;
 clrscr ();
 arch=fopen ("c:\\alumnos.001","ab");
 archa=fopen("c:\\alumnos.001","rb");
 if (arch==NULL||archa==NULL)
		printf ("Error de apertura ");
 else
	{
	fseek(archa,SEEK_SET,0);
	fflush(stdin);
	printf("Numero de control: "); gets(alumno.ncontrol);
	fflush(stdin);
	x=1;
	while(!feof(archa))
	{
	fread (&alumno1,sizeof(alumno1),1,archa);
	x=strcmp(alumno1.ncontrol,alumno.ncontrol);
	if(x==0)
		break;
 }
	if(x!=0)
	{
	printf ("Nombre completo:  ");gets (alumno.nombre);
	fflush (stdin);
	printf ("Direccion: ");gets(alumno.direccion);
	fflush (stdin);
	printf ("Carrera: "); gets(alumno.carrera);
	fflush (stdin);
	printf("Telefono: "); gets(alumno.telefono);
	fflush(stdin);
	alumno.status='A';
	fflush(stdin);
	fwrite (&alumno,sizeof (registro),1,arch);
	}
	else
	 printf("El registro ya existe");
	 getch();
	}
	 fclose(archa);
	 fclose (arch);
}


void altalib()
{
int x;
	FILE *arch,*archa;
 registrol libro,libro1;
 clrscr ();
 arch=fopen ("c:\\libros.001","ab");
 archa=fopen("c:\\libros.001","rb");
 if (arch==NULL||archa==NULL)
		printf ("Error de apertura ");
 else
	{
	fseek(archa,SEEK_SET,0);
	printf("Clave: "); gets(libro.clave);
	fflush(stdin);
	x=1;
	while(!feof(archa))
	{
	fread (&libro1,sizeof(libro1),1,archa);
	x=strcmp(libro1.clave,libro.clave);
	if(x==0)
		break;
 }
	if(x!=0)
	{
	printf ("Titulo:  ");gets (libro.titulo);
	fflush (stdin);
	printf ("Autor: ");gets(libro.autor);
	fflush (stdin);
	printf ("Editorial: "); gets(libro.editorial);
	fflush (stdin);
	printf("ISBN: "); gets(libro.isbn);
	fflush(stdin);
	printf("Clasificacion: "); gets(libro.clas);
	fflush(stdin);
	printf("Existencia: "); scanf("%d",&libro.cta);
	fflush(stdin);
	fwrite (&libro,sizeof (registrol),1,arch);
	}
	else
	{
	 printf("El registro ya existe");
	 getch();
	}
	}
	 fclose(archa);
	 fclose (arch);
}
void prestamo()
{
int x,y,ban=0;
registro alumno;
registrol libro;
registrop prestamo;
char nc[50],clave[50];
 FILE *arch,*archa,*archl,*arch1;
	clrscr ();
 archa=fopen("c:\\alumnos.001","rb");
 archl=fopen("c:\\libros.001","rb");
 arch=fopen ("c:\\prestamo.001","ab");
 if (arch==NULL||archa==NULL||archl==NULL)
		printf ("Error de apertura ");
 else
 {
printf("Numero de control: "); gets(prestamo.ncontrol);
	fflush(stdin);
	fseek(archl,SEEK_SET,0);
 fseek(archa,SEEK_SET,0);
	x=1; y=1;
 while(!feof(archa))
 {
 fread (&alumno,sizeof(alumno),1,archa);
 x=strcmp(prestamo.ncontrol,alumno.ncontrol);
 if(x==0)
	break;
 }
 if(x!=0)
 {
	printf("El registro del alumno no existe");
	getch();
	goto a;
 }
 printf ("Clave:  ");gets (prestamo.clave);
 fflush (stdin);
 while(!feof(archl))
 {
	fread (&libro,sizeof(libro),1,archl);
	 y=strcmp(prestamo.clave,libro.clave);
	 if(y==0)
	 {
		if(libro.cta==0)
		{
			printf("No hay mas libros imposible prestar");
			getch();
			goto salir;
		}
		break;
		}
 }
 if(y!=0)
 {
	printf("El registro del libro no existe");
	getch();
	goto b;
 }
	 if(x==0&&y==0)
 {
	ban=1;
	printf ("fecha de prestamo: ");gets(prestamo.fechp);
	fflush (stdin);
	printf ("Fecha de entrega: "); gets(prestamo.feche);
	fflush (stdin);
	prestamo.status='P';
	fflush(stdin);
	fwrite (&prestamo,sizeof (registrop),1,arch);
	}
	}
	a:
	b:
	salir:
	 fclose(archa);
	 fclose(archl);
	 fclose (arch);
/*para el descuento en libros*/
if(ban==1)
{
int a=0;
x=1;
			clrscr ();
			arch=fopen ("c:\\libros.001","rb");
			arch1=fopen ("c:\\libros1.001","ab");
 if (arch==NULL)
		printf ("Error de apertura ");
 else
	{
		 fseek (arch,SEEK_SET,0);
		 fread (&libro,sizeof (libro),1,arch);
		 while (!feof (arch))
					{
					x=strcmp (prestamo.clave,libro.clave);
					if (x==0)
						 {
							a=1;
							libro.cta=(libro.cta)-1;
							fwrite(&libro,sizeof(libro),1,arch1);
							}
					if(x!=0)
					{
						a=1;
						fwrite(&libro,sizeof(libro),1,arch1);
					}
				 fread (&libro,sizeof (libro),1,arch);
					}
					}
fclose (arch);
fclose (arch1);
if (a)
{
remove ("c:\\libros.001");
rename ("c:\\libros1.001","c:\\libros.001");
}
}
}



void bajas()
{
registrop prestamo;
registro alumno;
int a=0,com,ban=1,x,salir=0;
char Aux[50];
char Op;
 FILE *arch,*arch1,*archp;
			clrscr ();
			archp=fopen ("c:\\prestamos.001","rb");
			arch=fopen ("c:\\alumnos.001","rb");
			arch1=fopen ("c:\\alumnos1.001","ab");

 if (arch==NULL)
		printf ("Error de apertura ");
 else

		printf ("Numero de Control: ");fflush (stdin);gets (Aux);
		fseek (arch,SEEK_SET,0);
		 while (!feof (archp))
					{
					fread (&prestamo,sizeof (prestamo),1,archp);
					x=strcmp (Aux,prestamo.ncontrol);
					if (x==0)
						 {
						 if(prestamo.status=='E')
							 break;
						 else
						 {
						 printf ("Alumno con PRESTAMO PENDIENTE!!");
						 salir=1;
						 getch ();
						 goto e;
						 }
						 }
					}
		while(!feof(arch))
		{
	if (!ban)
		break;
	fread (&alumno,sizeof(alumno),1,arch);
	com=strcmp (Aux,alumno.ncontrol);
	if (com==0)
		 {
		 printf ("Nombre: %s\n",alumno.nombre);
		 printf ("Direccion %s\n",alumno.direccion);
		 printf ("Carrera: %s\n",alumno.carrera);
		 printf ("Telefono: %s\n",alumno.telefono);
		 printf ("Quiere Eliminar el Registro(Deberas deberas)? \n ");
		 printf ("      1.Si   2.No \n");scanf ("%c",&Op);
		 if (Op=='1')
		{
		fseek (arch,SEEK_SET,0);
		fread (&alumno,sizeof(alumno),1,arch);
		while(!feof(arch))
		{

		com=strcmp (Aux,alumno.ncontrol);
		if (com!=0)
		{
			 a=1;
			 fwrite (&alumno,sizeof (registro),1,arch1);
		}
		fread (&alumno,sizeof(alumno),1,arch);
		ban=0;
		}
		}
		if (Op=='2')
			 {
			 ban=0;
			 break;
			 }
	}
}
fclose (arch);
fclose (arch1);
if(com!=0&&Op!='2')
{
	printf("Registro inexistente");
	getch();
}
if (a)
{
remove ("c:\\alumnos.001");
rename ("c:\\alumnos1.001","c:\\alumnos.001");
}
e:
if(salir==1)
{
fclose (arch);
fclose (arch1);
}
}
void bajasl()
{
registrop prestamo;
registrol libro;
int a=0,com,ban=1,x,salir=0;
char Aux[50];
char Op;
 FILE *arch,*arch1,*archp;
			clrscr ();
			archp=fopen ("c:\\prestamos.001","rb");
			arch=fopen ("c:\\libros.001","rb");
			arch1=fopen ("c:\\libros1.001","ab");

 if (arch==NULL)
		printf ("Error de apertura ");
 else

		printf ("Clave del Libro: ");fflush (stdin);gets (Aux);
		fseek (arch,SEEK_SET,0);
		 while (!feof (archp))
					{
					fread (&prestamo,sizeof (prestamo),1,archp);
					x=strcmp (Aux,prestamo.clave);
					if (x==0)
						 {
						 if(prestamo.status=='E')
						 {
							 break;
						 }
						 else
						 {
						 printf ("LIBROS CON PRESTAMO PENDIENTE!!");
						 salir=1;
						 getch ();
						 goto e;
						 }
						 }
					}
		while(!feof (arch))
		{
	if (!ban)
		break;
	fread (&libro,sizeof(libro),1,arch);
	com=strcmp (Aux,libro.clave);
	if (com==0)
		 {
		 printf("Titulo: %s\n",libro.titulo);
		 printf("Autor: %s\n",libro.autor);
		 printf("Editorial: %s\n",libro.editorial);
		 printf("ISBN: %s\n",libro.isbn);
		 printf("Clasificacion: %s\n",libro.clas);
		 printf("Existencia: %d\n",libro.cta);
		 printf ("Quiere Eliminar el Registro(Deberas deberas)? \n ");
		 printf ("      1.Si   2.No \n");scanf ("%c",&Op);
		 if (Op=='1')
		{
		fseek (arch,SEEK_SET,0);
		fread (&libro,sizeof(libro),1,arch);
		while(!feof(arch))
		{

		com=strcmp (Aux,libro.clave);
		if (com!=0)
		{
			 a=1;
			 fwrite (&libro,sizeof (libro),1,arch1);
		}
		fread (&libro,sizeof(libro),1,arch);
		ban=0;
		}
		if (Op=='2')
			 break;
		 }
	}
}
fclose (arch);
fclose (arch1);
if((com!=0)&&(Op!='2'))
{
printf("Registro de libro inexistente");
getch();
}
if (a)
{
remove ("c:\\libros.001");
rename ("c:\\libros1.001","c:\\libros.001");
}
e:
if(salir==1)
{
fclose (arch);
fclose (arch1);
}
}
void bajasp ()
{
registrop prestamo;
registrol libro;
int a=0,com,x,y,ban=0,ban1=0,ban2=0;
char Aux[50],clave[50];
char Op;
 FILE *arch,*archp,*arch1;
			clrscr ();
			archp=fopen ("c:\\prestamo.001","rb");
			arch=fopen ("c:\\presta.001","ab");

if (arch==NULL)
		printf ("Error de apertura ");
 else
		printf ("Numero de Control ");fflush (stdin);gets (Aux);
		printf ("Clave del Libro ");fflush (stdin);gets (clave);
		fseek (archp,SEEK_SET,0);
		fread (&prestamo,sizeof (prestamo),1,archp);
		while (!feof (archp))
					{
					x=strcmp (Aux,prestamo.ncontrol);
					y=strcmp (clave,prestamo.clave);
					if(x==0)
						ban1=1;
					if(y==0)
						ban2=1;
					if ((x==0)&&(y==0))
						 {
							printf ("Libro Regresado? ");
							printf (" 1.Si     2.No   ");
							scanf ("%c",&Op);
							if (Op=='1')
									{

									x=1;y=1;
									fseek (archp,SEEK_SET,0);
									fread (&prestamo,sizeof (prestamo),1,archp);
									while (!feof (archp))
												{

												x=strcmp (Aux,prestamo.ncontrol);
												y=strcmp (clave,prestamo.clave);
												if ((x==0&&y!=0)||(x!=0&&y==0)||(x!=0&&y!=0))
													 fwrite (&prestamo,sizeof (prestamo),1,arch);
												if(x==0&&y==0)
												{
													ban=1;
													prestamo.status='E';
													a=1;
													fwrite (&prestamo,sizeof (prestamo),1,arch);
												 }
												fread (&prestamo,sizeof (prestamo),1,archp);
												}
												}
						 if (Op=='2')
									break;
						}
					fread (&prestamo,sizeof (prestamo),1,archp);
}
if(x!=0&&ban1==0||y!=0&&ban2==0)
{
	printf("\nRegistro de Prestamo inexistente");
	getch();
}
fclose (arch);
fclose (archp);
if (a)
{
remove ("c:\\prestamo.001");
rename ("c:\\presta.001","c:\\prestamo.001");
}
/*para el aumento en libros*/
if(ban==1)
{
int a=0;
x=1;
			clrscr ();
			arch=fopen ("c:\\libros.001","rb");
			arch1=fopen ("c:\\libros1.001","ab");
 if (arch==NULL)
		printf ("Error de apertura ");
 else
	{
		 fseek (arch,SEEK_SET,0);
		 fread (&libro,sizeof (libro),1,arch);
		 while (!feof (arch))
					{
					x=strcmp (prestamo.clave,libro.clave);
					if (x==0)
						 {
							a=1;
							libro.cta=(libro.cta)+1;
							fwrite(&libro,sizeof(libro),1,arch1);
							}
					if(x!=0)
					{
						a=1;
						fwrite(&libro,sizeof(libro),1,arch1);
					}
				 fread (&libro,sizeof (libro),1,arch);
					}
					}
fclose (arch);
fclose (arch1);
if (a)
{
remove ("c:\\libros.001");
rename ("c:\\libros1.001","c:\\libros.001");
}
}
}


void modal ()
{
registro alumno;
registrop prestamo;
int a=0,com,x,y,z=1,salir=0,w=0;
char Aux[50],clave[50];
char Op;
 FILE *arch,*archp,*archz;
			clrscr ();
			archp=fopen ("c:\\alumnos.001","rb");
			arch=fopen ("c:\\auxiliar.001","ab");
			archz=fopen ("c:\\prestamos.001","rb");
if (arch==NULL)
		printf ("Error de apertura ");
 else
		printf ("Numero de Control ");fflush (stdin);gets (Aux);
		fseek (archz,SEEK_SET,0);
		fread (&prestamo,sizeof (prestamo),1,archz);
		while (!feof (archz))
					{
					z=strcmp (Aux,prestamo.ncontrol);
					if (z==0)
						 {
						 if(prestamo.status=='E')
						 {
							break;
						 }
						 else
						 {
						 printf ("No se Puede Modificar el Registro!!\n");
						 printf ("Alumno con Libros Prestados !!! ");
						 salir=1;
						 getch ();
						 goto k;
						 }
						 }
					fread (&prestamo,sizeof (prestamo),1,archz);
					}
		fseek (archp,SEEK_SET,0);
		fread (&alumno,sizeof (alumno),1,archp);
		while (!feof (archp))
					{
					x=strcmp (Aux,alumno.ncontrol);
					if (x==0)
						 {
							printf ("Cambiar Contenido del Registro? \n ");
							printf (" 1.Si     2.No   ");
							scanf ("%c",&Op);
							if (Op=='1')
									{
									x=1;
									fseek (archp,SEEK_SET,0);
									fread (&alumno,sizeof (alumno),1,archp);
									while (!feof (archp))
												{
												x=strcmp (Aux,alumno.ncontrol);
												if (x!=0)
													 fwrite (&alumno,sizeof (alumno),1,arch);
												if(x==0)
												{
													w=1;
													printf ("Nombre Completo: ");fflush (stdin);
													gets (alumno.nombre);
													printf ("Direccion: ");fflush (stdin);
													gets (alumno.direccion);
													printf ("Carrera: ");fflush (stdin);
													gets (alumno.carrera);
													printf ("Telefono: ");fflush (stdin);
													gets (alumno.telefono);
													alumno.status='A';
													a=1;
													fwrite (&alumno,sizeof (alumno),1,arch);
												 }
												fread (&alumno,sizeof (alumno),1,archp);
												}
												}
						 if (Op=='2')
									break;
						}
					fread (&alumno,sizeof (alumno),1,archp);
}
fclose (arch);
fclose (archp);
fclose(archz);
if(x!=0&&w==0)
 {
	printf("Registro de alumno inexistente");
	getch();
	}
if (a)
{
remove ("c:\\alumnos.001");
rename ("c:\\auxiliar.001","c:\\alumnos.001");
}
k:
if(salir==1)
{
fclose (arch);
fclose (archp);
fclose(archz);
}
}
void modlib ()
{
registrol libro;
registrop prestamo;
int a=0,com,x,y,z=1,salir=0,w=0;
char Aux[50],clave[50],caso='2';
char Op;
 FILE *arch,*archp,*archx;
			clrscr ();
			archp=fopen ("c:\\libros.001","rb");
			arch=fopen ("c:\\auxiliar.001","ab");
			archx=fopen ("c:\\prestamo.001","rb");
if (arch==NULL)
		printf ("Error de apertura ");
 else
		printf ("Clave del Libro: ");fflush (stdin);gets (Aux);
		fseek (archx,SEEK_SET,0);
		fread (&prestamo,sizeof (prestamo),1,archx);
		while (!feof (archx))
					{
					z=strcmp (Aux,prestamo.clave);
					if (z==0)
						 {
						 if(prestamo.status=='E')
							break;
						 else
						 {
						 printf ("No se puede Modificar,Libro Prestado");
						 printf("\n Solo puedes modificar la existencia de libros: ");
						 printf("1. si  2. no ");  scanf("%c",&caso);
						 if(caso=='1')
							break;
						 else
						 {
						 salir=1;
						 getch ();
						 goto x;
						 }
						 }
						 }
					fread (&prestamo,sizeof (prestamo),1,archx);
					}

		fseek (archp,SEEK_SET,0);
		fread (&libro,sizeof (libro),1,archp);
		while (!feof (archp))
					{
					x=strcmp (Aux,libro.clave);
					if (x==0)
						 {
							fflush(stdin);
							printf ("Cambiar Contenido del Registro? \n ");
							printf (" 1.Si     2.No   ");
							scanf ("%c",&Op);
							if (Op=='1')
									{
									x=1;
									fseek (archp,SEEK_SET,0);
									fread (&libro,sizeof (libro),1,archp);
									while (!feof (archp))
												{
												x=strcmp (Aux,libro.clave);
												if (x!=0)
													 fwrite (&libro,sizeof (libro),1,arch);
												if(x==0)
												{
													w=1;
													if(caso=='1')
													{
														fflush(stdin);
														printf ("Existencia: ");
														scanf ("%d",&libro.cta);
													if(libro.cta<0)
													{
														printf("No puedes hacer eso");
														goto l;
													}
													}
													else
													{
													fflush(stdin);
													printf ("Titulo: ");fflush (stdin);
													gets (libro.titulo);
													printf ("Autor: ");fflush (stdin);
													gets (libro.autor);
													printf ("Editorial: ");fflush (stdin);
													gets (libro.editorial);
													printf ("Clasificacion: ");fflush (stdin);
													gets (libro.clas);
													printf ("ISBN: ");fflush (stdin);
													gets (libro.isbn);
													printf ("Existencia: ");
													scanf ("%d",&libro.cta);
													}
													a=1;
													fwrite (&libro,sizeof (libro),1,arch);
												 }
												fread (&libro,sizeof (libro),1,archp);
												}
												}
						 if (Op=='2')
									break;
						}
					fread (&libro,sizeof (libro),1,archp);

}
l:
if(x!=0&&w==0)
{
printf("Registro de libro inexistente");
getch();
}
fclose(archx);
fclose (arch);
fclose (archp);
if (a)
{
remove ("c:\\libros.001");
rename ("c:\\auxiliar.001","c:\\libros.001");
}
x:
if(salir==1)
{
fclose(archx);
fclose (arch);
fclose (archp);
}
}
void modp ()
{
registrop prestamo;

int a=0,com,x,y;
char Aux[50],clave[50];
char Op;
 FILE *arch,*archp;
			clrscr ();
			archp=fopen ("c:\\prestamo.001","rb");
			arch=fopen ("c:\\presta.001","ab");

if (arch==NULL)
		printf ("Error de apertura ");
 else
 {
		printf ("Numero de Control: ");fflush (stdin);gets (Aux);
		printf ("Clave del Libro: ");fflush (stdin);gets (clave);
		fseek (archp,SEEK_SET,0);
		fread (&prestamo,sizeof (prestamo),1,archp);
		while (!feof (archp))
					{
					x=strcmp (Aux,prestamo.ncontrol);
					y=strcmp (clave,prestamo.clave);

					if ((x==0)&&(y==0))
						 {
							printf ("Cambiar Fecha de Entrega? \n ");
							printf (" 1.Si     2.No   ");
							scanf ("%c",&Op);
							if (Op=='1')
									{

									x=1;y=1;
									fseek (archp,SEEK_SET,0);
									fread (&prestamo,sizeof (prestamo),1,archp);
									while (!feof (archp))
												{

												x=strcmp (Aux,prestamo.ncontrol);
												y=strcmp (clave,prestamo.clave);
												if ((x==0&&y!=0)||(x!=0&&y==0)||(x!=0&&y!=0))
													 fwrite (&prestamo,sizeof (prestamo),1,arch);
												if(x==0&&y==0)
												{
													printf ("Nueva Fecha? \n");fflush (stdin);
													gets (prestamo.feche);
													a=1;
													fwrite (&prestamo,sizeof (prestamo),1,arch);
												 }
												fread (&prestamo,sizeof (prestamo),1,archp);
												}
												}
						 if (Op=='2')
									goto g;
						}
					fread (&prestamo,sizeof (prestamo),1,archp);
}
if(x!=0||y!=0)
{
	printf("Registro de prestamo inexistente");
	getch();
}
}
fclose (arch);
fclose (archp);
if (a)
{
remove ("c:\\prestamo.001");
rename ("c:\\presta.001","c:\\prestamo.001");
}
g:
}
void reporte()
{
registro alumno;
 FILE *arch;
	clrscr ();
 arch=fopen ("c:\\alumnos.001","rb");
 if (arch==NULL)
		printf ("Error de apertura ");
 else
 {
 fread (&alumno,sizeof(alumno),1,arch);
 while(!feof(arch))
 {
 clrscr();
 gotoxy(33,3);
 cprintf("Datos de Alumnos");
 printf ("\nNumero de control: %s\n",alumno.ncontrol);
 printf("Nombre: %s\n",alumno.nombre);
 printf("Direccion: %s\n",alumno.direccion);
 printf("Carrera: %s\n",alumno.carrera);
 printf("Telefono: %s\n",alumno.telefono);
 printf("Status: %c",alumno.status);
 fread (&alumno,sizeof(alumno),1,arch);
 getch();
 }
 }
fclose (arch);
}
void reportel()
{
registrol libro;
 FILE *arch;
	clrscr ();
 arch=fopen ("c:\\libros.001","rb");
 if (arch==NULL)
		printf ("Error de apertura ");
 else
 {
 fread (&libro,sizeof(libro),1,arch);
 while(!feof(arch))
 {
 clrscr();
 gotoxy(33,3);
 cprintf("Datos de Libros");
 printf ("\nClave: %s\n",libro.clave);
 printf("Titulo: %s\n",libro.titulo);
 printf("Autor: %s\n",libro.autor);
 printf("Editorial: %s\n",libro.editorial);
 printf("ISBN: %s\n",libro.isbn);
 printf("Clasificacion: %s\n",libro.clas);
 printf("Existencia: %d\n",libro.cta);
 fread (&libro,sizeof(libro),1,arch);
 getch();
 }
 }
fclose (arch);
}
void reportep()
{
int x,y;
registro alumno;
registrol libro;
registrop prestamo;
 FILE *arch,*archa,*archl;
	clrscr ();
 archa=fopen("c:\\alumnos.001","rb");
 archl=fopen("c:\\libros.001","rb");
 arch=fopen ("c:\\prestamo.001","rb");
 if (arch==NULL||archa==NULL||archl==NULL)
		printf ("Error de apertura ");
 else
 {
fseek(arch,SEEK_SET,0);
fread (&prestamo,sizeof(prestamo),1,arch);
while(!feof(arch))
 {
 fseek(archl,SEEK_SET,0);
 fseek(archa,SEEK_SET,0);
 x=1; y=1;
 while(!feof(archa))
 {
 fread (&alumno,sizeof(alumno),1,archa);
 x=strcmp(prestamo.ncontrol,alumno.ncontrol);
if(x==0)
break;
}
 while(!feof(archl))
 {
	 fread (&libro,sizeof(libro),1,archl);
	 y=strcmp(prestamo.clave,libro.clave);
	 if(y==0)
	 break;
 }
	 if(x==0&&y==0)
 {

 clrscr();
 gotoxy(33,3);
 cprintf("Datos de Prestamos");
 printf ("\nNumero de Control: %s\n",prestamo.ncontrol);
 printf("Clave del libro: %s\n\n",prestamo.clave);
 printf("Nombre: %s\n",alumno.nombre);
 printf("Carrera: %s\n",alumno.carrera);
 printf("Direccion: %s\n",alumno.direccion);
 printf("Telefono: %s\n\n",alumno.telefono);
 printf("Titulo: %s\n",libro.titulo);
 printf("Autor: %s\n",libro.autor);
 printf("Clasificacion: %s\n",libro.clas);
 printf("Fecha de Prestamo: %s\n",prestamo.fechp);
 printf("Fecha de Entrega: %s\n",prestamo.feche);
 printf("Status: %c",prestamo.status);
 fread (&prestamo,sizeof(prestamo),1,arch);
 fread (&alumno,sizeof(alumno),1,archa);
 fread (&libro,sizeof(libro),1,archl);
 getch();
 }
 else
 {
 fread(&prestamo,sizeof(prestamo),1,arch);
 if(feof(arch))
 if (y!=0&&x!=0)
 {
	printf ("No Hay Ningun Registro de Prestamo Hasta Ahorita!!!!!");
	getch ();
	break;
 }
 }
 }
 }
fclose(archa);
fclose(archl);
fclose (arch);
}
void consulta()
{
int x;
	FILE *arch;
 registro alumno,alumno1;
 clrscr ();
 arch=fopen("c:\\alumnos.001","rb");
 if (arch==NULL)
		printf ("Error de apertura ");
 else
	{
	fseek(arch,SEEK_SET,0);
	fflush(stdin);
	printf("Numero de control: "); gets(alumno.ncontrol);
	fflush(stdin);
	x=1;
	while(!feof(arch))
	{
	fread(&alumno1,sizeof(alumno1),1,arch);
	x=strcmp(alumno1.ncontrol,alumno.ncontrol);
	if(x==0)
	{
	printf("Nombre: %s\n",alumno1.nombre);
 printf("Direccion: %s\n",alumno1.direccion);
 printf("Carrera: %s\n",alumno1.carrera);
 printf("Telefono: %s\n",alumno1.telefono);
 printf("Status: %c",alumno1.status);
 fread (&alumno1,sizeof(alumno1),1,arch);
 getch();
 break;
 }
 }
 if(x!=0)
 {
	printf("El registro del alumno no existe");
	getch();
 }
 }
fclose (arch);
}
void consultal()
{
int x;
	FILE *arch;
 registrol libro,libro1;
 clrscr ();
 arch=fopen("c:\\libros.001","rb");
 if (arch==NULL)
		printf ("Error de apertura ");
 else
	{
	gotoxy(28,3);
	cprintf("Datos del libro solicitado");
	fseek(arch,SEEK_SET,0);
	fflush(stdin);
	printf("\n\nClave: "); gets(libro.clave);
	fflush(stdin);
	x=1;
	while(!feof(arch))
	{
	fread(&libro1,sizeof(libro1),1,arch);
	x=strcmp(libro1.clave,libro.clave);
	if(x==0)
	{
	printf("Titulo: %s\n",libro1.titulo);
 printf("Autor: %s\n",libro1.autor);
 printf("Editorial: %s\n",libro1.editorial);
 printf("ISBN: %s\n",libro1.isbn);
 printf("Clasificacion: %s\n",libro1.clas);
 printf("Existencia: %d\n",libro1.cta);
 fread (&libro1,sizeof(libro1),1,arch);
 getch();
 break;
 }
 }
 if(x!=0)
 {
	printf("El registro del libro no existe");
 getch();
 }
 }
fclose (arch);
}
void consultap()
{
int x,y,salir=0;
registro alumno;
registrol libro;
registrop prestamo,prestamo1;
 FILE *arch,*archa,*archl;
	clrscr ();
 archa=fopen("c:\\alumnos.001","rb");
 archl=fopen("c:\\libros.001","rb");
 arch=fopen ("c:\\prestamo.001","rb");
 if (arch==NULL||archa==NULL||archl==NULL)
		printf ("Error de apertura ");
 else
 {
 x=1; y=1;
 fflush(stdin);
 printf("Clave del libro: "); gets(prestamo1.clave);
 fflush(stdin);
 printf("Numero de control del alumno: "); gets(prestamo1.ncontrol);

 while(!feof(arch))
 {
	 fread (&prestamo,sizeof(prestamo),1,arch);
	 y=strcmp(prestamo.clave,prestamo1.clave);
	 x=strcmp(prestamo.ncontrol,prestamo1.ncontrol);
 if(y==0&&x==0)
		break;
 else
	{
	y=1; x=1;
	continue;
 }

 }
	if(y!=0||x!=0)
	{
		printf("El registro del prestamo no existe");
		getch();
		goto c;
	}
	 if(x==0&&y==0)
 {
		x=1; y=1;
		fread(&alumno,sizeof(alumno),1,archa);
		while(!feof(archa))
		{
		x=strcmp(alumno.ncontrol,prestamo1.ncontrol);
		fread(&alumno,sizeof(alumno),1,archa);
		if(x==0)
			break;
		}
		fread (&libro,sizeof(libro),1,archl);
		while(!feof(archl))
		{
		y=strcmp(libro.clave,prestamo1.clave);
		fread (&libro,sizeof(libro),1,archl);
		if(y==0)
			break;
		}
 if(x!=0)
 {
	printf("Registro de alumno inexistente");
	getch();
	salir=1;
 }
 if(y!=0)
 {
 printf("Registro de libro inexistente");
 getch();
 salir=1;
 }
 if(salir==0)
 {
 clrscr();
 gotoxy(28,3);
 cprintf("Datos del Registro solicitado");
 printf ("\n\nNumero de Control: %s\n",prestamo1.ncontrol);
 printf("Clave del libro: %s\n\n",prestamo1.clave);
 printf("Nombre: %s\n",alumno.nombre);
 printf("Carrera: %s\n",alumno.carrera);
 printf("Direccion: %s\n",alumno.direccion);
 printf("Telefono: %s\n\n",alumno.telefono);
 printf("Titulo: %s\n",libro.titulo);
 printf("Autor: %s\n",libro.autor);
 printf("Clasificacion: %s\n",libro.clas);
 printf("Fecha de Prestamo: %s\n",prestamo.fechp);
 printf("Fecha de Entrega: %s\n",prestamo.feche);
 printf("Status: %c",prestamo.status);
 getch();
 }
 }
 }
c:
fclose(archa);
fclose(archl);
fclose (arch);
}