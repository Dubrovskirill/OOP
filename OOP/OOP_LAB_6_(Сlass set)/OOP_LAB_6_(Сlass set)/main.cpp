#include<iostream>
#include"Set.h"

int main()
{
	//std::cout<<"The set supports the following characters:"
	char c[3] = {' ','~'};
	Set s_1(c);
	Set s_2(s_1);
	s_2.Print();
	return 0;
}