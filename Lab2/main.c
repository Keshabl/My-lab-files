#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int a, i, j;
    double x1=0, x2=0;
	printf("Insert size of your massiv:\n");
	scanf("%d", &a);
	double x[a][a];
	printf("Insert meanings of elements of massiv:\n");
	for (i = 0; i<a; i++)
	{
    	for (j = 0; j<a; j++)
		{
    		scanf("%lf", &x[i][j]);
    		if (i==j)
    		{
    			x1=x1+x[i][j];
			}
			if(a==i+j+1)
			{
    			x2=x2+x[i][j];
			}
    	}
	}
	
	printf("Main di: %lf, Dop di: %lf", x1, x2);
}
