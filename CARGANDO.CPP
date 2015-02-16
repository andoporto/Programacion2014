#include<stdio.h>
#include<conio.h>
#include<DOS.H>
void main()
		  {
		   char opc=110;
		   int i,j,p,n,x,y,mat[10][10],ban=0;

		   clrscr();
		   textcolor(18);
		   gotoxy(30,10);
		   cprintf("Menu principal");
		   textcolor(10);
		   gotoxy(22,20);
		   printf("Cargando");
		   for(i=30;i<=60;i++)
			  {
			   delay(200);
			   gotoxy(i,20);
			   textcolor(12);
			   cprintf("Û");
			  }
		   clrscr();
		   textcolor(12);
		   gotoxy(20,5);
		   cprintf("Programa que analiza la matriz de una relacion");
		   gotoxy(20,6);
		   cprintf("y muestra sus propiedades");
		   delay(5000);
		   clrscr();
		   textcolor(15);
		   gotoxy(20,6);
		   cprintf("De cuantas filas o columnas es la matriz?. ");
		   scanf("%d", &n);
		   for(i=1;i<=n;i++)
			  for(j=1;j<=n;j++)
				  mat[i][j]=0;
		   textcolor(15);
		   gotoxy(20,8);
		   cprintf("Cuantos pares ordenados hay en la relacion?");
		   scanf("%d", &p);
		   clrscr();
		   for(i=1;i<=p;i++)
			  {
			   gotoxy(20,6);
			   printf("Dame el %d par de la relacion ", i);
			   gotoxy(50,6);
			   printf("R: (   ).");
			   gotoxy(55,6);
			   printf(",");
			   gotoxy(54,6);
			   scanf("%d", &x);
			   gotoxy(56,6);
			   scanf("%d", &y);
			   clrscr();
			   mat[x][y]=1;
			  }

		   for(i=1;i<=n;i++)
			  for(j=1;j<=n;j++)
				 {
				  textcolor(15);
				  gotoxy(30+(1*j),6+(1*i));
				  cprintf("%d", mat[i][j]);
				 }
		   for(i=1;i<=n;i++)
			  for(j=1;j<=n;j++)
				 {
				  gotoxy(30,14);
				  if ((mat[i][j]==1)&&(i==j))
					 printf("La matriz es reflexiva\n");
				  gotoxy(30,15);
				  if ((mat[i][j]==0)&&(i==j))
					 printf("La matriz es irreflexiva\n");
				  gotoxy(30,16);
				  if (((mat[i][j]==1)&&(mat[j][i]==1))&&((mat[i][j]==0)&&(mat[j][i]==0)))
					 printf("La relacion es simetrica\n");
				  gotoxy(30,17);
				  if  (((mat[i][j]==0)&&(i==j))&&((mat[i][j]==1)&&(mat[j][i]==0)))
					 printf("La relacion es asimetrica\n");
				  gotoxy(30,18);
				  if ((mat[i][j]==1)&&(mat[j][i]==0))
					 printf("La relacion es antisimetrica\n");
				  for(i=1;i<=n;i++)
					 for(j=1;j<=n;j++)
						{
						 if ((mat[i][j]==1)&&(mat[j][i+1]==1)&&(mat[i][i+1]==1))
							ban=1;
						 else
							ban=0;
						}
				  gotoxy(30,19);
				  if (ban==1)
					 printf("La Matriz es transitiva.");
				 }
		   getch();
		   }
		  }