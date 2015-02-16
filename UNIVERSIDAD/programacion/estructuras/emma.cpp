#include <conio.h>
#include <stdio.h>

struct fecha {int dia;
      		  int mes;
              };

struct sa {int num;
           char nom[25];
           float saldo;
  			  };

struct m {int num;
   	    struct fecha fh;
          int oper;
          };
int busqueda(struct sa[], int x, int y);

void main()
{FILE *saldo, *movim;
 int i, cc, ptoa[2500] ,ptob[2500] ,p;
 struct sa cuenta[2500];
 struct m mov;
 saldo=fopen("c:\\saldante.bin","rb");
 fread(&cuenta[i],sizeof (struct sa),1,saldo);
 while (!feof(saldo));
 	{i++
 	fread(&cuenta[i],sizeof (struct sa),1,saldo);
 	ptoa[i];
 	ptob[i];
   }
 cc=i;
 fclose(saldo);
 movim=fopen("c:\\movi.bin","rb");
 fread(&mov,sizeof (struct mov),1,movim);
 while(!feof(movim));
 	{p=busqueda(cuenta, mov.num, cc)
   switch (mov.oper)
   	{case 1:cuenta[p].saldo+=mov.imp;
       case 2:cuenta[p].saldo-=mov.imp;
       		  ptob[p]; break;
      }
   ptoa[p]=1;
   fread(&mov,sizeof (struct mov),1,movim);
   }
 fclose(movim);
 saldo=fopen("c:\\saldante.bin","wb");
 for (i=0;i<cc;i++)
 	fwrite(&cuenta[i],sizeof (struct sa),1,saldo);
 fclose(saldo);
 printf("cuentas sin movimientos");
 for (i=0;i<cc;i++)
  { if (ptoa[i]==0)
 		printf("%d \t %f",cuenta[i].num,cuenta[i].saldo);
  }
 printf("cuentas con mas de 5 movimientos");
  for (i=0;i<cc;i++)
  { if (ptob[i]>5)
 		printf("%d",cuenta[i].num);
  }
}
int busqueda (struct sa cliente[],int x, int y)
{  int pos
	pos=-1
   i=0
   while (i<y) && (pos==-1)
   	{if (cliente[i]==x)
           pos=i;
           else
           i++
      }
   return(pos)
