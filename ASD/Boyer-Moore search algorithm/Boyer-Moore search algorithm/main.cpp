#include<stdio.h>
#include<iostream>

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


int BMsearch(std::string text, std::string substring)
{
	int const l_text = text.length();
	int const l_substring = substring.length();
	int TAB[256];
	int i,j, k;
	for (i = 0; i < l_text; i++) TAB[text[i]] = l_substring;
	for (j = 0; j < l_substring - 1; j++) TAB[substring[j]] = l_substring - 1 - j;

	for (i = l_substring - 1, j = l_substring - 1; i <= l_text; i = k + TAB[text[k]])
	{
		if (j < 0) return k+1;
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

int BMsearchAll(std::string text, std::string substring, int *Occurrence)
{
	std::string t = text;
	int i = 0;
	int occ = BMsearch(t,substring);
	if (occ == -1) return -1;
	int sourse_i = 0;
	while (occ != -1)
	{
		Occurrence[i] = occ+ sourse_i;
		i++;
		t = ShiftStringLeft(t, occ+1);
		sourse_i += occ+1;
		occ = BMsearch(t, substring);
	}
	return i;
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
	if (first_occurrence == -1) cout << "There is no such substring in the string";
	else cout << "Index of the first occurrence: " << first_occurrence<<endl;
	//cout << ShiftStringLeft(text, 50);
	int *Occurrence=new int[text.length()];
	int size_arr = BMsearchAll(text, substring, Occurrence);
	if (size_arr == -1) cout << "There is no such substring in the string";
	else cout << "Indexes of each occurrence: ";
	OutputArr(Occurrence, size_arr);
	cout << endl;
	delete[]Occurrence;


	return 0;
}