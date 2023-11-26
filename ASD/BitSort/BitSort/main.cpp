#include<stdio.h>
#include<string>
#include<iostream>
#include <chrono>
#include <fstream>
#include<vector>
#include<iterator>

void CheckSort(std::vector<int>& vec, const int& size)
{
	for (int i = 1; i < size; i++)
	{
		if (vec[i - 1] > vec[i])
		{
			std::cout << ("Error::The array is not sorted");
			break;
		}
	}
}

int HighBit(std::vector<int>& vec)
{
	int max = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		int num = vec[i];
		int bit = 1;
		while (num)
		{
			num >>= 1;
			bit <<= 1;
		}
		bit >>= 1;
		if (max < bit)
			max = bit;
	}
	return max;
}

void BitSort(std::vector<int>& vec, int left=0, int right = -1, int hb= -2)
{
	if (right==-1)
		right = vec.size()-1;
	if (hb == -2)
		hb = HighBit(vec);
	if (left >= right || hb == -1)
		return;

	int i = left, j = right;
	while (i <= j)
	{
		while (i <= j && (hb & vec[i]) == 0)
			i++;
		while (i <= j && (hb & vec[j]) == hb)
			j--;
		if (i < j)
		{
			std::swap(vec[i], vec[j]);
			i++; j--;
		}
		if (hb==0)
			hb = -1;
		BitSort(vec, left, j, hb>>1);
		BitSort(vec, i, right, hb>>1);
	}
}

int main()
{

	std::vector<int> vec = { 3, 4, 1, 64, 865, 12, 34, 1,0 };
	for(int i=0;i<vec.size();i++)
		std::cout << vec[i]<<" ";
	std::cout << std::endl;

	BitSort(vec);

	for (int i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	
	return 0;
}