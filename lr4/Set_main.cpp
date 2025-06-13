#include"Set.h"

int main()
{
	char to_del = ' ', to_add = ' ';
	Set set1, set2;
	set1.set_size();
	set1.set_set();
	set1.set_show();
	system("pause");
	system("cls");

	cout << "Move to another set." << endl;
	set2.set_size();
	set2.set_set();
	set2.set_show();
	system("pause");

	unsigned char m1=' ', m2=' ';
	do
	{
		system("cls");
		cout << "Choose your set:" << endl << " > 1 -> set#1" << endl << " > 2 -> set#2" << endl << " > 0 -> exit" << endl << "> ";
		m1 = _getch();
		switch (m1)
		{
		case '1':
			do
			{
				system("cls");
				set1.set_show();
				cout << "What do you want?\n > 1 -> Remove an element\n > 2 -> Add an element\n > 3 -> Compare two sets \n > 0 -> Switch the set" << endl << "> ";
				m2 = _getch();
				switch (m2)
				{
				case '1':
					system("cls");
					set1.set_show();
					cout << "Which element do you want to delete?" << endl << "> ";
					cin >> to_del;
					set1 - to_del;
					break;
				case '2':
					system("cls");
					set1.set_show();
					cout << "Which element do you want to add?" << endl << "> ";
					cin >> to_add;
					set1(to_add);
					break;
				case '3':
					system("cls");
					set1 == set2;
					break;
				}
			} while (m2!='0');
			break;
		case '2':
			do
			{
				system("cls");
				set2.set_show();
				cout << "What do you want?\n > 1 -> Remove an element\n > 2 -> Add an element\n > 3 -> Compare two sets \n > 0 -> Switch the set" << endl << "> ";
				m2 = _getch();
				switch (m2)
				{
				case '1':
					system("cls");
					set2.set_show();
					cout << "Which element do you want to delete?" << endl << "> ";
					cin >> to_del;
					set2 - to_del;
					break;
				case '2':
					system("cls");
					set2.set_show();
					cout << "Which element do you want to add?" << endl << "> ";
					cin >> to_add;
					set2(to_add);
				break;
				case '3':
					system("cls");
					set2 == set1;
					break;
				}
			} while (m2 != '0');
			break;
		}
	} while (m1 != '0');
	cout << "Have a nice day /`(^3^)_/` ";
	return 0;
}



/*
int main()
{
	setlocale(LC_ALL, "Rus");
	Set a, b;
	a.setsize();
	a.setset();
	a.show();
	system("pause");
	system("cls");

	cout << "Move to the next set" << endl;
	b.setsize();
	b.setset();
	b.show();
	system("pause");

	int K, S;
	do 
	{
		system("cls");
		cout << "Choose your set\n - set a -> 1\n - set b -> 2 \n - exit -> 0" << endl;
		cin >> S;
		if (S == 1)
		{
			do
			{
				system("cls");
				a.show();
				cout << "What do you want?\n - Add an element -> 1\n - Remove an element -> 2\n - Compare two sets -> 3\n - Switch the set -> 0" << endl;
				cin >> K;
				if (K == 1)
				{
					system("cls");
					a.show();
					a.operator() ();
					a.show();
					system("pause");
				}
				if (K == 2)
				{
					a.show();
					a.operator-();
					a.show();
					system("pause");
				}
				if (K == 3)
				{
					a==b;
					system("pause");
				}
			} while (K != 0);
		}
		if (S == 2)
		{
			do
			{
				system("cls");
				b.show();
				cout << "What do you want?\n - Add an element -> 1\n - Remove an element -> 2\n - Compare two sets -> 3\n - Switch the set -> 0" << endl;
				cin >> K;
				if (K == 1)
				{
					system("cls");
					b.show();
					b.operator() ();
					b.show();
					system("pause");
				}
				if (K == 2)
				{
					b.show();
					b.operator-();
					b.show();
					system("pause");
				}
				if (K == 3)
				{
					b==a;
					system("pause");
				}
			} while (K != 0);
		}

	} while (S != 0);
	system("cls");
	cout << "Have a nice day /`(^ç^)_/` ";
	return 0;
}
*/