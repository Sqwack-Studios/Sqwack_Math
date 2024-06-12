#ifndef _SQ_SSE2_INSTRUCTIONS_HPP_
#define _SQ_SSE2_INSTRUCTIONS_HPP_

#include "sqm_config.hpp"
#include "simd_config.hpp"

//#ifdef SQM_USING_SSE2

///////////////////////////////////////////////////
//           128bit REGISTER FP32 INTRINSICS     //
///////////////////////////////////////////////////
#include <xmmintrin.h>
#include <emmintrin.h>

namespace sqm::simd
{

    SQM_INLINE __m128 add_single(__m128 left, __m128 right);
    SQM_INLINE __m128 add_packed(__m128 left, __m128 right);
    SQM_INLINE __m128 sub_single(__m128 left, __m128 right);
    SQM_INLINE __m128 sub_packed(__m128 left, __m128 right);
    SQM_INLINE __m128 mul_single(__m128 left, __m128 right);
    SQM_INLINE __m128 mul_packed(__m128 left, __m128 right);
    SQM_INLINE __m128 div_single(__m128 left, __m128 right);
    SQM_INLINE __m128 div_packed(__m128 left, __m128 right);
    SQM_INLINE __m128 sqrt_single(__m128 left, __m128 right);
    SQM_INLINE __m128 sqrt_packed(__m128 left, __m128 right);
    SQM_INLINE __m128 reciprocal_single(__m128 input);
    SQM_INLINE __m128 reciprocal_packed(__m128 input);
    SQM_INLINE __m128 rcp_sqrt_single(__m128 input);
    SQM_INLINE __m128 rcp_sqrt_packed(__m128 input);
    SQM_INLINE __m128 min_single(__m128 left, __m128 right);
    SQM_INLINE __m128 min_packed(__m128 left, __m128 right);
    SQM_INLINE __m128 max_single(__m128 left, __m128 right);
    SQM_INLINE __m128 max_packed(__m128 left, __m128 right);
    ///////////////////////////////////////////////////
    //           FP32 ARITHMETIC OPERATORS           //
    // ////////////////////////////////////////////////

    SQM_INLINE __m128 add_single(__m128 left, __m128 right)
    {
        return _mm_add_ss(left, right);
    }


    SQM_INLINE __m128 add_packed(__m128 left, __m128 right)
    {
        return _mm_add_ps(left, right);
    }

    SQM_INLINE __m128 sub_single(__m128 left, __m128 right)
    {
        return _mm_sub_ss(left, right);
    }

    SQM_INLINE __m128 sub_packed(__m128 left, __m128 right)
    {
        return _mm_sub_ps(left, right);
    }

    SQM_INLINE __m128 mul_single(__m128 left, __m128 right)
    {
        return _mm_mul_ss(left, right);
    }

    SQM_INLINE __m128 mul_packed(__m128 left, __m128 right);
    SQM_INLINE __m128 div_single(__m128 left, __m128 right);
    SQM_INLINE __m128 div_packed(__m128 left, __m128 right);
    SQM_INLINE __m128 sqrt_single(__m128 left, __m128 right);
    SQM_INLINE __m128 sqrt_packed(__m128 left, __m128 right);
    SQM_INLINE __m128 reciprocal_single(__m128 input);
    SQM_INLINE __m128 reciprocal_packed(__m128 input);
    SQM_INLINE __m128 rcp_sqrt_single(__m128 input);
    SQM_INLINE __m128 rcp_sqrt_packed(__m128 input);
    SQM_INLINE __m128 min_single(__m128 left, __m128 right);
    SQM_INLINE __m128 min_packed(__m128 left, __m128 right);
    SQM_INLINE __m128 max_single(__m128 left, __m128 right);
    SQM_INLINE __m128 max_packed(__m128 left, __m128 right);
}


//#endif//SQM_USING_SSE2


#endif //_SQ_SSE2_INSTRUCTIONS_HPP_