#include<stdio.h>
#include<conio.h>

long exp ( int , int ) ;

int main ()
   { int x, i;
     float expo=0;

     //clrscr();

     printf ( "Ingrese x:\t" ) ;
     scanf ( "%d" , &x ) ;

     printf ( "Ingrese exponente a calcular:\t" ) ;
     scanf ( "%d" , &i ) ;

     expo = exp ( x , i ) ;

     printf ( "%2.0f" , expo ) ;

     getch();
   }


   long exp ( int x , int i )

      {  int j = 0;
         long expo = 1 ;

         if ( i == 0 )

          	expo = 1 ;

         else

         	{ if ( i == 1 )

                 expo = x ;

              else

              	  {
                      while ( j < i )
                         {
                          expo = expo * x ;
                          j++;
                         }
                 }

             }



          return ( expo ) ;

      }
