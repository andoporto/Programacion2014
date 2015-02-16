#include<stdio.h>
#include<conio.h>
int main()
{
	int x1,x2,y1,y2,i,j,y,arr1[10][10],arr2[10][10],arr[10][10],m,n;

	clrscr();
	gotoxy(9,1);
	cprintf(":::PROGRAMA PARA CALCULAR EL PRODUCTO DE DOS MATRICES:::");
	gotoxy(11,3);
	cprintf(" Que dimension x para la primera matriz: ");
	cscanf("%d",&x1);
	gotoxy(11,5);
	cprintf(" Que dimension y para la primera matriz: ");
	cscanf("%d",&y1);
	gotoxy(11,7);
	cprintf(" Que dimension x para la segunda matriz: ");
	cscanf("%d",&x2);
	gotoxy(11,9);
	cprintf(" Que dimension y para la segunda matriz: ");
	cscanf("%d",&y2);
	if(y1!=x2)
	 {
		gotoxy(11,11);
		cprintf("No puedo multiplicar esto!!");
	 }
	else
	{
	for(i=0;i<10;i++)
		for(j=0;j<10;j++)
			{
			arr[i][j]=0;
			arr1[i][j]=0;
			arr2[i][j]=0;
			}
	clrscr();
	gotoxy(1,1);
	cprintf("Valores de la primera matriz: ");
	for(j=0;j<x1;j++)
		for(i=0;i<y1;i++)
		{
		gotoxy((i+1)*4,j+5);
		scanf("%d",&arr1[i][j]);
		}
	gotoxy(36,1);
	cprintf("Valores de la segunda matriz: ");
	for(j=0;j<x2;j++)
		for(i=0;i<y2;i++)
		{
		gotoxy((i+12)*(4),j+5);
		scanf("%d",&arr2[i][j]);
		}
	m=0; n=0; y=0;
	while(y<(x1*y2))
	{
	for(j=0;j<y1;)
	{
		for(i=0;i<x2;i++)
			{
			arr[m][n]+=(arr1[i][m])*(arr2[j][i]);
			}
			if(i==x2)
				n++;
			j++;
			if(j==y1)
				{
				m++;
				n=0;
				}
	}
y++;
}
gotoxy(9,13);
cprintf("El resultado de la matriz 1 * la matriz 2");
for(j=0;j<x1;j++)
		for(i=0;i<y2;i++)
		{
		gotoxy((i+7)*(4),j+15);
		printf("%d",arr[j][i]);
}
getch();

}
getch();
return 0;
}
