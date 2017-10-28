// пример программы создания массива размерности,укаазываемой пользователем
int main()
{
int *ptr_v = NULL;
int vector_size = 0;
scanf_s("%d", &vector_size); //ввод размера массива
ptr_v = (int *)malloc(vector_size * sizeof(int)); //выделение памяти под массив
for (int i = 0; i < vector_size; i++)
ptr_v[i] = i; //заполнение массива
for (int i = 0; i < vector_size; i++)
printf("%d\n", *(ptr_v + i)); Вывод элементов массива,можно заменить на ptr_v[i]
free(ptr_v) //освобождение памяти
return 0;
}
