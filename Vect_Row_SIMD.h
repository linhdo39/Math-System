//----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef Vect_Row_SIMD_H
#define Vect_Row_SIMD_H
#include <xmmintrin.h>
#include <smmintrin.h>  

class Matrix_Row_SIMD;

// -----------------------------------------------------------------------
// Rules: 
//    Implement for Row Major
//    No implementation in Header
//
//    Proxy (optional)
//    
//        Proxies are the only thing that can have the keyword "inline"
//            inline only for subsitution resolving.. that's it
//                No constructors or other operators... only proxy for substituion purpose
//            example:  (this is allowed)
//                inline vM operator * (const Vect_Row_SIMD &v, const Matrix_Row_SIMD &m)
//        No proxy implementation in header
//            conversion operator needs to be implemented in CPP file
//            proxy constructors are allowed in header (only exception)
// -----------------------------------------------------------------------

class Vect_Row_SIMD
{
public:
	Vect_Row_SIMD() = default;
	Vect_Row_SIMD(const Vect_Row_SIMD &tmp) = default;
	Vect_Row_SIMD &operator = (const Vect_Row_SIMD &tmp) = default;
	~Vect_Row_SIMD() = default;

	Vect_Row_SIMD(const float tx, const float ty, const float tz, const float tw);

	//Vect_Row_SIMD operator * ( const Matrix_Row_SIMD &ma);

public:

	// anonymous union
	union
	{
		__m128	_m;

		// anonymous struct
		struct
		{
			float x;
			float y;
			float z;
			float w;
		};
	};

private:

	friend struct VectorAdd;
	friend struct VectorAdd2;
	friend struct VectorAdd3;
	friend struct VectorAdd4;
	friend struct VectorAdd5;
};

struct VectorAdd
{
	const  Vect_Row_SIMD& v1;
	const  Matrix_Row_SIMD& m1;
	VectorAdd(const  Vect_Row_SIMD& t1, const  Matrix_Row_SIMD& t2)
		: v1(t1), m1(t2) {};
	operator Vect_Row_SIMD() {
		return Vect_Row_SIMD();
	}
};

struct VectorAdd2
{
	const  Vect_Row_SIMD& v1;
	const  Matrix_Row_SIMD& m1;
	const  Matrix_Row_SIMD& m2;
	VectorAdd2(const  VectorAdd& t1, const  Matrix_Row_SIMD& t2)
		: v1(t1.v1), m1(t1.m1), m2(t2) {};
	operator Vect_Row_SIMD() {
		return Vect_Row_SIMD();
	}
};

struct VectorAdd3
{
	const Vect_Row_SIMD& v1;
	const Matrix_Row_SIMD& m1;
	const Matrix_Row_SIMD& m2;
	const Matrix_Row_SIMD& m3;
	VectorAdd3(const  VectorAdd2& t1, const  Matrix_Row_SIMD& t2)
		: v1(t1.v1), m1(t1.m1), m2(t1.m2), m3(t2) {};
	operator Vect_Row_SIMD() {
		return Vect_Row_SIMD();
	}
};

struct VectorAdd4
{
	const Vect_Row_SIMD& v1;
	const Matrix_Row_SIMD& m1;
	const Matrix_Row_SIMD& m2;
	const Matrix_Row_SIMD& m3;
	const Matrix_Row_SIMD& m4;
	VectorAdd4(const  VectorAdd3& t1, const  Matrix_Row_SIMD& t2)
		: v1(t1.v1), m1(t1.m1), m2(t1.m2), m3(t1.m3), m4(t2) {};
	operator Vect_Row_SIMD() {
		return Vect_Row_SIMD();
	}
};

struct VectorAdd5
{
	const Vect_Row_SIMD& v1;
	const Matrix_Row_SIMD& m1;
	const Matrix_Row_SIMD& m2;
	const Matrix_Row_SIMD& m3;
	const Matrix_Row_SIMD& m4;
	const Matrix_Row_SIMD& m5;
	VectorAdd5(const  VectorAdd4& t1, const  Matrix_Row_SIMD& t2)
		: v1(t1.v1), m1(t1.m1), m2(t1.m2), m3(t1.m3), m4(t1.m4), m5(t2) {};
	operator Vect_Row_SIMD();
};

inline VectorAdd operator*(const Vect_Row_SIMD& a, const Matrix_Row_SIMD& b)
{
	return VectorAdd(a, b);
}

inline VectorAdd2 operator*(const VectorAdd& a, const Matrix_Row_SIMD& b)
{
	return VectorAdd2(a, b);
}

inline VectorAdd3 operator*(const VectorAdd2& a, const Matrix_Row_SIMD& b)
{
	return VectorAdd3(a, b);
}

inline VectorAdd4 operator*(const VectorAdd3& a, const Matrix_Row_SIMD& b)
{
	return VectorAdd4(a, b);
}

inline VectorAdd5 operator*(const VectorAdd4& a, const Matrix_Row_SIMD& b)
{
	return VectorAdd5(a, b);
}


#endif

// ---  End of File ---------------
