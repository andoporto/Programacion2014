#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{

int opc;
long int cant,bin,oct,bdiez,cantb,val,exp,dec,y,s;
do
{
clrscr();
printf("\n\n\t\tSelecciona el tipo de conversion");
printf("\n\nTecleando los digitos, primero del primer sistema y luego del segundo");
printf("\n\n\n\t\t1.- Decimal         1.-Decimal");
printf("\n\n\n\t\t2.- Octal           2.-Octal");
printf("\n\n\n\t\t3.- Binario         3.-Binario");
printf("\n\n\t\t\t4.-Salir");
printf("\n\nSelecciona una opcion:   ");
scanf("%d",&opc);

			switch(opc)
			{
				case 12: clrscr();
						 printf("\n\n\t\tConvertir de Decimal a Octal");
						 printf("\n\n\tDame la cantidad en base 10:  ");
						 scanf("%ld",&cant);


						while (cant>0)
						{
						val=cant%8;
						cant=cant/8;
						cantb+=val*bdiez;
						bdiez=bdiez*10;
						}
						printf("\n\n\tLa cantida en base 8 es:  %d",cantb);
						break;
				case 13: clrscr();
						 printf("\n\n\t\tConvertir de Decimal a Binario");
						 printf("\n\n\tDame la cantidad en base 10:  ");
						 scanf("%ld",&cant);
						 do
						 {
						 bin=cant%2;
						 cant=cant/2;
						 printf("%d",bin);
						 }while(cant!=0);
						 break;
				case 21: clrscr();
						 printf("\n\n\t\tConvertir de Octal a Decimal");
						 printf("\n\n\tDame la cantidad en base 8:  ");
						 scanf("%ld",&cant);
						 while(cant>0)
						 {
						 y=cant%10;
						 cant=cant/10;
						 cantb+=y*pow(8,s);
						 s++;
						 }
						 printf("La cantidad en base 10 es :  %ld",cantb);
						 break;
				case 23: clrscr();
						 printf("\n\n\t\tConvertir de Octal a Binario");
						 printf("\n\n\tDame la cantidad en base 8:  ");
						 scanf("%ld",&cant);
						 printf("La cantidad en base 2 es :  %d",cant);
						 break;
				case 31: clrscr();
						 printf("\n\n\t\tConvertir de Binario a Decimal");
						 printf("\n\n\tDame la cantidad en base 2:  ");
						 scanf("%ld",&cant);
						 bdiez=0;
						 while(cant>0)
						 {
						 val=cant%10;
						 cant=cant/10;
						 bdiez+=val*(pow(2,exp));
						 exp++;
						 }
						 printf("La cantidad en base 10 es :  %d",bdiez);
						 break;
				case 32: clrscr();
						 printf("\n\n\t\tConvertir de Binario a Octal");
						 printf("\n\n\tDame la cantidad en base 2:  ");
						 scanf("%o",&bin);
						for(dec=0;bin>0;bin=bin/10)
							{
						oct=bin%10;
						dec=(oct*(pow(2,exp)))+dec;
						exp++;
						 }
						oct=0;
						for(exp=0;dec>0;exp++)
						{
						bin=dec%8;
						dec=dec/8;
						oct=(bin*(pow(10,exp)))+oct;
						}
						 printf("La cantidad en base 8 es :  %d",oct);
						 break;
				case 4:  clrscr();
						 printf("\n\n\n\n\n\t\t\tSalir");
						 printf("\n\n\tCopyrigth. Derechos reservados SAGA Team 2004");
						 break;
				default: printf("\n\n\n\t\tOpcion No Valida");
						 break;

				}
	   printf("\n\n\n\n\n\n\t\tPresiona una tecla para continuar.......");
	   getch();
	   }while(opc!=4);
getch();
}