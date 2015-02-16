	/* PROYECTO DE APOLINAR MM
	VALIDACION DE ENTERO         int -32,768 to 32,767
	VALIDACION DE LARGO          long -2,147,483,648 to 2,147,483,647
	VALIDACION DE LARGO DOBLE    long double -3.4 * (10**-4932) to 1.1 * (10**+4932)
	VALIDACION DE CARACTERES */
	//DETALLE NO ENTRA TECLA SUPR
#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<bios.h>
#include<dos.h>
#include<string.h>
#include <ctype.h>
char *ValidChar(unsigned int n,unsigned colorfondo,unsigned colortexto, char tpl, char tipoinfo);
long double ValidLongDouble(unsigned int n, unsigned colorfondo,unsigned colortexto,char g);
long ValidLong(unsigned int n, unsigned colorfondo,unsigned colortexto,char g);
int ValidInte(unsigned int n, unsigned colorfondo,unsigned colortexto,char g);
main()
{
	int reint;
	long relong;
	long double relongdouble;
	char rechar[255]="";
	window(1,1,25,80);
	textbackground(0);
	textcolor(15);
	clrscr();
	printf("Teclea un Numero Entero : ");
	reint=ValidInte(5,1,15,'1');//[1-6]     //Digitos,Fondo,Texto,Signo
	printf("\nInserta un Entero Largo :");  //'1'Negativo, '2' ¢ Otro Sin Signo
	relong=ValidLong(10,1,15,'1');   //[1-11]
	printf("\nInserta un Numero Real : ");
	relongdouble=ValidLongDouble(10,1,15,'1'); //[1-99]
	printf("\nEscribe un Texto : \n");
	strcpy(rechar,ValidChar(40,1,15,'0','m'));//[1-255]
	cout<<"\n"<<reint<<"\n";                  //Nø Caracteres, Fondo, Texto
	cout<<"\n"<<relong<<"\n";                 //'0'Puras Letras ['m']['M']['l']
	cout<<"\n"<<relongdouble<<"\n";          //'1'De todo un poco'['l']
	cout<<"\n"<<rechar;                      //M  Mayus m minus l Libre
	getch();
}

			/* VALIDACION DE LOS ENTEROS */
int ValidInte(unsigned int n, unsigned colorfondo,unsigned colortexto,char g)
{
long as;
int key,i,a,pos,x,y,x1,y1;
char ascii,Vector[6];
x=wherex();
y=wherey();
textcolor(colortexto);
textbackground(colorfondo);
for(i=1;i<=n;i++)cprintf(" ");
do{
Vector[0]='\0';
gotoxy(x,y);
for(i=0,a=0;;)
{
	key=bioskey(0);
	ascii=key;
if(ascii==13)//Enter
	if(Vector[0]=='\0');
	else
	{
	as=0;
	as=atol(Vector);
	break;
	}
if(ascii==45 && i==0 && g=='1')//Dibuja un guion
{
	Vector[i]='-';
	Vector[i+1]='\0';
	cprintf("%c",ascii);
	i++; a++;
}
if(i>=0 && i<=n-1)
	if(ascii>47 && ascii<=57)//Pinta Los Numeros
	{
	Vector[i]=ascii;
	Vector[i+1]='\0';
	cprintf("%c",ascii);
	i++; a++;
	}
if(i>0)
if(ascii=='\b')       //Retorno
{
      gotoxy(wherex()-1,wherey());
      putchar(' ');
      gotoxy(wherex()-1,wherey());
      i--; a--;
      Vector[i]='\0';
}
	if(key==18176)//Inicio
	{
	x1=wherex(); y1=wherey();
	gotoxy(x,y);
	i=0;
	}
	if(key==20224)//Fin
	{
	gotoxy(x1,y1);
	i=a;
	}
if(key==19200 && i>0)   //Atraz
{
	gotoxy(wherex()-1,wherey());
	i--; a--;
}
if(key==19712 && i<n)          //Adelante
{
	gotoxy(wherex()+1,wherey());
	i++; a++;
}

}
//Empieza Break; Termina For
if(as<-32768 || as>32767)
{ a=0; gotoxy(x,y); for(i=1;i<=n;i++)cprintf(" "); }
}while(a==0);
return as;
}

			/*VALIDACION DE LONG */

long ValidLong(unsigned int n, unsigned colorfondo,unsigned colortexto,char g)
{
long double as=0;
int key,i,a,c=1;
char ascii,Vector[11],*asc;
int x,y,x1,y1;
x=wherex();
y=wherey();
//window(x,y,x+n,y);
textcolor(colortexto);
textbackground(colorfondo);
for(i=1;i<=n;i++)cprintf(" ");
do{
Vector[0]='\0';
gotoxy(x,y);
for(i=0,a=0;;)          //Sale con Enter
{
	key=bioskey(0);
	ascii=key;
if(ascii==13)//Enter \r
	if(Vector[0]=='\0');
	else
	break;
if(ascii=='-' && i==0 && g=='1')//Guion
	{
	Vector[i]='-';
	Vector[i+1]='\0';
	cprintf("%c",ascii);
	i++; a++;
	}
if(i>=0 && i<=n-1)
	if(ascii>47 && ascii<=57)//Pinta Los Numeros
	{
	Vector[i]=ascii;
	Vector[i+1]='\0';
	cprintf("%c",ascii);
	i++; a++;
	}
if(i>0)
	if(ascii=='\b')       //Retorno
	{
	gotoxy(wherex()-1,wherey());
	putchar(' ');
	gotoxy(wherex()-1,wherey());
	i--; a--;
	Vector[i]='\0';
	}
if(key==18176)//Inicio
	{
	x1=wherex(); y1=wherey();
	gotoxy(x,y);
	i=0;
	}
if(key==20224)//Fin
	{
	gotoxy(x1,y1);
	i=a;
	}
if(key==19200 && i>0)   //Atraz
	{
	gotoxy(wherex()-1,wherey());
	i--; a--;
	}
if(key==19712 && i<n)          //Adelante
	{
	gotoxy(wherex()+1,wherey());
	i++; a++;
	}

}
char Ayuda[11]="";
if(Vector[0]=='-')
{
	for(i=1;Vector[i]!='\0';i++)
		Ayuda[i-1]=Vector[i];
		Ayuda[i]='\0';
	as=_strtold(Ayuda,&asc);
	if(as>2147483648)
		a=0;
	else
		a=1;
}
else;
as=_strtold(Vector,&asc);
if(as>2147483647 || a==0)
{ a=0;gotoxy(x,y); for(i=1;i<=n;i++)cprintf(" ");}
}while(a==0);
      return as;
}

// ************** LONG DOUBLE **************//
long double ValidLongDouble(unsigned int n, unsigned colorfondo,unsigned colortexto,char g)
{
long double as=0.0;
int key,i,i1,a,a1,pos,c;
char ascii,Vector[100],Vec[100],*asc;
int x,y,x1,y1;
x=wherex();
y=wherey();
textcolor(colortexto);
textbackground(colorfondo);
for(i=1;i<=n;i++)cprintf(" ");
do{
Vector[0]='\0';
gotoxy(x,y);
for(i=0,a=0;;)
{
	key=bioskey(0);
	ascii=key;
if(ascii=='.')
{
	c=0;
	for(int k=0;Vector[k]!='\0';k++)
	{
	if(Vector[k]=='.')
	{c=1;break;}
	}
	if(c==1);
	else {
	Vector[i]=ascii;
	Vector[i+1]='\0';
	cprintf("%c",ascii);
	i++;a++;
	}
}
if(ascii=='e')
{
	c=0;
	for(int k=0;Vector[k]!='\0';k++)
	{
	if(Vector[k]=='e')
	{c=1;break;}
}
if(c==1);
	else {
	Vector[i]=ascii;
	Vector[i+1]='\0';
	cprintf("%c",ascii);
	i++;a++;
	}
}
if(ascii==13)
	if(Vector[0]=='\0');
	else
	{
	as=0;
	as=atol(Vector);
	break;
	}
if((ascii==45 && i==0 && g=='1')||(ascii==45&&Vector[i-1]=='e'))
	{
	Vector[i]='-';
	cprintf("%c",ascii);
	i++; a++;
	}
if(i>=0 && i<=n-1)
	if(ascii>47 && ascii<=57 )//Pinta Los Numeros
	{
	Vector[i]=ascii;
	Vector[i+1]='\0';
	cprintf("%c",ascii);
	i++; a++;
	}
if(i>0)
if(ascii=='\b')       //Retorno
	{
	gotoxy(wherex()-1,wherey());
	putchar(' ');
	gotoxy(wherex()-1,wherey());
	i--; a--;
	Vector[i]='\0';
	}
if(key==18176)//Inicio
	{
	x1=wherex(); y1=wherey();
	gotoxy(x,y);
	i=0;
	}
	if(key==20224)//Fin
	{
	gotoxy(x1,y1);
	i=a;
	}
if(key==19200 && i>0)   //Atraz
	{
	gotoxy(wherex()-1,wherey());
	i--; a--;
	}
if(key==19712 && i<n)          //Adelante
	{
	gotoxy(wherex()+1,wherey());
	i++; a++;
	}

}
Vector[n]='\0';
as=_strtold(Vector,&asc);
}while(a==0);
return as;
}
// ************ FUNCION CARACTERES *****************//
char *ValidChar(unsigned int n, unsigned colorfondo,unsigned colortexto, char tipoinfo, char tpl)
{
int key,i,a;
char ascii,Vector[255];
int x,y,x1,y1;
x=wherex();
y=wherey();
textcolor(colortexto);
textbackground(colorfondo);
for(i=1;i<=n;i++)cprintf(" ");
Vector[0]='\0';
gotoxy(x,y);
if(tipoinfo=='0')
switch(tpl)
{
	case 'm':
		for(i=0,a=0;;)
		{
		key=bioskey(0);
		ascii=key;
		if(ascii==13)
			break;
		ascii=tolower(ascii);
			if(key==18176)//Inico
				{
				//x1=wherex(); y1=wherey();
				gotoxy(x,y);
				i=0;
				}
			if(key==20224)//Fin
				{
				gotoxy(x1,y1);
				i=a;
				}
			if(key==19200 && i>0)   //Atraz
				{
				gotoxy(wherex()-1,wherey());
				i--; a--;
				}
			if(key==19712 && i<n)          //Adelante
				{
				gotoxy(wherex()+1,wherey());
				i++; a++;
				}

		if(i>=0 && i<=n-1)
		if((ascii>96&&ascii<=122)||ascii=='¤'||ascii==' '||ascii==' '||ascii=='‚'||ascii=='¢'||ascii=='£'||ascii=='¡'||ascii=='.')
		//Pinta Las Minusculas
		{
			Vector[i]=ascii;
			Vector[i+1]='\0';
			cprintf("%c",ascii);
			i++; a++;
		}
		if(ascii=='\b'&&i>0)       //Retorno
		{
			gotoxy(wherex()-1,wherey());
			putchar(' ');
			gotoxy(wherex()-1,wherey());
			i--; a--;
			Vector[i]='\0';
		}
		switch(ascii)
		{
		case 'µ': ascii=' ';
		Vector[i]=ascii;
			cprintf("%c",ascii);
			i++; a++;
			break;
		case '': ascii='‚';
		Vector[i]=ascii;
			cprintf("%c",ascii);
			i++; a++;
			break;
		case 'Ö': ascii='¡';
		Vector[i]=ascii;
			cprintf("%c",ascii);
			i++; a++;
			break;
		case 'à': ascii='¢';
		Vector[i]=ascii;
			cprintf("%c",ascii);
			i++; a++;
			break;
		case 'é': ascii='£';
			Vector[i]=ascii;
			cprintf("%c",ascii);
			i++; a++;
			break;
		}

		}
	break;
case 'M'://Solo Mayusculas
for(i=0,a=0;;)
{
	key=bioskey(0);
	ascii=key;
	if(ascii==13)
		break;
	ascii=toupper(ascii);
			if(key==18176)//Inicio
				{
				x1=wherex(); y1=wherey();
				gotoxy(x,y);
				i=0;
				}
			if(key==20224)//Fin
				{
				gotoxy(x1,y1);
				i=a;
				}
			if(key==19200 && i>0)   //Atraz
				{
				gotoxy(wherex()-1,wherey());
				i--; a--;
				}
			if(key==19712 && i<n)          //Adelante
				{
				gotoxy(wherex()+1,wherey());
				i++; a++;
				}

	if(i>=0 && i<=n-1)
	if((ascii>64&&ascii<=90)||ascii=='¥'||ascii==' '||ascii=='µ'||ascii==''||ascii=='Ö'||ascii=='à'||ascii=='é'||ascii=='.')
	//Pinta Las Minusculas
	{
	Vector[i]=ascii;
	Vector[i+1]='\0';
	cprintf("%c",ascii);
	i++; a++;
	}
	if(ascii=='\b'&&i>0)       //Retorno
		{
			gotoxy(wherex()-1,wherey());
			putchar(' ');
			gotoxy(wherex()-1,wherey());
			i--; a--;
			Vector[i]='\0';
		}
	switch(ascii)
		{
		case ' ': ascii='µ';
		Vector[i]=ascii;
			cprintf("%c",ascii);
			i++; a++;
			break;
		case '‚': ascii='';
		Vector[i]=ascii;
			cprintf("%c",ascii);
			i++; a++;
			break;
		case '¡': ascii='Ö';
		Vector[i]=ascii;
			cprintf("%c",ascii);
			i++; a++;
			break;
		case '¢': ascii='à';
		Vector[i]=ascii;
			cprintf("%c",ascii);
			i++; a++;
			break;
		case '£': ascii='é';
			Vector[i]=ascii;
			cprintf("%c",ascii);
			i++; a++;
			break;
		}
}
break;
case 'l':
for(i=0,a=0;;)
{
	key=bioskey(0);
	ascii=key;
	if(ascii==13)
		break;
			if(key==18176)//Inicio
				{
				x1=wherex(); y1=wherey();
				gotoxy(x,y);
				i=0;
				}
			if(key==20224)//Fin
				{
				gotoxy(x1,y1);
				i=a;
				}
			if(key==19200 && i>0)   //Atraz
				{
				gotoxy(wherex()-1,wherey());
				i--; a--;
				}
			if(key==19712 && i<n)          //Adelante
				{
				gotoxy(wherex()+1,wherey());
				i++; a++;
				}

	if(i>=0 && i<=n-1)
	if((ascii>=65 && ascii<=90) || (ascii>=97 && ascii<=122) || ascii=='¤'||ascii=='¥' || ascii==' ' || ascii=='‚' ||ascii=='¡' ||ascii=='¢' ||ascii=='£' ||ascii=='µ' ||ascii=='' ||ascii=='Ö' ||ascii=='à' ||ascii=='é' || ascii==' '||ascii=='.')
	//Pinta Las Minusculas
	{
	Vector[i]=ascii;
	Vector[i+1]='\0';
	cprintf("%c",ascii);
	i++; a++;
	}
	if(ascii=='\b'&&i>0)       //Retorno
	{
	gotoxy(wherex()-1,wherey());
	putchar(' ');
	gotoxy(wherex()-1,wherey());
	i--; a--;
	Vector[i]='\0';
	}
}
break;
}
//*****************HEY AQUI LA OTRA MITAD*********************
if(tipoinfo=='1'&&tpl=='l')
	for(i=0,a=0;;)
	{
		key=bioskey(0);
		ascii=key;
		if(ascii==13)
			break;
			if(key==18176)//Inicio
				{
				x1=wherex(); y1=wherey();
				gotoxy(x,y);
				i=0;
				}
			if(key==20224)//Fin
				{
				gotoxy(x1,y1);
				i=a;
				}
			if(key==19200 && i>0)   //Atraz
				{
				gotoxy(wherex()-1,wherey());
				i--; a--;
				}
			if(key==19712 && i<n)          //Adelante
				{
				gotoxy(wherex()+1,wherey());
				i++; a++;
				}

		if(i>=0 && i<=n-1)
		if((ascii>64 && ascii<91)||(ascii==' '||ascii==' '||ascii=='‚'||ascii=='¡'||ascii=='¢'||ascii=='£'))
		{
			Vector[i]=ascii;
			Vector[i+1]='\0';
			cprintf("%c",ascii);
			i++; a++;
		}
		if((ascii>32 && ascii<65)||(ascii>122 && ascii<255)||ascii=='¨'||ascii=='­'||ascii=='ø'||ascii=='_')
		{
			Vector[i]=ascii;
			Vector[i+1]='\0';
			cprintf("%c",ascii);
			i++; a++;
		}
		if((ascii>96 && ascii<123)||ascii=='¥'||ascii=='¤')
		{
			Vector[i]=ascii;
			Vector[i+1]='\0';
			cprintf("%c",ascii);
			i++; a++;
		}
		if(ascii=='µ'||ascii==''||ascii=='Ö'||ascii=='à'||ascii=='é')
		{
			Vector[i]=ascii;
			Vector[i+1]='\0';
			cprintf("%c",ascii);
			i++; a++;
		}
		if(ascii=='\b'&&i>0)       //Retroceso
		{
			gotoxy(wherex()-1,wherey());
			putchar(' ');
			gotoxy(wherex()-1,wherey());
			i--; a--;
			Vector[i]='\0';
		}
}
return Vector;
}



