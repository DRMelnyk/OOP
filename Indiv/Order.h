#pragma once
#include"Menu.h"
#include"Courier.h"
#include "Clients.h"

class Order :public Menu_, public Courier, public Clients
{
private:
	vector<string> order_body;
	vector<int> order_status;
	int bill;
public:
	void set_ord(Menu_&, Courier&, Clients&);
	string status_ord(int);

	void ord_clear();
	void ordl_clear(int);
	void fout_ord();
	void fin_ord();
	void ordlist_show();
	void status_change(int, Courier&);

	string get_body(int);
	int get_status(int);
};