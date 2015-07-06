#include <iostream>
using namespace std;
#define Max 20
/*
점화식 A(n) = 2*A(n-1)+1

*/
int solve(int n, int a[Max], int b[Max], int c[Max])
{
	if (n == 1)
	{
		cout << "Move A -> B" << endl;
		return 1;
	}
	else
	{
		solve(n - 1, a, c, b);
		cout << "" << endl;
		solve(n - 1, c, b, a);
	}
}

void move(int a[Max], int b[Max], int c[Max])
{

	for (int i = Max; i >= 0; i--)
	{
		if (a[i] != -1)
		{
			for (int j = Max; j >= 0; j--)
			{
				if (b[j] != -1 && b[j] > a[i])
				{
					b[j] = a[i];
					a[i] = -1;
					cout << "Move A->B" << endl; // 이부분 고쳐야함
				}
				else if (b[j] != -1 && b[j] < a[i])
				{
					for (int k = 0; k < Max; k++)
					{
						int count = 0;
						if (c[k] == -1)
						{
							c[k] = a[i];
							a[i] = -1;
							cout << "Move A->C" << endl; // 이부분 고쳐야함
							count += 1;
						}
						if (count != 0)
							break;
					}
				}
			}
		}
	}
}

void main()
{
	int n;
	cin >> n;
	int source[Max] = { -1 };
	int spare[Max] = { -1 };
	int dest[Max] = { -1 };

	for (int i = 0; i < n; i++)
	{
		int k = n;
		source[i] = k;
		k = k - 1;
	}

	move(source, spare, dest);
}




