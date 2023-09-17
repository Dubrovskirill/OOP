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
	//OutMasPtr(Way, count_sity + 1);//����� ���������� ����
	int MIN_Way_weight = MinWay(Way, Matr_Way_Weight, count_sity - 1);
	//cout << " " << MIN_Way_weight << endl;//���
	//������������
	CopyMas(Way, Min_Way, count_sity + 1);
	while (Permutation(count_sity, Way))
	{
		//OutMasPtr(Way, count_sity + 1);//����� ������������
		int m_Way_weight = MinWay(Way, Matr_Way_Weight, count_sity - 1);
		//cout << " " << m_Way_weight << endl;//����� ����� ����
		if (m_Way_weight < MIN_Way_weight)
		{
			MIN_Way_weight = m_Way_weight;
			CopyMas(Way, Min_Way, count_sity + 1);
		}
	}
	delete[]Way;
	return MIN_Way_weight;
}

bool �ycle(int r, int c, int* arr, int n)//�������� �� ����
{
	int f = 0,i,j;
	for ( i = 0, j = 1; i < n; i += 2, j += 2)
	{
		if (arr[i] == c && arr[j] == r) f = 0;
		else f = 1;
	}
	if (f) return true;
	for ( i = 0; i < n; i += 2)
		for ( j = 1; j < n; j += 2)
			if (arr[i] == c && arr[j] == r) return false;
	return true;
}

bool Exceptions(int* arr, int n, int r, int c)//���������� ����� � ��������
{
	int i;
	for (i = 0; i < n; i += 2)
		if (arr[i] == r || arr[i + 1] == c) return false;
	return true;
}

int Heuristics_1(int const count_sity, int start_sity, int** Matr_Way_Weight, int *Min_Way_H)
{
	int min_weight;
	int* way_data = new int[2 * count_sity];
	int n = 0, r, c;
	for (int i = 0; i < count_sity * 2; i++) way_data[i] = 0;
	int row = 0, coll = 0;
	for (int i = 0; i < count_sity - 1; i++)
	{
		min_weight = 100;
		for (r = 0; r < count_sity; r++)
			for (c = 0; c < count_sity; c++)
				if (r != c && Exceptions(way_data, n, r, c) && �ycle(r, c, way_data, n) && Matr_Way_Weight[r][c] < min_weight)
				{
					row = r; coll = c;
					min_weight = Matr_Way_Weight[r][c];
				}
		way_data[n] = row; way_data[n + 1] = coll;
		n += 2;
		OutMasPtr(way_data, count_sity*2);
		std::cout << " " << min_weight << std::endl;
	}
	min_weight = 100;
	for (r = 0; r < count_sity; r++)
		for (c = 0; c < count_sity; c++)
			if (r != c && Exceptions(way_data, n, r, c) && Matr_Way_Weight[r][c] < min_weight)
			{
				row = r; coll = c;
				min_weight = Matr_Way_Weight[r][c];
			}
	way_data[n] = row; way_data[n + 1] = coll;
	n += 2;
	OutMasPtr(way_data, count_sity * 2);
	std::cout << " " << min_weight << std::endl;
	int k = 0,i,j;
	
	for (j = 0; j < count_sity+1; j++)
	{
		for (i = 0; way_data[i] != start_sity; i += 2);

		Min_Way_H[k++] = way_data[i] + 1; 
		//std::cout << Min_Way_H[k]; 
		start_sity = way_data[i + 1];
	}
	std::cout << std::endl;
	int weight = MinWay(Min_Way_H, Matr_Way_Weight, count_sity - 1);
	delete[]way_data;
	return weight;
}
int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	setlocale(0, "");

	int** Matr_Way_Weight;
	int count_sity;//������ ���������� �������
	int start_sity;//������ ��������� �����
	cout << "������� ���������� �������: ";
	cin >> count_sity;
	cout <<endl<< "������� ��������� �����: ";
	cin >> start_sity;
	cout << endl;
	int i, j;
	Matr_Way_Weight = new int* [count_sity];
	for (int i = 0; i < count_sity; i++)
		Matr_Way_Weight[i] = new int[count_sity];
	RandMatr(Matr_Way_Weight, count_sity, count_sity);
	for (i = j = 0; i < count_sity; i++, j++)
		Matr_Way_Weight[i][j] = 0;
	OutputMatrD(Matr_Way_Weight, count_sity, count_sity);//����� �������
	cout << endl;
	//������ ��������� ����
	int *Min_Way=new int [count_sity + 1];
	clock_t start = clock();
	int MIN_way_weight=Dijkstra(count_sity, start_sity, Matr_Way_Weight,Min_Way);
	clock_t end = clock();
	float seconds = (float)(end - start) / CLOCKS_PER_SEC;
	cout << "���������� ���� � ��� ���: ";
	OutMasPtr(Min_Way, count_sity + 1);
	cout << " " << MIN_way_weight << endl<< seconds<<endl;
	delete[]Min_Way;
	//���������
	int* Min_Way_H = new int[count_sity+1];
	start = clock();
	int weight=Heuristics_1(count_sity, start_sity-1, Matr_Way_Weight, Min_Way_H);
	end = clock();
	seconds = (float)(end - start) / CLOCKS_PER_SEC;
	cout << "���������� ���� � ��� ���: ";
	cout << endl;
	OutMasPtr(Min_Way_H, count_sity + 1);
	cout << " " << weight << endl << seconds << endl;
	delete[]Min_Way_H;
	for (int i = 0; i < count_sity; i++)
		delete[]Matr_Way_Weight[i];
	delete[]Matr_Way_Weight;

	return 0;
}