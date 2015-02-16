#include <conio.h>
#include <stdio.h>
#include <stdlib.h>


struct datos
{
    long int dni;
    char nom[35];
    int edad;
};

struct nodo
{
    struct datos info;
    struct nodo *sig;
};

struct t_pila
{
    nodo *tope;
};



void inicializa(struct t_pila *);
int ingresar(struct datos *);
nodo * nuevo_nodo();
void carga_pila(struct datos ,struct t_pila **);
void crear_pila(struct t_pila **);
void menu(struct t_pila **);


int main()
{

    t_pila *pila;
//nodo *tope=NULL;

    inicializa(pila);
    for(;;)
        menu(&pila);

    return 0;
}



////////////////////////////////////////////////////////////////////////////////
void inicializa(struct t_pila *p)
{
    p->tope=NULL;
}
////////////////////////////////////////////////////////////////////////////////
int ingresar(struct datos *d)
{
    do
    {
        printf("\nINGRESE EL DNI:");
        scanf("%ld",&d->dni);
        fflush(stdin);
    }
    while(d->dni<0 || d->dni>90000000L);

    if(!d->dni)
        return 0;
    printf("\nINGRESE EL NOMBRE:");
    fgets(d->nom,35,stdin);

    do
    {
        printf("\nINGRESE LA EDAD:");
        scanf("%d",&d->edad);
    }
    while(d->edad < 0 || d->edad > 105);

    return 1;
}
////////////////////////////////////////////////////////////////////////////////
nodo * nuevo_nodo()
{
    nodo*q;

    q=(nodo*)malloc(sizeof(struct nodo));
    if(!q)
    {
        printf("\nERROR AL ASIGNAR MEMORIA");
        getch();
        exit(1);
    }

    return q;

}


////////////////////////////////////////////////////////////////////////////////
void cargar_pila(struct datos d,struct t_pila **p)
{
    nodo *q;

    nodo *aux=(*(*p)).tope;
    q=nuevo_nodo();

    q->info=d;
    q->sig=aux;
    aux=q;


}



////////////////////////////////////////////////////////////////////////////////
void crear_pila(struct t_pila **p)
{
    struct datos d;
    int flag;
    flag=ingresar(&d);
    while(flag)
    {
        cargar_pila(d,p);
        flag=ingresar(&d);
    }
}
////////////////////////////////////////////////////////////////////////////////
void desenlistar(struct t_pila **p)
{
    nodo *aux;

    aux=(*p)->tope;
    while(aux)
    {
        printf("\n----------------------------");
        printf("\nDNI: %ld",aux->info.dni);
        printf("\nNOMBRE: %s",aux->info.nom);
        printf("\nEDAD: %d\n",aux->info.edad);


        aux=aux->sig;


    }
    getch();

}

////////////////////////////////////////////////////////////////////////////////
void menu(struct t_pila **p)
{
    int opc;

    printf("\n1.CREAR PILA ");
    printf("\n0.SALIR");
    printf("\nINGRESE SU OPCION :");
    scanf("%d",&opc);

    switch (opc)
    {
    case 1:
        crear_pila(p);
        break;

    case 2:
        desenlistar(p);
        break;

    case 0:
        exit(0);
        break;

    default:
        printf("\nOPCION NO VALIDA!!!");
        getch();
        break;
    }



}
