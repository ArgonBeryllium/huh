#pragma once
#include "strex.h"
#include <cmath>
#include <cstdint>
#include <vector>

// A generic n-dimensional vector class.
template <uint8_t N, typename T>
struct vecn
{
	T val[N];
	T &x, &y, &z, &w;
	vecn(T a = 0) : x(val[0]), y(N>1?val[1]:val[0]), z(N>2?val[2]:val[0]), w(N>3?val[3]:val[0])
	{
		for(auto i = 0; i != N; i++)
			val[i] = a;
	}
	vecn(T v_[N]) : val(v_), x(val[0]), y(N>1?val[1]:val[0]), z(N>2?val[2]:val[0]), w(N>3?val[3]:val[0]) {}
	vecn(const std::vector<T>& v_) : x(val[0]), y(N>1?val[1]:val[0]), z(N>2?val[2]:val[0]), w(N>3?val[3]:val[0])
	{
		for(auto i = 0; i != N; i++) val[i] = v_[i];
	}
	template <typename VectorType>
	vecn(const VectorType& v_) : x(val[0]), y(N>1?val[1]:val[0]), z(N>2?val[2]:val[0]), w(N>3?val[3]:val[0])
	{
		for(auto i = 0; i != N; i++) val[i] = v_[i];
	}
	template <uint8_t N2, typename T2>
	vecn(const T2& vt_) : val(vt_.v), x(val[0]), y(N>1?val[1]:val[0]), z(N>2?val[2]:val[0]), w(N>3?val[3]:val[0]) {}

	T getLength() const { return std::sqrt(getLengthSquare()); }
	T getLengthSquare() const
	{
		T out;
		for(auto e : val) out += e*e;
		return out;
	}
	vecn normalised() const  { T l = getLength(); return l==0 ? vecn() : *this / l; }

	template <typename T2>
	vecn<N, T2> to() const
	{
		T2 outa[N];
		for(auto i = 0; i != N; i++)
			outa[i] = static_cast<T2>(val[i]);
		return vecn(outa);
	}

	template <typename T2>
	void operator+=(const vecn<N, T2>& v) { for(auto i = 0; i != N; i++) val[i] += v.val[i]; }
	template <typename T2>
	void operator-=(const vecn<N, T2>& v) { for(auto i = 0; i != N; i++) val[i] -= v.val[i]; }
	template <typename T2>
	void operator*=(const vecn<N, T2>& v) { for(auto i = 0; i != N; i++) val[i] *= v.val[i]; }
	template <typename T2>
	void operator/=(const vecn<N, T2>& v) { for(auto i = 0; i != N; i++) val[i] /= v.val[i]; }
	template <typename T2>
	void operator*=(const T2& s) { for(auto& e : val) e *= s; }
	template <typename T2>
	void operator/=(const T2& s) { for(auto& e : val) e /= s; }

	T& operator[](const int& i) { return val[i]; }
	static T dot(const vecn& a, const vecn& b);
};

template <uint8_t N, typename T1, typename T2>
inline vecn<N, T1> operator+(const vecn<N, T1>& a, const vecn<N, T2>& b)
{
	vecn<N, T1> out(a);
	out += b;
	return out;
}
template <uint8_t N, typename T1, typename T2>
inline vecn<N, T1> operator-(const vecn<N, T1>& a, const vecn<N, T2>& b)
{
	vecn<N, T1> out(a);
	out -= b;
	return out;
}
template <uint8_t N, typename T1, typename T2>
inline vecn<N, T1> operator*(const vecn<N, T1>& a, const vecn<N, T2>& b)
{
	vecn<N, T1> out(a);
	out *= b;
	return out;
}
template <uint8_t N, typename T1, typename T2>
inline vecn<N, T1> operator/(const vecn<N, T1>& a, const vecn<N, T2>& b)
{
	vecn<N, T1> out(a);
	out /= b;
	return out;
}

template <uint8_t N, typename T1, typename T2>
inline vecn<N, T1> operator*(const vecn<N, T1>& v, const T2& s)
{
	vecn<N, T1> out(v);
	for(auto& e : v.val) e *= s;
	return out;
}
template <uint8_t N, typename T1, typename T2>
inline vecn<N, T1> operator/(const vecn<N, T1>& v, const T2& s)
{
	vecn<N, T1> out(v);
	for(auto& e : v.val) e /= s;
	return out;
}
template <uint8_t N, typename T1, typename T2>
inline vecn<N, T1> operator*(const T1& s, const vecn<N, T2>& v) { return v*s; }
template <uint8_t N, typename T1, typename T2>
inline vecn<N, T1> operator/(const T1& s, const vecn<N, T2>& v)
{
	vecn<N, T1> out(v);
	for(auto& e : v.val) e = s/static_cast<T1>(e);
	return out;
}

template <uint8_t N, typename T>
inline bool operator==(const vecn<N, T>& a, const vecn<N, T>& b)
{
	for(auto i = 0; i != N; i++)
		if(a[i] != b[i])
			return false;
	return true;
}
template <uint8_t N, typename T>
inline bool operator!=(const vecn<N, T>& a, const vecn<N, T>& b) { return !(a==b); }

template <uint8_t N, typename T>
inline T vecn<N, T>::dot(const vecn<N, T>& a, const vecn<N, T>& b)
{
	T out;
	for(auto i = 0; i != N; i++) out += a[i]*b[i];
	return out;
}
