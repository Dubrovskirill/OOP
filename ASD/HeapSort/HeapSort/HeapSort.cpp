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

void Heap(std::vector<int>& vec, const int& n,const int &ind)
{
	int l = ind;
	int ch1 = 2 * ind + 1; 
	int ch2 = 2 * ind + 2;
	if (ch1<n && vec[ch1]>vec[l])
		l = ch1;
	if (ch2<n && vec[ch2]>vec[l])
		l = ch2;
	if (l != ind)
	{
		std::swap(vec[l], vec[ind]);
		Heap(vec, n, l);
	}
}

void HeapSort(std::vector<int>& vec, const int size)
{
	for (int i = size / 2 - 1; i >= 0; i--)
		Heap(vec, size, i);

	for (int n = size - 1; n >= 0; n--)
	{
		std::swap(vec[0], vec[n]);
		Heap(vec, n, 0);
	}

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
				HeapSort(vector, size);
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