#include<stdio.h>
#include<conio.h>

typedef struct{
    char apellido[30];
    char nombre[30];
    float promedio;}t_alumno;

int menu();
void cargarAlumno (t_alumno*);
void mostrarAlumno (FILE*);
void main()
{
 FILE *pt;
 t_alumno reg;
 int salida=1;

      if(!(pt=fopen("RegistroTexto.txt","r+t")))
        if(!(pt=fopen("RegistroTexto.txt","w+t")))
        {
            printf("\nerror al crear o abrir el archivo de texto");
            system("pause");
            exit(0);

        }

    while((salida=menu())!=0)
    {
        switch(salida)
        {
          case 1:
                    cargarAlumno(&reg);
                    fseek(pt,0,2);
                    fprintf(pt,"%s|%s|%f\n",reg.apellido,reg.nombre,reg.promedio);  //texto variable

            break;
          case 2:
                    fseek(pt,0,0);
                    mostrarAlumno(pt);
            break;
        }
        system("pause");
    }
    fclose(pt);
}
/////////////////////////MENU///////////////////////////////
int menu()
{
    int opcion;
    do {
            system("cls");
            printf("Menu Principal \n");
            printf("1- Insertar Registros de texto.\n");
            printf("2- Mostrar Registros de texto \n");
            printf("0- Salir \n");
            scanf("%d",&opcion);
         } while (opcion<0||opcion>2);
    return opcion;
}
//////////////////////////////////////////////////////////
void cargarAlumno(t_alumno* reg)
{
        printf("\nIngrese Apellido: ");
        fflush(stdin);
        gets(reg->apellido);

        printf ("\nIngrese Nombre: ");
        fflush(stdin);
        gets(reg->nombre);

        printf("\nIngrese Promedio: ");
        scanf("%f", &reg->promedio);

}
///////////////////////////////////////////
void mostrarAlumno (FILE* pt)
{
    t_alumno reg;
    char cad[200];
    while(!feof(pt))
    {
            fscanf(pt,"%[^|]|%[^|]|%f\n",reg.apellido,reg.nombre,&reg.promedio); //texto variable
            printf("\nApellido: %s Nombre: %s Promedio: %.2f\n", reg.apellido, reg.nombre, reg.promedio);

    }
}

