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
	printf("La sumatoria es: \n");
	while ((h=fgetc(f))!=EOF)
		{
		fscanf(f,"%f %f ",&v1,&v2);
		if (k<=n && h!=92)
			{
			printf("Para i=%d tenemos SUMA%d= (%.5f - %.5f)² = (%.5f)² \t=%.5f\n",k,k,prom,v2,(prom-v2),(prom-v2)*(prom-v2));
			suma+=((prom-v2)*(prom-v2));
			k++;
			}
		}
	printf("La suma total es: %f\n",suma);
	sigma2=suma/n;
	printf("sigma² = (1/n) * (Suma total) = (1/%d)*(%f) = %f\n",n,suma,sigma2);
	fclose(f);
	}
