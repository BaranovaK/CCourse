//Реализовать поиск тех точек, которые находятся на расстоянии R от точки, вводимой с клавиатуры.
Величина R, как и координаты точки, вводится с клавиатуры.
#include "stdafx.h"
#include <math.h>

int main()
{
	float X0, Y0, R, X, Y = 0;
	printf("X0: ");
	scanf_s("%f", &X0);
	printf("Y0: ");
	scanf_s("%f", &Y0);
	printf("R: ");
	scanf_s("%f", &R);

	if (R > 0)
	{
		X = X0 - R;
		Y = Y0;
		printf("X: %f\n", X);
		printf("Y: %f\n", Y);
		while (X < X0 + R)
		{
			X = X + 0.1;
			printf("X: %f\n", X);
			Y = sqrtf(R*R - (X - X0)*(X - X0)) + Y0;
			printf("Y: %f\n", Y);
			printf("X: %f\n", X);
			Y = - sqrtf(R*R - (X - X0)*(X - X0)) + Y0;
			printf("Y: %f\n", Y);
		}
		X = X0 + R;
		Y = Y0;
		printf("X: %f\n", X);
		printf("Y: %f\n", Y);

	}
	else
		printf("Error!\n");

	return 0;
}
