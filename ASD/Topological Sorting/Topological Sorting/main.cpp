#include<iostream>
#include <random>
#include <fstream>
#include<vector>
#include "../../../OOP/OOP_LAB_4_(Ñlass of boolean matrix)/BoolMatrix/BoolMatrix.h"
#include "../../../OOP/OOP_LAB_5_(Ñlass list)/OOP_LAB_5_(Ñlass list)/List.h"
#include "../../../OOP/OOP_LAB_2/OOP_LAB_2/Array.h"
#include"Functions.h"
#include"Graph.h"

void CheckandPrint(Array<int> & answer, int & size)
{
	if (!Ñheck(answer,size))
		std::cout << "!!!CYCLE!!!" << std::endl;
	else
	{
		std::cout << "Sorted vertices: ";
		for (int i = 0; i < size; i++)
			std::cout << answer[i] << " ";
	}
}

int main()
{
	std::vector<int> edges;
	int n = FormVectorFile(edges, "../../../../matrix.txt");
	BoolMatrix Adj(n, n, 0);
	FormAdjacencyMatr(Adj, edges);
	Adj.Print();

	Graph gr(Adj);
	while (true)
	{
		gr.TSort();
		Array<int> answer(gr.Ordered());
		CheckandPrint(answer, n);
		std::cout << "\n";
	}

	/*std::cout << "Would you like to use matrix sorting or use a list? (M/L)\n";
	char ans;
	std::cin >> ans;
	if (ans == 'L')
	{
		Graph gr(Adj);
		gr.TSort();
		Array<int> answer(gr.Ordered());
		
		int size = Adj.Rows();
		CheckandPrint(answer, size);
	}
	else if (ans == 'M')
	{
		Array<int> answer(TSortMatr(Adj));
		int size = Adj.Rows();
		CheckandPrint(answer, size);
	}
	else
		std::cout << "The value you entered is incorrect!";*/

}
