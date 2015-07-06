#include <iostream>
using namespace std;

int P[100][800];
int A[5][2];
int Count[10];
int QWE = 0;
int max(int x1, int x2)
{

	if (x1 >= x2)
		return x1;
	else
		Count[QWE] += 1;
		return x2;
}





int knapsack(int i,int w)
{
	if (i == 0 || w <= 0)
	{
		return A[i][1];
	}

	if (A[i][0] <= w)
	{
		
		QWE = i;
		return max(knapsack(i - 1,w), A[i][1] + knapsack(i - 1,w - A[i][0]));
		//if ([i][w] == A[i][1] + P[i - 1][w - A[i][0]])
		

	}
	else
	{
		return knapsack(i - 1,w);
	}

}

int main()
{
	A[0][0] = 2;
	A[0][1] = 3;
	A[1][0] = 3;
	A[1][1] = 4;
	A[2][0] = 4;
	A[2][1] = 5;
	A[3][0] = 5;
	A[3][1] = 8;
	A[4][0] = 9;
	A[4][1] = 10;
	int k;
	k = knapsack(4, 20);

	cout << k << endl;
	
	for (int i = 0; i < 10; i++)
	{
		//if (Count[i] == 1)
			cout << Count[i] << endl;
	}

}