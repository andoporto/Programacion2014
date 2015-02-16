#include<stdio.h>
#include<conio.h>
void main ()
{
clrscr();
int m1[99][99],i,j,l,m,r1=0,r2=0,cont=0,cont2=0;
 printf("Introduzaca el tama¤o de la matriz ");
 scanf("%d",&l);
	printf("Introduzca el numero de coordenada a introducir:");
	scanf("%d",&m);
	 printf("\n");
		for(i=0;i<l;i++)
		for(j=0;j<l;j++)
		 {
      m1[i][j]=0;
			 }
				printf("\n");
				 for(i=0;i<m;i++){
					printf("Introduzca el valor del dominio para la coordenada #%d\n",i+1);
					 scanf("%d",&r1);
						printf("Introduzaca el valor del codominio\n",i+1);
						 scanf("%d",&r2);
							m1[r1-1][r2-1]=1;
							 }
								for(i=0;i<l;i++){
								 printf("\n");
									for(j=0;j<l;j++)
									 {
										printf("(%d) ",m1[i][j]);
										 }
											}
											 printf("\n");
												printf("Las propiedades de la matriz son:\n ");
												 for(i=0;i<l;i++)
													for(j=0;j<l;j++)
													 {
													 if(i==j)
														{
														 if(m1[i][j])cont+=1;
															 else if(m1[i][j]==0)cont2+=1;
																}
																 }
																 if(cont==l)
																	printf("Reflexiva");
																	 else if(cont2==l)
																		printf("Irreflexiva");
getch();
}