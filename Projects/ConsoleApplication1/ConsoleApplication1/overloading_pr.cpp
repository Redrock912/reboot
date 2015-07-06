#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{	}
	void ShowPosition() const
	{
		cout << '[' << xpos << "," << ypos << ']' << endl;
	}
	Point operator-=(const Point &posw)
	{
		Point pos(xpos -= posw.xpos, ypos -= posw.ypos);
		return pos;
	}

	Point operator+=(const Point &posw)
	{
		Point pos(xpos += posw.xpos, ypos += posw.ypos);
		return pos;
	}
};

//Point operator-(const Point &posk, const Point &posl)
//{
//	Point pos(posk.xpos - posl.xpos, posk.ypos - posl.ypos);
//	return pos;
//}
int main(void)
{
	Point pos1(3, 4);
	Point pos2(10, 15);
	pos1 += pos2;
	int k;
	pos1.ShowPosition();

	pos2.ShowPosition();

	pos1 -= pos2;
	pos1.ShowPosition();
	cin >> k;
	return 0;
}