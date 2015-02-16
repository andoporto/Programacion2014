#include<stdio.h>
#include<conio.h>
void main()
{
clrscr();
int i=0,lc=0,ban=0,d=0;
char cad[50];
printf("Introduce una frase: ");gets(cad);
while(cad[lc])
{
	lc++;
}
d=lc/2;
lc--;
for(i=0;i<d;i++)
{
	if(cad[i]==32)
		i++;
	if(cad[lc]==32)
		lc--;
	if(cad[i]!=cad[lc])
	{
		ban=1;break;
	}
	lc--;
}
if(ban==0)
	printf("Es una palabra palindrome");
else
	printf("No es una palabra palndrome");
getch();

}

