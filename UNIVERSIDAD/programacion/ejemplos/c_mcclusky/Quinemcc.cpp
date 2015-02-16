#include <stdio.h>
#include<iostream.h>
#include <conio.h>
#include <math.h>

//universidad Industrial de Santander
//Ingenieria de Sistemas

long M[50][9],q,e,pm,x,n,v,r,c,i,j,k,vc,c1=0,VM[50];
long temp,ch,MN[50][9],t=0,M1[70][9],w=0,M2[70][9];
long w2=0,M3[70][9],w3=0,con=0,w4=0,M4[70][9],M5[70][9],w5=0;

void marco (int x1,int y1,int x2,int y2);

void main()
  {
    clrscr();
    textcolor(YELLOW);

    marco (23,3,52,5);
    gotoxy(26,4);
    cout<<"Metodo de Quine-McClusky";

    marco (8,6,72,14);
    gotoxy(24,8);
    cout<<"Digite el numero de variables..";
    cin>>v;
    gotoxy(24,10);
    cout<<"Cuantos valores ingresara..";
    cin>>n;
    clrscr();

    for(i=0;i<n;i++)
    {
    clrscr();
    marco (23,3,52,5);
    gotoxy(26,4);
    cout<<"Metodo de Quine-McClusky";
    marco (8,6,72,14);
    gotoxy(20,10);
    cout<<"Digite el valor..";
    cin>>x;
    vc=(v-1);
    c1=0;

       for(j=0;j<v;j++)
	{
	 c=fmod(x,2);
	 r=x/2;
	 x=r;
	 M[i][vc]=c;
	 vc=vc-1;

	 if(c==1)
	    c1+=1;
	}
	if(c1==0 || c1!=0)
	   {VM[i]=c1;
	   }

    }

  for(i=0;i<n-1;i++)
      {
       for(k=i+1;k<n;k++)
	{                      //ordena la matriz por cantidad de 1
	 if(VM[k]<VM[i])
	  { temp=VM[i];
	    VM[i]=VM[k];
	    VM[k]=temp;
	   for(j=0;j<v;j++)
	      {
	       temp=M[i][j];
	       M[i][j]=M[k][j];
	       M[k][j]=temp;
	      }
	  }
	}
      }

    clrscr();
    for(i=0;i<n;i++)
       {
	for(k=i+1;k<n;k++)
	    {ch=0;
	    for(j=0;j<v;j++)
	       {
		if(M[i][j]!=M[k][j])
		  {
		   ch+=1;
		   pm=j;
		  }
	       }
	     if(ch==1)
	       {
		M[i][8]=5;  //marca de los valores que cambian
		M[k][8]=5;

		for(j=0;j<v;j++)
		    {
		     M1[w][j]=M[k][j];
		     M1[w][pm]=5;       //asigancion en nueva matriz
		     }
		w+=1;
	       }
	    }
       }

   for(i=0;i<n;i++)
       {
	if(M[i][8]!=5)
	   {
	    for(j=0;j<v;j++)
		{                          //guarda valores que no cambian  de los n entrantes
		 MN[t][j]=M[i][j];
		}
	   t+=1;
	   }
       }

//------------------------------------

for(i=0;i<w;i++)
       {
	for(k=i+1;k<w;k++)
	    {ch=0;
	    for(j=0;j<v;j++)
	       {
		if(M1[i][j]!=M1[k][j])
		  {
		   ch+=1;
		   pm=j;
		  }
	       }
	     if(ch==1)
	       {
		M1[i][8]=5;  //marca de los valores que cambian
		M1[k][8]=5;

		for(j=0;j<v;j++)
		    {
		     M2[w2][j]=M1[k][j];
		     M2[w2][pm]=5;         //asigna a matriz 2
		     }
		w2+=1;
	       }
	    }
       }

for(i=0;i<w;i++)
       {
	if(M1[i][8]!=5)
	   {
	    for(j=0;j<v;j++)
		{
		 MN[t][j]=M1[i][j];         //guarda los que no cambian de m1
		}
	    t+=1;
	   }
       }
//---------------------------

for(i=0;i<w2;i++)
       {
	for(k=i+1;k<w2;k++)
	    {ch=0;
	    for(j=0;j<v;j++)
	       { if(M2[i][j]!=M2[k][j])
		    ch=1;
	       }
	    if(ch==0)
	       {pm=k;
		con=con+1;
		//
		 for(q=k;q<w2;q++)                  //mando los repetidos al fondo
		     {                               //y restrinjo las filas de la matriz
		      for(j=0;j<v;j++)
			{
			 temp=M2[q][j];
			 M2[q][j]=M2[q+1][j];
			 M2[q+1][j]=temp;
			}
		     }
		//


	       }

	    }
       }

  //-------------------------------------------------

 for(i=0;i<w2-con;i++)
       {
	for(k=i+1;k<w2-con;k++)
	    {ch=0;
	    for(j=0;j<v;j++)
	       {
		if(M2[i][j]!=M2[k][j])
		  {
		   ch+=1;
		   pm=j;
		  }
	       }
	     if(ch==1)
	       {
		M2[i][8]=5;  //marca de los valores que cambian
		M2[k][8]=5;

		for(j=0;j<v;j++)
		    {
		     M3[w3][j]=M2[k][j];
		     M3[w3][pm]=5;         //asigna a matriz 3
		     }
		w3+=1;
	       }
	    }
       }


for(i=0;i<w2-con;i++)
       {
	if(M2[i][8]!=5)
	   {
	    for(j=0;j<v;j++)
		{
		 MN[t][j]=M2[i][j];         //guarda los que no cambian  de M2
		}
	    t+=1;
	   }
       }


 ///-------------------------------------------------------


con=0;
for(i=0;i<w3;i++)
       {
	for(k=i+1;k<w3-con;k++)
	    {ch=0;
	    for(j=0;j<v;j++)
	       { if(M3[i][j]!=M3[k][j])
		    ch=1;
	       }
	    if(ch==0)
	       {pm=k;
		con=con+1;
		//
		 for(q=k;q<w3;q++)                  //mando los repetidos al fondo
		     {                               //y restrinjo las filas de la matriz
		      for(j=0;j<v;j++)
			{
			 temp=M3[q][j];
			 M3[q][j]=M3[q+1][j];
			 M3[q+1][j]=temp;
			}
		     }
		//

	       k=k-1;

	       }

	    }
       }




for(i=0;i<w3-con;i++)
       {
	for(k=i+1;k<w3-con;k++)
	    {ch=0;
	    for(j=0;j<v;j++)
	       {
		if(M3[i][j]!=M3[k][j])
		  {
		   ch+=1;
		   pm=j;
		  }
	       }
	     if(ch==1)
	       {
		M3[i][8]=5;  //marca de los valores que cambian
		M3[k][8]=5;

		for(j=0;j<v;j++)
		    {
		     M4[w4][j]=M3[k][j];
		     M4[w4][pm]=5;         //asigna a matriz 4
		     }
		w4+=1;
	       }
	    }
       }

for(i=0;i<w3-con;i++)
       {
	if(M3[i][8]!=5)
	   {
	    for(j=0;j<v;j++)
		{
		 MN[t][j]=M3[i][j];         //guarda los que no cambian   de M3
		}
	    t+=1;
	   }
       }
//------------------------------------------
con=0;
for(i=0;i<w4;i++)
       {
	for(k=i+1;k<w4-con;k++)
	    {ch=0;
	    for(j=0;j<v;j++)
	       { if(M4[i][j]!=M4[k][j])
		    ch=1;
	       }
	    if(ch==0)
	       {pm=k;
		con=con+1;
		//
		 for(q=k;q<w4;q++)                  //mando los repetidos al fondo
		     {                               //y restrinjo las filas de la matriz
		      for(j=0;j<v;j++)
			{
			 temp=M4[q][j];
			 M4[q][j]=M4[q+1][j];
			 M4[q+1][j]=temp;
			}
		     }
		//

	       k=k-1;

	       }

	    }
       }

for(i=0;i<w4-con;i++)
       {
	for(k=i+1;k<w4-con;k++)
	    {ch=0;
	    for(j=0;j<v;j++)
	       {
		if(M4[i][j]!=M4[k][j])
		  {
		   ch+=1;
		   pm=j;
		  }
	       }
	     if(ch==1)
	       {
		M4[i][8]=5;  //marca de los valores que cambian
		M4[k][8]=5;

		for(j=0;j<v;j++)
		    {
		     M5[w5][j]=M4[k][j];
		     M5[w5][pm]=5;         //asigna a matriz 4
		     }
		w5+=1;
	       }
	    }
       }

for(i=0;i<w4-con;i++)
       {
	if(M4[i][8]!=5)
	   {
	    for(j=0;j<v;j++)
		{
		 MN[t][j]=M4[i][j];         //guarda los que no cambian   de M4
		}
	    t+=1;
	   }
       }

//----------------------------------------------
   clrscr();
   marco (18,9,59,12);
   gotoxy(20,10);
   cout<<"Las letras minusculas son la negacion";
   gotoxy(20,11);
   cout<<"y las mayusculas las no negadas";
   getch();

   clrscr();
   marco (6,2,70,25);
   for(i=0;i<t;i++)
       {
	for(j=0;j<v;j++)
	   {


		 if(j==0) { if(MN[i][j]==0)
			     {	if(i<22)
				{
				 gotoxy(20+j,3+i);
				 cout<<"a";
				}
				if(i>=22&& i<44)
				  {gotoxy(28+j,i-19);
				   cout<<"a";
				  }

				if(i>=44)
				  {gotoxy(36+j,i-41);
				   cout<<"a";
				  }
			      }
			  if(MN[i][j]==1)
			     {	if(i<22)
				{
				 gotoxy(20+j,3+i);
				 cout<<"A";
				}
				if(i>=22&& i<44)
				  {gotoxy(28+j,i-19);
				   cout<<"A";
				  }

				if(i>=44)
				  {gotoxy(36+j,i-41);
				   cout<<"A";
				  }
			      }



			   }

		 if(j==1)  {if(MN[i][j]==0)
			     {	if(i<22)
				{
				 gotoxy(20+j,3+i);
				 cout<<"b";
				}
				if(i>=22&& i<44)
				  {gotoxy(28+j,i-19);
				   cout<<"b";
				  }

				if(i>=44)
				  {gotoxy(36+j,i-41);
				   cout<<"b";
				  }
			      }
			  if(MN[i][j]==1)
			     {	if(i<22)
				{
				 gotoxy(20+j,3+i);
				 cout<<"B";
				}
				if(i>=22&& i<44)
				  {gotoxy(28+j,i-19);
				   cout<<"B";
				  }

				if(i>=44)
				  {gotoxy(36+j,i-41);
				   cout<<"B";
				  }
			      }



			  }
		 if(j==2)  {if(MN[i][j]==0)
			     {	if(i<22)
				{
				 gotoxy(20+j,3+i);
				 cout<<"c";
				}
				if(i>=22&& i<44)
				  {gotoxy(28+j,i-19);
				   cout<<"c";
				  }

				if(i>=44)
				  {gotoxy(36+j,i-41);
				   cout<<"c";
				  }
			      }
			  if(MN[i][j]==1)
			     {	if(i<22)
				{
				 gotoxy(20+j,3+i);
				 cout<<"C";
				}
				if(i>=22&& i<44)
				  {gotoxy(28+j,i-19);
				   cout<<"C";
				  }

				if(i>=44)
				  {gotoxy(36+j,i-41);
				   cout<<"C";
				  }
			      }



			   }
		 if(j==3)  {if(MN[i][j]==0)
			     {	if(i<22)
				{
				 gotoxy(20+j,3+i);
				 cout<<"d";
				}
				if(i>=22&& i<44)
				  {gotoxy(28+j,i-19);
				   cout<<"d";
				  }

				if(i>=44)
				  {gotoxy(36+j,i-41);
				   cout<<"d";
				  }
			      }
			  if(MN[i][j]==1)
			     {	if(i<22)
				{
				 gotoxy(20+j,3+i);
				 cout<<"D";
				}
				if(i>=22&& i<44)
				  {gotoxy(28+j,i-19);
				   cout<<"D";
				  }

				if(i>=44)
				  {gotoxy(36+j,i-41);
				   cout<<"D";
				  }
			      }



			   }
		 if(j==4)  {if(MN[i][j]==0)
			     {	if(i<22)
				{
				 gotoxy(20+j,3+i);
				 cout<<"e";
				}
				if(i>=22&& i<44)
				  {gotoxy(28+j,i-19);
				   cout<<"e";
				  }

				if(i>=44)
				  {gotoxy(36+j,i-41);
				   cout<<"e";
				  }
			      }
			  if(MN[i][j]==1)
			     {	if(i<22)
				{
				 gotoxy(20+j,3+i);
				 cout<<"E";
				}
				if(i>=22&& i<44)
				  {gotoxy(28+j,i-19);
				   cout<<"E";
				  }

				if(i>=44)
				  {gotoxy(36+j,i-41);
				   cout<<"E";
				  }
			      }



			   }
		 if(j==5)  {if(MN[i][j]==0)
			     {	if(i<22)
				{
				 gotoxy(20+j,3+i);
				 cout<<"f";
				}
				if(i>=22&& i<44)
				  {gotoxy(28+j,i-19);
				   cout<<"f";
				  }

				if(i>=44)
				  {gotoxy(36+j,i-41);
				   cout<<"f";
				  }
			      }
			  if(MN[i][j]==1)
			     {	if(i<22)
				{
				 gotoxy(20+j,3+i);
				 cout<<"F";
				}
				if(i>=22&& i<44)
				  {gotoxy(28+j,i-19);
				   cout<<"F";
				  }

				if(i>=44)
				  {gotoxy(36+j,i-41);
				   cout<<"F";
				  }
			      }



			   }

		 /*
	    marco (6,2,70,25);
	    if(i<22)
	      {
	       gotoxy(20+j,3+i);
	       cout<<""<<MN[i][j];
	      }
	    if(i>=22&& i<44)
	      {gotoxy(28+j,i-19);
	       cout<<""<<MN[i][j];
	      }
				   //impresion de resultados
	    if(i>=44)
	      {gotoxy(36+j,i-41);
	       cout<<""<<MN[i][j];
	      }     */
	   }
	}

   getch();

 }

  void  marco(int x1,int y1,int x2,int y2 )
      {
      int i;
	      for(i=x1;i<=x2;i++)
	       {
		 gotoxy(i,y1); printf("Í");
		 gotoxy(i,y2); printf("Í");
		}
	      for (i=y1;i<y2;i++)
	       {
		   gotoxy(x1,i); printf("º");
		   gotoxy(x2,i); printf("º");
		}
		   gotoxy(x1,y2); printf("È");
		   gotoxy(x2,y1); printf("»");
		   gotoxy(x2,y2); printf("¼");
		   gotoxy(x1,y1); printf("É");
       }

















































































































































































































