#ifndef _MATRIX_H_
#define _MATRIX_H_

#include "Vector.h"

class Matrix3D
{
private:
	Vector3D n[3];
public:
	Matrix3D() {}

	~Matrix3D() {
		// if (no memory free)
		// free n
	}

	Matrix3D(const Vector3D& c1, const Vector3D& c2, const Vector3D& c3){
		n[0] = c1; n[1] = c2; n[2] = c3;
	}

	Matrix3D(float n00, float n01, float n02, float n10, float n11, float n12, float n20, float n21, float n22){
		n[0] = Vector3D(n00, n01, n02);
		n[1] = Vector3D(n10, n11, n12);
		n[2] = Vector3D(n20, n21, n22);
	}
 
	float& operator ()(long i, long j)
	{
		return (n[i][j]);
	}

	const float& operator ()(long i, long j) const
	{
		return (n[i][j]);
	}

	Vector3D& operator [](long j)
	{
		return n[j];
	}

	const Vector3D& operator [](long j) const
	{
		return n[j];
	}


	Matrix3D& operator *=(const Matrix3D& m);
	Matrix3D& operator *=(float t);
	Matrix3D& operator /=(float t);

	Matrix3D& SetIdentity(void);

	friend Matrix3D operator *(const Matrix3D& m1, const Matrix3D& m2);
	friend Matrix3D operator *(const Matrix3D& m, float t);
	friend Matrix3D operator *(float t, const Matrix3D& m);
	friend Matrix3D operator /(const Matrix3D& m, float t);
	friend Vector3D operator *(const Matrix3D& m, const Vector3D& v);
	friend Vector3D operator *(const Vector3D& v, const Matrix3D& m);

	friend bool operator ==(const Matrix3D& m1, const Matrix3D& m2);
	friend bool operator !=(const Matrix3D& m1, const Matrix3D& m2);
};


float Determinant(const Matrix3D& m);
Matrix3D Inverse(const Matrix3D& m);
Matrix3D Adjugate(const Matrix3D& m);
Matrix3D Transpose(const Matrix3D& m);

class Matrix4D
{
private:
	Vector4D n[4];

public:
	Matrix4D() {}

	Matrix4D(const Vector4D& c1, const Vector4D& c2, const Vector4D& c3, const Vector4D& c4){
		n[0] = c1; n[1] = c2; n[2] = c3; n[3] = c4;
	};

	Matrix4D(float n00, float n01, float n02, float n03, float n10, float n11, float n12, float n13, float n20, float n21, float n22, float n23, float n30, float n31, float n32, float n33){
		n[0][0] = n00; n[0][1] = n01; n[0][2] = n02; n[0][3] = n03;
		n[1][0] = n10; n[1][1] = n11; n[1][2] = n12; n[1][3] = n13;
		n[2][0] = n20; n[2][1] = n21; n[2][2] = n22; n[2][3] = n23;
		n[3][0] = n30; n[3][1] = n31; n[3][2] = n32; n[3][3] = n33;
	};

	float& operator ()(long i, long j)
	{
		return (n[i][j]);
	}

	const float& operator ()(long i, long j) const
	{
		return (n[i][j]);
	}

	Vector4D& operator [](long j)
	{
		return (n[j]);
	}

	const Vector4D& operator [](long j) const
	{
		return (n[j]);
	}

	Matrix4D& operator =(const Matrix3D& m);
	Matrix4D& operator *=(const Matrix4D& m);

	Matrix4D& SetIdentity(void);

	friend Matrix4D operator *(const Matrix4D& m1, const Matrix4D& m2);
	friend Vector4D operator *(const Matrix4D& m, const Vector4D& v);
	friend Vector4D operator *(const Vector4D& v, const Matrix4D& m);
	friend Matrix4D operator *(const Matrix4D& m, float t);
	friend bool operator ==(const Matrix4D& m1, const Matrix4D& m2);
	friend bool operator !=(const Matrix4D& m1, const Matrix4D& m2);
};


float Determinant(const Matrix4D& m);
Matrix4D Inverse(const Matrix4D& m);
Matrix4D Adjugate(const Matrix4D& m);
Matrix4D Transpose(const Matrix4D& m);

#endif