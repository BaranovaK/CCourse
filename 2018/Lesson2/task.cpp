#include "stdafx.h"
#include <stdlib.h>

typedef struct Node { //Структура односвязного списка, который состоит из узлов
	int value;
	struct Node *next;
} Node;

void push(Node **head, int data) { //Создание функции, которая собирает список из значений, которые ей передаются
	Node *tmp = (Node*)malloc(sizeof(Node)); //Выделение памяти
	tmp->value = data;
	tmp->next = (*head);
	(*head) = tmp;
}

int pop(Node **head) { //Создание функции, которая удаляет тот элемент, на который указывает head и возвращает его значение
	Node* prev = NULL;
	int val;
	if (head == NULL) {
		exit(-1);
	}
	prev = (*head);
	val = prev->value;
	(*head) = (*head)->next;
	free(prev);
	return val;
}

Node* getNth(Node* head, int n) { //Последовательный перебор всех элементов списка через указатель next следующего узла
	int counter = 0;
	while (counter < n && head) {
		head = head->next;
		counter++;
	}
	return head;
}

Node* getLast(Node *head) { //Нахождение последнего элемента
	if (head == NULL) { //Перебор всех элементов, пока не станет NULL
		return NULL;
	}
	while (head->next) {
		head = head->next;
	}
	return head;
}

void pushBack(Node *head, int value) { //Добавление нового элемента в конец списка
	Node *last = getLast(head); //Перекидывание указателя next старого элемента на новый
	Node *tmp = (Node*)malloc(sizeof(Node));
	tmp->value = value;
	tmp->next = NULL;
	last->next = tmp;
}

Node* getLastButOne(Node* head) { //Возвращение указателя на предпослдений элемент
	if (head == NULL) {
		exit(-2);
	}
	if (head->next == NULL) {
		return NULL;
	}
	while (head->next->next) {
		head = head->next;
	}
	return head;
}

void popBack(Node **head) { //Возможность удаления последнего элемента
	Node *lastbn = NULL;
	//Получили NULL
	if (!head) {
		exit(-1);
	}
	//Список пуст
	if (!(*head)) {
		exit(-1);
	}
	lastbn = getLastButOne(*head);
	if (lastbn == NULL) {
		free(*head);
		*head = NULL;
	}
	else {
		free(lastbn->next);
		lastbn->next = NULL;
	}
}

void insert(Node *head, unsigned n, int val) { //Создание функции, вставляющей новое значение на n-е место
	unsigned i = 0;
	Node *tmp = NULL;
	//Находим нужный элемент, если вышли за пределы списка, то выходим из цикла
	//Ошибок не будет, будет происходить вставка в конец
	while (i < n && head->next) {
		head = head->next;
		i++;
	}
	tmp = (Node*)malloc(sizeof(Node));
	tmp->value = val;
	if (head->next) //Если элемент не является последним, то происходит работы со следующим узлом
		{
    tmp->next = head->next; // Если элемент конечен, то переходим на NULL
	}
	else {
		tmp->next = NULL;
	}
	head->next = tmp;
}

int deleteNth(Node **head, int n) { //Функция удаления элемента
	if (n == 0) {
		return pop(head);
	}
	else {
		Node *prev = getNth(*head, n - 1);//Указание на элемент, стоящий до удаляемого
		Node *elm = prev->next; //Следующий элемент за удаляемым
		int val = elm->value;

		prev->next = elm->next;
		free(elm);
		return val;
	}
}

void deleteList(Node **head) { //Удаление списка
	Node* prev = NULL;
	while ((*head)->next) {
		prev = (*head);
		(*head) = (*head)->next;
		free(prev);
	}
	free(*head);
}
int ListSum(Node *head) //Реализация функции поиска суммы значений списка
{
	int sum = 0; //Инициализация

	while (head) {
		sum += head->value; //Перемещение по списку, указатель head перекидываем на новый узел
		head = head->next;
	}
	return sum; 
}
void printList(Node *head) //Реализация функции вывода в терминал всех значений списка
{
	while (head) {
		printf("%d\n", head->value); //Вывод функции вывода в терминал всех значений списка
		head = head->next; //Перемещение по списку, указатель head перекидываем на новый узел
	}
}

typedef struct SearchResult //Новое имя для уже существующего типа
{
	int min; //Реализация функции поиска максимального и минимального значений в списке
	int max;
} SearchResult;
SearchResult Min_Max(Node *head)
{
	SearchResult result;
	int min = 1000;
	int max = 0;
	while (head->next)
	{
		if (head->value > max) //Перемещение по списку, указатель head перекидываем на новый узел
		{
			max = head->value;
		}
		if (head->value < min)
		{
			min = head->value;
		}
		head = head->next;
	}
	result.max = max;
	result.min = min;

	return result; 
}

int main()
{
	Node *head = NULL;

	push(&head, 1);
	push(&head, 2);
	push(&head, 6);

	printList(head);
	
	
	printf("Sum: %d\n", ListSum(head)); //Вывод суммы значений списка

	SearchResult result = Min_Max(head); //Вывод результатов на максимальное и минимальное значения в списке
	printf("Max: %d\n", result.max);
	printf("Min: %d\n", result.min);

	return 0;
}
