#include<iostream>
#include "../../../OOP/OOP_LAB_4_(Ñlass of boolean matrix)/BoolMatrix/BoolMatrix.h"
#include "../../../OOP/OOP_LAB_5_(Ñlass list)/OOP_LAB_5_(Ñlass list)/List.h"
#include "../../../OOP/OOP_LAB_2/OOP_LAB_2/Array.h"
Array<int> TSortMatr(BoolMatrix& matrix)
{
	int n = matrix.Rows();
	Array<int> answer(n, 0);
	BoolVector exp(n, 0);
	int k = 0;
	while (!exp.Full())
	{
		BoolVector mask(n, 0);
		//std::cout << mask << std::endl;
		for (int i = 0; i < n; i++)
		{
			mask |= matrix[i];
			if (exp[i])
				mask[i] = exp[i];
			//std::cout << mask << std::endl;
		}

		//std::cout << mask << std::endl;
		//std::cout << std::endl;
		if (mask.Full())
		{
			std::cout << "!!!CYCLE!!!"<<std::endl;
			return answer;
		}
		mask = ~mask;
		

		for (int i = 0; i < n; i++)
			if (mask[i])
				exp[i] = mask[i];
		//std::cout << exp << std::endl;
		//std::cout << std::endl;
		BoolVector mask2(n, 1);

		for (int i = 0; i < n; i++)
			if ((mask[i] & mask2[i]) == 1)
			{
				answer[k++] = i + 1;
				mask2 >>= 1;
			}
		for (int j = 0; j < n; j++)
			for (int i = 0; i < k; i++)
				matrix[answer[i] - 1][j] = 0;
	}
	return answer;
}
int main()
{
	int n = 4;
	BoolMatrix Test(n, n, 0);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			std::cin >> Test[i][j];
	Array<int> answer(TSortMatr(Test));

	for (int i = 0; i < n; i++)
		std::cout << answer[i] << " ";
	std::cout << std::endl;
}