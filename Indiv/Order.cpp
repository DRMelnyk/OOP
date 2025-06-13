#include <sstream>
#include "Order.h"

void Order::set_ord(Menu_ &a, Courier &b, Clients &c)
{
	int q = 0, num=0, summ=0;
	string ord, pr=" | ", temp;
	bool w = true;
//____________________________________________
	c.client_adds();
	ord += c.ns + pr; // -> вводимо клієнта

	a.menu_show();
	do
	{
		q = 1;
		cout << "Number of product: ";
		cin >> num;
		if (num >= 0 && num < a.price.size())
		{
			cout << "You chose: " << a.menu[num] << endl << "How many do you need: ";
			cin >> q;
			summ += a.price[num] * q;
			temp += a.menu[num] + ": " + to_string(a.price[num]) + "$" + " * " + to_string(q) + " = " + to_string(a.price[num] * q) + "$" + " ";
		}
		else
		{
			cout << "Out of list." << endl;
		}
		cout << "Total cost: " << summ << endl << "That`s all? (yes -> 1 / no -> 0): ";
		cin >> w;
		cout << endl;
	} while (w == false);
	ord += temp + pr + to_string(summ) + "$" + pr;
	num = 0; // -> заказ прийнято
//__________________________________________
	temp.clear();
	ord += __TIME__ + pr;
//_________________________________________
	for (int i = 0; i < b.cour_status.size(); i++)
	{
		if (b.cour_status[i] == false)
		{
			cout << "Your courier is: " << b.cour_name[i] << endl;
			b.cour_status[i] = true;
			w = true;
			temp = to_string(b.cour_speed[i]) + "min" + " " + pr + b.cour_name[i];
			num = 1; // -> заказ відправлено
			break;
		}
		else
		{
			cout << "Courier will be sent in five minutes.";
		}
	}
	ord += temp + pr;
//_______________________________________
	order_body.push_back(ord);
	order_status.push_back(num);
	cout << order_body.back() << status_ord(order_status.back()) << pr << endl;
	fout_ord();
}

string Order::status_ord(int s)
{
	if (s == 0)
		return "PROCESSING";
	if (s == 1)
		return "BEING DELIVERED";
	if (s == 2)
		return "COMPLETE";
	if (s == 3)
		return "CANCELLED";
}

void Order::ord_clear()
{
	ofstream fout;
	fout.open("Order.txt", ofstream::trunc);
	fout.close();
}

void Order::ordl_clear(int i)
{
	order_body.erase(order_body.begin() + i);
	order_status.erase(order_status.begin() + i);
}

void Order::fout_ord()
{
	ofstream fout;
	fout.open("Order.txt", ofstream::trunc);
	fout.close();
	fout.open("Order.txt", ofstream::app);
	if (fout.is_open())
	{
		for (int i = 0; i < order_status.size(); i++)
		{
			fout << order_body[i] << endl << order_status[i];
			if (i != order_status.size() - 1)
				fout << endl;
		}
	}
	else
		cout << "File was not found" << endl;
	fout.close();
}
void Order::fin_ord()
{
	string n = "", pr = "";
	int p = 0, k = 1;
	ifstream fin;
	fin.open("Order.txt", ios::in);
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			if (k % 2 != 0)
			{
				getline(fin, n);
				order_body.push_back(n);
			}
			else
			{
				getline(fin, pr);
				p = stoi(pr);
				order_status.push_back(p);
			}
			k++;
		}
	}
	else
	{
		cout << "File with orders was not found" << endl;
	}
	fin.close();
}
void Order::ordlist_show()
{
	if (order_status.size() != 0)
	{
		for (int i = 0; i < order_body.size(); i++)
		{
			cout << i + 1 << ") ";
			cout <<	order_body[i] << " | " << status_ord(order_status[i]) << endl;
		}
	}
	else
		cout << "There is no any order." << endl;
}

void Order::status_change(int t, Courier& a)
{
	string temp;
	int i;
	cout << "Enter another status:" << endl
		<< "\t> 0 -> PROCESSING" <<endl
		<< "\t> 1 -> BEING DELIVERED" << endl
		<< "\t> 2 -> COMPLETE" << endl
		<< "\t> 3 -> CANCELLED" << endl << "/> ";
	cin >> i;
	if (i != order_status[t] || i<4)
	{
		order_status[t] = i;
		if (i == 1)
		{
			for (int j = 0; j < a.cour_status.size(); j++)
				if (a.cour_status[j] == false)
				{
					order_body[t] += to_string(a.cour_speed[j]) + "min" + " " + " | " + a.cour_name[j];;
					a.cour_status[j] = true;
				}
		}
	}
	else 
		cout << "It is the current status" << endl;
}

string Order::get_body(int i)
{
	if (i > 0 || i < order_body.size())
		return order_body[i];
	else
		cout<<"Out of list"<<endl;
}

int Order::get_status(int n)
{
	if (n > 0 || n < order_body.size())
		return order_status[n];
	else
		cout<< "Out of list" << endl;
}




