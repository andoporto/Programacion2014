#include <stdio.h>
#include <conio.h>

void main()
{
  clrscr();
  int marca, s, i, j, m, n, r, a, b, a1, b1, pesquisa, x[10][10];
  s=0,r=0;
  printf("Ingrese la cantidad de filas -entre 1 y 10- \n");
  scanf("%d",&m);

  printf("Ingrese la cantidad de columnas -entre 1 y 10- \n");
  scanf("%d",&n);
  printf("Ingrese los valores de la matriz: ");

	for (i=0;i<m;i++)
  		for (j=0;j<n;j++)
  			scanf("%d",&x[i][j]);
  	printf("Ingrese el valor a buscar \n ");
  	scanf("%d",&pesquisa);
  	if (pesquisa < x[0][0] || pesquisa > x[m-1][n-1])
  		printf("Valor  %d fuera de la matriz \n", pesquisa);
  	else
  		s=1;
	if (s==1) {
		marca=1;
		i=0;
			while (i<m && marca==1)  {
				j=0;
				while (j<n && marca==1)  {
					if (pesquisa==x[i][j]) {
						marca=0;r=1;a=i;b=j; }
					else
						if (pesquisa > x[i][j]) {
							marca=1;r=1;a=i;b=j; }
						else {
							marca=0; a1=i; b1=j;  }
						j++;
				}	/*fin del while interior*/
						i++;
			}	/*fin del while exterior*/
	 if (r==1) printf("Coincide con el elemento",a ,b );
	 else { printf("El valor buscado se encuentra entre: \n"); 
			printf("Fila %d Columna %d y la Fila %d Columna %d", a, b, a1, b1); }
	} /*fin el if (s==1)*/
getch();
}




















