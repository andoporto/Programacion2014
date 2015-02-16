void bajas()
{
	clrscr();
	int i,z;
	printf("\n                            Que Deseas Dar De Baja\n");
	printf("\n                                  1.-Alumno\n");
	printf("\n                                  2.-libro\n");
	scanf("%d",&i);
	if(i==1)
	{
		clrscr();
		FILE *arch,*temp;
		alumno2 alumnos1;
		char nc[50];
		int a,ban;
		temp=fopen("C:\\alumn1.txt","ab");
		arch=fopen("C:\\alumn.txt","rb");
		fflush(stdin);
		printf("\n\n                            Numero de Control: ");
		gets(nc);
		fread(&alumnos1,sizeof(alumnos1),1,arch);
		ban=0;
		while(!feof(arch)&&(!ban))
		{
			if(!strcmp(alumnos1.num_control,nc))//cadenas iguales
				 ban=1;
			else
				 fread(&alumnos1,sizeof(alumnos1),1,arch);
		}
		if (!ban)
				printf("                           Registro No Localizado");
		else
		{
			 fseek(arch,SEEK_SET,0);
			 fread(&alumnos1,sizeof(alumnos1),1,arch);
			 while(!feof(arch))
			 {
				z=strcmp(alumnos1.num_control,nc);
				if( z!=0)//strcmp(alumnos1.num_control,nc))
				fwrite(&alumnos1,sizeof(alumnos1),1,temp);
				fread(&alumnos1,sizeof(alumnos1),1,arch);
		{
		// fwrite(&alumnos1,sizeof(alumnos1),1,temp);

		}

			 }
			 fclose(arch);
			 fclose(temp);
			 remove("C:\\alumn.txt");
			 rename("C:\\alumn1.txt","C:\\alumn.txt");
			 printf("\n\n                               Registro Borrado");
			}
			getch();
	}
	else
		{
			clrscr();
			FILE *arch5,*tempo;
			reg_lib libro;
			char ncl[30];
			int band,a;
			tempo=fopen("C:\\libros2.txt","ab");
			arch5=fopen("C:\\libros1.txt","rb");
			fflush(stdin);
			printf("\n\n                              Clave Del Libro: ");
			gets(ncl);
			fread(&libro,sizeof(libro),1,arch5);
			band=0;
			while(!feof(arch5)&&(!band))
			{
				if(!strcmp(libro.clave_lib,ncl))//cadenas iguales
		 band=1;
				else
		 fread(&libro,sizeof(libro),1,arch5);
			}
			if (!band)
				 printf("                            Registro No Localizado");
			else
			{
			 {
			 fseek(arch5,SEEK_SET,0);
			 fread(&libro,sizeof(libro),1,arch5);
			 while(!feof(arch5))
			 {
				a=strcmp(libro.clave_lib,ncl);
				if(a!=0)
				fwrite(&libro,sizeof(libro),1,tempo);
				fread(&libro,sizeof(libro),1,arch5);
			 }
		 //		fread(&libro,sizeof(libro),1,arch5);
			 }
			 fclose(arch5);
			 fclose(tempo);
			 remove("C:\\libros1.txt");
			 rename("C:\\libros2.txt","C:\\libros1.txt");
			 printf("\n\n                                  Registro Borrado");
			}
	 }
			getch();
}

