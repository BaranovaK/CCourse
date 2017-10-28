//Программа поиска суммы и произведения в массиве с использованием динамического выделения памяти, 
задания размера массива пользователем, а так же введения пользователем массива
#include "stdafx.h"
#include <stdlib.h>



int main()

{
	
	int  *ptr_v;
	
	int i = 0;
	int N = 0;
	scanf_s("%d", &N);
	ptr_v = (int *)malloc(N * sizeof(int));

	for (int i = 0; i < N; i++)
		scanf_s("%d", (ptr_v + i));

	for (int i = 0; i < N; i++)
		printf("%d\n", *(ptr_v + i));

	int a = 0;
	for (int i = 0; i < N; i++)
	a = a + ptr_v[i];

		printf("%d\n", a);
		
		int b = 1;
		for (int i = 0; i < N; i++)
			b= b * ptr_v[i];

		printf("%d\n", b);
	
		return 0;
}

