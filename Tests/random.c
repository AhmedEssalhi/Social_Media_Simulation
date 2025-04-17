#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
	unsigned int n;

	srand(time(0));
	n = rand() + RAND_MAX / 2;
	n %= 1000;

	printf("random number: %u\n", abs(n));

	return 0;
}

