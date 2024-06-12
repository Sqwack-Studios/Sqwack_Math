#ifndef __SQ_MATH_CONFIG_HPP__
#define __SQ_MATH_CONFIG_HPP__

#include <cstdint>


#ifdef SQM_ENABLE_SIMD
    #define SQM_SIMD
#else
    #define SQM_SCALAR
#endif


//SQM_INLINE
#ifdef _MSC_VER
    #define SQM_INLINE inline __forceinline
#else
    #define SQM_INLINE inline
#endif//SQM_INLINE

namespace sqm
{
    struct cpu_intrinsics
    {
        static bool is_SSE_available();
        static bool is_SSE2_available();
        static bool is_SSE3_available();
        static bool is_SSSE3_available();
        static bool is_SSE41_available();
        static bool is_SSE42_available();
        static bool is_FMA3_available();
        static bool is_FMA4_available();
        static bool is_AVX_available();
        static bool is_AVX2_available();
        static bool is_AVX512F_available();
        static bool is_AVX512DQ_available();




    private:
        static std::uint32_t arch_flags;


        enum class IntrinsicShifts : std::uint32_t
        {
            SSE = 1,
            SSE2 = 2,
            SSE3 = 4,
            SSSE3 = 8,
            SSE41 = 16,
            SSE42 = 32,
            FMA3 = 64,
            FMA4 = 128,
            AVX = 256,
            AVX2 = 512,
            AVX512F = 1024,
            AVX512DQ = 2048,
        };

        static bool check_flags(IntrinsicShifts shift);

    };

    inline bool cpu_intrinsics::check_flags(cpu_intrinsics::IntrinsicShifts shift)
    {

    }
}





#endif//__SQ_MATH_CONFIG_HPP__