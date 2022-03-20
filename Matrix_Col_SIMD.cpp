//----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "Vect_Col_SIMD.h"
#include "Matrix_Col_SIMD.h"

Matrix_Col_SIMD::Matrix_Col_SIMD(const Vect_Col_SIMD &tV0,
								 const Vect_Col_SIMD &tV1,
								 const Vect_Col_SIMD &tV2,
								 const Vect_Col_SIMD &tV3)
	: v0(tV0), v1(tV1), v2(tV2), v3(tV3)
{
}

MatrixAdd5::operator Vect_Col_SIMD() {
	Vect_Col_SIMD A, B, C, D;
	Vect_Col_SIMD T1, T2, T3;
	A._m = _mm_mul_ps(v1._m, m5.v0._m);
	B._m = _mm_mul_ps(v1._m, m5.v1._m);
	C._m = _mm_mul_ps(v1._m, m5.v2._m);
	T1._m = _mm_hadd_ps(A._m, B._m);
	D._m = _mm_mul_ps(v1._m, m5.v3._m);
	T2._m = _mm_hadd_ps(C._m, D._m);
	T3._m = _mm_hadd_ps(T1._m, T2._m);

	A._m = _mm_mul_ps(T3._m, m4.v0._m);
	B._m = _mm_mul_ps(T3._m, m4.v1._m);
	C._m = _mm_mul_ps(T3._m, m4.v2._m);
	T1._m = _mm_hadd_ps(A._m, B._m);
	D._m = _mm_mul_ps(T3._m, m4.v3._m);
	T2._m = _mm_hadd_ps(C._m, D._m);
	T3._m = _mm_hadd_ps(T1._m, T2._m);

	A._m = _mm_mul_ps(T3._m, m3.v0._m);
	B._m = _mm_mul_ps(T3._m, m3.v1._m);
	C._m = _mm_mul_ps(T3._m, m3.v2._m);
	T1._m = _mm_hadd_ps(A._m, B._m);
	D._m = _mm_mul_ps(T3._m, m3.v3._m);
	T2._m = _mm_hadd_ps(C._m, D._m);
	T3._m = _mm_hadd_ps(T1._m, T2._m);

	A._m = _mm_mul_ps(T3._m, m2.v0._m);
	B._m = _mm_mul_ps(T3._m, m2.v1._m);
	C._m = _mm_mul_ps(T3._m, m2.v2._m);
	T1._m = _mm_hadd_ps(A._m, B._m);
	D._m = _mm_mul_ps(T3._m, m2.v3._m);
	T2._m = _mm_hadd_ps(C._m, D._m);
	T3._m = _mm_hadd_ps(T1._m, T2._m);

	A._m = _mm_mul_ps(T3._m, m1.v0._m);
	B._m = _mm_mul_ps(T3._m, m1.v1._m);
	C._m = _mm_mul_ps(T3._m, m1.v2._m);
	T1._m = _mm_hadd_ps(A._m, B._m);
	D._m = _mm_mul_ps(T3._m, m1.v3._m);
	T2._m = _mm_hadd_ps(C._m, D._m);
	T3._m = _mm_hadd_ps(T1._m, T2._m);
	return T3;
}

// ---  End of File ---------------
