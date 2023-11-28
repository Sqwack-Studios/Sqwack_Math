#ifndef _SQ_MATH_TYPE_TRAITS_HPP_
#define _SQ_MATH_TYPE_TRAITS_HPP_



namespace sqm
{
    template<typename dataType>
    struct vector_traits
    {

    };

    class float2;
    class float3;
    class float4;

    class float2x2;
    class float2x3;
    class float2x4;

    class float3x2;
    class float3x3;
    class float3x4;

    class float4x2;
    class float4x3;
    class float4x4;


    template<>
    struct vector_traits<float>
    {
        using data_type = float;

        using vector2_type = float2;
        using vector3_type = float3;
        using vector4_type = float4;

        using matrix2x2_type = float2x2;
        using matrix2x3_type = float2x3;
        using matrix2x4_type = float2x4;

        using matrix3x2_type = float3x2;
        using matrix3x3_type = float3x3;
        using matrix3x4_type = float3x4;

        using matrix4x2_type = float4x2;
        using matrix4x3_type = float4x3;
        using matrix4x4_type = float4x4;
    };
}




#endif //_SQ_MATH_TYPE_TRAITS_HPP_