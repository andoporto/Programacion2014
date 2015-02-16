#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 30

typedef struct
{
    float sueldo;
    int dni;
    char nom[TAM],ape[TAM];

} t_empleados;

typedef struct
{
    float prom;
    int dni;
    char nom[TAM],ape[TAM];

} t_estudiantes;


void carga_registros_estudiantes(t_estudiantes *);
void carga_registros_empleados(t_empleados *);
void actualizar_empleados(FILE* ,FILE *);
int menu();
void mostrar_empleados(FILE* );
void mostrar_estudiantes(FILE *);

int main()
{
    FILE* pem;
    FILE* pes;
    int salida=0;
    t_estudiantes est;
    t_empleados emp;

    if(!(pem=fopen("empleados","r+b")))
        if(!(pem=fopen("empleados","w+b")))
        {
            printf("\nerror al crear o abrir el archivo empleados");
            system("pause");
            exit(1);
        }

    if(!(pes=fopen("estudiantes","r+b")))
        if(!(pes=fopen("estudiantes","w+b")))
        {
            printf("\nerror al crear o abrir el archivo estudiantes");
            system("pause");
            exit(1);
        }

    while((salida=menu())!=0)
    {
        switch(salida)
        {
        case 1:
            do
            {
                carga_registros_empleados(&emp);
                fseek(pem,0,2);
                fwrite(&emp,sizeof(t_empleados),1,pem);
                printf("\n 1-Cargar mas Registros de empleados\n0-Salir ");
                scanf("%d",&salida);
                do
                {
                    if(salida<0 || salida>1)
                    {
                        printf("\nopcion incorrecta...");
                        system("pause");
                        system("cls");
                    }
                }
                while(salida<0 || salida>1);
            }
            while(salida==1);
            break;
        case 2:
            do
            {
                carga_registros_estudiantes(&est);
                fseek(pes,0,2);
                fwrite(&est,sizeof(t_estudiantes),1,pes);
                do
                {
                    printf("\n1-Cargar mas Registros de estudiantes\n0-Salir ");
                    scanf("%d",&salida);


                    if(salida<0 || salida>1)
                    {
                        printf("\nopcion incorrecta...");
                        system("pause");
                        system("cls");
                    }
                }
                while(salida<0 || salida>1);
            }
            while(salida==1);
            break;
        case 3:
            fseek(pes,0,0);
            fseek(pem,0,0);
            actualizar_empleados(pes,pem);
            do
            {
                system("cls");
                printf("\ndesea ver el archivo actualizado?\n1-si\n0-no");
                scanf("%d",&salida);
                if(salida<0 || salida>1)
                {
                    printf("\nopcion incorrecta...\n");
                    system("pause");
                }
            }
            while(salida<0 || salida>1);

            if(salida==1)
            {
                fseek(pem,0,0);
                mostrar_empleados(pem);
                system("pause");
            }
            break;
        case 4:

            fseek(pem,0,0);
            mostrar_empleados(pem);
            system("pause");

            break;

        case 5:
            fseek(pes,0,0);
            mostrar_estudiantes(pes);
            system("pause");
            break;
        }
    }
    fclose(pem);
    fclose(pes);
    return 0;
}
/////////////////////////////////////////////////////////////
int menu()
{
    int opcion;

    do
    {
        system("cls");
        printf("Menu Principal \n\n");
        printf("1- Insertar Registros de empleados.\n");
        printf("2- Insertar registros de estudiantes.\n");
        printf("3- Actualizar registros(Merge).\n");
        printf("4- Mostrar Registros de empleados.\n");
        printf("5- Mostrar Registros de estudiantes.\n");
        printf("0- Salir \n");
        scanf("%d",&opcion);
        if(opcion<0 || opcion>5)
        {
            printf("\nopcion incorrecta...\n");
            system("pause");
        }
    }
    while (opcion<0||opcion>5);

    return opcion;
}

////////////////////////////////////////////////////////////////
void carga_registros_empleados(t_empleados * emp)
{
    system("cls");
    printf("DATOS DEL EMPLEADO");
    printf("\n\ningrese DNI: ");
    scanf("%d",&emp->dni);
    printf("\ningrese Apellido: ");
    fflush(stdin);
    scanf("%[^\n]",emp->ape);
    fflush(stdin);
    printf("\ningrese Nombre: ");
    fflush(stdin);
    scanf("%[^\n]",emp->nom);
    fflush(stdin);
    printf("\ningrese sueldo: ");
    scanf("%f",&emp->sueldo);

}
///////////////////////////////////////////////////////////////////
void carga_registros_estudiantes(t_estudiantes* est)
{
    system("cls");
    printf("DATOS DEL ESTUDIANTE");
    printf("\n\ningrese DNI: ");
    scanf("%d",&est->dni);
    printf("\ningrese Apellido: ");
    fflush(stdin);
    scanf("%[^\n]",est->ape);
    fflush(stdin);
    printf("\ningrese Nombre: ");
    fflush(stdin);
    scanf("%[^\n]",est->nom);
    fflush(stdin);
    printf("\ningrese promedio: ");
    scanf("%f",&est->prom);
}
/////////////////////////////////////////////////////////////////
void mostrar_empleados(FILE* pem)
{
    t_empleados emp;

    fread(&emp,sizeof(t_empleados),1,pem);

    while(!feof(pem))
    {
        printf("\n\n-DNI: %d \n-APELLIDO: %s \n-NOMBRE: %s \n-sueldo: %f\n",emp.dni,emp.ape,emp.nom,emp.sueldo);
        fread(&emp,sizeof(t_empleados),1,pem);
    }
}
//////////////////////////////////////////////////////////////////////
void mostrar_estudiantes(FILE* pes)
{
    t_estudiantes est;

    fread(&est,sizeof(t_estudiantes),1,pes);

    while(!feof(pes))
    {
        printf("\n\n-DNI: %d \n-APELLIDO: %s \n-NOMBRE: %s \n-promedio: %f",est.dni,est.ape,est.nom,est.prom);
        fread(&est,sizeof(t_estudiantes),1,pes);
    }

}
///////////////////////////////////////////////////////////////////////
void actualizar_empleados(FILE* pes,FILE* pem)
{
    t_estudiantes est;
    t_empleados emp;

    fread(&est,sizeof(t_estudiantes),1,pes);
    fread(&emp,sizeof(t_empleados),1,pem);

    while(!feof(pes) && !feof(pem))
    {
        if(strcmp(emp.ape,est.ape)==0 && strcmp(emp.nom,est.nom)==0 && (emp.dni)==(est.dni) && (est.prom)>7)
        {
            emp.sueldo*=1.0728;
            fseek(pem,-sizeof(t_empleados),1);
            fwrite(&emp,sizeof(t_empleados),1,pem);
            fseek(pem,sizeof(t_empleados),1);
            fread(&est,sizeof(t_estudiantes),1,pes);
            fread(&emp,sizeof(t_empleados),1,pem);
        }
        else
        {
            if(strcmp(emp.ape,est.ape)==0 && strcmp(emp.nom,est.nom)==0 && (emp.dni)==(est.dni))
            {
                fread(&est,sizeof(t_estudiantes),1,pes);
                fread(&emp,sizeof(t_empleados),1,pem);
            }
        }

        if(strcmp(emp.ape,est.ape)>0)
            fread(&est,sizeof(t_estudiantes),1,pes);
        else
        {
            if(strcmp(emp.ape,est.ape)<0)
                fread(&emp,sizeof(t_empleados),1,pem);
            else
            {
                if(strcmp(emp.nom,est.nom)>0)
                    fread(&est,sizeof(t_estudiantes),1,pes);
                else
                {
                    if(strcmp(emp.nom,est.nom)<0)
                        fread(&emp,sizeof(t_empleados),1,pem);
                    else
                    {
                        fread(&est,sizeof(t_estudiantes),1,pes);
                        fread(&emp,sizeof(t_empleados),1,pem);
                    }
                }
            }
        }
    }
}
