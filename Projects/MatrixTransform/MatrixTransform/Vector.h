//============================================================================
//
// 2D/3D/4D Vector Classes
//
//
//============================================================================
#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <cmath>

class Vector2D
{
public:

	float	x;
	float	y;

	Vector2D() {}

	Vector2D(float r, float s)
	{
		x = r;
		y = s;
	}

	Vector2D& Set(float r, float s)
	{
		x = r;
		y = s;
		return (*this);
	}

	float& operator [](long k)
	{
		return ((&x)[k]);
	}

	const float& operator [](long k) const
	{
		return ((&x)[k]);
	}

	Vector2D& operator +=(const Vector2D& v)
	{
		x += v.x;
		y += v.y;
		return (*this);
	}

	Vector2D& operator -=(const Vector2D& v)
	{
		x -= v.x;
		y -= v.y;
		return (*this);
	}

	Vector2D& operator *=(float t)
	{
		x *= t;
		y *= t;
		return (*this);
	}

	Vector2D& operator /=(float t)
	{
		float f = 1.0F / t;
		x *= f;
		y *= f;
		return (*this);
	}

	Vector2D& operator &=(const Vector2D& v)
	{
		x *= v.x;
		y *= v.y;
		return (*this);
	}

	Vector2D& Normalize(const Vector2D &v)
	{
		return (*this *= 1 / Magnitude(v));
	}
	float Magnitude(const Vector2D& v)
	{
		return pow(v.x*v.x + v.y*v.y, 0.5);
	}
};


inline Vector2D operator -(const Vector2D& v)
{
	return (Vector2D(-v.x, -v.y));
}

inline Vector2D operator +(const Vector2D& v1, const Vector2D& v2)
{
	return (Vector2D(v1.x + v2.x, v1.y + v2.y));
}

inline Vector2D operator -(const Vector2D& v1, const Vector2D& v2)
{
	return (Vector2D(v1.x - v2.x, v1.y - v2.y));
}

inline Vector2D operator *(const Vector2D& v, float t)
{
	return (Vector2D(v.x * t, v.y * t));
}

inline Vector2D operator *(float t, const Vector2D& v)
{
	return (Vector2D(t * v.x, t * v.y));
}

inline Vector2D operator /(const Vector2D& v, float t)
{
	float f = 1.0F / t;
	return (Vector2D(v.x * f, v.y * f));
}


inline bool operator ==(const Vector2D& v1, const Vector2D& v2)
{
	return ((v1.x == v2.x) && (v1.y == v2.y));
}

inline bool operator !=(const Vector2D& v1, const Vector2D& v2)
{
	return ((v1.x != v2.x) || (v1.y != v2.y));
}

inline float Dot(const Vector2D& v1, const Vector2D& v2)
{
	return v1.x*v2.x + v1.y*v2.y;
}


inline float Magnitude(const Vector2D& v)
{
	return pow(v.x*v.x + v.y*v.y, 0.5);
}




class Vector3D
{
public:

	float	x;
	float	y;
	float	z;

	Vector3D() {}

	Vector3D(float r, float s, float t)
	{
		x = r;
		y = s;
		z = t;
	}

	Vector3D(const Vector2D& v)
	{
		x = v.x;
		y = v.y;
		z = 0.0F;
	}

	Vector3D(const Vector2D& v, float u)
	{
		x = v.x;
		y = v.y;
		z = u;
	}

	Vector3D& Set(float r, float s, float t)
	{
		x = r;
		y = s;
		z = t;
		return (*this);
	}

	Vector3D& Set(const Vector2D& v, float u)
	{
		x = v.x;
		y = v.y;
		z = u;
		return (*this);
	}

	float& operator [](long k)
	{
		return ((&x)[k]);
	}

	const float& operator [](long k) const
	{
		return ((&x)[k]);
	}

	Vector2D& GetVector2D(void)
	{
		return (*reinterpret_cast<Vector2D *>(this));
	}

	const Vector2D& GetVector2D(void) const
	{
		return (*reinterpret_cast<const Vector2D *>(this));
	}

	Vector3D& operator =(const Vector2D& v)
	{
		x = v.x;
		y = v.y;
		z = 0.0F;
		return (*this);
	}

	Vector3D& operator +=(const Vector3D& v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
		return (*this);
	}

	Vector3D& operator +=(const Vector2D& v)
	{
		x += v.x;
		y += v.y;
		return (*this);
	}

	Vector3D& operator -=(const Vector3D& v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
		return (*this);
	}

	Vector3D& operator -=(const Vector2D& v)
	{
		x -= v.x;
		y -= v.y;
		return (*this);
	}

	Vector3D& operator *=(float t)
	{
		x *= t;
		y *= t;
		z *= t;
		return (*this);
	}

	Vector3D& operator /=(float t)
	{
		float f = 1.0F / t;
		x *= f;
		y *= f;
		z *= f;
		return (*this);
	}


	Vector3D& Normalize(void)
	{
		return (*this *= 1.0 / sqrt(x * x + y * y + z * z));
	}

	float Magnitude(const Vector3D& v)
	{
		return pow(v.x*v.x + v.y*v.y + v.z*v.z, 0.5);
	}
};


inline Vector3D operator -(const Vector3D& v)
{
	return (Vector3D(-v.x, -v.y, -v.z));
}

inline Vector3D operator +(const Vector3D& v1, const Vector3D& v2)
{
	return (Vector3D(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z));
}

inline Vector3D operator +(const Vector3D& v1, const Vector2D& v2)
{
	return (Vector3D(v1.x + v2.x, v1.y + v2.y, v1.z));
}

inline Vector3D operator -(const Vector3D& v1, const Vector3D& v2)
{
	return (Vector3D(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z));
}

inline Vector3D operator -(const Vector3D& v1, const Vector2D& v2)
{
	return (Vector3D(v1.x - v2.x, v1.y - v2.y, v1.z));
}

inline Vector3D operator *(const Vector3D& v, float t)
{
	return (Vector3D(v.x * t, v.y * t, v.z * t));
}


inline Vector3D operator /(const Vector3D& v, float t)
{
	float f = 1.0F / t;
	return (Vector3D(v.x * f, v.y * f, v.z * f));
}


inline bool operator ==(const Vector3D& v1, const Vector3D& v2)
{
	return ((v1.x == v2.x) && (v1.y == v2.y) && (v1.z == v2.z));
}

inline bool operator !=(const Vector3D& v1, const Vector3D& v2)
{
	return ((v1.x != v2.x) || (v1.y != v2.y) || (v1.z != v2.z));
}

inline float Dot(const Vector3D& v1, const Vector3D& v2)
{
	return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
}

inline Vector3D Cross(const Vector3D& v1, const Vector3D& v2)
{
	return Vector3D(v1.y*v2.z - v1.z*v2.y, -(v1.x*v2.z - v1.z*v2.x), v1.x*v2.y - v1.y*v2.x);
}





class Vector4D
{
public:

	float	x;
	float	y;
	float	z;
	float	w;

	Vector4D() {}

	Vector4D(float r, float s, float t, float u)
	{
		x = r;
		y = s;
		z = t;
		w = u;
	}

	Vector4D(const Vector3D& v, float u)
	{
		x = v.x;
		y = v.y;
		z = v.z;
		w = u;
	}



	Vector4D(const Vector3D& v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
		w = 0.0F;
	}



	Vector4D(const Vector2D& v)
	{
		x = v.x;
		y = v.y;
		z = 0.0F;
		w = 0.0F;
	}



	Vector4D& Set(float r, float s, float t, float u)
	{
		x = r;
		y = s;
		z = t;
		w = u;
		return (*this);
	}

	Vector4D& Set(const Vector3D &v, float u)
	{
		x = v.x;
		y = v.y;
		z = v.z;
		w = u;
		return (*this);
	}



	float& operator [](long k)
	{
		return ((&x)[k]);
	}

	const float& operator [](long k) const
	{
		return ((&x)[k]);
	}

	Vector3D& GetVector3D(void)
	{
		return (*reinterpret_cast<Vector3D *>(this));
	}

	const Vector3D& GetVector3D(void) const
	{
		return (*reinterpret_cast<const Vector3D *>(this));
	}



	Vector4D& operator =(const Vector3D& v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
		w = 0.0F;
		return (*this);
	}



	Vector4D& operator =(const Vector2D& v)
	{
		x = v.x;
		y = v.y;
		z = 0.0F;
		w = 0.0F;
		return (*this);
	}



	Vector4D& operator +=(const Vector4D& v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
		w += v.w;
		return (*this);
	}

	Vector4D& operator +=(const Vector3D& v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
		return (*this);
	}

	Vector4D& operator +=(const Vector2D& v)
	{
		x += v.x;
		y += v.y;
		return (*this);
	}

	Vector4D& operator -=(const Vector4D& v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
		w -= v.w;
		return (*this);
	}

	Vector4D& operator -=(const Vector3D& v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
		return (*this);
	}

	Vector4D& operator -=(const Vector2D& v)
	{
		x -= v.x;
		y -= v.y;
		return (*this);
	}

	Vector4D& operator *=(float t)
	{
		x *= t;
		y *= t;
		z *= t;
		w *= t;
		return (*this);
	}

	Vector4D& operator /=(float t)
	{
		float f = 1.0F / t;
		x *= f;
		y *= f;
		z *= f;
		w *= f;
		return (*this);
	}

	Vector4D& operator &=(const Vector4D& v)
	{
		x *= v.x;
		y *= v.y;
		z *= v.z;
		w *= v.w;
		return (*this);
	}

	Vector4D& Normalize(const Vector4D &v)
	{
		return (*this *= 1 / Magnitude(v));
	}

	float Magnitude(const Vector4D& v)
	{
		return pow(v.x*v.x + v.y*v.y + v.z*v.z + v.w*v.w, 0.5);
	}
};


inline Vector4D operator -(const Vector4D& v)
{
	return (Vector4D(-v.x, -v.y, -v.z, -v.w));
}

inline Vector4D operator +(const Vector4D& v1, const Vector4D& v2)
{
	return (Vector4D(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w));
}

inline Vector4D operator +(const Vector4D& v1, const Vector3D& v2)
{
	return (Vector4D(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w));
}

inline Vector4D operator +(const Vector3D& v1, const Vector4D& v2)
{
	return (Vector4D(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v2.w));
}

inline Vector4D operator +(const Vector4D& v1, const Vector2D& v2)
{
	return (Vector4D(v1.x + v2.x, v1.y + v2.y, v1.z, v1.w));
}

inline Vector4D operator +(const Vector2D& v1, const Vector4D& v2)
{
	return (Vector4D(v1.x + v2.x, v1.y + v2.y, v2.z, v2.w));
}

inline Vector4D operator -(const Vector4D& v1, const Vector4D& v2)
{
	return (Vector4D(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w - v2.w));
}

inline Vector4D operator -(const Vector4D& v1, const Vector3D& v2)
{
	return (Vector4D(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w));
}

inline Vector4D operator -(const Vector3D& v1, const Vector4D& v2)
{
	return (Vector4D(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, -v2.w));
}

inline Vector4D operator -(const Vector4D& v1, const Vector2D& v2)
{
	return (Vector4D(v1.x - v2.x, v1.y - v2.y, v1.z, v1.w));
}

inline Vector4D operator -(const Vector2D& v1, const Vector4D& v2)
{
	return (Vector4D(v1.x - v2.x, v1.y - v2.y, -v2.z, -v2.w));
}

inline Vector4D operator *(const Vector4D& v, float t)
{
	return (Vector4D(v.x * t, v.y * t, v.z * t, v.w * t));
}

inline Vector4D operator *(float t, const Vector4D& v)
{
	return (Vector4D(t * v.x, t * v.y, t * v.z, t * v.w));
}

inline Vector4D operator /(const Vector4D& v, float t)
{
	float f = 1.0F / t;
	return (Vector4D(v.x * f, v.y * f, v.z * f, v.w * f));
}


inline bool operator ==(const Vector4D& v1, const Vector4D& v2)
{
	return ((v1.x == v2.x) && (v1.y == v2.y) && (v1.z == v2.z) && (v1.w == v2.w));
}

inline bool operator !=(const Vector4D& v1, const Vector4D& v2)
{
	return ((v1.x != v2.x) || (v1.y != v2.y) || (v1.z != v2.z) || (v1.w != v2.w));
}


inline float Dot(const Vector4D& v1, const Vector4D& v2)
{
	return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z + v1.w*v2.w;
}

inline float Magnitude(const Vector4D& v)
{
	return pow(v.x*v.x + v.y*v.y + v.z*v.z + v.w*v.w, 0.5);
}

#endif