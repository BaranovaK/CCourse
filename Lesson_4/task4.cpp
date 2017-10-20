#include "stdafx.h"
#include <math.h>


int main()
{
	int y = 0;
	int n = 0;
	int factorial = 1;
	printf("Enter n:");
	scanf_s("%d", &n);
	y = (n - 1)*factorial*n;
	printf("y: %d", y);
	return 0;
}
