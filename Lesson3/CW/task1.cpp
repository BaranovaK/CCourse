// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{

	int selector = 0;
	float S = 0;
	float radius = 0;
	float side = 0;
	float a = 0;
	float b = 0;
	float c = 0;
	float d = 0;
	float h = 0;

	printf("Area calculation\n");
	printf("\tEnter 1 for circle\n");
	printf("\tEnter 2 for square\n");
	printf("\tEnter 3 for rectangle\n");
	printf("\tEnter 4 for trapeze\n");
	scanf_s("%d", &selector);
	switch (selector)
	{
	case 1:
		printf("Enter radius:\n");
		scanf_s("%f", &radius);
		S = 3.14*radius*radius;
		break;
	case 2:
		printf("Enter side:\n");
		scanf_s("%f", &side);
		S = side*side;
		break;
	case 3:
		printf("Enter a:\n");
		printf("Enter b:\n");
		scanf_s("%f", &a);
		scanf_s("%f", &b);
		S = a*b;
		break;
	case 4:
		printf("Enter c:\n");
		printf("Enter d:\n");
		printf("Enter h:\n");
		scanf_s("%f", &c);
		scanf_s("%f", &d);
		scanf_s("%f", &h);
		S = (a + b)*h / 2;
		break;
	default:
		printf("unexpected symbol!!!\n");
		break;
	}
	printf("Area S=%f\n, S");
	return 0;
}

