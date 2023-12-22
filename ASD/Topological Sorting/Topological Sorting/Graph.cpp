#include<stdint.h>
#include<iostream>
#include<stack>
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
				node.st += 1;
		}
		m_lead.PushBack(node);
	}

	//List<Leader>::Iterator cur = m_lead.begin();
	List<Leader>::Iterator cgr = m_lead.begin();
	//List<List<Leader::Trailer>>::Iterator hlp = m_trai.begin();
	for (int row = 0; row < m_matrix.Rows(); row++)
	{
		List<Leader>::Iterator cur = m_lead.begin();
		List < Leader::Trailer> tmplist;
		Leader::Trailer tmpnode;
		for (int col = 0; col < m_matrix.Cols(); col++)
		{
			if (m_matrix[row][col] == true)
			{
				tmpnode.lead = cur;
				tmplist.PushBack(tmpnode);
			}
			++cur;
		}
		m_trai.PushBack(tmplist);
		List<List<Leader::Trailer>>::Iterator hlp = m_trai.begin()+row;
		cgr.m_node->data.trl = hlp.m_node->data.begin();
		++cgr;
		//++hlp;
	}
}
void Graph::fillLDnew(List<Leader>& LDnew)
{
	List<Leader>::Iterator cgr = m_lead.begin();
	while (cgr!=m_lead.end())
	{
		if (cgr.m_node->data.st == 0)
		{
			LDnew.PushFront(cgr.m_node->data);

			m_STACKLEADITER.push(cgr);
			m_lead.TakeNode(cgr);


		}
		 ++cgr;
	}
}

void Graph::ReducingArcs(List<Leader>& LDnew)
{
	List<Leader>::Iterator it = LDnew.begin();
	ordered.Insert(it.m_node->data.key, ordered.end());
	//it.m_node->data.trl
	List<Leader::Trailer>::Iterator cur = it.m_node->data.trl;
	while (cur.m_node->next != nullptr)
	{
		cur.m_node->data.lead.m_node->data.st -= 1;
		++cur;
	}
	LDnew.Remove(it);
}
void Graph::Sort(List<Leader>& LDnew)
{
	ReducingArcs(LDnew);
	fillLDnew(LDnew);
	if (!(LDnew.isEmpty()))
		Sort(LDnew);
}
void Graph::TSort()
{
	ordered = Array<int>(0);

	List<Leader> LDnew;
	fillLDnew(LDnew);
	if (!(LDnew.isEmpty()))
		Sort(LDnew);

	Recovery();
}

Array<int> Graph::Ordered()
{
	return ordered;
}

void Graph::Recovery()
{

	//ordered.Print();
	List<List<Leader::Trailer>>::Iterator it = m_trai.begin();
	//List < List<Leader>::Iterator>::Iterator ldit = m_leaditr.begin();
	//List<Leader>::Iterator cur = m_lead.begin();
	while (!m_STACKLEADITER.empty())
	{
		//List<Leader>::Iterator cur = m_STACKLEADITER.top();
		m_lead.InsertNode(m_STACKLEADITER.top(), m_lead.begin());
		List<Leader::Trailer>::Iterator cur= m_STACKLEADITER.top().m_node->data.trl;
		m_STACKLEADITER.pop();
		while (cur.m_node->next != nullptr)
		{
			cur.m_node->data.lead.m_node->data.st+=1;
			++cur;
		}

	}
}