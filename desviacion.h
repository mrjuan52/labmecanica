#include "varianza.h"
#include <math.h>
float desviacion()
	{
	float V,D;
	V=varianza();
	D=sqrt(V);
	return (D);
	}
