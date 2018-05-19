//Доделать программу излеции и посмотреть в какой последовательности будут выведены сообщения
// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


class queue {
	int _q[100];
	int _sloc, _rloc;
public:        //публичные данные
	queue(); // конструктор
	~queue(); // деструктор
	void gput(int i);
	int qget();
};
queue::queue()
{
	_sloc = _rloc = 0;
	printf("Queue initialized. \n");
}
queue ::~queue()
{
	printf("Queue destroyed.\n");
}

int main() {
	queue MyQueue1;
	queue MyQueue2;
	return 0;
}
