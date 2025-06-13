#pragma once
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Dictionary //клас словник
{
private:
	string eng, rus; //слово, перевод
public:
	Dictionary () {} //базовий конструктор
	Dictionary (ifstream& file); //конструктор зі считуванням з файлу
	void set(); //набір з клавіатури
	void show(); //вивід у консоль
	size_t retleng() { return eng.length(); } //повертає довжину англійського слова
	size_t retlrus() { return rus.length(); } //повертає довжину російського слова
	string reteng() { return eng; } //повертає англійське слово
	string retrus() { return rus; } //повертає російське слово
};
