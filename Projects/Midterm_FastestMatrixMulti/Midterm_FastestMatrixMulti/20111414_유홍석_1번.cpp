#include <iostream>
#include <cmath>
using namespace std;

class Matp
{
public:
	int row;
	int column;
	int **k;
	Matp()
	{

	}
	Matp(int a, int b)
	{
		this->row = a;
		this->column = b;
		k = new int*[row];
		for (int i = 0; i < row; i++)
		{
			k[i] = new int[column];
		}
	}

	int get(int row, int column){
		return k[row][column];
	}

	void set(int row, int column)
	{
		int a;
		for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++){
			k[i][j] = 0;
		}
	}

};

Matp matmult(const Matp &a, const Matp &b)
{
	Matp temp;
	if (a.column == b.row)
	{
		temp.set(a.row, b.column);
		for (int i = 0; i < a.row; i++)
		{
			for (int j = 0; j < b.column; j++)
			{
				for (int z = 0; z < a.column; z++)
					temp.k[i][j] = temp.k[i][j] + a.k[i][z] * b.k[z][j];
			}
		}
	}
	else if (b.column == a.row)
	{
		temp.set(b.row, a.column);
		for (int i = 0; i < b.row; i++)
		{
			for (int j = 0; j < a.column; j++)
			{
				for (int z = 0; z < b.column; z++)
					temp.k[i][j] = temp.k[i][j] + a.k[i][z] * b.k[z][j];
			}
		}
	}
	return temp;
}
int binsearch(int* a, int x, int high)
{
	int location = 0;
	int mid;
	int low = 0;
	while (low <= high && location == 0)
	{
		mid = (low + high) / 2;
		if (x == a[mid])
			location = mid + 1;
		else if (x < a[mid])
			high = mid - 1;
		else
		{
			low = mid + 1;
		}
	}
	return location;
}

void selection(const Matp &a1, const Matp &a2, const Matp &a3, const Matp &a4, const Matp &a5, const Matp &a6)
{
	int row[6];
	int column[6];

	row[0] = a1.row;
	row[1] = a2.row;
	row[2] = a3.row;
	row[3] = a4.row;
	row[4] = a5.row;
	row[5] = a6.row;

	column[0] = a1.column;
	column[1] = a2.column;
	column[2] = a3.column;
	column[3] = a4.column;
	column[4] = a5.column;
	column[5] = a6.column;

}
/*
if (n <= 2){
for (int k = 0; k < 2; k++){
for (int l = 0; l < 2; l++){
c[k][l] = 0;
for (int m = 0; m < 2; m++){
c[k][l] = c[k][l] + a[k][m] * b[m][l];
}
}
*/
//void floyd(int n, const Matp& a, Matp b)
//{
//	int i, j, k;
//	for (int i = 0; i < a.row; i++)
//	for (int j = 0; j < a.column; j++)
//		b.k[i][j] = a.k[i][j];
//
//	for (k = 0; k < n; k++){
//		for (i = 0; i < n; i++){
//			for (j = 0; j < n; j++){
//				if (b.k[i][j] > b.k[i][k] + b.k[k][j])
//					b.k[i][j] = b.k[i][k] + b.k[k][j];
//			}
//		}
//	}
//
//}
//
//void floyd2(int n, const Matp& a, Matp b, int **c)
//{
//	for (int i = 0; i < n; i++)
//	for (int j = 0; j < n; j++)
//		c[i][j] = 0;
//
//	for (int i = 0; i < a.row; i++)
//	for (int j = 0; j < a.column; j++)
//		b.k[i][j] = a.k[i][j];
//
//	for (int k = 0; k < n; k++){
//		for (int i = 0; i < n; i++){
//			for (int j = 0; j < n; j++){
//				if (b.k[i][j] > b.k[i][k] + b.k[k][j]){
//					c[i][j] = k + 1;
//					b.k[i][j] = b.k[i][k] + b.k[k][j];
//				}
//			}
//		}
//	}
//}


int example[5][5] = {
	{ 0, 1, 10000, 1, 5 },
	{ 9, 0, 3, 2, 10000 },
	{ 10000, 10000, 0, 4, 10000 },
	{ 10000, 10000, 2, 0, 3 },
	{ 3, 10000, 10000, 10000, 0 }
};

void floydex(int n, int**c)
{
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		c[i][j] = 0;
	for (int k = 0; k < n; k++){
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if (example[i][j] > example[i][k] + example[k][j]){
					c[i][j] = k + 1;
					example[i][j] = example[i][k] + example[k][j];
				}
			}
		}
	}
}



int exarray[5][5] = { 0 };

void path(int q, int r)
{
	if (exarray[q - 1][r - 1] != 0){
		path(q, exarray[q - 1][r - 1]);
		cout << " v" << exarray[q - 1][r - 1];
		path(exarray[q - 1][r - 1], r);
	}
}


void main()
{
	int number, row, column;
	int **p;

	Matp a1(6, 7), a2(7, 5), a3(5, 20), a4(20, 2), a5(2, 3), a6(3, 7);


	//cout << "How many rows and columns would you like to make? Type the amount of the row first, then the column." << endl;
	//cin >> number;
	number = 5;
	row = number;
	column = number;
	Matp test(row, column);
	Matp temp(row, column);
	cout << "Now set the values for the matrix you have made. Fill it in row by row." << endl;
	//test.set(row, column);

	/////////////////// example 3-2 //////////////


	/*cout << "Here is the result." << endl;
	for (int i = 0; i < row; i++){
	for (int j = 0; j < column; j++)
	cout << test.k[i][j] << " ";
	cout << endl;
	}*/

	cout << endl;


	p = new int*[number];
	for (int i = 0; i < number; i++)
		p[i] = new int[number];


	//floyd(number, test, temp);

	//floyd2(number, test, temp,p);
	floydex(number, p);
	for (int i = 0; i < row; i++){
		for (int j = 0; j < column; j++)
			//cout << temp.k[i][j] << " ";
			cout << example[i][j] << " ";
		cout << endl;
	}

	cout << endl;

	for (int i = 0; i < row; i++){
		for (int j = 0; j < column; j++)
			cout << p[i][j] << " ";
		cout << endl;
	}

	cout << endl;


	for (int i = 0; i < 5; i++)
	for (int j = 0; j < 5; j++)
		exarray[i][j] = p[i][j];
	path(5, 3);


	delete test.k;
	delete temp.k;
	delete p;
}