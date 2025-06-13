#include "Courier.h"

void Courier::set_name()
{
	srand(time(NULL));
	string name="";
	int sp=0;
	ifstream fin;
	fin.open("Courier.txt", ios::in);
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			getline(fin, name);
			cour_name.push_back(name);
			cour_status.push_back(false);
			sp = 10 + rand() % 10;
			cour_speed.push_back(sp);
		}
	}
	else cout << "File with couriers was not found."<<endl;
	fin.close();
}

void Courier::show_name()
{
	int minSpI=0, minSpV=999, maxSpI=0, maxSpV=-999;
	for (int i = 0; i < cour_name.size(); i++)
	{
		if (cour_speed[i] > maxSpV)
		{
			maxSpV = cour_speed[i];
			maxSpI = i;
		}
		if (cour_speed[i]<minSpV)
		{
			minSpV = cour_speed[i];
			minSpI = i;
		}
		cout << i + 1 << ") " << cour_name[i] << "\t" << "| " << cour_status[i] << " |" << "\t" << cour_speed[i] << " min" << endl;
	}
	cout << "The slowest courier: " << cour_name[maxSpI] << " (" << maxSpV << ")" << endl;
	cout << "The fastest courier: " << cour_name[minSpI] << " (" << minSpV << ")" << endl;
}

void Courier::name_f()
{
	ofstream fout;
	fout.open("Courier.txt", ofstream::trunc);
	fout.close();
	fout.open("Courier.txt", ofstream::app);
	if (fout.is_open())
	{
		for (int i = 0; i < cour_name.size(); i++)
		{
			fout << cour_name[i];
			if (i != cour_name.size() - 1)
				fout << endl;
		}
	}
	else
		cout << "File was not found" << endl;
	fout.close();
}

void Courier::add_person()
{
	string n = "",pr=" ", s = "";
	ofstream fout;
	fout.open("Courier.txt", ofstream::app);
	if (fout.is_open())
	{
		cout << "Enter courier`s name: ";
		cin >> n;
		cout << "Enter courier`s surname: ";
		cin >> s;
		cout << "Done" << endl;
		n += pr + s;
	}
	else
		cout << "File was not found" << endl;
	cour_name.push_back(n);
	fout << endl << n;
	cour_status.push_back(false);
	fout.close();
}

void Courier::remove_person()
{
	int num = 0;
	bool w = true;
	cout << "Enter a number to remove: ";
	do
	{
		cin >> num;
		if (num > 0 && num <= cour_name.size())
		{
			cour_name.erase(cour_name.begin() + num - 1);
			cour_status.erase(cour_status.begin() + num - 1);
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
