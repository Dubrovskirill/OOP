#include<stdio.h>
#include<string>
#include<iostream>
#include <chrono>
#include <fstream>
#include<vector>
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

void StandartStep(std::vector<int>* vec, const int& size)
{
	int s = size;
	while (s / 2 >= 1)
	{
		s /= 2;
		vec->push_back(s);
	}
}

void ShellSort(std::vector<int>& vec, const int& size)
{
	std::vector<int> step;
	StandartStep(&step, size);
	for (int k = 0; k < step.size(); k++)
		for (int r = 0; r < step[k]; r++)
			Insert(vec, size, step[k], r);

}




int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	std::vector<int>vector;
	std::ifstream inputFile("example.txt");
	if (inputFile.is_open()) 
	{
		int num;
		while (inputFile>>num) 
			vector.push_back(num);
	}
	else cout << "File opening error!\n";
	inputFile.close();
	for (int i = 0; i < vector.size(); i++)
		cout << vector[i] << " ";
	const int size = vector.size();
	
	ShellSort(vector, size);
	CheckSort(vector, size);

	cout << endl;
	for (int i = 0; i < vector.size(); i++)
		cout << vector[i] << " ";
	
	
	return 0;
 }