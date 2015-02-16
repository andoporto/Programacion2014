//lectura y carga del vector de estructuras de productos

void carga_productos(struct p *x,int n)
{
 int i;
 for (i=0;i<n;i++)ç
 {
  printf("\nIngrese numero de producto\n");
  scanf("%d",&x[i].numero);
  printf("\nIngrese el precio\n");
  scanf("%d",&x[i].precio);
  printf("\nIngrese la descripcion\n");
  fflush(stdin)
  gets("%d",&x[i].descripcion);
  x[i].total=0;
 }
}

//lectura y actualizacion de la informacion de movimientos
void carga_movimientos(struct cl *x,int n,struct p*y,int m,float mat[][30])
{
 int nro,nrocl,nrop,cant,aux,mes,dia,s,i,k,s1;
 long int fecha;
  printf("Ingrese fecha \n");
  scanf("%l",&fecha);
  printf("Ingrese fecha \n"); }
  scanf("%l",&fecha);
 