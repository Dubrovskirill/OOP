#include<stdio.h>
#include<string>
#include<iostream>
#include <chrono>
#include <fstream>
#include<vector>
#include<iterator>

void CheckSort(std::vector<int>& vec)
{
	for (int i = 1; i < vec.size(); i++)
	{
		if (vec[i - 1] > vec[i])
		{
			std::cout << ("Error::The array is not sorted");
			break;
		}
	}
}

int HighBit( const std::vector<int>& vec, int left, int right) 
{
	int bit = 1;
	int count = 0;
	int max = INT_MIN;
	for (int i = left; i <=right; i++)
		if (max < vec[i])
			max = vec[i];

	while (max)
	{
		max >>= 1;
		bit <<= 1;
	}
	//bit >>= 1;
	return bit;
}

void Convert(std::vector<int>& vec, int border)
{
	for (int k = 0; k <= border; k++) 
			vec[k] = ~vec[k]+1;
}

void IncrSort(std::vector<int>& vec, int left, int right, int hb)
{
	if (left >= right || hb == 0)
		return;

	int i = left, j = right;
	while (i <= j)
	{
		while (i <= j && (hb & vec[i]) == 0)
			i++;
		while (i <= j && (hb & vec[j]) != 0)
			j--;
		if (i < j)
		{
			std::swap(vec[i], vec[j]);
			i++; j--;
		}
	}
	IncrSort(vec, left, j, hb >> 1);
	IncrSort(vec, i, right, hb >> 1);
}

void DecrSort(std::vector<int>& vec, int left,int right, int hb) 
{
	if (left >= right || hb == 0)
		return;

	int i = left, j = right;
	while (i <= j)
	{
		while (i <= j && (hb & vec[i]) == 0)
			i++;
		while (i <= j && (hb & vec[j]) != 0)
			j--;
		if (i < j)
		{
			std::swap(vec[i], vec[j]);
			i++; j--;
		}
	}
	DecrSort(vec, left, j, hb >> 1);
	DecrSort(vec, i, right, hb >> 1);
}

int Prep(std::vector<int>& vec)
{
	int i = 0, j = vec.size()-1, x = 0;
	while (i <= j)
	{
		while (vec[i] < x)
			i++;
		while (vec[j] >= x)
			j--;
		if (i <= j)
		{
			std::swap(vec[i], vec[j]);
			i++;
			j--;
		}
	}

	return j;
}

void BitSort(std::vector<int>& vec)
{
	int border = Prep(vec);
	int h = HighBit(vec, 0, vec.size() - 1);
	IncrSort(vec, 0, border, h);
	IncrSort(vec, border + 1, vec.size() - 1, h);
}

void Input(int j, int i, std::vector<int>& vector)
{
	std::string s = "arr_size_" + std::to_string(i) + "_in_range_" + std::to_string(j) + ".txt";
	std::string path = "../../../../";
	std::ifstream inputFile(path + s);
	if (inputFile.is_open())
	{
		int num;
		while (inputFile >> num)
			vector.push_back(num);
	}
	else std::cout << "File opening error!\n";
	inputFile.close();
}

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	int count = 1;
	for (int j = 10; j <= 100000; j *= 100)
	{
		for (int i = 10000; i <= 1000000; i *= 10)
		{
			float time[3];
			float avti = 0;
			cout << count << ". " << endl;
			count += 1;
			for (int t = 0; t < 3; t++)
			{
				std::vector<int>vector;
				Input(j, i, vector);
				auto start = std::chrono::high_resolution_clock::now();
				BitSort(vector);
				auto end = std::chrono::high_resolution_clock::now();
				time[t] = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
				cout << "size: " << i << " range: " << j << " time: " << time[t] << " ms" << endl;
				CheckSort(vector);
				avti += time[t];
			}
			avti /= 3;
			cout << "Average time: " << avti << " ms" << "\n----------------------\n";
		}
	}

	return 0;
}