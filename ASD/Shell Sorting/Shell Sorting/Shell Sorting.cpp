#include<stdio.h>
#include<string>
#include<iostream>
#include <chrono>
#include <fstream>
void Insert(int * array,int size, int h, int r)
{
	for (int i = h+r; i < size; i += h)
	{
		int key = array[i];
		int j;
		for (j = i - h; key < array[j] && j >= 0; j -= h) array[j + h] = array[j];
		array[j + h] = key;
	}
}
void ShellSort(int *array,const int size)
{
	const int s = 3;
	int h[s] = { 5,2,1 };
	for (int k = 0; k < 3; k++)
		for (int r = 0; r < h[k]; r++)
			Insert(array, size, h[k], r);
}


int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	const int size = 20;
	int array[size] = { 64,34,75,87,64,5,432,467,52,34,7,4,1,5,564,32,56,2,54, 87 };
	for (int i = 0; i < size; i++)
		cout << array[i] << " ";
	cout << endl;
	ShellSort(array, size);
	for (int i = 0; i < size; i++)
		cout << array[i] << " ";
	cout << endl;
	
	return 0;
 }