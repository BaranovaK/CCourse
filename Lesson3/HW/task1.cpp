// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <math.h>

int main()
{
	float A = 0;
	float B = 0;
	float C = 0;
	float Mx = 0;
	float My = 0;
	float result = 0;
	printf("Enter A\n");
	scanf_s("%f", &A);
	printf("Enter B\n");
	scanf_s("%f", &B);
	printf("Enter C\n");
	scanf_s("%f", &C);
	printf("Enter Mx\n");
	scanf_s("%f", &Mx);
	printf("Enter My\n");
	scanf_s("%f", &My);
	if (A, B != 0)
	{
		result = fabs(A*Mx + B*My + C) / sqrtf(powf(A,2) + powf(B, 2));
		printf("fabs (A*Mx + B*My + C) / sqrtf(A ^ 2 + B ^ 2)=%f\n", result);

	}
	else
		printf("Error!\n");
	return 0;


}
