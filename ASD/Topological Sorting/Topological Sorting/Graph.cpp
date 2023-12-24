#include<stdint.h>
#include<iostream>
#include<stack>
#include "Graph.h"


void Graph::FormLead(const BoolMatrix& matrix)
{

	for (int col = 0; col < matrix.Cols(); col++)
	{
		Leader node;
		node.key = col + 1;
		for (int row = 0; row < matrix.Rows(); row++)
		{
			if (matrix[row][col] == true)
				node.st += 1;
		}
		m_leader.PushBack(node);
	}

	List<Leader>::Iterator cgr = m_leader.begin();
	for (int row = 0; row < matrix.Rows(); row++)
	{
		List<Leader>::Iterator cur = m_leader.begin();
		List < Leader::Trailer> tmplist;
		Leader::Trailer tmpnode;
		for (int col = 0; col < matrix.Cols(); col++)
		{
			if (matrix[row][col] == true)
			{
				tmpnode.lead = cur;
				tmplist.PushBack(tmpnode);
			}
			++cur;
		}
		m_trailer.PushBack(tmplist);
		List<List<Leader::Trailer>>::Iterator hlp = m_trailer.begin()+row;
		cgr.m_node->data.trl = hlp.m_node->data.begin();
		++cgr;
	}
}

void Graph::fillLDnew()
{
	List<Leader>::Iterator cgr = m_leader.begin();
	while (cgr!=m_leader.end())
	{
		if (cgr.m_node->data.st == 0)
		{
			m_LDnew.PushFront(cgr.m_node->data);

			m_StackDeleteVertices.push(cgr);
			m_leader.TakeNode(cgr);
		}
		 ++cgr;
	}
}

void Graph::ReducingArcs()
{
	List<Leader>::Iterator it = m_LDnew.begin();
	while (!m_LDnew.isEmpty())
	{
		m_ordered.Insert(it.m_node->data.key, m_ordered.end());
		List<Leader::Trailer>::Iterator cur = it.m_node->data.trl;
		while (cur.m_node->next != nullptr)
		{
			cur.m_node->data.lead.m_node->data.st -= 1;
			++cur;
		}

		it=m_LDnew.Remove(it);
	}
}

void Graph::Sort()
{
	ReducingArcs();
	fillLDnew();
	if (!m_LDnew.isEmpty())
		Sort();
}
void Graph::TSort()
{
	if (m_ordered.Size())
		return;
	fillLDnew();
	Sort();
	Recovery();
}

Array<int> Graph::Ordered()
{
	return m_ordered;
}

void Graph::Recovery()
{
	List<List<Leader::Trailer>>::Iterator it = m_trailer.begin();
	while (!m_StackDeleteVertices.empty())
	{
		m_leader.InsertNode(m_StackDeleteVertices.top(), m_leader.begin());
		List<Leader::Trailer>::Iterator cur= m_StackDeleteVertices.top().m_node->data.trl;
		m_StackDeleteVertices.pop();
		while (cur.m_node->next != nullptr)
		{
			cur.m_node->data.lead.m_node->data.st+=1;
			++cur;
		}
	}
}