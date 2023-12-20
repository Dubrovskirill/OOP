#include<iostream>
#include"Set.h"

int main()
{
	//std::cout<<"The set supports the following characters:"
	char c[5] = {' ','~',' 7', 'f', 'o'};
	Set s_1(c);
	Set s_2(s_1);
	s_2.Print();
	std::cout << s_2.Weight();

	if (s_2.isPresent('0'))
		std::cout<<"ok";
	return 0;
}