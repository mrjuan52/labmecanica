/*Programa principal.
Creado por: 
Torreblanca Nava José Francisco 
Juan Olivos*/
#include <string.h>
#include "funciones.h"

int tot(),x,c,h,H,k;
float v1,v2,p,var,des,err,m,b,corr,Em,eb,X,Xred,A,B,C;
char l[80],d[65],V1,V2,V[5];
FILE *f;
int main(){
    //Iniciamos pidiendo el nombre del archivo a analizar. La condición de este es que al final de cada renglón tenga un \n para que funcione correctamente. La extensión del archivo no importa, solo que sea un archivo de texto plano.
    printf("Nombre del archivo a analizar: ");
    scanf("%79s",l);
    //Solo como medidia de control, imprimimos en pantalla el nombre del archivo, esto para que cuando el programa se guarde como archivo de texto sepamos a partir de qué archivo se hizo el análisis
    printf("\n**** ABRIENDO %s ****\n",l);
    //Mandamos a llamar la función tot(cadena) que nos dará el total de filas que hay en el archivo 'cadena'.
    x=tot(l);
    printf("Numero de datos: %i \n",x);
    c=0;
    float arreglo[x][2];
    //Creamos un pequeño formato de tabla para que sea claro cómo se interpretan los datos
    printf("-------------------------\n");
    printf("|     X      |     Y    |\n");
    //Abrimos el archivo con la función 'fopen'.
    f = fopen(l,"r");
    //h será el valor ascii del símbolo analizado, el cual obtenemos con fgetc.
    while((h = fgetc(f))!=EOF){
	//Utilizamos la función fscanf para asginar los datos en el archivo a alguna variable. V2 es para corregir un bug que existe al solo asginar valores reales a las demás variables, v1 y v2 son los valores de X y Y respectivamente y V1 será de nuevo para corregir el bug.
	//El bug es que detecta el \n que ocupamos para contar las filas como un valor más y entonces entra en conflicto y detecta los datos de manera errónea.
	fscanf(f, "%c%f %f %c", &V2,&v1,&v2, &V1);
        if(c<x){
	    if (h>47 && h<58){
		//Utilizamos la función sprintf para pasar a una cadena el valor de h, el cual es un entero, pero con "%c" lo convertimos a su símbolo ascii, por ejemplo si h=48, entonces con  "%c" le decimos que en realidad es 0, pues el ascii del 0 es 48. Esta cadena la almacenamos en d.
		sprintf(d,"%c",h);
		//Este es el arreglo del bug antes dicho. Pues si no pusiéramos V2 este valor nos lo detectaría como 0, en ves de .0, esto adquiere importancia pues ligaremos este valor para que este valor sea 0.v1 y no v1. Para que quede más claro: Digamos que el valor es 9.81, debido aque  fgetc nos detecta el 6, entonces éste no lo detecta el fscanf, sino que detecta a partir del siguiente caracter, por ello lo siguiente sería .81, sin el %c%f nos detectaría el número como 81, en ves de 0.81, por ello el %c%f nos detecta el carácter '.' y luego el 81. Con el sprintf lo transformamos en la cadena '.81'. Esta cadena la almacenamos en V.
		if (V2=='.'){sprintf(V,".%i",(int)v1);}
		else {sprintf(V,"%f",v2); v2=v1;}
		//Aquí juntamos las cadenas d con V, ya obtenemos una cadena con el valor correcto de X.
		strcat(d,V);
		//Ahora transformamos la cadena en el valor real 
		v1=atof(d);
		//Ahora asignamos cada valor en su correspondiente celda de la matriz.
		arreglo[c][0]=v1;
		arreglo[c][1]=v2;
		//Vamos imprimiendo cada valor de la matriz, para así ver que todo esté correcto.
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
    //Llamamos a la función promedio(matriz real,total de filas, columna), el cual nos dará el promedio de la columna designada en la matriz dada.
    p=promedio(arreglo,x,0);
    printf("Promedio de datos en x: %f \n", p);
    p=promedio(arreglo,x,1);
    printf("Promedio de datos en y: %f \n", p);
    printf("+++++++++++++++++++++++++++++++++++++\n");
    //Llamamos a la función varianza(matriz real, total de filas,columna) que nos dará la varianza de los datos en la columna designada de la matriz dada.
    var=varianza(arreglo,x,0);
    printf("sigma²x = %f\n", var);
    var=varianza(arreglo,x,1);
    printf("sigma²y = %f\n", var);
    var=varianza(arreglo,x,2);
    printf("sigma²xy = %f\n", var);
    printf("+++++++++++++++++++++++++++++++++++++\n");
    //Llamamos a la función desviación(matriz real, total de filas, columna) que nos dará la desviación estándar de la columna designada en la matriz dada.
    des=desviacion(arreglo,x,0);
    printf("Sigma x = %f\n", des);
    des=desviacion(arreglo,x,1);
    printf("Sigma y = %f\n", des);
    des=desviacion(arreglo,x,2);
    printf("Sigma xy = %f\n", des);
    printf("+++++++++++++++++++++++++++++++++++++\n");
    //Llamamos a la función ErEs(matriz real, total de filas, columna) que nos dará el error estándar de la columna designada en la matriz dada.
    err=ErEs(arreglo,x,0);
    printf("Sx= %f\n",err);
    err=ErEs(arreglo,x,1);
    printf("Sy= %f\n",err);
    printf("+++++++++++++++++++++++++++++++++++++\n");
    printf("|||\tMínimos cuadrados caso recta\t|||\n");
    //Llamamos a la función MinCuaM(matriz real, total de filas) que nos dará la pendiente en el ajuste por mínimos cuadrados.
    m=MinCuaM(arreglo,x);
    printf("m= %f\n",m);
    //Llamamos a la función MinCuaB(Matriz real, total de filas) que nos dará la ordenanda al origen en el ajuste por mínimos cuadrados.
    b=MinCuaB(arreglo,x);
    printf("b= %f\n",b);
    //Ahora llamamos EMinCuaM(Matriz real, total de filas) que nos dará el error en la pendiente en el ajuste por mínimos cuadrados.
    Em=EMinCuaM(arreglo,x);
    printf("Error en m= %f\n",Em);
    //Llamamos EMinCuaB(Matriz real, total de filas) que nos dará el error en la ordenada al origen en el ajuste por mínimos cuadrados.
    eb=EMinCuaB(arreglo,x);
    printf("Error en b= %f\n", eb);
    printf("|||\tf(x)=((%f) +- (%f))x + ((%f) +- (%f))\t|||\n",m,Em,b,eb);
    printf("+++++++++++++++++++++++++++++++++++++\n");
    //Llamamos a la función correlación(Matriz real, total de filas) que nos dará la correlación de Pearson entre los valores de la matriz.
    corr=correlacion(arreglo,x);
    printf("P= %f\n",corr);
    //Llamamos a la función chi2(Matriz real, total de filas, tipo de función) que nos dará la chi cuadrada. En el último parámetro se nos pedirá qué tipo de función es: 1 para recta, 2 para parábola.
    X=chi2(arreglo,x,1);
    printf("Caso recta X²= %f\n",X);
    X=chi2(arreglo,x,2);
    printf("Caso parábola X²= %f\n",X);
    //Llamamos a la función chi2Red(Matriz real, total de filas, tipo de función). Aquí, en el último parámetro es solo como control, para saber cuántos parametros tomar, conforme a la función que sea, Si es una recta se pone 1, si es una parábola se pone 2
    Xred=chi2Red(arreglo,x,1);
    printf("Si es una recta, entonces la X²red= %f\n",Xred);
    Xred=chi2Red(arreglo,x,2);
    printf("Si es una parábola, entonces la X²red= %f\n",Xred);
    printf("+++++++++++++++++++++++++++++++++++++\n");
    //Llamamos a la función MinCuaP(matriz real, total de filas), el cual nos dará los valores para la parábola ajustada.
    printf("|||\tMínimos cuadrados caso parábola\t|||\n");
    A=MinCuaP(arreglo, x,1);
    printf("A= %f\n",A);
    B=MinCuaP(arreglo,x,2);
    printf("B= %f\n",B);
    C=MinCuaP(arreglo,x,3);
    printf("C= %f\n",C);
    printf("|||\tf(x)= (%f)x² + (%f)x + (%f)\t|||\n",A,B,C);
    fclose(f);
}
