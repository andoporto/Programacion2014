#include<stdio.h>
#include<conio.h>
#include<iostream.h>

void main(){
int x,cad[10],aux,y;
clrscr();
 printf("ingresa 10 valores \n");
   for(x=0;x<10;x++)
   { cin>>cad[x];
   }
	for(x=9;x>0;x--)
	{ if(cad[x]<cad[x-1])
	  { aux=cad[x];
		cad[x]=cad[x-1];
		cad[x-1]=aux;
	   }
	  for(aux=0;aux<10;aux++)
		cout<<cad[aux]<<" ";
	  cout<<endl;
	}

 getch();
}