#include <stdio.h>
#include <conio.h>

void asterisco (int);
void main ()

{
	clrscr();

	int n;
	printf("Ingrese cantidad de *: ");
	scanf("%d",&n);
	asterisco (n);
	printf("TITULO");
	asterisco (n);
	getch();
}


void asterisco (int n)


{
  int i;
  for (i=1;i<=n;i++);
  {
  printf("*");
  }
}
