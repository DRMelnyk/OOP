#include "Menu.h"

Menu_::Menu_()
{
}

Menu_::~Menu_()
{
}

void Menu_::get_list()
{
	string n = "", pr = ""; 
	int p = 0, k = 1;
	ifstream fin;
	fin.open("Menu.txt", ios::in);
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			if (k % 2 != 0)
			{
				getline(fin, n);
				menu.push_back(n);
			}
			else
			{
				getline(fin, pr);
				p = stoi(pr);
				price.push_back(p);
			}
			k++;
		}
	}
	else
	{
		cout << "File with menu was not found" << endl;
	}
	fin.close();
}

void Menu_::menu_show()
{
	for (int i = 0; i < menu.size(); i++)
	{
		cout << i << ") " << menu[i] << " = " << price[i] << endl;
	}
}

void Menu_::menu_f()
{
	ofstream fout;
	fout.open("Menu.txt", ofstream::trunc);
	fout.close();
	fout.open("Menu.txt", ofstream::app);
	if (fout.is_open())
	{
		for (int i = 0; i < menu.size(); i++)
		{
			fout << menu[i] << endl << price[i];
			if (i != menu.size() - 1)
				fout << endl;
		}
	}
	else
		cout << "File was not found" << endl;
	fout.close();
}

void Menu_::operator() ()
{
	string n = "";
	int p = 0;
	ofstream fout;
	fout.open("Menu.txt", ofstream::app);
	if (fout.is_open())
	{
		cout << "Enter a new dish: ";
		cin >> n;
		cout << "Enter price: ";
		cin >> p;
		cout << "Done" << endl;
	}
	else 
		cout << "File was not found" << endl;
	menu.push_back(n);
	fout << endl << n;
	price.push_back(p);
	fout << endl << p;
	fout.close();
}

void Menu_::operator- ()
{
	int num=0;
	bool w=true;
	cout << "Enter a number to remove: ";
	do
	{
		cin >> num;
		if (num > 0 && num <= menu.size())
		{
			menu.erase(menu.begin() + num - 1);
			price.erase(price.begin() + num - 1);
			w = true;
			cout << "Element was removed successfully.";
		}
		else
		{
			cout << "Try another value." << endl;
			w = false;
		}
	} while (w == false);
}