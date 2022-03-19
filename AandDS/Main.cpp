#define N 3
#include <stdlib.h>
#include <iostream>
#include <exception>

void printArrayMatrix(int* array, int size) {
	if (size <= 0)
		throw std::exception("Неположительный размер массива");
	for (size_t i = 0; i < size; i++) {
		for (size_t j = 0; j < size; j++) {
			std::cout << array[i * size + j] << "\t";
		}
		std::cout << std::endl;
	}
}

void swapLinesArrayMatrix(int* array, int size, int firstLine, int secondLine) {
	if (size <= 0)
		throw std::exception("Неположительный размер массива");
	if (firstLine < 0)
		throw std::exception("Отрицательный номер первой строки для перестановки");
	if (secondLine < 0)
		throw std::exception("Отрицательный номер второй строки для перестановки");
	for (size_t i = 0; i < size; i++) {
		int temp = array[firstLine * size + i];
		array[firstLine * size + i] = array[secondLine * size + i];
		array[secondLine * size + i] = temp;
	}
	std::cout << "Произошла перестановка " << firstLine << " и " << secondLine << " строк" << std::endl;
}

void printPtrArrayMatrix(int** ptrArray, int size) {
	if (size <= 0)
		throw std::exception("Неположительный размер массива");
	for (size_t i = 0; i < size; i++) {
		for (size_t j = 0; j < size; j++) {
			std::cout << ptrArray[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}

void swapLinesPtrArrayMatrix(int** ptrArray, int size, int firstLine, int secondLine) {
	if (size <= 0)
		throw std::exception("Неположительный размер массива");
	if (firstLine < 0)
		throw std::exception("Отрицательный номер первой строки для перестановки");
	if (secondLine < 0)
		throw std::exception("Отрицательный номер второй строки для перестановки");
	int* temp = ptrArray[firstLine];
	ptrArray[firstLine] = ptrArray[secondLine];
	ptrArray[secondLine] = temp;
	std::cout << "Произошла перестановка " << firstLine << " и " << secondLine << " строк" << std::endl;
}

int main() {
	setlocale(LC_ALL, "ru");
	srand(time(0));

	std::cout << "Матрица, реализованная через массив:" << std::endl;
	int array[N * N];
	for (size_t i = 0; i < N*N; i++) {
		array[i] = rand() % 100;
	}

	printArrayMatrix(array, N);
	swapLinesArrayMatrix(array, N, 0, 1);
	printArrayMatrix(array, N);

	std::cout << "Матрица, реализованная через массив указателей" << std::endl;
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