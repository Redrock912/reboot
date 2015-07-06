#include <iostream>
using namespace std;

class Matn
{
public:
	int row, column;
	int **v;
	Matn(){

	}
	Matn(int a,int b){
		this->column = a;
		this->row = b;
		v = new int *a;

	}

	
};

void strassen(int n, int** a, int** b, int** c){
	if (n <= 2){
		for (int k = 0; k < 2; k++){
			for (int l = 0; l < 2; l++){
				c[k][l] = 0;
				for (int m = 0; m < 2; m++){
					c[k][l] = c[k][l] + a[k][m] * b[m][l];
				}
			}
		}
		int m1, m2, m3, m4, m5, m6, m7;
		m1=(a[0][0] + a[1][1])*(b[0][0] + b[1][1]);
		m2 = (a[1][0] + a[1][1])*b[0][0];
		m3 = (a[0][0])*(b[0][1] - b[1][1]);
		m4 = a[1][1] * (b[1][0] - b[0][0]);
		m5 = (a[0][0] + a[0][1])*b[1][1];
		m6 = (a[1][0] - a[0][0])*(b[0][0] + b[1][1]);
		m7 = (a[0][1] - a[1][1])*(b[1][0] + b[1][1]);

		c[0][0] = m1 + m4 - m5 + m7;
		c[0][1] = m3 + m5;
		c[1][0] = m2 + m4;
		c[1][1] = m1 + m3 - m2 + m6;
	}
	else{
		int k = n / 2;
			int **a11 = new int* [k];
			int** a12 = new int*[k];
			int** a21 = new int*[k];
			int** a22 = new int*[k];
			int** b11 = new int*[k];
			int** b12 = new int*[k];
			int** b21 = new int*[k];
			int** b22 = new int*[k];
		for (int i = 0; i < n / 2; i++){
			a11[i] = new int[k];
			a12[i] = new int[k];
			a21[i] = new int[k];
			a22[i] = new int[k];
			b11[i] = new int[k];
			b12[i] = new int[k];
			b21[i] = new int[k];
			b22[i] = new int[k];
		}

		for (int i = 0; i < k; i++){
			for (int j = 0; j < k; j++){
				a11[i][j] = a[i][j];
				b11[i][j] = b[i][j];
				a12[i][j] = a[i + k][j];
				b12[i][j] = b[i + k][j];
				a21[i][j] = a[i][j + k];
				b21[i][j] = b[i][j + k];
				a22[i][j] = a[i + k][j + k];
				b22[i][j] = b[i + k][j + k];
			}
		}

		// strassen(k,) 노답이라 할 수 있지!

		c[0][0] = m1 + m4 - m5 + m7;
		c[0][1] = m3 + m5;
		c[1][0] = m2 + m4;
		c[1][1] = m1 + m3 - m2 + m6;

	}
}

int main(void)
{
	int k, l;

	cout << "Type in the size of the matrix. It must be a power of 2" << endl;

	cin >> k;

	l = k;
	if (k % 2 == 0)
	{
		while (k % 2 == 0)
		{
			k /= 2;
			if (k == 1){
				cout << "it is power of 2" << endl;
				k = l;
				break;
			}
		}
	}
	else
	{
		cout << "this is not the right size." << endl;
	}

	if (k != l)
	{
		return 0;
	}

	int **A = new int* [k];
	int **B = new int*[l];
	for (int i = 0; i < k; i++){
		A[i] = new int[k];
		B[i] = new int[l];
	}

	cout << "Type in the matrix elements. Type in the rows left to right." << endl;
	int num;
	for (int i2 = 0; i2 < k; i2++){
		for (int i3 = 0; i3 < k; i3++){
			cin >> num;
			A[i2][i3] = num;
		}
	}

	for (int i = 0; i < k; i++){
		for (int i2 = 0; i2 < k; i2++){
			cout << A[i][i2] << " ";
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < k; i++){
		delete[] A[i];
		delete[] B[i];
	}
	delete[] A;
	delete[] B;


}