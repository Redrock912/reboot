#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;
#define MAX 1000
#define LOW 0
void exSort(int n, int a[MAX])
{
	int i, j, temp;
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (a[j] < a[i])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

int location(int low, int high, int s[], int x)
{
	int mid;
	if (low > high)
		return -1;
	else
	{
		mid = (low + high) / 2;
		if (x == s[mid])
		{
			return mid;
		}
		else if (x < s[mid])
			return location(low, mid - 1, s, x);
		else if (x > s[mid])
			return location(mid + 1, high, s, x);
	}
}
//int binsearch(int* a, int x, int high)
//{
//	int location = 0;
//	int mid;
//	int low = 0;
//	while (low <= high && location == 0)
//	{
//		mid = (low + high) / 2;
//		if (x == a[mid])
//			location = mid + 1;
//		else if (x < a[mid])
//			high = mid - 1;
//		else
//		{
//			low = mid + 1;
//		}
//	}
//	return location;
//}

void merge(int h, int m, int u[], int v[], int s[])
{
	int i, j, k;
	i = 0; j = 0; k = 0;
	while (i < h && j < m)
	{
		if (u[i] < v[j])
		{
			s[k] = u[i];
			i++;
		}
		else
		{
			s[k] = v[j];
			j++;
		}
		k++;
	}
	if (i >= h)
	{
		for (int c = j; c < m; c++)
		{
			s[k] = v[c];
			k++;
		}
	}
	else if(j>=m)
	{
		for (int d = i; d < h; d++)
		{
			s[k] = u[d];
			k++;
		}
	}
}

void mergesort(int n, int a[])
{
	const int h = n / 2;
	const int m = n - h;
	int *u, *v;
	u = new int[h];
	v = new int[m];
	if (n > 1)
	{
		for (int i = 0; i < h; i++)
		{
			u[i] = a[i];
		}
		for (int j = h; j < n; j++)
		{
			v[j-h] = a[j];
		}
		mergesort(h, u);
		mergesort(m, v);
		merge(h, m, u, v, a);
	};

	delete u;
	delete v;
}

int main(void)
{
	int* s;
	s = new int[MAX];
	int k;
	srand(time(NULL));
	cout << "put in one number" << endl;
	cin >> s[0];
	for (int i = 1; i < MAX; i++)
	{
		s[i] = rand();
	}


	//exSort(MAX, s);
	mergesort(MAX, s);
	for (int n = 0; n < MAX; n++)
	{
		cout << s[n] << " ";
	}
	int num;
	cin >> num;
	int asdf;
	asdf = location(LOW, MAX, s, num);

	if (asdf != -1)
		cout << "Out of 1000 numbers... the number is in the  " << asdf << " th" << endl;
	else
		cout << "It is not in the list" << endl;

	delete[] s;
	return 0;
}