#pragma once
#include <cmath>

// A generic 2-dimensional vector class.
template <typename T>
struct vec2
{
	T x, y;
	vec2() : x(0), y(0) {}
	vec2(const T& x_, const T& y_) : x(x_), y(y_) {}
	template <typename VectorType>
	vec2(const VectorType& v) : x(v.x), y(v.y) {}

	T getLength() const { return std::sqrt(getLengthSquare()); }
	T getLengthSquare() const { return x*x + y*y; }
	vec2<T> normalised() const  { T l = getLength(); return l==0 ? vec2{} : *this / l; }

	template <typename T2>
	vec2<T2> to() const { return {static_cast<T2>(x), static_cast<T2>(y)}; }

	template <typename T2>
	void operator+=(const vec2<T2>& v) { x += static_cast<T>(v.x); y += static_cast<T>(v.y); }
	template <typename T2>
	void operator-=(const vec2<T2>& v) { x -= static_cast<T>(v.x); y -= static_cast<T>(v.y); }
	template <typename T2>
	void operator*=(const vec2<T2>& v) { x *= static_cast<T>(v.x); y *= static_cast<T>(v.y); }
	template <typename T2>
	void operator/=(const vec2<T2>& v) { x /= static_cast<T>(v.x); y /= static_cast<T>(v.y); }
	template <typename T2>
	void operator*=(const T2& s) { x *= static_cast<T>(s); y *= static_cast<T>(s); }
	template <typename T2>
	void operator/=(const T2& s) { x /= static_cast<T>(s); y /= static_cast<T>(s); }

	static T dot(const vec2& a, const vec2& b);
};

template <typename T1, typename T2>
inline vec2<T1> operator+(const vec2<T1>& a, const vec2<T2>& b) { return vec2<T1>{a.x + static_cast<T1>(b.x), a.y + static_cast<T1>(b.y)}; }
template <typename T1, typename T2>
inline vec2<T1> operator-(const vec2<T1>& a, const vec2<T2>& b) { return vec2<T1>{a.x - static_cast<T1>(b.x), a.y - static_cast<T1>(b.y)}; }
template <typename T1, typename T2>
inline vec2<T1> operator*(const vec2<T1>& a, const vec2<T2>& b) { return vec2<T1>{a.x * static_cast<T1>(b.x), a.y * static_cast<T1>(b.y)}; }
template <typename T1, typename T2>
inline vec2<T1> operator/(const vec2<T1>& a, const vec2<T2>& b) { return vec2<T1>{a.x / static_cast<T1>(b.x), a.y / static_cast<T1>(b.y)}; }

template <typename T1, typename T2>
inline vec2<T1> operator*(const vec2<T1>& v, const T2& s) { return vec2<T1>{v.x*static_cast<T1>(s), v.y*static_cast<T1>(s)}; }
template <typename T1, typename T2>
inline vec2<T1> operator/(const vec2<T1>& v, const T2& s) { return vec2<T1>{v.x/static_cast<T1>(s), v.y/static_cast<T1>(s)}; }
template <typename T1, typename T2>
inline vec2<T1> operator*(const T1& s, const vec2<T2>& v) { return v*s; }
template <typename T1, typename T2>
inline vec2<T1> operator/(const T1& s, const vec2<T2>& v) { return v/s; }

template <typename T>
inline bool operator==(const vec2<T>& a, const vec2<T>& b) { return a.x==b.x && a.y==b.y; }
template <typename T>
inline bool operator!=(const vec2<T>& a, const vec2<T>& b) { return !(a==b); }

template <typename T>
inline T vec2<T>::dot(const vec2<T>& a, const vec2<T>& b) { return a.x * b.x + a.y * b.y; }
