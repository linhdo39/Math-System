//----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "Vect_Row_SIMD.h"
#include "Matrix_Row_SIMD.h"

Vect_Row_SIMD::Vect_Row_SIMD(const float tx, const float ty, const float tz, const float tw)
	: x(tx), y(ty), z(tz), w(tw)
{
}
VectorAdd5::operator Vect_Row_SIMD() {
	Vect_Row_SIMD X, Y, Z, W;
	Vect_Row_SIMD A, B, C, D;
	Vect_Row_SIMD T1, T2, T3;
	X._m = _mm_set1_ps(v1.x);
	A._m = _mm_mul_ps(X._m, m1.v0._m);
	Y._m = _mm_set1_ps(v1.y);
	B._m = _mm_mul_ps(Y._m, m1.v1._m);
	Z._m = _mm_set1_ps(v1.z);
	C._m = _mm_mul_ps(Z._m, m1.v2._m);
	W._m = _mm_set1_ps(v1.w);
	T1._m = _mm_add_ps(A._m, B._m);
	D._m = _mm_mul_ps(W._m, m1.v3._m);
	T2._m = _mm_add_ps(T1._m, C._m);
	T3._m = _mm_add_ps(T2._m, D._m);

	X._m = _mm_set1_ps(T3.x);
	A._m = _mm_mul_ps(X._m, m2.v0._m);
	Y._m = _mm_set1_ps(T3.y);
	B._m = _mm_mul_ps(Y._m, m2.v1._m);
	Z._m = _mm_set1_ps(T3.z);
	C._m = _mm_mul_ps(Z._m, m2.v2._m);
	W._m = _mm_set1_ps(T3.w);
	T1._m = _mm_add_ps(A._m, B._m);
	D._m = _mm_mul_ps(W._m, m2.v3._m);
	T2._m = _mm_add_ps(T1._m, C._m);
	T3._m = _mm_add_ps(T2._m, D._m);

	X._m = _mm_set1_ps(T3.x);
	A._m = _mm_mul_ps(X._m, m3.v0._m);
	Y._m = _mm_set1_ps(T3.y);
	B._m = _mm_mul_ps(Y._m, m3.v1._m);
	Z._m = _mm_set1_ps(T3.z);
	C._m = _mm_mul_ps(Z._m, m3.v2._m);
	W._m = _mm_set1_ps(T3.w);
	T1._m = _mm_add_ps(A._m, B._m);
	D._m = _mm_mul_ps(W._m, m3.v3._m);
	T2._m = _mm_add_ps(T1._m, C._m);
	T3._m = _mm_add_ps(T2._m, D._m);

	X._m = _mm_set1_ps(T3.x);
	A._m = _mm_mul_ps(X._m, m4.v0._m);
	Y._m = _mm_set1_ps(T3.y);
	B._m = _mm_mul_ps(Y._m, m4.v1._m);
	Z._m = _mm_set1_ps(T3.z);
	C._m = _mm_mul_ps(Z._m, m4.v2._m);
	W._m = _mm_set1_ps(T3.w);
	T1._m = _mm_add_ps(A._m, B._m);
	D._m = _mm_mul_ps(W._m, m4.v3._m);
	T2._m = _mm_add_ps(T1._m, C._m);
	T3._m = _mm_add_ps(T2._m, D._m);

	X._m = _mm_set1_ps(T3.x);
	A._m = _mm_mul_ps(X._m, m5.v0._m);
	Y._m = _mm_set1_ps(T3.y);
	B._m = _mm_mul_ps(Y._m, m5.v1._m);
	Z._m = _mm_set1_ps(T3.z);
	C._m = _mm_mul_ps(Z._m, m5.v2._m);
	W._m = _mm_set1_ps(T3.w);
	T1._m = _mm_add_ps(A._m, B._m);
	D._m = _mm_mul_ps(W._m, m5.v3._m);
	T2._m = _mm_add_ps(T1._m, C._m);
	T3._m = _mm_add_ps(T2._m, D._m);
	return T3;
}



// ---  End of File ---------------


