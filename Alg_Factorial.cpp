#include<iostream.h>
//-------Block1------------
int n;
char mnu='s';
//-------Block2------------
long int fact(int x);
//-------Block3------------
void salir();
void main()

{
    cout<<"\n";
	cout<<"              ALGORTIMO FACTORIAL"<<endl;  
	cout<<"              *******************\n";
	cout<<"\n";
//-------Block4------------
	while (mnu!='n')
	
	{
    
	cout<<" Ingrese el Numero: ";
    cin>>n;
	cout<<"\n";
    cout<<" El Factorial de "<<n<<" es: "<<fact(n)<<endl;
	cout<<" Evaluar Otro Numero ? Si(s), No(n): ";
	cin>>mnu;
	cout<<"\n";

	}
	
	salir();
}
//-------Block5------------
long int fact(int x)

{
     if(x==1)
     return 1;
	
     else
	 return x*fact(x-1);
	
}
//-------Block6------------     
void salir()

{
		cout<<" FIN \n";//Fin
		cout<<" ///\n";
		cout<<"\n";
		cout<<" Visita: http//Algoritmopuro.blogspot.com. Algoritmos Dividelos y Venceras ...\n";
		cout<<" Edaniel15@hotmail.com & edaniel15@gmail.com ...\n";
		cout<<"\n"; //Salto de Linea
}
/* Desarrollado por edaniel15@hotmail.com || edaniel15@gmail.com ... Algoritmos Dividelos y venceras ....
visiten: algoritmopuro.blogspot.com */