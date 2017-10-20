#include "stdafx.h"
#include <math.h>


int main()
{
	int x = 0;
	int y = 0;
	int a = 0;
	printf("Enter x:\n");
	scanf_s("%d\n", &x);
	printf("Enter a:\n");
	scanf_s("%d\n", &a);
	y = pow(x, a);
	printf("y: %d\n", y);
	return 0;
}
