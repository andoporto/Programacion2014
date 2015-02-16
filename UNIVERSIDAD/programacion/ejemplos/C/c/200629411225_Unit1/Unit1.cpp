//---------------------------------------------------------------------------

#pragma hdrstop
#include<iostream.h>
#include<conio.h>
//---------------------------------------------------------------------------

#pragma argsused

bool EsNumPerfecto(int num);
void NumerosPerfectos(int inicio,int fin);
int main(int argc, char* argv[])
{
int inicio,fin;
cout<<"Entre el rango en el que quiere encontrar los numeros perfectos"<<endl;
do
{
   cout<<"Entre el inicio(mayor que cero)"<<endl;
   cin>>inicio;
}
while(inicio<=0);

do
{
   cout<<"Entre el final(mayor o igual que el inicio)"<<endl;
   cin>>fin;
}
while(fin<inicio);

NumerosPerfectos(inicio,fin);

getch();
        return 0;
}
//---------------------------------------------------------------------------
bool EsNumPerfecto(int num)
{
   int numero=0;
   for(int i=0;numero<num;i++)
      numero+=i;
   if(numero==num)
      return true;
   return false;
}
void NumerosPerfectos(int inicio,int fin)
{
   while(inicio<=fin)
   {
      if(EsNumPerfecto(inicio))
         cout<<inicio<<endl;
      inicio++;
   }
}

