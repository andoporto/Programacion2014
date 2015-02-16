/*Programa que lee una cantidad y muestra su equivalente en letra*/
#include<stdio.h>
#include<conio.h>

void main()
	  {
		   int cifra1,cifra2,cifra3,cifra4,cifra5,cifra6,cifra7,opc;
		   long int cant;
		do
		  {
		   clrscr ();
		   printf("Este programa transforma un numero a su equivalente en letra.\n");
		   printf("Teclea el n£mero de la opci¢n a ejecutar\n\n");
		   printf("                          1._ Combertir un n£mero a letra.\n");
		   printf("                          2._ Salir del programa: ");
		   scanf("%d", &opc);
		   if (opc==1)
			   {
				 printf("Escribe una cantidad maximo de 7 cifras a combertir a letra: ");
				 scanf("%ld", &cant);
				 cifra1=cant/1000000;
				 cant=cant%1000000;
				 cifra2=cant/100000;
				 cant=cant%100000;
				 cifra3=cant/10000;
				 cant=cant%10000;
				 cifra4=cant/1000;
				 cant=cant%1000;
				 cifra5=cant/100;
				 cant=cant%100;
				 cifra6=cant/10;
				 cant=cant%10;
				 cifra7=cant;
				 if (cifra1>9)
				   {
					printf("Cantidad no valida.\n");
					printf("Presiona cualquier tecla para continuar");
					getch();
				   }
				   else
				   {
					if (cifra1!=0)
					   {
						if (cifra1==1)
							printf("Un millon,");
						if (cifra1==2)
							printf("Dos millones, ");
						if (cifra1==3)
							printf("Tres millones, ");
						if (cifra1==4)
							printf("Cuatro millones, ");
						if (cifra1==5)
							printf("Cinco Millones, ");
						if (cifra1==6)
							printf("Seis millones, ");
						if (cifra1==7)
							printf("Siete millones, ");
						if (cifra1==8)
							printf("Ocho mimllones, ");
						if (cifra1==9)
							printf("Nueve millones, ");
					   }

					  if (cifra2!=0)
					  {
						if (cifra2==1)
							printf("Ciento, ");
						if (cifra2==2)
							printf("Doscientos, ");
						if (cifra2==3)
							printf("Trescientos, ");
						if (cifra2==4)
							printf("Cuatrocientos, ");
						if (cifra2==5)
							printf("Quinientos, ");
						if (cifra2==6)
							printf("Seicientos ");
						if (cifra2==7)
							printf("Setecientos, ");
						if (cifra2==8)
							printf("Ochocientos, ");
						if (cifra2==9)
							printf("Novecientos, ");
					   }

						if (cifra3!=0)
						   {
							if (cifra3==1)
								printf("Diez, ");
							if ((cifra3==1)&&(cifra4==2))
								 printf("Docemil, ");
							if ((cifra3==1)&&(cifra4==3))
								 printf("Trecemil, ");
							if ((cifra3==1)&&(cifra4==4))
								printf("Catorcemil, ");
							if ((cifra3==1)&&(cifra4==5))
								printf("Quincemil, ");
							if ((cifra3==2)&&(cifra4==0))
								printf("Veintemil, ");
							else if (cifra3==2)
									 printf("Veinte, ");
							if ((cifra3==3)&&(cifra4==0))
								printf("Treintamil, ");
							else if (cifra3==3)
									 printf("treinta, ");
							if ((cifra3==4)&&(cifra4==0))
								 printf("Cuarentamil, ");
							else if (cifra3==4)
									 printf("Cuarenta, ");
							if ((cifra3==5)&&(cifra4==0))
								printf("cincuetamil, ");
							else if (cifra3==5)
									 printf("Cincuenta, ");
							if ((cifra3==6)&&(cifra4==0))
								 printf("Sesentamil, ");
							else if (cifra3==6)
									 printf("Setenta, ");
							if ((cifra3==7)&&(cifra4==0))
								 printf("Setentamil, ");
							else if (cifra3==7)
									 printf("Setenta, ");
							if ((cifra3==8)&&(cifra4==0))
								printf("Ochentamil, ");
							else if (cifra3==8)
									 printf("Ochenta, ");
							if ((cifra3==9)&&(cifra4==0))
								 printf("Noventamil, ");
							else if (cifra3==9)
									 printf("Noventa, ");
						   }

						if ((cifra4!=0)&&(cifra2!=0)&&(cifra3!=0))
						   {
							if ((cifra4==1)&&(cifra3!=1))
								printf(" y Unmil, ");
							if ((cifra4==2)&&(cifra3!=1))
								printf("y Dosmil, ");
							if ((cifra4==3)&&(cifra3!=1))
								printf("y Tresmil, ");
							if ((cifra4==4)&&(cifra3!=1))
								printf("y Cuatromil, ");
							if ((cifra4==5)&&(cifra3!=1))
								printf("y Cincomil, ");
							if (cifra4==6)
								printf("y Seismil, ");
							if (cifra4==7)
								printf("y Sietemil, ");
							if (cifra4==8)
								printf("y Ochomil, ");
							if (cifra4==9)
								printf("y Nuevemil, ");
						   }
						if (cifra5!=0)
						   {
							if (cifra5==1)
								printf("Ciento, ");
							if (cifra5==2)
								printf("Doscientos, ");
							if (cifra5==3)
								printf("Trescientos, ");
							if (cifra5==4)
								printf("Cuatorcientos, ");
							if (cifra5==5)
								printf("Quinientos, ");
							if (cifra5==6)
								printf("Seiscientos, ");
							if (cifra5==7)
								printf("Setecientos, ");
							if (cifra5==8)
								printf("Ochocientos, ");
							if (cifra5==9)
								printf("Novecientos, ");
						   }

						if (cifra6!=0)
						   {
							if ((cifra6==1)&&(cifra7==0))
								 printf("Diez, ");
							if ((cifra6==1)&&(cifra7==1))
								 printf("Once, ");
							if ((cifra6==1)&&(cifra7==2))
								 printf("Doce, ");
							if ((cifra6==1)&&(cifra7==3))
								 printf("Trece, ");
							if ((cifra6==1)&&(cifra7==4))
								 printf("Catorce, ");
							if ((cifra6==1)&&(cifra7==5))
								 printf("Quince, ");
							if ((cifra6==2)&&(cifra7==0))
								 printf("Veinte, ");
							if (cifra6==2)
								printf("Venti, ");
							if (cifra6==3)
								printf("Treinta, ");
							if (cifra6==4)
								printf("Cuarenta, ");
							if (cifra6==5)
								printf("Cincuenta, ");
							if (cifra6==6)
								printf("Sesenta, ");
							if (cifra6==7)
								printf("Setenta, ");
							if (cifra6==8)
								printf("Ochenta, ");
							if (cifra6==9)
								printf("Noventa, ");
						   }
							if ((cifra7==1)&&(cifra6!=1))
								 printf("y Uno");
							if ((cifra7==2)&&(cifra6!=1))
								printf("y Dos");
							if ((cifra7==3)&&(cifra6!=1))
								 printf("y Tres");
							if ((cifra7==4)&&(cifra6!=1))
								 printf("y Cuatro");
							if ((cifra7==5)&&(cifra6!=1))
								 printf("y Cinco");
							if (cifra7==6)
								printf("y Seis");
							if (cifra7==7)
								printf("y Siete");
							if (cifra7==8)
								printf("y Ocho");
							if (cifra7==9)
								printf("y Nueve");

			   }
	   getch();
	  }

	 }while (opc==1);
	 printf("Presiona cualquier tecla para salir");
	 getch();
   }