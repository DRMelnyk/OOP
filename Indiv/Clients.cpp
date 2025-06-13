#include "Clients.h"

Clients::Clients()
{
}

Clients::~Clients()
{
}

void Clients::client_remove()
{
	int num = 0;
	bool w = true;
	cout << "Enter a number to remove: ";
	do
	{
		cin >> num;
		if (num > 0 && num <= cl_name.size())
		{
			cl_name.erase(cl_name.begin() + num - 1);
			orders_n.erase(orders_n.begin() + num - 1);
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

string Clients::client_adds()
{
	string n, s, pr = " ";
	int o = 0;
	bool w = false;
	cout << "Enter your name: ";
	cin >> n;
	cout << "Enter your surname: ";
	cin >> s;
	n += pr + s;
	for (int i = 0; i < cl_name.size(); i++)
	{
		pr = cl_name[i];
		if (n == pr)
		{
			orders_n[i]++;
			w = false;
			break;
		}
		else w = true;
	}
	if (w == true)
	{
		cl_name.push_back(n);
		orders_n.push_back(1);
	}
	clientlist_f();
	return ns = n;
}

void Clients::clientlist_get()
{
	string n, pr; 
	int p = 0, k = 1;
	ifstream fin;
	fin.open("Clients.txt");
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			if (k % 2 != 0)
			{
				getline(fin, n);
				cl_name.push_back(n);
			}
			else
			{
				getline(fin, pr);
				p = stoi(pr);
				orders_n.push_back(p);
			}
			k++;
		}
	}
	else
	{
		cout << "File with clients was not found" << endl;
	}
	fin.close();
}

void Clients::clientlist_f()
{
	ofstream fout;
	fout.open("Clients.txt", ofstream::trunc);
	fout.close();
	fout.open("Clients.txt", ofstream::app);
	if (fout.is_open())
	{
		for (int i = 0; i < cl_name.size(); i++)
		{
			fout << cl_name[i] << endl << orders_n[i];
			if (i != cl_name.size() - 1)
				fout << endl;
		}
	}
	else
		cout << "File was not found" << endl;
	fout.close();
}

void Clients::clientlist_show()
{
	int maxInd = -1, maxVol = -1;
	for (int i = 0; i < cl_name.size(); i++)
	{
		if (maxVol<orders_n[i])
		{
			maxVol = orders_n[i];
			maxInd = i;
		}
		cout << i + 1 << ") " << cl_name[i] << " \t " << orders_n[i] << endl;
	}
	cout << "The most active client: " << cl_name[maxInd] << "(" << maxVol << ")";
}

void Clients::client_add()
{
	string n, s, pr=" ";
	int o = 0;
	bool w = false;
	cout << "Enter your name: ";
	cin >> n;
	cout << "Enter your surname: ";
	cin >> s;
	n += pr + s;
	for (int i = 0; i < cl_name.size(); i++)
	{
		pr = cl_name[i];
		if (n == pr)
		{
			orders_n[i]++;
			w = false;
			break;
		}
		else w = true;
	}
	if (w == true)
	{
		cl_name.push_back(n);
		orders_n.push_back(1);
	}
}