#include<stdio.h>
#include<conio.h>
#include<math.h>
void biseccion();
void punto_fijo();
void secante();
void posicion_falsa();
void newton_raphson();
float funcionpf(float *po);
float funcionsec(float *p);
float funcionbi(float *p);
float funcion(float *p);
float derivada(float *p);
float funcionpos(float *p);


void main()
{
	int opc;
	for(;;)
	{
		clrscr();
		gotoxy(20,3);printf("PROGRAMA QUE CALCULA x PARA QUE f(x)=0");
		gotoxy(25,7);printf("1.Metodo de Punto Fijo");
		gotoxy(25,8);printf("2.Metodo de la Secante");
		gotoxy(25,9);printf("3.Metodo de Posicion Falsa");
		gotoxy(25,10);printf("4.Metodo de la Biseccion");
		gotoxy(25,11);printf("5.Metodo de Newton Raphson");
		gotoxy(25,12);printf("6.Salir");
		gotoxy(20,15);printf("Seleccione el metodo que desee utilizar: ");
		scanf("%d",&opc);
		switch(opc)
		{
			case 1:punto_fijo();break;
			case 2:secante();break;
			case 3:posicion_falsa();break;
			case 4:biseccion();break;
			case 5:newton_raphson();break;
			case 6:break;
			default: gotoxy(25,17);printf("No existe tal opcion");getch();
		}
		if(opc==6)
			break;
	}
//getch();
}

void punto_fijo()
{
	float TOL,po,p,TI,EXP,fpo,ap;
	int No,i,ban=0;
	clrscr();
	gotoxy(30,1);printf("METODO DE PUNTO FIJO");
	gotoxy(8,3);printf("Programa para encontrar una solucion de f(x)=0 dada la funcion:");
	gotoxy(30,5);printf("1/2(10-x^3)^1/2 = 0");
	gotoxy(15,8);printf("Dame aproximacion inicial: ");scanf("%f",&po);
	gotoxy(15,9);printf("Dame el margen de error: ");scanf("%f",&TOL);
	gotoxy(15,10);printf("Dame el numero maximo de iteraciones: ");scanf("%d",&No);
	for(i=1;i<=No;i++)
	{
		fpo=funcionpf(&po);
		p=fpo;
		if(fabs(p-po)<TOL)
		{
			ban=1;break;
		}
		else
			po=p;
	}
	if(ban==1)
		{
			gotoxy(25,13);printf("x= %f para que f(x)=0",p);
			gotoxy(20,15);printf("Procedimiento completado satisfactoriamente");
		}
	else
	{
	 gotoxy(20,15);printf("Procedimiento completado insatisfactoriamente");
	}
	getch();

}
float funcionpf(float *po)
{       //Mi funcion es: 1/2(10-x^3)^1/2=0
	int cant,j,num,i;
	float fpo;
	fpo=0.5*pow(10-pow(*po,3),0.5);
	return fpo;
}

void secante()
{
	float p0,p1,TOL,q0,q1,p,fp;
	int No,i,ban=0;
	clrscr();
	printf("Dame aproximacion inicial po: ");scanf("%f",&p0);
	printf("Dame aproximacion inicial pi: ");scanf("%f",&p1);
	printf("Dame el margen de error: ");scanf("%f",&TOL);
	printf("Dame el numero maximo de iteraciones: ");scanf("%d",&No);
	i=2;
	q0=funcionsec(&p0);
	q1=funcionsec(&p1);

	while(i<=No)
	{
		p=(p1-(q1*(p1-p0)))/(q1-q0);
		if(fabs(p-p1)<TOL)
		{
			ban=1;break;
		}
		i++;
		p0=p1;q0=q1;p1=p;
		fp=funcionsec(&p);
		q1=fp;
	}
	if(ban==1)
			{printf("\np: %f\n",p);printf("Procedimiento completado satisfactoriamente");}
	else
		printf("\nEl metodo fracaso despues de %d iteraciones\nProcedimiento completado insatisfactoriamente",i-2);
	getch();
}


float funcionsec(float *p)
{       //NO SE CUAL FUNCION
	int cant,j,num,i;
	float fp;
	fp=(3*(*p))+2;
	return fp;
}

void biseccion()
{
	float a,b,TOL,fa,fb,p,fp;
	int No,i,ban=0;
	clrscr();
	gotoxy(8,3);printf("Programa para encontrar una solucion de f(x)=0 dada la funcion:");
	gotoxy(30,5);printf("x^3+4x^2-10 = 0");
	gotoxy(15,8);printf("Dame extremo a: ");scanf("%f",&a);
	gotoxy(15,9);printf("Dame extremo b: ");scanf("%f",&b);
	gotoxy(15,10);printf("Dame la tolerancia: ");scanf("%f",&TOL);
	gotoxy(15,11);printf("Dame el numero maximo de iteraciones: ");scanf("%d",&No);
	i=1;
	while(i<=No)
	{
		p= a+((b-a)/2);
		fp=funcionbi(&p);
		if(fp==0 ||(b-a)/2<TOL)
		{
			ban=1;
			break;
		}
		else
		{
			i++;
			fa=funcionbi(&a);
			//fb=funcionbi(&b);
			if((fa*fp)>0)
				a=p;
			else
				b=p;
		}
	}
	if(ban==1)
		{
			gotoxy(25,14);printf("x= %f para que f(x)=0",p);
			gotoxy(15,17);printf("Procedimiento completado satisfactoriamente");
		}
	if(ban==0)
	{
		gotoxy(15,17);
		printf("El metodo fracas¢ despues de %d iteraciones\nProcedimiento completado insatisfactoriamente!!!",i-1);
	}
	getch();
}



float funcionbi(float *p)
{       //Mi funcion es: x'3+4x'2-10
	int cant,j,num,i;
	float fp;
	fp=(pow(*p,3)+(4*pow(*p,2))-10);
	return fp;
}

void newton_raphson()
{
	float po,p,TOL,fp,fpo,dpo,a,b,fa,fb,ban=0;
	int No,i;//ban=0;
	clrscr();
	gotoxy(8,3);printf("Programa para encontrar una solucion de f(x)=0 dada la funcion:");
	gotoxy(30,5);printf("x^3+4x^2-10 = 0");
	gotoxy(15,8);printf("Dame aproximacion inicial: ");scanf("%f",&po);
	gotoxy(15,9);printf("Dame el margen de error: ");scanf("%f",&TOL);
	gotoxy(15,10);printf("Dame el numero maximo de iteraciones: ");scanf("%d",&No);
	i=1;
	while(i<=No)
	{
		fpo=funcion(&po);
		dpo=derivada(&po);

		p=po-fpo/dpo;
		if(fabs(p-po)<TOL)
		{
			ban=1;break;
		}
		else
			i++;
			po=p;
	}
	if(ban==1)
		{
			gotoxy(25,13);printf("x= %f para hacer f(x)=0",p);
			gotoxy(20,15);printf("Procedimiento completado satisfactoriamente");
		}
	else
	{
		gotoxy(20,15);printf("El metodo fracaso despues de %d iteraciones",i-1);
		gotoxy(20,16);printf("Procedimiento completado sin exito");
	}
	getch();
}

float funcion(float *po)
{       //Mi funcion es: xï3+4x'2-10 =0
	float fpo;
	fpo=pow(*po,3)+4*pow(*po,2)-10;
	return fpo;
}

float derivada(float *po)
{       //Mi funcion es: xï3-2xï2-5=0
	float dpo;
	dpo=3*(pow(*po,2))+(8*(*po));
	return dpo;
}

void posicion_falsa()
{
	float a,b,TOL,fa,fb,p,fp;
	int No,i,ban=0;
	clrscr();
	printf("Dame extremo a: ");scanf("%f",&a);
	printf("Dame extremo b: ");scanf("%f",&b);
	printf("Dame el margen de error: ");scanf("%f",&TOL);
	printf("Dame el numero maximo de iteraciones: ");scanf("%d",&No);
	i=1;
	while(i<=No)
	{
		fa=funcionpos(&a);fb=funcionpos(&b);
		p= p ; //no se como va
		fp=funcionpos(&p);
		if((fp*fa)<0)
		{
			a++; p=b+1;
		}
		else
		{
			i++;
			p=a+1;b=b+1;
		}
	}
	if(ban==1)
		{printf("\nfp: %f\n",fp);printf("Procedimiento completado satisfactoriamente");}
	if(ban==0)
		printf("\nEl metodo fracas¢ despues de %d iteraciones\nProcedimiento completado insatisfactoriamente!!!",i-1);
	getch();
}

float funcionpos(float *p)
{       //Mi funcion es: x'3+4x'2-10
	int cant,j,num,i;
	float fp;
	fp=(pow(*p,3)+(4*pow(*p,2))-10);
	return fp;
}