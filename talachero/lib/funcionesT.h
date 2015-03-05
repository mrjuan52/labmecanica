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

float promedio(float arreglo[][2], int x,int col)
	{
	int cont,h;
	float c1,suma,prom;
	cont=0;
	suma=0;
	while(cont<x){
	if (col==2){suma+=arreglo[cont][0]*arreglo[cont][1];}
	else{suma+=arreglo[cont][col];}
//	printf("%f\n",arreglo[cont][col]);
        cont++;
		}
	prom=(suma)/x;
	return(prom);
	}

float varianza(float arreglo[][2], int x, int col)
	{
	float prom,sigma2,suma1;
	int k;
	prom=promedio(arreglo,x,col);
	suma1=0;
	k=0;
	while(k<x){
		if (col==2){suma1+=fabs((((prom-(arreglo[k][0]*arreglo[k][1]))*(prom-(arreglo[k][0]*arreglo[k][1])))));}
		else {suma1+=fabs((((prom-arreglo[k][col])*(prom-arreglo[k][col]))));}
			//printf("Para i=%d tenemos SUMA%d= (%f - %f)² = (%f)² =%f\n",k+1,k+1,prom,arreglo[k][1],(prom-arreglo[k][1]),fabs((((prom-arreglo[k][1])*(prom-arreglo[k][1])))));
			k++;
	}
	//printf("La suma total es: %f\n",suma1);
	sigma2=suma1/(x-1);
    k=k-1;
	//printf("sigma² = (1/n-1) * (Suma total) = (1/%d)*(%f) = %f\n",k,suma1,sigma2);
	return(sigma2);
	}

float desviacion(float arreglo[][2], int x,int col)
	{
	    float V,D;
	    V=varianza(arreglo,x,col);
	    D=sqrt(V);
	    //printf("Sigma = √[Varianza] = √(%f) = %f\n",V,D);
	return (D);
	}

float ErEs(float arreglo[][2], int x, int col)
	{
	    float D,S;
        D=desviacion(arreglo,x,col);
        S=(D)/(sqrt(x));
	    //printf("S= (sigma)/√n = (%f)/(√%i) = %f\n",D,x,S);
	    return (S);
	}

float MinCuaM(float arreglo[][2], int x)
	{
	float m,sumaxy,sumax,sumay,sumax2;
	sumax=0;
	sumay=0;
	sumaxy=0;
	sumax2=0;
	int k;
	for (k=0;k<x;k++)
		{
		sumax+=arreglo[k][0];
		sumay+=arreglo[k][1];
		sumaxy+=arreglo[k][0]*arreglo[k][1];
		sumax2+=arreglo[k][0]*arreglo[k][0];
		}
	m=(((x*sumaxy)-(sumax*sumay))/((x*sumax2)-(sumax*sumax)));
	return(m);
	}

float MinCuaB(float arreglo[][2], int x)
	{
	float b,m,sumax=0,sumay=0;
	int k;
	for (k=0;k<x;k++)
		{
		sumax+=arreglo[k][0];
		sumay+=arreglo[k][1];
		}
	m=MinCuaM(arreglo,x);
	b=(((sumay)-(m*sumax))/x);
	return(b);
	}

float correlacion(float arreglo[][2], int x)
	{
	float corr,sumaxy,sumax,sumay,sumax2, sumay2;
	sumax=0;
	sumay=0;
	sumaxy=0;
	sumax2=0;
	sumay2=0;
	int k;
	for (k=0;k<x;k++)
		{
		sumax+=arreglo[k][0];
		sumay+=arreglo[k][1];
		sumaxy+=arreglo[k][0]*arreglo[k][1];
		sumax2+=arreglo[k][0]*arreglo[k][0];
		sumay2+=arreglo[k][1]*arreglo[k][1];
		}
	corr=(((x*sumaxy)-(sumax*sumay))/(sqrt(((x*sumax2)-(sumax*sumax))*((x*sumay2)-(sumay*sumay)))));
	return (corr);
	}

float EMinCuaM(float arreglo[][2], int x)
	{
	float Em,m,sumax,sumax2,dy,sumady2,b;
	sumax=0;
	sumax2=0;
	sumady2=0;
	m=MinCuaM(arreglo,x);
	b=MinCuaB(arreglo,x);
	int k;
	for (k=0;k<x;k++)
		{
		dy=(m*arreglo[k][0])+b-arreglo[k][1];
		sumax+=arreglo[k][0];
		sumax2+=arreglo[k][0]*arreglo[k][0];
		sumady2+=dy*dy;
		}
	printf("%f %f %f %f\n",sumax,sumax2,dy,sumady2);
	Em=sqrt((1/(x-2))*(sumady2))*sqrt((x)/((x*sumax2)-(sumax*sumax)));
	return(Em);
	}
