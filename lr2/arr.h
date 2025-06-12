#include <stdio.h>
#include <iostream>


class Arr {

	int *arr;
	int size;
	int evens;
	void get_evens(); //вилучення всіх парних елементів, крім останнього

public:
	Arr();			//конструктор за замовченням
	Arr(int);		//конструктор з параметрами
		
	void fill_A();	//заповнення масиву 

	void mod2_A();	//вилучення всіх парних елементів, крім останнього
	void sort_A();	//розташування чисел у порядку зростання
	void mod_max(); //знаходження max[mod2; mod3] та перестановка їх місцями
	void show();	//функція виведення масиву
	
	~Arr();			//диструктор
};
