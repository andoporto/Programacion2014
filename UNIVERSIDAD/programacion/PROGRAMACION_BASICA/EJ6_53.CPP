 #include <stdio.h>
 #include <conio.h>

  void main()
  {
   float temp,sum;
   int cont,i,prom;
   for (i=0;i<15;i++)
   {
    printf("\n Ingrese temperatura: ");
    scanf("%f",&temp);
     if (temp>0)
     {
      sum+=temp;
      cont++;
     }
   }
   if (cont!=0)
   {
    prom=sum/cont;
    printf("\n El promedio de los valores positivos es: %d",prom);
   }
   else
	printf("\n No se ingreso mingun valor positivo");
  getch();
 }