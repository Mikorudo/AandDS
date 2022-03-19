#include <stdlib.h>
#include <iostream>
#include <exception>

class MyList {
private:
	MyList* nextPtr;
	int value;

	MyList(int _value, MyList* _nextPtr) {
		value = _value;
		nextPtr = _nextPtr;
	}

public:

	MyList* Push(int _value) {
		MyList* head = this;
		MyList* newFirst = new MyList(_value, head);
		head = newFirst;
		return head;
	}

	MyList* Pop(int& outValue) {
		outValue = value;
		MyList* head = nextPtr;
		this->nextPtr = NULL;
		delete this;
		return head;
	}

	void Print() {
		std::cout << value << "\t";
		if (nextPtr != NULL)
			nextPtr->Print();
		else
			std::cout << std::endl;
	}

	MyList* Clear() {
		delete this;
		return NULL;
	}

	~MyList() {
		if (nextPtr != NULL)
			delete nextPtr;
	}
};
class MyStack {
private:
	MyList* head;
public:
	MyStack() {
		head = NULL;
	}
	void Push(int _value) {
		head = head->Push(_value);
	}
	int Pop() {
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
			std::cout << "Пустой стек" << std::endl;
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
	MyStack stack;
	std::cout << "Добавление элементов в стек" << std::endl;
	for (size_t i = 0; i < 5; i++) {
		stack.Push(myRand());
		stack.Print();
	}
	std::cout << "Извлекаем элемент " << stack.Pop() << std::endl;
	std::cout << "Стек после извлечения" << std::endl;
	stack.Print();
	
	std::cout << "Очистка стэка" << std::endl;
	stack.Clear();
	stack.Print();
}