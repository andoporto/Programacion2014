#include <graphics.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <dos.h>
#define PI 3.14               //  <------Valor de PI
int opc;
struct Nota
{
	char nota;
	int tiempo;
	int espacio;
};


//***************************************************************************
			      //Funcion para iniciar graficos
void Inicia_Graf(void)
{
   int gdriver = DETECT, gmode, errorcode;
   initgraph(&gdriver, &gmode, "C:\\BC31\bgi");
   errorcode = graphresult();
   if (errorcode != grOk)
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
   }
}

//***************************************************************************
		       // Funcion de la pantalla de presentacion

void Presentacion(int in_out)
{
   int i,x,y;
   Inicia_Graf();
   setbkcolor(1);
//______________________________________________________
			       // Colores de la pantalla

   for(x=1; x<=getmaxx(); x++)
    for(y=(getmaxy()/6)*2; y<=(getmaxy()/6)*4; y++)
     putpixel(x,y,58);
   for(x=1; x<=getmaxx(); x++)
   {
      putpixel(x,1,58);
      putpixel(x,getmaxy(),58);
   }
   for(y=1; y<=getmaxy(); y++)
   {
      putpixel(1,y,58);
      putpixel(getmaxx(),y,58);
   }
//__________________________________________________
			      // Textos

   settextstyle(1,0,7);
    settextjustify(2,0);
    setcolor(58);
    outtextxy((getmaxx()/6)*5.5,getmaxy()/7,"P R O Y E C T O");

   settextstyle(4,0,2);
    settextjustify(0,0);
    setcolor(60);
    outtextxy((getmaxx()/6)*5,getmaxy()/5,"XP...u¤al");

   settextstyle(2,0,8);
    settextjustify(1,0);
    setcolor(9);
    outtextxy(getmaxx()/2,(getmaxy()/4)*3,"P r o d u c i d o   p o r :");

   settextstyle(1,0,3);
    settextjustify(1,0);
    setcolor(15);
    outtextxy(getmaxx()/2,getmaxy()-50,"SOFTWARE PATITO");

   if(in_out == 1)
   {
      settextstyle(7,0,3);
       settextjustify(1,1);
       setcolor(20);
       outtextxy(getmaxx()/2,getmaxy()/4,"Bienvenidos");

      settextstyle(10,0,1);
       settextjustify(1,0);
       setcolor(0);
       outtextxy(getmaxx()/2,getmaxy()/2,"CARGANDO ARCHIVOS");
   }
   else if(in_out == 2)
   {
      settextstyle(7,0,3);
       settextjustify(1,1);
       setcolor(20);
       outtextxy(getmaxx()/2,getmaxy()/4,"Hasta la vista");

      settextstyle(10,0,1);
       settextjustify(1,0);
       setcolor(0);
       outtextxy(getmaxx()/2,getmaxy()/2,"CERRANDO ARCHIVOS");
   }

//____________________________________________________
			     // Rectangulo de carga

   setcolor(3);
   rectangle(getmaxx()/4,(getmaxy()/2)+45,(getmaxx()/4)*3,(getmaxy()/2)+55);
   for(x=(getmaxx()/4)+1; x<(getmaxx()/4)*3; x++)
    for(y=(getmaxy()/2)+46; y<(getmaxy()/2)+55; y++)
     putpixel(x,y,14);

   for(x=(getmaxx()/4)+1; x<(getmaxx()/4)*3; x++)
    {
    for(y=(getmaxy()/2)+46; y<(getmaxy()/2)+55; y++)
     putpixel(x,y,9);
    randomize();
    delay(random(60));
    }
//__________________________________________________
			     //Fin
   closegraph();
}


//***************************************************************************
			  //Funcion para desplegar el menu
void Menu(void)
{
   int x;
   clrscr();
   for(x=1; x<=80; x++)
    {
      gotoxy(x,1);
      printf("=");
      gotoxy(x,24);
      printf("=");
      gotoxy(x,3);
      printf("=");
    }
   gotoxy(30,2);
    printf("P R O Y E C T O   x p ");
   gotoxy(2,6);
    printf("*Modo de Texto (n£meros complejos)");
   gotoxy(4,8);
    printf("1.Suma/Resta");
   gotoxy(4,9);
    printf("2.Multiplicacion");
   gotoxy(4,10);
    printf("3.Division");
   gotoxy(2,12);
    printf("*Modo Gr fico");
   gotoxy(4,14);
    printf("4.Funci¢n Seno");
   gotoxy(4,15);
    printf("5.Funci¢n Coseno");
   gotoxy(4,16);
    printf("6.Funci¢n Tangente");
   gotoxy(4,17);
    printf("7.Funci¢n Cosecante");
   gotoxy(4,18);
    printf("8.Funci¢n Secante");
   gotoxy(4,19);
    printf("9.Funcion Cotangente");
   gotoxy(4,20);
    printf("10.Ver Dibujo");
   gotoxy(4,22);
    printf("11.Salir");
   gotoxy(2,4);
    printf("Ingresa a continuaci¢n el n£mero de la opci¢n que eligas: ");
    _setcursortype(_SOLIDCURSOR);
   scanf("%d",&opc);
}
//***************************************************************************
			    // Funcion Suma y Resta
void Suma_Resta(void)
{
   int x,real1,real2,img1,img2;
   float real_suma,img_suma,real_resta,img_resta;
   clrscr();
   for(x=1; x<=80; x++)
    {
      gotoxy(x,1);
      printf("=");
      gotoxy(x,24);
      printf("=");
      gotoxy(x,3);
      printf("=");
    }
   gotoxy(35,2);
    printf("Suma y Resta ");
   gotoxy(2,4);
    printf("Ingresa a continuaci¢n los valores que se te piden:");
    _setcursortype(_SOLIDCURSOR);
   gotoxy(2,6);
    printf("El valor real del primer n£mero: ");
    scanf("%d",&real1);
   gotoxy(2,7);
    printf("El valor imaginario del primer n£mero: ");
    scanf("%d",&img1);
   gotoxy(2,8);
    printf("El valor real del segundo n£mero: ");
    scanf("%d",&real2);
   gotoxy(2,9);
    printf("El valor imaginario del segundo n£mero: ");
    scanf("%d",&img2);

   real_suma= real1 + real2;
   img_suma= img1 + img2;
   real_resta= real1 - real2;
   img_resta= img1 - img2;

   gotoxy(2,11);
    printf("Los resultados son:");
   gotoxy(4,13);
    printf("(%d + %d) + (%d + %d) == (%1.1f + %1.1f)",
	    real1,img1,real2,img2,real_suma,img_suma);
   gotoxy(4,15);
    printf("(%d + %d) - (%d + %d) == (%1.1f + %1.1f",
	    real1,img1,real2,img2,real_resta,img_resta);
   getch();
}
//***************************************************************************
			     //Funcion Multiplicacion
void Multiplica(void)
{
   int x,real1,real2,img1,img2;
   float real_mult,img_mult;
   clrscr();
   for(x=1; x<=80; x++)
    {
      gotoxy(x,1);
      printf("=");
      gotoxy(x,24);
      printf("=");
      gotoxy(x,3);
      printf("=");
    }
   gotoxy(35,2);
    printf("Multiplicaci¢n");
   gotoxy(2,4);
    printf("Ingresa a continuaci¢n los valores que se te piden:");
    _setcursortype(_SOLIDCURSOR);
   gotoxy(2,6);
    printf("El valor real del primer n£mero: ");
    scanf("%d",&real1);
   gotoxy(2,7);
    printf("El valor imaginario del primer n£mero: ");
    scanf("%d",&img1);
   gotoxy(2,8);
    printf("El valor real del segundo n£mero: ");
    scanf("%d",&real2);
   gotoxy(2,9);
    printf("El valor imaginario del segundo n£mero: ");
    scanf("%d",&img2);

   real_mult = (real1 * real2) - (img1*img2);
   img_mult = (img1 * real2) + (real1 * img2);

   gotoxy(2,11);
    printf("Los resultados son:");
   gotoxy(4,13);
    printf("(%d + %d) * (%d + %d) ==",real1,img1,real2,img2);
   gotoxy(4,15);
    printf("((%d * %d) - (%d * %d)) + ((%d * %d) + ((%d * %d)) ==",
	    real1,real2,img1,img2,img1,real2,real1,img2);
   gotoxy(6,17);
    printf("(%1.1f + %1.1f)",real_mult,img_mult);
   getch();
}
//***************************************************************************
			      // Funcion Division
void Division(void)
{
   int x,real1,real2,img1,img2;
   float real_div,img_div;
   clrscr();
   for(x=1; x<=80; x++)
    {
      gotoxy(x,1);
      printf("=");
      gotoxy(x,24);
      printf("=");
      gotoxy(x,3);
      printf("=");
    }
   gotoxy(35,2);
    printf("Divisi¢n");
   gotoxy(2,4);
    printf("Ingresa a continuaci¢n los valores que se te piden:");
    _setcursortype(_SOLIDCURSOR);
   gotoxy(2,6);
    printf("El valor real del primer n£mero: ");
    scanf("%d",&real1);
   gotoxy(2,7);
    printf("El valor imaginario del primer n£mero: ");
    scanf("%d",&img1);
   gotoxy(2,8);
    printf("El valor real del segundo n£mero: ");
    scanf("%d",&real2);
   gotoxy(2,9);
    printf("El valor imaginario del segundo n£mero: ");
    scanf("%d",&img2);

   real_div =
     (((real1 * real2) + (img1 * img2))*.1) /
     (((real2 * real2) + (img2 * img2))*.1);
   img_div =
     (((img1 * real2) - (real1 * img2))*.1) /
     (((real2 * real2) + (img2 * img2))*.1);

   gotoxy(2,11);
    printf("Los resultados son:");
   gotoxy(4,13);
    printf("(%d + %d) / (%d + %d) == ",real1,img1,real2,img2);
    printf("(%f + %f)",real_div,img_div);
   getch();
}

//***************************************************************************
			  // Funcion para dibujar el plano

			  // De esta funcion solo interesa
			  // los ejes y sus escalas, lo demas
			  // es pura mamada

void Plano(int letrero)
{
    int x,y;
    setbkcolor(56);

    //--------------- ESCRIBE EL NOMBRE CORRESPONDIENTE-----------

    for(x=(getmaxx()/2)-70; x<=(getmaxx()/2)+70; x++)
     for(y=1; y<=25; y++)
      putpixel(x,y,58);

    setcolor(3);
     settextjustify(1,0);
     settextstyle(1,0,2);
    switch(letrero)
    {
       case 1: outtextxy(getmaxx()/2,24,"SENO");       break;
       case 2: outtextxy(getmaxx()/2,24,"COSENO");     break;
       case 3: outtextxy(getmaxx()/2,24,"TANGENTE");   break;
       case 4: outtextxy(getmaxx()/2,24,"COSECANTE");    break;
       case 5: outtextxy(getmaxx()/2,24,"SECANTE");  break;
       case 6: outtextxy(getmaxx()/2,24,"COTANGENTE"); break;
    }

    //------------------- DIBUJA LOS EJES DEL PLANO----------
    setcolor(15); //color
     setlinestyle(0,1,1); //tipo de linea , no se , espesor
     line(1,getmaxy()/2,getmaxx(),getmaxy()/2);
     // de (1,mitad) a (maximo,mitad)----> linea horizontal
     line(10,1,10,getmaxy());
     // de (10,1) a (10,maximo)-----> linea vertical

    //------------------- DIBUJA LOS BORDES DE LA PANTALLA---
    setcolor(58);
     setlinestyle(0,1,0);
     line(0,0,0,getmaxy());
     line(0,0,getmaxx(),0);
     line(0,getmaxy(),getmaxx(),getmaxy());
     line(getmaxx(),0,getmaxx(),getmaxy());

     //------------------- ESCRIBE LA ESCALA DEL PLANO--------

     //----------------------EJE Y--------------------
     //Solo voy a explicar la linea de .5

     setcolor(15); //color
      settextjustify(0,1); //justificacion
      settextstyle(2,0,4); //tipo de letra ,  no se , tama¤o

     //---------------------.5
     //El valor maximo de seno es 1. Cuando grafico, multiplico el seno por
     //100. Eso quire decir que mi valor maximo en pixeles es 100. Como en
     //este ejemplo vamos a poner .5 , pues utilizo 50 pixeles
     y=(getmaxy()/2) - 50;
     // y es igual a la mitad menos 50
     // x va a ser muy variado dependiendo de que es lo que ponga.
      setlinestyle(0,1,1);
      //tipo de linea
	line( 10 , y , 15 , y );
	// Esta linea va a ser muy chica. Solo indica donde va a caer el
	//numero .5 en el eje.
      setlinestyle(4,1,1);
	//tipo de linea
	line(50 , y ,getmaxx(), y );
	// Esta linea corre a travez de la pantaya a la altura del valor
	//de .5
      outtextxy(20,y,".5");
      // Despliega un .5
      //Esto va a quedar asi:
      // |- .5 ---------...hasta el final de la pantalla.
      // (Se supone que esta linea horizontal es el eje y)

     //--------------------- 1
     y=(getmaxy()/2) - 100;
      setlinestyle(0,1,1);
	line( 10 , y , 15 , y );
      setlinestyle(4,1,1);
	line(50 , y ,getmaxx(), y );
      outtextxy(20,y,"1");
     //--------------------- 1.5
     y=(getmaxy()/2) - 150;
      setlinestyle(0,1,1);
	line( 10 , y , 15 , y );
      setlinestyle(4,1,1);
	line(50 , y ,getmaxx(), y );
      outtextxy(20,y,"1.5");
     //--------------------- 2
     y=(getmaxy()/2) - 200;
      setlinestyle(0,1,1);
	line( 10 , y , 15 , y );
      setlinestyle(4,1,1);
	line( 50 , y ,getmaxx(), y );
      outtextxy(20,y,"2");
     //--------------------- -.5
     y=(getmaxy()/2) + 50;
      setlinestyle(0,1,1);
	line( 10 , y , 15 , y );
      setlinestyle(4,1,1);
	line(50 , y ,getmaxx(), y );
      outtextxy(20,y,"-.5");
     //--------------------- -1
     y=(getmaxy()/2) + 100;
      setlinestyle(0,1,1);
	line( 10 , y , 15 , y );
      setlinestyle(4,1,1);
	line(50 , y ,getmaxx(), y );
      outtextxy(20,y,"-1");
     //--------------------- -1.5
     y=(getmaxy()/2) + 150;
      setlinestyle(0,1,1);
	line( 10 , y , 15 , y );
      setlinestyle(4,1,1);
	line(50 , y ,getmaxx(), y );
      outtextxy(20,y,"-1.5");
     //--------------------- -2
     y=(getmaxy()/2) + 200;
      setlinestyle(0,1,1);
	line( 10 , y , 15 , y );
      setlinestyle(4,1,1);
	line(50 , y ,getmaxx(), y );
      outtextxy(20,y,"-2");

      //------------------------EJE X----------------
      //Solo voy a explicar 1PI

     setcolor(15);
      settextjustify(1,0);
      settextstyle(2,0,4);

     //----------------------- 1 pi
     // En el grafico x va aumentando de 1 en 1 tantas veces como el
     // valor de teta aumente de .01 en .01 hasta llegar a 2PI, osea 6.2.
     // Esto quiere decir que el valor maximo de x en la grafica es 620,
     // osea 2PI*100. Se le suma 10, porque el conteo de x en la grafica no
     // empieza en 0 si no en 10.
     x=(PI*100)+10;
     y=getmaxy()/2;
      setlinestyle(0,1,1);
	line( x , y , x , y-5 );
	// Esta dibuja una peque¤a linea para indicar en donde cae el valor
	// PI en el eje x.
      setlinestyle(1,1,1);
	line(x , y-20 , x , 25 );
	// Esta linea dibuja el recorrido de PI a travez de la pantalla desde
	// la mitad hasta arriba.
	// Inica en mitad-20 para no tapar el numero. Llega hasta 25 para no
	// tapar la barra donde dice "seno".
	line(x , y , x , y*2);
	// Esta linea dibuja el recorrido de PI a travez de la pantalla desde
	// la mitad hasta abajo.
	// Inicia en la mitad y llega hasta el maximo.
      outtextxy(x,y-10,"Pi");
     //----------------------- 1/2 pi
     x=((PI*100)+10)/2;
     y=getmaxy()/2;
      setlinestyle(0,1,1);
	line( x , y , x , y-5 );
      setlinestyle(1,1,1);
	line(x , y-20 , x , 0 );
	line(x , y , x , y*2);
      outtextxy(x,y-10,"1/2 Pi");
     //----------------------- 3/2 pi
     x=(((PI*100)+10)/2)*3;
     y=getmaxy()/2;
      setlinestyle(0,1,1);
	line( x , y , x , y-5 );
      setlinestyle(1,1,1);
	line(x , y-20 , x , 0 );
	line(x , y , x , y*2);
      outtextxy(x,y-10,"3/2 Pi");

}
//***************************************************************************
		     // Funcion para dibujar las graficas

		     // Solo explico la funcion seno; las
		     // demas son las mismas.


void Funciones(int funcion)
{
   Inicia_Graf();
   float teta;        //<------- Inicai en .01  hasta   PI*2 osea(6.2)
   int y,x;           //<------- Valores x,y para la grafica

   switch(funcion)
   {
      case 1: //---------------------SENO---------------
	 for(teta=0.01,x=10; teta<=PI*2; teta=teta+.01)
	  {
	  y=getmaxy()/2 + ( sin(teta) * (-100) );
	  // Multiplico el seno de teta por -100 para: 1.- aumentar el valor
	  // del seno. 2.- hacer que nuestro valor sea negativo para que se
	  // le reste al valor de la mitad de la pantalla.
	  putpixel(x,y,57);
	  // x va a ser igual a 10,11,12...2PI+10.
	  // y va a ser igual a el valor de sin(teta) aumentado cien veces.
	  x++;
	  // x va a aumentar de uno en uno
	  // obviamente y va a aumentar en funcion de teta
	  }
	 Plano(funcion);
      break;
      case 2: //---------------------COSENO-------------
	 for(teta=0.01,x=10; teta<=PI*2; teta=teta+.01){
	  y=getmaxy()/2 + ( cos(teta) * (-100) );
	  putpixel(x,y,57); x++;                    }
	 Plano(funcion);
      break;
      case 3: //-------------------TANGENTE-------------
	 for(teta=0.01,x=10; teta<=PI*2; teta=teta+.01){
	  y=getmaxy()/2 + ( tan(teta) * (-100) );
	  putpixel(x,y,57); x++;                    }
	 Plano(funcion);
      break;
      case 4: //------------------COSECANTE---------------
	 for(teta=0.01,x=10; teta<=PI*2; teta=teta+.01){
	  y=getmaxy()/2 + ( (1/sin(teta)) * (-100) );
	  putpixel(x,y,57); x++;                    }
	 Plano(funcion);
      break;
      case 5: //------------------SECANTE-------------
	 for(teta=0.01,x=10; teta<=PI*2; teta=teta+.01){
	  y=getmaxy()/2 + ( (1/cos(teta)) * (-100) );
	  putpixel(x,y,57); x++;                    }
	 Plano(funcion);
      break;
      case 6: //------------------COTANGENTE------------
	 for(teta=0.01,x=10; teta<=PI*2; teta=teta+.01){
	  y=getmaxy()/2 + ( (1/tan(teta)) * (-100) );
	  putpixel(x,y,57); x++;                    }
	 Plano(funcion);
      break;
   }
   getch();
   closegraph();
}

//**************************************************************************
//                            Funciones para el dibujo
//**************************************************************************

void ojos(void)    // O J O S
{
   setfillstyle(SOLID_FILL,8);  //color//
   fillellipse(256,210,18,24);
   fillellipse(380,210,18,24);
}

void anima(void)
{
   int x,y;
   for(y=186; y<=208; y++)
    for(x=238; x<=274 ; x++)
     {
     putpixel(x,y,getmaxcolor());
     putpixel(x+124,y,getmaxcolor());
     }
    for(x=238; x<=274 ; x++)
     for(y=234; y>=212; y--)
     {
     putpixel(x,y,getmaxcolor());
     putpixel(x+124,y,getmaxcolor());
     }
  sound(600);
  delay(100);
  sound(1100);
  delay(100);
  sound(900);
  delay(50);
  nosound();
}
void texto(void)   // T E X T O
{
   int x,y,i=100;
   for(x=10; x<450; x=x+210)
    for(y=10; y<480; y=y+30)
      {
      sound(i);
      if(x>10&&x<400&&y>350)y=490;
      settextjustify(LEFT_TEXT, CENTER_TEXT);
      settextstyle(7, HORIZ_DIR, 1);
      setcolor(56);
      outtextxy(x,y,"H e l l o K i t t i e");
      delay(80);
      i=i+50;
      }
   nosound();
}

void cara(void)    // C A R A
{
   setcolor(WHITE);
   setfillstyle(XHATCH_FILL,13); //color//
   sector(getmaxx()/2.0,getmaxy()/1.3,359.99,180,45,45);  //cuello
   setfillstyle(SOLID_FILL,15); //color//
   fillellipse(getmaxx()/2,getmaxy()/2,180,140);//cara
   sector(getmaxx()/2.85,getmaxy()/2.75,38,195,80,120); //oreja1
   sector(getmaxx()/1.565,getmaxy()/2.5,0,142,81,138); //oreja2
   setfillstyle(SOLID_FILL,14); //color
   fillellipse(getmaxx()/2,getmaxy()/1.85,24,18); //nariz
}

void bigotes(void)     // B I G O T E S
{
   setfillstyle(SOLID_FILL,8); //color
   sector(getmaxx()/7.70,getmaxy()/2,359.99,353,105,48); //bigote1
   sector(getmaxx()/7.25,getmaxy()/1.75,359.99,355,105,58); //bigote1
   sector(getmaxx()/6.65,getmaxy()/1.55,359.99,354,105,58); //bigote1
   sector(getmaxx()/1.49,getmaxy()/2,0,5.9,115,68); //bigote2
   sector(getmaxx()/1.55,getmaxy()/1.75,0,5.9,115,68); //bigote2
   sector(getmaxx()/1.61,getmaxy()/1.55,1,5.9,115,68); //bigote2
}

void cuerpo(void)     // C U E R P O
{
   setfillstyle(XHATCH_FILL,13); //color
   pieslice(getmaxx()/1.55,getmaxy()/3.95,110,190,90);   //mo¤o1
   pieslice(getmaxx()/1.55,getmaxy()/4.2,359.99,289,95);   //mo¤o2
   fillellipse(getmaxx()/1.55,getmaxy()/3.95,20,20);//mo¤o
   sector(getmaxx()/2.60,getmaxy()/1,80,180,105,107); //manga1
   sector(getmaxx()/1.65,getmaxy()/1,0,95,105,107); //manga2
   fillellipse((getmaxx()/2),getmaxy()-35,8,8);//flor
   fillellipse((getmaxx()/2),getmaxy()-5,8,8);//flor
}

//***************************************************************************
//***************************************************************************
//         DE AQUI EN ADELANTE EL CODIGO ES DE OTRA PERSONA:

//******* Programa hecho por Raul Marmolejo ********
//*******  	  rm3 kReAtIoNz             ********
//*******      www.raul.marmolejo.net       ********
//*******     raulgerardo@marmolejo.net     ********


//*********NOTAS*********

#define doo				515
#define re				580
#define mi				650
#define fa				685
#define sol				780
#define sols			838
#define la				870
#define si				995
#define DO				1045
#define RE				1162
#define MI				1300
#define FA				1385

//*******TIEMPOS*********

#define Redonda		2000
#define Blanca			1000
#define Negra			500
#define Corchea		250
#define Semicorchea	125

//********OTROS**********

#define Espacio		100

void tocar(Nota &N)
{
	int sonido,time;
	if(!kbhit()){
		switch(N.nota){
			case	'c'	:sonido = doo 	;break;
			case	'd'	:sonido = re 	;break;
			case	'e'	:sonido = mi 	;break;
			case	'f'	:sonido = fa 	;break;
			case	'g'	:sonido = sol	;break;
			case	'h'   :sonido = sols ;break;
			case	'a'	:sonido = la 	;break;
			case	'b'	:sonido = si 	;break;
			case	'C'	:sonido = DO 	;break;
			case	'D'	:sonido = RE 	;break;
			case	'E'	:sonido = MI 	;break;
			case	'F'	:sonido = FA 	;break;
		}
		switch(N.tiempo){
			case	1	:time = Redonda 	  ;break;
			case	2  :time = Blanca 	  ;break;
			case	3  :time = Negra 		  ;break;
			case	4	:time = Corchea	  ;break;
			case	5  :time = Semicorchea ;break;
		}
		sound(sonido);
		delay(time);
		nosound();
		delay(Espacio);
	}
	else
		nosound();
}

void cancion(void)
{
	Nota Love_History[106]=	{  {'C',4},{'e',4},{'e',4},{'C',4},{'C',2}, {'e',4},{'e',4},{'C',4},{'C',4},{'e',4},{'f',4},{'e',4},{'d',4},
		{'d',4},{'d',4},{'b',4},{'b',2},{'d',4},{'d',4},{'b',4},{'b',4},{'d',4},{'e',4},{'d',4},{'c',4},{'c',4},{'c',4},{'a',4},{'a',2},
		{'c',4},{'c',4},{'a',4},{'a',4},{'c',4},{'d',4},{'c',4},{'b',4},{'b',4},{'b',4},{'h',4},{'h',1},{'a',3},{'b',3},{'f',3},{'e',1},
		{'e',3},{'C',1},{'D',3},{'E',3},{'a',3},{'F',1},{'a',4},{'F',4},{'a',4},{'a',4},{'b',4},{'b',2},{'D',4},{'F',4},{'D',4},{'E',2},
		{'g',4},{'E',4},{'g',4},{'g',4},{'a',4},{'a',2},{'C',4},{'E',4},{'C',4},{'D',2},{'b',4},{'D',4},{'b',4},{'C',2},{'D',4},{'E',4},
		{'a',4},{'C',4},{'E',4},{'F',1},{'g',4},{'a',4},{'C',4},{'C',3},{'b',2},{'b',4},{'C',4},{'D',4},{'f',4},{'e',2},{'e',4},{'f',4},
		{'g',4},{'b',3},{'a',2},{'a',3},{'f',4},{'e',4},{'h',2},{'h',4},{'b',4},{'h',4},{'a',2},{'g',3},{'a',1}};
	for(int i=0;i<45;i++)
		tocar(Love_History[i]);      //1ra parte
	for(i=0;i<43;i++)
		tocar(Love_History[i]);      //2da parte
	for(i=45;i<104;i++)
		tocar(Love_History[i]);      //3ra parte
	for(i=0;i<43;i++)
		tocar(Love_History[i]);      //1ra parte
	for(i=104;i<106;i++)
		tocar(Love_History[i]);      //4ta parte

}
//**************************************************************************
//                     Termina el codigo de Raul
//**************************************************************************

void Kitti(void)
{
   Inicia_Graf();
   setbkcolor(9);
   texto();
   cara();
   bigotes();
   cuerpo();
   cancion();
   getch();
   ojos();
   while (!kbhit())
   {
   ojos(); delay(300);
   anima(); delay(300);
   }
   closegraph();
}


//**************************************************************************
			     // Funcion para el switch
void Opciones(void)
{
      switch(opc)
      {
	 case 1: Suma_Resta(); break;
	 case 2: Multiplica(); break;
	 case 3: Division ();  break;
	 case 4: Funciones(1); break;
	 case 5: Funciones(2); break;
	 case 6: Funciones(3); break;
	 case 7: Funciones(4); break;
	 case 8: Funciones(5); break;
	 case 9: Funciones(6); break;
	 case 10: Kitti();     break;
	 case 11: Presentacion(2); break;
	 default: clrscr(); getch();
      }
}


//***************************************************************************
//********************** AQUI ESTA LA FUNCION PRINCIPAL *********************
//***************************************************************************

void main (void)
{
   Presentacion(1);
   do
   {
      Menu();
      Opciones();
   }while(opc != 11);
}