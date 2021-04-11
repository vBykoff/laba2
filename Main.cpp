#include <iostream>
#include "Header.h"


int main() {
	using namespace std;
	
	Vector a(3);
	Vector b(3);
	cin >> a;
	cout << a << endl;
	cin >> b;
	cout << b << endl;
	/*double k[] = { 1.25, 1.543, 1 };
	int k1[] = { 0, 1, 2 };
	int k2[] = { 0, 1, 2, 3 };
	Matrix A(3, 3, k, k1, k2);*/

	//Vector a(3);
	//cin >> a;
	
	double k[] = { 1, 2, 1, 1, 2 };
	int k1[] = { 0, 1, 1, 2, 2};
	int k2[] = { 0, 2, 4, 5 };

	/*double k[] = { 1,1,1 };
	int k1[] = { 2, 1, 0 };
	int k2[] = { 0, 1, 2, 3 };*/
	Matrix A(3, 5, k, k1, k2);
	//Vector b(3);
	cout << A << endl;
	b = a * A;
	cout << b;

	return 0;
}	//1 2 0
	//0 1 1
	//0 0 2 