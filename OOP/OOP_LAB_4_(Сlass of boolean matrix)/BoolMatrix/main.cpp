#include<iostream>
#include "BoolMatrix.h"
#include <random>
#include <ctime>

char** CharMatr(int rows, int cols)
{
	std::mt19937 rng(std::time(nullptr));
	std::uniform_int_distribution<int> dist(0, 1);
	char** boolMatrix = new char* [rows];
	for (int i = 0; i < rows; i++) {
		boolMatrix[i] = new char[cols + 1];
		int j = 0;
		for (j = 0; j < cols; j++) {
			std::cin >> boolMatrix[i][j];
		}
		boolMatrix[i][j] = '\0';
	}
	return boolMatrix;
}

char** RandCharMatr(int rows,int cols)
{
	std::mt19937 rng(std::time(nullptr));
	std::uniform_int_distribution<int> dist(0, 1);
	char** boolMatrix = new char* [rows];
	for (int i = 0; i < rows; i++) {
		boolMatrix[i] = new char[cols+1];
		int j=0;
		for (j = 0; j < cols; j++) {
			boolMatrix[i][j]= dist(rng) == 0 ? '0' : '1';
		}
		boolMatrix[i][j] = '\0';
	}
	return boolMatrix;
}

void Print(int rows,int cols, char** boolMatrix)
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cout << boolMatrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void Del(int rows, int cols, char**boolMatrix)
{
	for (int i = 0; i < rows; i++) {
		delete[] boolMatrix[i];
	}
	delete[] boolMatrix;
}

int main()
{
	BoolMatrix bm0;
	bm0.Print();
	std::cout << std::endl;
	BoolMatrix bm1(5,15,1);
	bm1.Print();
	std::cout << std::endl;
	BoolMatrix bm2(bm1);
	bm2.Print();
	std::cout << std::endl;
	char** cmatr = RandCharMatr(10, 10);
	Print(10, 10, cmatr);
	std::cout << std::endl;
	BoolMatrix bm3(cmatr, 10, 10);
	bm3.Print();
	Del(10, 10, cmatr);
	std::cout << std::endl;

	return 0;
}

//void Rand(char** matrix, int rows, int cols) {
//	std::mt19937 rng(std::time(nullptr)); // генератор случайных чисел
//	std::uniform_int_distribution<int> dist(0, 1); // равномерное распределение от 0 до 1
//
//	for (int i = 0; i < rows; i++) {
//		for (int j = 0; j < cols; j++) {
//			matrix[i][j] = dist(rng) == 0 ? '0' : '1'; // заполняем случайными значениями '0' или '1'
//		}
//	}
//}
