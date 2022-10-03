#pragma once
#include "strex.h"
#include <cmath>

// A generic 3-dimensional vector class.
template <typename T>
struct vec3
{
	T x, y, z;
	vec3() : x(0), y(0), z(0) {}
	vec3(const T& x_, const T& y_, const T& z_) : x(x_), y(y_), z(z_) {}
	template <typename VectorType>
	vec3(const VectorType& v) : x(v.x), y(v.y), z(v.z) {}

	T getLength() const { return std::sqrt(getLengthSquare()); }
	T getLengthSquare() const { return x*x + y*y + z*z; }
	vec3<T> normalised() const  { T l = getLength(); return l==0 ? vec3{} : *this / l; }

	template <typename T2>
	vec3<T2> to() const { return {static_cast<T2>(x), static_cast<T2>(y), static_cast<T2>(z)}; }

	template <typename T2>
	void operator+=(const vec3<T2>& v)
	{
		x += static_cast<T>(v.x);
		y += static_cast<T>(v.y);
		z += static_cast<T>(v.z);
	}
	template <typename T2>
	void operator-=(const vec3<T2>& v)
	{
		x -= static_cast<T>(v.x);
		y -= static_cast<T>(v.y);
		z -= static_cast<T>(v.z);
	}
	template <typename T2>
	void operator*=(const vec3<T2>& v)
	{
		x *= static_cast<T>(v.x);
		y *= static_cast<T>(v.y);
		z *= static_cast<T>(v.z);
	}
	template <typename T2>
	void operator/=(const vec3<T2>& v)
	{
		x /= static_cast<T>(v.x);
		y /= static_cast<T>(v.y);
		z /= static_cast<T>(v.z);
	}
	template <typename T2>
	void operator*=(const T2& s) { x *= static_cast<T>(s); y *= static_cast<T>(s); z *= static_cast<T>(s); }
	template <typename T2>
	void operator/=(const T2& s) { x /= static_cast<T>(s); y /= static_cast<T>(s); z *= static_cast<T>(s); }

	T& operator[](const int& i)
	{
		if(i == 0) return x;
		if(i == 1) return y;
		if(i == 2) return z;
		else throw strex("invalid axis index");
	}

	static T dot(const vec3& a, const vec3& b);
};

template <typename T1, typename T2>
inline vec3<T1> operator+(const vec3<T1>& a, const vec3<T2>& b)
{ return {static_cast<T1>(a.x + b.x), static_cast<T1>(a.y + b.y), static_cast<T1>(a.z + b.z)}; }
template <typename T1, typename T2>
inline vec3<T1> operator-(const vec3<T1>& a, const vec3<T2>& b)
{ return {static_cast<T1>(a.x - b.x), static_cast<T1>(a.y - b.y), static_cast<T1>(a.z - b.z)}; }
template <typename T1, typename T2>
inline vec3<T1> operator*(const vec3<T1>& a, const vec3<T2>& b)
{ return {static_cast<T1>(a.x * b.x), static_cast<T1>(a.y * b.y), static_cast<T1>(a.z * b.z)}; }
template <typename T1, typename T2>
inline vec3<T1> operator/(const vec3<T1>& a, const vec3<T2>& b)
{ return {static_cast<T1>(a.x / b.x), static_cast<T1>(a.y / b.y), static_cast<T1>(a.z / b.z)}; }

template <typename T1, typename T2>
inline vec3<T1> operator*(const vec3<T1>& v, const T2& s) { return vec3<T1>{v.x*static_cast<T1>(s), v.y*static_cast<T1>(s), v.z*static_cast<T1>(s)}; }
template <typename T1, typename T2>
inline vec3<T1> operator/(const vec3<T1>& v, const T2& s) { return vec3<T1>{v.x/static_cast<T1>(s), v.y/static_cast<T1>(s), v.z/static_cast<T1>(s)}; }
template <typename T1, typename T2>
inline vec3<T1> operator*(const T1& s, const vec3<T2>& v) { return v*s; }
template <typename T1, typename T2>
inline vec3<T1> operator/(const T1& s, const vec3<T2>& v) { return vec3<T1>{s/static_cast<T1>(v.x), s/static_cast<T1>(v.y), s/static_cast<T1>(s.z)}; }

template <typename T>
inline bool operator==(const vec3<T>& a, const vec3<T>& b) { return a.x==b.x && a.y==b.y && a.z==b.z; }
template <typename T>
inline bool operator!=(const vec3<T>& a, const vec3<T>& b) { return !(a==b); }

template <typename T>
inline T vec3<T>::dot(const vec3<T>& a, const vec3<T>& b) { return a.x * b.x + a.y * b.y + a.z*b.z; }
