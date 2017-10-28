int main()
{
int age = 15;
int steve_age = 0;
int *ptr_age = NULL;
ptr_age = &age;
steve_age = *ptr_age;
printf("%d\n", age);
printf("%d\n", ptr_age);
printf("%d\n", steve_age);
return 0;
}
