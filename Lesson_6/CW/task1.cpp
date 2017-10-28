//пример работы с указателями
int main()
{
int age = 15;
int *ptr_age = NULL;
ptr_age = &age;
printf("%d\n", age);
printf("%d\n", ptr_age);
return 0;
}
