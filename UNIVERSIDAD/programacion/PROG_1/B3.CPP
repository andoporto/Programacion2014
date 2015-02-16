#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 10

struct fecha {int dia;
				  int mes;
				  int anio;};

struct vendedor {int vend;
					 int art;
					 float imp;};

struct vendedor10 {int vend;
						 char apeynom[30];};

struct ventaxdia{ int cliente;
						char RSC[30];
						int vende;
						int art;
						int cantvend;
						float pu;
						float total;};

struct vector{ int vend;
					float imp;
					float sp;
               char apeynom[30];};





void fechaproceso(struct fecha *);
int controlvalor(int, int);
void ordenavende(int, struct vector *);                         // ordena
void intercambio(struct vector *, struct vector *); 				// intercambio de estructuras
float porcentaje(float, float);
float porcentaje2(float, float);
int controlvalor2(int, int);
void ordenaporcentaje(int, struct vector*);
void interporcentaje(struct vector *, struct vector *);
void copianombre(struct vector *, struct vendedor10 *);

void main()
{float vendedora [11][6];
float vector [11];
float tot[5];
int i, j,k,ind,x,y,a,b,z,c, h, g;
float totales, totalr,prom;
struct fecha fecha;
struct vendedor vend[50];
struct vendedor10 vend10[10];
struct vector vec[10];
struct ventaxdia ventaxdia[max];

FILE* sal;
FILE* vendedor;

clrscr();


if ((sal = fopen("C:\\salviejo.dat","wb")) == NULL)

	{
	printf("error al crear el archivo salviejo\n");
	exit(0);
	}

if ((vendedor = fopen("c:\\vendedor.dat","wb")) == NULL)
	{
	printf("error al crear el archivo vendedor\n");
	exit(1);
	}

for (i=0; i<10; i++)
{
do{
printf("ingrese numero de vendedor: ");
scanf("%d",&vend[i].vend);
} while (controlvalor(vend[i].vend,10)!=0);

do{
printf("ingrese numero de articulo: ");
scanf("%d",&vend[i].art);
} while (controlvalor(vend[i].art,5)!=0);

printf("ingrese importe: ");
scanf("%f",&vend[i].imp);

fwrite(&vend[i],sizeof(struct vendedor),1,sal);
}
fclose(sal);



for (j=0; j<10; j++)
{
do{
printf("ingrese numero de vendedor: ");
scanf("%d",&vend10[j].vend);
} while (controlvalor(vend10[j].vend,10)!=0);


printf("ingrese apellido y nombre del vendedor: ");
scanf("%s", vend10[j].apeynom); fflush(stdin);

fwrite(&vend10[j],sizeof(struct vendedor10),1,vendedor);

}
fclose(vendedor);


for(h=0; h<10; h++)
	{
		vec[h].imp=0;                                       //pone en cero el arrays de estructuras
		vec[h].vend=0;
		vec[h].sp=0;
	}

ind=0;

do{
printf("ingrese numero de cliente: ");
scanf("%d",&ventaxdia[ind].cliente);
} while(controlvalor2(ventaxdia[ind].cliente,50000)!=0);

while (ventaxdia[ind].cliente>0)
{

printf("ingrese razon social del cliente: ");
scanf("%s", ventaxdia[ind].RSC);  fflush(stdin);

do{
printf("ingrese numero de vendedor: ");
scanf("%d",&ventaxdia[ind].vende);
} while(controlvalor(ventaxdia[ind].vende,10)!=0);


do{
printf("ingrese numero de articulo: ");
scanf("%d",&ventaxdia[ind].art);
} while(controlvalor(ventaxdia[ind].art,5)!=0);

do{
printf("ingrese cantidad vendida: ");
scanf("%d",&ventaxdia[ind].cantvend);
} while(controlvalor(ventaxdia[ind].cantvend,10000)!=0);

printf("ingrese precio unitario: ");
scanf("%f",&ventaxdia[ind].pu);

ventaxdia[ind].total=0;

ind++;

do{
printf("ingrese numero de cliente: ");
scanf("%d",&ventaxdia[ind].cliente);
} while(controlvalor2(ventaxdia[ind].cliente,50000)!=0);

}																					//cierre del while principal

printf("ingrese la fecha de proceso:\n ");
fechaproceso(&fecha);


for (k=0; k<ind; k++)
{
ventaxdia[k].total = ventaxdia[k].cantvend * ventaxdia[k].pu;
}

totales=0;


printf("\n dia del proceso: %d - %d - %d \n",fecha.dia, fecha.mes, fecha.anio);

printf("\n RAZON SOCIAL DEL CLIENTE	  N DE ARTICULO		  IMPORTE VENDIDO\n");


for(x=0; x<ind; x++)
	{
	printf("\n %-30s	 %-1d		%-4.2f \n\n\n",ventaxdia[x].RSC, ventaxdia[x].art, ventaxdia[x].total);

	totales = totales + ventaxdia[x].total;
	}

printf("total ventas del dia: %4.2f",totales);
getch();




totalr=0;
for(y=0; y<ind; y++)
{

	for (z=0; z<10; z++)
		{


   				if (ventaxdia[y].vende == vend[z].vend)
     	   			{
                  			if (ventaxdia[y].art == vend[z].art)
      										vend[z].imp = vend[z].imp + ventaxdia[y].total;


                  }

    						totalr = totalr + vend[z].imp;



		}
}








for (g=0; g<50; g++)
	{
      		if (vend[g].vend == vend[g+1].vend)
              {
					vec[vend[g].vend - 1].imp = vec[vend[g].vend - 1].imp + vend[g].imp;
      			vec[vend[g].vend - 1].vend  = vend[g].vend;
      			vec[vend[g].vend - 1].sp = 0;
              }
	}


ordenavende(10, vec);





printf("\n\n dia del proceso: %d - %d - %d\n", fecha.dia, fecha.mes, fecha.anio);
printf("			\n\n N DE VENDEDOR			IMPORTE VENDIDO\n\n ");

for(a=0; a<10; a++)
	{
	printf("\n\n 		%2d		%-4.2f 		\n\n", vec[a].vend, vec[a].imp);
	}

printf("\n\n el total recaudado es: %6.2f \n\n", totalr);



prom = totalr / 10;

for(b=0; b<10; b++)
	{
   	if (vec[b].imp > prom)
   			vec[b].sp = porcentaje(vec[b].imp, prom);
		else
		vec[b].sp = 0;
   }




ordenaporcentaje(10, vec);
copianombre(vec, vend10);




printf("dia del proceso:%d - %d - %d \n\n",fecha.dia, fecha.mes, fecha.anio);

printf("\n\n N DE VENDEDOR     APELLIDO Y NOMBRE    PORC DE SUPERACION AL PROMEDIO \n\n ");


for(c=0; c<10; c++)
	{

	printf("%2d	 %s	  %-2.0f  \n\n", vec[c].vend, vec[c].apeynom, vec[c].sp);
	}

for(i=1; i<11;i++)
{
	for(j=1;j<6;j++)
   {	vendedora[i][j] = porcentaje2(vend[(i * j) - 1].imp,totalr);
      vendedora[0][j] = j;
      vector[i] = vector[i] + vendedora[i][j];
   }
   vendedora[i][0] = i;
}

for(j=1; j<6; j++)
{
	for(i=1; i<11; i++)
		{	tot[j - 1] = tot[j - 1] + vendedora[i][j];

      }
}



printf("vendedor:\n\n");

for(i=0;i<11;i++)
{
	for(j=0; j<6;j++)
   {	printf (" %2.3f ", vendedora[i][j]);

   }
   printf("%1f\n", vector[i]);
}

for(i=0; i<5; i++)
{
  printf("%3.0f", tot[i]);
  }

getch();

}													//cierre del main






int controlvalor(int a, int b)
{

if (a>=1 && a<=b)

return(0);

else

return(1);
}

void fechaproceso(struct fecha *fe)
{

do
{
printf("ingrese dia:");
scanf("%d",&fe->dia);
}
while(fe->dia<1 || fe->dia>30);

do
{
printf("ingrese mes:");
scanf("%d",&fe->mes);
}
while(fe->mes<1 || fe->mes>12);

do
{
printf("ingrese año:");
scanf("%d",&fe->anio);
}
while(fe->anio > 2007);
}


void ordenavende(int a, struct vector ve[])
{
int sen,i;
sen=0;

while(sen == 0)
{
sen = 1;


		for(i=0; i<a-1; i++)
			{
					if (ve[i].imp < ve[i+1].imp)
						{
						intercambio(&ve[i], &ve[i+1]);
						sen=0;
                  }

			}

}

}


void intercambio(struct vector *a, struct vector *b)
{
struct vector aux;
aux=*a;
*a=*b;
*b=aux;
}

float porcentaje(float a, float b)
{
float por;

por = ((a - b) / b) * 100;            // (imp-prom / prom) *100;

return(por);
}


int controlvalor2(int a, int b)
{
if (a<=b)
return(0);
else
return(1);
}

void ordenaporcentaje(int x, struct vector vect[])
{
int sena,j;
sena=0;

while(sena == 0)
{
sena = 1;


		for(j=0; j<x-1; j++)
			{
					if (vect[j].sp < vect[j+1].sp)
						{
						interporcentaje(&vect[j], &vect[j+1]);
						sena=0;
                  }

			}

}

}


void interporcentaje(struct vector *c, struct vector *d)
{
struct vector auxi;
auxi=*c;
*c=*d;
*d=auxi;
}




void copianombre(struct vector vec[], struct vendedor10 ven10[])
{
int sena,j;
sena=0;

while(sena == 0)
{
sena = 1;


		for(j=0; j<10; j++)
			{
  					if (vec[j].vend == ven10[j].vend)
						{
                  strcpy (vec[j].apeynom, ven10[j].apeynom);
						sena=0;
                  }

			}

}

}
float porcentaje2(float a, float b)
{
float porc;

porc = a / b;

return(porc);

}


















