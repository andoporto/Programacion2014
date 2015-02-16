 #include <stdio.h>
 #include <conio.h>

  void main()
  {
	int art;
	clrscr ();
	printf("\n Ingrese n de articulo: ");
	scanf ("%d",&art);

	if ((art < 1200)||(art > 90000))
		printf("codigo erroneo");
	else
	  {
	   if (((art >= 12121)&&(art <= 18081)) || ((art >= 30012)&&(art <= 45565)) ||((art >= 67000)&&(art <= 68000)))
	   			printf("articulo defectuoso");
	   			else
				printf("articulo OK");
          }
  getch();
  }