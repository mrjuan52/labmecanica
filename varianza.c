#include "promedio.h"
int main()
	{
	float prom,sigma2,suma,v1,v2;
	int n,h,k;
	FILE *f;
	n=tot();
	prom=promedio(2);
	suma=0;
	k=1;
	f=fopen("datos.txt","r");
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
	printf("sigma²= %f\n",sigma2);
	fclose(f);
	}
