#include "funcionesT.h"
int main()
	{
	char l[80];
	int t;
	float prom,var,des,err;
	printf("Nombre del archivo a analizar: ");
	scanf("%79s",l);
	printf("\n**** ABRIENDO %s ****\n",l);
	t=tot(l);
	printf("\nFILAS TOTALES: %d\n",t);
	prom=promedio(l,2);
	printf("\nPROMEDIO: %f\n\n",prom);
	var=varianza(l,2,'v');
	printf("VARIANZA: %f\n\n",var);
	des=desviacion(l,2,'d');
	printf("DESVIACIÓN ESTÁNDAR: %f\n\n",des);
	err=ErEs(l,2,'e');
	printf("ERROR ESTÁNDAR: %f\n",err);
	return 0;
	}
