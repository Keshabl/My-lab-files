#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, char *argv[])
{
	int i;
	char s[81];
	if (fgets(s,81,stdin))
		for(i=0;s[i];i++)
		{
			if(s[i]=='a'||s[i]=='b')
				s[i]-=32;
			printf("%c", s[i]);
		}
	return 0;
}
