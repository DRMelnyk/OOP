#include <stdio.h>
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include "arr.h"
using namespace std;

void Arr::get_evens() {
	for(int i =0; i<size; i++) {
		if ((arr[i]%2)==0) {
			this->evens++;
		}
	}
}

Arr::Arr() { // конструктор за замовченням
	cout<< "Size error"<<endl;
}

Arr::Arr(int s) { 	//конструктор з параметрами
	if (s<=0) {
		cout<<"\n Size error" << endl;
		exit (0);	
	}
	else {
		size = s;
		arr = new int[s];
	}
}

void Arr::fill_A() { 	//заповнення массиву віпадковими значеннями
	srand(time(NULL));
	for (int i=0; i<size; i++) {
		arr[i] = rand() % 20;
		cout<< "|"<< arr[i] << "|\t";
	}
	cout<<"\n";

	get_evens(); //отримання кількості парних елементів
	cout << "\nk(odds) = " << evens << endl;
}

void Arr::mod2_A() { 	//видалення всіх парних елементів крім останнього
	if (evens >= 2) {
		do {
			for (int i = 0; i < size; i++) {
				if ((arr[i] % 2) == 0) {
					cout << evens << ") Removing element " << i + 1 << ": " << arr[i] << endl;
					for (int f = i; f < size; f++) {
						arr[f] = arr[f + 1];
					}
					size--;
					evens--;
					break; // вихід з циклу для перезапуску з новим розміром масиву
				}
			}
			if(evens == 1) { // якщо залишився лише один парний елемент, то він не видаляється
				cout << "Last even element: " << arr[size - 1] << endl;
				break;
			}
			else {
				cout << "Remaining even elements: " << evens << endl;
			}
		} while (true);
	}
	else
		cout << "\nk(mod2) = " << evens;
}

void Arr::sort_A() { //розташування чисел у порядку зростання
	for (int i=0; i<size; ++i) {
		int mInd=i;
		int mValue=arr[i];
		for(int j=i+1; j<size; ++j)
			if(arr[j]<mValue){
				mInd=j;
				mValue=arr[j];
			}
		arr[mInd]=arr[i];
		arr[i]=mValue;
	}
}

void Arr::mod_max(){ //знаходження max[mod2; mod3] та перестановка їх місцями
	int Mod2_max=-1, Mod3_max=-1, m2Ind=-1, m3Ind=-1, tempValue=0;
	for (int i=0; i<size; i++) {
		if ((arr[i]%2) == 0 && arr[i]>Mod2_max) {
			m2Ind=i;
			Mod2_max=arr[i];
		}
		if ((arr[i]%3) == 0 && arr[i]>Mod3_max){
			m3Ind=i;
			Mod3_max=arr[i];
		}
	}
	if (m2Ind==-1)
		cout<<"m2Ind does not exist\n";
	else
		if (m3Ind==-1)
			cout<<"m3Ind does not exist\n";
		else
			if (m2Ind!=m3Ind) {
				tempValue = Mod2_max;
				arr[m2Ind] = Mod3_max;
				arr[m3Ind] = tempValue;
			}
			else
				cout<<"m2Ind=m3Ind\n";
}

void Arr::show() { //функція виведення масиву
	for (int i=0; i<size; i++){
		cout<<"|"<<arr[i]<<"|\t";
	}
	cout<<"\n";
}

Arr::~Arr() { 	//диструктор
		delete [] arr;
	}
