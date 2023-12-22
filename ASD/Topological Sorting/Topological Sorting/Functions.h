#pragma once
#include<iostream>
#include <random>
#include <fstream>
#include<vector>
#include "../../../OOP/OOP_LAB_4_(Ñlass of boolean matrix)/BoolMatrix/BoolMatrix.h"
#include "../../../OOP/OOP_LAB_5_(Ñlass list)/OOP_LAB_5_(Ñlass list)/List.h"
#include "../../../OOP/OOP_LAB_2/OOP_LAB_2/Array.h"


int FormVectorFile(std::vector<int>& vec, std::string name)
{
	std::ifstream inputFile(name);
	int count = 0;
	if (inputFile.is_open())
	{
		int num;
		
		while (inputFile >> num)
		{
			if (num > count)
				count = num;
			vec.push_back(num);
		}
	}
	return count;
}
void FormAdjacencyMatr(BoolMatrix& bm, std::vector<int>& vec)
{
	for (int k = 0; k <= vec.size() - 2; k += 2)
		bm[vec[k] - 1][vec[k + 1] - 1] = 1;
}

bool Ñheck(const Array<int>& arr, int& size)
{
	if(arr.Size()!=size)
		return false;
	return true;
}

Array<int> TSortMatr(BoolMatrix matrix)
{
	int n = matrix.Rows();
	Array<int> answer(0);
	BoolVector crossed(n, 0);
	int k = 0;
	while (!crossed.Full())
	{
		BoolVector mask = matrix.RowÂisjunction() | crossed;
		if (mask.Full())
			return answer;

		mask = ~mask;
		crossed |= mask;
		for (int i = 0; i < n; i++)
			if (mask[i])
			{
				answer.Insert(i+1,answer.end());
				matrix[i].Set0();
			}
	}
	
	return answer;
}



