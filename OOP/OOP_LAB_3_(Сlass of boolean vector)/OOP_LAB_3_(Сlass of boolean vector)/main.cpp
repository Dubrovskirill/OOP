#include<iostream>
#include "BoolVector.h"
#include"assert.h"
int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	BoolVector bvec_1;
	cout << "bvec_1: "; bvec_1.Print();
	BoolVector bvec_2(19, 1);
	cout << "bvec_2: "; bvec_2.Print();
	cout << endl;

	BoolVector bvec_3 = "10111";
	cout << "bvec_3: "; bvec_3.Print();
	cout << endl;

	bvec_1.Swap(bvec_2);
	cout << "bvec_1: "; bvec_1.Print();
	cout << "bvec_2: "; bvec_2.Print();
	cout << endl;

	BoolVector bvec_4(bvec_3);
	cout << "bvec_4: "; bvec_4.Print();
	cout << endl;
	return 0;
}