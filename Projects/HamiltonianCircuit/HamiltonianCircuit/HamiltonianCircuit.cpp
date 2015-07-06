#include <iostream>
using namespace std;

int n;
int vindex[10];
int W[13][13] = {};
bool promising(int i)
{
	int j = 1;
	bool swit = true;
	if (i == n - 1 && !W[vindex[n - 1]][vindex[0]])
		swit = false;
	else if (i > 0 && !W[vindex[i - 1]][vindex[i]])
		swit = false;
	else
	{
		while (j < i && swit)
		{
			if (vindex[i] == vindex[j])
				swit = false;
			j++;
		}
	}
	return swit;
}

void hamiltonian(int i)
{
	int j;
	if (promising(i))
	{
		if (i == n - 1)
		{
			for (int k = 0; k < n; k++)
				cout << vindex[k] << " ";
			cout << endl;
		}
		else
		{
			for (j = 2; j <= n; j++)
			{
				vindex[i + 1] = j;
				hamiltonian(i + 1);
			}
		}
	}
}


int main()
{
	n = 12;
	W[1][2] = 1;
	W[2][1] = 1;
	W[1][5] = 1;
	W[5][1] = 1;
	W[2][3] = 1;
	W[3][2] = 1;
	W[7][2] = 1;
	W[2][7] = 1;
	W[2][8] = 1;
	W[8][2] = 1;
	W[3][4] = 1;
	W[4][3] = 1;
	W[3][8] = 1;
	W[8][3] = 1;
	W[4][9] = 1;
	W[9][4] = 1;
	W[5][6] = 1;
	W[6][5] = 1;
	W[5][10] = 1;
	W[10][5] = 1;
	W[6][7] = 1;
	W[7][6] = 1;
	W[6][11] = 1;
	W[11][6] = 1;
	W[8][9] = 1;
	W[9][8] = 1;
	W[10][11] = 1;
	W[11][10] = 1;
	W[11][12] = 1;
	W[12][11] = 1;
	W[12][9] = 1;
	W[9][12] = 1;
	W[8][12] = 1;
	W[12][8] = 1;

	hamiltonian(0);

	return 0;
}