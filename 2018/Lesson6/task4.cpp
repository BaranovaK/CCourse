// ConsoleApplication1.cpp : Defines the entry point for the console application.
// РЕАЛИЗОВАТЬ ПРОГРАММУ СЛОЖЕНИЯ ДВУХ ВЕКТОРОВ
!!!ДОДЕЛАТЬ!!!


#include "stdafx.h"
#include "math.h"

class Vector { //личные данные
	int _x1;
	int _x2;
	int _y1;
	int _y2;


public: //публичные данные
	int add_vector (),
	void set_x1(int);
	void set_x2(int);
	void set_y1(int);
	void set_y2(int);
	
	
}; //список объектов

int Vector::add_vector(V1) { //::-оператор области видимости, эта функция относится к классу Vector
	int V1 = sqrtf((_x2 - _x1)*(_x2 - _x1) + (_y2 - _y1)*(_y2 - _y1));
	return V1;

int Vector::add_vector(V2)
	int V2 = sqrtf((_x4 - _x3)*(_x4 - _x3) + (_y4 - _y3)*(_y4 - _y3));
    return V2;

int Vector::add_vector(V)
	int V = sqrtf
	return V;
}

void Vector::set_x1(int x1) {
	_x1 = x1;
}
void Vector::set_x2(int x2) {
	_x2 = x2;
}

void Vector::set_y1(int y1) {
	_y1 = y1;
}
void Vector::set_y2(int y2) {
	_y2 = y2;
}


int main()
{
	Vector my_Vector; //создание экземпляра класса segment
	my_vector.set_x1(1);
	my_vector.set_x2(6);
	
	my_vector.set_y1(3);
	my_vector.set_y2(3);
	 //.-обращение к свойству структуры,обращение к конкретной функции идет после точки

	printf("V = %d\n", my_vector.get_lengt());
	return 0;
}
