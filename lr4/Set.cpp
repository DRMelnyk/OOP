#include"Set.h"

void Set::set_size()
{
	cout << "Enter the size of the set: ";
	cin >> size;
}

void Set::set_set()
{
	char temp = ' ';
	cout << "Enter the set: ";
	for (int i = 0; i < size; i++)
	{
		cin >> temp;
		set_.insert(temp);
	}
}

void Set::set_show()
{
	cout << "Your set is: [";
	for (it = set_.begin(); it != set_.end(); ++it)
		cout << *it;
	cout << "]" << endl;
}

void Set::operator-(char del)
{
	int s = set_.size();
	set_.erase(del);
	if (s > set_.size())
		cout << "Elemnt was removed successfully." << endl;
	else
		cout << "Element has not been removed (not in the set)." << endl;
	set_show();
	system("pause");
}

void Set::operator()(char add)
{
	int s = set_.size();
	set_.emplace(add);
	if(s<set_.size())
		cout << "Elemnt was added successfully." << endl;
	else
		cout << "Element has not been added (already in the set)." << endl;
	set_show();
	system("pause");
}

void Set::operator==(const Set& a)
{
	bool comp=false;
	if (set_.size() < a.set_.size())
	{
		cout << "Another set is bigger." << endl;
	}
	if (set_.size() > a.set_.size())
	{
		cout << "This is bigger." << endl;
	}
	if (set_.size() == a.set_.size())
	{
			cout << "Sizes are equal. Starting comperison by element..." << endl;
			comp = true;
	}

	if (comp == true)
	{
		int comm=0;
		cout << "These elemnts are common: [";
		for (it = set_.begin(); it != set_.end(); ++it)
		{
			for (set<char> ::iterator ita = a.set_.begin(); ita != a.set_.end(); ++ita)
			{
				if (*ita == *it)
				{
					cout << *it;
					comm++;
					break;
				}
			}
		}
		cout << "]" << endl;
		if (comm == set_.size())
			cout << "Sets are similar." << endl;
		else if (comm == 0)
			cout << "Sets are compeletly different (no common element)." << endl;
		else
			cout << "Sets are different (some elements are common)." << endl;
	}
	system("pause");
}
