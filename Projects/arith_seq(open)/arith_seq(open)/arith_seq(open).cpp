#include <iostream>
using namespace std;

int main()
{
	int a, d, an;
	cin >> a;
	cin >> d;
	cin >> an;
	int count=1;
	bool res = true;
	for (int i = a; i <= an; i=i + d)
	{
		if (i == an)
		{
			res = true;
			cout << count << endl;
		}
		res = false;
		count++;
	}
	if (!res)
		cout << "X" << endl;
	return 0;
}