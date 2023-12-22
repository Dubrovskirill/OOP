#pragma once
#pragma once
#include<iostream>
#include <random>
#include <fstream>
#include<vector>
#include<stack>
#include "../../../OOP/OOP_LAB_4_(Сlass of boolean matrix)/BoolMatrix/BoolMatrix.h"
#include "../../../OOP/OOP_LAB_5_(Сlass list)/OOP_LAB_5_(Сlass list)/List.h"
#include "../../../OOP/OOP_LAB_2/OOP_LAB_2/Array.h"

struct Leader
{
	struct Trailer;
	int key = 0;//номер вершины
	int st = 0;//число входящих дуг
	//int del_st = 0;//число удаленых входящих дуг
	//bool flag = 0;
	List<Trailer>::Iterator trl=nullptr;
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
		Array<int> arr();
		ordered = Array<int>(0);
		FormLead();
	}

	void TSort();
	Array<int> Ordered();
	
private:
	List<Leader> m_lead;
	//List<List<Leader>::Iterator> m_leaditr;
	std::stack <List<Leader>::Iterator> m_STACKLEADITER;
	List<List<Leader::Trailer>> m_trai;
	BoolMatrix m_matrix;
	Array<int> ordered;

	void FormLead();
	void Sort(List<Leader>& LDnew);
	void fillLDnew(List<Leader>& LDnew);
	void ReducingArcs(List<Leader>& LDnew);
	void Recovery();
};