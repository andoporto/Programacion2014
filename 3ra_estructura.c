#include <stdio.h>
#include <stdlib.h>


struct t_fecha
{
    int dd;
    int mm;
    int aa;

};


struct t_alumno
{
    int dni;
    int ap[TAM];
    int nom[TAM];
    struct t_fecha fnac;
};



0l
�
int main()
{
    struct t_fecha fecha;
    printf("El d�a es: ");
    scanf("%d",&fecha.dd);



    return 0;
}
