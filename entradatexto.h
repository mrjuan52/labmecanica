#include <stdio.h>
#include <stdlib.h>
FILE *f;
int total;
char ch;
int tot(void){
    total=0;
    f = fopen("datos.txt","r");
    if (f == NULL){
        printf("\nError de apertura. \n\n");
        fclose(f);
        exit(0);
    }else{
        while((ch = fgetc(f))!= EOF){
            if(ch=='\n'){
              total++;
            }
        }
    }
    fclose(f);
    return(total);
}