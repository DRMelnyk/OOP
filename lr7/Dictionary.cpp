#include "Dictionary.h"
#include <iomanip>

Dictionary::Dictionary(ifstream& in) 
{
	in >> eng >> rus;
}

void Dictionary::set() 
{
	cout << "Add the word: ";
	cin >> eng;
	cout << "Add the translation: ";
	cin >> rus;
}

void Dictionary::show() 
{
	cout << eng << " \t--> " << rus;
}