#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funccool.h"


int main(int argc, char *argv[]) 
{
	
	double x, y, z;
	scanf("%lf %lf %lf", &x, &y, &z);
	if ((x+y<=z)||(x+z<=y)||(y+z<=x))
	{
		printf("Takogo ne bivaet, ti chego");
	}
	else 
	{
		double P = Per (x,y,z);
		double S = Plo (x,y,z);
		printf("Per - %lf, Plo - %lf", P, S);
	}
}
