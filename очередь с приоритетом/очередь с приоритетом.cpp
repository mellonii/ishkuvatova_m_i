﻿// очередь с приоритетом.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

typedef struct {
    int num;
}NUM;

typedef struct {
    NUM n; //это наши данные
    struct QUEUE* prev, * next;

}QUEUE;

class List
{
    QUEUE* head, * tail; // Указатели на первый и последний элементы списка.

public:
    List() :head(NULL), tail(NULL) {}; // Создание пустого списка (конструктор).
    ~List(); // Деструктор.	

    void push(QUEUE* queue, NUM num) {
        //queue это элемент после которого будем добавлять новый элемент в список
        QUEUE* ptr = new QUEUE; //создаем новый элемент
        ptr->n = num; //присваиваем значение
        ptr->prev = queue;
        //указатель на предыдущий элемент, после которого добавляем
        ptr->next = (queue == NULL) ? NULL : queue->next;
        //указатель на следующий, если такой есть

        if (queue != NULL) {
            // если мы добавляем не первый элемент
            queue->next = ptr;
            //присваиваем предыдущему элементу указатель на следующий (наш)
        }

        if (queue->prev == NULL) head = ptr;
        if (queue->next == NULL) tail = ptr; // если добавили после последнего элемента
    }

    void pop() {};
};

int main(){

    std::cout << "Hello World!\n";
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
