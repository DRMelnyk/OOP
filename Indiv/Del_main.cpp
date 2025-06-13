#include"Menu.h"
#include"Courier.h"
#include"Time.h"
#include"Clients.h"
#include"Order.h"


int main()
{
	bool program = true;
	char ord_ = '0', act = '0', menu = '0', cour = '0', client = '0', or_list = '0';
	int ord = 0;

	Menu_ menu_class;
	Courier courier_class;
	Clients clients_class;
	Order order_class;
	
	menu_class.get_list();
	courier_class.set_name();
	clients_class.clientlist_get();
	order_class.fin_ord();

	do
	{
		cout << __DATE__ << " " << __TIME__ << endl 
			<< "> 1 -> Open the menu" << endl
			<< "> 2 -> Open the courier list" << endl
			<< "> 3 -> Open the client list" << endl
			<< "> 4 -> Open the order list" << endl
			<< "> 5 -> Form a new order" << endl
			<< "> 0 -> Exit" << endl << "/> ";
		act = _getch();
		switch (act)
		{
//-------------------------------------------------
		case '1':
			system("cls");
			cout << "List of products:" << endl;
			do
			{
				menu_class.menu_show();
				cout << endl
					<< "> 1 -> Add a new dish" << endl
					<< "> 2 -> Remove a dish" << endl
					<< "> 0 -> Previous menu" << endl << "/> ";
				menu = _getch();
				switch (menu)
				{
				case '1':
					menu_class();
					system("cls");
					break;
				case '2':
					-menu_class;
					system("cls");
					break;
				}
			} while (menu != '0');
			menu_class.menu_f();
			break;
//------------------------------------------------
		case '2':
			system("cls");
			cout << "List of couriers: " << endl;
			do
			{
				courier_class.show_name();
				cout << endl 
					<< "> 1 -> Add a new courier" << endl
					<< "> 2 -> Remove a courier" << endl
					<< "> 0 -> Previous menu" << endl << "/> ";
				cour = _getch();
				switch (cour)
				{
				case '1':
					courier_class.add_person();
					system("cls");
					break;
				case '2':
					courier_class.remove_person();
					system("cls");
					break;
				}
			} while (cour!='0');
			courier_class.name_f();
			break;
//-----------------------------------------------
		case '3':
			system("cls");
			do
			{
				cout << "List of clients:" << endl;
				clients_class.clientlist_show();
				cout<<endl
					<< "> 1 -> Add a new client" << endl
					<< "> 2 -> Remove a client" << endl
					<< "> 0 -> Previous menu" << endl << "/> ";
				client = _getch();
				switch (client)
				{
				case '1':
					clients_class.client_add();
					system("cls");
					break;
				case '2':
					clients_class.client_remove();
					system("cls");
					break;
				}
			} while (client!='0');
			clients_class.clientlist_f();
			break;
//-----------------------------------------------
		case '4':
			do 
			{
				system("cls");
				cout << "List of orders:" << endl;
				order_class.ordlist_show();
				cout << endl << 
					"> 1 -> Clear the order list" << endl <<
					"> 2 -> Get the order" << endl <<
					"> 0 -> Previous menu" << endl << "/> ";
				or_list = _getch();
				switch (or_list)
				{
				case '1':
					order_class.ord_clear();
					break;
				case '2':
					cout << "Enter the order to change: ";
					cin >> ord;
					do 
					{
						system("cls");
						cout << order_class.get_body(ord-1) << order_class.status_ord(order_class.get_status(ord-1)) << endl << 
							"> 1 -> Change status" << endl <<
							"> 2 -> Remove order" << endl <<
							"> 0 -> Move back" << endl << "/> ";
						cin >> ord;
						switch (ord)
						{
						case 1:
							order_class.status_change(ord-1, courier_class);
							break;
						case 2:
							order_class.ordl_clear(ord - 1);
							break;
						}
					} while (ord != 0);
					break;
				}
			} while (or_list != '0');
			break;
//-----------------------------------------------
		case '5':
			system("cls");
			cout << "Forming a new order..." << endl;
			order_class.set_ord(menu_class, courier_class, clients_class);
			system("pause");
			break;
			order_class.fout_ord();
			}
		system("cls");
	} while (act != '0');
	return 0;
}