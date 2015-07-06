#include "Matrix.h"

Matrix3D& Matrix3D::operator *=(const Matrix3D& m)
{
	Matrix3D temp;
	for (int i = 0; i < 3; i++)
	for (int j = 0; j < 3; j++)
	{
		temp.n[i][j] = 0;
		for (int k = 0; k < 3; k++)
			temp.n[i][j] = temp.n[i][j] + n[i][k] * n[k][j];
	}

	for (int i = 0; i < 3; i++)
	for (int j = 0; j < 3; j++)
		this->n[i][j] = temp.n[i][j];

	return (*this);
}

Matrix3D& Matrix3D::operator *=(float t)
{
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			n[i][j] *= t;
		}
	}

	return (*this);
}

Matrix3D& Matrix3D::operator /=(float t)
{
	for (int i = 0; i < 3;i++)
	for (int j = 0; j < 3; j++){
		n[i][j] /= t;
	}

	return (*this);
}

Matrix3D& Matrix3D::SetIdentity(void)
{
	n[0][0] = n[1][1] = n[2][2] = 1.0F;
	n[0][1] = n[0][2] = n[1][0] = n[1][2] = n[2][0] = n[2][1] = 0.0F;

	return (*this);
}

Matrix3D operator *(const Matrix3D& m1, const Matrix3D& m2)
{
	Matrix3D temp;
	for (int i = 0; i < 3; i++)
	for (int j = 0; j < 3; j++)
	{
		temp.n[i][j] = 0;
		for (int k = 0; k < 3; k++)
			temp.n[i][j] = temp.n[i][j] + m1.n[i][k] * m2.n[k][j];
	}

	//temp.nomemoryfree = true

	return temp;
}


////////////////////////////////////////////////////////
Matrix3D operator *(const Matrix3D& m, float t)
{
	return (Matrix3D(m.n[0][0] * t, m.n[0][1] * t, m.n[0][2] * t,
		m.n[1][0] * t, m.n[1][1] * t, m.n[1][2] * t,
		m.n[2][0] * t, m.n[2][1] * t, m.n[2][2] * t));
}

Matrix3D operator *(float t, const Matrix3D& m)
{
	return m*t;
}

Matrix3D operator /(const Matrix3D& m, float t)
{
	float f = 1.0F / t;
	return (Matrix3D(m.n[0][0] * f, m.n[0][1] * f, m.n[0][2] * f,
		m.n[1][0] * f, m.n[1][1] * f, m.n[1][2] * f,
		m.n[2][0] * f, m.n[2][1] * f, m.n[2][2] * f));
}

Vector3D operator *(const Matrix3D& m, const Vector3D& v)
{
	float nx, ny, nz;
	nx = m.n[0][0] * v.x + m.n[0][1] * v.y + m.n[0][2] * v.z;
	ny = m.n[1][0] * v.x + m.n[1][1] * v.y + m.n[1][2] * v.z;
	nz = m.n[2][0] * v.x + m.n[2][1] * v.y + m.n[2][2] * v.z;
	return (Vector3D(nx,ny,nz));
}

//////////// 이 아래부분은 교환법칙이 성립안되기 때문에 지워야할 것 같지만 위의 식과 동일한 결과로 일단 나오게 했습니다.////
Vector3D operator *(const Vector3D& v, const Matrix3D& m)
{
	return m*v;
}


bool operator ==(const Matrix3D& m1, const Matrix3D& m2)
{
	return ((m1.n[0][0] == m2.n[0][0]) && (m1.n[0][1] == m2.n[0][1]) && (m1.n[0][2] == m2.n[0][2]) &&
		(m1.n[1][0] == m2.n[1][0]) && (m1.n[1][1] == m2.n[1][1]) && (m1.n[1][2] == m2.n[1][2]) &&
		(m1.n[2][0] == m2.n[2][0]) && (m1.n[2][1] == m2.n[2][1]) && (m1.n[2][2] == m2.n[2][2]));
}

bool operator !=(const Matrix3D& m1, const Matrix3D& m2)
{
	return ((m1.n[0][0] != m2.n[0][0]) || (m1.n[0][1] != m2.n[0][1]) || (m1.n[0][2] != m2.n[0][2])
		|| (m1.n[1][0] != m2.n[1][0]) || (m1.n[1][1] != m2.n[1][1]) || (m1.n[1][2] != m2.n[1][2])
		|| (m1.n[2][0] != m2.n[2][0]) || (m1.n[2][1] != m2.n[2][1]) || (m1.n[2][2] != m2.n[2][2]));
}

float Determinant(const Matrix3D& m)
{
	float f;
	f = m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1]) - m[0][1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0]) + m[0][2] * (m[1][0] * m[2][1] - m[2][0] * m[1][1]);
	return f;
}

Matrix3D Inverse(const Matrix3D& m)
{
	float a, b, c, d, e, f, g, h, i, Det;
	a = m[0][0];
	b = m[0][1];
	c = m[0][2];
	d = m[1][0];
	e = m[1][1];
	f = m[1][2];
	g = m[2][0];
	h = m[2][1];
	i = m[2][2];
	Det = Determinant(m);
	return Matrix3D((e*i - f*h) * (1 / Det), (c*h - b*i) * (1 / Det), (b*f - c*e) * (1 / Det), (f*g - d*i) * (1 / Det), (a*i - c*g) * (1 / Det), (c*d - a*f) * (1 / Det), (d*h - e*g) * (1 / Det), (b*g - a*h) * (1 / Det), (a*e - b*d)*(1 / Det));
}

Matrix3D Adjugate(const Matrix3D& m)
{
	float a, b, c, d, e, f, g, h, i;
	a = m[0][0];
	b = m[0][1];
	c = m[0][2];
	d = m[1][0];
	e = m[1][1];
	f = m[1][2];
	g = m[2][0];
	h = m[2][1];
	i = m[2][2];

	/*n00 = e*i - f*h;
	n10 = c*h - b*i;
	n20 = b*f - c*e;
	n01 = f*g - d*i;
	n11 = a*i - c*g;
	n21 = c*d - a*f;
	n02 = d*h - e*g;
	n12 = b*g - a*h;
	n22 = a*e - b*d;
	*/
	return Matrix3D((e*i - f*h), (c*h - b*i), (b*f - c*e) , (f*g - d*i) , (a*i - c*g) , (c*d - a*f) , (d*h - e*g) , (b*g - a*h), (a*e - b*d));

}

Matrix3D Transpose(const Matrix3D& m)
{

	return Matrix3D(m[0][0], m[1][0], m[2][0], m[0][1], m[1][1], m[2][1], m[0][2], m[1][2], m[2][2]);
}

Matrix4D& Matrix4D::operator =(const Matrix3D& m)
{
	n[0][0] = m[0][0];
	n[0][1] = m[0][1];
	n[0][2] = m[0][2];
	n[1][0] = m[1][0];
	n[1][1] = m[1][1];
	n[1][2] = m[1][2];
	n[2][0] = m[2][0];
	n[2][1] = m[2][1];
	n[2][2] = m[2][2];

	n[0][3] = n[1][3] = n[2][3] = n[3][0] = n[3][1] = n[3][2] = 0.0F;
	n[3][3] = 1.0F;

	return (*this);
}

Matrix4D& Matrix4D::operator *=(const Matrix4D& m)
{
	Matrix4D temp;
	for (int i = 0; i < 4; i++)
	for (int j = 0; j < 4; j++)
	{
		temp.n[i][j] = 0;
		for (int k = 0; k < 4; k++)
			temp.n[i][j] = temp.n[i][j] + n[i][k] * n[k][j];
	}

	for (int i = 0; i < 4; i++)
	for (int j = 0; j < 4; j++)
		this->n[i][j] = temp.n[i][j];
	
	return (*this);
}

Matrix4D& Matrix4D::SetIdentity(void)
{
	n[0][0] = n[1][1] = n[2][2] = n[3][3] = 1.0F;
	n[1][0] = n[2][0] = n[3][0] = n[0][1] = n[2][1] = n[3][1] = n[0][2] = n[1][2] = n[3][2] = n[0][3] = n[1][3] = n[2][3] = 0.0F;
	return (*this);
}

Matrix4D operator *(const Matrix4D& m1, const Matrix4D& m2)
{
	Matrix4D temp;
	for (int i = 0; i < 4; i++)
	for (int j = 0; j < 4; j++)
	{
		temp.n[i][j] = 0;
		for (int k = 0; k < 4; k++)
			temp.n[i][j] = temp.n[i][j] + m1.n[i][k] * m2.n[k][j];
	}

	//temp.nomemoryfree = true

	return temp;
}

Vector4D operator *(const Matrix4D& m, const Vector4D& v)
{
	float nx, ny, nz,nw;
	nx = m.n[0][0] * v.x + m.n[0][1] * v.y + m.n[0][2] * v.z + m.n[0][3] * v.w;
	ny = m.n[1][0] * v.x + m.n[1][1] * v.y + m.n[1][2] * v.z + m.n[1][3] * v.w;
	nz = m.n[2][0] * v.x + m.n[2][1] * v.y + m.n[2][2] * v.z + m.n[2][3] * v.w;
	nw = m.n[3][0] * v.x + m.n[3][1] * v.y + m.n[3][2] * v.z + m.n[3][3] * v.w;
	return (Vector4D(nx, ny, nz,nw));
}

////// 이 부분도 위의 vector3d 와 마찬가지로 교환법칙으로 성립은 안하지만, 위의 식과 같은 결과가 나오게끔 했습니다.////////
Vector4D operator *(const Vector4D& v, const Matrix4D& m)
{
	return m*v;
}


Matrix4D operator *(const Matrix4D& m, float t)
{
	return (Matrix4D(m.n[0][0] * t, m.n[0][1] * t, m.n[0][2] * t, m.n[0][3] * t,
		m.n[1][0] * t, m.n[1][1] * t, m.n[1][2] * t, m.n[1][3] * t,
		m.n[2][0] * t, m.n[2][1] * t, m.n[2][2] * t, m.n[2][3] * t, m.n[3][0] * t, m.n[3][1] * t, m.n[3][2] * t, m.n[3][3] * t));
}

bool operator ==(const Matrix4D& m1, const Matrix4D& m2)
{
	return ((m1.n[0][0] == m2.n[0][0]) && (m1.n[0][1] == m2.n[0][1]) && (m1.n[0][2] == m2.n[0][2]) && (m1.n[0][3] == m2.n[0][3]) && (m1.n[1][0] == m2.n[1][0]) && (m1.n[1][1] == m2.n[1][1]) && (m1.n[1][2] == m2.n[1][2]) && (m1.n[1][3] == m2.n[1][3]) && (m1.n[2][0] == m2.n[2][0]) && (m1.n[2][1] == m2.n[2][1]) && (m1.n[2][2] == m2.n[2][2]) && (m1.n[2][3] == m2.n[2][3]) && (m1.n[3][0] == m2.n[3][0]) && (m1.n[3][1] == m2.n[3][1]) && (m1.n[3][2] == m2.n[3][2]) && (m1.n[3][3] == m2.n[3][3]));
}

bool operator !=(const Matrix4D& m1, const Matrix4D& m2)
{
	return ((m1.n[0][0] != m2.n[0][0]) || (m1.n[0][1] != m2.n[0][1]) || (m1.n[0][2] != m2.n[0][2]) || (m1.n[0][3] != m2.n[0][3]) || (m1.n[1][0] != m2.n[1][0]) || (m1.n[1][1] != m2.n[1][1]) || (m1.n[1][2] != m2.n[1][2]) || (m1.n[1][3] != m2.n[1][3]) || (m1.n[2][0] != m2.n[2][0]) || (m1.n[2][1] != m2.n[2][1]) || (m1.n[2][2] != m2.n[2][2]) || (m1.n[2][3] != m2.n[2][3]) || (m1.n[3][0] != m2.n[3][0]) || (m1.n[3][1] != m2.n[3][1]) || (m1.n[3][2] != m2.n[3][2]) || (m1.n[3][3] != m2.n[3][3]));
}


float Determinant(const Matrix4D& m)
{
	Matrix3D m1(m[1][1],m[1][2],m[1][3],m[2][1],m[2][2],m[2][3],m[3][1],m[3][2],m[3][3]);
	Matrix3D m2(m[0][1],m[0][2],m[0][3],m[2][1],m[2][2],m[2][3],m[3][1],m[3][2],m[3][3]);
	Matrix3D m3(m[0][1],m[0][2],m[0][3],m[1][1],m[1][2],m[1][3],m[3][1],m[3][2],m[3][3]);
	Matrix3D m4(m[0][1],m[0][2],m[0][3],m[1][1],m[1][2],m[1][3],m[2][1],m[2][2],m[2][3]);
	float d1, d2, d3, d4;
	d1 = Determinant(m1);
	d2 = Determinant(m2);
	d3 = Determinant(m3);
	d4 = Determinant(m4);

	float det;
	det = m[0][0] * d1 - m[1][0] * d2 + m[2][0] * d3 - m[3][0] * d4;
	return det;
}
Matrix4D Inverse(const Matrix4D& m)
{
	float m00, m01, m02, m03, m10, m11, m12, m13, m20, m21, m22, m23, m30, m31, m32, m33, det;
	det = Determinant(m);
	m00 = (m[1][2]*m[2][3]*m[3][1] - m[1][3]*m[2][2]*m[3][1] + m[1][3]*m[2][1]*m[3][2] - m[1][1]*m[2][3]*m[3][2] - m[1][2]*m[2][1]*m[3][3] + m[1][1]*m[2][2]*m[3][3]) * (1/det);
	m01 = (m[0][3]*m[2][2]*m[3][1] - m[0][2]*m[2][3]*m[3][1] - m[0][3]*m[2][1]*m[3][2] + m[0][1]*m[2][3]*m[3][2] + m[0][2]*m[2][1]*m[3][3] - m[0][1]*m[2][2]*m[3][3]) * (1/det);
	m02 = (m[0][2]*m[1][3]*m[3][1] - m[0][3]*m[1][2]*m[3][1] + m[0][3]*m[1][1]*m[3][2] - m[0][1]*m[1][3]*m[3][2] - m[0][2]*m[1][1]*m[3][3] + m[0][1]*m[1][2]*m[3][3]) * (1/det);
	m03 = (m[0][3]*m[1][2]*m[2][1] - m[0][2]*m[1][3]*m[2][1] - m[0][3]*m[1][1]*m[2][2] + m[0][1]*m[1][3]*m[2][2] + m[0][2]*m[1][1]*m[2][3] - m[0][1]*m[1][2]*m[2][3]) * (1/det);
	m10 = (m[1][3]*m[2][2]*m[3][0] - m[1][2]*m[2][3]*m[3][0] - m[1][3]*m[2][0]*m[3][2] + m[1][0]*m[2][3]*m[3][2] + m[1][2]*m[2][0]*m[3][3] - m[1][0]*m[2][2]*m[3][3]) * (1/det);
	m11 = (m[0][2] * m[2][3] * m[3][0] - m[0][3] * m[2][2] * m[3][0] + m[0][3] * m[2][0] * m[3][2] - m[0][0] * m[2][3] * m[3][2] - m[0][2] * m[2][0] * m[3][3] + m[0][0] * m[2][2] * m[3][3]) * (1 / det);
	m12 = (m[0][3] * m[1][2] * m[3][0] - m[0][2] * m[1][3] * m[3][0] - m[0][3] * m[1][0] * m[3][2] + m[0][0] * m[1][3] * m[3][2] + m[0][2] * m[1][0] * m[3][3] - m[0][0] * m[1][2] * m[3][3]) * (1 / det);
	m13 = (m[0][2] * m[1][3] * m[2][0] - m[0][3] * m[1][2] * m[2][0] + m[0][3] * m[1][0] * m[2][2] - m[0][0] * m[1][3] * m[2][2] - m[0][2] * m[1][0] * m[2][3] + m[0][0] * m[1][2] * m[2][3]) * (1 / det);
	m20 = (m[1][1] * m[2][3] * m[3][0] - m[1][3] * m[2][1] * m[3][0] + m[1][3] * m[2][0] * m[3][1] - m[1][0] * m[2][3] * m[3][1] - m[1][1] * m[2][0] * m[3][3] + m[1][0] * m[2][1] * m[3][3]) * (1 / det);
	m21 = (m[0][3] * m[2][1] * m[3][0] - m[0][1] * m[2][3] * m[3][0] - m[0][3] * m[2][0] * m[3][1] + m[0][0] * m[2][3] * m[3][1] + m[0][1] * m[2][0] * m[3][3] - m[0][0] * m[2][1] * m[3][3]) * (1 / det);
	m22 = (m[0][1] * m[1][3] * m[3][0] - m[0][3] * m[1][1] * m[3][0] + m[0][3] * m[1][0] * m[3][1] - m[0][0] * m[1][3] * m[3][1] - m[0][1] * m[1][0] * m[3][3] + m[0][0] * m[1][1] * m[3][3]) * (1 / det);
	m23 = (m[0][3] * m[1][1] * m[2][0] - m[0][1] * m[1][3] * m[2][0] - m[0][3] * m[1][0] * m[2][1] + m[0][0] * m[1][3] * m[2][1] + m[0][1] * m[1][0] * m[2][3] - m[0][0] * m[1][1] * m[2][3]) * (1 / det);
	m30 = (m[1][2] * m[2][1] * m[3][0] - m[1][1] * m[2][2] * m[3][0] - m[1][2] * m[2][0] * m[3][1] + m[1][0] * m[2][2] * m[3][1] + m[1][1] * m[2][0] * m[3][2] - m[1][0] * m[2][1] * m[3][2]) * (1 / det);
	m31 = (m[0][1] * m[2][2] * m[3][0] - m[0][2] * m[2][1] * m[3][0] + m[0][2] * m[2][0] * m[3][1] - m[0][0] * m[2][2] * m[3][1] - m[0][1] * m[2][0] * m[3][2] + m[0][0] * m[2][1] * m[3][2]) * (1 / det);
	m32 = (m[0][2] * m[1][1] * m[3][0] - m[0][1] * m[1][2] * m[3][0] - m[0][2] * m[1][0] * m[3][1] + m[0][0] * m[1][2] * m[3][1] + m[0][1] * m[1][0] * m[3][2] - m[0][0] * m[1][1] * m[3][2]) * (1 / det);
	m33 = (m[0][1] * m[1][2] * m[2][0] - m[0][2] * m[1][1] * m[2][0] + m[0][2] * m[1][0] * m[2][1] - m[0][0] * m[1][2] * m[2][1] - m[0][1] * m[1][0] * m[2][2] + m[0][0] * m[1][1] * m[2][2]) * (1 / det);
	return Matrix4D(m00, m01, m02, m03, m10, m11, m12, m13, m20, m21, m22, m23, m30, m31, m32, m33);
}
Matrix4D Adjugate(const Matrix4D& m)
{
	float det;
	det = Determinant(m);
	Matrix4D inv;
	inv = Inverse(m);
	Matrix4D temp;
	temp = inv*det;
	return temp;
}
Matrix4D Transpose(const Matrix4D& m)
{
	return Matrix4D(m[0][0], m[1][0], m[2][0],m[3][0], m[0][1], m[1][1], m[2][1],m[3][1], m[0][2], m[1][2], m[2][2],m[3][2],m[0][3],m[1][3],m[2][3],m[3][3]);
}






