 #include <stdio.h>
 #include <conio.h>

  void main()
  {
	int mes,anio;
	clrscr ();
	printf("\n Ingrese el mes: ");
	scanf ("%d",&mes);
	printf("\n Ingrese el a¤o: ");
	scanf ("%d",&anio);

	if ((mes==1)||(mes==3)||(mes== 5)||(mes==7)||(mes==8)||(mes==10)||(mes==12))
	 	printf("\n El mes tiene 31 d¡as");
	else
	{
	 	if ((mes==4)||(mes==6)||(mes==9)||(mes==11)
	 		printf("\n El mes tiene 30 d¡as");
	 	else
	 	{
	 		if (mes==2)&&(a%4==0))
				printf("\n El mes tiene 29 d¡as");
	 		else
				printf("\n El mes tiene 28 d¡as");
	     }
     }
    getch();
   }