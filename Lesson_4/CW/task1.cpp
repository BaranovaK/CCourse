int main()
{
	int selector = 1;
	int M = 0;
	int N = 0;

	int current_month = 0; // месяц, относительно которого считаем дату рождения
	int current_year = 0; // год, относительно которого считаем дату рождения

	int bd_month = 0; // месяц рождения
	int bd_year = 0; // год рождения

	printf("Enter current month:\n");
	scanf_s("%d", &current_month);
	printf("Enter current year:\n");
	scanf_s("%d", &current_year);
	
	printf("Enter bd month:\n");
	scanf_s("%d", &bd_month);
	printf("Enter bd year:\n");
	scanf_s("%d", &bd_year);

	printf("Enter print type:\n");
	scanf_s("%d", &selector);

	// Поиск M
	N = current_month - bd_month;
	// Поиск N
	M = current_year - bd_year;

	if (N < 0)
	{
		M = M - 1; // число лет уменьшаем на 1
		N = 12 + N; // Месяца = 12 + N
	}


	switch (selector)
	{
	case 0:
		printf("%d - month\n", 12 * M + N);
		break;	
	case 1:
		printf("%d - years, %d - month\n", M, N);		
		break;
	default:
		break;
	}
	
	return 0;

}

