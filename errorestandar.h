#include "desviacion.h"
float ErEs()
	{
	float D, S;
	int n;
	n=tot();
	D=desviacion();
	S=(D)/sqrt(n);
	return (S);
	}
