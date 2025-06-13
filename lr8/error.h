#pragma once
#include <string>
#include <iostream>
using namespace std;

class Error { // ������� ����
public:
	virtual void what() {};
};
class Indexerror : public Error { // ������� � ������ �������
protected:
	string msg;
public:
	Indexerror() {
		msg = "Index Error\n";
	}
	virtual void what() {
		cout << msg;
	}
};

class Sizeerror : public Error { // ������� � ����� �������
protected:
	string msg;
public:
	Sizeerror() {
		msg = "size error\n";
	}
	virtual void what() {
		cout << msg;
	}
};

class Maxsizeerror :public Sizeerror { // ����������� ������������� ������
protected:
	string msg_;
public:
	Maxsizeerror() {
		Sizeerror();
		msg_ = "size>MAXSIZE\n";
	}
	virtual void what() {
		cout << msg << msg_;
	}
};

class Emptysizeerror : public Sizeerror { //��������� � ���������� �������
protected:
	string msg_;
public:
	Emptysizeerror() {
		Sizeerror();
		msg_ = "Vector is empty\n";
	}
	virtual void what() {
		cout << msg << msg_;
	}
};

class Indexerror1 :public Indexerror { //������ ����� ����
protected:
	string msg_;
public:
	Indexerror1() {
		Indexerror();
		msg_ = "index <0\n";
	}
	virtual void what() {
		cout << msg << msg_;
	}
};

class Indexerror2 :public Indexerror { //������ ����� ��������� ������ �������
protected:
	string msg_;
public:
	Indexerror2() {
		Indexerror();
		msg_ = "index>size\n";
	}
	virtual void what() {
		cout << msg << msg_;
	}
};