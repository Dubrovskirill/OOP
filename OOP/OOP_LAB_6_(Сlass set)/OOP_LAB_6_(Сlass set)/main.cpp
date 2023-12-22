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
	/*std::cout << s_1.BoolVector::Weight()<<std::endl;
	std::cout << s_1.Set::Weight();*/

	//std::cout<<"The set supports the following characters:"
	/*Set s_0;
	s_0.Print();
	char c[6] = {' ','~',' 7', 'f', 'o'};
	Set s_1(c);
	s_1.Print();
	
	if(!s_1.isEmpty())
		std::cout << s_1.Weight();*/
	
	//Set s_2(s_1);
	////s_2.Print();
	//std::cout << std::endl;
	//std::cout << s_2.Weight();
	//std::cout << std::endl;
	//if (s_2.isPresent('0'))
	//	std::cout<<"ok";
	//Set s_3;
	//if (s_2.isEmpty())
	//	std::cout << "ok";
	//s_3.Print();
	//s_2.Print();
	//std::cout << s_2;
	////std::cout << s_3;
	return 0;
}