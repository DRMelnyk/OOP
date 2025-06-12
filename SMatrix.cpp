#include <cstdlib>
#include <ctime>
#include <iostream>
#include "SMatrix.h"
using namespace std;

mat::mat (int _rows, int _cols) {
	rows = _rows;
	cols = _cols;
	_mat = new int *[_cols];
	for (int i = 0; i < _cols; i++) {
		_mat[i] = new int[_rows];
	}
}

void mat::input_m() {
	srand(time(NULL));
	for (int i = 0; i < cols; cout<<endl, i++) {
		for (int j = 0; j < rows; j++) {
			_mat[i][j] = rand()% 19 - 10;
			cout << "|" << _mat[i][j] << "|\t";
		}	
	}
}

void mat::positive_col(){
	cout<<endl;
	int k=0, t=0; 
	for (int i=0; i<rows; i++){
		k=0;
		for (int j=0; j<cols; j++){
			if (_mat[j][i]>=0){
				k++;
			}
			else break; 
		} 
		if (k==cols) {
			t++;
		}
	}
	cout<<"Number_of_positive_cols: "<< t <<endl;
}

void mat::min_pos() {
	int min_pos_volue=999;
	for (int i=0; i<cols; i++) {
		for (int j = 0; j<rows; j++){
			if (_mat[i][j]>=0)
				if (_mat[i][j]<min_pos_volue) {
					min_pos_volue = _mat[i][j];
			}
		}
	}
	if (min_pos_volue==999)
		cout<<"\n Minimum_positive_value: does not exist"<<endl;
	else	
		cout<<"\n Minimum_positive_value: "<<min_pos_volue<<endl;
}

void mat::max_neg() {
	int max_neg_volue=-999;
	for (int i=0; i<cols; i++){
		for (int j=0; j<rows; j++) {
		if (_mat[i][j]<0) {
			if (_mat[i][j]>max_neg_volue) {
				max_neg_volue = _mat[i][j];
			}
		}
		}
	}
	if (max_neg_volue==-999)
		cout<<" Maximum_negative_value: does not exist"<<endl;
	else
		cout<<" Maximum_negative_value: "<<max_neg_volue<<endl;
}

void mat::zero_replace() {
	int M=cols-1, N=rows-1;
	for (int i=0; i<cols; i++) {
		for (int j=0; j<rows; j++)
		{
			if (_mat[i][j]==0) 
			{
				if (i==0 && j==0)
					{_mat[i][j]=(_mat[0][1]+_mat[1][0])/2;}
				if (i==0 && j==M)
					{_mat[i][j]=(_mat[1][M]+_mat[0][M-1])/2;}
				if (i==N && j==M)
					{_mat[i][j]=(_mat[N][M-1]+_mat[N-1][M])/2;}
				if (i==N && j==0)
					{_mat[i][j]=(_mat[N][1]+_mat[N-1][0])/2;}
					
				if (i==N && j>0 && j<M)
					{_mat[i][j]=(_mat[N][j+1]+_mat[N-1][j]+_mat[N][j-1])/2;}
				if (i==0 && j>0 && j<M)
					{_mat[i][j]=(_mat[0][j+1]+_mat[0][j-1]+_mat[1][j])/2;}
				if (j==M && i>0 && i<N)
					{_mat[i][j]=(_mat[i+1][M]+_mat[i-1][M]+_mat[i][M-1])/2;}
				if (j==0 && i>0 && i<N)
					{_mat[i][j]=(_mat[i+1][0]+_mat[i-1][0]+_mat[i][1])/2;}
				if (i!=0 && i!=N && j!=0 && j!=M)
					{_mat[i][j]=(_mat[i][j+1]+_mat[i+1][j]+_mat[i-1][j]+_mat[i][j-1])/2;}							
			}	
		}
	}
}


void mat::output_m() {
	cout<<"------------------------------------------------------------------------"<<endl;
	for (int i = 0; i < cols; i++) {
		cout << endl;
		for (int j = 0; j < rows; j++) {
			cout << "|" << _mat[i][j] << "|\t";
		}
	}
}
