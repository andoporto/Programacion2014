/*Programa que convierte cantidades numericas de un sistema a otro*/
#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
		  {
		   int opc;
		   do
			 {
			  int numb10,cont,bin,oct,oct2,n,i;
			  clrscr();
			  printf("                  ////////////////Menu principal\\\\\\\\\\\\\\\\\n");
			  printf("1._ Comberci¢n de decimal a binario.   4._ Comberci¢n de binario a octal.\n");
			  printf("2._ Comberci¢n de decimal a octal.     5._ Comberci¢n de octal a decimal.\n");
			  printf("3._ Comberci¢n de binario a decimal.   6._ Comberci¢n de octal a binario\n");
			  printf("                                  7._Salir.\n");
			  printf("Teclea el numero de la opci¢n que deseas ejecutar: ");
			  scanf("%d", &opc);
			  switch (opc)
						{
						  case 1:
								 printf("Teclea el n£mero en base diez: ");
								 scanf("%d", &numb10);
								 cont=0;
								 printf("La posici¢n n del n£mero binario es:\n");
								 while (numb10!=0)
								 {
								 bin=numb10%2;
								 numb10=numb10/2;
								 printf(" n%d=%d\n", cont, bin);
								 cont++;
								 }
								 getch();
									   break;
						  case 2:
								 printf("Teclea el n£mero en base 10: ");
								 scanf("%d", numb10);
								 printf("La posici¢n n del n£mero octal es: \n");
								 cont=0;
								 while (numb10!=0)
								 {
								 oct=numb10%8;
								 numb10=numb10/8;
								 printf("n%d=%d\n", cont,oct);
								 cont++;
								 }
										break;
						  case 3:
								 printf("De cuantos digitos es el n£mero binario?: ");
								 scanf("%d", &n);
								 numb10=0;
								 cont=1;
								 i=0;
								 do
								  {
								   printf("Dame el n£mero %d binario de derecha a izquierda", cont);
								   scanf("%d", &bin);
								   cont++;
								   numb10=numb10+(bin*(pow(2,i)));
								   i++;
								  }while (cont<=n);
								   printf("El n£mero en base diez: %d", numb10);
								   getch();
								   break;
						  case 4:
								 cont=1;
								 printf("Este programa transforma cantidades binarias a octales cifra por cifra");
								 printf(" en bloques de 3 bits, si al dividir la cifra");
								 printf(" faltan pociciones en le ultimo bloque, completa con 0 los 3 bits.\n");
								 printf("Teclea el n£mero de bloques del digito: ");
								 scanf("%d", &n);

								 while (cont<=n)
									   {
										printf("Teclea el %d bloque de derecha a izquierda", cont);
										scanf("%d", &bin);
										if (bin==0)
										   printf("Le corresponde: 0\n");
										if (bin==1)
										   printf("Le corresponde: 1\n");
										if (bin==10)
										   printf("Le corresponde: 2\n");
										if (bin==11)
										   printf("Le corresponde: 3\n");
										if (bin==100)
										   printf("Le corresponde: 4\n");
										if (bin==101)
										   printf("Le corresponde: 5\n");
										if (bin==110)
										   printf("6Le corresponde: \n");
										if (bin==111)
										   printf("Le corrosponde: 7\n");
										cont++;
									   }
								 getch();
								 break;
						  case 5:
								 printf("De cuantos digitos es el n£mero octal");
								 scanf("%d", &n);
								 numb10=0;
								 cont=1;
								 i=0;
								 while (cont<=n)
									   {
										printf("Teclea el n£mero %d octal de derecha a izquierda", cont);
										scanf("%oct", &oct);
										cont++;
										numb10=numb10+(oct*(pow(8,i)));
										i++;
										}
								 printf("El n£mero en base diez= %d", numb10);
								 getch();
								 break;
						  case 6:
								 printf("Teclea el n£mero octal: ");
								 scanf("%d", &oct);
								 n=1000;
								 for (;n>=0;n=n/10)
								  {
									  bin=oct/n;
									  oct=oct%n;
									  if (bin==0)
										  printf(" 000,");
									  if (bin==1)
										  printf(" 001,");
									  if (bin==2)
										  printf(" 010,");
									  if (bin==3)
										  printf(" 011,");
									  if (bin==4)
										  printf(" 100,");
									  if (bin==5)
										  printf(" 101,");
									  if (bin==6)
										  printf(" 110,");
									  if (bin==7)
										  printf(" 111,");
										  getch();
								  }
						  case 7:
						  printf("Eligi¢ la opci¢n salir, presione cualquier tecla.");
								 break;

						}
			 }while (opc!=7);
			 getch();
		  }