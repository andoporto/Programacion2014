#include <stdio.h>
#include <conio.h>
#define M 3
void main(){
int i,j, band=0;
float tpi=0, tpc=0, tpb=0, pi, pc, pb, suma, msuma, total=0;
char nombre[20], mnombre[15], menor[20];

for( i = 0; i <= M; i++ )
{
	clrscr();
	flushall;
	printf("\nApellido y Nombre: ");
	scanf("%s", &nombre);
	printf("\nPuntos por inteligencia: ");
	scanf("%f", &pi);
	tpi = tpi + pi;
	printf("\nPuntos por cultura general: ");
	scanf("%f", &pc);
	tpc = tpc + pc;
	printf("\nPuntos por belleza: ");
	scanf("%f", &pb);
	tpb = tpb + pb;
	if ( tpb < tpc && tpb < tpi)
	{
		menor[0] = 'B';
		menor[1] = 'e';
		menor[2] = 'l';
		menor[3] = 'l';
		menor[4] = 'e';
		menor[5] = 'z';
		menor[6] = 'a';
	}
	if ( tpc < tpb && tpc < tpi)
	{
		menor[0] = 'C';
		menor[1] = 'u';
		menor[2] = 'l';
		menor[3] = 't';
		menor[4] = 'u';
		menor[5] = 'r';
		menor[6] = 'a';
		menor[7] = ' ';
		menor[8] = 'G';
		menor[9] = 'e';
		menor[10] = 'n';
		menor[11] = 'e';
		menor[12] = 'r';
		menor[13] = 'a';
		menor[14] = 'l';
	}
	if ( tpi < tpb && tpi < tpc)
	{
		menor[0] = 'I';
		menor[1] = 'n';
		menor[2] = 't';
		menor[3] = 'e';
		menor[4] = 'l';
		menor[5] = 'i';
		menor[6] = 'g';
		menor[7] = 'e ';
		menor[8] = 'n';
		menor[9] = 'c';
		menor[10] = 'i';
		menor[11] = 'a';
	}
	suma = pi + pc + pb;
	total = total + suma;
	if( band == 0 || suma > msuma )
	{
		for( j = 0; j <= 20; j++ )
		mnombre[j] = nombre[j];
		band = 1;
	}
}
clrscr();
printf("\nEl nombre de la concursante de mayor puntaje general fue: %s", mnombre);
printf("\nEl puntaje acumulado de todas las concursantes en las tres categorias es: %.2f", total);
printf("\nLa categoria en la que hubo menos cantidad de puntos fue en: Puntos por %s", menor);
gotoxy(1,50);
printf("Presione una tecla para salir");
getch();
}