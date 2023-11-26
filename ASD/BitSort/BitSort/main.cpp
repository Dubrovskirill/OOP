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

void Convert(std::vector<int>& vec)
{
	for (int k = 0; k < vec.size(); k++) 
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
		while (i <= j && (hb & vec[i]) != 0)
			i++;
		while (i <= j && (hb & vec[j]) == 0)
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

std::vector<int> Negative(std::vector<int>& vec)
{
	std::vector<int> negative;
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] < 0) {
			negative.push_back(vec[i]);
		}
	}
	return  negative;
}

std::vector<int> Positive(std::vector<int>& vec)
{
	std::vector<int> positive;
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] >= 0) {
			positive.push_back(vec[i]);
		}
	}
	return  positive;
}

void BitSort(std::vector<int>& vec)
{
	std::vector<int> negative = Negative(vec);
	Convert(negative);
	int right = negative.size()-1;
	int hb = HighBit(negative);
	DecrSort(negative,0,right,hb);
	Convert(negative);
	std::vector<int> positive = Positive(vec);
	right = positive.size()-1;
	hb = HighBit(positive);
	IncrSort(positive, 0, right, hb);

	vec = negative;
	for (int i=0; i<positive.size();i++)
		vec.push_back(positive[i]);
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