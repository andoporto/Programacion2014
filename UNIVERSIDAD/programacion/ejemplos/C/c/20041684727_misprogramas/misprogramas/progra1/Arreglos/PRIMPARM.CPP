#include<stdio.h>
#include<conio.h>
void main()
{
	int i,n[10],par=0,impar=0,mayor=0,menor=0,moda=0,j,d=0,cont=0,suma=0,prom=0,opc,primo=0;
	clrscr();
	for(i=0;i<10;i++)
	{
		gotoxy(15,8);printf("Introduce numero %d: ",i+1); scanf("%d",&n[i]);
		clrscr();
	}
for(;;)
{
	clrscr();
	gotoxy(20,7);printf("1.Total numeros pares\n2.Total numeros impares\n3.total de numeros primos\n4.Promedio\n5.Numero mayor\n6.Numero menor\n7.Moda\n8.Salir");
	gotoxy(20,16);printf("Selecciona una opcion: ");scanf("%d",&opc);
	switch(opc)
	{
		case 1:
			clrscr();
			 for(i=0;i<10;i++)
			 {
				if(!(n[i]%2))
					par++;
				else
					impar++;
			 }
			 printf("El total de numeros pares es: %d ",par);
			 getch();
		break;
		case 2:
			clrscr();
			printf("El total de numeros impares es: %d ",impar);getch();
		break;
		case 3:
			clrscr();i=0;
			for(j=2;j<n[i];j++)
			{
				for(i=0;i<10;i++)
				{
					if(n[i]%j!=0)
						 primo++;
				}
			}
			printf("El total de numeros primos es: %d ",primo);getch();
		break;
		case 4:
			clrscr();
			for(i=0;i<10;i++)
				suma=suma+n[i];
			prom=suma/10;
			printf("El promedio es: %d",prom);getch();
		break;
		case 5:
			clrscr();
			mayor=n[0];menor=n[0];
			for(i=1;i<10;i++)
			{
				if(n[i]>mayor)
					mayor=n[i];
				if(n[i]<menor)
					menor=n[i];
			}
			printf("El numero mayor es: %d",mayor);getch();
		break;
		case 6:
			clrscr();
			printf("El numero menor es: %d",menor);getch();
		break;
		case 7:
			clrscr();cont=0;d=0;
			for(j=0;j<9;j++)
			{
				for(i=j+1;i<10;i++)
				{
					if(n[j]==n[i])
						cont++;
				}
				if(cont>d)
				{
					moda=n[j];d=cont;
				}
				cont=0;
			}
			printf("La moda es: %d",moda);getch();
		break;
		case 8: break;
		default:printf("No existe tal opcion!!!");
	}
	if(opc==8)
		break;
}
}
/*for(x=0;x<(n-1);x++)
	for(y=x+1;y<10;y++)
	{
		if(num[x]>num[y])
		{
			arr=num[y];
			num[y]=num[x];
			num[x]=arr;
		}
	}*/