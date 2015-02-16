#include<stdio.h>
#include<conio.h>
typedef struct
			  {
			   int cont;
			   char nombre[50];
			   int edad;
			   char sexo;
			  }REGISTRO;
void main()
		   {

			FILE *arch;
			REGISTRO alumno;
			clrscr();
			arch=fopen("c:\\alumnos.txt","rb");
			if (arch==NULL)
				printf("Error de apertura");
			else
				{
				 fread(&alumno,sizeof(REGISTRO),1,arch);
				 printf("Nombre:                          Edad:           Sexo:\n");
				 fread(&alumno,sizeof(REGISTRO),1,arch);
				 while (!feof(arch))
					   {
						printf("%d %s        %d        %c\n",  alumno.cont,alumno.nombre, alumno.edad, alumno.sexo);
						fread(&alumno,sizeof(alumno),1,arch);
						getch();
					   }
				 fclose(arch);
				}
				getch();
		   }