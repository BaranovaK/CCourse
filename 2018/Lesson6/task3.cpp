// ConsoleApplication1.cpp : Defines the entry point for the console application.
//ПРОГРАММА ПОИСКА ДЛИНЫ ОТРЕЗКА


#include "stdafx.h"
#include "math.h"

class Segment { //личные данные
	int _x1;
	int _x2;
	int _y1;
	int _y2;
	
public: //публичные данные
	int get_lengt();
	void set_x1(int);
	void set_x2(int);
	void set_y1(int);
	void set_y2(int);
	
}; //список объектов

int Segment::get_lengt() { //::-оператор области видимости, эта функция относится к классу Rectangle
	int L = sqrtf((_x2 - _x1)*(_x2 - _x1) + (_y2 - _y1)*(_y2 - _y1));
	return L;
}

void Segment::set_x1(int x1) {
	_x1 = x1;
}
void Segment::set_x2(int x2) {
	_x2 = x2;
}
void Segment::set_y1(int y1) {
	_y1 = y1;
}
void Segment::set_y2(int y2) {
	_y2 = y2;
}

int main()
{
	Segment my_segment; //создание экземпляра класса segment
	my_segment.set_x1(1); 
	my_segment.set_x2(2);
	my_segment.set_y1(1);
	my_segment.set_y2(2); //.-обращение к свойству структуры,обращение к конкретной функции идет после точки

	printf("L = %d\n", my_segment.get_lengt());
	return 0;
}
