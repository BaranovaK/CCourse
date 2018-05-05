// ConsoleApplication1.cpp : Defines the entry point for the console application.
//НАХОЖДЕНИЕ ПЛОЩАДИ КРУГА


#include "stdafx.h"
class Сircle { //личные данные
	int _r;
	
public: //публичные данные
	int get_square();
	void set_r(int);
	
}; //список объектов

int Сircle::get_square() { //::-оператор области видимости, эта функция относится к классу Rectangle
	int S = 3.14 *_r*_r;
	return S;
}

void Сircle::set_r(int r) { //присваивание значения (2)
	_r = r;
}

int main()
{
	Сircle my_circle; //создание экземпляра класса circle
	my_circle.set_r(2); //.-обращение к свойству структуры,обращение к конкретной функции идет после точки
	printf("S = %d\n", my_circle.get_square());
	return 0;
}
