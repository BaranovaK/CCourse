РЕАЛИЗАЦИЯ ПРОГРАММЫ "ЭЛЕКТРОННЫЙ МАГАЗИН"
// ConsoleApplication.cpp : Defines the entry point for the console application. 
 
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
 
printf("\n"); 
printf("ID: %d\n", product_info.id); 
printf("Category: %d\n", product_info.category); 
printf("Name: %s\n", product_info.name); 
printf("Cost: %.2f\n", product_info.cost); 
printf("\n"); 
 
} 
 
void sort_by_cat(struct product tosort[], int cat) 
{ 
printf("\nSorted by category [%d]:\n", cat); 
for (int i = 0; i <= SKLAD_CAP; i++) 
{ 
if (tosort[i].category == cat) 
{ 
print_product_info(tosort[i]); 
} 
} 
} 
 
 
void sort_by_price(struct product a[]) 
{ 
struct product buf; 
struct product k; 
int position = 0; 
 
 
for (int i = 0; i < (SKLAD_CAP - 1); i++) 
{ 
 
buf = a[i]; 
 
for (int j = i; j < SKLAD_CAP; j++) 
{ 
if (buf.cost > a[j].cost) 
{ 
buf = a[j]; 
position = j; 
} 
 
} 
 
k = a[i]; 
a[i] = buf; 
a[position] = k; 
 
} 
 
 
printf("\nSorted by price:\n"); 
 
for(int i = 0; i < (SKLAD_CAP); i++) 
{ 
print_product_info(a[i]); 
} 
} 
 
 
int main() 
{ 
 
struct product thing[SKLAD_CAP]; 
 
FILE *file; 
errno_t err = fopen_s(&file, "D:\\product.txt", "r"); 
if (err) 
{ 
printf_s("The file was not opened\n"); 
 
} 
else 
{ 
 
printf("\nThe products in warehouse: \n"); 
int a = 0; 
while ((fscanf_s(file, "%d %d %30s %f", &thing[a].id, &thing[a].category, thing[a].name, 30, &thing[a].cost) != EOF) || (a <= 5)) 
{ 
print_product_info(thing[a]); 
a++; 
} 
 
} 
 
int cat = 0; 
printf("Select the category for sorting: "); 
scanf_s("%d", &cat); 
if (cat <= 0) 
printf("Wrong category!"); 
sort_by_cat(thing, cat); 
sort_by_price(thing); 
 
return 0; 
}
