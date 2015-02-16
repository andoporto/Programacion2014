#include <stdio.h>
#include <stdlib.h>

struct t_fecha
{
    int dd;
    int mm;
    int aa;

};



int main()
{
    struct t_fecha fecha;
    printf("El dìa es: ");
    scanf("%d",&fecha.dd);



    return 0;
}
