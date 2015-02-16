#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int* buscar (int *);

int main()
{
    int array[]={1, 2, 3, 4, 5};
    int *pa;
    pa=&array[0];
    pa=buscar(pa);
    printf("%p", pa);
    return 0;
}

int* buscar (int *array)
{
    int elemento, i;
    printf("Ingrese elemento a buscar: ");
    scanf("%d", &elemento);
    for (i=0; i<TAM; i++)
    {
        if (*(array+i)==elemento)
        {
            return array+i;
        }
    }
    return NULL;
}
