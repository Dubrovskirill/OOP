#include<iostream>
#include <random>
#include <fstream>
#include<vector>
#include "../../../OOP/OOP_LAB_4_(Ñlass of boolean matrix)/BoolMatrix/BoolMatrix.h"
#include "../../../OOP/OOP_LAB_5_(Ñlass list)/OOP_LAB_5_(Ñlass list)/List.h"
#include "../../../OOP/OOP_LAB_2/OOP_LAB_2/Array.h"

void RandMatr(BoolMatrix& matrix)
{
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_int_distribution<int> dist(0, 1);
	for (int i = 0; i < matrix.Rows(); i++) 
		for (int j = 0; j < matrix.Cols(); j++) 
			matrix[i][j] = dist(rng);
}
BoolMatrix Form(std::string name)
{
	std::ifstream inputFile(name);
	std::string st;
	if (inputFile.is_open())
	{
		char num;
		while (inputFile >> num)
			if (num != ',' && num != ' ')
				st.push_back(num);
	}
	else std::cout << "File opening error!\n";
	/*for (int i = 0; i < st.size(); i++)
		std::cout << st[i];*/
	return BoolMatrix(st);
}
bool Ñheck(const Array<int>& arr)
{
	for (int i = arr.Size()-1; i >= 0; --i)
	{
		if (!arr[i])
			return false;
	}
	return true;
}
Array<int> TSortMatr(BoolMatrix matrix)
{
	int n = matrix.Rows();
	Array<int> answer(n, 0);
	BoolVector exp(n, 0);
	int k = 0;
	while (!exp.Full())
	{
		BoolVector mask(n, 0);
		for (int i = 0; i < n; i++)
		{
			mask |= matrix[i];
			if (exp[i])
				mask[i] = exp[i];
		}
		if (mask.Full())
		{
			return answer;
		}
		mask = ~mask;
		
		for (int i = 0; i < n; i++)
			if (mask[i])
				exp[i] = mask[i];
		BoolVector mask2(n, 1);

		for (int i = 0; i < n; i++)
			if ((mask[i] & mask2[i]) == 1)
			{
				answer[k++] = i + 1;
				mask2 >>= 1;
			}
		for (int j = 0; j < n; j++)
			for (int i = 0; i < k; i++)
				matrix[answer[i] - 1][j] = 0;
	}

	return answer;
}
int main()
{
	/*std::cout << "Enter the size of the matrix: ";
	int n;
	std::cin >> n;
	BoolMatrix Test(n, n, 0);
	std::cout << "Enter the matrix: " << std::endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			std::cin >> Test[i][j];*/
	
	BoolMatrix Test(Form("../../../../matrix.txt"));
	//BoolMatrix Test(18, 18, 1);
	Test.Print();
	Array<int> answer(TSortMatr(Test));
	
	if (!Ñheck(answer))
		std::cout << "!!!CYCLE!!!" << std::endl;
	else 
	{
		std::cout << "Sorted vertices: ";
		for (int i = 0; i < Test.Rows(); i++)
			std::cout << answer[i] << " ";
	}
}
//0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 
//0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0,
//0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
//0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
//0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
//0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
//0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
//0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,