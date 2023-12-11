#include<iostream>
#include "List.h"
//#include "../../OOP_LAB_2/OOP_LAB_2/Array.h"
int main()
{
	List<int> list_1(5);
	list_1.Print();
	Array<char> arr(10, 'z');
	arr.Print();
	List<char> list_arr(arr);
	list_arr.Print();

	List<int> list_2(7, 15);
	list_2.Print();
	List<int> list_3(7,15);
	list_2 = list_3;
	list_2.Print();
	//std::cin >> list_2;
	//List<int>::Node* n=list_2.Search(5);
	std::cout << std::endl;
	/*for (int i = 0; i < 10; i++)
	{
		list_1.PushBack(i);
		list_1.Print();
	}
	for (int i = 0; i < 10; i++)
	{
		list_1.PopBack();
		list_1.Print();
	}

	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
	{
		list_1.PushFront(i);
		list_1.Print();
	}
	for (int i = 0; i < 10; i++)
	{
		list_1.PopFront();
		list_1.Print();
	}*/

	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
	{
		list_1.Insert(i, i);
		list_1.Print();
	}
	//std::cout << std::endl << list_1[10];
	/*for (int i = 9; i >-1; i--)
	{
		list_1.Remove(i);
		list_1.Print();
	}*/
	List<char> list_4;
	list_4.PushBack('a');
	list_4.PushBack('b');
	list_4.PushBack('A');
	list_4.PushBack('c');
	list_4.PushBack('Z');
	std::cout << std::endl << list_4.Max() << std::endl;

	list_3 = list_1 + list_2;
	list_3.Print();
	list_3 += list_1;
	list_3.Print();
	list_1.Print();
	list_2.Print();

	std::cout << *(list_4.begin());
	return 0;
}