#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int a, b, c ,d;
    double x1, x2;
    printf("Insert your changebel meanings:\n");
    scanf("%d %d %d", &a, &b, &c);
    d=b*b-4*a*c;
    printf("D=%d \n", d);
    if (d<0)
    {
    	printf("Roots is not exist");
    	return 0;
	}
	if (d==0)
	{
		x1=-(b/(2*a));
		printf("x1=%lf",x1);
		return 0;
	}
    x1 = (-b + sqrt(d)) / (2*a);
    x2 = (-b - sqrt(d)) / (2*a);
    printf("x1=%lf, x2=%lf",x1,x2);
    return 0;
}
