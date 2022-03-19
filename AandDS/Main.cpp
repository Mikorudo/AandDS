#define N 3
#include <stdlib.h>
#include <iostream>
#include <exception>

void printArrayMatrix(int* array, int size) {
	if (size <= 0)
		throw std::exception("��������������� ������ �������");
	for (size_t i = 0; i < size; i++) {
		for (size_t j = 0; j < size; j++) {
			std::cout << array[i * size + j] << "\t";
		}
		std::cout << std::endl;
	}
}

void swapLinesArrayMatrix(int* array, int size, int firstLine, int secondLine) {
	if (size <= 0)
		throw std::exception("��������������� ������ �������");
	if (firstLine < 0)
		throw std::exception("������������� ����� ������ ������ ��� ������������");
	if (secondLine < 0)
		throw std::exception("������������� ����� ������ ������ ��� ������������");
	for (size_t i = 0; i < size; i++) {
		int temp = array[firstLine * size + i];
		array[firstLine * size + i] = array[secondLine * size + i];
		array[secondLine * size + i] = temp;
	}
	std::cout << "��������� ������������ " << firstLine << " � " << secondLine << " �����" << std::endl;
}

void printPtrArrayMatrix(int** ptrArray, int size) {
	if (size <= 0)
		throw std::exception("��������������� ������ �������");
	for (size_t i = 0; i < size; i++) {
		for (size_t j = 0; j < size; j++) {
			std::cout << ptrArray[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}

void swapLinesPtrArrayMatrix(int** ptrArray, int size, int firstLine, int secondLine) {
	if (size <= 0)
		throw std::exception("��������������� ������ �������");
	if (firstLine < 0)
		throw std::exception("������������� ����� ������ ������ ��� ������������");
	if (secondLine < 0)
		throw std::exception("������������� ����� ������ ������ ��� ������������");
	int* temp = ptrArray[firstLine];
	ptrArray[firstLine] = ptrArray[secondLine];
	ptrArray[secondLine] = temp;
	std::cout << "��������� ������������ " << firstLine << " � " << secondLine << " �����" << std::endl;
}

int main() {
	setlocale(LC_ALL, "ru");
	srand(time(0));

	std::cout << "�������, ������������� ����� ������:" << std::endl;
	int array[N * N];
	for (size_t i = 0; i < N*N; i++) {
		array[i] = rand() % 100;
	}

	printArrayMatrix(array, N);
	swapLinesArrayMatrix(array, N, 0, 1);
	printArrayMatrix(array, N);

	std::cout << "�������, ������������� ����� ������ ����������" << std::endl;
	int** ptrArray = new int*[N];
	for (size_t i = 0; i < N; i++) {
		ptrArray[i] = new int[N];
		for (size_t j = 0; j < N; j++) {
			ptrArray[i][j] = rand() % 100;
		}
	}

	printPtrArrayMatrix(ptrArray, N);
	swapLinesPtrArrayMatrix(ptrArray, N, 0, 1);
	printPtrArrayMatrix(ptrArray, N);

	delete[] ptrArray;
	return 0;
}