#include<stdio.h>
#include<conio.h>
void main()
{
clrscr();
int lc,a=0,z=0,noes=0;
char cad[50];
printf("Introduce una frase: ");gets(cad);
while(cad[z++])
while(z>a)
{
	if(cad[a]!=cad[z])
	{
		noes=1;printf("No es palindrome");break;
	}
}
if(noes==0)
	printf("\Es una palabra palndrome");
getch();

}

