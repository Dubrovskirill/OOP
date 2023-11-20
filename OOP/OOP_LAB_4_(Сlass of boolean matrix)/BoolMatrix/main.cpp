#include<iostream>
#include "BoolMatrix.h"
#include <random>
#include <ctime>

char** CharMatr(int rows, int cols)
{
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
	std::mt19937 rng( time(nullptr));
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
	using  std::cout;
	using  std::cin;
	using  std::endl;

	BoolMatrix bm0;
	bm0.Print();
	 cout <<  endl;
	BoolMatrix bm1(5,15,1);
	bm1.Print();
	 cout <<  endl;
	BoolMatrix bm2(bm1);
	bm2.Print();
	 cout <<  endl;
	char** cmatr = RandCharMatr(10, 10);
	Print(10, 10, cmatr);
	 cout <<  endl;
	BoolMatrix bm3(cmatr, 10, 10);
	bm3.Print();
	Del(10, 10, cmatr);
	 cout <<  endl;

	/* cin >> bm1[1];
	bm1.Print();
	 cout <<  endl;*/

	cout << bm1.Weight() << endl;
	cout << bm1[0].Weight() << endl;
	cout << bm1.Weight(0) << endl;

	 bm3.Print();
	 cout << endl;
	 cout << bm3.LogAnd() << endl;
	 cout << bm3.LogOr() << endl;



	 cmatr = RandCharMatr(5, 5);
	 Print(5, 5, cmatr);
	 cout << endl;
	 BoolMatrix bm4(cmatr, 5, 5);
	 Del(5, 5, cmatr);

	 bm3.Print();
	 cout << endl;
	 bm4.Print();
	 cout << endl;
	 cout << endl << (bm3 & bm4);
	 cout << endl << (bm3 | bm4);
	 cout << endl << (bm3 ^ bm4);
	 cout << endl<< ~bm4;
	 cout << endl;
	 cout << "=========="<<endl;
	 cout <<bm4;
	 bm4.Inverse(2, 0);
	 cout<<endl << bm4;
	 bm4.Inverse(0,2,8);
	 cout << endl << bm4;
	 bm4.Set1(0, 0);
	 cout << endl << bm4;
	 bm4.Set0(0, 0,8);
	 cout << endl << bm4;
	return 0;
}


