#include <iostream>

using namespace std;

int main()
{
	int x1, y1;
	int x2, y2;

	cin >> x1 >> y1;
	cin >> x2 >> y2;

	int res1, res2;
	res1 = x1 - x2;
	res2 = y1 - y2;
	

	int leftover;
	int slant;

	slant = res2 / res1;
	leftover = (y1 - x1*slant);

	cout << slant << " " << leftover;

	return 0;
	
}