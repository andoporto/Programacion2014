#include<stdio.h>
#include<conio.h>

void main()
{
clrscr();
long int cant;
long int mill,cmil,dmil,mil,cen,dec,uni;
printf("\n\n\n\t\tIntroduce la cantidad  :   ");
scanf("%ld",&cant);

		   mill=cant/1000000;
		   cant=cant%1000000;
		   cmil=cant/100000;
		   cant=cant%100000;
		   dmil=cant/10000;
		   cant=cant%10000;
		   mil=cant/1000;
		   cant=cant%1000;
		   cen=cant/100;
		   cant=cant%100;
		   dec=cant/10;
		   uni=cant%10;


		   switch (mill)
		  {
		   case 1: printf("UN MILLON ");
			   break;
		   case 2: printf("DOS MILLONES ");
			   break;
		   case 3: printf("TRES MILLONES ");
			   break;
		   case 4: printf("CUATRO MILLONES ");
			   break;
		   case 5: printf("CINCO MILLONES ");
			   break;
		   case 6: printf("SEIS MILLONES ");
			   break;
		   case 7: printf("SIETE MILLONES ");
			   break;
		   case 8: printf("OCHO MILLONES ");
			   break;
		   case 9: printf("NUEVE MILLONES  ");
			   break;
		   case 0: printf(" ");
			   break;
		  }



		   switch (cmil)
		  {
		   case 1: if(dmil==0&&mil==0)
					printf("CIEN");
					else
					printf("CIENTO ");
			   break;
		   case 2: printf("DOSCIENTOS ");
			   break;
		   case 3: printf("TRESCIENTOS ");
			   break;
		   case 4: printf("CUATROCIENTOS ");
			   break;
		   case 5: printf("QUINIENTOS ");
			   break;
		   case 6: printf("SEISCIENTOS ");
			   break;
		   case 7: printf("SETECIENTOS ");
			   break;
		   case 8: printf("OCHOCIENTOS ");
			   break;
		   case 9: printf("NOVECIENTOS ");
			   break;
		   case 0: printf(" ");
			   break;
		  }
		  switch (dmil)
		  {
		   case 1: if(mil==1)
					printf("ONCE MIL");
					else
						if(mil==2)
						printf("DOCE MIL");
						else
							if(mil==3)
							printf("TRECE MIL");
							else
								if(mil==4)
								printf("CATORCE MIL");
								else
									if(mil==5)
									printf("QUINCE MIL");
								else
								printf("DIEZ MIL");
								break;
		   case 2: if(uni==0)
					printf("VEINTE MIL ");
					else
					printf("VEINTI");
					break;
		   case 3: if(mil==0)
					printf("TREINTA MIL ");
					else
					printf("TREINTA ");
			   break;
		   case 4: if(mil==0)
					printf("CUARENTA MIL ");
					else
		   printf("CUARENTA ");
			   break;
		   case 5: if(mil==0)
					printf("CINCUENTA MIL ");
					else
		   printf("CINCUENTA ");
			   break;
		   case 6: if(mil==0)
					printf("SESENTA MIL ");
					else
		   printf("SESENTA ");
			   break;
		   case 7: if(mil==0)
					printf("SETENTA MIL ");
					else
		   printf("SETENTA ");
			   break;
		   case 8: if(mil==0)
					printf("OCHENTA MIL ");
					else
		   printf("OCHENTA ");
			   break;
		   case 9: if(mil==0)
					printf("NOVENTA MIL ");
					else
		   printf("NOVENTA ");
			   break;
		   case 0: if(dmil==0&&cmil==0)
					printf("");
				   else
				   if(dmil==0)
				   printf(" MIL ");
				   else
				   printf(" ");
				   break;
		  }



		   switch (mil)
		  {
		   case 1:  if(dmil==1)
					printf(" ");
				   else
					if(dmil==2)
				   printf("MIL");
				   else
				   printf("Y UN MIL ");
			   break;
		   case 2: if(mill==0&&cmil==0&&dmil==0)
				   printf("DOS MIL ");
				   else

		   if(dmil==1)
					printf(" ");
				   else
				   if(dmil==2)
				   printf("DOS MIL ");
				   else
				   printf("Y DOS MIL ");


			   break;
		   case 3: if(mill==0&&cmil==0&&dmil==0)
				   printf("TRES MIL ");
				   else

		   if(dmil==1)
					printf(" ");
				   else
			if(dmil==2)
				   printf("TRES MIL ");
				   else

		   printf("Y TRES MIL ");
			   break;
		   case 4: if(mill==0&&cmil==0&&dmil==0)
				   printf("TRES MIL ");
				   else
				   if(dmil==1)
					printf(" ");
				   else

		   if(dmil==2)
				   printf("CUATRO MIL ");
				   else
		   printf("Y CUATRO MIL ");
			   break;
		   case 5: if(mill==0&&cmil==0&&dmil==0)
				   printf("CUATRO MIL ");
				   else
				   if(dmil==1)
					printf(" ");
				   else
			if(dmil==2)
				   printf("CINCO MIL ");
				   else
		   printf("Y CINCO MIL ");
			   break;
		   case 6: if(mill==0&&cmil==0&&dmil==0)
				   printf("SEIS MIL ");
				   else
				   if(dmil==2)
				   printf("SEIS MIL ");
				   else
		   printf("Y SEIS MIL ");
			   break;
		   case 7: if(mill==0&&cmil==0&&dmil==0)
				   printf("SIETE MIL ");
				   else
					if(dmil==2)
				   printf("SIETE MIL ");
				   else
		   printf("Y SIETE MIL ");
			   break;
		   case 8: if(mill==0&&cmil==0&&dmil==0)
				   printf("OCHO MIL ");
				   else
					if(dmil==2)
				   printf("OCHO MIL ");
				   else
		   printf("Y OCHO MIL ");
			   break;
		   case 9: if(mill==0&&cmil==0&&dmil==0)
				   printf("NUEVE MIL");
				   else
					if(dmil==2)
				   printf("NUEVE MIL ");
				   else
		   printf("Y NUEVE MIL ");
			   break;
		   case 0: printf(" ");
			   break;
		  }

		   switch (cen)
		  {
		   case 1: printf("CIENTO ");
			   break;
		   case 2: printf("DOSCIENTOS ");
			   break;
		   case 3: printf("TRESCIENTOS ");
			   break;
		   case 4: printf("CUATROCIENTOS ");
			   break;
		   case 5: printf("QUINIENTOS ");
			   break;
		   case 6: printf("SEISCIENTOS ");
			   break;
		   case 7: printf("SETECIENTOS ");
			   break;
		   case 8: printf("OCHOCIENTOS ");
			   break;
		   case 9: printf("NOVECIENTOS ");
			   break;
		   case 0: printf(" ");
			   break;
		  }

		   switch (dec)
		  {
		   case 1:  if(uni==1)
					printf("ONCE");
					else
						if(uni==2)
						printf("DOCE");
						else
							if(uni==3)
							printf("TRECE");
							else
								if(uni==4)
								printf("CATORCE");
								else
									if(uni==5)
									printf("QUINCE");
								else
								printf("DIEZ ");
					break;
		   case 2:  if(uni==0)
					printf("VEINTE");
					else
					printf("VEINTI");
					break;
		   case 3: printf("TREINTA ");
			   break;
		   case 4: printf("CUARENTA ");
			   break;
		   case 5: printf("CINCUENTA ");
			   break;
		   case 6: printf("SESENTA ");
			   break;
		   case 7: printf("SETENTA ");
			   break;
		   case 8: printf("OCHENTA ");
			   break;
		   case 9: printf("NOVENTA ");
			   break;
		   case 0: printf(" ");
			   break;
		  }

		   switch (uni)
		  {
		   case 1:  if(mill==0&&cmil==0&&dmil==0&&cen==0&&dec==0)
					printf(" UNO");
					else

					if(dec==1)
					printf(" ");
				   else
				   if(dec==2)
				   printf("UNO");
				   else
				   printf("Y UNO ");
			   break;
		   case 2: if(mill==0&&cmil==0&&dmil==0&&cen==0&&dec==0)
					printf(" DOS");
					else

		   if(dec==1)
				   printf(" ");
				   else
					if(dec==2)
				   printf("DOS");
				   else
					printf("Y DOS ");
			   break;
		   case 3: if(mill==0&&cmil==0&&dmil==0&&cen==0&&dec==0)
					printf(" TRES");
					else

		   if(dec==1)
				   printf(" ");
				   else
					if(dec==2)
				   printf("TRES");
				   else
				   printf("Y TRES ");
			   break;
		   case 4: if(mill==0&&cmil==0&&dmil==0&&cen==0&&dec==0)
					printf(" CUATRO");
					else

		   if(dec==1)
				   printf(" ");
				   else
					if(dec==2)
				   printf("CUATRO");
				   else
					 printf(" Y CUATRO ");
			   break;
		   case 5: if(mill==0&&cmil==0&&dmil==0&&cen==0&&dec==0)
					printf(" CINCO");
					else

		   if(dec==1)
				   printf(" ");
				   else
					if(dec==2)
				   printf("CINCO");
				   else
					printf("Y CINCO ");
			   break;
		   case 6: if(mill==0&&cmil==0&&dmil==0&&cen==0&&dec==0)
					printf(" SEIS");
					else
					 if(dec==2)
				   printf("SEIS");
				   else
				   printf("Y SEIS ");
				   break;
		   case 7:  if(mill==0&&cmil==0&&dmil==0&&cen==0&&dec==0)
					printf(" SIETE");
					else
					if(dec==2)
				   printf("SIETE");
				   else
				   printf("Y SIETE ");
				   break;
		   case 8:  if(mill==0&&cmil==0&&dmil==0&&cen==0&&dec==0)
					printf(" OCHOO");
					else
					if(dec==2)
				   printf("OCHO");
				   else
					printf("Y OCHO ");
					break;
		   case 9:  if(mill==0&&cmil==0&&dmil==0&&cen==0&&dec==0)
					printf(" NUEVE");
					else
					if(dec==2)
				   printf("NUEVE");
				   else
				   printf("Y NUEVE ");
				   break;
		   case 0: printf(" ");
			   break;
		  }

getch();
}
