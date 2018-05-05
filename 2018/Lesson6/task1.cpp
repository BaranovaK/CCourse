// ConsoleApplication1.cpp : Defines the entry point for the console application.
// ПРОГРАММА ПОИСКА ПЛОЩАДИ ПРЯМОУГОЛЬНИКА


#include "stdafx.h"
class Rectangle { //личные данные
	int _a;
	int _b;
public: //публичные данные
	int get_square();
	void set_a(int);
	void set_b(int);
};
//список объектов
int Rectangle::get_square() { //::-оператор области видимости, эта функция относится к классу Rectangle
	int S = _a * _b;
	return S;
}

void Rectangle::set_a(int a) {
	_a = a;
}
void Rectangle::set_b(int b) {
	_b = b;
}
int main()
{
	Rectangle my_rectangle; //здесь находится функция
	my_rectangle.set_a(2); //.-обращение к свойству структуры,обращение к конкретной функции идет после точки
	my_rectangle.set_b(3);
	printf("S = %d\n", my_rectangle.get_square());
	return 0;
}
