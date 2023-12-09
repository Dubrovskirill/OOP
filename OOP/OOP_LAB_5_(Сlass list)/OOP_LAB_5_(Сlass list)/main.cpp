#include<iostream>
#include "List.h"
int main()
{
	List<int> list_1;
	list_1.Print();
	List<int> list_2(5, 10);
	list_2.Print();
	List<int> list_3(3,7);
	list_3.Print();
	list_2.Swap(list_3);
	list_2.Print();
	list_3.Print();
	list_3.PushFront(19);
	list_3.PopFront();
	list_3.Print();


	return 0;
}