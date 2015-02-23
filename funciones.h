#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int tot(char* l)
  {
	FILE *f;
	int total;
	char ch;
	total=0;
	f = fopen(l,"r");
	if (f == NULL)
		{
	        printf("\nError de apertura. \n\n");
		}
	else
		{
	        while((ch = fgetc(f))!= EOF)
			{
			if(ch=='\n')
				{
				total++;
				}
			}
		}
	fclose(f);
	return(total);
  }

float promedio(char* l,int columna)
	{
	int cont,h,n;
	float c1,c2,suma,prom;
	FILE *f;
	n=tot(l);
	cont=1;
	suma=0;
	f=fopen(l,"r");
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

float varianza(char* l,int columna)
	{
	float prom,sigma2,suma,v1,v2;
	int n,h,k;
	FILE *f;
	n=tot(l);
	prom=promedio(l,columna);
	suma=0;
	k=1;
	f=fopen(l,"r");
	while ((h=fgetc(f))!=EOF)
		{
		fscanf(f,"%f %f ",&v1,&v2);
		if (k<=n && h!=92)
			{
			suma+=((prom-v2)*(prom-v2));
			k++;
			}
		}
	sigma2=suma/n;
	fclose(f);
	return(sigma2);
	}

float desviacion(char* l, int columna)
	{
	float V,D;
	V=varianza(l,columna);
	D=sqrt(V);
	return (D);
	}

float ErEs(char* l, int columna)
	{
	float D, S;
	int n;
	n=tot(l);
	D=desviacion(l,columna);
	S=(D)/(sqrt(n));
	return (S);
	}


