#include<stdint.h>
#include<iostream>
#include "../../../OOP/OOP_LAB_4_(Ñlass of boolean matrix)/Boolmatrix/Boolmatrix.h"
#include "../../../OOP/OOP_LAB_5_(Ñlass list)/OOP_LAB_5_(Ñlass list)/List.h"
#include "../../../OOP/OOP_LAB_2/OOP_LAB_2/Array.h"
#include "Graph.h"


void Graph::FormLead()
{

	for (int col = 0; col < m_matrix.Cols(); col++)
	{
		Leader node;
		node.key = col + 1;
		for (int row = 0; row < m_matrix.Rows(); row++)
		{
			if (m_matrix[row][col] == true)
				node.real_st += 1;
		}
		m_lead.PushBack(node);
	}
	for (int row = 0; row < m_matrix.Rows(); row++)
	{
		List<Leader>::Iterator cur = m_lead.begin();
		List<Leader>::Iterator cgr = m_lead.begin() + row;
		for (int col = 0; col < m_matrix.Cols(); col++)
		{
			Leader::Trailer node;
			if (m_matrix[row][col] == true)
			{
				node.lead = cur;
				cgr.m_node->data.trl.PushBack(node);
			}
			++cur;
		}
	}
}
void Graph::CreateLDnew(List<Leader>& LDnew)
{
	List<Leader>::Iterator cgr = m_lead.begin();
	while (cgr != m_lead.end())
	{
		if (cgr.m_node->data.flag == 0 && (cgr.m_node->data.real_st - cgr.m_node->data.del_st) == 0)
		{
			LDnew.PushFront(cgr.m_node->data);
			cgr.m_node->data.flag = 1;
		}
		++cgr;
	}
}

void Graph::ReducingArcs(List<Leader>& LDnew)
{
	List<Leader>::Iterator it = LDnew.begin();
	LDnew.TakeNode(it);
	answer[a_size] = it.m_node->data.key;
	a_size++;
	List<Leader::Trailer>::Iterator cur = it.m_node->data.trl.begin();
	while (cur != it.m_node->data.trl.end())
	{
		cur.m_node->data.lead.m_node->data.del_st += 1;
		++cur;
	}
	CreateLDnew(LDnew);
}
void Graph::Sort(List<Leader>& LDnew)
{
	ReducingArcs(LDnew);
	if (!(LDnew.isEmpty()))
		Sort(LDnew);
}
void Graph::TSort()
{
	a_size = 0;
	Array<int> arr(m_matrix.Cols(), 0);
	answer = arr;
	List<Leader> LDnew;
	CreateLDnew(LDnew);
	Sort(LDnew);
	Recovery();
}

Array<int> Graph::Answer()
{
	return answer;
}

void Graph::Recovery()
{
	List<Leader>::Iterator it = m_lead.begin();
	while (it != m_lead.end())
	{
		it.m_node->data.del_st = 0;
		it.m_node->data.flag = 0;
		++it;
	}
}