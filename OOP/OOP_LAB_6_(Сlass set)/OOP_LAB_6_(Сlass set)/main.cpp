#include<iostream>
#include"Set.h"

int main()
{
	Set s_0;
	s_0.Print();
	char c[6] = { ' ','~',' 7', 'f', 'o' };
	Set s_1(c);
	Set s_2(s_1);
	s_2.Print();
	std::cout << s_1<<s_0;
	Set s_3;
	std::cin >> s_3;
	s_3.Print();
	if (s_3 != s_2)
	{
		std::cout<<"Bimbim";
	}
	s_0 = s_3;
	s_0.Print();
	if (s_3 == s_0)
	{
		std::cout << "BamBam";
	}
	return 0;
}