//----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "Vect_M_SIMD.h"
#include "Matrix_M_SIMD.h"

Matrix_M_SIMD::Matrix_M_SIMD(const Vect_M_SIMD &tV0,
							 const Vect_M_SIMD &tV1,
							 const Vect_M_SIMD &tV2,
							 const Vect_M_SIMD &tV3)
	: v0(tV0), v1(tV1), v2(tV2), v3(tV3)
{
}

Matrix_M_SIMD Matrix_M_SIMD::operator * (const Matrix_M_SIMD &mb) const
{
	Vect_M_SIMD X, Y, Z, W;
	Vect_M_SIMD A, B, C, D;
	Vect_M_SIMD T1, T2;
	Matrix_M_SIMD T3;
	X._m = _mm_set1_ps(this->v0.x);
	Y._m = _mm_set1_ps(this->v0.y);
	Z._m = _mm_set1_ps(this->v0.z);
	W._m = _mm_set1_ps(this->v0.w);
	
	A._m = _mm_mul_ps(X._m, mb.v0._m);
	B._m = _mm_mul_ps(Y._m, mb.v1._m);
	C._m = _mm_mul_ps(Z._m, mb.v2._m);
	D._m = _mm_mul_ps(W._m, mb.v3._m);
	
	X._m = _mm_set1_ps(this->v1.x);
	T1._m = _mm_add_ps(A._m, B._m);
	Y._m = _mm_set1_ps(this->v1.y);
	Z._m = _mm_set1_ps(this->v1.z);
	W._m = _mm_set1_ps(this->v1.w);
	T2._m = _mm_add_ps(T1._m, C._m);

	A._m = _mm_mul_ps(X._m, mb.v0._m);
	B._m = _mm_mul_ps(Y._m, mb.v1._m);
	C._m = _mm_mul_ps(Z._m, mb.v2._m);

	T3.v0._m = _mm_add_ps(T2._m, D._m);
	T1._m = _mm_add_ps(A._m, B._m);
	X._m = _mm_set1_ps(this->v2.x);
	Y._m = _mm_set1_ps(this->v2.y);
	D._m = _mm_mul_ps(W._m, mb.v3._m);
	
	T2._m = _mm_add_ps(T1._m, C._m);
	A._m = _mm_mul_ps(X._m, mb.v0._m);
	B._m = _mm_mul_ps(Y._m, mb.v1._m);
	Z._m = _mm_set1_ps(this->v2.z);
	W._m = _mm_set1_ps(this->v2.w);
	T3.v1._m = _mm_add_ps(T2._m, D._m);
	T1._m = _mm_add_ps(A._m, B._m);
	C._m = _mm_mul_ps(Z._m, mb.v2._m);
	D._m = _mm_mul_ps(W._m, mb.v3._m);
	X._m = _mm_set1_ps(this->v3.x);
	A._m = _mm_mul_ps(X._m, mb.v0._m);
	T2._m = _mm_add_ps(T1._m, C._m);
	Y._m = _mm_set1_ps(this->v3.y);
	Z._m = _mm_set1_ps(this->v3.z);
	W._m = _mm_set1_ps(this->v3.w);
	B._m = _mm_mul_ps(Y._m, mb.v1._m);
	T1._m = _mm_add_ps(A._m, B._m);
	T3.v2._m = _mm_add_ps(T2._m, D._m);

	C._m = _mm_mul_ps(Z._m, mb.v2._m);
	T2._m = _mm_add_ps(T1._m, C._m);	
	D._m = _mm_mul_ps(W._m, mb.v3._m);

	T3.v3._m = _mm_add_ps(T2._m, D._m);
	
	return T3;
}


// ---  End of File ---------------
