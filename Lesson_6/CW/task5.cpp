// пример программы с динамическим выделением памяти для 40 целых чисел
#include "stdafx.h"
#include <stdlib.h>
int main()
{
int *р;
р = (int *)malloc(40 * sizeof(int));
free(p);
return 0;
}
