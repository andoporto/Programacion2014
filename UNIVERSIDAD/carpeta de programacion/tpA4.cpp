#include <stdio.h>
#include <conio.h>

int val_notas (int a, int b);
char val_tp ();
char FUNCIONCOND (int a, int b, char c);
float FPROM(int a, int b);

void main()
{int NDNI,NDNI1,NDNI2,NPEP,NSEP,NUMAL,CANTPROM,CANTRENDIR,CANTREP,CANTAUS;
char RTP,CONDAL[14],MATER[18];
float PROMALU,PPROMO,MPROM,MPROM1,MPROM2,N1MP1,N2MP1,N1MP2,FPROM,N2MP2;

NUMAL=CANTPROM=CANTRENDIR=CANTREP=CANTAUS=MPROM1=MPROM2=NDNI1=NDNI2=N1MP1=N2MP1=N1MP2=N2MP2=0;

scanf("%c%c",&MATER,&NDNI);
while(NDNI!=0&&NUMAL<=20&&NUMAL>=10)
{
  //{scanf("%c%d%d",&RTP,&NPEP,&NSEP);

 //do
 //CONDAL=FUNCIONCOND(NPEP,NSEP,RTP);
 //while (CONDAL!= )
 if(CONDAL == 'Promociona')
  {CANTPROM++;
   PROMALU = FPROM(NPEP,NSEP);
   	if(PROMALU>MPROM1)
        {MPROM2=MPROM1;
       	NDNI2=NDNI1;
       	N1MP2=N1MP1;
       	N2MP2=N2MP1;
       	MPROM1=PROMALU;
       	NDNI1=NDNI;
       	N1MP1=NPEP;
       	N2MP1=NSEP;
        }
   	else
          	if(PROMALU>MPROM2)
               {
                MPROM2=PROMALU;
                NDNI2=NDNI;
                N1MP2=NPEP;
                N2MP2=NSEP;
               }
    }
 else
    	if(CONDAL='RindeExFinal')
      	{
          CANTRENDIR++;
         }
      else {
            if(CONDAL='Reprobo')
              {
                CANTREP++;
              }
           }
printf("\nAlumno:%d\nPromedio:%f",NDNI,PROMALU);
if(NPEP==0 && NSEP==0)
	CANTAUS++;
NUMAL++;
scanf ("%d",&NDNI);
}
printf("\nCantidad de alumnos que Promocionaron la materia: %d",CANTPROMO);
printf("\nCantidad de alumnos que deben rendir examen final: %d",CANTRENDIR);
printf("\nCantidad de alumnos que reprobaron la materia: %d",CANTREP);
printf("\nCantidad de alumnos ausentes a los examenes: %d",CANTAUS);
printf("\n\nAlumno Primer Mejor Promedio: %d",NDNI1);
printf("\nPromedio: %d",MPROM1);
printf("\nNota 1 obtenida: %d", N1MP1);
printf("\nNota 2 Obtenida: %d", N2MP1);
printf("\n\nAlumno Segundo Mejor Promedio: %d",NDNI2);
printf("\nPromedio: %d",MPROM2);
printf("\nNota 1 obtenida: %d", N1MP2);
printf("\nNota 2 Obtenida: %d", N2MP2);
getch();
}



int val_notas (int a, int b)
{int nota;
  
  do
    {
     printf ("\n Ingrese nota(0 a 10): ")
     scanf("%d",&nota);  
     if (nota<a || nota>b)
       printf ("\n el valor ingresado el erroneo (Reingresar nota)");
     }
  while (nota<a || nota>b);
  return(nota);
}


char val_tp ()
{
 char tp;
 do
   {
    printf("\n Ingrese Resultado de los Trabajos Practico(A/R): ")
    scanf("%c",&tp);
    if (tp != 'a' || tp != 'A' || tp != 'r' || tp != 'R')
      printf ("\n el valor ingresado es errones (Reingresar Resultado)");
 while (tp != 'a' || tp != 'A' || tp != 'r' || tp != 'R );
 Return (tp);
}

char[14] Funcioncond (int a, int b, char c)
{char result[14];

  if (a >= 7 && b >= 7 && c == 'A')
   {result = 'Promociona';
   }
  else
    {
    if (a >= 4 && b >= 4 && c == 'A')
      {result = 'RindeExFinal'
      }
     else 
        result = 'Reprobo';
    }
 return (result);
}

float FProme(int a, int b)
 {float prome;
  prome = (a+b)/2;
  return (prome);
}


