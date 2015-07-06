#include <iostream>
using namespace std;

#define MAX 1000

int fib(int n)
{
	if (n <= 1)
		return n;
	else
		return (fib(n - 1) + fib(n - 2));
}

int fib2(int n)
{
	int a[MAX];
	int i;
	a[0] = 0;
	a[1] = 1;
	if (n > 0){
		for ( i = 2; i <= n; i++)
			a[i] = a[i - 1] + a[i - 2];
	}
	return a[n];
}

void main()
{
	int f, g,c;
	cout << "How do you wish to use your algorithm? If you wish to use the recursive way press 1, or if you wish to use iterative way press 2" << endl;
	cin >> g;
	if (g == 1)
	{
		cout << "what fibonacci number do you wish to find?" << endl;
		cin >> f;
		f=fib(f);
		cout << f;
	}
	else if (g == 2)
	{
		cout << "what fibonacci number do you wish to find?" << endl;
		cin >> f;
		f=fib2(f);
		cout << f;

	}
	else
		cout << "wrong number" << endl;
	cin >> c;
}