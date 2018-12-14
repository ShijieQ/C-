#include "Matrix.h"
#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;
int main() {
	int dimM_A, dimN_A, dimM_B, dimN_B, k;
	cout << "Please input the dimensions of matrix A: ";
	cin >> dimM_A >> dimN_A;
	cout << "Please input the dimensions of matrix B: ";
	cin >> dimM_B >> dimN_B;
	Matrix A(dimM_A, dimN_A), B(dimM_B, dimN_B);
	cout << "To matrix A :" << endl;
	A.Change();
	cout << "To matrix B :" << endl;
	B.Change();
	cout << "Please input the value of k: " << endl;
	cin >> k;
	cout << "A * k: " << endl;
	(A*k).Output();
	cout << "B * k: " << endl;
	(B*k).Output();
	cout << "A + A: " << endl;
	(A + A).Output();
	cout << "A X B: " << endl;
	(A*B).Output();
	if (A.dimM == A.dimN){
		cout << "det A: " << endl;
		cout << A.Det << endl;
	}
	if (B.dimM == B.dimN) {
		cout << "det B: " << endl;
		cout << B.Det << endl;
	}
	return 0;
}