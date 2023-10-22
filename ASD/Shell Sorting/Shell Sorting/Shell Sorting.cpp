#include<stdio.h>
#include<string>
#include<iostream>
#include <chrono>
#include <fstream>
#include<vector>
#include<iterator>


void CheckSort(std::vector<int>& vec,const int &size)
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

void Insert(std::vector<int>& vec, const int& size, int h, int r)
{
	for (int i = h+r; i < size; i += h)
	{
		int key = vec[i];
		int j;
		for (j = i - h; j >= 0 && key < vec[j]; j -= h)
			vec[j + h] = vec[j];
		vec[j + h] = key;
	}
}

void Sort(std::vector<int>& vec, const int& size, std::vector<int>& step)
{
	for (int k = 0; k < step.size(); k++)
		for (int r = 0; r < step[k]; r++)
			Insert(vec, size, step[k], r);
}

void ShellStep(std::vector<int>& vec, const int& size)
{
	int s = size;
	while (s / 2 >= 1)
	{
		s /= 2;
		vec.push_back(s);
	}
}

void Shell(std::vector<int>& vec, const int& size)
{
	std::vector<int> step;
	ShellStep(step, size);
	Sort(vec, size, step);
}

void KnuthStep(std::vector<int>& vec, const int& size)
{
	int gap = 1;
	vec.insert(vec.begin(), gap);
	while (gap<size/3)
	{
		gap = gap * 3 + 1;
		vec.insert(vec.begin(), gap);
	}
}

void Knuth(std::vector<int>& vec, const int& size)
{
	std::vector<int> step;
	KnuthStep(step, size);
	Sort(vec, size, step);
}

void HibbardStep(std::vector<int>& vec, const int& size)
{
	int gap;
	int i = 1;
	int pow = 2;
	while(pow - 1< size)
	{
		gap = pow - 1;
		pow *= 2;
		vec.insert(vec.begin(), gap);
		i++;
	}
}

void Hibbard(std::vector<int>& vec, const int& size)
{
	std::vector<int> step;
	HibbardStep(step, size);
	Sort(vec, size, step);
}

void Input(int j, int i, std::vector<int>& vector)
{
	std::string s = "arr_size_" + std::to_string(i) + "_in_range_" + std::to_string(j) + ".txt";
	std::ifstream inputFile(s);
	if (inputFile.is_open())
	{
		int num;
		while (inputFile >> num)
			vector.push_back(num);
	}
	else std::cout << "File opening error!\n";
	inputFile.close();
}

void CoutCurAlg(int f)
{
	using std::cout;
	using std::cin;
	using std::endl;
	switch (f)
	{
	case 0:
		cout << "Shell" << endl;
		break;
	case 1:
		cout << "Knuth" << endl;
		break;
	case 2:
		cout << "Hibbard" << endl;
		break;
	default:
		break;
	}
}

void CurAlg(int f, std::vector<int>& vec, const int& size)
{
	switch (f)
	{
	case 0:
		Shell(vec, size);
		break;
	case 1:
		Knuth(vec, size);
		break;
	case 2:
		Hibbard(vec, size);
		break;
	default:
		break;
	}
}


int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	
	for (int f = 0; f < 3; f++)
	{
		CoutCurAlg(f);
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
					CurAlg(f, vector, size);
					auto end = std::chrono::high_resolution_clock::now();
					time[t] = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
					cout << "size: " << i << " range: " << j << " time: " << time[t] << " ms"<< endl;
					CheckSort(vector, size);
					avti += time[t];
				}
				avti /= 3;
				cout << "Average time: " << avti << " ms" << "\n----------------------\n";

			}
		}
	}
	return 0;
 }