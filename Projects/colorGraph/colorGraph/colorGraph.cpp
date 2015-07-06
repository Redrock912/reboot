#include <iostream>
using namespace std;
int n;
int vcolor[10] = {};
int m;
int W[6][6] = {};

bool promising(int i)
{
	int j = 0;
	bool swit = true;
	while (j < i && swit)
	{
		if (W[i][j] && vcolor[i] == vcolor[j])
			swit = false;
		j++;
	}

	return swit;
}

void m_coloring(int i)
{
	int color;
	if (promising(i))
	{

		if (i == n)
		{
			for (int j = 1; j <= n; j++)
			{
				cout << vcolor[j] << " " ;
			}
			cout << endl;
		}
		else
		{
			for (color = 1; color <= m; color++)
			{
				vcolor[i+1] = color;
				m_coloring(i + 1);
			}
		}
	}
}

void m_coloring2(int i)
{
	int j = 0;
	int color;
	bool swit = true;
	while (j < i && swit)
	{
		if (W[i][j] && vcolor[i] == vcolor[j])
			swit = false;
		j++;
	}
	if (swit)
	{
		if (i == n)
		{
			for (int j = 1; j <= n; j++)
			{
				cout << vcolor[j] << " ";
			}
			cout << endl;
		}
		else
		{
		
			vcolor[i+1] = 1;
			
			if (vcolor[i + 1] == vcolor[j])
				vcolor[i + 1] = vcolor[j] % 3 + 1;
			m_coloring2(i + 1);
		}
	}
}

int main()
{
	W[6][1] = 1;
	W[1][6] = 1;
	W[2][1] = 1;
	W[1][2] = 1;
	W[2][3] = 1;
	W[3][2] = 1;
	W[3][4] = 1;
	W[4][3] = 1;
	W[5][4] = 1;
	W[4][5] = 1;
	W[5][6] = 1;
	W[6][5] = 1;
	W[5][2] = 1;
	W[2][5] = 1;
	
	n = 6;
	m = 3;

	m_coloring2(0);
}