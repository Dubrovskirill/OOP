#pragma once
#pragma once
#include<iostream>
#include <random>
#include <fstream>
#include<vector>
#include "../../../OOP/OOP_LAB_4_(Сlass of boolean matrix)/BoolMatrix/BoolMatrix.h"
#include "../../../OOP/OOP_LAB_5_(Сlass list)/OOP_LAB_5_(Сlass list)/List.h"
#include "../../../OOP/OOP_LAB_2/OOP_LAB_2/Array.h"

struct Leader
{
	struct Trailer;
	int key = 0;//номер вершины
	int real_st = 0;//число входящих дуг
	int del_st = 0;//число удаленых входящих дуг
	bool flag = 0;
	List<Leader::Trailer> trl;
};

struct Leader::Trailer
{
	List<Leader>::Iterator lead = nullptr;
};



class Graph
{
public:
	Graph(BoolMatrix matrix)
		:m_matrix(matrix)
	{
		Array<int> arr(m_matrix.Cols(), 0);
		answer = arr;
		FormLead();
	}

	void TSort();
	Array<int> Answer();
	
private:
	List<Leader> m_lead;
	BoolMatrix m_matrix;
	Array<int> answer;
	int a_size = 0;

	void FormLead();
	void Sort(List<Leader>& LDnew);
	void CreateLDnew(List<Leader>& LDnew);
	void ReducingArcs(List<Leader>& LDnew);
	void Recovery();
};