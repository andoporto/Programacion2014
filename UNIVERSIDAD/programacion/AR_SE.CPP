//principio------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <iostream.h>
#define TRUE 1
#define FALSE 0
//----------------------------------------------------------------------
//declaraciones
typedef int bool;
typedef char t_sCad[5];
typedef struct t_sAlumno
   {
     char chrcurso;
     char strnombre[10];
     int  intnota;
   };

//----------------------------------------------------------------------
//prototipos

bool AbrirE(t_sCad aNomarch,FILE *&ArchE);
bool AbrirS(t_sCad aNomarch,FILE *&ArchS);
void leerArch(FILE *&ArchE,t_sAlumno &sRegE, bool &bfin);
void grabar (FILE *&ArchS,t_sAlumno sreg);
void cerrar (FILE *Arch);
bool ingreso(t_sAlumno &sReg,bool &bfin);

//----------------------------------------------------------------------
void main(void)
{
  t_sAlumno sAlumno;
  bool bFinArch;
  FILE* archsal;
  FILE* arching;
  bool bOKE,bOKS,bOKA;
  bFinArch=FALSE;
  int cantapro,cantalum;
  t_sCad snomarch;
  clrscr();
  strcpy(snomarch,"c:\\notas.dat");
  bOKA=AbrirS(snomarch,arching);
    ingreso(sAlumno,bFinArch);
    if ((bOKA)&&(!bFinArch))
      {
 while (!bFinArch)
   {
     grabar(arching,sAlumno);
     ingreso(sAlumno,bFinArch);
   }
   cerrar(arching);
      }
  bOKE=AbrirE(snomarch,arching);
  strcpy(snomarch,"c:\\aprobado.dat");
  bOKS=AbrirS(snomarch,archsal);
  if ((bOKE)&&(bOKS))
    {
      cantalum=0;
      cantapro=0;
      leerArch(arching,sAlumno,bFinArch);
      while (!bFinArch)
 {
   cantalum++;
   if (sAlumno.intnota>=4)
     {
       grabar(archsal,sAlumno);
       cantapro++;
     };
       leerArch(arching,sAlumno,bFinArch);
 }
      cout<<"cantidad de alumnos procesados:"<<cantalum<<endl;
      cout<<"cantidad de alumnos aprobados:"<<cantapro<<endl;
      cerrar(arching);
      cerrar(archsal);
      getch();
    }
}

//----------------------------------------------------------------------
bool AbrirE(t_sCad aNomarch,FILE *&ArchE)
{
  bool bpude=FALSE;
  ArchE=fopen(aNomarch,"rb");
  if (ArchE==NULL)
    {
      cout <<"no se pudo abrir el archivo de entrada"<<"\n";
      bpude =FALSE;
    }
  else bpude =TRUE;
    return bpude;
}

//----------------------------------------------------------------------
bool AbrirS(t_sCad aNomarch,FILE *&ArchS)
{
  bool bPude=FALSE;
  ArchS=fopen(aNomarch,"wb");
  if (ArchS==NULL)
    {
      //tambien puede preguntarse if(!ArchS)
      cout<<"no se pudo abrir el archivo de salida"<<"\n";
      bPude=FALSE;
    }
  else bPude=TRUE;
    return bPude;
}

//----------------------------------------------------------------------
void leerArch(FILE *&ArchE, t_sAlumno &sRegE,bool &bfin)
{
  fread(&sRegE,sizeof(sRegE),1,ArchE);
  if feof(ArchE)
    {
      bfin=TRUE;
    }
  else
    bfin=FALSE;//tambien puede escribirse bfin =feof (arche)
      return;
}

//----------------------------------------------------------------------
void grabar (FILE *&ArchS,t_sAlumno sReg)
{
  fwrite(&sReg,sizeof(sReg),1,ArchS);
}

//----------------------------------------------------------------------
void cerrar (FILE *arch)
{
  fclose(arch);
  return;
}
//----------------------------------------------------------------------
bool ingreso(t_sAlumno &sReg,bool &bfinArch)
    {
 char *str="fin";
 bfinArch=FALSE;
 cout<<"ingrese nombre"<<"\n";
 cin>>sReg.strnombre;
 if (strcmp(sReg.strnombre,str)==0)
   {
     bfinArch=TRUE;
   }
 else
   {bfinArch=FALSE;
   cout<<"ingrese nota"<<"\n";
   cin>>sReg.intnota;}
      return bfinArch;
    }
//fin-------------------------------------------------------------------------------------------------------------
