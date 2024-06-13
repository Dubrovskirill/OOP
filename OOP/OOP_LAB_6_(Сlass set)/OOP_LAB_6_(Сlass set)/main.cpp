#include<iostream>
#include"Set.h"

int main()
{
	Set s_0;
	s_0.Print();
	char c[6] = { ' ','~', '7', 'f', 'o' };
	Set s_1(c);
	Set s_2(s_1);
	s_2.Print();
	std::cout << s_1 << s_0;
	Set s_3;
	std::cin >> s_3;
	s_0 = s_3+'1';
	s_0 += '~';
	s_0.Print();
	s_0 -= 'B';
	s_0 -= 'a';
	s_0.Print();

	Set foo;
	for (int i =0; i < Set::capacity; ++i) {
		std::cout << char(i + Set::offset) << ": " << foo.isPresent(i + Set::offset) << '\n';
		foo[i] = 1;
		std::cout << char(i + Set::offset) << ": " << foo.isPresent(i + Set::offset) << '\n';

	}
	
	return 0;
}