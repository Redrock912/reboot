#include <iostream>
using namespace std;


int binsearch(int* a, int x, int high)
{
	int location = 0;
	int mid;
	int low = 0;
	while (low <= high && location == 0)
	{
		mid = (low + high) / 2;
		if (x == a[mid])
			location = mid+1;
		else if (x < a[mid])
			high = mid - 1;
		else
		{
			low = mid + 1;
		}
	}
	return location;
}

void main()
{
	int low, high, mid;
	int x;
	int result;
	cout << "Type in the length of numbers" << endl;
	int inputListNumber;
	cin >> inputListNumber;
	int *List = new int[inputListNumber];

	cout << "Type in the numbers in an ascending order" << endl;
	for (int i = 0; i < inputListNumber; i++)
	{
		cin >> List[i];
	}

	cout << "which number do you wish to find?";

	cin >> x;

	result = binsearch(List, x, inputListNumber);

	if (result == 0)
	{
		cout << "No match in this list";
	}
	else
	{
		cout << result << endl;
	}
	delete[] List;
}