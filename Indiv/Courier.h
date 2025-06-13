#pragma once
#include"Menu.h"

class Courier
{
public:
	vector<string> cour_name;	// для збереження імені та призвища кур'єра
	vector<bool> cour_status;	// для статусу (може бути PROCESSING", "BEING DELIVERED", "COMPLETE" та "CANCELLED")
	vector<int> cour_speed;		// для підрахунку швидкості виконання доставки

	void set_name();			// метод для отримання інформації про кур'єрів з файлу
	void show_name();			// метод для виводу інформації про кур'єрів на єкран
	void name_f();				// метод для збереження інформації про кур'єра у файл

	void add_person();			// метод для додавання кур'єра
	void remove_person();		// метод для видалення кур'єра
};