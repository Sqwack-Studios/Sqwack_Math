#ifndef _SQ_MATH_FLOAT2_HPP_
#define _SQ_MATH_FLOAT2_HPP_


namespace sq::math
{
    class float2;
    class float3;
    class float4;

    //.....

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

    class float2 : public vector2<float2_traits>
    {
    public:


    };

    class float3 : public vector3<float3_traits>
    {
    public:

    };
}


#endif //_SQ_MATH_FLOAT2_HPP_