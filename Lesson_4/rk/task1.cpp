Реализовать программу "Электронный магазин"  ДОДЕЛАТЬ

// ConsoleApplication2.cpp : Defines the entry point for the console application.
//


#include"stdafx.h"
#define SKLAD_CAP 6

struct product 
{
	int id;
	int category;
	char name[30];
	float cost;
};
void print_product_info(struct product product_info)
{
	printf("ID: %d\n", product_info.id);
	printf("Category: %d\n", product_info.category);
	printf("Name: %s\n", product_info.name);
	printf("Cost: %f\n", product_info.cost);
	
}
int main()
{
	FILE *file;
	errno_t err = fopen_s(&file, "C:\\Users\\uc2\\Desktop\\product.txt", "r");
	
	// Это сохранение в структуру с консоли
	struct product product_info;
	scanf_s("%d", &product_info.id);
	scanf_s("%d", &product_info.category);
	scanf_s("%30s",&product_info.name, 30);
	scanf_s("%f", &product_info.cost);
	print_product_info(product_info);


	struct product sklad[SKLAD_CAP];
	// В цикле считываем данные из файла products в массив структур sklad
	int sklad;
	while (fscanf_s(file, "%d %d %s %f", &product_info.id, &product_info.category, &product_info.name, &product_info.cost)!= EOF)
	{
		printf("Product:  id=%d; category=%d; name=%s; cost=%f", sklad.product[i].id);
	}

	// Выбор категории
	int selected_cat = 0;
	printf("Enter category: ");
	scanf_s("%d", &selected_cat);
	for (int i = 0; i < SKLAD_CAP; i++)
	{
		if (sklad[i].category == selected_cat)
		{
			printf("%d\n", s);
		}
	}

	// Сортировка массива sklad


	// нужна функция сортировки массива по полю cost 
	int n, i, j;
	int a[6];
	scanf_s("%f", &n);
	for (i = 0; i < n; i++)
	{
		scanf_s("%f", &a[i]);
	}
	for (i = 0; i < n - 1; i++) 
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;

			}
			return 0;
		}



