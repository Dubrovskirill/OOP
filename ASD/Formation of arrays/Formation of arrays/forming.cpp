#include<stdio.h>
#include<string>
#include<iostream>
#include<windows.h>
#include <chrono>
#include<random>
#include <fstream>
void Forming(int j, int size)
{
    std::random_device rd; // источник энтропии для генератора
    std::mt19937 gen(rd());// генератор случайных чисел
    long long randomNumber;
    std::string s = "arr_size_" + std::to_string(size)+"_in_range_" + std::to_string(j)+".txt";
    std::ofstream outputFile(s);
    if (outputFile.is_open())
    {
        for (int i = 0; i < size; i++)
        {
            std::uniform_int_distribution<long long> dis(-j, j);
            randomNumber = dis(gen);
            outputFile << randomNumber << " ";
        }
    }
    outputFile.close();
}
int main()
{
    for (int j = 10; j <= 100000; j *= 100)
    {
        for (int i = 0; i < 3; i++)
        {
            switch (i)
            {
            case 0:
                Forming(j, 10000);
                break;
            case 1:
                Forming(j, 100000);
                break;
            case 2:
                Forming(j, 1000000);
                break;
            default:
                break;
            }
        }
        }
	return 0;
}
