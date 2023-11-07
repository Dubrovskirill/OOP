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
	bvec_4.Inverse();
	cout << "bvec_4: "<<bvec_4; 
	cout << endl;

	cout << "bvec_1: ";
	for(int i=0;i<24;i++)
		cout << bvec_1[i];
	cout <<endl<< bvec_1;
	bvec_1.Inverse();
	cout << bvec_1;
	cout << endl;

	bvec_1 = "101110011101001111";
	cout << bvec_1<<"&\n";
	bvec_2 = "1100101001";
	cout << bvec_2<<"=\n";
	bvec_3 = bvec_1 & bvec_2;
	cout << bvec_3<<endl;
	bvec_1 &= bvec_2;
	cout << bvec_1;
	cout << endl;

	bvec_1 = "101110011101001111";
	cout << bvec_1 << "|\n";
	cout << bvec_2 << "=\n";
	bvec_3 = bvec_1 | bvec_2;
	cout << bvec_3 << endl;
	bvec_1 |= bvec_2;
	cout << bvec_1;
	cout << endl;

	bvec_1 = "101110011101001111";
	cout << bvec_1 << "^\n";
	cout << bvec_2 << "=\n";
	bvec_3 = bvec_1 ^ bvec_2;
	cout << bvec_3 << endl;
	bvec_1 ^= bvec_2;
	cout << bvec_1;
	cout << endl;

	cout << ~bvec_1;
	cout << endl;

	BoolVector bvec_5 = "111110111101001111110101010101010100001111010001001010111101";
	cout << bvec_5;
	cout << (bvec_5<<35);
	bvec_5 <<= 35;
	cout << bvec_5;
	cout << endl;

	bvec_5 = "111110111101001111110101010101010100001111010001001010111101";
	cout << bvec_5;
	cout << (bvec_5 >> 35);
	bvec_5 >>= 35;
	cout << bvec_5;
	cout << endl;

	bvec_5 = "1011101";
	cout << bvec_5;
	cout << (bvec_5 << 35);
	cout << (bvec_5 << 5);
	cout << (bvec_5 >> 5);
	cout << endl;

	BoolVector bvec_6 = "0000010";

	cout << bvec_6;

	cout << bvec_6[0]<<endl;
    //cin >> bvec_6[1];
	//cout << bvec_6;
	int n = 32; bvec_6[2] = n; cout << bvec_6;
	bool b = 1; bvec_6[1] = b; cout << bvec_6;
	if (bvec_6[2] == bvec_6[1])
		cout << "GG"<<endl;

	bvec_6[1] = 1;
	if (bvec_6[0] != bvec_6[1])
		cout << "GG" << endl;
	bvec_6[0]=bvec_6[1]& bvec_6[2];
	cout << bvec_6;
	bvec_6[0] &= 0;
	cout << bvec_6;

	cout << endl;
	bvec_6[0] = 0; bvec_6[1] = 0;
	cout << bvec_6;
	bvec_6[0] = bvec_6[1] | bvec_6[2];
	cout << bvec_6;
	bvec_6[1] |= 1;
	cout << bvec_6;
	cout << ~bvec_6[0];
	cout << endl;
	cout << (bvec_6[0] ^ bvec_1[0])<<endl;
	if(bvec_6[0]>=bvec_6[0])
		cout << "GG" << endl;
	cout << bvec_6.Weight();
	bvec_6.Inverse(1);
	cout << bvec_6;
	bvec_6.Set1(3, 55);
	cout << bvec_6;
	bvec_6.Set0(0, 55);
	cout << bvec_6;

	bvec_6.Set1();
	cout << bvec_6;
	bvec_6.Set0();
	cout << bvec_6;
	for (int i = 0; i < 8; i++)
	{
		cin >> bvec_6[i];
	}
	for (int i = 0; i < 8; i++)
	{
		cout<< bvec_6[i]<<" ";
	}
	return 0;
}