# include <stdio.h>
# include <conio.h>
# include <stdlib.h>
struct cliente{ // DECLARACI�N DE TIPO DE DATO CLIENTE.
                     int nc;                   // n�mero de cuenta
                     char rz [29];         // raz�n social
                     float cm;              // cr�dito m�ximo
                     float sal;              // saldo
                     } ;
void main (void)
{
struct cliente cl; // cliente cl DECLARACION DE VARIABLE cl DEL TIPO DATO cliente FILE *pf; // PUNTERO AL ARCHIVO.
FILE*pf;                                                       // APERTURA DEL ARCHIVO PARA GRABACI�N.
pf = fopen  ("SALDOS.DAT ","wb") ;
if (pf == NULL)                                // COMPROBACI�N DEL ACCESO.
{
 printf ( " NO SE PUEDE ACCEDER" ) ;
getch ( ) ;        exit (1) ;        }
printf (" \ nINGRESAR NUMERO DE CUENTA  :  " ) ;
scanf ( "%d",&cl . nc) ;
while ( cl .nc)
{
fflush ( stdin) ;
printf ( "  \ nINGRESAR RAZON SOCIAL   :  " ) ;
gets ( cl . rz ) ;
printf ( "  \ nINGRESAR  CREDITO MAXIMO   :  " ) ;
scanf ( " %f ",&cl . cm) ;
printf ( " \  nINGRESAR  SALDO  :  " ) ;
scanf ( " % f " , &cl . sal ) ;
fwrite ( &cl , sizeof ( cliente) ,1, pf ) ;    // GRABACI�N ( DE LOGICA A FISICO)
printf  ( " \  nINGRESAR  NUMERO DE CUENTA  :  " ) ;
scanf  ( " % d " , &cl . nc) ;
}
fclose  (pf) ;       // CIERRE DEL ARCHIVO

// COMPROBACION DE QUE EL ARCHIVO ESTA BIEN GENERADO - LECTURA-
pf = fopen (  "SALDOS . DAT" , " rb" ) ;
if ( pf == NULL)                                // COMPROBACION DEL ACCESO
{
printf ( " NO SE PUEDE ACCEDER " ) ;
getch () ;
exit (1);
}
printf ( "NRO. CUENTA   RAZON SOCIAL  CREDITO MAXIMO   SALDO " ) ;
 fread ( &cl , sizeof (cliente) ,1, pf) ;                 // LECTURA ( FISICO A LOGICA)
while (!feof(pf))                // MIENTRAS NO SEA FIN DE ARCHIVO, SE LEE
{
printf  ("  \ n  %d                  %s     %f    %f " , cl . nc , cl.rz , cl. cm , cl . sal ) ;
fread ( &cl , sizeof ( cliente) , 1, pf ) ;                 // LECTURA ( FISICO LOGICA )
}
fclose ( pf ) ;
getch ( ) ;
}
