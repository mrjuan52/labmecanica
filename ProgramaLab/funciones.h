/*Biblioteca de funciones
Creado por: 
Torreblanca Nava José Francisco
Juan Olivos*/
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
		if (col==2)
		{suma1+=((promedio(arreglo,x,0)-arreglo[k][0])*(promedio(arreglo,x,1)-arreglo[k][1]));}
		else 
		{suma1+=fabs((((prom-arreglo[k][col])*(prom-arreglo[k][col]))));}
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

/*float correlacion(float arreglo[][2], int x)
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
*/

float correlacion(float arreglo[][2],int x)
	{
		float corrp,sigmaxy,sigmax,sigmay;
		sigmax=desviacion(arreglo,x,0);
		sigmay=desviacion(arreglo,x,1);
		sigmaxy=varianza(arreglo,x,2);
		corrp=(sigmaxy/(sigmax*sigmay));
		return(corrp);
	}

float EMinCuaM(float arreglo[][2], int x)
	{
	float Em,em1,em2,m,sumax,sumax2,dy,sumady2,b,sumady2p,em1p;
	sumax=0;
	sumax2=0;
	sumady2=0;
	m=MinCuaM(arreglo,x);
	b=MinCuaB(arreglo,x);
	int k;
	for (k=0;k<x;k++)
		{
		dy=((m*arreglo[k][0])+(b-arreglo[k][1]));
		sumax+=arreglo[k][0];
		sumax2+=pow(arreglo[k][0],2);
		sumady2+=pow(dy,2);
        //printf("%f\n",sumady2);
		}
	//printf("%f %f %f %f %i\n",sumax,sumax2,dy,sumady2,x); 
        sumady2p=sumady2;
       // em1=(sqrt(1)/sqrt((x-2)))*sqrt((sumady2p))*sqrt(x/((x*sumax2)-pow(sumax,2)));
	//em2=sqrt(x/((x*sumax2)-pow(sumax,2)));
        Em=(sqrt(1)/sqrt((x-2)))*sqrt((sumady2p))*sqrt(x/((x*sumax2)-pow(sumax,2)));
        //printf("%f %f %f\n",em1, em1p, em2);
        
	return(Em);
	}
float EMinCuaB(float arreglo[][2],int x){
    
    float sumabx,sumabx2,sumabdy2,m1,b1,bdy,eb;
    sumabx=0;
    sumabx2=0;
    sumabdy2=0;
    m1=MinCuaM(arreglo,x);
    b1=MinCuaB(arreglo,x);
    int pa;
    pa=0;
    while(pa<x){
        bdy=((m1*arreglo[pa][0])+(b1-arreglo[pa][1]));
        sumabx+=arreglo[pa][0];
        sumabx2+=pow(arreglo[pa][0],2);
        sumabdy2+=pow(bdy,2);
        pa++;
    }
    eb=(sqrt(1)/sqrt((x-2)))*sqrt((sumabdy2))*(sqrt(sumabx2)/sqrt((x*sumabx2)-pow(sumabx,2)));
    return(eb);
}

//Mínimos cuadrados de una parábola Y=AX²+BX+C
float MinCuaP(float arreglo[][2], int n,int V)
{
	float Ap,Bp,Cp,Sx,Sy,Sxy,Sx2,Sx3,Sx4,Sx2y,Dt,DA,DB,DC;
	int k;
	Sx=0;Sy=0;Sxy=0;Sx2=0;Sx3=0;Sx4=0;Sx2y=0;
	for (k=0;k<n;k++)
	{
		Sx+=arreglo[k][0];
		Sy+=arreglo[k][1];
		Sxy+=arreglo[k][0]*arreglo[k][1];
		Sx2+=pow(arreglo[k][0],2);
		Sx3+=pow(arreglo[k][0],3);
		Sx4+=pow(arreglo[k][0],4);
		Sx2y+=pow(arreglo[k][0],2)*arreglo[k][1];
	}
	Dt=((n*Sx2*Sx4)+(Sx*Sx3*Sx2)+(Sx2*Sx*Sx3)-(pow(Sx2,3))-(Sx*Sx*Sx4)-(n*Sx3*Sx3));
	DC=(Sy*Sx2*Sx4)+(Sxy*Sx3*Sx2)+(Sx2y*Sx*Sx3)-(Sx2y*Sx2*Sx2)-(Sxy*Sx*Sx4)-(Sy*Sx3*Sx3);
	DB=((n*Sxy*Sx4)+(Sy*Sx3*Sx2)+(Sx2*Sx*Sx2y)-(Sx2*Sxy*Sx2)-(Sx*Sy*Sx4)-(n*Sx2y*Sx3));
	DA=((n*Sx2*Sx2y)+(Sx*Sxy*Sx2)+(Sy*Sx*Sx3)-(Sx2*Sx2*Sy)-(Sx*Sx*Sx2y)-(n*Sx3*Sxy));	
	Ap=DA/Dt;
	Bp=DB/Dt;
	Cp=DC/Dt;
	if (V==1) {return(Ap);}
	if (V==2) {return(Bp);}
	if (V==3) {return(Cp);}
}

float chi2(float arreglo[][2],int N,int W)
{
	float M,Bl,X2,suma,vari,Al,Pen,Cl;
	int L;
	suma=0;
	M=MinCuaM(arreglo,N);
	Pen=MinCuaB(arreglo,N);
	vari=varianza(arreglo,N,1);
	Al=MinCuaP(arreglo,N,1);
	Bl=MinCuaP(arreglo,N,2);
	Cl=MinCuaP(arreglo,N,3);
	for (L=0;L<N;L++)
	{
		if (W==1) {suma+=pow(((M*arreglo[L][0]+Pen)-arreglo[L][1]),2);}
		if (W==2) {suma+=pow((((Al*pow(arreglo[L][0],2))+(Bl*arreglo[L][0])+Cl)-arreglo[L][1]),2);}
	}
	X2=((suma)/(vari));
	return (X2);
}

float chi2Red(float arreglo[][2],int x,int l)
{
	float chi,N,chi2Red, P;
	if (l==1) {P=2;}
	if (l==2) {P=3;}
	chi=chi2(arreglo,x,l);
	chi2Red=(chi)/(x-P);
	return(chi2Red);
}
