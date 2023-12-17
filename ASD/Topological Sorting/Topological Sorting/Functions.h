#pragma once
#include<iostream>
#include <random>
#include <fstream>
#include<vector>
#include "../../../OOP/OOP_LAB_4_(Сlass of boolean matrix)/BoolMatrix/BoolMatrix.h"
#include "../../../OOP/OOP_LAB_5_(Сlass list)/OOP_LAB_5_(Сlass list)/List.h"
#include "../../../OOP/OOP_LAB_2/OOP_LAB_2/Array.h"

//struct Leader
//{
//	int key = 0;//номер вершины
//	int real_st = 0;//число входящих дуг
//	int del_st = 0;//число удаленых входящих дуг
//	List<Trailer>::Iterator trl = nullptr;
//};
//
//struct Trailer
//{
//	//List<Leader>::Node* lead = nullptr;
//	List<Leader>::Iterator lead = nullptr;
//};

//void RandMatr(BoolMatrix& matrix)
//{
//	std::random_device rd;
//	std::mt19937 rng(rd());
//	std::uniform_int_distribution<int> dist(0, 1);
//	for (int i = 0; i < matrix.Rows(); i++)
//		for (int j = 0; j < matrix.Cols(); j++)
//			matrix[i][j] = dist(rng);
//}
//
//BoolMatrix Form(std::string name)
//{
//	std::ifstream inputFile(name);
//	std::string st;
//	if (inputFile.is_open())
//	{
//		char num;
//		while (inputFile >> num)
//			if (num != ',' && num != ' ')
//				st.push_back(num);
//	}
//	else std::cout << "File opening error!\n";
//	return BoolMatrix(st);
//}

//void FormVector(std::vector<int>& vec, const int  n)
//{
//	int ed;
//	std::cin >> ed;
//	if (ed > n || ed == 0)
//	{
//		std::cout << "The entered value is incorrect: exceeding the number of verinches.\n Try again:";
//		FormVector(vec, n);
//		return;
//	}
//	if (ed < 0)
//		return;
//	vec.push_back(ed);
//	FormVector(vec, n);
//}

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
	for (int k = 0; k < vec.size() - 2; k += 2)
		bm[vec[k] - 1][vec[k + 1] - 1] = 1;
}

bool Сheck(const Array<int>& arr)
{
	for (int i = arr.Size() - 1; i >= 0; --i)
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


//Array<int> TSortList(BoolMatrix matrix)
//{
//	List<Leader> Graph;
//	Array<int> answer(matrix.Cols(), 0);
//	for (int col = 0; col < matrix.Cols(); col++)
//	{
//		Leader node;
//		node.key = col + 1;
//		for (int row = 0; row < matrix.Rows(); row++)
//		{
//			if (matrix[row][col] == true)
//				node.real_st += 1;
//		}
//		Graph.PushBack(node);
//	}
//
//	for (int row = 0; row < matrix.Rows(); row++)
//	{
//		List<Trailer> arcs;
//		List<Leader>::Iterator cur = Graph.begin();
//		for (int col = 0; col < matrix.Cols(); col++)
//		{
//			Trailer node;
//			if (matrix[row][col] == true)
//			{
//				node.lead = cur;
//				arcs.PushBack(node);
//			}
//			++cur;
//		}
//		//List<Leader>::Iterator cgr = Graph.begin();
//
//	}
//
//	return answer;
//}
