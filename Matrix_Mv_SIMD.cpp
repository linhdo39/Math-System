//----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "Vect_Mv_SIMD.h"
#include "Matrix_Mv_SIMD.h"

Matrix_Mv_SIMD::Matrix_Mv_SIMD(const Vect_Mv_SIMD &tV0,
							   const Vect_Mv_SIMD &tV1,
							   const Vect_Mv_SIMD &tV2,
							   const Vect_Mv_SIMD &tV3)
	: v0(tV0), v1(tV1), v2(tV2), v3(tV3)
{
}

Vect_Mv_SIMD Matrix_Mv_SIMD::operator * (const Vect_Mv_SIMD &v) const
{
	// replace everything... 
	// stub to shut up warnings
	Vect_Mv_SIMD A,B,C,D;
	Vect_Mv_SIMD T1,T2,T3;
	A._m = _mm_mul_ps(this->v0._m, v._m);
	B._m = _mm_mul_ps(this->v1._m, v._m);
	C._m = _mm_mul_ps(this->v2._m, v._m);
	D._m = _mm_mul_ps(this->v3._m, v._m);
	
	T1._m = _mm_hadd_ps(A._m, B._m);
	 
	T2._m = _mm_hadd_ps(C._m, D._m);
	T3._m = _mm_hadd_ps(T1._m, T2._m);

	return T3;
}


// ---  End of File ---------------
