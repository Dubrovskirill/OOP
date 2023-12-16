#include<iostream>
#include "List.h"
//#include "../../OOP_LAB_2/OOP_LAB_2/Array.h"

int main()
{
	List<int> list_1;
	list_1.Print();

	for (int i = 0; i < 5; ++i) 
	{
		list_1.PopFront();
		list_1.PopBack();
	}
	
	for (int i = 0; i < 10; i++)
	{
		list_1.Insert(i,i);
		list_1.Print();
	}

	for (int i = 9; i >=0; i--)
	{
		list_1.Remove(i);
		list_1.Print();
	}

	for (int i = 0; i < 10; i++)
		list_1.Insert(i, i);
	list_1.Print();

	if ( list_1.RemoveKey(5))
		list_1.Print();
	//List<int>::Iterator<int,List<int>> t= list_1.end() - 1;
	list_1.Print();
	List<int>::Iterator t = list_1.end() - 1;
	list_1.RemoveRange(list_1.begin(),t);
	list_1.Print();

	for (int i = 0; i < 10; i++)
		list_1.Insert(i, i);
	//list_1.Print();
	list_1.InsertAfter(5, 400);
	list_1.Print();
	std::cout << list_1.Max()<<std::endl<< list_1.Min() << std::endl;
	List<char> list_2;
	list_2.PushBack('a');
	list_2.PushBack('z');
	list_2.PushBack('c');
	list_2.PushBack('D');
	list_2.PushBack('a');
	list_2.PushBack('V');
	list_2.Print();
	list_2.Sort();
	list_2.Print();
	List<int> list_3(4, 7);
	//list_3 += list_1;
	List<int> list_4 = (list_3 + list_1);
	list_4.Print();
	List<int>::Iterator iy = list_4.end() - 1;
	iy--;
	std::cout<<" "<< *iy<<"\n";
	list_4.Sort();
	list_4.Print();
	return 0;
}