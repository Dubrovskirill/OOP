#pragma once
#include<iostream>
#include <random>
#include <fstream>
#include<vector>
#include<stack>
#include "../../../OOP/OOP_LAB_4_(Ñlass of boolean matrix)/BoolMatrix/BoolMatrix.h"
#include "../../../OOP/OOP_LAB_5_(Ñlass list)/OOP_LAB_5_(Ñlass list)/List.h"
#include "../../../OOP/OOP_LAB_2/OOP_LAB_2/Array.h"

struct Leader
{
	struct Trailer;
	int key = 0;
	int st = 0;
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
	{
		Array<int> arr();
		m_ordered = Array<int>(0);
		FormLead(matrix);
	}

	void TSort();
	Array<int> Ordered();
	
	
private:
	List<Leader> m_leader;
	std::stack <List<Leader>::Iterator> m_StackDeleteVertices;
	List<List<Leader::Trailer>> m_trailer;
	Array<int> m_ordered;
	List<Leader> m_LDnew;

	void FormLead(const BoolMatrix& matrix);
	void Sort();
	void fillLDnew();
	void ReducingArcs();
	void Recovery();
};