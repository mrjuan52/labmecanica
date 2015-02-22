#include <stdio.h>
#include "entradatexto.h"
int tot(),x,c,h;
float v1,v2;
char na;
FILE *f;
int main(){
    x=tot();
    c=0;
    float arreglo[x][2];
    f = fopen("datos.txt","r");
    while((h = fgetc(f))!=EOF){
        fscanf(f, "%f %f ", &v1, &v2);
        if(c<x && h!=92){
            arreglo[c][0] = v1;
            arreglo[c][1] = v2;
            printf("%f %f\n", arreglo[c][0], arreglo[c][1]);
            c++;
        }
    }
    
    fclose(f);
}
