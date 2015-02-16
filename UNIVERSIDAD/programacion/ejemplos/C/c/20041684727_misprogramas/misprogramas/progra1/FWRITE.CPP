#include<stdio.h>
#include<conio.h>
#include<string.h>
typedef struct
	    {
	     char nombre[50];
	     int edad;
	     char sexo;
	    }REGISTRO;
void main()
	  {
	   FILE *arch;
	   REGISTRO alumno;
	   int i=0;
	   arch=fopen("c:\\alumnos.txt","wb");
	   if (arch==NULL)
	      printf("error de apertura");
	   else
	      {
	       for (i=1;i<=5;i++)
		   {
		    fflush(stdin);
		    printf("Nombre: %d", i);gets(alumno.nombre);
		    fflush(stdin);
		    printf("edad: %d", i);scanf("%d", &alumno.edad);
		    fflush(stdin);
		    printf("sexo: %d", i);
		    alumno.sexo=getchar();
		    fwrite(&alumno,sizeof(alumno),2,arch);
		   }
	      }
	    fclose(arch);
	  }  	      