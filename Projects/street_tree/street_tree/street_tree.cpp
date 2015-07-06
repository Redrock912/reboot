#include <iostream>
using namespace std;

int main()
{
	int num;
	int temp;
	int res;
	int res2;
	cin >> num;

	int* a;
	int* b;
	a = new int[num];
	b = new int[num];
	for (int i = 0; i < num; i++)
	{
		cin >> a[i];
	}

	for (int i = 0; i < num - 1; i++)
	{
		b[i] = a[i + 1] - a[i];
	}
	if (b[1] - b[0]>0)
		res2 = b[1] - b[0];
	else
		res2 = b[0] - b[1];
	for (int i = 1; i < num - 1; i++)
	{
		for (int j = 0; j < num - 2; j++)
		{
			if (b[i] < b[j])
			{
				temp = b[i];
				b[i] = b[j];
				b[j] = temp;
			}

			while (b[i] - b[j] >= 0)
			{
				res = b[i] - b[j];
				b[i] = b[j];
				b[j] = res;
			}
			if (res != 0 && res2 > res)
				res2 = res;
		}
	}

	int count;
	//////////////// 이부분까지와서 잘못된걸 깨달음 애초에 입력값은 오름차순으로 받는거였다니....
	count = a[num - 1] - a[0];
	count = count / res2;
	count = count + 1 - num;

	cout << count << endl;
	delete[] a;
	delete[] b;
}