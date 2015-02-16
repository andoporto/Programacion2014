/*Programa que determina la edad de una persona y si esta es mayor de edad*/
#include<stdio.h>
#include<conio.h>
void main()
		  {

		   const int a=2004;
		   int edad,fec_de_nac;
		   clrscr();
		   printf("Programa que c…lcula tu edad y te dice si eres mayor de edad\n");
		   printf("Escribe tu fecha de nacimiento: ");
		   scanf("%d", &fec_de_nac);
		   if (fec_de_nac<=1904)
			   printf("No es posible que tengas 100 a¤os");
			   if (fec_de_nac>=2004)
				  printf(" Tu todavia no naces");
			   else
				  {
					edad=a-fec_de_nac;
					printf("Tu edad es: %d,", edad);
					if (fec_de_nac<18)
						printf("todavia no eres mayor de edad");
						if (fec_de_nac>=18)
							printf("ya eres mayor de edad");
				  }
			getch();
		   }