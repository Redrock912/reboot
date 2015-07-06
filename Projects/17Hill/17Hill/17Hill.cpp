#include <iostream>
using namespace std;

void main()
{
	int Hill[] = { 1, 98, 99 };
	int N = 3;
	int sumOfDiff=0;
	int average = 0;

	for (int i = 0; i < N; i++)
	{
		average = average + Hill[i];
	}
	average = average / N;

	cout << average << endl;
	for (int i = 0; i < N; i++)
	{
		if (Hill[i] < (average - 8))
		{
			Hill[i] = (-1)*Hill[i];
		}
	}

	for (int i = 0; i < N; i++)
	{
		sumOfDiff += Hill[i];
	}
	cout << sumOfDiff << endl;


}