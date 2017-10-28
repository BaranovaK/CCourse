// работа с оператором присваивания
int main()
{
int ann_book = 12;
int *ptr_ann = NULL;
int *ptr_mike = NULL;
ptr_ann = &ann_book;
ptr_mike = ptr_ann;
printf("%d\n", ann_book);
printf("%d\n", *ptr_ann);
printf("%d\n", *ptr_mike);
return 0;
}
