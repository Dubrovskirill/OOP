#include<stdio.h>
#include<iostream>
#include<windows.h>
#include <chrono>

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

void Dijkstra(int const count_sity,int start_sity, int**Matr_Way_Weight,int *Min_Way,int *Max_Way, int &min_way_weight, int &max_way_weight)
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
	min_way_weight=max_way_weight = MinWay(Way, Matr_Way_Weight, count_sity - 1);
	//std::cout << " " << min_way_weight << std::endl;//вес
	//перестановки
	CopyMas(Way, Min_Way, count_sity + 1);
	while (Permutation(count_sity, Way))
	{
		//OutMasPtr(Way, count_sity + 1);//вывод перестановки
		int way_weight = MinWay(Way, Matr_Way_Weight, count_sity - 1);
		//std::cout << " " << way_weight << std::endl;//вывод длины пути
		if (way_weight < min_way_weight)
		{
			min_way_weight = way_weight;
			CopyMas(Way, Min_Way, count_sity + 1);
		}
		if (way_weight > max_way_weight)
		{
			max_way_weight = way_weight;
			CopyMas(Way, Max_Way, count_sity + 1);
		}
	}
	delete[]Way;
}

int Find_cols(int* a, int n, int D)
{
	for (int i = 1; i < n; i+=2)
		if (a[i] == D) return i;
	return -1;
}

bool Cycle(int r, int c, int* arr, int n)//проверка на цикл
{
	int i,j;
	for (i = 0, j = 1; i < n; i += 2, j += 2)
		if (arr[i] == c && arr[j] == r) return false;
	i = Find_cols(arr, n, r);
	while (i != -1)
	{
		if (arr[i - 1] == c) return false;
		i = Find_cols(arr, n, arr[i - 1]);
	}
	return true;
	
}

bool Exceptions(int* arr, int n, int r, int c)//исключение строк и столбцов
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
	for (int i = 0; i < count_sity; i++)
	{
		min_weight = 100;
		bool flag = true;
		for (r = 0; r < count_sity; r++)
			for (c = 0; c < count_sity; c++)
				if (r != c && Exceptions(way_data, n, r, c)  && Matr_Way_Weight[r][c] < min_weight)
				{
					if (i != count_sity-1)  flag = Cycle(r, c, way_data, n);
					if (flag)
					{
						row = r; coll = c;
						min_weight = Matr_Way_Weight[r][c];
					}
				}
		way_data[n] = row; way_data[n + 1] = coll;
		n += 2;
		//OutMasPtr(way_data, count_sity*2);
		//std::cout << " " << min_weight << std::endl;
	}
	/*OutMasPtr(way_data, count_sity * 2);
	std::cout << " " << min_weight << std::endl;*/
	int k = 0,i,j;
	
	for (j = 0; j < count_sity+1; j++)
	{
		for (i = 0; way_data[i] != start_sity; i += 2);

		Min_Way_H[k++] = way_data[i] + 1; 
		start_sity = way_data[i + 1];
	}
	//std::cout << std::endl;
	int weight = MinWay(Min_Way_H, Matr_Way_Weight, count_sity - 1);
	delete[]way_data;
	return weight;
}

float Percentag_Quality(int way_weight_h, int min_way_weight, int max_way_weight)
{
	float p; float a = way_weight_h - min_way_weight; float b = max_way_weight - min_way_weight;
	float d = a / b;
	return 100 - d * 100;
}
float Percentag_Speed(float time_h,float time)
{
	return  time / time_h * 100;

}

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	setlocale(0, "");

	

	int** Matr_Way_Weight;
	int count_sity;//задаем количество городов
	int start_sity;//задаем начальный город
	cout << "Количество городов: ";
	cin >> count_sity;
	cout <<endl<< "Начальный город: ";
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
	int *Max_Way = new int[count_sity + 1];
	int min_way_weight;
	int max_way_weight;

	auto start = std::chrono::high_resolution_clock::now();
	Dijkstra(count_sity, start_sity, Matr_Way_Weight,Min_Way,Max_Way,min_way_weight,max_way_weight);
	auto end = std::chrono::high_resolution_clock::now();
	float time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
	cout << "Наилучший путь и его вес: ";
	OutMasPtr(Min_Way, count_sity + 1);
	cout << " " << min_way_weight << endl;
	cout << "Наихудший путь и его вес: ";
	OutMasPtr(Max_Way, count_sity + 1);

	cout << " " << max_way_weight << endl << "Время работы: " << time <<" наносекунд"<< endl;
	delete[]Min_Way;
	delete[]Max_Way;
	//эвристика
	int* Min_Way_H = new int[count_sity+1];
	start = std::chrono::high_resolution_clock::now();
	int way_weight_h=Heuristics_1(count_sity, start_sity-1, Matr_Way_Weight, Min_Way_H);
	end = std::chrono::high_resolution_clock::now();
	float time_h = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
	cout << "Эвристическое решение; путь и его вес: ";
	OutMasPtr(Min_Way_H, count_sity + 1);
	cout << " " << way_weight_h << endl <<"Время работы: " << time_h<<" наносекунд" << endl;
	// отчет
	float perc_q = Percentag_Quality(way_weight_h,min_way_weight,max_way_weight);
	float perc_s = Percentag_Speed(time_h, time);
	cout << "Процент качества: "<<perc_q<<"%"<<endl<< "Процент скорости: " << perc_s << "%" << endl;
	
	delete[]Min_Way_H;
	for (int i = 0; i < count_sity; i++)
		delete[]Matr_Way_Weight[i];
	delete[]Matr_Way_Weight;

	return 0;
}