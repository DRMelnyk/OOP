#include <iostream>

class mat {
	int **_mat;
	int rows;
	int cols;

public:
	mat();
	mat(int, int);

	void input_m();
	void output_m();

	void positive_col();
	void zero_replace();
	void min_pos();
	void max_neg();
	};

