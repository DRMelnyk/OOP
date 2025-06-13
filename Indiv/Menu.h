#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<conio.h>
#include<algorithm>
#include<time.h>
#include<cstdlib>
using namespace std;

class Menu_
{
public:
	vector<string> menu;
	vector<int> price;

	Menu_();
	~Menu_();

	void get_list();
	void menu_show();
	void menu_f();

	void operator() ();
	void operator- ();
};