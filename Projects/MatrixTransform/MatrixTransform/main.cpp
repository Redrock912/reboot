#include <iostream>
#include "Vector.h"
#include "Matrix.h"
using namespace std;

void main()
{
	float k = 0;
	Matrix4D m(1, 2, 6, 4, 0, 1, 6, 9, 0,2,5,6,0,5,8,4);
	k= Determinant(m);
	cout << k;

	for (int i = 0; i < 4; i++){
		cout << endl;
		for (int j = 0; j < 4; j++){
			cout << m[i][j] << " ";
		}
	}

	cout << endl;

	Matrix4D inv;
	inv = Inverse(m);

	for (int i = 0; i < 4; i++){
		cout << endl;
		for (int j = 0; j < 4; j++){
			cout << inv[i][j] << " ";
		}
	}

	cout << endl;

	Matrix4D adj;
	adj = Adjugate(m);

	for (int i = 0; i < 4; i++){
		cout << endl;
		for (int j = 0; j < 4; j++){
			cout << adj[i][j] << " ";
		}
	}
}