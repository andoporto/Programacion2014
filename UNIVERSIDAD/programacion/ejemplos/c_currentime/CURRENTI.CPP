//current_time.cpp

//by felixcriv@msn.com ;)

//Entrega el formato fr nces de fecha a partir del formato ingles del sistema
//es decir, Dia(Lunes, Martes..), Mes(Enero,...), del A¤o(2000,2003...)
//La hora es entregada en formato hh:mm:ss; dependiendo del sistema.
//Fue desarrollado en Borland C++ 5.0,no se necesitan ajustes para su
//compilaci¢n / Ejecuci¢n.

//Las rutinas desarrolladas aqu¡ pueden las puedes incluir en tus programas
//salvo que tienes que colocar en los comentarios de donde tomastes las
//rutinas, s¡ me reservo derechos de autor, puesto que las rutinas de tiempo/
//fecha son empleadas y desarrolladas de cientos de formas por otros programadores
//Es muy £til usarlas en archivos generados o en la impresi¢n de archivos por
//impresora, o para lanzar una ejecuci¢n cada cierta fecha u hora.
//Este codigo genera una clave que me puedes enviar y yo te envio uno de mis
//manuales de programacion en c/c++/vc++.

//No dudes en enviar cualquier duda, comentario, sugerencia sobre el c¢digo o
//¨como? incluir las funciones en tus programas.

//F‚lix Guerrero
//Nov 2003 M‚rida - Venezuela.

//----------------------------------------------------------------------------
#include <stdio.h>
#include <dos.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <fstream.h>
#include <iostream.h>
//----------------------------------------------------------------------------

char horas,mes,dias;
int  activ,filter;
char days[10],d[20];
char *tzstr = "TZ=PST8PDT"; //An array of pointers to strings containing
			    //abbreviations for time-zone names.
char name[30];
char ema[30];


void filex();


void main(void)
{
  struct dostime_t hora; _dos_gettime(&hora); //hora  DOS-BIOS del sistema
  struct dosdate_t fecha;_dos_getdate(&fecha);//fecha DOS-BIOS del sistema
  struct tm *area;

  time_t t;
  t    = time(NULL);
  area = localtime(&t);

  clrscr();
  /*********************************************************************
  *                                                                    *
  *                        AM/PM TIME SELECT                           *
  *                                                                    *
  **********************************************************************/
  switch(hora.hour)
  {

   case 24:
   case  1:
   case  2:
   case  3:
   case  4:
   case  5:
   case  6:
   case  7:
   case  8:
   case  9:
   case 10:
   case 11:          activ=0;break;//horas matutinas


   case 12: horas=12;activ=1;break;//es mediodia


   case 13: horas=1 ;activ=2;break;//horas vespertinas
   case 14: horas=2 ;activ=2;break;
   case 15: horas=3 ;activ=2;break;
   case 16: horas=4 ;activ=2;break;
   case 17: horas=5 ;activ=2;break;
   case 18: horas=6 ;activ=2;break;
   case 19: horas=7 ;activ=2;break;
   case 20: horas=8 ;activ=2;break;
   case 21: horas=9 ;activ=2;break;
   case 22: horas=10;activ=2;break;
   case 23: horas=11;activ=2;break;


   }

  /*******************************************************************
  *								     *
  *	                  Month/Year/Day Select	                     *
  *								     *
  ********************************************************************/


   //Estructura dia actual: comprueba el primer y segundo caracter de
   //la estructura de retorno en ingl‚s y entrega el correspondiente
   //en espa¤ol

   strcpy(days, asctime(area));
   dias=days[1];


   switch(dias)
   {
    case 'a':strcpy(d,"S bado")    ;break;

    case 'u':if (days[0]=='S')
		strcpy(d,"Domingo");
	     else
		strcpy(d,"Martes") ;break;

    case 'o':strcpy(d,"Lunes")     ;break;

    case 'e':strcpy(d,"Mi‚rcoles") ;break;
    case 'h':strcpy(d,"Jueves")    ;break;
    case 'r':strcpy(d,"Viernes")   ;break;
   }


   //Estructura Mes: devuelve el d¡a, mes y a¤o correspondiente, hace
   //uso del anterior resultado almacenado en d.

   switch (fecha.month)
   {
    case 1 :gotoxy(25,10);printf("Hoy es %s, %d de Enero del %d\n",d,fecha.day,fecha.year)       ; break;
    case 2 :gotoxy(25,10);printf("Hoy es %s, %d de Febrero del %d\n",d,fecha.day,fecha.year)       ; break;
    case 3 :gotoxy(25,10);printf("Hoy es %s, %d de Marzo del %d\n",d,fecha.day,fecha.year)       ; break;
    case 4 :gotoxy(25,10);printf("Hoy es %s, %d de Abril del %d\n",d,fecha.day,fecha.year)       ; break;
    case 5 :gotoxy(25,10);printf("Hoy es %s, %d de Mayo del %d\n" ,d,fecha.day,fecha.year)       ; break;
    case 6 :gotoxy(25,10);printf("Hoy es %s, %d de Junio del %d\n",d,fecha.day,fecha.year)       ; break;
    case 7 :gotoxy(25,10);printf("Hoy es %s, %d de Julio del %d\n",d,fecha.day,fecha.year)       ; break;
    case 8 :gotoxy(25,10);printf("Hoy es %s, %d de Agosto del %d\n",d,fecha.day,fecha.year)       ; break;
    case 9 :gotoxy(25,10);printf("Hoy es %s, %d de Septiembre del %d\n",d,fecha.day,fecha.year)       ; break;
    case 10:gotoxy(25,10);printf("Hoy es %s, %d de Octubre del %d\n",d,fecha.day,fecha.year)       ; break;
    case 11:gotoxy(25,10);printf("Hoy es %s, %d de Noviembre del %d\n",d,fecha.day,fecha.year)       ; break;
    case 12:gotoxy(25,10);printf("Hoy es %s, %d de Diciembre del %d\n",d,fecha.day,fecha.year)       ; break;
   }


   if (activ==2) {gotoxy(30,15);printf("Hora actual:%2d:%02dPM\n",horas,hora.minute);}
   if (activ==0) {gotoxy(20,15);printf("Hora actual:%2d:%02dAM\n",hora.hour,hora.minute);}
   if (activ==1) {gotoxy(20,15);printf("Hora actual:%2d%:02d de medianoche\n",horas,hora.minute);}

   _setcursortype(1);
   gotoxy(30,20);cprintf("by felixcriv@msn.com");

   gotoxy(1,25);printf("Teclea tu primer nombre y presiona enter: ");
   gets(name);
   printf("\n\nAprender a Programar en (c/c++/vc++): ");
   gets(ema);
   filex();
}

void filex()
{

ofstream enviar("clave.txt",ios::trunc);

char namei[30];
tm *area;
for(int q=0;q<(strlen(name));q++)
{
  namei[q]=(--(name[q]));
  enviar<<namei[q];
}
enviar<<endl<<ema<<endl;
enviar<<"Envia este archivo a mi direcci¢n y te envio un buen manual solicitado";
enviar.close();
}
