#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double Per (double x, double y, double z)
{
	return(x+y+z);
}
double Plo (double x, double y, double z)
{
	double p = ((Per (x,y,z))/2);
	return(sqrt(p*(p-x)*(p-y)*(p-z)));
}

