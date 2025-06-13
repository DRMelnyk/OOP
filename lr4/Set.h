#pragma once
#include<iostream>
#include<set>
#include<iterator>
#include<conio.h>

using namespace std;

class Set
{
private:
	int size;
	set<char> set_;
	set<char> :: iterator it;
public:
	Set(void) {}
	~Set(void) {}

	void set_size();
	void set_set();
	void set_show();

	void operator- (const char);
	void operator() (const char);
	void operator== (const Set&);
};
