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
    printf("El d�a es: ");
    scanf("%d",&fecha.dd);



    return 0;
}
