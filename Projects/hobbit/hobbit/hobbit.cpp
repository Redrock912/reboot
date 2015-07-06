#include <iostream>
using namespace std;

int main()
{
	int a[] = { 7, 8, 10, 13, 15, 19, 20, 23, 25 };
	int sum = 0;;
	int ans;
	int ex1, ex2;

	for (int i = 0; i < 9; i++)
	{
		sum += a[i];
	}

	ans = sum - 100;

	for (int i = 0; i < 9;i++)
	for (int j = 0; j < 9; j++)
	{
		if (ans == a[i] + a[j])
		{
			ex1 = i;
			ex2 = j;
		}
	}

	for (int i = 0; i < 9; i++)
	{
		if (!(i == ex1 || i == ex2))
			cout << a[i] << " ";
	}
	return 0;
}