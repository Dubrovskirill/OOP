#include<iostream>
#include "List.h"
int main()
{
	List<int> list_1;
	list_1.Print();
	List<int> list_2(5, 10);
	list_2.Print();
	List<int> list_3(list_2);
	list_3.Print();
	return 0;
}