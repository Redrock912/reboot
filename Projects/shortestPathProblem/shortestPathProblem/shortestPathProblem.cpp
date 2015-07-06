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
			cin >> a;
			k[i][j] = a;
		}
	}


};

void floyd(int n,const Matp& a, Matp b)
{
	int i, j, k;
	for (int i = 0; i < a.row;i++)
	for (int j = 0; j < a.column; j++)
		b.k[i][j] = a.k[i][j];

	for (k = 0; k < n; k++){
		for (i = 0; i < n; i++){
			for (j = 0; j < n; j++){
				if (b.k[i][j] > b.k[i][k] + b.k[k][j])
					b.k[i][j] = b.k[i][k] + b.k[k][j];
			}
		}
	}

}

void floyd2(int n, const Matp& a, Matp b, int **c)
{
	for (int i = 0; i < n;i++)
	for (int j = 0; j < n; j++)
		c[i][j] = 0;

	for (int i = 0; i < a.row; i++)
	for (int j = 0; j < a.column; j++)
		b.k[i][j] = a.k[i][j];

	for (int k = 0; k < n; k++){
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if (b.k[i][j] > b.k[i][k] + b.k[k][j]){
					c[i][j] = k + 1;
					b.k[i][j] = b.k[i][k] + b.k[k][j];
				}
			}
		}
	}
}


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
		path(q, exarray[q-1][r-1]);
		cout << " v" << exarray[q - 1][r - 1];
		path(exarray[q-1][r-1], r);
	}
}


void main()
{
	int number, row, column;
	int **p;
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