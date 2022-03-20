//----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "Vect_vM_SIMD.h"
#include "Matrix_vM_SIMD.h"

Vect_vM_SIMD::Vect_vM_SIMD(const float tx, const float ty, const float tz, const float tw)
	: x(tx), y(ty), z(tz), w(tw)
{
}

//------------------------------
// For No proxy:
//------------------------------

Vect_vM_SIMD Vect_vM_SIMD::operator * (const Matrix_vM_SIMD &ma) const
{
	Vect_vM_SIMD X, Y, Z, W;
	Vect_vM_SIMD A, B, C, D;
	Vect_vM_SIMD T1, T2, T3;
	X._m = _mm_set1_ps(this->x);
	A._m = _mm_mul_ps(X._m, ma.v0._m);
	Y._m = _mm_set1_ps(this->y);
	B._m = _mm_mul_ps(Y._m, ma.v1._m);
	Z._m = _mm_set1_ps(this->z);
	C._m = _mm_mul_ps(Z._m, ma.v2._m);
	W._m = _mm_set1_ps(this->w);
	T1._m = _mm_add_ps(A._m, B._m);
	D._m = _mm_mul_ps(W._m, ma.v3._m);
	T2._m = _mm_add_ps(T1._m, C._m);
	T3._m = _mm_add_ps(T2._m, D._m);

	return T3;
};


// ---  End of File ---------------


