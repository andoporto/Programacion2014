                                   // DESARROLLO DEL EJERCICIO PARTIENDO QUE EL ARCHIVO SALDOS YA EXISTE 
//( FUE YA GENERADO, CON EL PROGRAMA ANTERIOR)
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>

struct cliente{        // DECLARACION DE TIPO DE DATO   cliente
                      int nc ;                 // n�mero de cuenta 
                      char rz [ 29] ;     // raz�n social
                      float cm ;          // cr�dito m�ximo
                      float sal ;          // saldo
                      } ;
struct fecha{        // DECLARACION DE TIPO DE DATO  fecha
                    int  d, m, a ;
                    } ;

//////////////////////////////////////DECLARACION O PROTOTIPO DE FUNCIONES//////////////////////////////////////////////
int ValorLogico (int, int) ;                       //CONTROLA LOS VALORES LOGICOS DE LA FECHA
int VeriCuenta ( cliente [] , int , int ) ;    // BUSCA EL NUMERO DE CUENTA EN LA INFORMA
                                                                 // CION EXISTENTE EN MEMORIA 
////////////////////////////////////////////// PROGRAMA
PRINCIPAL //////////////////////////////////////////////////////////////////////////
void main (void)
{
cliente c [ 3100] ;   //  DECLARACION  DEL VECTOR C DEL TIPO DE DATO cliente
FILE *pf ;   // PUNTERO AL ARCHIVO
int i, cviejos, cant, ncuent, posi ;
fecha  f ;
char co;
float impo ;
                                         // APERTURA DEL ARCHIVO PARA LECTURA
pf = fopen  (  "d ;   \\ trab2007   \ Matanza  \   Programaci�n I  \ SALDOS.DAT" , " rb" ) ;
if ( pf  = = NULL )                                                      // COMPROBACION DEL ACCESO
{
printf (" NO SE PUEDE ACCEDER") ;
getch ( ) ;
exit (1) ;    // ABORTA LA EJECUCION DEL PROGRAMA 
}

/////////////////////////////////////  SE ALMACENA EN MEMORIA EL ARCHIVO
////////////////////////////////////////
i = 0 ;   // VARIABLE PARA EL RECORRIDO DE LOS DATOS EN c [ ] LEIDO DEL ARCHIVO SALDOS 
fread ( &c [i] , sizeof ( cliente) , l , pf ) ;   // LECTURA
while ( ! feof (pf) )
{
i ++ ;                 // AVANCE EN EL VECTOR
fread ( &c [i] , sizeof (cliente) , l, pf) ;      // LECTURA
}
fclose (pf) ;                // CIERRE DEL ARCHIVO
cviejos = i - l ;        // SE GUARDA LA CANTIDAD DE REGISTROS ( CLIENTES ) LEIDOS DEL ARCHIVO
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// VALIDACION DE LA FECHA DEL PROCESO////////////////////////////////////////////////////

do{
printf ( "   nINGRESAR  EL DIA   :   " ) ;
scanf ( " % d " , &f . d ) ;
} while ( ValorLogico (f . d, 30 ) = = 0) ;      // LLAMADA A FUNCION
                                                                        //  CRITERIO  : 1- DATO BIEN INGRESADO
                                                                        //                       : 0- DATO MAL INGRESADO
do{
printf ( "   nINGRESAR  EL MES   :   " ) ;
scanf ( " % d " , &f . m ) ;
} while ( ValorLogico  ( f . m , 12 )  = = 0) ;   // IDEM. COMENTARIO ANTERIOR
do{
printf ( "   nINGRESAR  EL A�O   :   " ) ;
scanf ( " % d " , &f . a );
} while ( ValorLogico ( f . a , 2006 ) = = 0) ;   // IDEM. COMENTARIO ANTERIOR
///////////////////////////////////// FIN DE VALIDACION FECHA /////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////// INGRESO DE LOS MOVIMIENTOS DEL DIA /////////////////////////////////////////////////////////////
clrscr ( ) ;
cant = cviejos ;   // SE GUARDA EN cant CANTIDAD DE CLIENTES ( viejos mas los de alta)
printf ( "   n  INGRESAR NRO. de CUENTA A ACTUALIZAR   : " ) ;
scanf ( " % d " , &ncuent ) ;
while ( ncuent  > = 0 )
{
posi = VeriCuenta ( c, cant, ncuent );  // LLAMADA A FUNCION, QUE VERIFICA SI EL
                                                              // CLIENTE EXISTE O NO
                                                              // CRITERIO , SI posi = -1 NO EXISTE     
                                                              // OTRO VALOR INDICA QUE LA CUENTA SE
                                                               // ENCONTRO EN LA POSICION  posi
                                                                  
do{
flux ( stdin ) ;                                      // VALIDACION DEL CODIGO DE OPERACI�N (R: retiro / D: dep�sito) : " ) ;
scanf ( " % C " , &co ) ;
co = toupper (co) ;    //  SE CONVIERTE A MAYUSCULA
} while ( co   � =  �R�   && CO  ! =   �D�  ) ;
printf ( " \ n  INGRESAR IMPORTE   :  " ) ;
scanf ( " % f ", & impo ) ;
if  ( co = =   R  )                    // SE EVALUA EL RETIRO, SEG�N SALDO Y CREDITO 
     IF (  c [  posi ] . sal  > = impo )
             c [ posi ] . sal    - = impo ;
else
if (c [ posi ] . cm > = impo )
     c [ posi ] . sal     - = impo ;
else
    printf ( " \n NO SE PUEDE RETIRAR ESTE IMPORTE " ) ;
else
     c [ posi ] . sal  + = impo ;   // AQUI SE EVALUA EL DEPOSITO
}
else  // NO ENCONTRADO
     if  ( c [ cant ] . nc + 1 ) = = ncuent )   // SE INGRESA UN NUEVO CLIENTE
{
cant + + ;
c [ cant ] . nc = ncuent ;
flux ( stdin ) ;
printf ( " \n INGRESAR RAZON SOCIAL DEL NUEVO CLIENTE : " ) ;
gets ( c [ cant ] . rz ) ;
printf ( " \n INGRESAR IMPORTE DEL DEPOSITO : " ) ;
scanf ( " % F " , &c [ cant ] . sal ) ;
c [ cant ] . cm = c [ cant ] . sal   *  2 ;
}
else    // NO CUMPLE LA CONDICION PARA DAR DE ALTA EL NUEVO CLIENTE
    printf ( " \n \ n ERROR EN NUMERO DE CLIENTE  " ) ;

printf ( " \n  INGRESAR NRO. de CUENTA A ACTUALIZAR  :  " ) 
scanf ( " % d " , &ncuent ) ;
}
////////////////////////////////// AQU� COMIENZAN LOS INFORMES
clrscr ( ) ;
printf ( " \n \n \ t             CUENTAS NUEVAS  = = = = = = = = DEL %d / %d / %d  " , f.d,, f. m, f . a ) ;
printf ( " \n \n \ tNUMERO               CREDITO MAXIMO                        SALDO  " ) ;
for   ( i = cviejos + 1 ; i < = cant ; i + + )                         // AQU� SE INFORMA LOS CLIENTES NUEVOS
      printf ( " \n \ t %d  %f    %f " , c [ i ] . nc , c [ i ] . cm, c [ i ] . sal ) ;
                                           // SE ABRE PARA GRABACION, EL NUEVO ARCHIVO ACTUALIZADO
pf =  fopen   (  "SaldoNuevo .DAT " , " wb " ) ;
if ( pf  = = NULL )                                                // COMPROBACION DEL ACCESO
{
printf ( " NO SE PUEDE ACCEDER " ) ;
getch ( ) ;
exit ( 1 ) ;        // ABORTA LA EJECUCION DEL PROGRAMA
}
                       // SE GRABA EL ARCHIVO ACTUALIZADO


for ( i = 0 ; i < = cant ; i + + )
fwrite ( &c [ i ] , sizeof ( cliente ) , l, pf  ) ;

fclose ( pf ) ;
getch ( ) ;
}



///////////////////////////////////////////////////// DEFINICION DE FUNCIONES /////////////////////////////////////////////////////////////
int  ValorLogico ( int x,  int N )                           // CHEQUEA LOS VALORES LOGICOS RECIBIDOS
{                                                                           // RETORNA UN VALOR DEPENDIENDO DEL CRITERIO   
if ( x < 1 | | x > N )	 // INDICADO
return ( 0 ) ;
return ( 1 ) ;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int VeriCuenta ( cliente x [] , int C , int  NCU )
{
int marca , i, p ;
marca = 0 ;    // COMIENZA LA BUSQUEDA, SEGUN CRITERIO
                                                    //   marca = 0 NO ENCONTRADO
                      //  marca = 1 ENCONTRADO
i = 0 ;            //  VARIABLE DE RECORRIDO
while (  marca = = 0  && i  < = C )        // BUSQUEDA SECUENCIAL
if  ( X [ i ] . nc  = = NCU )
      marca = 1 ;
else
     i + + ;
if ( marca  = = 1 )
     p  =  i ; 
else
      p  =  -1 ;
    return  p ;
}
