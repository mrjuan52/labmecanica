#include <stdio.h>
#include "entradatexto.h"
int tot(),cont,h,n;
float c1,c2,suma,prom;
FILE *f;
float promedio(int columna)
	{
	n=tot();
	cont=1;
	suma=0;
	f=fopen("datos.txt","r");
	while((h=fgetc(f))!=EOF)
		{
		fscanf(f,"%f %f ",&c1,&c2);
		if(cont<=n && h!=92)
			{
			if (columna==1) {suma+=c1;}
			else if (columna==2) {suma+=c2;}
			cont++;
			}
		}
	prom=(suma)/n;
	fclose(f);
	return(prom);
	}
