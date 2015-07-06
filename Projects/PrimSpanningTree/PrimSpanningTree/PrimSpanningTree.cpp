#include <iostream>
using namespace std;



class edge
{
public:
	int i;
	int j;
	int weight;
	edge()
	{

	}
	edge(int a,int b,int c)
	{
		i = a;
		j = b;
		weight = c;
	}

	void set(int a, int b, int c)
	{
		i = a;
		j = b;
		weight = c;
	}

};

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

void prim(int n, Matp W, edge F[])
{
	int *nearest;
	int *distance;
	int i, vnear;
	int min;
	nearest = new int[n];
	distance = new int[n];

	
	////////////////////////////////////////
	for (int i = 1; i < n; i++)
	{
		nearest[i] = 1;
		distance[i] = W.k[0][i];
	}

	for (int i = 0; i < n; i++)
	{
		min = 1000;
		for (int j = 1; j < n; j++)
		{
			if (distance[j] >= 0 && distance[j] < min)
			{
				min = distance[j];
				vnear = j;
				//k[j - 1] = vnear;//
			}
		}
		F[i].weight = W.k[vnear][nearest[vnear]];
		
		distance[vnear] = -1;
		for (int j = 1; j < n; j++)
		{
			if (W.k[j][vnear] < distance[j])
			{
				distance[j] = W.k[j][vnear];
				nearest[j] = vnear;
			}
		}
		F[i].i = vnear;
		F[i].j = nearest[vnear];

	}

	for (int i = 0; i <=8; i++)
		cout << "v" << F[i].i+1 << " " << "v" << F[i].j+1 << " " << F[i].weight << endl;



	delete [] nearest;
	delete [] distance;
}

void dijkstra(int n, Matp W, edge F[])
{
	int i, vnear;
	int min;

	int* touch;
	int* length;

	touch = new int[n];
	length = new int[n];

	for (int i = 1; i < n; i++)
	{
		touch[i] = 0;
		length[i] = W.k[0][i];
	}

	for (int i = 0; i < n-1; i++)
	{
		min = 1000;
		for (int j = 1; j < n; j++)
		{
			if (length[j] >= 0 && length[j] < min)
			{
				min = length[j];
				vnear = j;
			}
		}

		F[i].i = vnear;
		F[i].j = touch[vnear];
		F[i].weight = W.k[vnear][touch[vnear]];

		for (int j = 1; j < n; j++)
		{
			if (length[vnear] + W.k[vnear][j] < length[j])
			{
				length[j] = length[vnear] + W.k[vnear][j];
				touch[j] = vnear;
			}
		}
		length[vnear] = -1;
	}

	for (int i = 0; i < 7; i++)
		cout << "v" << F[i].i + 1 << " " << "v" << F[i].j + 1 << " " << F[i].weight << endl;


	
	delete[] touch;
	delete[] length;
}

void main()
{
	//edge F[5];
	//
	//Matp path(5, 5);
	//path.k[0][0] = 0;
	//path.k[0][1] = 1;
	//path.k[0][2] = 3;
	//path.k[0][3] = 1000;
	//path.k[0][4] = 1000;
	//path.k[1][0] = 1;
	//path.k[1][1] = 0;
	//path.k[1][2] = 3;
	//path.k[1][3] = 6;
	//path.k[1][4] = 1000;
	//path.k[2][0] = 3;
	//path.k[2][1] = 3;
	//path.k[2][2] = 0;
	//path.k[2][3] = 4;
	//path.k[2][4] = 2;
	//path.k[3][0] = 1000;
	//path.k[3][1] = 6;
	//path.k[3][2] = 4;
	//path.k[3][3] = 0;
	//path.k[3][4] = 5;
	//path.k[4][0] = 1000;
	//path.k[4][1] = 1000;
	//path.k[4][2] = 2;
	//path.k[4][3] = 5;
	//path.k[4][4] = 0;

	//prim(5, path, F);
	//dijkstra(5, path, F);

	edge F[9];
	Matp path(9, 9);
	path.k[0][0] = 0;
	path.k[0][1] = 7;
	path.k[0][2] = 8;
	path.k[0][3] = 1000;
	path.k[0][4] = 3;
	path.k[0][5] = 1000;
	path.k[0][6] = 1000;
	path.k[0][7] = 1000;
	path.k[1][0] = 7;
	path.k[1][1] = 0;
	path.k[1][2] = 12;
	path.k[1][3] = 1000;
	path.k[1][4] = 4;
	path.k[1][5] = 7;
	path.k[1][6] = 5;
	path.k[1][7] = 1000;
	path.k[2][0] = 8;
	path.k[2][1] = 12;
	path.k[2][2] = 0;
	path.k[2][3] = 4;
	path.k[2][4] = 1000;
	path.k[2][5] = 1000;
	path.k[2][6] = 7;
	path.k[2][7] = 1000;
	path.k[3][0] = 1000;
	path.k[3][1] = 1000;
	path.k[3][2] = 4;
	path.k[3][3] = 0;
	path.k[3][4] = 1000;
	path.k[3][5] = 1000;
	path.k[3][6] = 7;
	path.k[3][7] = 2;
	path.k[4][0] = 3;
	path.k[4][1] = 4;
	path.k[4][2] = 1000;
	path.k[4][3] = 1000;
	path.k[4][4] = 0;
	path.k[4][5] = 5;
	path.k[4][6] = 1000;
	path.k[4][7] = 1000;
	path.k[5][0] = 1000;
	path.k[5][1] = 7;
	path.k[5][2] = 1000;
	path.k[5][3] = 1000;
	path.k[5][4] = 5;
	path.k[5][5] = 0;
	path.k[5][6] = 17;
	path.k[5][7] = 8;
	path.k[6][0] = 1000;
	path.k[6][1] = 5;
	path.k[6][2] = 7;
	path.k[6][3] = 7;
	path.k[6][4] = 1000;
	path.k[6][5] = 17;
	path.k[6][6] = 0;
	path.k[6][7] = 9;
	path.k[7][0] = 1000;
	path.k[7][1] = 1000;
	path.k[7][2] = 1000;
	path.k[7][3] = 2;
	path.k[7][4] = 1000;
	path.k[7][5] = 8;
	path.k[7][6] = 9;
	path.k[7][7] = 0;
	
	//prim(9, path, F);
	dijkstra(9, path, F);
}