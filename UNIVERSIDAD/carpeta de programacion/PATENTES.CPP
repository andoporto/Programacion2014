#include <stdio.h>
#include  <conio.h>
#include <stdio.h>
#include <stdlib.h>

struct ARCHIVO1{ int NP,CAT,AF;
	char AYN[31], DOM[31];};

struct ARCHIVO2 { int np;
	float  mes[12];};

struct ARCHIVO3 { int NP8, CAT8, AF8;
	float I8;};

struct FECHA  { int d,m,a;};

struct FECHA FECHAPROCESO(void);
void  ORDENACION (int[],float[]);
void ORDENACION1 (int [], int[],int);
//////////////////////////////////////////////////////////////////////
void main (void)
{
	int I,K,CANT,H,LUG,IMPAGO7[10],i,k,j,marca,D,CATS[5],pos,DEUDA[10];
	int NROP[10],NA,LOC,posh,sit,L;
	float IMP[10],TOTCAT[5],TOTREC,MATRIZ8 [5][5];
	struct FECHA F;
	struct ARCHIVO1 PT[10];
	struct ARCHIVO2 PAG[10];
	struct  ARCHIVO3 NUEVO[10];
	FILE*PF,*PF2;

	F=FECHAPROCESO(); clrscr();
	PF=fopen("PARQUE.mae","rb");
	if(PF==NULL)
	{printf("\n No se puede accder al archivo");
		getch();
		exit(1);
	}
	I=0;
	fread(&PT[I],sizeof(struct ARCHIVO1),1,PF);
	while(!feof(PF))
	{I++;
		fread(&PT[I],sizeof(struct ARCHIVO1),1,PF);
	}
	CANT=I-1;
	fclose(PF);
	PF2=fopen("PAGOS.mov","rb");
	if(PF2==NULL)
	{ printf("\n No se puede acceder al archivo" );
		getch();
		exit(1);}
	K=0;
	fread(&PAG[K], sizeof(struct ARCHIVO2),1,PF2);
	while(!feof(PF2))
	{ K++;
		fread(&PAG[K], sizeof(struct ARCHIVO2),1,PF2);
	}
	LUG=K-1;
	NA=0;
	fclose(PF2);
	for (i=0;i<=LUG;i++)
	{
		IMP[i]=0;
		IMPAGO7[i]=0;
	}
	for (i=0;i<=LUG;i++)
	for(j=0;j<=11;j++)
	IMP[i]+=PAG[i].mes[j];

	printf("\nPATENTES CON DEUDAS PEDIENTES AL 30/12/%d",F.a );
	printf("\nPATENTES    MESES ADEUDADOS   DOMICILIO\n");

	for(i=0;i<=LUG;i++)
	{ k=0;
		for (j=0;j<=11;j++)
		{ if (PAG[i].mes[j]==0)
			{IMPAGO7[i]++;
				DEUDA[k]=j+1;
				k++;
			}
		}
		if(k!=0)
		{ printf("%d\t\t",PAG[i].np);
			for(L=0;L<(k-1);L++)
			printf("%d",DEUDA[L]);

			for (H=0;H<=CANT;H++);
			if(PAG[i].np==PT[H].NP)
			printf ("\t%s\n",PT[H].DOM);
		}
		else
		{for (H=0;H<=CANT;H++)
			if (PAG[i].np==PT [H].NP)
			{NUEVO[NA].NP8=PAG[i].np;
				NUEVO [NA].CAT8=PT[H].CAT;
				NUEVO [NA].AF8=PT[H].AF;
				NUEVO [NA].I8=IMP[i];
			}
			NA++;
		}
	}
	LOC=NA-1;

	for(i=0;i<=4;i++)
	TOTCAT[i]=0;
	for (i=0;i<=LUG;i++)
	{marca=0;
		D=0;
		while((marca==0)&&(D<=CANT))
		{ if (PAG[i].np==PT[D].NP)
			{ marca=1;
				pos=D;
			}
			else
			D++;
		}
		if (marca==1)
		{ sit=PT[pos].CAT;
			TOTCAT[sit-1]+=IMP[i];
		}
	}
	TOTREC=0;
	for (i=0;i<=4;i++)
	{
		CATS[i]=i+1;
		TOTREC+=TOTCAT[i];}

	ORDENACION(CATS,TOTCAT);

	printf("\n RECAUDACION AL 31/12/%d",F.a);
	printf("\n CATEGORIA        IMPORTE\n");
	for (i=0;i<=4;i++)
	printf("%d               %f\n",CATS[i],TOTCAT[i]);
	printf("\nTOTAL RECAUDADO: %f",TOTREC);

	for(i=0;i<=LUG;i++)
	NROP[i]=PAG[i].np;

	ORDENACION1 (NROP,IMPAGO7,LUG);
	printf("\n PATENTE   MESES IMPAGOS");
	for (i=0;i<=LUG;i++)
	if(IMPAGO7[i]!=0)
	printf("\n%d          %d",NROP[i],IMPAGO7[i]);

	for  (i=0;i<=4;i++)
	for (j=0;j<=4;j++)
	MATRIZ8[i][j]=0;

	for (i=0;i<=LUG;i++)
	{ marca=0;
		k=0;
		while  ((marca==0)&&(k<=CANT))
		{ if (PAG[i].np==PT[k].NP)
			{ marca=1;
				posh=k;
			}
			else
			k++;
		}
		if(marca==1)
		MATRIZ8[(PT[posh].CAT)-1][(PT[posh].AF)-2000]+=IMP[i];
	}
	printf("\n DISTRIBUCION DE PAGOS EFECTUADOS CON IMPORTES:    ");
	printf("\n CATEGORIA 2000	2001	2001	2003	2004");

	for(i=0;i<=4;i++)
	{printf("\n%d",i+1);
		for (j=0;j<=4;j++)
		printf("%f",MATRIZ8[i][j]);}
	PF=fopen("Sin Deudas.dat","wb");
	if (PF==NULL)
	{printf("\n No se puede acceder al archivo");
		getch();
		exit(1); }
	for (i=0;i<=LOC;i++)
	fwrite(&NUEVO[i],sizeof(struct ARCHIVO3),1,PF);
	fclose(PF);

	printf("\nFIN DEL PROGAMA");
	getch();
}


void ORDENACION(int c[],float t[])
{  int marca,i,aux2;
	float aux;
	marca=0;

	while (marca==0)
	{ marca=1;
		for (i=0;i<=3;i++)
		{
			if (t[i]<t[i+1])
			{ aux=t[i];
				t[i]=t[i+1];
				t[i+1]=aux;
				aux2=c[i];
				c[i]=c[i+1];
				c[i+1]=aux2;
				marca=0;
			}
		}
	}
}



void ORDENACION1 (int n[], int y[], int z )
{int marca=0,aux2,aux,i;
	while(marca==0)
	{ marca=1;
		for(i=0;i<=z-1;i++)
		{ if (y[i]<y[i+1])
			{ aux=y[i];
				y[i]=y[i+1];
				y[i]=aux;
				aux2=n[i];
				n[i]=n[i+1];
				n[i+1]=aux2;
				marca=0;
			}
		}

	}
}



struct FECHA  FECHAPROCESO (void)

{struct FECHA F ;
	do {printf("\n Ingrese el dia:    ");
		scanf("%d",&F.d);
	}while ((F.d<1)||(F.d>31));
	do{ printf("\n Ingrese el mes:  ");
		scanf("%d",&F.m);
	}while((F.m<1)||(F.m>12));
	do{printf("\n Ingrese el año:   ");
		scanf("%d",&F.a);
	}while((F.a<2000)||(F.a>2004));
	return(F);

}