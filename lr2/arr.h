#include <stdio.h>
#include <iostream>


class Arr {

	int *arr;
	int size;
	int evens;
	void get_evens(); //��������� ��� ������ ��������, ��� ����������

public:
	Arr();			//����������� �� �����������
	Arr(int);		//����������� � �����������
		
	void fill_A();	//���������� ������ 

	void mod2_A();	//��������� ��� ������ ��������, ��� ����������
	void sort_A();	//������������ ����� � ������� ���������
	void mod_max(); //����������� max[mod2; mod3] �� ������������ �� ������
	void show();	//������� ��������� ������
	
	~Arr();			//����������
};
