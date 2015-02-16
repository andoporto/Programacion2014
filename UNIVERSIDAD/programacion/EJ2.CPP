#include<stdio.h>
#include<conio.h>

void main()

{int i,dni[5],marca,aux1;
 float s[5],aux;

 for(i=0;i<=4;i++)
 {printf("ingrese dni empleado %d\n", i+1);
  scanf("%d", &dni[i]);
  printf("\ningrese sueldo empleado%d\n", i+1);
  scanf("%f", &s[i]);
 }

 marca=0;

 while(marca==0)
 {marca=1;
  for(i=0;i<=3;i++)
   if(s[i]<s[i+1])
   {aux=s[i];
    s[i]=s[i+1];
    s[i+1]=aux;
    aux1=dni[i];
    dni[i]=dni[i+1];
    dni[i+1]=aux1;
    marca=0;
   }
 }

 printf("\ndni\tsueldo");

 for(i=0;i<=4;i++)
 printf("\n%d\t%.2f",dni[i],s[i]);

 getch();
} 

