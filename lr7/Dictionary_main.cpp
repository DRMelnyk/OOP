#include <iostream>
#include <fstream>
#include <Windows.h>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <conio.h>
#include "Dictionary.h"

using namespace std;

void load(vector<Dictionary>& ); //перепис файлу у вектор
void save(vector<Dictionary>& ); //збереження словника на диску
bool srteng(Dictionary&, Dictionary&); //сортування по англійськії мові
bool srtrus(Dictionary& , Dictionary&); //сортування по російській мові
bool srtlength(Dictionary& , Dictionary&); //сортування по довжині слів
void show5(vector<Dictionary>& ); //функция для вывода топ-5 по длиннеангл слов

int main() 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	vector<Dictionary> dict;
	load(dict);

	char ch = '9';
	size_t choise = 0;

	while (ch != '0') 
	{
		system("cls");
		cout << "\tENGLISH DICTIONARY"<<endl;
		if (!dict.empty()) 
		{
			cout << "  #| English --> Russian";
			for (size_t i = 0; i < dict.size(); i++) {
				cout << endl << setw(3) << i << ") ";
				dict[i].show();
			}
		}
		else {
			cout << "\nThe dictionary is empty.";
		}
		cout << endl
			<< endl << "> 1 -> Add the word"
			<< endl << "> 2 -> Remove the word"
			<< endl << "> 3 -> Sort in English"
			<< endl << "> 4 -> Sort in Russian"
			<< endl << "> 5 -> Five longest words"
			<< endl << "> 0 -> Exit"
			<< endl << ">> ";
		ch = _getch();
		switch (ch)
		{
		case '1':
		{
			Dictionary card_;
			card_.set();
			dict.push_back(card_);
		}
		break;
		case '2':
			if (!dict.empty()) 
			{
				cout << endl << "Add the number to remove: ";
				while (!(cin >> choise) || choise < 0 || choise >= dict.size()) 
				{
					cin.clear();
					cin.ignore(100, '\n');
					cout << endl << "Try again.";
				}
				dict.erase(dict.begin() + choise);
			}
			else 
			{
				cout << endl << "The list is empty" << endl;
				system("pause");
			}
			break;
		case '3':
			if (!dict.empty()) 
			{
				sort(dict.begin(), dict.end(), srteng);
				cout << endl << "Sorted in English successfully." << endl;
			}
			else 
			{
				cout << endl << "The list is empty" << endl;
			}
			system("pause");
			break;
		case '4':
			if (!dict.empty()) 
			{
				sort(dict.begin(), dict.end(), srtrus);
				cout << endl << "Sorted in Russian successfully." << endl;
			}
			else 
			{
				cout << endl << "The list is empty" << endl;
			}
			system("pause");
			break;
		case '5':
			if (!dict.empty()) 
			{
				show5(dict);
			}
			else {
				cout << endl << "The list is empty" << endl;
			}
			system("pause");
			break;
		case '0':
			save(dict);
			break;
		}
	}
	return 0;
}

void load(vector<Dictionary>& card) 
{
	ifstream file("Dictionary.txt", ios_base::in);
	if (file.is_open()) {
		while (!file.eof()) {
			Dictionary buff(file);
			card.push_back(buff);
		}
	}
}
void save(vector<Dictionary>& card) 
{
	ofstream ofile("Dictionary.txt", ios_base::trunc);
	if (!card.empty()) {
		for (size_t i = 0; i < card.size(); i++) {
			ofile << card[i].reteng() << " " << card[i].retrus();
			if (i + 1 < card.size()) {
				ofile << endl;
			}
		}
	}
}
bool srteng(Dictionary& c1, Dictionary& c2) 
{
	return c1.reteng() < c2.reteng();
}
bool srtrus(Dictionary& c1, Dictionary& c2) 
{
	return c1.retrus() < c2.retrus();
}

bool srtlength(Dictionary& c1, Dictionary& c2) 
{
	return c1.retleng() > c2.retleng();
}
void show5(vector<Dictionary>& card) 
{
	if (card.size() > 5) {
		vector<Dictionary> buff = card;
		sort(buff.begin(), buff.end(), srtlength);
		cout << endl << "Top-5 by length" << endl;
		cout << "№| English --> Russian";
		for (size_t i = 0; i < 5; i++) {
			cout << endl << i + 1 << ")"; buff[i].show();
		}
	}
	else {
		cout << endl << "There is less than 5 words" << endl;
		system("pause");
	}
}
