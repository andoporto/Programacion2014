 #include <stdio.h>
 #include <conio.h>

  void main()
  {
	int a,b,c;
	clrscr ();
	printf("\n Ingrese el primer valor: ");
	scanf ("%d",&a);
	printf("\n Ingrese el segundo valor: ");
	scanf ("%d",&b);
	printf("\n Ingrese el tercer valor: ");
	scanf ("%d",&c);

	if ((a==b)&&(b==c))
		printf("\n tres iguales");
	else
	  {
	   if ((a>c)&&(b>c))
				printf("\n mayores al tercero");
	   			else
	   			if ((a<c)||(b<c))
				printf("\n alguno es menor");
      }
  getch();
  }