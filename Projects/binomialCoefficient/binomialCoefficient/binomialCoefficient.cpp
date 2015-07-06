#include <iostream>
using namespace std;

int bin(int n, int k)
{
	if (k == 0 || n == k)
	{
		return 1;
	}
	else
		return (bin(n - 1, k - 1) + bin(n - 1, k));
}

int bin2(int n, int k)
{
	int i, j, t;
	int ** b = new int*[n+1];
	for (int z = 0; z<n+1; z++)
		b[z] = new int[k+1];
	for (i = 0; i <= n; i++)
	{
		if (i> k)
			t = k;
		else
			t = i;
		for (j = 0; j <= t; j++)
		{
			if (j == 0 || j == i)
				b[i][j] = 1;
			else
				b[i][j] = b[i - 1][j - 1] + b[i - 1][j];
		}
	}
	return b[n][k];
}

void main()
{

	int row, column;

	cin >> row;
	cin >> column;

	int res;

	//res = bin(row, column);
	res = bin2(row, column);
	cout << res << endl;
}