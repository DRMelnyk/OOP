#pragma once
#include <string>
#include <iostream>
using namespace std;

class Error { // базовий клас
public:
	virtual void what() {};
};
class Indexerror : public Error { // помилка в індексі вектору
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

class Sizeerror : public Error { // помилка в розмірі вектору
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

class Maxsizeerror :public Sizeerror { // перевищення максимального розміру
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

class Emptysizeerror : public Sizeerror { //видалення з порожнього вектору
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

class Indexerror1 :public Indexerror { //індекс менше нуля
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

class Indexerror2 :public Indexerror { //індекс більше поточного розміру вектору
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