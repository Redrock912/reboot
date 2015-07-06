#include <iostream>
#include "Vector2D.h"
//#include "matrix3D.h"
using namespace std;


Vector2D projected_pt_onto_line(Vector2D p, Vector2D v, Vector2D q)
{
	// the line is defined as p+t*v
	// where p is the point position on the line
	//       v is the directional vector along the line
	//       t is the scalar values

	// Compute the projected point of q on the line "p+t*v" 
	return Dot(q - p, v) / pow(v.Magnitude(), 2) * v;
}

float dist_btw_pt_line(Vector2D p, Vector2D v, Vector2D q)
{
	// compute the distance between the point q and the line "p+t*v"
	return pow(pow((q - p).Magnitude(), 2) - pow(Dot(q - p, v)/v.Magnitude(), 2), 0.5);
}

bool same_side_of_plane(Vector3D a, Vector3D b, Vector3D c, Vector3D p, Vector3D q)
{

	// point a, b, c define the plane 
	// Let's decide whether point p and point q are on the same side of the plane
	if (Dot(Cross(a - b, b - c), p)*Dot(Cross(a - b, b - c), q) > 0)
	{
		return true;
	}
	else
		return false;
}
//
float dist_from_pt_to_plane(Vector3D a, Vector3D b, Vector3D c, Vector3D p)
{
	// point a, b, c define the plane 
	// Compute the distance from point p to the plane
	Vector3D k;
	k = Cross(a - b, b - c);
	
	return Dot(p-a,k)/k.Magnitude();
}

int main(void)
{
	Vector2D v1(3,7), v2(-12,5), v5(4,5);
	Vector3D v3(8, -3, 0.5), v4(4, -7, 0);
	float x;
	v1 *= -1;
	// Q1 
	cout << "////////////////// Question 1 /////////////////////" << endl;
	//a
	cout << v1.x << " " << v1.y << endl;
	//b
	cout << v2.Magnitude() << endl;
	//c
	cout << v3.Magnitude() << endl;
	//d
	v4 *= 3;
	cout << v4.x << " " << v4.y << " " << v4.z << endl;
	//e
	v5 /= 2;
	cout << v5.x << " " << v5.y << endl<<endl;

	//Q2
	cout << "////////////////// Question 2 /////////////////////" << endl;
	Vector3D v6(7, -2, -3), v7(6, 6, -4), v8(2, 9, -1), v9(-2, -9, 1), v10(3, 10, 7), v11(8, -7, 4), v12(4, 5, -11), v13(-4, -5, 11), v14, v15(2, 10, -6);
	Vector3D qa,qb,qc,qd,qe;
	//a
	qa = v6 + v7;
	cout << qa.x << " " << qa.y << " " << qa.z << endl;
	//b
	qb = v8 + v9;
	cout << qb.x << " " << qb.y << " " << qb.z << endl;
	//c
	qc = v10 - v11;
	cout <<qc.x << endl << qc.y << endl << qc.z << endl << endl;
	//d
	qd = v12 - v13;
	cout << qd.x << endl << qd.y << endl << qd.z << endl << endl;
	//e
	float a, b, c;
	cout << "Set the parameters for the Q2.(e) " << endl;
	cin >>a;
	cin >> b;
	cin >> c;
	v14.Set(a, b, c);  // ÁÂÇ¥°ª ¼³Á¤
	qe = v14*3 - v15*4;

	cout << qe.x << endl << qe.y << endl << qe.z << endl << endl;

	//Q3
	cout << "////////////////// Question 3 /////////////////////" << endl;
	Vector2D a1(10, 6), a2(-14, 30), b1(0, 0), b2(-12, 5);
	Vector3D c1(3, 10, 7), c2(8, -7, 4), d1(-2, -4, 9), d2(6, -7, 9.5);
	Vector4D e1(4, -4, -4, 4), e2(-6, 6, 6, -6);

	//a
	cout << (a1 - a2).Magnitude() << endl;
	//b
	cout << (b1 - b2).Magnitude() << endl;
	//c
	cout << (c1 - c2).Magnitude() << endl;
	//d
	cout << (d1 - d2).Magnitude() << endl;
	//e
	cout << (e1 - e2).Magnitude() << endl<< endl;

	//Q4
	cout << "////////////////// Question 4 /////////////////////" << endl;

	Vector2D f1(2, 6), f2(-3, 8), g1(1, 2), g2(11, -4);
	Vector3D  h1(-5, 1, 3), h2(4, -13, 9), i1(-2, 0, 4), i2(8, -2, 1.5), i3(0, 9, 7),temp;
	float q4a, q4b, q4c, q4d;
	
	//a
	q4a = Dot(f1, f2);
	cout << q4a << endl;
	//b
	q4b = Dot(g1, g2);
	cout << -7 * q4b << endl;
	//c
	q4c = Dot(h1, h2);
	cout << 10 + q4c << endl;
	//d
	temp = i2 + i3;
	q4d = Dot(i1, temp);
	cout << 3 * q4d << endl;
	
	
	
	

	/*Vector2D v4(0, 0), v5(0, 2), v6(19, 1);
	cout << re.x << " " << re.y << endl;
	
	x = dist_btw_pt_line(v4, v5, v6);

	cout << x << endl;

	Vector3D v7(0, 0, 0), v8(1, 0, 0), v9(0, 0, 1), v10(0, 3, 0), v11(-1, -4, 2);
	if (same_side_of_plane(v7, v8, v9, v10, v11))
	{
		cout << "Yes" << endl;
	}
	else
		cout << "NO" << endl;

	Vector3D va(0, 0, 0), vb(0, 0, 1), vc(1, 1, 0), vd(0, 1, 0);
	float k;
	k = dist_from_pt_to_plane(va, vb, vc, vd);
	cout << k << endl;*/
	return 0;

	
}