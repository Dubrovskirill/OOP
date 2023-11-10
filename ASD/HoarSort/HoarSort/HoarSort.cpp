#include<stdio.h>
#include<string>
#include<iostream>
#include <chrono>
#include <fstream>
#include<vector>
#include<iterator>

bool CheckSort(std::vector<int>& vec, const int& size)
{
	for (int i = 1; i < size; i++)
	{
		if (vec[i - 1] > vec[i])
		{
			return false;
		}
	}

	return true;
}

void HoarSort(std::vector<int>& vec,const int left, const int right)
{
	if (left >= right) return; 
	int i = left, j = right, x = vec[(left + right) / 2];
	while (i <= j)
	{
		while (vec[i] < x)
			i++;
		while (vec[j] > x)
			j--;
		if (i <= j)
		{
			std::swap(vec[i], vec[j]);
			i++;
			j--;
		}
	}
	HoarSort(vec, left, j);
	HoarSort(vec, i, right);
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
				const int size = vector.size();
				auto start = std::chrono::high_resolution_clock::now();
				HoarSort(vector,0, size-1);
				auto end = std::chrono::high_resolution_clock::now();
				time[t] = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
				cout << "size: " << i << " range: " << j << " time: " << time[t] << " ms" << endl;
				CheckSort(vector, size);
				avti += time[t];
			}
			avti /= 3;
			cout << "Average time: " << avti << " ms" << "\n----------------------\n";

		}
	}


	return 0;
}