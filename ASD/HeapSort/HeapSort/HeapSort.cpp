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

//bool CheckHeap(int* arr, int f, int l)
//{
//	int n = l - f + 1;
//	
//}

int main()
{
	const int size = 9;
	int arr[size] = { 6,42,55,12,4,32,24,5,12 };
	int count = 1;
	std::cout << count << ". ";
	count++;
	for (int i = 0; i < 9; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
	
	for (int n=size;n>1;n--)
	{
		for (int ind = n / 2 - 1; ind >= 0; ind--)
		{
			int a1 = 2 * ind + 1;
			int	a2 = 2 * ind + 2;
			if (a2 >= n) a2 = -1;
			if (a2 != -1)
			{
				if (arr[ind] < arr[a1] || arr[ind] < arr[a2])
				{
					if (arr[a1] >= arr[a2]) std::swap(arr[a1], arr[ind]);
					else std::swap(arr[a2], arr[ind]);
				}
			}
			else
			{
				if (arr[ind] < arr[a1])
				{
					std::swap(arr[a1], arr[ind]);
				}
			}
			std::cout << count << ". ";
			count++;
			for (int i = 0; i < 9; i++)
				std::cout << arr[i] << " ";
			std::cout << std::endl;
		}

		std::cout << std::endl;
		std::swap(arr[0], arr[n - 1]);
		for (int i = 0; i < 9; i++)
			std::cout << arr[i] << " ";
		std::cout << std::endl << std::endl;
	}
	std::cout << count << ". ";
	count++;
	for (int i = 0; i < 9; i++)
		std::cout << arr[i]<<" ";
	


	return 0;
}