#include<stdio.h>
#include<iostream>
int BMsearchALL(std::string text, std::string substring)
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
		for (k = i, j = l_substring - 1; j >= 0 && text[k] == substring[j]; k--, j--);
	}
	if (i >= l_text && j < 0) return k + 1;
	else return 100;
}
int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	using std::string;
	string text = "std::move_iterator is an iterator adaptor which behaves exactly like the underlying iterator";
	string substring = "ke";
	cout << text << endl << substring << endl;
	cout << BMsearchALL(text, substring);


	return 0;
}