#include <stdlib.h>
#include <iostream>
#include <exception>


class MyTwoSideCiclicList {
private:
	MyTwoSideCiclicList* nextPtr; 
	MyTwoSideCiclicList* previousPtr;
	int value;

public:
	MyTwoSideCiclicList(int _value, MyTwoSideCiclicList* _nextPtr, MyTwoSideCiclicList* _previousPtr) {
		value = _value;
		nextPtr = _nextPtr;
		previousPtr = _previousPtr;
	}
	void Push(int _value) {
		if (previousPtr == NULL) {
			if (nextPtr != NULL)
				throw std::exception("Список незамкнутый");
			else {
				previousPtr = new MyTwoSideCiclicList(_value, this, this);
				nextPtr = previousPtr;
			}
		}
		else {
			MyTwoSideCiclicList* temp = previousPtr;
			previousPtr = new MyTwoSideCiclicList(_value, this, temp);
			temp->nextPtr = temp;
		}
	}

	MyTwoSideCiclicList* Pop(int& outValue) {
		if (previousPtr == NULL) {
			if (nextPtr != NULL)
				throw std::exception("Список незамкнутый");
			else {
				outValue = this->value;
				delete this;
				return NULL;
			}
		} else {
			MyTwoSideCiclicList* temp = previousPtr;
			outValue = temp->value;
			temp->previousPtr->nextPtr = temp->nextPtr;
			temp->nextPtr->previousPtr = temp->previousPtr;
			temp->previousPtr = NULL;
			temp->nextPtr = NULL;
			delete temp;
			return this;
		}
	}

	void Print() {
		if (nextPtr == NULL) {
			std::cout << value << std::endl;
			return;
		}
		MyTwoSideCiclicList* ptr = this;
		do {
			std::cout << ptr->value << "\t";
			ptr = ptr->nextPtr;
		} while (ptr != this);
		std::cout << std::endl;
	}

	MyTwoSideCiclicList* Clear() {
		delete this;
		return NULL;
	}

	~MyTwoSideCiclicList() {
		if (nextPtr != NULL)
			delete nextPtr;
	}
};

class MyQueue {
private:
	MyTwoSideCiclicList* head;
public:
	MyQueue() {
		head = NULL;
	}
	void Push(int value) {
		if (IsEmpty())
			head = new MyTwoSideCiclicList(value, NULL, NULL);
		head->Push(value);
	}
	int Pop() {
		if (IsEmpty())
			throw std::exception("Пустая очередь");
		int value;
		head = head->Pop(value);
		return value;
	}
	void Clear() {
		head = head->Clear();
	}
	void Print() {
		if (!IsEmpty())
			head->Print();
		else
			std::cout << "Пустая очередь" << std::endl;
	}
	bool IsEmpty() {
		return head == NULL;
	}
};


int myRand() {
	return rand() % 100;
}

int main() {
	setlocale(LC_ALL, "ru");
	srand(time(0));
	
	MyQueue queue;
	std::cout << "Добавление элементов в стек" << std::endl;
	for (size_t i = 0; i < 5; i++) {
		queue.Push(myRand());
		queue.Print();
	}
	std::cout << "Извлекаем элемент " << queue.Pop() << std::endl;
	std::cout << "Стек после извлечения" << std::endl;
	queue.Print();

	std::cout << "Очистка стэка" << std::endl;
	queue.Clear();
	queue.Print();
}