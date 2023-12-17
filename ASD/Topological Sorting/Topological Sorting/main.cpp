#include<iostream>
#include <random>
#include <fstream>
#include<vector>
#include "../../../OOP/OOP_LAB_4_(Ñlass of boolean matrix)/BoolMatrix/BoolMatrix.h"
#include "../../../OOP/OOP_LAB_5_(Ñlass list)/OOP_LAB_5_(Ñlass list)/List.h"
#include "../../../OOP/OOP_LAB_2/OOP_LAB_2/Array.h"
#include"Functions.h"
#include"Graph.h"


int main()
{
	std::vector<int> edges;
	int n=FormVectorFile(edges, "../../../../matrix.txt");
	BoolMatrix Adj(n, n, 0);
	FormAdjacencyMatr(Adj, edges);
	Adj.Print();
	Graph gr(Adj);
	gr.TSort();
	Array<int> answer(gr.Answer());
	if (!Ñheck(answer))
		std::cout << "!!!CYCLE!!!" << std::endl;
	else 
	{
		std::cout << "Sorted vertices: ";
		for (int i = 0; i < Adj.Rows(); i++)
	 std::cout << answer[i] << " ";
	}

	//Array<int> answer(gr.TSortList(Adj));

	//std::cout << "Would you like to use matrix sorting or use a list? (M/L)\n";
	//char ans;
	//std::cin >> ans;
	//if (ans == 'L')
	//{
	//	std::cout << "ok";//sortlist;
	//	Array<int> answer(TSortList(Adj));
	//}
	//if (ans == 'M')
	//{
	//	Array<int> answer(TSortMatr(Adj));
	//    if (!Ñheck(answer))
	//	std::cout << "!!!CYCLE!!!" << std::endl;
	//    else 
	//    {
	//	   std::cout << "Sorted vertices: ";
	//	   for (int i = 0; i < Adj.Rows(); i++)
	//		   std::cout << answer[i] << " ";
	//    }
	//}
	//if (ans != 'M' && ans !='L')
	//	std::cout << "The value you entered is incorrect!";



	




}
