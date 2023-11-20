#ifndef _SQ_MATH_TRAITS_HPP
#define _SQ_MATH_TRAITS_HPP

namespace sq::math
{
    class float2;
    class float3;
    class float4;

    class float2x2;
    class float2x3;
    class float2x4;

    class float3x3;
    class float3x2;
    class float3x4;

    class float4x4;
    class float4x2;
    class float4x3;


    struct float2_traits
    {
        using data_type = float;
        using mathematic_type = float2;
    };

    struct float3_traits
    {
        using data_type = float;
        using mathematic_type = float3;
    };

    struct float4_traits
    {
        using data_type = float;
        using mathematic_type = float4;
    };
}

#endif //_SQ_MATH_TRAITS_HPP
