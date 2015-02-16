#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#define M 3

void main(void){

int i, j, val;
float mat[M][6], dep, ext, com, in, max=0;
char seguir, seg;

for(i=0; i<M; i++)
	for(j=0; j<6; j++)
	mat[i][j]=0;
do
{
clrscr();
printf("\nIngrese n£mero de cliente: ");
scanf("%d", &i);
while(i > M || i < 1)
{
clrscr();
printf("\nIngrese n£mero de cliente: ");
scanf("%d", &i);
}
i--;
mat[i][0] = i;
if(mat[i][5]==0)
{
printf("\nIngrese el saldo: ");
scanf("%f", &mat[i][5]);
}
clrscr();
printf("\nC¢digo de transacci¢n\n\n\t\t1.Dep¢sito\n\t\t2.Extracci¢n\n\t\t3.Comisiones deducidas\n\t\t4.Intereses acreditados\n\n\n\t\tC¢digo: ");
scanf("%d", &j);
while(j < 1 || j > 4)
{
clrscr();
printf("\nC¢digo de transacci¢n\n\n\t\t1.Dep¢sito\n\t\t2.Extracci¢n\n\t\t3.Comisiones deducidas\n\t\t4.Intereses acreditados\n\n\n\t\tC¢digo: ");
scanf("%d", &j);
}
switch(j){
case 1: clrscr();
	printf("\nDeposito: ");
	scanf("%f", &dep);
	mat[i][1] = mat[i][1] + dep;
	mat[i][5] = mat[i][5] + dep;
	break;
case 2: clrscr();
	printf("\nExtracci¢n: ");
	scanf("%f", &ext);
	while(ext > mat[i][5])
	{
	clrscr();
	printf("\nNo tienes suficiente dinero depositado para realizar esa extracci¢n");
	printf("\n\nDesea extraer menos cantidad s/n?: ");
	seg=getch();
	seg=tolower(seg);
	while(seg!= 's' && seg!= 'n')
		{
		clrscr();
		printf("\nDesea extraer menos cantidad s/n?: ");
		seg=getch();
		seg = tolower(seg);
		}
	if(seg=='n')
		{
		clrscr();
		break;
		}
	if(seg=='s')
		{
		clrscr();
		printf("\nExtracci¢n: ");
		scanf("%f", &ext);
		}
	}
	mat[i][2] = mat[i][2] + ext;
	mat[i][5] = mat[i][5] - ext;
	break;
case 3: clrscr();
	printf("\nComisiones deducidas: ");
	scanf("%f", &com);
	mat[i][3] = mat[i][3] + com;
	mat[i][5] = mat[i][5] - com;
	break;
case 4: clrscr();
	printf("\nIntereses acreditados: ");
	scanf("%f", &in);
	mat[i][4] = mat[i][4] + in;
	mat[i][5] = mat[i][5] + in;
	break;
	}
printf("\nDesea seguir s/n?: ");
seguir=getch();
seguir=tolower(seguir);
}while(seguir=='s');
clrscr();
mat[0][0]++;
for(i=1; i<M; i++)
       {
       if(mat[i][0]!=0)
       mat[i][0]++;
       }
printf("  ÚÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄ¿\n");
printf("  ³N¦ cliente ³ Total dep.³ Total ext ³ Total com.³ Total int.³   Saldo   ³\n");
printf("  ÃÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄ´\n  ");
for(i=0; i<M; i++)
       {
	if(i!=0)
	printf("³\n  ");
	for(j=0; j<6; j++)
	printf("³ %6.2f    ", mat[i][j]);
	}
	printf("³");
	printf("\n");
	printf("  ÀÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÙ");
	for(i=0; i<M; i++)
		if(mat[i][1] > max)
		max = mat[i][1];
	printf("\n\n\n  La mayor cantidad de dinero depositada fue $%.2f", max);
	printf("\n\n  Los numeros de el/los clientes con esa cantidad depositada son:\n\n\n ");
	for(i=0; i<M; i++)
		if(mat[i][1] == max)
		printf(" %d  ", i+1);
getch();
}






