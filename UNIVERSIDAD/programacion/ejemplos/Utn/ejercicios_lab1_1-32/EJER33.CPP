#include<stdio.h>
#include<conio.h>

void main ()
{
	float x,total,max,min;
	int c,flag,d,maydi,mindi;
	total=0;
	max=0;
	flag=0;
	clrscr();
	printf("\nIngrese la cantidad de dias que tiene el mes: ");
	scanf("%d",&d);
	for(c=0;c<d;c++)
	{
		clrscr();
		printf("\nIngrese la cantidad de lluvia (mm) del dia %d: ",c+1);
		scanf("%f",&x);
		if(flag==0)
		{
			min=x;
			flag=1;
		}
		total=total+x;
		if(x>max)
		{
			max=x;
			maydi=c+1;
		}
		if(x<=min)
		{
			min=x;
			mindi=c+1;
		}
	}
	total=total/c;
	clrscr();
	printf("\nEl promedio de lluvias de este mes es de %.2f mm",total);
	printf("\n\nEl dia de mayor lluvia fue el %d",maydi);
	printf("\n\nEl dia de menor lluvia fue el %d",mindi);
    gotoxy(1,24);
	printf("Presione una tecla para salir");
	getch();

}
