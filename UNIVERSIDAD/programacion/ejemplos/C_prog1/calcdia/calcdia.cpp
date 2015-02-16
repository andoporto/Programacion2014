#include <assert.h>
#include <stdio.h>
#include <string.h>

char LlegirCaracter(void);
void LlegeixData(int *const any,int *const dia,int *const mes);
void CalculaDia (int any, int dia, int mes,int *const n);
				  
void main(void){
  int dia;
  int mes;
  int any;
  int n;
  int otro;
  LlegeixData (&dia,&mes,&any);
  CalculaDia (dia, mes, any, &n);
  printf ("Quieres conocer que dia era en otra fecha? (1=si 2=no): ");
  scanf ("%d",&otro);

  if (otro==1 || otro==2){
  }else if (otro!=1 && otro!=2){
    while (otro!=1 && otro!=2){
      printf("respuesta erronea, escriba 1 o 2 (1=si 2=no)");
      scanf ("%d",&otro);
    }
  }else assert (0);

  while (otro==1){
    LlegeixData (&dia,&mes,&any);
    CalculaDia (dia, mes, any, &n);
    printf("Quieres conocer que dia era en otra fecha? (1=si 2=no): ");
    scanf("%d",&otro);
    if (otro==1 || otro==2){
    }else if (otro!=1 && otro!=2){
      while (otro!=1 && otro!=2){
	printf("respuesta erronea, escriba 1 o 2 (1=si 2=no)");
	scanf ("%d", &otro);
      }
    }
  }
  printf ("Este programa ha finalizado");
}
  

void LlegeixData (int *const any,int *const dia,int *const mes){
  printf("Escribe el año a estudiar: ");
  scanf("%d",any);
  printf("Escribe el mes a estudiar: ");
  scanf("%d",mes);
  printf("Escribe el dia a estudiar: ");
  scanf("%d",dia);
}


char LlegirCaracter(void){
  return getchar();
}

void CalculaDia (int any,int dia,int mes,int *const n){
  
  int diaref,mesref,anyref;
  diaref=1;
  mesref=1;
  anyref=1996;
  *n=1;
  
  if (any < anyref){
    while (any < anyref){
      anyref=anyref-4;
      *n=(*n)+2;
    }}else if (any > anyref){
      while (any >= anyref+4){
	anyref=anyref+4;
      *n=*n+5;
      }}else if (any == anyref){
      }else assert(0);

  if (any-anyref==0){
  }else if (any-anyref==1){
    *n=*n+2;
  }else if (any-anyref==2){
    *n=*n+3;
  }else if (any-anyref==3){
    *n=*n+4;
  }else assert (0);
  
  if (any-anyref==0){
    if (mes==1){
      *n=*n+dia-1;
    }else if (mes==2){
      *n=*n+3+dia-1;
    }else if (mes==3){
      *n=*n+dia+4-1;
    }else if (mes==4){
      *n=*n+dia-1;
    }else if (mes==5){
      *n=*n+dia+1;
    }else if (mes==6){
      *n=*n+dia+4;
    }else if (mes==7){
      *n=*n+dia-1;
    }else if (mes==8){
      *n=*n+dia+2;
    }else if (mes==9){
      *n=*n+dia+5;
    }else if (mes==10){
      *n=*n+dia;
    }else if (mes==11){
      *n=*n+dia+3;
    }else if (mes==12){
      *n=*n+dia+5;
    }else assert (0);
  }else if (any-anyref!=0){
     if (mes==1){
      *n=*n+dia-1;
    }else if (mes==2){
      *n=*n+3+dia-1;
    }else if (mes==3){
      *n=*n+dia+2;
    }else if (mes==4){
      *n=*n+dia-5;
    }else if (mes==5){
      *n=*n+dia;
    }else if (mes==6){
      *n=*n+dia+3;
    }else if (mes==7){
      *n=*n+dia+5;
    }else if (mes==8){
      *n=*n+dia+1;
    }else if (mes==9){
      *n=*n+dia+4;
    }else if (mes==10){
      *n=*n+dia-1;
    }else if (mes==11){
      *n=*n+dia+2;
    }else if (mes==12){
      *n=*n+dia+4;
    }else assert (0);
     }else assert (0);

  while (*n>7)
    {
      *n=*n-7;
    }

  if (*n==1){
    printf("Lunes\n\n");
  }else if (*n==2){
    printf("martes\n\n");
  }else if(*n==3){
    printf("miercoles\n\n");
  }else if(*n==4){
    printf("jueves\n\n");
  }else if (*n==5){
    printf("viernes\n\n");
  }else if (*n==6){
    printf ("sabado\n\n");
  }else if (*n==7){
    printf ("domingo\n\n");
  }else assert (0);
}












