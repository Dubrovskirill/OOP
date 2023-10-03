#include<stdio.h>
#include<iostream>
#include<vector>

int *CreateTAB(std::string text, std::string substring)
{
	int l_text = text.length();
	int l_substring = substring.length();
	int *TAB = new int[256];
	int i, j, k = 0;
	for (i = 0; i < l_text; i++) TAB[text[i]] = l_substring;
	for (j = 0; j < l_substring - 1; j++) TAB[substring[j]] = l_substring - 1 - j;
	return TAB;
}

int Search(std::string text, std::string substring, int *TAB, int first = 0, int l_text = -1)
{
	if (l_text < 0)  l_text = text.length();
	int l_substring = substring.length();
	int i, j, k = 0;

	for (i = first + l_substring - 1, j = l_substring - 1; i <= l_text; i = k + TAB[text[k]])
	{
		if (j < 0) return k + 1;
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

int BMsearch(std::string text, std::string substring)
{
	int *TAB = CreateTAB(text,substring);
	int occ= Search(text, substring, TAB);
	delete[]TAB;
	return occ;

}

std::vector<int> BMsearchAllRange(std::string text, std::string substring,int first, int last)
{
	std::vector<int> Occurrence;
	int* TAB = CreateTAB(text, substring);
	int i = 0;
	int occ = Search(text, substring,TAB, first,last);
	if (occ == -1) return Occurrence;
	while (occ != -1)
	{
		Occurrence.push_back(occ);
		first = occ+1;
		occ = Search(text, substring,TAB, first, last);
	}
	delete[]TAB;
	return Occurrence;
}

std::vector<int> BMsearchAll(std::string text, std::string substring)
{
	return BMsearchAllRange(text, substring, 0, text.length());
}

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	using std::string;
	string text = "std::move_iterator is an iterator adaptor which behaves exactly like the underlying iterator";
	text = "orem ipsum dolor sit amet, consectetur adipiscing elit. Sed commodo urna at malesuada sagittis. Nulla consequat risus et lacinia sagittis. Aliquam interdum nisl ut purus consectetur tincidunt. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia curae; Phasellus dictum magna a massa tincidunt, in semper sem pharetra. Sed nec quam vitae mi pharetra consequat. Proin auctor turpis ut ipsum condimentum, nec blandit metus ultrices. Maecenas viverra, lectus eu rutrum rhoncus, velit erat dignissim lectus, vitae vulputate nunc odio sed lorem. Donec volutpat, nulla sed facilisis lobortis, arcu justo mattis est, a rutrum mi ex nec elit. Suspendisse molestie massa et feugiat pretium. Fusce eu arcu vel mi lacinia euismod vel eu eros. Maecenas tortor felis, rutrum id diam sed, congue semper eros. Vestibulum congue est sed mauris gravida, ut tincidunt nisl iaculis. Vivamus non lobortis urna, vitae vestibulum orci. Nulla vitae ex risus. Morbi faucibus a lorem et ornare.Vestibulum laoreet justo id velit fringilla, vitae tincidunt dolor tristique.Curabitur facilisis, est a tempus fringilla, mi ipsum imperdiet lectus, id accumsan eros enim a enim.Sed bibendum purus non mattis auctor.Quisque pretium iaculis nulla.Ut blandit leo quis mauris luctus maximus.Proin faucibus dolor vel turpis eleifend maximus.Suspendisse malesuada nunc sapien, eget fringilla sapien interdum interdum.Nam at neque mauris.Nulla facilisi.blandit elementum dolor, a feugiat odio tristique sed.Mauris a aliquam orci.Fusce vulputate nec metus sit amet semper.Nulla facilisi.Aliquam in risus vitae justo malesuada porta.Phasellus bibendum bibendum enim, sed aliquet enim facilisis vel.Fusce sed felis nisl.Nunc fermentum, lectus eu interdum ullamcorper, erat nisl fringilla velit, in accumsan dolor massa sit amet odio.Vestibulum volutpat massa nec elit eleifend, ut ullamcorper lectus pretium.Cras ut facilisis odio.Sed fringilla justo non lectus ullamcorper, non fringilla eros scelerisque.Mauris feugiat semper tellus, ac hendrerit velit pulvinar sit ameto";
	string substring = "o";
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