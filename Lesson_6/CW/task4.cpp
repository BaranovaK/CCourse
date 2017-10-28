//пример программы с динамическим выделением 25 байт памяти
#include "stdafx.h"
#include <stdlib.h>
int main()
{
char *р;
р = (char *)malloc(25);
free(p);
return 0;
}
