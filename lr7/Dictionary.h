#pragma once
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Dictionary //���� �������
{
private:
	string eng, rus; //�����, �������
public:
	Dictionary () {} //������� �����������
	Dictionary (ifstream& file); //����������� � ����������� � �����
	void set(); //���� � ���������
	void show(); //���� � �������
	size_t retleng() { return eng.length(); } //������� ������� ����������� �����
	size_t retlrus() { return rus.length(); } //������� ������� ���������� �����
	string reteng() { return eng; } //������� ��������� �����
	string retrus() { return rus; } //������� �������� �����
};
