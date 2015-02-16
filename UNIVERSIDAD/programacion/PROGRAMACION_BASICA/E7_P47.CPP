   #include <stdio.h>
   #include <conio.h>

   void main()
   {
	int a,b,c,d,min,ord;
	clrscr ();
	printf("\n Ingrese el primer n£mero: ");
	scanf ("%d",&a);
	printf("\n Ingrese el segundo n£mero: ");
	scanf ("%d",&b);
	printf("\n Ingrese el tercer n£mero: ");
	scanf ("%d",&c);
	printf("\n Ingrese el cuarto n£mero: ");
	scanf ("%d",&d);

	min=a;
	ord=1;
	if (b<min)
	{
	 min=b;
	 ord=2; }
	if (c<min)
	{
	 min=c;
	 ord=3; }
	if (d<min)
	{
	 min=d;
	 ord=4; }


	printf ("\n El primer valor es : %d , el segundo valor es: %d , el tercer valor es: %d ,       el cuarto valor es: %d",a,b,c,d);
	printf("\n\n M¡nimo: %d N£mero de orden: %d", min, ord);
	getch();
	}