#include <iostream>
#include "Matrix.h"

int** MemoryAlloc(int m, int n)
{
	{
		int** Arr;
		Arr = new int* [m];
		for (size_t i = 0; i < m; i++) {
			Arr[i] = new int[n];
		}

		return Arr;
	}
}

void MatrixFill(int** pArr, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			pArr[i][j] = rand();

			std::cout << pArr[i][j] << " ";
		}
	}
}

void MatrixDelete(int** ptr, int m)
{
	for (size_t i = 0; i < m; i++) {
		delete[] ptr[i]; // Освобождаем i-тый одномерный int массив
	}
	delete[] ptr;
}
