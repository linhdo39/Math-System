//----------------------------------------------------------------------------
// Copyright 2021, Ed Keenan, all rights reserved.
//----------------------------------------------------------------------------

#ifndef Matrix_Col_SIMD_H
#define Matrix_Col_SIMD_H

#include "Vect_Col_SIMD.h"
   
// -----------------------------------------------------------------------
// Rules: 
//    Implement for Col Major
//    No implementation in Header
//
//    Proxy (optional)
//    
//        Proxies are the only thing that can have the keyword "inline"
//            inline only for subsitution resolving.. that's it
//                No constructors or other operators... only proxy for substituion purpose
//            example:  (this is allowed)
//                inline MM operator * (const Matrix_Col_SIMD &m, const Matrix_Col_SIMD &n)
//        No proxy implementation in header
//            conversion operator needs to be implemented in CPP file
//            proxy constructors are allowed in header (only exception)
// -----------------------------------------------------------------------

class Matrix_Col_SIMD
{
public:
	Matrix_Col_SIMD() = default;
	Matrix_Col_SIMD(const Matrix_Col_SIMD &tmp) = default;
	Matrix_Col_SIMD &operator=(const Matrix_Col_SIMD &tmp) = default;
	~Matrix_Col_SIMD() = default;

	Matrix_Col_SIMD(const Vect_Col_SIMD &tV0,
					const Vect_Col_SIMD &tV1,
					const Vect_Col_SIMD &tV2,
					const Vect_Col_SIMD &tV3);
 
	//Matrix_Col_SIMD operator * (const Matrix_Col_SIMD &n);
	//Vect_Col_SIMD operator * (const Vect_Col_SIMD &n);

	union
	{
		struct
		{
			Vect_Col_SIMD v0;
			Vect_Col_SIMD v1;
			Vect_Col_SIMD v2;
			Vect_Col_SIMD v3;
		};

		struct
		{
			float m0;
			float m1;
			float m2;
			float m3;
			float m4;
			float m5;
			float m6;
			float m7;
			float m8;
			float m9;
			float m10;
			float m11;
			float m12;
			float m13;
			float m14;
			float m15;
		};
	};
private:
	friend struct MatrixAdd;
	friend struct MatrixAdd2;
	friend struct MatrixAdd3;
	friend struct MatrixAdd4;
	friend struct MatrixAdd5;
};

struct MatrixAdd
{
	const  Matrix_Col_SIMD& m1;
	const  Matrix_Col_SIMD& m2;
	MatrixAdd(const  Matrix_Col_SIMD& t1, const  Matrix_Col_SIMD& t2)
		: m1(t1), m2(t2) {};
};

struct MatrixAdd2
{
	const  Matrix_Col_SIMD& m1;
	const  Matrix_Col_SIMD& m2;
	const  Matrix_Col_SIMD& m3;
	MatrixAdd2(const  MatrixAdd& t1, const  Matrix_Col_SIMD& t2)
		: m1(t1.m1), m2(t1.m2), m3(t2) {};
};

struct MatrixAdd3
{
	const  Matrix_Col_SIMD& m1;
	const  Matrix_Col_SIMD& m2;
	const  Matrix_Col_SIMD& m3;
	const  Matrix_Col_SIMD& m4;
	MatrixAdd3(const  MatrixAdd2& t1, const  Matrix_Col_SIMD& t2)
		: m1(t1.m1), m2(t1.m2), m3(t1.m3), m4(t2) {};
};

struct MatrixAdd4
{
	const  Matrix_Col_SIMD& m1;
	const  Matrix_Col_SIMD& m2;
	const  Matrix_Col_SIMD& m3;
	const  Matrix_Col_SIMD& m4;
	const  Matrix_Col_SIMD& m5;
	MatrixAdd4(const  MatrixAdd3& t1, const  Matrix_Col_SIMD& t2)
		: m1(t1.m1), m2(t1.m2), m3(t1.m3), m4(t1.m4), m5(t2) {};
};

struct MatrixAdd5
{
	const  Matrix_Col_SIMD& m1;
	const  Matrix_Col_SIMD& m2;
	const  Matrix_Col_SIMD& m3;
	const  Matrix_Col_SIMD& m4;
	const  Matrix_Col_SIMD& m5;
	const Vect_Col_SIMD& v1;
	MatrixAdd5(const  MatrixAdd4& t1, const  Vect_Col_SIMD& t2)
		: m1(t1.m1), m2(t1.m2), m3(t1.m3), m4(t1.m4), m5(t1.m5), v1(t2) {};
	operator Vect_Col_SIMD();
};

inline MatrixAdd operator*(const Matrix_Col_SIMD& a, const Matrix_Col_SIMD& b)
{
	return MatrixAdd(a, b);
}

inline  MatrixAdd2 operator*(const MatrixAdd& a, const Matrix_Col_SIMD& b)
{
	return MatrixAdd2(a, b);
}

inline  MatrixAdd3 operator*(const MatrixAdd2& a, const Matrix_Col_SIMD& b)
{
	return MatrixAdd3(a, b);
}

inline  MatrixAdd4 operator*(const MatrixAdd3& a, const Matrix_Col_SIMD& b)
{
	return MatrixAdd4(a, b);
}

inline  MatrixAdd5 operator*(const MatrixAdd4& a, const Vect_Col_SIMD& b)
{
	return MatrixAdd5(a, b);
}
#endif

// ---  End of File ---------------
