#include <iostream>
#include <cstdlib>
#include "SMatrix.h"
using namespace std;


int main() {
	int c, r;
	cout << "Cols_number: ";
	cin >> c;
	cout << "Rows_number: ";
	cin >> r;

	mat a(c,r);
	a.input_m();
	a.positive_col();
	a.zero_replace();
	a.min_pos();
	a.max_neg();
	a.output_m();
	
	return 0;
}
