/*//////////////////////////////////////////////////////////////////////
alumno          Miguel Angel Cajero Amador
carrera         Inggeniero en Cibernetica
programa        promedios
fecha           09 enero 2005
profesor        serna
*///////////////////////////////////////////////////////////////////////

# include <stdio.h>
# include <conio.h>

void intro();
void modif();
void borra();
void consu();
void error();
void promedia();
void pantalla();


struct
{
	char nombre[50];
	int porcen_asistencia;
	float parcial_1;
	float parcial_2;
	float parcial_3;
	float prom_parcial;
	float cal_semestral;
	float cal_final;
}datos;

FILE *fichero;

	char opc,nom[30];
	int tama;

main()
{
	for(;;)
		{
			clrscr();
			pantalla();
			gotoxy(35,8);printf("Menu principal");
			gotoxy(29,10);printf("1.- Dar de alta alumnos");
			gotoxy(29,12);printf("2.- modificar alumnos");
			gotoxy(29,14);printf("3.- borrar alumnos");
			gotoxy(29,16);printf("4.- consultar");
			gotoxy(29,18);printf("5.- finalizar");
			gotoxy(29,22);printf("escoge una opcion...");
			opc=getch();

			switch(opc)
			{
				case '1':intro();break;
				case '2':modif();break;
				case '3':borra();break;
				case '4':consu();break;
				case '5':exit(0);
				default: break;
			}
		}
}

/*verifica como te calificaran*/
void promedia()
{
clrscr();

	datos.prom_parcial=(datos.parcial_1+datos.parcial_2+datos.parcial_3)/3;
	datos.cal_final=datos.prom_parcial/2+datos.cal_semestral/2;

	if(datos.porcen_asistencia<80)
     {
	printf("%s \n",datos.nombre);
	printf("\n");
	printf("Tu asistencia es de: %d \n",datos.porcen_asistencia);
	printf("\n");
	printf("Por  lo  tanto  tu  calificacion  es  SD \n");
	printf("(sin derecho a calificacion final)");

     }
     else
     {
	if((datos.parcial_1<=5.9 && datos.parcial_2<=5.9) || (datos.parcial_1<=5.9 && datos.parcial_3<=5.9) || (datos.parcial_2<=5.9 && datos.parcial_3<=5.9))
	{
		printf("%s \n",datos.nombre);
		printf("\n");
		printf("Tu asistencia es de: %d \n",datos.porcen_asistencia);
		printf("\n");
		printf("Pero tienes dos parciales reprobados \n");
		printf("\n");
		printf("Por  lo  tanto  tu  calificacion  es  REC \n");
		printf("(recursar para obtener una calificacion final)");
	}
	else
	{
		if(datos.prom_parcial<6)
		{
			printf("%s \n",datos.nombre);
			printf("\n");
			printf("Tu asistencia es de: %d \n",datos.porcen_asistencia);
			printf("\n");
			printf("Pero tu promedio de los parciales es menor a 6 \n");
			printf("\n");
			printf("Por  lo  tanto  tu  calificacion  es  EE \n");
			printf("(examen extraordinario para obtener una calificacion final)");
		}
		else
		{
			printf("%s \n",datos.nombre);
			printf("\n");
			printf("\n");
			printf("Tu asistencia es de: %d \n",datos.porcen_asistencia);
			printf("\n");
			printf("Y tu calificacion final es:%d",datos.cal_final);
		}
	}
    }
   printf(" \nNombre | asistencia |   1ø  |   2ø  |   3ø  | Prom. | Sem. | Final |\n\n\n");



       printf(datos.nombre);
       printf("\tº%d",datos.porcen_asistencia);
       printf("º%f",datos.parcial_1);
       printf("º %f",datos.parcial_2);
       printf("º%f",datos.parcial_3);
       printf("º%f",datos.prom_parcial);
       printf("º %f",datos.cal_semestral);
       printf("º %f",datos.cal_final);
       printf("\n\n");


}
/* grabar registros */
void intro()
{
int s;
char w;
	clrscr();
	if((fichero=fopen("altasalu.dat","ab"))==NULL)error();
       for(;;)
	{
		clrscr();
		pantalla();

		gotoxy(28,8);printf("Registrar alumno");
		gotoxy(20,10);printf("Nombre alumno:");
		gotoxy(20,12);printf("porcentaje de asistencias:");
		gotoxy(20,14);printf("primer paracial:");
		gotoxy(20,16);printf("segundo paracial:");
		gotoxy(20,18);printf("tercer paracial:");
		gotoxy(20,20);printf("examen semestral:");
		gotoxy(35,10);scanf("%s",&datos.nombre);
		gotoxy(50,12);scanf("%d",&datos.porcen_asistencia);
		gotoxy(50,14);scanf("%f",&datos.parcial_1);
		gotoxy(50,16);scanf("%f",&datos.parcial_2);
		gotoxy(50,18);scanf("%f",&datos.parcial_3);
		gotoxy(50,20);scanf("%f",&datos.cal_semestral);


		gotoxy(20,22);printf("Datos correctos (S/N):");
		opc=toupper(getch());
		if(opc=='S')fwrite(&datos,sizeof(datos),1,fichero);
		promedia();
	      gotoxy(20,22);printf("Desea agregar otro alumno (S/N):");
		w=toupper(getch());
		if((w)=='N')break;
}
	fclose(fichero);
}


/* modificar registros*/

void modif()
{
	clrscr();
	pantalla();
	tama=sizeof(datos);
	if((fichero=fopen("altasalu.dat","r+b"))==NULL)error();
	gotoxy(15,12);printf("introduce nombre a modificar:");
	gets(nom);
	clrscr();
	while(!feof(fichero))
	{
		fread(&datos,sizeof(datos),1,fichero);
		if(strcmp(datos.nombre,nom)==0)
		{
			pantalla();
			gotoxy(18,7);printf("1.- Nombre  : %s",datos.nombre);
			gotoxy(18,9);printf("2.-porcentaje de asistencias: %d",datos.porcen_asistencia);
			gotoxy(18,11);printf("3.-primer paracial: %f",datos.parcial_1);
			gotoxy(18,13);printf("4.-segundo paracial: %f",datos.parcial_2);
			gotoxy(18,15);printf("5.-tercer paracial:  %f",datos.parcial_3);
			gotoxy(18,18);printf("6.-examen semestral: %f",datos.cal_semestral);
			gotoxy(18,20);printf("7.-salir de las modificaciones:");
			while(opc!='7')
			{
				gotoxy(18,22);printf("Campo a modificar");
				opc=getch();
				gotoxy(18,19);clreol();
				switch(opc)
				{
					case '1' :gotoxy(31,7);clreol();
					scanf("%s",&datos.nombre);break;
					case '2' :gotoxy(48,9);clreol();
					scanf("%d",&datos.porcen_asistencia);break;
					case '3' :gotoxy(38,11);clreol();
					scanf("%f",&datos.parcial_1);break;
					case '4' :gotoxy(38,13);clreol();
					scanf("%f",&datos.parcial_2);break;
					case '5' :gotoxy(38,15);clreol();
					scanf("%f",&datos.parcial_3);break;
					case '6' :gotoxy(38,17);clreol();
					scanf("%f",&datos.cal_semestral);break;
					case '7' :fseek(fichero,-tama,SEEK_CUR);
					fwrite(&datos,sizeof(datos),1,fichero);break;
					default:break;
				}
			}
			break;
		}
	}
	fclose(fichero);
}


/* borrar registros */

void borra()
{
	clrscr();
	pantalla();
	tama=sizeof(datos);
	if((fichero=fopen("altasalu.dat","r+b"))==NULL)error();
	gotoxy(15,12);printf("Introduce nombre a borrar: ");
	gets(nom);
	clrscr();
	while(!feof(fichero))
	{
		fread(&datos,sizeof(datos),1,fichero);
		if(strcmp(datos.nombre,nom)==0)
		{
			pantalla();
			gotoxy(20,7);printf("Nombre  : %s",datos.nombre);
			gotoxy(20,9);printf("porcentaje de asistencias: %d",datos.porcen_asistencia);
			gotoxy(20,11);printf("primer paracial: %f",datos.parcial_1);
			gotoxy(20,13);printf("segundo paracial: %f",datos.parcial_2);
			gotoxy(20,15);printf("tercer paracial:  %f",datos.parcial_3);
			gotoxy(20,18);printf("examen semestral: %f",datos.cal_semestral);
			gotoxy(20,20);printf("Estas seguro de querer borrarlo (S/N)");

			opc=toupper(getch());
			clrscr();
			if(opc=='S')
			{
				strcpy(datos.nombre,"*");
				fseek(fichero,-tama,SEEK_CUR);
				fwrite(&datos,sizeof(datos),1,fichero);
				break;
			}
		}
	}
	close(fichero);
}


/*consultar un registro*/
void consu()
{
	clrscr();
	pantalla();
	if((fichero=fopen("altasalu.dat","rb"))==NULL)error();
	gotoxy(15,12);printf("Introduce nombre a consultar:");
	gets(nom);
	clrscr();
	while(!feof(fichero))
	{
		fread(&datos,sizeof(datos),1,fichero);
		if(strcmp(datos.nombre,nom)==0)
		{
			pantalla();
			gotoxy(20,7);printf("Nombre  : %s",datos.nombre);
			gotoxy(20,9);printf("porcentaje de asistencias: %d",datos.porcen_asistencia);
			gotoxy(20,11);printf("primer paracial: %f",datos.parcial_1);
			gotoxy(20,13);printf("segundo paracial: %f",datos.parcial_2);
			gotoxy(20,15);printf("tercer paracial:  %f",datos.parcial_3);
			gotoxy(20,18);printf("examen semestral: %f",datos.cal_semestral);
			getch();
			break;
		}
	}
	fclose(fichero);
}



/* error en apertura */
void error()
{
	clrscr();
	pantalla();
	printf("Error no puedo abrir el fichero");
	getch();
	exit(0);
}

void pantalla()
{
	int x=1;
	int y=1;
	int i=1;
	clrscr();
///////////////////////////////////////////////////horizontal
	gotoxy(23,3);printf(" -------LISTA DE ALUMNOS------ ");
	for(y=i;y<=5;y++)
	{

		for(x=1;x<=80;x++)
		{
			gotoxy(x,y);printf("Í");
		 }
	y=i+3;
	i=y;
	 }
		for(x=1;x<=80;x++)

		{       y=6;
			gotoxy(x,y);printf("Í");
		 }
		for(x=1;x<=80;x++)
		{       y=24;
			gotoxy(x,y);printf("Í");
		 }


////////////////////////////////////////////////////vertical
		for(y=1;y<=5;y++)
		{
			x=1;
			gotoxy(x,y);printf("º");
		 }
		for(y=1;y<=5;y++)
		{
			x=80;
			gotoxy(x,y);printf("º");
		 }
		for(y=6;y<=24;y++)
		{       x=1;
			gotoxy(x,y);printf("º");
		 }
		for(y=6;y<=24;y++)
		{       x=80;
			gotoxy(x,y);printf("º");
		 }


/////////////////////////////////////////////////////esquinas
	gotoxy(1,1);printf("É");
	gotoxy(1,5);printf("È");
	gotoxy(80,1);printf("»");
	gotoxy(80,5);printf("¼");
	gotoxy(1,6);printf("É");
	gotoxy(1,24);printf("È");
	gotoxy(80,6);printf("»");
	gotoxy(80,24);printf("¼");





   }




