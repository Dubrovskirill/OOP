#include<stdint.h>
#include<iostream>
#include "../../../OOP/OOP_LAB_4_(�lass of boolean matrix)/Boolmatrix/Boolmatrix.h"
#include "../../../OOP/OOP_LAB_5_(�lass list)/OOP_LAB_5_(�lass list)/List.h"
#include "../../../OOP/OOP_LAB_2/OOP_LAB_2/Array.h"
#include "Graph.h"


void Graph::FormLead()
{

	//Array<int> answer(m_matrix.Cols(), 0);
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
		//List< Leader::Trailer> arcs;
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

		//List<Leader>::Iterator cgr = m_lead.begin() + row;
		//cgr.m_node->data.trl = arcs;
	}

	//return answer;
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
	answer.Print();
	if (!(LDnew.isEmpty()))
		Sort(LDnew);
}
void Graph::TSort()
{
	//Array<int> ans(m_matrix.Cols(), 0);
	List<Leader> LDnew;
	FormLead();
	CreateLDnew(LDnew);
	Sort(LDnew);
	/*ReducingArcs(LDnew);
	answer.Print();
	if (!(LDnew.isEmpty()))
		TSort();*/

}

Array<int> Graph::Answer()
{
	return answer;
}