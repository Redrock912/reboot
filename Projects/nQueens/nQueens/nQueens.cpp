#include <iostream>
using namespace std;

int col[100] = { 0 };
int number;
bool promising(int i)
{
	int k = 1;
	bool Swit = true;
	while (k < i && Swit)
	{
		if (col[i] == col[k] || abs(col[i] - col[k]) == abs(i - k) )
		{
			Swit = false;
		}
		k++;
	}
	return Swit;
}

int Temp[100];
void queens(int i)
{
	int j;
	
	
	if (promising(i))
	{
		if (i == number)
		{
			for (int k = 1; k <= number; k++)
			{
				cout << col[k] << " ";
				Temp[k] = col[k];
			}
			cout << endl;
		}
		else
		{
			for (j = 1; j <= number; j++)
			{
				col[i + 1] = j;
				queens(i + 1);
			}
		}
	}
	
}

void main()
{
	cin >> number;

	queens(0);

	for (int i = 1; i <= number; i++)
	{
		for (int j = 1; j <= number; j++)
		{
			if (Temp[j]==i)
			cout << "O ";
			else
			cout << "X ";
		}
		cout << endl;
	}
}