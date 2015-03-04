/*Revisa el archivo ./lib/funcionesT.h*/
#include <stdio.h>
#include "./lib/funcionesT.h"

int tot(),x,c,h;
float v1,v2,promedio(),p,varianza(),var,desviacion(),des,ErEs(),err;
char l[80];
FILE *f;
int main(){printf("Nombre del archivo a analizar: ");
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
        fscanf(f, "%f %f ", &v1, &v2);
        if(c<x && h!=92){
            arreglo[c][0] = v1;
            arreglo[c][1] = v2;
            printf("| %f | %f |\n", arreglo[c][0], arreglo[c][1]);
            c++;
        }
    }
    printf("-------------------------\n");
    //Friking matriz
    //Promedio
    p=promedio(arreglo,x);
    printf("Promedio de datos %f \n", p);
    //promedio
    //sigma^2
    var=varianza(arreglo,x);
    printf("sigma² = %f\n", var);
    //sigma^2
    //desviacion standard
    des=desviacion(arreglo,x);
    printf("Sigma = %f\n", des);
    //Desviacion standard
    //Error Estimado
    err=ErEs(arreglo,x);
    printf("S= %f\n",err);
    //error Estimado
    fclose(f);
}
