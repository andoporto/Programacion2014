 #include <stdio.h>
 #include <conio.h>

  void main()
  {
   int sum,a,i;
   sum=0;
   clrscr();

   for (i=0;i<=9;i++)
   {
    printf("\n Ingrese el valor: ");
    scanf("%d",&a);
    sum+=a;
   }
   printf("\n La suma vale: %d",sum)
  getch;
  }