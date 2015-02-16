printf("Que quieres dar de baja?\n");
	 printf("1.    Libro\n2.    Alumno " );
	  scanf("%d",&r);
	 if(r==1){//bl
	   FILE *basura;
	   printf("Baja libro\n ");
	   printf("Clave del libro ");
	   fflush (stdin);
	   gets(clave_lib2);
	   basura=fopen("c:\\bajalibro.001","ab");
	   archl=fopen("c:\\archlib.001","rb");
	   fseek(archl,SEEK_SET,0);
	   fread(&libro,sizeof(libro),1,archl);
	   while(!feof(archl))
		{
		z=strcmp(clave_lib2,libro.clave_lib);
		if(z!=0)
		  fwrite(&libro,sizeof(libro),1,basura);
		fread(&libro,sizeof(libro),1,archl);
		}
	  fclose(basura);
	  fclose(archl);
	  remove("c:\\archlib.001");
	  rename("c:\\bajalibro.001","c:\\archlib.001");
