#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 100

void cargar (char *);
void mostrar (char *, const char *);
char* stringCopy (char *, const char *);

int main()
{
    char cad1[TAM], cad2[TAM];
    cargar(cad2);
    stringCopy(cad1,cad2);
    mostrar(cad1, cad2);
    return 0;
}

void cargar (char *cad2)
{
    gets(cad2);
}

void mostrar (char *cad1, const char *cad2)
{
    puts(cad1);
    printf("strcpy: %s", strcpy(cad1,cad2));
}

char* stringCopy (char *cad1, const char *cad2)
{
    int i=0;
    while (*(cad2+i)!='\0')
    {
        *(cad1+i)=*(cad2+i);
        i++;
    }
    *(cad1+i)='\0';
    return cad1;
}
