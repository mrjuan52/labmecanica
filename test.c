#include "funciones.h"
int main()
	{
	char l[80];
	int t;
	float prom,var,des,err;
	printf("Nombre del archivo a analizar: ");
	scanf("%79s",l);
	printf("Abriendo %s\n",l);
	t=tot(l);
	prom=promedio(l,2);
	var=varianza(l,2);
	des=desviacion(l,2);
	err=ErEs(l,2);
	printf("Total de filas: %d\n",t);
	printf("Promedio: %f\n",prom);
	printf("Varianza: %f\n",var);
	printf("Desviación Estándar: %f\n",des);
	printf("Error estándar: %f\n",err);
	return 0;
	}
