#include<iostream.h>
#include<conio.h>
void main (){
int an,sun,s,su,p,q,cont,w,est,mes,dia,tol,sel,n,t,y;
int conta=0,x,suma=0,an1,dia2,mes2,z,vivi,toll,g,e;
clrscr ();
cout<<"\nINTRODUCE EL A¥O EN EL NACISTES: ";
cin>>an;
///////********* calculo de bisiesto*////////////////
								  //
	 if ((an%4==0 && an%100!=0) || (an%400==0))              //
	 {
	  cout<<"\nEL A¥O EN EL QUE USTED NACIO FUE BISIESTO";       //
	  s=an/an;
	  sun=s*366;

	  cout<<"\nINTRODUCE EL DIA QUE NACISTES: ";
	  cin>>dia;

	  cout<<"\nINTRODUCE EL MES EN EL QUE NACISTES: ";
	  cin>>mes;

	  if (mes==1)
	   {
	   /*mes=366-31;
	   e=31-dia;
	   toll=mes+e;*/
	   mes=31-dia;
	   toll=mes+336;
	   }
	   if (mes==2)
	   {
	   mes=29-dia;
	   toll=mes+307;
	   }
	   if (mes==3)
	   {
	   mes=31-dia;
	   toll=mes+276;
	   }
	   if (mes==4)
	   {
	   mes=30-dia;
	   toll=mes+246; /*245*/
	   }
	   if (mes==5)
	   {
	   mes=31-dia;
	   toll=mes+215;
	   }
	   if (mes==6)
	   {
	   mes=30-dia;
	   toll=mes+185;
	   }
	   if (mes==7)
	   {
	   mes=31-dia;
	   toll=mes+154;
	   }
	   if (mes==8)
	   {
	   mes=31-dia;
	   toll=mes+123;
	   }
	   if (mes==9)
	   {
	   mes=30-dia;
	   toll=mes+93;
	   }
	   if (mes==10)
	   {
	   mes=31-dia;
	   toll=mes+62;
	   }
	   if (mes==11)
	   {
	   mes=30-dia;
	   toll=mes+32;
	   }
	   if (mes==12)
	   {
	   mes=31-dia;
	   toll=mes+1;
	   }

	  }

	  else
     {                                            //
	  cout<<"\nEl A¥O EN EL QUE USTED NACIO NO FUE BISIESTO";  //
	  p=an/an;
	  su=p*365;

	  cout<<"\nINTRODUCE EL DIA QUE NACISTES: ";
	  cin>>dia;

	  cout<<"\nINTRODUCE EL MES EN EL QUE NACISTES: ";
	  cin>>mes;

	  if (mes==1)
	   {
	   mes=31-dia;
	   toll=mes+335;
	   }
	   if (mes==2)
	   {
	   mes=28-dia;
	   toll=mes+307;
	   }
	   if (mes==3)
	   {
	   mes=31-dia;
	   toll=mes+276;
	   }
	   if (mes==4)
	   {
	   mes=30-dia;
	   toll=mes+246;
	   }
	   if (mes==5)
	   {
	   mes=31-dia;
	   toll=mes+215;
	   }
	   if (mes==6)
	   {
	   mes=30-dia;
	   toll=mes+185;
	   }
	   if (mes==7)
	   {
	   mes=31-dia;
	   toll=mes+154;
	   }
	   if (mes==8)
	   {
	   mes=31-dia;
	   toll=mes+123;
	   }
	   if (mes==9)
	   {
	   mes=30-dia;
	   toll=mes+93;
	   }
	   if (mes==10)
	   {
	   mes=31-dia;
	   toll=mes+62;
	   }
	   if (mes==11)
	   {
	   mes=30-dia;
	   toll=mes+32;
	   }
	   if (mes==12)
	   {
	   mes=31-dia;
	   toll=mes+1;
	   }

      }
/*//////////////*************////////////////**********///////////////
////////*************************/////////////////////////////////////
cout<<"\nINTRODUCE EL A¥O EN EL QUE TE ENCUENTRAS: ";
cin>>an1;

								  //
	 if ((an1%4==0 && an1%100!=0) || (an1%400==0))              //
   {
	  cout<<"\nEL A¥O EN EL QUE USTED SE ENCUENTRA ES BISIESTO";       //
	  q=an1/an1;
	  cont=q*366;

	  cout<<"\nINTRODUCE EL DIA EN EL QUE ESTAS HOY: ";
	  cin>>dia2;

	  cout<<"\nINTRODUCE EL MES EN EL QUE TE ENCUENTRAS: ";
	  cin>>mes2;

	  if (mes2==1)
	   {
	   mes2=dia2;
	   tol=mes2;
	   }
	   if (mes2==2)
	   {
	   mes2=31+dia2;
	   tol=mes2;
	   }
	   if (mes2==3)
	   {
	   mes2=60+dia2;
	   tol=mes2;
	   }
	   if (mes2==4)
	   {
	   mes2=91+dia2;
	   tol=mes2;
	   }
	   if (mes2==5)
	   {
	   mes2=121+dia2;
	   tol=mes2;
	   }
	   if (mes2==6)
	   {
	   mes2=152+dia2;
	   tol=mes2;
	   }
	   if (mes2==7)
	   {
	   mes2=182+dia2;
	   tol=mes2;
	   }
	   if (mes2==8)
	   {
	   mes2=213+dia2;
	   tol=mes2;
	   }
	   if (mes2==9)
	   {
	   mes2=244+dia2;
	   tol=mes2;
	   }
	   if (mes2==10)
	   {
	   mes2=274+dia2;
	   tol=mes2;
	   }
	   if (mes2==11)
	   {
	   mes2=305+dia2;
	   tol=mes2;
	   }
	   if (mes2==12)
	   {
	   mes2=335+dia2;
	   tol=mes2;
	   }

   }

	  else
   {
	  cout<<"\nEl A¥O EN EL QUE USTED SE ENCUENTRA NO ES BISIESTO";
	  w=an1/an1;
	  est=w*365;

	  cout<<"\nINTRODUCE EL DIA EN EL QUE ESTAS HOY: ";
	  cin>>dia2;

	  cout<<"\nINTRODUCE EL MES EN EL QUE TE ENCUENTRAS: ";
	  cin>>mes2;

	  if (mes2==1)
	   {
	   mes2=dia2;
	   tol=mes2;
	   }
	   if (mes2==2)
	   {
	   mes2=31+dia2;
	   tol=mes2;
	   }
	   if (mes2==3)
	   {
	   mes2=59+dia2;
	   tol=mes2;
	   }
	   if (mes2==4)
	   {
	   mes2=90+dia2;
	   tol=mes2;
	   }
	   if (mes2==5)
	   {
	   mes2=120+dia2;
	   tol=mes2;
	   }
	   if (mes2==6)
	   {
	   mes2=151+dia2;
	   tol=mes2;
	   }
	   if (mes2==7)
	   {
	   mes2=181+dia2;
	   tol=mes2;
	   }
	   if (mes2==8)
	   {
	   mes2=212+dia2;
	   tol=mes2;
	   }
	   if (mes2==9)
	   {
	   mes2=243+dia2;
	   tol=mes2;
	   }
	   if (mes2==10)
	   {
	   mes2=273+dia2; /*272*/
	   tol=mes2;
	   }
	   if (mes2==11)
	   {
	   mes2=304+dia2;
	   tol=mes2;
	   }
	   if (mes2==12)
	   {
	   mes2=334+dia2;
	   tol=mes2;
	   }


   }
///////////////////****************************************//
t=an+1;
n=an1-1;
////////////////////////////////***********///////////////////
  for (x=t; x<=n; x++)
    {
      if ((x%4==0 && x%100!=0) || (x%400==0))
	  {

	  suma++;
	  z=suma*366;
	  }

      else
	  {

	  conta++;
	  sel=conta*365;
	  }

     }

   vivi=z+sel+tol+toll;

   cout<<"\nLos dias vividos son: "<<vivi;
   cout<<"\n"<<z;
   cout<<"\n"<<sel;
   cout<<"\n"<<tol;
   cout<<"\n"<<toll;
   cout<<"\nESTUDILLO HERNANDEZ MIGUEL E. ";
cout<<"miguel_enrique_86@hotmail.com";




 getch ();

}

