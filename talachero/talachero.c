/*Revisa el archivo ./lib/funcionesT.h*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./lib/funcionesT.h"

int tot(),x,c,h,H,k;
float v1,v2,p,var,des,err,m,b,corr,Em,eb;
char l[80],d[65],V1,V2,V[5];
FILE *f;
int main(){
    printf("Nombre del archivo a analizar: ");
    scanf("%79s",l);
    printf("\n**** ABRIENDO %s ****\n",l);
    x=tot(l);
    printf("Numero de datos: %i \n",x);
    c=0;
    float arreglo[x][2];
    printf("-------------------------\n");
    printf("|     X      |     Y    |\n");
    //friking matriz
    f = fopen(l,"r");
    while((h = fgetc(f))!=EOF){
	fscanf(f, "%c%f %f %c", &V2,&v1,&v2, &V1);
        if(c<x){
	    if (h>47 && h<58){
		sprintf(d,"%c",h);
		if (V2=='.'){sprintf(V,".%i",(int)v1);}
		else {sprintf(V,"%f",v2); v2=v1;}
		strcat(d,V);
		v1=atof(d);
		arreglo[c][0]=v1;
		arreglo[c][1]=v2;
	     	printf("| %f | %f |\n", arreglo[c][0], arreglo[c][1]);
	    	c++;
	    }
	    else{
	            arreglo[c][0] = v1;
        	    arreglo[c][1] = v2;
        	    printf("| %f | %f |\n", arreglo[c][0], arreglo[c][1]);
        	    c++;
	    }
        }
    }
    printf("-------------------------\n");
    //Friking matriz
    //Promedio
    p=promedio(arreglo,x,0);
    printf("Promedio de datos en x: %f \n", p);
    p=promedio(arreglo,x,1);
    printf("Promedio de datos en y: %f \n", p);
    p=promedio(arreglo,x,2);
    printf("Promedio de datos en xy: %f \n", p);
    //promedio
    //sigma^2
    var=varianza(arreglo,x,0);
    printf("sigma²x = %f\n", var);
    var=varianza(arreglo,x,1);
    printf("sigma²y = %f\n", var);
    var=varianza(arreglo,x,2);
    printf("sigma²xy = %f\n", var);
    //sigma^2
    //desviacion standard
    des=desviacion(arreglo,x,0);
    printf("Sigma x = %f\n", des);
    des=desviacion(arreglo,x,1);
    printf("Sigma y = %f\n", des);
    des=desviacion(arreglo,x,2);
    printf("Sigma xy = %f\n", des);
    //Desviacion standard
    //Error Estimado
    err=ErEs(arreglo,x,0);
    printf("Sx= %f\n",err);
    err=ErEs(arreglo,x,1);
    printf("Sy= %f\n",err);
    //error Estimado
    //pendiente en mínimos cuadrados
    m=MinCuaM(arreglo,x);
    printf("m= %f\n",m);
    //ordenada en el origen en mínimos cuadrados
    b=MinCuaB(arreglo,x);
    printf("b= %f\n",b);
    //coeficiente de correlacion
    corr=correlacion(arreglo,x);
    printf("P= %f\n",corr);
    //Error en la pendiente
    Em=EMinCuaM(arreglo,x);
    printf("Error en m= %f\n",Em);
    eb=EMinCuaB(arreglo,x);
    printf("Error en b= %f\n", eb);
    fclose(f);
}
