#include<iostream>
#include "List.h"
int main()
{
	List<int> list_1;
	list_1.Print();
	List<int> list_2(7, 15);
	list_2.Print();
	List<int> list_3(7,15);
	list_2 = list_3;
	list_2.Print();
	std::cin >> list_2;
	
	std::cout << list_2;
	return 0;
}