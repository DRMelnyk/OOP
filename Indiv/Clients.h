#pragma once
#include"Menu.h"

class Clients
{

public:
	vector<string> cl_name;
	vector<int> orders_n;
	string ns;
	Clients();
	~Clients();

	void client_add();
	string client_adds();
	void client_remove();

	void clientlist_get();
	void clientlist_f();
	void clientlist_show();
};

