/*Programa que por medio de un switch muestra un men— con 5 opciones:
suma, resta, multiplicaci•n, divici•n y salir*/
#include<stdio.h>
#include<conio.h>
void main()
		 {
		  int opc,cant,cant2,i;
		  float cifra,suma,resta,mult=1,divc,div,divs;
		  do
			{
			  clrscr();
			  printf("                   ******** Men— principal********\n");
			  printf("                               1._ Suma.\n");
			  printf("                               2._ Resta.\n");
			  printf("                               3._ Multiplicaci•n.\n");
			  printf("                               4._ Divisi•n.\n");
			  printf("                               5._ Salir.\n");
			  printf("Selecciona la opcci•n que deseas ejecutar: ");
			  scanf("%d", &opc);
			  switch (opc)
						 {
						  case 1:
								 printf("Cuantas cantidades deseas sumar?: ");
								 scanf("%d", &cant);
								 for (i=0;i<=cant-1;i++)
									 {
									  printf("Dame la cantidad: ");
									  scanf("%f", &cifra);
									  suma=suma+cifra;
									 }
								 printf("El resultado de la suma es= %f", suma);
									   getch();

									   break;
						  case 2:
								 printf("Dame la primera cantidad");
								 scanf("%d", &cant);
								 printf("Dame la segunda cantidad");
								 scanf("%d", &cant2);
								 resta=cant-cant2;
								 printf("El resultado de la resta es: %f",resta);
								 getch();
									   break;
						  case 3:
								 printf("Cuantas cantidades deseas multiplicar?: ");
								 scanf("%d", &cant);
								 for (i=0;i<=cant-1;i++)
									{
									 printf("Dame la cantidad: ");
									 scanf("%f", &cifra);
									 mult=mult*cifra;
									}
								 printf("El resultado de la multiplicaci•n es:%f", mult);
								 getch();
								 break;
						  case 4:
								 printf("Dame el dividendo: ");
								 scanf("%f", &div);
								 printf("Dame el divisor: ");
								 scanf("%f", &divs);
								 divc=div/divs;
								 printf("El resultado de la divici•n es:%f", divc);
									   getch();
									   break;
						  case 5:
								 printf("Elejiste la opci•n salir, presiona cualquier tecla para terminar.");
									   break;
						  default :
								 printf("opci•n no valida!!!! vuelve a intentar.");
								 break;
						 }
			}while (opc!=5);
			getch();
		 }