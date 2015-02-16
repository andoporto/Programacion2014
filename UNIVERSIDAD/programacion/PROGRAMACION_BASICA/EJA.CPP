 #include <stdio.h>
 #include <conio.h>

  void main()
  {
	char val;
	clrscr ();
	printf("\n Ingrese una letra: ");
	scanf ("%c",&val);

	if ((val!='a')&&(val!='b'))
		printf("no es a o b");
	else
	  	printf("es a o b");

  getch();
  }