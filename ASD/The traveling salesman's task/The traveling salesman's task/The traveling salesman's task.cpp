#include<stdio.h>
#include<iostream>
#include<windows.h>

void OutputMatrD(int** matr, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++) printf("%7d", matr[i][j]);
		printf("\n");
	}
}

void OutMasPtr(int* a, int n)
{
	for (int* p = a; p < a + n; p++) printf("%d ", *p);
}

void Swap(int& a, int& b)
{
	int x;
	x = a; a = b; b = x;
}

void RandMatr(int** matr, int m, int n)
{
	srand(time(0));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) matr[i][j] = rand() % 20 + 1;
}

int MinWay(int* arr, int** matr, int n)
{
	int min = 0;
	int i;
	for (i = 0; i < n; i++)
		min += matr[arr[i] - 1][arr[i + 1] - 1];

	min += matr[arr[i] - 1][arr[0] - 1];
	return min;
}

bool Permutation(int n, int* arr)
{
	int i = n - 2;
	while (i != 0 && arr[i] >= arr[i + 1]) i--;
	if (i == 0) return false;
	int j = n - 1;
	while (arr[i] >= arr[j]) j--;

	Swap(arr[i], arr[j]);
	int k, l;

	for (k = i + 1, l = n - 1; i <= n / 2 && k < l; k++, l--)
		Swap(arr[k], arr[l]);
	return true;
}
void CopyMas(int* a, int* b, int n)
{
	for (int i = 0; i < n; i++) b[i] = a[i];
}

int Dijkstra(int const count_sity,int start_sity, int**Matr_Way_Weight,int *Min_Way)
{
	int *Way =new int[count_sity + 1];
	Way[0] = start_sity;
	Way[count_sity] = start_sity;
	int i, n;
	for (i = 1, n = 1; i < count_sity; n++)
		if (n != start_sity)
		{
			Way[i] = n;
			i++;
		}
	//OutMasPtr(Way, count_sity + 1);//вывод начального пути
	int MIN_Way_weight = MinWay(Way, Matr_Way_Weight, count_sity - 1);
	//cout << " " << MIN_Way_weight << endl;//вес
	//перестановки
	CopyMas(Way, Min_Way, count_sity + 1);
	while (Permutation(count_sity, Way))
	{
		//OutMasPtr(Way, count_sity + 1);//вывод перестановки
		int m_Way_weight = MinWay(Way, Matr_Way_Weight, count_sity - 1);
		//cout << " " << m_Way_weight << endl;//вывод длины пути
		if (m_Way_weight < MIN_Way_weight)
		{
			MIN_Way_weight = m_Way_weight;
			CopyMas(Way, Min_Way, count_sity + 1);
		}
	}
	delete[]Way;
	return MIN_Way_weight;
}



//bool Permutation_A(int n, int* arr)
//{
//	int i = 1;
//	while (i != n - 1 && arr[i] < arr[i + 1]) i++;
//	if (i == n - 1) return false;
//	int j = i + 1;
//	while (j != n && arr[i] < arr[j]) j++;
//
//	Swap(arr[i], arr[j]);
//	int k, l;
//
//	for (k = i + 1, l = n - 1; i <= n / 2 && k < l; k++, l--)
//		Swap(arr[k], arr[l]);
//	return true;
//}

using std::cout;
using std::cin;
using std::endl;

int main()
{
	setlocale(0, "");

	int** Matr_Way_Weight;
	int count_sity;//задаем количество городов
	int start_sity;//задаем начальный город
	cout << "Введите количество городов: ";
	cin >> count_sity;
	cout <<endl<< "Введите начальный город: ";
	cin >> start_sity;
	cout << endl;
	int i, j;
	Matr_Way_Weight = new int* [count_sity];
	for (int i = 0; i < count_sity; i++)
		Matr_Way_Weight[i] = new int[count_sity];
	RandMatr(Matr_Way_Weight, count_sity, count_sity);
	for (i = j = 0; i < count_sity; i++, j++)
		Matr_Way_Weight[i][j] = 0;
	OutputMatrD(Matr_Way_Weight, count_sity, count_sity);//вывод матрицы
	cout << endl;
	//задаем начальный путь
	int *Min_Way=new int [count_sity + 1];
	clock_t start = clock();
	int MIN_way_weight=Dijkstra(count_sity, start_sity, Matr_Way_Weight,Min_Way);
	clock_t end = clock();
	float seconds = (float)(end - start) / CLOCKS_PER_SEC;
	cout << "Кратчайший путь и его вес: ";
	OutMasPtr(Min_Way, count_sity + 1);
	cout << " " << MIN_way_weight << endl<< seconds<<endl;
	delete[]Min_Way;
	for (int i = 0; i < count_sity; i++)
		delete[]Matr_Way_Weight[i];
	delete[]Matr_Way_Weight;

	return 0;
}