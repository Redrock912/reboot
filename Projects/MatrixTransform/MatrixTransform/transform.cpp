#include "Matrix.h"
#include "Vector.h"

// rotate about X-axis 
Matrix4D RotateX(float theta)
{ 
	Matrix4D rotx(1, 0, 0, 0, 0, cos(theta), -sin(theta), 0, 0, sin(theta), cos(theta), 0, 0, 0, 0, 1);
	return rotx;
}

Matrix4D RotateY(float theta)
{
	Matrix4D roty(cos(theta), 0, sin(theta), 0, 0, 1, 0, 0, -sin(theta),0, cos(theta), 0, 0, 0, 0, 1);
	return roty;
}

Matrix4D RotateZ(float theta)
{
	Matrix4D rotz(cos(theta), -sin(theta), 0, 0, sin(theta), cos(theta), 0, 0, 0, 0, 1,0,0,0,0,1);
	return rotz;
}
Matrix4D Translate(float x, float y, float z)
{
	Matrix4D trans(1, 0, 0, -x, 0, 1, 0, -y, 0, 0, 1, -z, 0, 0, 0, 1);
	return trans;
}

// rotate about u-axis 
Matrix4D Rotate(const Matrix4D &m,const Vector3D& u, float theta)
{
	float x, y, z,w;
	x = u.x;
	y = u.y;
	z = u.z;

	w=Magnitude(u);
	float ux, uy, uz,ud,xtheta,ytheta;
	ux = x / w;
	uy = y / w;
	uz = z / w;

	ud = pow(pow(uy, 2) + pow(uz, 2), 0.5);
	xtheta = acos(uy / ud);
	ytheta = acos(ud);

	Matrix4D temp;
	temp = Translate(x, y, z)*m;
	temp = RotateX(ytheta)*temp;
	temp = RotateY(ytheta)*temp;
	temp = RotateZ(theta)*temp;
	temp = Inverse(RotateY(ytheta))*temp;
	temp = Inverse(RotateX(xtheta))*temp;
	temp = Inverse(Translate(x, y, z))*temp;

	return temp;

}


Matrix4D Scale(float x, float y, float z)
{
	Matrix4D scl(x, 0, 0, 0, 0, y, 0, 0, 0, 0, z, 0, 0, 0, 0, 1);
	return scl;
}

Matrix4D ReflectX()
{
	Matrix4D refx(1, 0, 0, 0, 0, -1, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1);
	return refx;
}

Matrix4D ReflectY()
{
	Matrix4D refy(-1, 0, 0, 0, 0, 1, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1);
	return refy;
}