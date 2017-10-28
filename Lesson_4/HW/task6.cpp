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

	int *a = 0;
	int max = 0;

	for (int i = 0; i < N; i++)
		if (ptr_v[i] > max)
		{
			max = ptr_v[i]; 
			a = &ptr_v[i];
		}
			printf("Max: %d\n", max);
			printf("Max adr: %d\n", a);
	
		return 0;
}
