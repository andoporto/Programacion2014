#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>

char opc1;
char caracter,aux;
int i,cont,y,w,otraflag=0;
FILE *arch;
char ruta[50];
char nombre[50];
char buffer[60],word2[15];
char letra,wordaux;

int comienzo=0, delantero=0, estado=0, letras=0, ban=0, gral=0, bande=0, c=0, tipo;

int buscar(char word[]);
void sintactico();
void gs(char otravar[]);
char * leer();
int buscartipo(char word4[]);

int casoif();
int casofor();
int casowhile();
void casodo();

typedef struct
 {
  int tipo;
  char valor[10];
  char tdato[13];
  char ambito[15];
  char nombre[15];
 }simbolo;

simbolo tabla[200];
char palabra[15];

int esletra(char x)
{
 if((x>=65 && x<=90) || (x>=97 && x<=122))
	return(1);
 else
	return(0);
}

int esdigito(char z)
{
 if(z>=48 && z<=57)
	return(1);
 else
	return(0);
}

int esoperador(char y)
{
 if(y==';' || y=='<' || y=='>' || y=='=' || y=='+' || y=='-' || y=='*' || y=='/' || y=='%' || y=='^' || y=='&' || y=='|' || y=='!' || y=='==' || y=='&&' || y=='||' || y=='!=' || y=='>=' || y=='<=' || y=='++' || y=='--')
	return(1);
 else
	return(0);
}

int esoperador2(char yy[])
{
 if((strcmp(yy,"<")==0) || (strcmp(yy,">")==0) || (strcmp(yy,"=")==0) || (strcmp(yy,"+")==0) || (strcmp(yy,"-")==0) || (strcmp(yy,"*")==0) || (strcmp(yy,"/")==0) || (strcmp(yy,"%")==0) || (strcmp(yy,"^")==0) || (strcmp(yy,"&")==0) || (strcmp(yy,"|")==0) || (strcmp(yy,"!")==0) || (strcmp(yy,"==")==0) || (strcmp(yy,"&&")==0) || (strcmp(yy,"||")==0) || (strcmp(yy,"!=")==0) || (strcmp(yy,">=")==0) || (strcmp(yy,"<=")==0) || (strcmp(yy,"++")==0) || (strcmp(yy,"--")==0))
	return(1);
 else
	return(0);
}


int escaracter(char w)
{
 if(w=='{' || w=='}' || w=='[' || w==']' || w=='(' || w==')')
	return(1);
 else
	return(0);
}

void gramatica()
   {
	char checar[15];
	int est=0;
	for (int i=0;i<gral;i++)
	   {
		 strcpy(checar,tabla[i].nombre);
		 c=0;
		 while (checar[c]!='\x0' && checar[c]!=' ')
			 {
				switch(est)
				   {
					 case 0: if (checar[c]=='i'||checar[c]=='I')
								est=1;
							 else if(checar[c]=='e'||checar[c]=='E')
								est=2;
							 else if(checar[c]=='w'||checar[c]=='W')
								est=3;
							 else if(checar[c]=='d'||checar[c]=='D')
								est=4;
							 else if(checar[c]=='f'||checar[c]=='F')
								est=5;
							 else if(checar[c]=='c'||checar[c]=='C')
								est=6;
							 else if(checar[c]=='s'||checar[c]=='S')
								est=7;
							 else if(esdigito(checar[c])||checar[c]=='.')
								est=0;
							 else if(checar[c]=='+' || checar[c]=='-' || checar[c]=='*' || checar[c]=='/' || checar[c]=='<' || checar[c]=='>' || checar[c]=='%' ||  checar[c]=='=')
								{
								strcpy(tabla[i].tdato,"Operador");
								est=23;
								}
							 else
								est=8;
							 break;
					 case 1: if (checar[c]=='f'||checar[c]=='F')
								{
								est=9;
								strcpy(tabla[i].tdato,"Funcion");
								}
							 else if(checar[c]=='n'||checar[c]=='N')
								est=10;
							 else
								est=8;
							 break;
					 case 2: if(checar[c]=='l'||checar[c]=='L')
								est=11;
							 else
								est=8;
							 break;
					case 3: if(checar[c]=='h'||checar[c]=='H')
								est=13;
							 else
								est=8;
							 break;
					 case 4: if(checar[c]=='o'||checar[c]=='O')
								{
								est=9;
								strcpy(tabla[i].tdato,"Ciclo");
								}
							 else
								est=8;
							 break;
					 case 5: if(checar[c]=='o'||checar[c]=='O')
								est=16;
							 else
								est=8;
							 break;
					 case 6: if(checar[c]=='h'||checar[c]=='H')
								est=17;
							 else
								est=8;
							 break;
					 case 7: if(checar[c]=='t'||checar[c]=='T')
								est=19;
							 else
								est=8;
							 break;

					 case 10: if(checar[c]=='t'||checar[c]=='T')
								{
								est=9;
								strcpy(tabla[i].tdato,"Declaracion");
								}
							  else
								est=8;
							  break;
					 case 9: est=8;
							 break;
					 case 11: if(checar[c]=='s'||checar[c]=='S')
								est=12;
							 else
								est=8;
							 break;
					 case 13: if(checar[c]=='i'||checar[c]=='I')
								est=14;
							 else
								est=8;
							 break;
					 case 16: if(checar[c]=='r'||checar[c]=='R')
								{
								est=9;
								strcpy(tabla[i].tdato,"Ciclo");
								}
							 else
								est=8;
							 break;
					 case 17: if(checar[c]=='a'||checar[c]=='A')
								est=18;
							 else
								est=8;
							 break;
					case 19: if(checar[c]=='r'||checar[c]=='R')
								est=20;
							 else
								est=8;
							 break;
					case 12: if(checar[c]=='e'||checar[c]=='E')
								{
								est=9;
								strcpy(tabla[i].tdato,"Funcion");
								}
							 else
								est=8;
							 break;
					case 14: if(checar[c]=='l'||checar[c]=='L')
								est=15;
							 else
								est=8;
							 break;
					case 18: if(checar[c]=='r'||checar[c]=='R')
								{
								est=9;
								strcpy(tabla[i].tdato,"Declaracion");
								}
							 else
								est=8;
							 break;
					case 20: if(checar[c]=='u'||checar[c]=='U')
								est=21;
							 else
								est=8;
							 break;
					case 21: if(checar[c]=='c'||checar[c]=='C')
								est=22;
							 else
								est=8;
							 break;
					case 15: if(checar[c]=='e'||checar[c]=='E')
								{
								est=9;
								strcpy(tabla[i].tdato,"Ciclo");
								}
							 else
								est=8;
							 break;
					case 22: if(checar[c]=='t'||checar[c]=='T')
								{
								est=9;
								strcpy(tabla[i].tdato,"Declaracion");
								}
							 else
								est=8;
							 break;
					case 8:  break;
				   }
			  c++;
			 }
		 switch(est)
			 {
			  case 0: //printf("\n%s, N£mero V lido",checar);
					  tabla[i].tipo=1;
					  strcpy(tabla[i].tdato,"Numerico");
					  est=0;
					  //getch();
					  break;
			  case 8: //printf("\n%s, ID V lido",checar);
					  tabla[i].tipo=2;
					  strcpy(tabla[i].tdato,"Identificador");
					  est=0;
					  //getch();
					  break;
			  case 9: //printf("\n%s, Palabra Reservada",checar);
					  strcpy(tabla[i].tdato,"Palabra Res.");
					  tabla[i].tipo=3;
					  est=0;
					  //getch();
					  break;
			  case 23://printf("\n%s, Operador",checar);
					  strcpy(tabla[i].tdato,"Operador");
					  tabla[i].tipo=4;
					  est=0;
					  //getch();
					  break;
			  default:strcpy(tabla[i].tdato,"Identificador");
					  tabla[i].tipo=2;
					  break;
			 }
	   }
   }

void main()
	{
	 clrscr();
	 cont=0;
	 printf("\n\n ESCRIBA EL NOMBRE DEL ARCHIVO A COMPILAR: ");
	 scanf("%s",&nombre);
	 strcpy(ruta,"c:\\");
	 strcat(ruta,nombre);
	 strcat(ruta,".cpp");
	 arch=fopen(ruta,"r");
	 if (!arch)
		 {
		 printf("\n\n No se ha encontrado el archivo...");
		 getch();
		 exit(0);
		 }
	 else
		 {
		   while(!feof(arch))
				{
				  for(i=0;i<60;i++)
					{
					 fread(&buffer[i],1,1,arch);
					 cont++;
					 if (feof(arch))
						i=60;
					}
				  while(comienzo<cont)
					{
					 if(esletra(buffer[comienzo]))
					   {
						estado=1;
						if(esletra(buffer[delantero]) || esdigito(buffer[delantero]) || buffer[delantero]=='.')
						  {
						   palabra[letras]=buffer[delantero];
						   //printf("%c",buffer[delantero]);
						   letras++;
						   if (delantero==59)
							 {
							  while(!feof(arch) && bande==0)
								{
								 fread(&aux,1,1,arch);
								 if (aux!=' ' && aux!=';' && aux!='(' && aux!='{' && aux!=':' && aux!='[' && aux!='+' && aux!='-' && aux!='*' && aux!='/' && aux!='=')
								   {
									palabra[letras]=aux;
									letras++;
								   }
								 else
								   {
									if ((buscar(palabra))==1)
										{
										strcpy(tabla[gral].nombre,palabra);
										fflush(stdin);
										gral++;
										}
									for (int i=0;i<letras;i++)
										palabra[i]=NULL;
									fflush(stdin);
									comienzo=delantero;
									letras=0;
									bande=1;
									comienzo=cont;
								   }
								}
							 }
						   delantero++;
						  }
						else
						  {
						   //gramatica
						   estado=2;
						   delantero++;
						   //se guarda palabra en tabla
						   //se guarda el identificador con letras
						   if ((buscar(palabra))==1)
							  {
							   strcpy(tabla[gral].nombre,palabra);
							   fflush(stdin);
							   gral++;
							   comienzo=delantero;
							   //printf(" es un identificador valido \n");
							  }
						   for (int i=0;i<letras;i++)
								palabra[i]=NULL;
						   fflush(stdin);
						   comienzo=delantero;
						   letras=0;
						  }
					   }
					 else if(esdigito(buffer[comienzo]))
					   {
						 estado=1;
						 if(esdigito(buffer[delantero])||buffer[delantero]=='.')
						   {
							palabra[letras]=buffer[delantero];
							//printf("%c",buffer[delantero]);
							letras++;
							if (delantero==59)
							 {
							  while(!feof(arch) && bande==0)
								{
								 fread(&aux,1,1,arch);
								 if ((aux!=' ' && aux!=';' && aux!='(' && aux!='{' && aux!=':' && aux!='[' && aux!='-' && aux!='=' && aux!='+' && aux!='*' && aux!='/') && (!esletra(aux)))
								   {
									palabra[letras]=aux;
									letras++;
								   }
								 else
								   {
									if (esletra(aux))
										{
										palabra[letras]=aux;
										letras++;
										ban=1;
										}
									else
										{
									if ((buscar(palabra))==1)
									   {
										strcpy(tabla[gral].nombre,palabra);
										fflush(stdin);
										gral++;
										comienzo=delantero;
										//printf(" es un numero valido \n");
										bande=1;
										comienzo=cont;
									   }
									for (int i=0;i<letras;i++)
										palabra[i]=NULL;
								   fflush(stdin);
								   letras=0;
								   comienzo=delantero;
								   comienzo=cont;
								   }
								   }
								}
							 }

							delantero++;
						   }
						 else
						   {
							if(esletra(buffer[delantero]))
							  {
							   ban=1;
							   if (buffer[delantero]!=' ')
								  {
								   //printf("%c",buffer[delantero]);
								   delantero++;
								  }
							   else
								  {
								   //printf(" Error lexico.\n");
								   otraflag=1;
								   delantero++;
								   comienzo=delantero;
								  }
							  }
							else
							  {
							   if (estado==1 && ban==0)
								  {
								   delantero++;
								   comienzo=delantero;
								   fflush(stdin);
								   if ((buscar(palabra))==1)
									   {
										strcpy(tabla[gral].nombre,palabra);
										gral++;
										//printf(" es un numero valido \n");
									   }
								   for (int i=0;i<letras;i++)
									  palabra[i]=NULL;
								   fflush(stdin);
								   comienzo=delantero;
								   letras=0;
								  }
							   else if(ban==1)
								  {
								   //printf(" Error. \n");
								   otraflag=1;
								   delantero++;
								   comienzo=delantero;
								  }
							  }
							letras=0;
						   }
						 }
					  else if(buffer[comienzo]=='+' || buffer[comienzo]=='-' || buffer[comienzo]=='*' || buffer[comienzo]=='/' || buffer[comienzo]=='%' || buffer[comienzo]=='<' || buffer[comienzo]=='>' || buffer[comienzo]=='=')
						 {
						  char aux1[2];
						  aux1[0]=buffer[comienzo];
						  aux1[1]=NULL;
						  if ((buscar(aux1))==1)
							  {
							  strcpy(tabla[gral].nombre,aux1);
							  gral++;
							  }
						  delantero++;
						  comienzo=delantero;
						 }
					  else
						 {
						 delantero++;
						 comienzo=delantero;
						 }
					  }
				  /*for(i=0;i<gral;i++)
				  printf("%s ,",tabla[i].nombre);*/
				  cont=0;
				  comienzo=0; delantero=0; letras=0, ban=0, bande=0;
				  fflush(stdin);
		 //		  getch();

				}
		 }
	 gramatica();
	 clrscr();
	 for(int g=0;g<gral;g++)
		printf("%s, %d, %s \n",tabla[g].nombre,tabla[g].tipo,tabla[g].tdato);
	 getch();
	 if (otraflag==1)
	   {
		printf("Hay errores l‚xicos, no se puede proceder al an lisis sint ctico, revise su c¢digo");
		getch();
		exit(0);
	   }
	 sintactico();
	 printf("Codigo sin errores...");
	 getch();
}

int buscar(char word[])
   {
   for (int i=0;i<gral;i++)
	 if ((strcmp(tabla[i].nombre,word))==0)
		 return(0);
   return(1);
   }

void sintactico()
   {
	 arch=fopen(ruta,"r");
	 while(!feof(arch))
		 gs(leer());
	 fclose(arch);
   }

char * leer()
   {

	 estado=0;
	 for (i=0;i<letras;i++)
		palabra[i]=NULL;
	 letras=0;
	 while(!feof(arch))
			 {
			  if (wordaux!=NULL)
				 {
				  if(esletra(wordaux))
				   {
					estado=1;
					palabra[letras]=wordaux;
					letras++;
					wordaux=NULL;
				   }
				  else if(esdigito(wordaux))
				   {
					estado=2;
					palabra[letras]=wordaux;
					letras++;
					wordaux=NULL;
				   }
				  else if(escaracter(wordaux))
				   {
					estado=3;
					palabra[letras]=wordaux;
					letras++;
					wordaux=NULL;
				   }
				  else if(esoperador(wordaux))
				   {
					estado=4;
					palabra[letras]=wordaux;
					letras++;
					wordaux=NULL;
				   }
				  else wordaux=NULL;

				 }
			  switch(estado)
			   {
				case 0:fread(&letra,1,1,arch);
					   if(esletra(letra))
						 {
						 estado=1;
						 palabra[letras]=letra;
						 letras++;
						 }
					   else if(esdigito(letra))
						 {
						 estado=2;
						 palabra[letras]=letra;
						 letras++;
						 }
					   else if(escaracter(letra))
						 {
						 estado=3;
						 palabra[letras]=letra;
						 letras++;
						 }
					   else if(esoperador(letra))
						 {
						 estado=4;
						 palabra[letras]=letra;
						 letras++;
						 }
					   break;
				case 1: fread(&letra,1,1,arch);
						if (esletra(letra) || esdigito(letra) || letra=='.')
						  {
						  estado=1;
						  palabra[letras]=letra;
						  letras++;
						  }
						else
						  estado=5;
						break;
				case 2: fread(&letra,1,1,arch);
						if (esdigito(letra) || letra=='.')
						  {
						  estado=2;
						  palabra[letras]=letra;
						  letras++;
						  }
						else
						  estado=5;
						break;
				case 3: fread(&letra,1,1,arch);
						if (escaracter(letra))
						  {
						  estado=3;
						  palabra[letras]=letra;
						  letras++;
						  }
						else
						  estado=5;
						break;
				case 4: fread(&letra,1,1,arch);
						if (esoperador(letra))
						  {
						  estado=4;
						  palabra[letras]=letra;
						  letras++;
						  }
						else
						  estado=5;
						break;
				case 5: for (i=0;i<strlen(word2);i++)
							word2[i]=NULL;
						int otraban=0;
						do{
						   if ((esletra(letra))==1 || (esdigito(letra))==1 || (esoperador(letra))==1 || (escaracter(letra))==1)
							 {
							  wordaux=letra;
							  otraban=1;
							 }
						   else
							 {
							  if(!feof(arch))
								fread(&letra,1,1,arch);
							  else
								otraban=1;
							 }
						}while(otraban==0);
						return(palabra);
						break;
				default:break;
			   }
			 }
   }


void gs(char otravar[])
   {
	  if ((strcmp(otravar,"if"))==0)
		 tipo=1;
	  else if ((strcmp(otravar,"for"))==0)
		 tipo=2;
	  else if ((strcmp(otravar,"while"))==0)
		 tipo=3;
	  else if ((strcmp(otravar,"do"))==0)
		 tipo=4;
	  else tipo=5;
	switch (tipo)
	   {
		 case 1: casoif();  //printf("IF, ");       			//if
				 break;
		 case 2: casofor();
				 break;
		 case 3: casowhile();
				 break;
		 case 4: casodo();
				 break;
		 default: break;
	   }
	for (i=0;i<letras;i++)
	  palabra[i]=NULL;
   }

int casoif()
	{

	}

int casofor()
	{
	 int estad=0, flag1=0;
	 char word5[15];
	 while(!feof(arch))
	   {
		for(i=0;i<strlen(word5);i++)
			word5[i]=NULL;
		strcpy(word5,leer());
		switch(estad)
		 {
		  case 0:if((strcmp(word5,"("))==0)
					estad=1;
				 else
					estad=17;
				 break;
		  case 1:if((buscartipo(word5))==2)
					estad=2;
				 else if((buscartipo(word5))==3)
					estad=5;
				 else
					estad=17;
				 break;

		  case 2:if(esoperador2(word5))
					estad=3;
				 else
					estad=17;
				 break;
		  case 3:if((buscartipo(word5))==2 || (buscartipo(word5))==1)
					estad=4;
				 else
					estad=17;
				 break;
		  case 4:if((strcmp(word5,";"))==0)
					estad=6;
				 else
					estad=17;
				 break;
		  case 5:if((buscartipo(word5))==2)
					estad=2;
				 else
					estad=17;
				 break;
		  case 6:if((buscartipo(word5))==2)
					estad=7;
				 else
					estad=17;
				 break;
		  case 7:if(esoperador2(word5))
					estad=8;
				 else
					estad=17;
				 break;
		  case 8:if((buscartipo(word5))==2 || (buscartipo(word5))==1)
					estad=9;
				 else
					estad=17;
				 break;
		  case 9:if((strcmp(word5,";"))==0)
					estad=10;
				 else
					estad=17;
				 break;
		  case 10:if((buscartipo(word5))==2)
					estad=11;
				 else
					estad=17;
				 break;
		  case 11:if(esoperador2(word5))
					estad=12;
				 else
					estad=17;
				 break;
		  case 12:if((strcmp(word5,")"))==0)
					estad=13;
				  else
					estad=17;
				  break;
		  case 13:if((strcmp(word5,"{"))==0)
					estad=15;
				  else if((strcmp(word5,"{"))!=0)
				   {
					estad=14;
					gs(word5);
				   }
				  else
					estad=17;
				  break;
		  case 14:return(1);
				  break;
		  case 15:while((strcmp(word5,"}"))!=0)
				   {
					if (!feof(arch))
					  {
					   gs(word5);
					   for(i=0;i<strlen(word5);i++)
					   word5[i]=NULL;
					   strcpy(word5,leer());
					  }
					else
					  {
					   printf("ERROR: Ciclo FOR incompleto");
					   getch();
					   exit(0);
					  }
				   }
				  estad=14;
				  break;
		  case 17:printf("ERROR: Ciclo FOR mal estructurado");
				  getch();
				  exit(0);
				  break;
		  default: break;
		 }
	   }
	}

int casowhile()
	{
	 int estad1=0;
	 char word6[15];
	 while(!feof(arch))
	   {
		for(i=0;i<strlen(word6);i++)
			word6[i]=NULL;
		strcpy(word6,leer());
		switch(estad1)
		 {
		  case 0:if((strcmp(word6,"("))==0)
					estad1=1;
				 else
					estad1=9;
				 break;
		  case 1:if((buscartipo(word6))==2)
					estad1=2;
				 else
					estad1=9;
				 break;

		  case 2:if(esoperador2(word6))
					estad1=3;
				 else
					estad1=9;
				 break;
		  case 3:if((buscartipo(word6))==2 || (buscartipo(word6))==1)
					estad1=4;
				 else
					estad1=9;
				 break;
		  case 4:if((strcmp(word6,")"))==0)
					estad1=5;
				 else
					estad1=9;
				 break;
		  case 5:if((strcmp(word6,"{"))==0)
					estad1=7;
				  else if((strcmp(word6,"{"))!=0)
				   {
					estad1=6;
					gs(word6);
				   }
				  else
					estad1=9;
				  break;
		  case 6:return(1);
				  break;
		  case 7:while((strcmp(word6,"}"))!=0)
				   {
					if (!feof(arch))
					  {
					   gs(word6);
					   for(i=0;i<strlen(word6);i++)
					   word6[i]=NULL;
					   strcpy(word6,leer());
					  }
					else
					  {
					   printf("ERROR: Ciclo WHILE incompleto");
					   getch();
					   exit(0);
					  }
				   }
				  estad1=6;
				  break;
		  case 9:printf("ERROR: Ciclo WHILE mal estructurado");
				  getch();
				  exit(0);
				  break;
		  default: break;
		 }
	   }
	}

int buscartipo(char word4[])
   {
   for (int i=0;i<gral;i++)
	 if ((strcmp(tabla[i].nombre,word4))==0)
		 return(tabla[i].tipo);
   return(0);
   }

void casodo()
{
 int lo=0;
 char word3[15];
 if((strcmp(leer(),"{"))==0)
  {
   strcpy(word3,leer());
   while((strcmp(word3,"}"))!=0)
	   {
	   if (!feof(arch))
		{
		gs(word3);
		lo=1;
		for(i=0;i<strlen(word3);i++)
			word3[i]=NULL;
		strcpy(word3,leer());
		}
	   else
		{
		printf("ERROR: Ciclo DO incompleto");
		getch();
		exit(0);
		}
	   }
   if((strcmp(leer(),"while"))==0)
	 {
	  if((strcmp(leer(),"("))==0)
		{
		 if((buscartipo(leer()))==2)
		   {
			if(esoperador2(leer()))
			  {
			   for(i=0;i<strlen(word3);i++)
					 word3[i]=NULL;
			   strcpy(word3,leer());
			   if((buscartipo(word3))==2 || (buscartipo(word3))==1)
				 {
				  if((strcmp(leer(),")"))==0)
					{
					 if((strcmp(leer(),";"))==0)
					   {
					   }
					 else
					   {
						printf("ERROR: Se esperaba ;");
						getch();
						exit(0);
					   }
					}
				  else
					{
					 printf("ERROR: Se esperaba )");
					 getch();
					 exit(0);
					}
				 }
			   else
				 {
				  printf("ERROR: Condici¢n erronea en ciclo DO...");
				  getch();
				  exit(0);
				 }
			  }
			else
			  {
			   printf("ERROR: Condici¢n erronea en ciclo DO...");
			   getch();
			   exit(0);
			  }
		   }
		 else
		   {
			printf("ERROR: Condici¢n erronea en ciclo DO...");
			getch();
			exit(0);
		   }
		}
	  else
		{
		 printf("ERROR: Se esperaba (");
		 getch();
		 exit(0);
		}
	 }
   else
	 {
	  printf("ERROR: Ciclo DO incompleto...");
	  getch();
	  exit(0);
	 }
  }
 else
  {
   printf("ERROR: Se esperaba {");
   getch();
   exit(0);
  }
 if(lo==0)
  {
   printf("ERROR: Se esperaba }");
   getch();
   exit(0);
  }

}



