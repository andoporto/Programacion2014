#include <stdio.h>
#include <conio.h>

#define TAM 3

typedef struct
{long int num;}t_info;

typedef struct
{int tope;
 t_info pila[TAM];
}t_pila;

int pila_llena(const t_pila *);
void crear_pila(t_pila *);
void cargar_datos(t_info *);
int apilar (t_pila *,const t_info*);
void suma (t_pila *,t_pila*,t_info * );
int ver_tope (const t_pila*,t_info*);

void main()
{t_pila pila1,pila2,pila_res;
 t_info dato1,dato2,dato_res;
   long int sum;
      if(!pila_llena(&pila1))
         { if(!pila_llena(&pila2))
                {crear_pila(&pila1);
                 crear_pila(&pila2);
                 crear_pila(&pila_res);
                 }
         }
      while(!pila_llena(&pila1) && !pila_llena(&pila2))
          { cargar_datos(&dato1);
            cargar_datos(&dato2);
               if(apilar(&pila1,&dato1))
                    puts("¡pila 1 apilo bien!");
               if(apilar(&pila2,&dato2))
                      puts("¡pila 2 apilo bien!");
              suma(&pila1,&pila2,&dato_res);
                  //dato_res.num=sum;
                if(apilar(&pila_res,&dato_res))
                     puts("se apilo la suma!");
          }
printf("el numero del tope es:%d\t",ver_tope(&pila_res,&dato_res));
//printf("la suma total es: %d",sum);
getch();
}

int pila_llena(const t_pila *p)
{ return (p->tope==TAM);
}

void crear_pila(t_pila* p)
{p->tope=0;}

void cargar_datos(t_info *d)
{  printf("ingrese el numero:\n");
      scanf("%d",&d->num);
}

int apilar(t_pila *p,t_info *d)
{  if(p->tope==TAM)
         return 0;
     p->pila[p->tope]=*d;
         p->tope++;
           return 1;
}

void suma (t_pila *p1,t_pila *p2,t_info *d)
{  //int suma;
         //*d = (p1->pila[p1->tope-1])+(p2->pila[p2->tope-1]);/////////////////ACA ME TIRA EL WARNING/////////////////////////
		 d->num = p1->pila[p1->tope-1].num + p2->pila[p2->tope-1].num;
    //return suma;
}

int ver_tope(const t_pila *p , t_info *d)
{  if(p->tope==0)
      return 0;
    *d = p->pila[p->tope];
       return 1;
}