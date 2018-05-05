#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define BUF_SIZE                1024

#define OPERATOR_DEFAULT        '+'

#define INPUT_inputFile_NAME    "input.txt"
#define OUTPUT_inputFile_NAME   "output.txt"


  //Элемент однонаправленного списка.
  
  Node 1: 
       value = 5
       operator = '+'
       next = Node 2
       
  Node 2: 
       value = 2
       operator = '*'
       next = Node 3
       

  
Node 6: 
       value = 7
       operator = '+' (значение по умолчанию)
      next = NULL
       
  //Тогда сам список будет содержать 6 + 1 (начальный) элементов
typedef struct Node {
    double value;               // операнд - число
    char operator;              // операция следующая за операндом
    struct Node * next;         // следующий элемент списка или NULL
} Node;
//Создает указатель на компонент и инициализирует его начальными значениями
 
Node * NodeFactory()
{
    struct Node * node = (Node*)malloc(sizeof(Node));

    node->value = .0;
    node->next = NULL;
    node->operator = OPERATOR_DEFAULT;

    return node;
}
 //Вставляет узел Needle в конец списка start
 
void pushBack(struct Node * start, struct Node * needle)
{
    struct Node * tmp = start;

    while (tmp->next != NULL) {
        tmp = tmp->next;
    }

    tmp->next = needle;
}
 //Печатает список на экран
void print(struct Node * start)
{
    struct Node * tmp = start->next;

    while (tmp != NULL) {

        printf("%.2f ", tmp->value);

        if (tmp->next != NULL) {
            printf("%.2c ", tmp->operator);
        }

        tmp = tmp->next;
    }

    printf("\n");
}
 //Проверяет: высший ли у оператора приоритет.
 
 symbol  // Знак оператора
 
int isHightPriority(const char symbol)
{
    if (symbol == '*'
    ||  symbol == '/') {
        return  1;
    }

    return 0;
}
  //Завершает выполнение текущего приложения (code-код выхода,msg-сообщение, которое будет напечатано перед завершением

void closeApp(const int code, char * msg)
{
    printf(msg);
    system("pause");
    exit(code);
}
 //Проверяем входящий символ: является ли он разделителем
 
int isDelimiter(const char symbol)
{
    if (symbol == ' '
    ||  symbol == '\t'
    ||  symbol == '\n') {
        return 1;
    }

    return 0;
}
 //Проверяет входящий символ: является ли он оператором.
int isOperator(const char symbol)
{
    if (symbol == '+'
    ||  symbol == '-'
    ||  symbol == '*'
    ||  symbol == '/') {
        return 1;
    }

    return 0;
}


  //Начиная с позиции i перебирает строку str до тех пор,пока в строке не найдется символ, которыЙ не является разделителем 
  
 return //Позицию первого символа не являющемся разделителем
 
int ignoreDelimiters(char * str, int i)
{
    for (++i; isDelimiter(str[i]); ++i) {
        // не обращаем внимания на все разделители
    }
    return i;
}

//Деление числа А на В.
double division(const double A, const double B)
{
    return A / B;
}
 //Произведение числа А и В
double multiplication(const double A, const double B)
{
    return A * B;
}
//Сумма числа А и В.
 
double sum(const double A, const double B)
{
    return A + B;
}
 //Разность чисел А и В.
double difference(const double A, const double B)
{
    return A - B;
}
 //Вычисляет выражение операндов А и В в зависимости от оператора
double calculateOperands(const char operator, const double A, const double B)
{
    if (operator == '/') {
        return division(A, B);
    }

    if (operator == '*') {
        return multiplication(A, B);
    }

    if (operator == '+') {
        return sum(A, B);
    }

    if (operator == '-') {
        return difference(A, B);
    }

    return .0;
}


 //Функция считает элемент операцию над операндами элемента tmp и tmp->next
int calculateAdjacentElements(struct Node * tmp)
{
    // если происходит деление на 0, то вернуть false
    if (tmp->operator == '/' && tmp->next->value == 0) {
        return 0;
    }
    // в качестве операнда А берем элемент tmp
    // в качетсве операнда B берем элемент tmp->next
    // операция определяется первым элементом
    tmp->value = calculateOperands(tmp->operator, tmp->value, tmp->next->value);
    tmp->operator = tmp->next->operator;

    // запоминаем элемент, который уже посчитали, чтобы очистить память
    struct Node * usedNode = tmp->next;

    // так как операнд B уже учтён, для следующих вычислений,берем  следующий за ним операнд С
    tmp->next = tmp->next->next;

    // операнд В уже не нужен, удаляем
    free(usedNode);
    return 1;
}

//Функция последовательно считает операции низжего приоритета (сумма и разность) и преобразует группы таких элементов в единое число
 
void calcLowPriorityNodes(struct Node * start)
{
    struct Node * tmp = start;

    while (tmp->next != NULL) {
        calculateAdjacentElements(tmp);
    }
}

//Функция последовательно считает операции высшего приоритета (умножение и деление) и преобразует группы таких элементов в единое число
int calcHightPriorityNodes(struct Node * start)
{
    struct Node * tmp = start;

    while (tmp != NULL) {

        while (isHightPriority(tmp->operator)) {

            // если в результате вычисления произошла ошибка (например деление на 0),то возвращаем false в функцию вызыва
            if (! calculateAdjacentElements(tmp)) {
                return 0;
            }
        }

        tmp = tmp->next;
    }
    return 1;
}


  //Обрабатывает считываемую строку из файла попутно наполняя список list
void handleInputString(char * str, Node * list)
{
    unsigned int i = 0;
    unsigned int start = 0;

    // временное хранение чисел
    char buf[BUF_SIZE];

    //  просматриваем строку по каждому символу
    for (i = 0; str[i] != '\0'; i++) {

        struct Node * tmp = NodeFactory();

        // собираем число из цифр: сначала запоминаем позицию первой цифры числа,далее идем по строке и ищем позициюю последней цифры числа
        for (start = i; str[i] != '\0' && isdigit(str[i]); i++);

        // число начинается с позиции start и заканчивается позицией i,
        // копируем строковое число длиной i - start символов в буфер
        strncpy_s(buf, i - start + 1, str + start, i - start);

        // преобразуем число из строки в тип int и записываем в структуру
        tmp->value = atoi(buf);

        // если после числа следует конец строки,то  завершаем цикл и добавляем операнд в список
        if (str[i] == '\0' || str[i] == '\n') {
            pushBack(list, tmp);
            break;
        }

        // после числа должен стоять пробел, для последующей работы оператора смещаем позицию i на одну позицию пробела
        i++;

        // если после числа и пробела стоит не оператор,то завершаем работу программы
        if (! isOperator(str[i])) {
            closeApp(-1, "Syntax error!\n");
        }

        tmp->operator = str[i];

        // после оператора также должен быть пробел, следовательно сдвигаем i на одну его позицию
        i++;

        // добавляем операнд в конец списка
        pushBack(list, tmp);
    }
}

int main()
{
    // объявляем указатель на созданный поток данных для чтения из файла
    FILE * inputFile, * outputFile;

    // переменная, в которую поочередно будут помещаться считываемые строки
    char buf[BUF_SIZE];

    // открываем файл с режимом доступа «только чтение ,r»
    if (fopen_s(&inputFile, INPUT_inputFile_NAME, "r") != 0) {
        // если не получилось открыть файл, то закрываем приложение с текстом сообщения
        closeApp(-1, "Can't open inputFile input inputFile!");
    }
    // открываем файл с режимом доступа «только запись, w»
    if (fopen_s(&outputFile, OUTPUT_inputFile_NAME, "w") != 0) {
        // если не получилось открыть файл, то закрываем приложение с текстом сообщения
        closeApp(-1, "Can't open inputFile input inputFile!");
    }

    // построчно читаем строки из файла в буфер
    while (fgets(buf, BUF_SIZE, inputFile)) {

        struct Node * start = NodeFactory();                // создаем первый элемент списка

        handleInputString(buf, start);                      // отправляем строку на обработку

        if (calcHightPriorityNodes(start)) {                // считаем операции высшего приоритета
                                                            // не было деления на 0
            calcLowPriorityNodes(start);                    // считаем операции низкого приоритета
            fprintf(outputFile, "%.2f\n", start->value);    // пишем результат в файл

        } else {

            fprintf(outputFile, "NaN\n");                   // пишем NaN в файл          
        }

        free(start);                                        // освобождение памяти
    }   

    fclose(inputFile);
    fclose(outputFile);

    // закрываем приложение
    system("pause");
    return 0;
}
