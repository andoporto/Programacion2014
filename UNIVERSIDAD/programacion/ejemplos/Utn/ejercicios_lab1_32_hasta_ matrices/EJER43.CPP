#include <stdio.h>
#include <conio.h>
#include <ctype.h>

void main (void){

int hockey=0, futbol=0, tenis=0, rugby=0, voley=0,nsocio, edad, tedadt=0, tedadr=0, tedadv=0, tedadh=0, tedadf=0, dep;
char seguir = 's', apellido[20], nombre[20];

while(seguir=='s')
{
	clrscr();
	printf("Numero de socio: ");
	scanf("%d", &nsocio);
	flushall;
	printf("\nApellido: ");
	scanf("%s", &apellido);
	printf("\nNombre: ");
	scanf("%s", &nombre);
	printf("\nEdad: ");
	scanf("%d", &edad);
	printf("\nTipo de deporte que practica(1 tenis, 2 rugby, 3 voley,4 hockey, 5 futbol): ");
	scanf("%d", &dep);
	switch(dep){
	case 1: tenis=tenis++; tedadt = tedadt + edad; break;
	case 2: rugby=rugby++; tedadr = tedadr + edad; break;
	case 3: voley=voley++; tedadv = tedadv + edad; break;
	case 4: hockey=hockey++; tedadh = tedadh + edad; break;
	case 5: futbol=futbol++, tedadf = tedadf + edad; break;
	}
	fflush(stdin);
	printf("Desea seguir s/n?: ");
	scanf("%c", &seguir);
	seguir = tolower(seguir);
}
printf("La cantidad de socios que practican tenis son %d y los que practican futbol son %d", tenis, futbol);
printf("\nEl promedio de edad de los que practican tenis es de %d a¤os", tedadt / tenis);
printf("\nEl promedio de edad de los que practican rugby es de %d a¤os", tedadr / rugby);
printf("\nEl promedio de edad de los que practican voley es de %d a¤os", tedadv / voley);
printf("\nEl promedio de edad de los que practican hockey es de %d a¤os", tedadh / hockey);
printf("\nEl promedio de edad de los que practican futbol es de %d a¤os", tedadf / futbol);
gotoxy(1,50);
printf("Presione una tecla para salir");
getch();
}
