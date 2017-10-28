#include "stdafx.h"

int pow(int base, int power)
{
	int result = 1;
	for (int i = 1; i <= power; i++)
	result = result*base;
		return result;
}

int main()
{
	int x = 0;
	int a = 0;
	int result1 = 0;
	printf("Enter x:\n");
	scanf_s("%d", &x);
	printf("Enter a:\n");
	scanf_s("%d", &a);
	result1 = pow(x, a);
	printf("Result: %d\n", result1);
	return 0;
}
