//----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#include "Vect_TRIANGLE_SIMD.h"



Vect_TRIANGLE_SIMD::Vect_TRIANGLE_SIMD(const float tx, const float ty, const float tz, const float tw)
	:x(tx),y(ty),z(tz),w(tw)
{

}

float Vect_TRIANGLE_SIMD::Length() const
{
	Vect_TRIANGLE_SIMD A,T1;
	T1._m = _mm_mul_ps(this->_m, this->_m);
	A._m = _mm_hadd_ps(T1._m, T1._m);
	A._m = _mm_hadd_ps(A._m, A._m);
	A._m = _mm_sqrt_ss(A._m);
	return A.x;
}

Vect_TRIANGLE_SIMD Vect_TRIANGLE_SIMD::Cross(const Vect_TRIANGLE_SIMD &R) const
{
	// replace everything... 
	// stub to shut up warnings

	Vect_TRIANGLE_SIMD A,B,C,D;
	A._m = _mm_shuffle_ps(this->_m, this->_m, _MM_SHUFFLE(3, 0, 2, 1));
	B._m = _mm_shuffle_ps(R._m, R._m, _MM_SHUFFLE(3, 1, 0, 2));
	A._m = _mm_mul_ps(A._m, B._m);
	C._m = _mm_shuffle_ps(this->_m, this->_m, _MM_SHUFFLE(3, 1, 0, 2));
	D._m = _mm_shuffle_ps(R._m, R._m, _MM_SHUFFLE(3, 0, 2, 1));
	C._m = _mm_mul_ps(C._m, D._m);
	B._m = _mm_sub_ps(A._m, C._m);
 	return B;
}

float Vect_TRIANGLE_SIMD::Area(const Vect_TRIANGLE_SIMD &T, const Vect_TRIANGLE_SIMD &R) 
{

	// replace everything... 
	// stub to shut up warnings
	Vect_TRIANGLE_SIMD A = T.Cross(R);
	return A.Length() /2;

}


// ---  End of File ---

