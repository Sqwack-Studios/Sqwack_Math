#pragma once
#include "sqm_config.hpp"

#ifndef __SQ_MATH_SIMD_TYPES_HPP__
#define __SQ_MATH_SIMD_TYPES_HPP__

//compile time check for simd support? 
//runtime check for simd support-> no compile dispatching

//TODO: REMEMBER PULLING "ammintrin.h" for FMA4 instructions (although support looks scarce)!!!!!

namespace sqm
{
#ifdef SQM_SIMD
    

    #if defined(SQM_ENABLE_AVX) && defined(__AVX__)
        #define SQM_USING_AVX
        #include <immintrin.h>
    #endif//SQM_ENABLE_AVX

    #if defined(SQM_ENABLE_AVX2) && defined(__AVX2__)
        #define SQM_USING_AVX2
    #endif


   //    //AVX for another day...!
   //#ifdef SQM_ENABLE_AVX512
   //    #include <zmmintrin.h>
   //#endif//SQM_AVX512

 //TODO: Fix includes

#ifndef _MSC_VER
    #ifdef SQM_ENABLE_SSE

        #if defined(SQM_ENABLE_SSE2) && defined(__SSE2__)
            #define SQM_USING_SSE2
        #endif//SQM_SSE2

        #if defined(SQM_ENABLE_SSE3) && defined(__SSE3__)
            #define SQM_USING_SSE3
            #include <pmmintrin.h>
        #endif//SQM_SSE3

        #if defined(SQM_ENABLE_SSSE3) && defined(__SSSE3__)
            #define SQM_USING_SSSE3
            #include <tmmintrin.h>
        #endif//SQM_SSSE3

        #if defined(SQM_ENABLE_SSE41) && defined(__SSE4_1__)
            #define SQM_USING_SSE41
            #include <smmintrin.h>
        #endif//SQM_SSE4_1

        #if defined(SQM_ENABLE_SSE42) && defined(__SSE4_2__)
            #define SQM_USING_SSE42
            #include <nmmintrin.h>
        #endif//SQM_SSE4_2

    #endif//SQM_ENABLE_SSE

 

#else 
 //NOTE: MSVC likes to play it funny! Every single other compiler
 //defines ISA macros when they are enabled but MSVC goes on it's own.
 //This is a workaround for MSVC
 // 
 // 
//It appears that if:
// AVX2 is enabled, so is AVX.
// AVX enabled -> FMA3_AVX/AVX2, SSE4_2, SSE4_1, SSSE3, SSE3 is enabled
// if any of the SSE instructions greater than SSE2 is enabled, then SSE2 is also enabled. We can also check using other macros.   
    #ifdef __AVX__
    
        #if SQM_ENABLE_SSE42 
            #define SQM_USING_SSE42
        #endif
    
        #if SQM_ENABLE_SSE41
            #define SQM_USING_SSE41
        #endif
    
        #if SQM_ENABLE_SSSE3
            #define SQM_USING_SSSE3
        #endif
    
        #if SQM_ENABLE_SSE3
            #define SQM_USING_SSE3
        #endif
    //M_IX86_FP is only for 32 bits machines. In x86-64 SSE2 is enabled by default and we can check that by using _M_X64 preprocessor
        #if SQM_ENABLE_SSE2 && (defined(_M_X64) || ((defined(M_IX86_FP) && _M_IX86_FP >= 2)) )
            #define SQM_USING_SSE2
        #endif
    
    #endif //__AVX__      

#endif//!def _MSC_VER


#endif//SQM_SIMD



}


#endif //__SQ_MATH_SIMD_TYPES_HPP__
