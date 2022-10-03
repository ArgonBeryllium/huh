#pragma once
#include <cmath>

// linear interpolation
template<typename T, typename R>
const inline T lerp(const T& a, const R& b, const float& t) { return a + (b-a)*t; }

// apply-lerp; Interpolated value is assigned to the first argument
template<typename T, typename R>
const inline T alerp(T& a, const R& b, const float& t)
{
	a = lerp(a, b, t);
	return a;
}

// framerate-independent smoothing
// Approaching a lerp between two points in discrete intervals, at a point in time `n` can be described like so:
// f(n) = b + (f(0) - b)*r^n
//        = b - br^n + f(0)r^n
//        = b(1 - r^n) + ar^n
//        = lerp(a, b, 1-r^n)
// where:
//   f(0) - initial value (a)
//   r - rate of change   (amt)
//   n - step             (dt)
template<typename T, typename R>
const inline T fin_damp(const T& a, const R& b, const float& amt, const float dt)
{ return lerp(a, b, 1-std::pow(amt, dt)); }
