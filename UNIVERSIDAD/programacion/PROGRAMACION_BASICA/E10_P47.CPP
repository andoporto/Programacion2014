 #include <stdio.h>
 #include <conio.h>

  void main()
  {
	int m,a;
	clrscr ();
	printf("\n Ingrese el mes: ");
	scanf ("%d",&m);
	printf("\n Ingrese el a¤o: ");
	scanf ("%d",&a);

	switch (m)
	{
	 case 1:
	 case 3:
	 case 5:
	 case 7:
	 case 8:
	 case 10:
	 case 12:
	 printf("\n El mes tiene 31 d¡as");
	 break;

	 case 4:
	 case 6:
	 case 9:
	 case 11:
	 printf("\n El mes tiene 30 d¡as");
	 break;

	 default:
	 	if (a%4==0)
			printf("\n El mes tiene 29 d¡as");
	 	else
			printf("\n El mes tiene 28 d¡as");
    }
    getch();
   }