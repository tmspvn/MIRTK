/*
 * Copyright 1993-2010 NVIDIA Corporation.  All rights reserved.
 *
 * Please refer to the NVIDIA end user license agreement (EULA) associated
 * with this source code for terms and conditions that govern your use of
 * this software. Any use, reproduction, disclosure, or distribution of
 * this software and related documentation outside the terms of the EULA
 * is strictly prohibited.
 *
 */

/*
    This file implements common mathematical operations on vector types
    (float3, float4 etc.) since these are not provided as standard by CUDA.

    The syntax is modelled on the Cg standard library.

    This is part of the CUTIL library and is not supported by NVIDIA.

    Thanks to Linh Hah for additions and fixes.
*/

/*
    This file (cutil_math.h) has been modified by Andreas Schuh to add the
    MIRTKCU_API modifier and embed it into the MIRTK namespace.
*/

#ifndef MIRTK_CutilMath_H
#define MIRTK_CutilMath_H

#if !defined(__CUDACC__)
#  include <cmath>
#  include <cstdlib>
#  include <algorithm>
#endif

#include "mirtk/Config.h" // MIRTKCU_API
#include "mirtk/CudaTypes.h"


namespace mirtk {

////////////////////////////////////////////////////////////////////////////////
// Standard C library functions for built-in types
////////////////////////////////////////////////////////////////////////////////

using ::floorf;
using ::fmodf;
using ::fabs;

using std::abs;
using std::min;
using std::max;

////////////////////////////////////////////////////////////////////////////////
// host implementations of CUDA functions
////////////////////////////////////////////////////////////////////////////////
#if !defined(__CUDACC__)

inline float fminf(float a, float b)
{
  return a < b ? a : b;
}

inline float fmaxf(float a, float b)
{
  return a > b ? a : b;
}

inline float rsqrtf(float x)
{
  return 1.0f / sqrtf(x);
}

#endif // !defined(__CUDACC__)
////////////////////////////////////////////////////////////////////////////////
// constructors
////////////////////////////////////////////////////////////////////////////////

// andreas: Moved to mirtk/CudaTypes.h

////////////////////////////////////////////////////////////////////////////////
// negate
////////////////////////////////////////////////////////////////////////////////

MIRTKCU_API inline float2 operator-(float2 &a)
{
  return make_float2(-a.x, -a.y);
}
MIRTKCU_API inline int2 operator-(int2 &a)
{
  return make_int2(-a.x, -a.y);
}
MIRTKCU_API inline float3 operator-(float3 &a)
{
  return make_float3(-a.x, -a.y, -a.z);
}
MIRTKCU_API inline int3 operator-(int3 &a)
{
  return make_int3(-a.x, -a.y, -a.z);
}
MIRTKCU_API inline float4 operator-(float4 &a)
{
  return make_float4(-a.x, -a.y, -a.z, -a.w);
}
MIRTKCU_API inline int4 operator-(int4 &a)
{
  return make_int4(-a.x, -a.y, -a.z, -a.w);
}

////////////////////////////////////////////////////////////////////////////////
// addition
////////////////////////////////////////////////////////////////////////////////

MIRTKCU_API inline float2 operator+(float2 a, float2 b)
{
  return make_float2(a.x + b.x, a.y + b.y);
}
MIRTKCU_API inline void operator+=(float2 &a, float2 b)
{
  a.x += b.x; a.y += b.y;
}
MIRTKCU_API inline float2 operator+(float2 a, float b)
{
  return make_float2(a.x + b, a.y + b);
}
MIRTKCU_API inline float2 operator+(float b, float2 a)
{
  return make_float2(a.x + b, a.y + b);
}
MIRTKCU_API inline void operator+=(float2 &a, float b)
{
  a.x += b; a.y += b;
}

MIRTKCU_API inline int2 operator+(int2 a, int2 b)
{
  return make_int2(a.x + b.x, a.y + b.y);
}
MIRTKCU_API inline void operator+=(int2 &a, int2 b)
{
  a.x += b.x; a.y += b.y;
}
MIRTKCU_API inline int2 operator+(int2 a, int b)
{
  return make_int2(a.x + b, a.y + b);
}
MIRTKCU_API inline int2 operator+(int b, int2 a)
{
  return make_int2(a.x + b, a.y + b);
}
MIRTKCU_API inline void operator+=(int2 &a, int b)
{
  a.x += b; a.y += b;
}

MIRTKCU_API inline uint2 operator+(uint2 a, uint2 b)
{
  return make_uint2(a.x + b.x, a.y + b.y);
}
MIRTKCU_API inline void operator+=(uint2 &a, uint2 b)
{
  a.x += b.x; a.y += b.y;
}
MIRTKCU_API inline uint2 operator+(uint2 a, uint b)
{
  return make_uint2(a.x + b, a.y + b);
}
MIRTKCU_API inline uint2 operator+(uint b, uint2 a)
{
  return make_uint2(a.x + b, a.y + b);
}
MIRTKCU_API inline void operator+=(uint2 &a, uint b)
{
  a.x += b; a.y += b;
}


MIRTKCU_API inline float3 operator+(float3 a, float3 b)
{
  return make_float3(a.x + b.x, a.y + b.y, a.z + b.z);
}
MIRTKCU_API inline void operator+=(float3 &a, float3 b)
{
  a.x += b.x; a.y += b.y; a.z += b.z;
}
MIRTKCU_API inline float3 operator+(float3 a, float b)
{
  return make_float3(a.x + b, a.y + b, a.z + b);
}
MIRTKCU_API inline void operator+=(float3 &a, float b)
{
  a.x += b; a.y += b; a.z += b;
}

MIRTKCU_API inline int3 operator+(int3 a, int3 b)
{
  return make_int3(a.x + b.x, a.y + b.y, a.z + b.z);
}
MIRTKCU_API inline void operator+=(int3 &a, int3 b)
{
  a.x += b.x; a.y += b.y; a.z += b.z;
}
MIRTKCU_API inline int3 operator+(int3 a, int b)
{
  return make_int3(a.x + b, a.y + b, a.z + b);
}
MIRTKCU_API inline void operator+=(int3 &a, int b)
{
  a.x += b; a.y += b; a.z += b;
}

MIRTKCU_API inline uint3 operator+(uint3 a, uint3 b)
{
  return make_uint3(a.x + b.x, a.y + b.y, a.z + b.z);
}
MIRTKCU_API inline void operator+=(uint3 &a, uint3 b)
{
  a.x += b.x; a.y += b.y; a.z += b.z;
}
MIRTKCU_API inline uint3 operator+(uint3 a, uint b)
{
  return make_uint3(a.x + b, a.y + b, a.z + b);
}
MIRTKCU_API inline void operator+=(uint3 &a, uint b)
{
  a.x += b; a.y += b; a.z += b;
}

MIRTKCU_API inline int3 operator+(int b, int3 a)
{
  return make_int3(a.x + b, a.y + b, a.z + b);
}
MIRTKCU_API inline uint3 operator+(uint b, uint3 a)
{
  return make_uint3(a.x + b, a.y + b, a.z + b);
}
MIRTKCU_API inline float3 operator+(float b, float3 a)
{
  return make_float3(a.x + b, a.y + b, a.z + b);
}

MIRTKCU_API inline float4 operator+(float4 a, float4 b)
{
  return make_float4(a.x + b.x, a.y + b.y, a.z + b.z,  a.w + b.w);
}
MIRTKCU_API inline void operator+=(float4 &a, float4 b)
{
  a.x += b.x; a.y += b.y; a.z += b.z; a.w += b.w;
}
MIRTKCU_API inline float4 operator+(float4 a, float b)
{
  return make_float4(a.x + b, a.y + b, a.z + b, a.w + b);
}
MIRTKCU_API inline float4 operator+(float b, float4 a)
{
  return make_float4(a.x + b, a.y + b, a.z + b, a.w + b);
}
MIRTKCU_API inline void operator+=(float4 &a, float b)
{
  a.x += b; a.y += b; a.z += b; a.w += b;
}

MIRTKCU_API inline int4 operator+(int4 a, int4 b)
{
  return make_int4(a.x + b.x, a.y + b.y, a.z + b.z,  a.w + b.w);
}
MIRTKCU_API inline void operator+=(int4 &a, int4 b)
{
  a.x += b.x; a.y += b.y; a.z += b.z; a.w += b.w;
}
MIRTKCU_API inline int4 operator+(int4 a, int b)
{
  return make_int4(a.x + b, a.y + b, a.z + b,  a.w + b);
}
MIRTKCU_API inline int4 operator+(int b, int4 a)
{
  return make_int4(a.x + b, a.y + b, a.z + b,  a.w + b);
}
MIRTKCU_API inline void operator+=(int4 &a, int b)
{
  a.x += b; a.y += b; a.z += b; a.w += b;
}

MIRTKCU_API inline uint4 operator+(uint4 a, uint4 b)
{
  return make_uint4(a.x + b.x, a.y + b.y, a.z + b.z,  a.w + b.w);
}
MIRTKCU_API inline void operator+=(uint4 &a, uint4 b)
{
  a.x += b.x; a.y += b.y; a.z += b.z; a.w += b.w;
}
MIRTKCU_API inline uint4 operator+(uint4 a, uint b)
{
  return make_uint4(a.x + b, a.y + b, a.z + b,  a.w + b);
}
MIRTKCU_API inline uint4 operator+(uint b, uint4 a)
{
  return make_uint4(a.x + b, a.y + b, a.z + b,  a.w + b);
}
MIRTKCU_API inline void operator+=(uint4 &a, uint b)
{
  a.x += b; a.y += b; a.z += b; a.w += b;
}

////////////////////////////////////////////////////////////////////////////////
// subtract
////////////////////////////////////////////////////////////////////////////////

MIRTKCU_API inline float2 operator-(float2 a, float2 b)
{
  return make_float2(a.x - b.x, a.y - b.y);
}
MIRTKCU_API inline void operator-=(float2 &a, float2 b)
{
  a.x -= b.x; a.y -= b.y;
}
MIRTKCU_API inline float2 operator-(float2 a, float b)
{
  return make_float2(a.x - b, a.y - b);
}
MIRTKCU_API inline float2 operator-(float b, float2 a)
{
  return make_float2(b - a.x, b - a.y);
}
MIRTKCU_API inline void operator-=(float2 &a, float b)
{
  a.x -= b; a.y -= b;
}

MIRTKCU_API inline int2 operator-(int2 a, int2 b)
{
  return make_int2(a.x - b.x, a.y - b.y);
}
MIRTKCU_API inline void operator-=(int2 &a, int2 b)
{
  a.x -= b.x; a.y -= b.y;
}
MIRTKCU_API inline int2 operator-(int2 a, int b)
{
  return make_int2(a.x - b, a.y - b);
}
MIRTKCU_API inline int2 operator-(int b, int2 a)
{
  return make_int2(b - a.x, b - a.y);
}
MIRTKCU_API inline void operator-=(int2 &a, int b)
{
  a.x -= b; a.y -= b;
}

MIRTKCU_API inline uint2 operator-(uint2 a, uint2 b)
{
  return make_uint2(a.x - b.x, a.y - b.y);
}
MIRTKCU_API inline void operator-=(uint2 &a, uint2 b)
{
  a.x -= b.x; a.y -= b.y;
}
MIRTKCU_API inline uint2 operator-(uint2 a, uint b)
{
  return make_uint2(a.x - b, a.y - b);
}
MIRTKCU_API inline uint2 operator-(uint b, uint2 a)
{
  return make_uint2(b - a.x, b - a.y);
}
MIRTKCU_API inline void operator-=(uint2 &a, uint b)
{
  a.x -= b; a.y -= b;
}

MIRTKCU_API inline float3 operator-(float3 a, float3 b)
{
  return make_float3(a.x - b.x, a.y - b.y, a.z - b.z);
}
MIRTKCU_API inline void operator-=(float3 &a, float3 b)
{
  a.x -= b.x; a.y -= b.y; a.z -= b.z;
}
MIRTKCU_API inline float3 operator-(float3 a, float b)
{
  return make_float3(a.x - b, a.y - b, a.z - b);
}
MIRTKCU_API inline float3 operator-(float b, float3 a)
{
  return make_float3(b - a.x, b - a.y, b - a.z);
}
MIRTKCU_API inline void operator-=(float3 &a, float b)
{
  a.x -= b; a.y -= b; a.z -= b;
}

MIRTKCU_API inline int3 operator-(int3 a, int3 b)
{
  return make_int3(a.x - b.x, a.y - b.y, a.z - b.z);
}
MIRTKCU_API inline void operator-=(int3 &a, int3 b)
{
  a.x -= b.x; a.y -= b.y; a.z -= b.z;
}
MIRTKCU_API inline int3 operator-(int3 a, int b)
{
  return make_int3(a.x - b, a.y - b, a.z - b);
}
MIRTKCU_API inline int3 operator-(int b, int3 a)
{
  return make_int3(b - a.x, b - a.y, b - a.z);
}
MIRTKCU_API inline void operator-=(int3 &a, int b)
{
  a.x -= b; a.y -= b; a.z -= b;
}

MIRTKCU_API inline uint3 operator-(uint3 a, uint3 b)
{
  return make_uint3(a.x - b.x, a.y - b.y, a.z - b.z);
}
MIRTKCU_API inline void operator-=(uint3 &a, uint3 b)
{
  a.x -= b.x; a.y -= b.y; a.z -= b.z;
}
MIRTKCU_API inline uint3 operator-(uint3 a, uint b)
{
  return make_uint3(a.x - b, a.y - b, a.z - b);
}
MIRTKCU_API inline uint3 operator-(uint b, uint3 a)
{
  return make_uint3(b - a.x, b - a.y, b - a.z);
}
MIRTKCU_API inline void operator-=(uint3 &a, uint b)
{
  a.x -= b; a.y -= b; a.z -= b;
}

MIRTKCU_API inline float4 operator-(float4 a, float4 b)
{
  return make_float4(a.x - b.x, a.y - b.y, a.z - b.z,  a.w - b.w);
}
MIRTKCU_API inline void operator-=(float4 &a, float4 b)
{
  a.x -= b.x; a.y -= b.y; a.z -= b.z; a.w -= b.w;
}
MIRTKCU_API inline float4 operator-(float4 a, float b)
{
  return make_float4(a.x - b, a.y - b, a.z - b,  a.w - b);
}
MIRTKCU_API inline void operator-=(float4 &a, float b)
{
  a.x -= b; a.y -= b; a.z -= b; a.w -= b;
}

MIRTKCU_API inline int4 operator-(int4 a, int4 b)
{
  return make_int4(a.x - b.x, a.y - b.y, a.z - b.z,  a.w - b.w);
}
MIRTKCU_API inline void operator-=(int4 &a, int4 b)
{
  a.x -= b.x; a.y -= b.y; a.z -= b.z; a.w -= b.w;
}
MIRTKCU_API inline int4 operator-(int4 a, int b)
{
  return make_int4(a.x - b, a.y - b, a.z - b,  a.w - b);
}
MIRTKCU_API inline int4 operator-(int b, int4 a)
{
  return make_int4(b - a.x, b - a.y, b - a.z, b - a.w);
}
MIRTKCU_API inline void operator-=(int4 &a, int b)
{
  a.x -= b; a.y -= b; a.z -= b; a.w -= b;
}

MIRTKCU_API inline uint4 operator-(uint4 a, uint4 b)
{
  return make_uint4(a.x - b.x, a.y - b.y, a.z - b.z,  a.w - b.w);
}
MIRTKCU_API inline void operator-=(uint4 &a, uint4 b)
{
  a.x -= b.x; a.y -= b.y; a.z -= b.z; a.w -= b.w;
}
MIRTKCU_API inline uint4 operator-(uint4 a, uint b)
{
  return make_uint4(a.x - b, a.y - b, a.z - b,  a.w - b);
}
MIRTKCU_API inline uint4 operator-(uint b, uint4 a)
{
  return make_uint4(b - a.x, b - a.y, b - a.z, b - a.w);
}
MIRTKCU_API inline void operator-=(uint4 &a, uint b)
{
  a.x -= b; a.y -= b; a.z -= b; a.w -= b;
}

////////////////////////////////////////////////////////////////////////////////
// multiply
////////////////////////////////////////////////////////////////////////////////

MIRTKCU_API inline float2 operator*(float2 a, float2 b)
{
  return make_float2(a.x * b.x, a.y * b.y);
}
MIRTKCU_API inline void operator*=(float2 &a, float2 b)
{
  a.x *= b.x; a.y *= b.y;
}
MIRTKCU_API inline float2 operator*(float2 a, float b)
{
  return make_float2(a.x * b, a.y * b);
}
MIRTKCU_API inline float2 operator*(float b, float2 a)
{
  return make_float2(b * a.x, b * a.y);
}
MIRTKCU_API inline void operator*=(float2 &a, float b)
{
  a.x *= b; a.y *= b;
}

MIRTKCU_API inline int2 operator*(int2 a, int2 b)
{
  return make_int2(a.x * b.x, a.y * b.y);
}
MIRTKCU_API inline void operator*=(int2 &a, int2 b)
{
  a.x *= b.x; a.y *= b.y;
}
MIRTKCU_API inline int2 operator*(int2 a, int b)
{
  return make_int2(a.x * b, a.y * b);
}
MIRTKCU_API inline int2 operator*(int b, int2 a)
{
  return make_int2(b * a.x, b * a.y);
}
MIRTKCU_API inline void operator*=(int2 &a, int b)
{
  a.x *= b; a.y *= b;
}

MIRTKCU_API inline uint2 operator*(uint2 a, uint2 b)
{
  return make_uint2(a.x * b.x, a.y * b.y);
}
MIRTKCU_API inline void operator*=(uint2 &a, uint2 b)
{
  a.x *= b.x; a.y *= b.y;
}
MIRTKCU_API inline uint2 operator*(uint2 a, uint b)
{
  return make_uint2(a.x * b, a.y * b);
}
MIRTKCU_API inline uint2 operator*(uint b, uint2 a)
{
  return make_uint2(b * a.x, b * a.y);
}
MIRTKCU_API inline void operator*=(uint2 &a, uint b)
{
  a.x *= b; a.y *= b;
}

MIRTKCU_API inline float3 operator*(float3 a, float3 b)
{
  return make_float3(a.x * b.x, a.y * b.y, a.z * b.z);
}
MIRTKCU_API inline void operator*=(float3 &a, float3 b)
{
  a.x *= b.x; a.y *= b.y; a.z *= b.z;
}
MIRTKCU_API inline float3 operator*(float3 a, float b)
{
  return make_float3(a.x * b, a.y * b, a.z * b);
}
MIRTKCU_API inline float3 operator*(float b, float3 a)
{
  return make_float3(b * a.x, b * a.y, b * a.z);
}
MIRTKCU_API inline void operator*=(float3 &a, float b)
{
  a.x *= b; a.y *= b; a.z *= b;
}

MIRTKCU_API inline int3 operator*(int3 a, int3 b)
{
  return make_int3(a.x * b.x, a.y * b.y, a.z * b.z);
}
MIRTKCU_API inline void operator*=(int3 &a, int3 b)
{
  a.x *= b.x; a.y *= b.y; a.z *= b.z;
}
MIRTKCU_API inline int3 operator*(int3 a, int b)
{
  return make_int3(a.x * b, a.y * b, a.z * b);
}
MIRTKCU_API inline int3 operator*(int b, int3 a)
{
  return make_int3(b * a.x, b * a.y, b * a.z);
}
MIRTKCU_API inline void operator*=(int3 &a, int b)
{
  a.x *= b; a.y *= b; a.z *= b;
}

MIRTKCU_API inline uint3 operator*(uint3 a, uint3 b)
{
  return make_uint3(a.x * b.x, a.y * b.y, a.z * b.z);
}
MIRTKCU_API inline void operator*=(uint3 &a, uint3 b)
{
  a.x *= b.x; a.y *= b.y; a.z *= b.z;
}
MIRTKCU_API inline uint3 operator*(uint3 a, uint b)
{
  return make_uint3(a.x * b, a.y * b, a.z * b);
}
MIRTKCU_API inline uint3 operator*(uint b, uint3 a)
{
  return make_uint3(b * a.x, b * a.y, b * a.z);
}
MIRTKCU_API inline void operator*=(uint3 &a, uint b)
{
  a.x *= b; a.y *= b; a.z *= b;
}

MIRTKCU_API inline float4 operator*(float4 a, float4 b)
{
  return make_float4(a.x * b.x, a.y * b.y, a.z * b.z,  a.w * b.w);
}
MIRTKCU_API inline void operator*=(float4 &a, float4 b)
{
  a.x *= b.x; a.y *= b.y; a.z *= b.z; a.w *= b.w;
}
MIRTKCU_API inline float4 operator*(float4 a, float b)
{
  return make_float4(a.x * b, a.y * b, a.z * b,  a.w * b);
}
MIRTKCU_API inline float4 operator*(float b, float4 a)
{
  return make_float4(b * a.x, b * a.y, b * a.z, b * a.w);
}
MIRTKCU_API inline void operator*=(float4 &a, float b)
{
  a.x *= b; a.y *= b; a.z *= b; a.w *= b;
}

MIRTKCU_API inline int4 operator*(int4 a, int4 b)
{
  return make_int4(a.x * b.x, a.y * b.y, a.z * b.z,  a.w * b.w);
}
MIRTKCU_API inline void operator*=(int4 &a, int4 b)
{
  a.x *= b.x; a.y *= b.y; a.z *= b.z; a.w *= b.w;
}
MIRTKCU_API inline int4 operator*(int4 a, int b)
{
  return make_int4(a.x * b, a.y * b, a.z * b,  a.w * b);
}
MIRTKCU_API inline int4 operator*(int b, int4 a)
{
  return make_int4(b * a.x, b * a.y, b * a.z, b * a.w);
}
MIRTKCU_API inline void operator*=(int4 &a, int b)
{
  a.x *= b; a.y *= b; a.z *= b; a.w *= b;
}

MIRTKCU_API inline uint4 operator*(uint4 a, uint4 b)
{
  return make_uint4(a.x * b.x, a.y * b.y, a.z * b.z,  a.w * b.w);
}
MIRTKCU_API inline void operator*=(uint4 &a, uint4 b)
{
  a.x *= b.x; a.y *= b.y; a.z *= b.z; a.w *= b.w;
}
MIRTKCU_API inline uint4 operator*(uint4 a, uint b)
{
  return make_uint4(a.x * b, a.y * b, a.z * b,  a.w * b);
}
MIRTKCU_API inline uint4 operator*(uint b, uint4 a)
{
  return make_uint4(b * a.x, b * a.y, b * a.z, b * a.w);
}
MIRTKCU_API inline void operator*=(uint4 &a, uint b)
{
  a.x *= b; a.y *= b; a.z *= b; a.w *= b;
}

////////////////////////////////////////////////////////////////////////////////
// divide
////////////////////////////////////////////////////////////////////////////////

MIRTKCU_API inline float2 operator/(float2 a, float2 b)
{
  return make_float2(a.x / b.x, a.y / b.y);
}
MIRTKCU_API inline void operator/=(float2 &a, float2 b)
{
    a.x /= b.x; a.y /= b.y;
}
MIRTKCU_API inline float2 operator/(float2 a, float b)
{
  return make_float2(a.x / b, a.y / b);
}
MIRTKCU_API inline void operator/=(float2 &a, float b)
{
    a.x /= b; a.y /= b;
}
MIRTKCU_API inline float2 operator/(float b, float2 a)
{
  return make_float2(b / a.x, b / a.y);
}

MIRTKCU_API inline float3 operator/(float3 a, float3 b)
{
  return make_float3(a.x / b.x, a.y / b.y, a.z / b.z);
}
MIRTKCU_API inline void operator/=(float3 &a, float3 b)
{
    a.x /= b.x; a.y /= b.y; a.z /= b.z;
}
MIRTKCU_API inline float3 operator/(float3 a, float b)
{
  return make_float3(a.x / b, a.y / b, a.z / b);
}
MIRTKCU_API inline void operator/=(float3 &a, float b)
{
    a.x /= b; a.y /= b; a.z /= b;
}
MIRTKCU_API inline float3 operator/(float b, float3 a)
{
  return make_float3(b / a.x, b / a.y, b / a.z);
}

MIRTKCU_API inline float4 operator/(float4 a, float4 b)
{
  return make_float4(a.x / b.x, a.y / b.y, a.z / b.z,  a.w / b.w);
}
MIRTKCU_API inline void operator/=(float4 &a, float4 b)
{
    a.x /= b.x; a.y /= b.y; a.z /= b.z; a.w /= b.w;
}
MIRTKCU_API inline float4 operator/(float4 a, float b)
{
  return make_float4(a.x / b, a.y / b, a.z / b,  a.w / b);
}
MIRTKCU_API inline void operator/=(float4 &a, float b)
{
    a.x /= b; a.y /= b; a.z /= b; a.w /= b;
}
MIRTKCU_API inline float4 operator/(float b, float4 a){
  return make_float4(b / a.x, b / a.y, b / a.z, b / a.w);
}

////////////////////////////////////////////////////////////////////////////////
// min
////////////////////////////////////////////////////////////////////////////////

MIRTKCU_API inline float2 fminf(float2 a, float2 b)
{
  return make_float2(fminf(a.x,b.x), fminf(a.y,b.y));
}
MIRTKCU_API inline float3 fminf(float3 a, float3 b)
{
  return make_float3(fminf(a.x,b.x), fminf(a.y,b.y), fminf(a.z,b.z));
}
MIRTKCU_API inline float4 fminf(float4 a, float4 b)
{
  return make_float4(fminf(a.x,b.x), fminf(a.y,b.y), fminf(a.z,b.z), fminf(a.w,b.w));
}

MIRTKCU_API inline int2 min(int2 a, int2 b)
{
  return make_int2(min(a.x,b.x), min(a.y,b.y));
}
MIRTKCU_API inline int3 min(int3 a, int3 b)
{
  return make_int3(min(a.x,b.x), min(a.y,b.y), min(a.z,b.z));
}
MIRTKCU_API inline int4 min(int4 a, int4 b)
{
  return make_int4(min(a.x,b.x), min(a.y,b.y), min(a.z,b.z), min(a.w,b.w));
}

MIRTKCU_API inline uint2 min(uint2 a, uint2 b)
{
  return make_uint2(min(a.x,b.x), min(a.y,b.y));
}
MIRTKCU_API inline uint3 min(uint3 a, uint3 b)
{
  return make_uint3(min(a.x,b.x), min(a.y,b.y), min(a.z,b.z));
}
MIRTKCU_API inline uint4 min(uint4 a, uint4 b)
{
  return make_uint4(min(a.x,b.x), min(a.y,b.y), min(a.z,b.z), min(a.w,b.w));
}

MIRTKCU_API inline uint min(uint2 a)
{
  return min(a.x,a.y);
}
MIRTKCU_API inline uint min(uint3 a)
{
  return min(a.x,min(a.y, a.z));
}
MIRTKCU_API inline uint min(uint4 a)
{
  return min(min(a.x, a.y),min(a.z, a.w));
}

MIRTKCU_API inline float min(float2 a)
{
  return min(a.x,a.y);
}
MIRTKCU_API inline float min(float3 a)
{
  return min(a.x,min(a.y, a.z));
}
MIRTKCU_API inline float min(float4 a)
{
  return min(min(a.x, a.y),min(a.z, a.w));
}

////////////////////////////////////////////////////////////////////////////////
// max
////////////////////////////////////////////////////////////////////////////////

MIRTKCU_API inline float2 fmaxf(float2 a, float2 b)
{
  return make_float2(fmaxf(a.x,b.x), fmaxf(a.y,b.y));
}
MIRTKCU_API inline float3 fmaxf(float3 a, float3 b)
{
  return make_float3(fmaxf(a.x,b.x), fmaxf(a.y,b.y), fmaxf(a.z,b.z));
}
MIRTKCU_API inline float4 fmaxf(float4 a, float4 b)
{
  return make_float4(fmaxf(a.x,b.x), fmaxf(a.y,b.y), fmaxf(a.z,b.z), fmaxf(a.w,b.w));
}

MIRTKCU_API inline int2 max(int2 a, int2 b)
{
  return make_int2(max(a.x,b.x), max(a.y,b.y));
}
MIRTKCU_API inline int3 max(int3 a, int3 b)
{
  return make_int3(max(a.x,b.x), max(a.y,b.y), max(a.z,b.z));
}
MIRTKCU_API inline int4 max(int4 a, int4 b)
{
  return make_int4(max(a.x,b.x), max(a.y,b.y), max(a.z,b.z), max(a.w,b.w));
}

MIRTKCU_API inline uint2 max(uint2 a, uint2 b)
{
  return make_uint2(max(a.x,b.x), max(a.y,b.y));
}
MIRTKCU_API inline uint3 max(uint3 a, uint3 b)
{
  return make_uint3(max(a.x,b.x), max(a.y,b.y), max(a.z,b.z));
}
MIRTKCU_API inline uint4 max(uint4 a, uint4 b)
{
  return make_uint4(max(a.x,b.x), max(a.y,b.y), max(a.z,b.z), max(a.w,b.w));
}

MIRTKCU_API inline uint max(uint2 a)
{
  return max(a.x,a.y);
}
MIRTKCU_API inline uint max(uint3 a)
{
  return max(a.x,max(a.y, a.z));
}
MIRTKCU_API inline uint max(uint4 a)
{
  return max(max(a.x, a.y),max(a.z, a.w));
}

MIRTKCU_API inline float max(float2 a)
{
  return max(a.x,a.y);
}
MIRTKCU_API inline float max(float3 a)
{
  return max(a.x,max(a.y, a.z));
}
MIRTKCU_API inline float max(float4 a)
{
  return max(max(a.x, a.y),max(a.z, a.w));
}

////////////////////////////////////////////////////////////////////////////////
// lerp
// - linear interpolation between a and b, based on value t in [0, 1] range
////////////////////////////////////////////////////////////////////////////////

MIRTKCU_API inline float lerp(float a, float b, float t)
{
  return a + t*(b-a);
}
MIRTKCU_API inline float2 lerp(float2 a, float2 b, float t)
{
  return a + t*(b-a);
}
MIRTKCU_API inline float3 lerp(float3 a, float3 b, float t)
{
  return a + t*(b-a);
}
MIRTKCU_API inline float4 lerp(float4 a, float4 b, float t)
{
  return a + t*(b-a);
}

////////////////////////////////////////////////////////////////////////////////
// clamp
// - clamp the value v to be in the range [a, b]
////////////////////////////////////////////////////////////////////////////////

MIRTKCU_API inline float clamp(float f, float a, float b)
{
  return fmaxf(a, fminf(f, b));
}
MIRTKCU_API inline int clamp(int f, int a, int b)
{
  return max(a, min(f, b));
}
MIRTKCU_API inline uint clamp(uint f, uint a, uint b)
{
  return max(a, min(f, b));
}

MIRTKCU_API inline float2 clamp(float2 v, float a, float b)
{
  return make_float2(clamp(v.x, a, b), clamp(v.y, a, b));
}
MIRTKCU_API inline float2 clamp(float2 v, float2 a, float2 b)
{
  return make_float2(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y));
}
MIRTKCU_API inline float3 clamp(float3 v, float a, float b)
{
  return make_float3(clamp(v.x, a, b), clamp(v.y, a, b), clamp(v.z, a, b));
}
MIRTKCU_API inline float3 clamp(float3 v, float3 a, float3 b)
{
  return make_float3(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y), clamp(v.z, a.z, b.z));
}
MIRTKCU_API inline float4 clamp(float4 v, float a, float b)
{
  return make_float4(clamp(v.x, a, b), clamp(v.y, a, b), clamp(v.z, a, b), clamp(v.w, a, b));
}
MIRTKCU_API inline float4 clamp(float4 v, float4 a, float4 b)
{
  return make_float4(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y), clamp(v.z, a.z, b.z), clamp(v.w, a.w, b.w));
}

MIRTKCU_API inline int2 clamp(int2 v, int a, int b)
{
  return make_int2(clamp(v.x, a, b), clamp(v.y, a, b));
}
MIRTKCU_API inline int2 clamp(int2 v, int2 a, int2 b)
{
  return make_int2(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y));
}
MIRTKCU_API inline int3 clamp(int3 v, int a, int b)
{
  return make_int3(clamp(v.x, a, b), clamp(v.y, a, b), clamp(v.z, a, b));
}
MIRTKCU_API inline int3 clamp(int3 v, int3 a, int3 b)
{
  return make_int3(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y), clamp(v.z, a.z, b.z));
}
MIRTKCU_API inline int4 clamp(int4 v, int a, int b)
{
  return make_int4(clamp(v.x, a, b), clamp(v.y, a, b), clamp(v.z, a, b), clamp(v.w, a, b));
}
MIRTKCU_API inline int4 clamp(int4 v, int4 a, int4 b)
{
  return make_int4(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y), clamp(v.z, a.z, b.z), clamp(v.w, a.w, b.w));
}

MIRTKCU_API inline uint2 clamp(uint2 v, uint a, uint b)
{
  return make_uint2(clamp(v.x, a, b), clamp(v.y, a, b));
}
MIRTKCU_API inline uint2 clamp(uint2 v, uint2 a, uint2 b)
{
  return make_uint2(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y));
}
MIRTKCU_API inline uint3 clamp(uint3 v, uint a, uint b)
{
  return make_uint3(clamp(v.x, a, b), clamp(v.y, a, b), clamp(v.z, a, b));
}
MIRTKCU_API inline uint3 clamp(uint3 v, uint3 a, uint3 b)
{
  return make_uint3(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y), clamp(v.z, a.z, b.z));
}
MIRTKCU_API inline uint4 clamp(uint4 v, uint a, uint b)
{
  return make_uint4(clamp(v.x, a, b), clamp(v.y, a, b), clamp(v.z, a, b), clamp(v.w, a, b));
}
MIRTKCU_API inline uint4 clamp(uint4 v, uint4 a, uint4 b)
{
  return make_uint4(clamp(v.x, a.x, b.x), clamp(v.y, a.y, b.y), clamp(v.z, a.z, b.z), clamp(v.w, a.w, b.w));
}

////////////////////////////////////////////////////////////////////////////////
// dot product
////////////////////////////////////////////////////////////////////////////////

MIRTKCU_API inline float dot(float2 a, float2 b)
{
  return a.x * b.x + a.y * b.y;
}
MIRTKCU_API inline float dot(float3 a, float3 b)
{
  return a.x * b.x + a.y * b.y + a.z * b.z;
}
MIRTKCU_API inline float dot(float4 a, float4 b)
{
  return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

MIRTKCU_API inline int dot(int2 a, int2 b)
{
  return a.x * b.x + a.y * b.y;
}
MIRTKCU_API inline int dot(int3 a, int3 b)
{
  return a.x * b.x + a.y * b.y + a.z * b.z;
}
MIRTKCU_API inline int dot(int4 a, int4 b)
{
  return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

MIRTKCU_API inline uint dot(uint2 a, uint2 b)
{
  return a.x * b.x + a.y * b.y;
}
MIRTKCU_API inline uint dot(uint3 a, uint3 b)
{
  return a.x * b.x + a.y * b.y + a.z * b.z;
}
MIRTKCU_API inline uint dot(uint4 a, uint4 b)
{
  return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

////////////////////////////////////////////////////////////////////////////////
// length
////////////////////////////////////////////////////////////////////////////////

MIRTKCU_API inline float length(float2 v)
{
  return sqrtf(dot(v, v));
}
MIRTKCU_API inline float length(float3 v)
{
  return sqrtf(dot(v, v));
}
MIRTKCU_API inline float length(float4 v)
{
  return sqrtf(dot(v, v));
}

////////////////////////////////////////////////////////////////////////////////
// normalize
////////////////////////////////////////////////////////////////////////////////

MIRTKCU_API inline float2 normalize(float2 v)
{
    float invLen = rsqrtf(dot(v, v));
  return v * invLen;
}
MIRTKCU_API inline float3 normalize(float3 v)
{
    float invLen = rsqrtf(dot(v, v));
  return v * invLen;
}
MIRTKCU_API inline float4 normalize(float4 v)
{
    float invLen = rsqrtf(dot(v, v));
  return v * invLen;
}

////////////////////////////////////////////////////////////////////////////////
// floor
////////////////////////////////////////////////////////////////////////////////

MIRTKCU_API inline float2 floorf(float2 v)
{
  return make_float2(floorf(v.x), floorf(v.y));
}
MIRTKCU_API inline float3 floorf(float3 v)
{
  return make_float3(floorf(v.x), floorf(v.y), floorf(v.z));
}
MIRTKCU_API inline float4 floorf(float4 v)
{
  return make_float4(floorf(v.x), floorf(v.y), floorf(v.z), floorf(v.w));
}

////////////////////////////////////////////////////////////////////////////////
// frac - returns the fractional portion of a scalar or each vector component
////////////////////////////////////////////////////////////////////////////////

MIRTKCU_API inline float fracf(float v)
{
  return v - floorf(v);
}
MIRTKCU_API inline float2 fracf(float2 v)
{
  return make_float2(fracf(v.x), fracf(v.y));
}
MIRTKCU_API inline float3 fracf(float3 v)
{
  return make_float3(fracf(v.x), fracf(v.y), fracf(v.z));
}
MIRTKCU_API inline float4 fracf(float4 v)
{
  return make_float4(fracf(v.x), fracf(v.y), fracf(v.z), fracf(v.w));
}

////////////////////////////////////////////////////////////////////////////////
// fmod
////////////////////////////////////////////////////////////////////////////////

MIRTKCU_API inline float2 fmodf(float2 a, float2 b)
{
  return make_float2(fmodf(a.x, b.x), fmodf(a.y, b.y));
}
MIRTKCU_API inline float3 fmodf(float3 a, float3 b)
{
  return make_float3(fmodf(a.x, b.x), fmodf(a.y, b.y), fmodf(a.z, b.z));
}
MIRTKCU_API inline float4 fmodf(float4 a, float4 b)
{
  return make_float4(fmodf(a.x, b.x), fmodf(a.y, b.y), fmodf(a.z, b.z), fmodf(a.w, b.w));
}

////////////////////////////////////////////////////////////////////////////////
// absolute value
////////////////////////////////////////////////////////////////////////////////

MIRTKCU_API inline float2 fabs(float2 v)
{
	return make_float2(fabs(v.x), fabs(v.y));
}
MIRTKCU_API inline float3 fabs(float3 v)
{
	return make_float3(fabs(v.x), fabs(v.y), fabs(v.z));
}
MIRTKCU_API inline float4 fabs(float4 v)
{
	return make_float4(fabs(v.x), fabs(v.y), fabs(v.z), fabs(v.w));
}

MIRTKCU_API inline int2 abs(int2 v)
{
	return make_int2(abs(v.x), abs(v.y));
}
MIRTKCU_API inline int3 abs(int3 v)
{
	return make_int3(abs(v.x), abs(v.y), abs(v.z));
}
MIRTKCU_API inline int4 abs(int4 v)
{
	return make_int4(abs(v.x), abs(v.y), abs(v.z), abs(v.w));
}

////////////////////////////////////////////////////////////////////////////////
// reflect
// - returns reflection of incident ray I around surface normal N
// - N should be normalized, reflected vector's length is equal to length of I
////////////////////////////////////////////////////////////////////////////////

MIRTKCU_API inline float3 reflect(float3 i, float3 n)
{
	return i - 2.0f * n * dot(n,i);
}

////////////////////////////////////////////////////////////////////////////////
// cross product
////////////////////////////////////////////////////////////////////////////////

MIRTKCU_API inline float3 cross(float3 a, float3 b)
{
  return make_float3(a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x);
}

////////////////////////////////////////////////////////////////////////////////
// smoothstep
// - returns 0 if x < a
// - returns 1 if x > b
// - otherwise returns smooth interpolation between 0 and 1 based on x
////////////////////////////////////////////////////////////////////////////////

MIRTKCU_API inline float smoothstep(float a, float b, float x)
{
	float y = clamp((x - a) / (b - a), 0.0f, 1.0f);
	return (y*y*(3.0f - (2.0f*y)));
}
MIRTKCU_API inline float2 smoothstep(float2 a, float2 b, float2 x)
{
	float2 y = clamp((x - a) / (b - a), 0.0f, 1.0f);
	return (y*y*(make_float2(3.0f) - (make_float2(2.0f)*y)));
}
MIRTKCU_API inline float3 smoothstep(float3 a, float3 b, float3 x)
{
	float3 y = clamp((x - a) / (b - a), 0.0f, 1.0f);
	return (y*y*(make_float3(3.0f) - (make_float3(2.0f)*y)));
}
MIRTKCU_API inline float4 smoothstep(float4 a, float4 b, float4 x)
{
	float4 y = clamp((x - a) / (b - a), 0.0f, 1.0f);
	return (y*y*(make_float4(3.0f) - (make_float4(2.0f)*y)));
}

////////////////////////////////////////////////////////////////////////////////
// shift
////////////////////////////////////////////////////////////////////////////////

MIRTKCU_API inline uint2 operator<<(uint2 a, int b)
{
  return make_uint2(a.x  << b, a.y << b);
}

MIRTKCU_API inline uint3 operator<<(uint3 a, int b)
{
  return make_uint3(a.x  << b, a.y << b, a.z << b);
}

MIRTKCU_API inline uint4 operator<<(uint4 a, int b)
{
  return make_uint4(a.x << b, a.y << b, a.z << b, a.w << b);
}

MIRTKCU_API inline uint2 operator>>(uint2 a, int b)
{
  return make_uint2(a.x  >> b, a.y >> b);
}

MIRTKCU_API inline uint3 operator>>(uint3 a, int b)
{
  return make_uint3(a.x  >> b, a.y >> b, a.z >> b);
}

MIRTKCU_API inline uint4 operator>>(uint4 a, int b)
{
  return make_uint4(a.x >> b, a.y >> b, a.z >> b, a.w >> b);
}



MIRTKCU_API inline int2 operator<<(int2 a, int b)
{
  return make_int2(a.x  << b, a.y << b);
}

MIRTKCU_API inline int3 operator<<(int3 a, int b)
{
  return make_int3(a.x  << b, a.y << b, a.z << b);
}

MIRTKCU_API inline int4 operator<<(int4 a, int b)
{
  return make_int4(a.x << b, a.y << b, a.z << b, a.w << b);
}

MIRTKCU_API inline int2 operator>>(int2 a, int b)
{
  return make_int2(a.x  >> b, a.y >> b);
}

MIRTKCU_API inline int3 operator>>(int3 a, int b)
{
  return make_int3(a.x  >> b, a.y >> b, a.z >> b);
}

MIRTKCU_API inline int4 operator>>(int4 a, int b)
{
  return make_int4(a.x >> b, a.y >> b, a.z >> b, a.w >> b);
}


} // namespace mirtk

#endif // MIRTK_CutilMath_H
