#pragma once
#include"Menu.h"

class Courier
{
public:
	vector<string> cour_name;	// ��� ���������� ���� �� �������� ���'���
	vector<bool> cour_status;	// ��� ������� (���� ���� PROCESSING", "BEING DELIVERED", "COMPLETE" �� "CANCELLED")
	vector<int> cour_speed;		// ��� ��������� �������� ��������� ��������

	void set_name();			// ����� ��� ��������� ���������� ��� ���'��� � �����
	void show_name();			// ����� ��� ������ ���������� ��� ���'��� �� �����
	void name_f();				// ����� ��� ���������� ���������� ��� ���'��� � ����

	void add_person();			// ����� ��� ��������� ���'���
	void remove_person();		// ����� ��� ��������� ���'���
};