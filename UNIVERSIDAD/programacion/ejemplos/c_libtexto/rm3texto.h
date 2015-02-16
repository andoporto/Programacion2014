	/* *********************************************** */
	/*     Libreria para el manejo del modo texto      */
	/*	Desarrollada por Raul Marmolejo            */
	/*	    www.raul.marmolejo.net                 */
	/*	  raulgerardo@marmolejo.net                */
	/*	  Probada con Turbo C++ 3.0                */
	/* *********************************************** */


#ifndef _rm3texto_h
#define _rm3texto_h


#include <bios.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <dos.h>
#include <stdio.h>
#include <stdlib.h>

#define arriba    1072
#define izquierda 1075
#define derecha   1077
#define abajo     1080
#define esc         27
#define enter       13
#define altf4     1107
#define win1      1182
#define win2      1183
#define back         8
#define espace      32

/************************** Inicio de los prototipos ************************/
int rm3getch(int cur);
int evento(void);
void mver(void);
void mocultar(void);
int mxpos(int);
int mypos(int);
void msituar(int, int, int);
int mclick(void);
void mlimit(int, int, int, int, int);
void limpiar_buffer(void);
void rm3cursor(int vis);
void uno(void);
void dos(void);
void tres(void);
void cuatro(void);
void cinco(void);
void seis(void);
void limpiarcuadro(int x,int y, int longitud, int ancho, char *text, int color);
void imprimir(int x, int y,int time, char *msje, int color);
void ventana(int x, int y, int largo, int ancho, int time, int fondo,int col);
void mensaje(int x, int y, char *msje, int colorc, int colort,int fondo);
void centrar(int y, char *cad,int color);
void centrarmensaje(int y, char *texto, int colorc, int colorm, int fondo,int time);
void barra(int x, int y, int largo, int time, int color);
void fidsbar(int x, int y, int largo, int time, int color,int colorp, char *text,char *text2, int colort);
void ventana2(int x, int y, int longi, int ancho, int time, int color,int fondo,int tipo);
void ventana3(int x, int y,int largo, int ancho, int time,int tipo, int colorc, char *c, int colorchar);
void linea(int x, int y, int longitud, int time, int tipo,int color, char *direccion);
void desplazar(int x, int y, int time, char *msje, int color, int londes, char *direccion);
void limpiarpantalla(int colorfondo);
void espacio(int x,int y,int max);
/************************** Fin de los prototipos ***************************/



void imprimir(int x, int y,int time,char *msje, int color)
{
	for(int s=0;msje[s]!=NULL;s++){
		gotoxy((x+1),y);
		textcolor(color);cprintf("%c",msje[s]);
		delay(time);
		x++;
	}
}


void ventana(int x, int y, int largo, int ancho, int time, int fondo,int col)
{
	int i,j;
	textbackground(fondo);
	for(i=largo;i>0;i--){
		gotoxy((x+i),y);
		textcolor(col);cprintf("Í");
		delay(time);
	}

	printf("\b");

	for(j=0;j<ancho;j++){
		if(j==0){
			gotoxy(x,(y+j));
			textcolor(col);cprintf("É");
		}
		gotoxy(x,(y+(j+1)));
		textcolor(col);cprintf("º");
		delay(time);
	}

	for(i=0;i<largo;i++){
		if(i==0){
			gotoxy((x+i),(y + ancho));
			textcolor(col);cprintf("È");}
		gotoxy(((x+1)+i),(y + ancho));
		textcolor(col);cprintf("Í");
		delay(time);
	}

	for(j=0;j<ancho;j++){
		if(j==0){
			gotoxy((largo + x),((y + ancho)-j));
			textcolor(col);cprintf("¼");}
		gotoxy((largo + x),((y + ancho)-(j+1)));
		textcolor(col);cprintf("º");
		delay(time);
	}
	gotoxy((largo + x),y);
	textcolor(col);cprintf("»");

}


void mensaje(int x, int y, char *msje, int colorc, int colort,int fondo)
{
	int longitud;
	longitud = strlen(msje)+5;
	ventana((x-2),(y-1),longitud,2,0,colorc,fondo); 	//x,y,largo,ancho,tiempo,color
	imprimir(x,y,0,msje,colort);   		//x,y,time,mensaje,color
}

void limpiarcuadro(int x,int y, int longitud, int ancho, char *text, int color)
{
	for(int i=0;i<ancho;i++){
		for(int j=0;j<longitud;j++){
			gotoxy((x+j),y);
			textattr(color);cprintf("%s",text);
		}
		y++;
	}
}



void centrar(int y,char *cad,int color)
{
	int longitud;
	longitud = strlen(cad);
	gotoxy(((80-longitud)/2),y);
	textcolor(color);cprintf("%s",cad);
}

void centrarmensaje(int y, char *texto, int colorc, int colorm, int fondo,int time)
{
	int longitud;
	longitud = strlen(texto)+5;
	ventana((((80-longitud)/2)-2),y,longitud,2,time,fondo,colorc);
	imprimir(((80-longitud)/2),(y+1),time,texto,colorm);
}


void barra(int x, int y, int largo, int time, int color)
{
	for(int i=0;i<largo;i++){
		gotoxy((x+i),y);textattr(color);
		cprintf("Û");
		delay(time);
	}
}


void fidsbar(int x, int y, int largo, int time, int color,int colorp, char *text, char *text2,int colort)
{
	float nk,s=0;
	int pos,pos2,pos3;
	pos = (x+(largo-3)/2);
	pos2 = (x+(largo - strlen(text))/2)+1;
	pos3= (x+(largo -strlen(text2))/2)+1;
	nk = (100/largo);
	barra(x,y,largo,0,15);
	//getch();
	gotoxy(pos2,(y+1));textattr(colort);
	cprintf("%s",text);
	for(int i=0;i<largo;i++){
		gotoxy((x+i),y);textattr(color);
		cprintf("Û");
		s += nk;
		gotoxy(pos,(y-1));textattr(colorp);
		cprintf("%.0f%",s);
		delay(time);
	}
	if(s!=100){
		gotoxy(pos,(y-1));textattr(colorp);
		cprintf("100%");
	}
	gotoxy(pos2,(y+1));limpiarcuadro(pos2,(y+1),(strlen(text)),1," ",colort);
	gotoxy(pos3,(y+1));textattr(colort);
	cprintf("%s",text2);
}

void ventana2(int x, int y, int longi, int ancho, int time, int color,int fondo ,int tipo)
{
	int i,j,h,k,mitad,media;
	mitad=longi/2;
	h = mitad;
	media=mitad+1;
	textbackground(fondo);
	textcolor(color);
	for(j=0;j<h;j++){
		gotoxy((x+mitad),y);
		if(tipo==1)
			cprintf("Ä");
		else
			cprintf("Í");
		delay(time);
		gotoxy((x+media),y);
		if(tipo==1)
			cprintf("Ä");
		else
			cprintf("Í");
		mitad--;
		media++;
	}
	gotoxy(x,y);
	if(tipo==1)
			cprintf("Ä");
		else
			cprintf("Í");
	gotoxy(x,y);

	for(k=0;k<ancho;k++){
		if(k==0){
			gotoxy(x,y);
			if(tipo==1)
				cprintf("Ú");
			else
				cprintf("É");
			gotoxy((x+media),y);
			if(tipo==1)
				cprintf("¿");
			else
				cprintf("»");
		}
		else{
			gotoxy(x,y);
			if(tipo==1)
				cprintf("³");
			else
				cprintf("º");
			gotoxy((x+media),y);
			if(tipo==1)
				cprintf("³");
			else
				cprintf("º");
		}
		delay(time);
		y++;
	}

	for(i=0;i<(h+1);i++){
		if(i==0){
			gotoxy(x,y);
			if(tipo==1)
				cprintf("À");
			else
				cprintf("È");
			gotoxy((x+media),y);
			if(tipo==1)
				cprintf("Ù");
			else
				cprintf("¼");
		}
		else{
			gotoxy((x+mitad),y);
			if(tipo==1)
				cprintf("Ä");
			else
				cprintf("Í");
			delay(time);
			gotoxy((x+media),y);
			if(tipo==1)
				cprintf("Ä");
			else
				cprintf("Í");
		}
		x++;
		media-=2;
	}
}

void ventana3(int x, int y,int largo, int ancho, int time,int tipo, int colorc, char *c, int colorchar)
{
	limpiarcuadro(x,y,largo,ancho,c,colorchar);
	textattr(colorc);
	ventana2(x,y,(largo-1),(ancho-1),time,colorc,tipo,BLACK);
}

void linea(int x, int y, int longitud, int time, int tipo,int color, char *direccion)
{
	int longi;
	longi = strlen(direccion);
	for(int k=0;k<longi;k++)
		direccion[k] = toupper(direccion[k]);
	if(strcmpi(direccion,"HORIZONTAL")==0){
		for(int i=0;i<longitud;i++){
			gotoxy(x,y);textattr(color);
			if(tipo == 1)
				cprintf("Ä");
			else
				cprintf("Í");
			x++;
			delay(time);
		}
	}
	else{
		if(strcmpi(direccion,"VERTICAL")==0){
			for(int j=0;j<longitud;j++){
				gotoxy(x,y);textattr(color);
				if(tipo == 1)
					cprintf("³");
				else
					cprintf("º");
				y++;
				delay(time);
			}
		}
		else{
			textattr(color);cprintf("Error de direcci¢n de l¡nea(vertical/horizontal)...");
		}
	}
}

void desplazar(int x, int y, int time, char *msje, int color, int londes, char *direccion)
{
	int largo;
	int longi,ra;
	ra = x;
	longi = strlen(direccion);
	for(int k=0;k<longi;k++)
		direccion[k] = toupper(direccion[k]);
	largo = strlen(msje)+2;
	if(strcmpi(direccion,"IZQUIERDA")==0){
		for(int i=0;i<londes;i++){
			imprimir(x,y,0,msje,color);
			x--;limpiarcuadro((x+largo),y,2,1," ",color);
			if(x==1){
				x=ra;
				limpiarcuadro(1,y,largo,1," ",color);
			}
			delay(time);
		}
	}
	if(strcmpi(direccion,"DERECHA")==0){
		for(int i=0;i<londes;i++){
			imprimir(x,y,0,msje,color);
			x++;limpiarcuadro((x-1),y,1,1," ",color);
			if((x+largo)==80){
				x=ra;
				limpiarcuadro(ra,y,(x+largo),1," ",color);
			}
			delay(time);
		}
	}
}

void limpiarpantalla(int colorfondo)
{
	int x=0,y=25;
	for(int i=0;i<25;i++){
		for(int j=80;j>=1;j--){
			gotoxy((x+j),y);
			textattr(colorfondo);
			cprintf(" ");
		}
		y--;
	}
	textattr(15);
	espacio(1,1,3);
}

void espacio(int x,int y,int max)
{
	gotoxy(x,y);
	for(int i=0;i<max;i++)
		cprintf(" ");
	gotoxy(x,y);
}
int ratondentro(int X1, int Y1, int X2, int Y2, int MODO)
{
	return (mxpos(MODO) >= X1) && (mxpos(MODO) <=X2) && (mypos(MODO) >= Y1) && (mypos(MODO) <= Y2);
}

int menu(int x1,int y1,int no_opciones,const char *opciones[],int texto=1,int fondo=7,int resaltar=10)
{
  char memoria[1000];
  int tecla,juana,cont=0;
  gettext(x1,y1-1,x1+19,y1+no_opciones+1,memoria);
  rm3cursor(0);
  textbackground(7);
  textcolor(texto);
  ventana2(x1,y1-1,16,no_opciones+1,0,BLACK,fondo,1);
  for(int vieta=x1+1;vieta<=x1+18;vieta++){
   textcolor(BLACK);
   gotoxy(vieta,y1+no_opciones+1);
   cprintf("Û");
   }
   for(int rm3=y1;rm3<=y1+no_opciones+1;rm3++){
    textcolor(BLACK);
    gotoxy(x1+18,rm3);
    cprintf("ÛÛ");
   }
  textcolor(texto);
  textbackground(fondo);
   for(int l=y1;l<=no_opciones+y1-1;l++){
     if( l-y1 == 0) {
     gotoxy(x1+1,l);
     textbackground(resaltar);
     cprintf(">> %s",opciones[0]);}
     else{
       textbackground(fondo);
       gotoxy(x1+1,l);
       cprintf("> %s ",opciones[l-y1]);
     }
    }

for(;;){
  tecla=evento();
  if(tecla == abajo){
    cont++;
     if(cont == no_opciones) {
       cont=0;
       textbackground(resaltar);
       textcolor(texto);
       gotoxy(x1+1,y1);
       cprintf(">> %s",opciones[cont]);
       textbackground(fondo);
       textcolor(texto);
       gotoxy(x1+1,y1+no_opciones-1);
       cprintf("> %s ",opciones[no_opciones-1]);
      }
   else{
     textbackground(resaltar);
     textcolor(texto);
     gotoxy(x1+1,cont+y1);
     cprintf(">> %s",opciones[cont]);
     textbackground(fondo);
     textcolor(texto);
     gotoxy(x1+1,cont+y1-1);
     cprintf("> %s ",opciones[cont-1]);
      }
    }
    if(tecla == arriba){
    cont--;
     if(cont == -1) {
       cont=no_opciones-1;
       textbackground(resaltar);
       textcolor(texto);
       gotoxy(x1+1,y1+cont);
       cprintf(">> %s",opciones[cont]);
       textbackground(fondo);
       textcolor(texto);
       gotoxy(x1+1,y1);
       cprintf("> %s ",opciones[0]);
      }
   else{
     textbackground(resaltar);
     textcolor(texto);
     gotoxy(x1+1,cont+y1);
     cprintf(">> %s",opciones[cont]);
     textbackground(fondo);
     textcolor(texto);
     gotoxy(x1+1,cont+y1+1);
     cprintf("> %s ",opciones[cont+1]);
      }
    }
  if(tecla == esc) {
       puttext(x1,y1-1,x1+19,y1+no_opciones+1, memoria);
       return 0;
       }
  if(tecla == enter ){
       puttext(x1,y1-1,x1+19,y1+no_opciones+1, memoria);
       return cont+1;
       }
  if(tecla == 1){
    juana=mypos(8);
    if(ratondentro(x1,y1-1,x1+15,y1+no_opciones,8)){
       puttext(x1,y1-1,x1+19,y1+no_opciones+1, memoria);
       return (juana+2-y1);
      }
    else {
       puttext(x1,y1-1,x1+19,y1+no_opciones+1, memoria);
       return 0;
      }

     }
   }
 }

int rm3getch(int cur=1)
{
    int c;
//    limpiar_buffer();
    if (cur==1) rm3cursor(1);               /*muestra cursor*/

    c = getch();                            /*lee una tecla*/
    if (c == 0) {                           /*si especial*/
	c = getch()+1000;                   /*lee otra, corrige*/
    }

    if (cur==0)  rm3cursor(0);                   /*oculta cursor*/
    return c;                               /*devuelve tecla*/
}

void salir(void)
{
 int r;
 randomize();
 r=random(6);
 switch(r){
  case 0:uno();break;
  case 1:dos();break;
  case 2:tres();break;
  case 3:cuatro();break;
  case 4:cinco();break;
  case 5:seis();break;
 }

}

void limpiar_buffer(void)
{
    while (kbhit()) {                       /*hasta que hay caracteres*/
	getch();                            /*los lee y los ignora*/
    }
}



void uno(void)
{    int i;
    for(i=0;i<=14;i++)
    {
    clrscr();
    gotoxy(1,1+i);
    printf("                          (o-o) ");
    gotoxy(1,2+i);
    printf("==-=-=-=-=-=-=-=-=---.oOO--(_)--OOo.---=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==");
    gotoxy(1,3+i);
    printf("                                     |");
    gotoxy(1,4+i);
    printf("       ______ ______  _______        | Nombre : Raul Marmolejo");
    gotoxy(1,5+i);
    printf("         \_  __\\      \\____  \         |");
    gotoxy(1,6+i);
    printf("        |  | \/  Y Y  \_(__  <         | E-mail : raul@marmolejo.net");
    gotoxy(1,7+i);
    printf("        |__| |__|_| /      /         |");
    gotoxy(1,8+i);
    printf("                  \/____  /           | Website: www.raul.marmolejo.net");
    gotoxy(1,9+i);
    printf("  Kreationz            \\/            |");
    gotoxy(1,10+i);
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-==");
    delay(300);
  }

 }





 void dos(void)
{
printf("\n          .:'                                   `:. ");
printf("\n         ::'                                     `:: ");
printf("\n        :: :.                                  .: :: ");
printf("\n         `:. `:.               .             .:'  .:' ");
printf("\n           `::. `::            !           ::' .::' ");
printf("\n             `::.`::.       .' ! `.    .::'.::' ");
printf("\n		  `:.  `::::'':!:``::::'   ::' ");
printf("\n		  :'*:::.  .:' ! `:.  .:::*`: ");
printf("\n		 :: HHH::.   ` ! '   .::HHH :: ");
printf("\n		::: `H TH::.  `!'  .::HT H' :::         ===> rm3 <===   ");
printf("\n     		::..  `THHH:`:   :':HHHT'  ..::       <=== Kreation ===>             ");
printf("\n     		`::      `T: `. .' :T'      ::' ");
printf("\n     		  `:. .   :         :   . .:' ");
printf("\n     		    `::'               `::' ");
printf("\n     		      :'  .`.  .  .'.  `: ");
printf("\n     		      :' ::.       .:: `: ");
printf("\n     		      :' `:::     :::' `: ");
printf("\n     		       `.  ``     ''  .' ");
printf("\n     			:`...........': ");
printf("\n     			` :`. ___ .': ' ");
printf("\n     			 `:  `   '  :' ");

}

void seis(void)
{
printf("\n        @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ");
printf("\n        @@@@@@@@@@@@@@@@@@@@'~~~     ~~~`@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ ");
printf("\n        @@@@@@@@@@@@@@@'                     `@@@@@@@@@@@@@@@@@@@@@@@@@@ ");
printf("\n        @@@@@@@@@@@@'                           `@@@@@@@@@@@@@@@@@@@@@@@ ");
printf("\n        @@@@@@@@@@'          [[[rm3]]]            `@@@@@@@@@@@@@@@@@@@@@ ");
printf("\n        @@@@@@@@'                                   `@@@@@@@@@@@@@@@@@@@ ");
printf("\n        @@@@@@@'             kReAtIoNs               `@@@@@@@@@@@@@@@@@@ ");
printf("\n        @@@@@@'                                       `@@@@@@@@@@@@@@@@@ ");
printf("\n        @@@@@@                                         @@@@@@@@@@@@@@@@@ ");
printf("\n        @@@@@'                      n,                 `@@@@@@@@@@@@@@@@ ");
printf("\n        @@@@@                     _/ | _                @@@@@@@@@@@@@@@@ ");
printf("\n        @@@@@                    /'  `'/                @@@@@@@@@@@@@@@@ ");
printf("\n        @@@@@a                 <~    .'                a@@@@@@@@@@@@@@@@ ");
printf("\n        @@@@@@                 .'    |                 @@@@@@@@@@@@@@@@@ ");
printf("\n        @@@@@@a              _/      |                a@@@@@@@@@@@@@@@@@ ");
printf("\n        @@@@@@@a           _/      `.`.              a@@@@@@@@@@@@@@@@@@ ");
printf("\n        @@@@@@@@a     ____/ '   \__ | |______        a@@@@@@@@@@@@@@@@@@@ ");
printf("\n        @@@@@@@@@@a__/___/      /__\ \ \     \___.    a@@@@@@@@@@@@@@@@@@@@@ ");
printf("\n        @@@@@@@@@@/  (___.'\_______)\_|_|        \   @@@@@@@@@@@@@@@@@@@@@@ ");
printf("\n        @@@@@@@@@|\________                       ~~~~~\  @@@@@@@@@@@@@@@@ ");
printf("\n        @@@@@@@@@||       |\___________________________/|@/~~~~~~~~~\  @@@ ");
printf("\n        @@@@@@@@/ |  |    | |                         | ||\__________| @@ ");

}


void cuatro(void)
{
printf("\n\n\n\n\n\n");
printf("\n                       ,,,)))      _____________");
printf("\n                        \ (, ,)    |        '\\\\\\");
printf("\n                        c\   >'    |        ' ____|_");
printf("\n                         ) o/     |   +    '||::::::");
printf("\n                     ___/ /___    |        '||_____|");
printf("\n	            '--/ \\_/   )  \\'_______|_____|");
printf("\n                  |'/'.   /  ='\\  ___/____|___\\___");
printf("\n                 _|/_oOo__:__oOo_\|    _    '  <<<:|");
printf("\n               /___/__________/__|_________'___o_o|");
printf("\n                   rm3 Kreationz    ");

}


void cinco(void)
{
printf("\n\n\n\n");
printf("\n                                        .");
printf("\n                              /^\\     .  ");
printf("\n                         /\\   'V'        ");
printf("\n              rm3       /__\\   I      O  o");
printf("\n           KrEaTiOnZ   //..\\\\  I     .   ");
printf("\n                       \\].`[/  I          ");
printf("\n                       /l\\/j\\  (}    .  O  ");
printf("\n                      /. ~~ ,\\\/I          .");
printf("\n                     \\\\L__j^\\\\/I       o   ");
printf("\n                      \\\\/--v}  I     o   . ");
printf("\n                       |    |  I   _________ ");
printf("\n                       |    |  I c(`       ')o ");
printf("\n                       |    l  I  \\.     ,/     ");
printf("\n                     _/j  L l\\_!  _//^---^\\\_ ");
printf("\n                  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ");

}


void tres(void)
{
printf("\n\n");
printf("\n                              __---__");
printf("\n                           _-       _--______");
printf("\n                       __--( /     \ )XXXXXXXXXXXXX_");
printf("\n		     --XXX(   O   O  )XXXXXXXXXXXXXXX-");
printf("\n		    /XXX(       U     )        XXXXXXX\\ ");
printf("\n		  /XXXXX(              )--_  XXXXXXXXXXX\\");
printf("\n		 /XXXXX/ (      O     )   XXXXXX   \XXXXX\\");
printf("\n		 XXXXX/   /            XXXXXX   \__ \XXXXX----");
printf("\n		 XXXXXX__/          XXXXXX         \__----  -");
printf("\n	 ---___  XXX__/          XXXXXX      \__         ---");
printf("\n	   --  --__/   ___/\  XXXXXX            /  ___---=");
printf("\n	     -_    ___/    XXXXXX              '--- XXXXXX");
printf("\n	       --\/XXX\ XXXXXX                      /XXXXX");
printf("\n		 \XXXXXXXXX                        /XXXXX/");
printf("\n		  \XXXXXX        {{{rm3}}}       _/XXXXX/");
printf("\n		    \XXXXX--__/   Kreations   __-- XXXX/");
printf("\n		     --XXXXXXX---------------  XXXXX--");
printf("\n			\XXXXXXXXXXXXXXXXXXXXXXXX-");
printf("\n			  --XXXXXXXXXXXXXXXXXX-");

 }


void hora(int x=70,int y=25)
{
char *meridiano="AM";
struct  time t;

gettime(&t);
if(t.ti_hour>12)
 {
  t.ti_hour-=12;
  meridiano="PM";
  }

gotoxy(x,y);
printf("%2d:%02d %s ", t.ti_hour, t.ti_min,meridiano);
 }


void fecha(int x=52,int y=1)
{
  int mes2,dia2;
  char *mes,*dia;
  struct date rm3;
  getdate(&rm3);
  mes2=rm3.da_year;
   switch(mes2)
   {
   case 1:mes="Enero";break;
   case 2:mes="Febrero";break;
   case 3:mes="Marzo";break;
   case 4:mes="Abril";break;
   case 5:mes="Mayo";break;
   case 6:mes="Junio";break;
   case 7:mes="Julio";break;
   case 8:mes="Agosto";break;
   case 9:mes="Septiembre";break;
   case 10:mes="Octubre";break;
   case 11:mes="Noviembre";break;
   case 12:mes="Diciembre";break;
   }

   dia2=rm3.da_day;
   switch(dia2)
   {
   case 1:dia="Lunes";break;
   case 2:dia="Martes";break;
   case 3:dia="Mi‚rcoles";break;
   case 4:dia="Jueves";break;
   case 5:dia="Viernes";break;
   case 6:dia="S bado";break;
   case 7:dia="Domingo";break;
   }

  gotoxy(x,y);
  printf("%s %d de %s del %d ",dia,rm3.da_day,mes,rm3.da_year);

}

void rm3cursor(int vis)
{
    static int           v = 1;             /*normalmente, cursor visible*/
    static unsigned char start;             /*l¡nea inicial del cursor*/
    static unsigned char end;               /*l¡nea final del cursor*/

    union REGS ir;                          /*para interface con BIOS*/
    union REGS or;

    if (vis != v) {                         /*procede s¢lo si cambia*/
	if (vis) {                          /*si debe mostrarlo*/
	    ir.h.ah = 0x01;                 /*Set Cursor Size*/
	    ir.h.ch = start;                /*valores guardados antes*/
	    ir.h.cl = end;
	    int86(0x10,&ir,&or);            /*llama al V¡deo del BIOS*/
       } else {                            /*si debe ocultarlo*/
	    ir.h.ah = 0x03;                 /*Read Cursor Pos, Size*/
	    ir.h.bh = 0;                    /*p gina v¡deo 0*/
	    int86(0x10,&ir,&or);            /*llama al V¡deo del BIOS*/
	    start = or.h.ch;                /*graba datos del cursor*/
	    end = or.h.cl;
	    ir.h.ah = 0x01;                 /*Set Cursor Size*/
	    ir.h.ch = 0x20;                 /*ning£n cursor*/
	    int86(0x10,&ir,&or);            /*llama al V¡deo del BIOS*/
	}
	v = vis;                            /*registra nuevo estado*/
    }
}

#endif