/*Si le metes mano a este archivo sigue el metodo con el que yo corregí, practicamente estamos a unos pasos de acabar, si puedo mañana me lo aviento si ayudas lo llego a revisar. Segun yo ya debe de estar bien, pero hay un pequeño bug en el que hay que dejar un enter en el archivo inicial para que te vacie bien los datos a la matriz. Si lo puedes checar e  intentar parchar, seria genial.
    Saludos!
 Creditos a: Francisco Torreblanca por el archivo original*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int tot(char* l){
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
	        while((ch = fgetc(f))!= EOF){
			if(ch=='\n')
				{
				total++;
				}
			}
        }
	fclose(f);
	return(total);
  }

float promedio(float arreglo[][2], int x)
	{
	int cont,h;
	float c1,suma,prom;
	cont=0;
	suma=0;
	while(cont<=x){
        suma+=arreglo[cont][1];
        cont++;
		}
	prom=(suma)/x;
	return(prom);
	}

float varianza(float arreglo[][2], int x)
	{
	float prom,sigma2,suma1;
	int k;
	prom=promedio(arreglo,x);
	suma1=0;
	k=0;
	while(k<x){
			suma1+=fabs((((prom-arreglo[k][1])*(prom-arreglo[k][1]))));
			//printf("Para i=%d tenemos SUMA%d= (%f - %f)² = (%f)² =%f\n",k+1,k+1,prom,arreglo[k][1],(prom-arreglo[k][1]),fabs((((prom-arreglo[k][1])*(prom-arreglo[k][1])))));
			k++;
			}
	//printf("La suma total es: %f\n",suma1);
	sigma2=suma1/(x-1);
    k=k-1;
	//printf("sigma² = (1/n-1) * (Suma total) = (1/%d)*(%f) = %f\n",k,suma1,sigma2);
	return(sigma2);
	}

float desviacion(float arreglo[][2], int x)
	{
	    float V,D;
	    V=varianza(arreglo,x);
	    D=sqrt(V);
	    //printf("Sigma = √[Varianza] = √(%f) = %f\n",V,D);
	return (D);
	}

float ErEs(float arreglo[][2], int x)
	{
	    float D,S;
        D=desviacion(arreglo,x);
        S=(D)/(sqrt(x));
	    //printf("S= (sigma)/√n = (%f)/(√%i) = %f\n",D,x,S);
	    return (S);
	}
