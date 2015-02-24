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
	        printf("\n---ERROR DE APERTURA---\n\n");
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

float varianza(char* l,int columna,char A)
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
			if (A=='v'){printf("Para i=%d tenemos SUMA%d= (%.5f - %.5f)² = (%.5f)² =%.5f\n",k,k,prom,v2,(prom-v2),(prom-v2)*(prom-v2));}
			k++;
			}
		}
	if (A=='v'){printf("La suma total es: %f\n",suma);}
	sigma2=suma/(n-1);
	if (A=='v'){printf("sigma² = (1/n-1) * (Suma total) = (1/%d)*(%f) = %f\n",n,suma,sigma2);}
	fclose(f);
	return(sigma2);
	}

float desviacion(char* l, int columna,char A)
	{
	float V,D;
	V=varianza(l,columna, 'd');
	D=sqrt(V);
	if (A=='d'){printf("Sigma = √[Varianza] = √(%f) = %f\n",V,D);}
	return (D);
	}

float ErEs(char* l, int columna, char A)
	{
	float D, S;
	int n;
	n=tot(l);
	D=desviacion(l,columna,'e');
	S=(D)/(sqrt(n));
	if (A=='e'){printf("S= (sigma)/√n = (%f)/(√%i) = %f\n",D,n,S);}
	return (S);
	}


