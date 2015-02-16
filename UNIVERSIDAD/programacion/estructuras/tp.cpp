#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

float maximoterna(float,float,float);
void titilar(float[3][3]);
void sumamatriz(float[3][3]);
void prodmatriz(float[3][3],float[3][3]);
void cerear(float [3][3]);
void divide(FILE *,float);

struct arraytrian
{
	float lado1;
   float lado2;
   float lado3;
   int cang;
   float sup;
  	char tipt[10];
   char t1[1];
   float imp;
};

void main()
{
	struct arraytrian t;
   int a=0,b=0,i,z=0,mayor,contador=0;
   float matrizmayor[3][3],vm[6],acumimp=0,promedio;

   FILE *arch;

	printf("Superficie del Triangulo:==>");
	scanf("%f",&t.sup);
	printf("\n");

	while(t.sup!=0)
	{
		a++;
   	printf("INGRESE LA %d TERNA DE LADOS DEL TRIANGULO\n",a);
     	printf("\n");
      do
      {
      	printf("Ingrese el lado 1:==>");
      	scanf("%f",&t.lado1);
      }
      while(t.lado1<0);

      do
      {
      	printf("Ingrese el lado 2:==>");
      	scanf("%f",&t.lado2);
      }
      while(t.lado2<0);

      do
      {
      	printf("Ingrese el lado 3:==>");
      	scanf("%f",&t.lado3);
      }
      while(t.lado3<0);

      mayor=maximoterna(t.lado1,t.lado2,t.lado3);
     	vm[z]=mayor;
     	z++;

      do
      {
     	printf("\n");
      printf("Tipo de material (C:cartulina P:papel T:tela) ==>\n ");
      scanf("%s",&t.t1);
      }
      while( *t.t1!='c' && *t.t1!='p' && *t.t1!='t');

      if(*t.t1=='c')
      t.imp=t.sup*4.5;

      if(*t.t1=='p')
      t.imp=t.sup*2.5;

      if(*t.t1=='t')
      t.imp=t.sup*6.6;



      arch=fopen("triangulos.dat","wb");
      if(arch==NULL)
      {
      printf("el Archivo no se pudo abrir");
   	exit(0);
      }
      fwrite(&t.imp,sizeof(t.imp),1,arch);

      acumimp+=t.imp;


      printf("Tipo de triangulo==>");
   	scanf("%s",&t.tipt);
     	printf("\n");

   	if(a==2 || a==4 || a==6)
     	{
      	matrizmayor[b][0]=t.lado1;
         matrizmayor[b][1]=t.lado2;
         matrizmayor[b][2]=t.lado3;
      	b++;
     	}
   	printf("ingrese el codigo angular==>");
   	scanf("%d",&t.cang);
   	while(t.cang!=0 && t.cang!=1)
   	{
   		printf("Codigo angular==>");
   		scanf("%d",&t.cang);
   	}
     	clrscr();

  		printf("Superficie del Triangulo:==>");
		scanf("%f",&t.sup);
     	printf("\n");
   }
   fclose(arch);

   promedio=acumimp/a;
   printf("Promedio de los triangulos: %.2f\n",promedio);

   if(t.imp>promedio)
   	contador++;

   printf("La cantidad de triangulos mayores al promedio son:%.0f\n",contador);
   getch();
   clrscr();

   printf("<<<<<MATRIZ MAYOR>>>>>>\n");
	titilar(matrizmayor);
   sumamatriz(matrizmayor);

   printf("\n");
   printf("Los mayores son:\n ");
   for (i=0;i<6;i++)
   {
   	printf("\t%.0f\n",vm[i]);
   }
   divide(arch,promedio);
  	getch();



}

float maximoterna(float l1,float l2,float l3)
{
	float max;
 	max=l1;
  	if (l2>max)
   	max=l2;
  	else
      {
   		if (l3>max)
      		max=l3;
      }
 	return(max);
}

void titilar(float m[3][3])
{
	int c,f;
  	printf("*****************************\n");
  	printf("* MATRIZ ORDENADA POR FILAS *\n");
  	printf("*****************************\n");
  	printf("\n");
	for(f=0;f<3;f++)
  	{
  		for(c=0;c<3;c++)
  		{
     		printf("%.0f\t",m[f][c]);
     	}
     	printf("\n");
  	}
}

void sumamatriz(float m[][3])
{
	float matrizsuma[3][3],matriztrans[3][3];
	int c,f;
	for(f=0;f<3;f++)
  	{
   	for(c=0;c<3;c++)
		{
      	matriztrans[f][c]=m[c][f];
        	matrizsuma[f][c]=m[f][c]+matriztrans[f][c];
     	}
  	}
   printf("\n");
   printf("<<<<<MATRIZ SUMA>>>>>>\n");

   titilar(matrizsuma);
   prodmatriz(m,matriztrans);
}

void prodmatriz(float m[][3],float mt[][3])
{
	float matrizproducto[3][3];
  	int c,f,z;
	for(f=0;f<3;f++)
  	{
  		for(c=0;c<3;c++)
  		{
     		for(z=0;z<3;z++)
      	{
         	matrizproducto[f][c]=matrizproducto[f][c]+m[f][z]*mt[z][c];
        	}
     	}
  	}
   printf("\n");
   printf("<<<<<MATRIZ PRODUCTO>>>>>>\n");
   titilar(matrizproducto);
}


void cerear(float m[][3])
{
	int f,c;

	for(f=0;f<3;f++)
  	{
  		for(c=0;c<3;c++)
  		{
     		m[f][c]=0;
     	}
  	}
}

void divide(FILE * arch,float p)
{
   float tmen,tmay;

	FILE * a1;
   FILE * a2;

   float j;

   arch=fopen("Triangulos.dat","rb");
 	if(arch==NULL)
   {
   	exit(0);
   }

   while (!feof(arch))
   {
      fread(&j,sizeof(j),1,arch);

   	if (j<p)
      {
      	 a1=fopen("Triangulosmen.dat","wb");
          if(a1==NULL)
   		 {
   		  	exit(0);
          }
         fwrite(&j,sizeof(j),1,a1);

      }
      else
      {
      	if (j>p)
      	{
      	 	a2=fopen("Triangulosmay.dat","wb");
            if(a2==NULL)
   			{
   			  	exit(0);
   		   }
          	fwrite(&j,sizeof(float),1,a2);

      	}
      }
	}


   fclose(arch);
   fclose(a1);
   fclose(a2);
   tmen=ftell(a1);
   printf("%f",tmen);

   }

