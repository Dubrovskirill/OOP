#include<stdio.h>
#include<iostream>
#include<vector>

void OutputArr(int* a, int n)
{
	for (int* p = a; p < a + n; p++) printf("%d ", *p);
}

std::string ShiftStringLeft(std::string s, int i)
{
	int j,k;
	for (j = 0; j < i; j++)
	{
		
		k = 0;
		for (; s[k]; k++) s[k] = s[k + 1];
	}
	return s;
}


int BMsearch(std::string text, std::string substring, int first=0, int l_text=-1)
{
	if(l_text<0)  l_text = text.length();
	//else int const l_text = last;
	int l_substring = substring.length();
	int TAB[256];
	int i,j, k=0;
	for (i = first; i < l_text; i++) TAB[text[i]] = l_substring;
	for (j = 0; j < l_substring - 1; j++) TAB[substring[j]] = l_substring - 1 - j;

	for (i = first+ l_substring - 1, j = l_substring - 1; i <= l_text; i = k + TAB[text[k]])
	{
		if (j < 0) return k+1;
		if (k >= l_text) return -1;
		for (k = i, j = l_substring - 1; j >= 0 && text[k] == substring[j]; )
		{
			k--;
			j--;
			if (k < 0) return 0;
		}
	}
	if (i >= l_text && j < 0) return k + 1;
	else return -1;
}
std::vector<int> BMsearchAllRange(std::string text, std::string substring,int first, int last)
{
	std::vector<int> Occurrence;
	int i = 0;
	int occ = BMsearch(text, substring,first,last);
	if (occ == -1) return Occurrence;
	while (occ != -1)
	{
		Occurrence.push_back(occ);
		first = occ+1;
		occ = BMsearch(text, substring, first, last);
	}
	return Occurrence;
}

std::vector<int> BMsearchAll(std::string text, std::string substring)
{
	/*std::string t = text;
	std::vector<int> Occurrence;
	int i = 0;
	int occ = BMsearch(t,substring);
	if (occ == -1) return Occurrence;
	int sourse_i = 0;
	while (occ != -1)
	{
		Occurrence.push_back(occ+sourse_i);
		t = ShiftStringLeft(t, occ+1);
		sourse_i += occ+1;
		occ = BMsearch(t, substring);
	}*/
	return BMsearchAllRange(text, substring, 0, text.length());
}

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	using std::string;
	string text = "std::move_iterator is an iterator adaptor which behaves exactly like the underlying iterator";
	string substring = "tor";
	cout <<"STRING: "<< text << endl << "It's length: " <<text.length() << endl << "SUBSTRING: " << substring << endl;
	int first_occurrence = BMsearch(text, substring);
	if (first_occurrence == -1) cout << "There is no such substring in the string" << endl;
	else cout << "Index of the first occurrence: " << first_occurrence<<endl;
	
	std::vector<int> Occurrence = BMsearchAll(text, substring);
	if (Occurrence.size()==0) cout << "There is no such substring in the string";
	else
	{
		cout << "Indexes of each occurrence: ";
		for (auto& vector : Occurrence) cout << vector << " ";
	}
	cout << endl;
	Occurrence = BMsearchAllRange(text, substring,17,36);
	if (Occurrence.size() == 0) cout << "There is no such substring in the string";
	else
	{
		cout << "Indexes of each occurrence in range: ";
		for (auto& vector : Occurrence) cout << vector << " ";
	}
	cout << endl;

	return 0;
}