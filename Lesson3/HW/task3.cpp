int main()
{
	float a = 0;
	float b = 0;
	float c = 0;
	float x = 0;
	float x1 = 0;
	float x2 = 0;

	float result = 0;
	printf("Enter a\n");
	scanf_s("%f", &a);
	printf("Enter b\n");
	scanf_s("%f", &b);
	printf("Enter c\n");
	scanf_s("%f", &c);
	/*
	printf("Enter x1\n");
	scanf_s("%f", &x1);
	printf("Enter x2\n");
	scanf_s("%f", &x2);
	*/



	if ((b*b - 4 * a*c) >= 0)
	{
		x1 = (-b + sqrt(pow(b, 2) - 4 * a*c)) / (2 * a);
		x2 = (-b - sqrt(pow(b, 2) - 4 * a*c)) / (2 * a);
		printf("x1 = %f\n", x1);
		printf("x2 = %f\n", x2);


		// printf, x1 = (-b + sqrt(pow(b, 2) - 4 * a*c)) / (2 * a);
		// x2 = (-b - sqrt(pow(b, 2) - 4 * a*c)) / (2 * a); x2);

	}
	else
		printf("Error!\n");
	return 0;

}

