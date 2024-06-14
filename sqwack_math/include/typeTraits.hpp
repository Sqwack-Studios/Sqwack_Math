#ifndef _SQ_MATH_TYPE_TRAITS_HPP_
#define _SQ_MATH_TYPE_TRAITS_HPP_

#include <type_traits>
#include <type_traits>


namespace sqm
{
    namespace details
    {
        struct undefined{};
    }

    template<typename dataType>
    struct vector_traits
    {
        using data_type = details::undefined;
    };

    //Option 1: use traits with structs, but requires us to specialize, more text. Better looking syntax imo.
    //template<typename dataType>
    //struct has_vector_traits
    //{
    //    static constexpr bool result{ false };
    //};

    //template<>
    //struct has_vector_traits<float>
    //{
    //    static constexpr bool result{ true };
    //};

    //Option 2: with functions. Requires specialization, but looks much more compact. Syntax not good and requires building an object.
    //static constexpr bool has_vector_traits(...) { return false; }
    //static constexpr bool has_vector_traits(float) { return true; }


    //Option 3: templated variables using std::_Is_any_of_v. Similar syntax to struct and it's free of template specialization. Much cleaner.
    template<typename dataType>
    static constexpr bool has_vector_traits = std::_Is_any_of_v<dataType, float, double, std::uint32_t, std::int32_t>;

    //-------------------------------------//


//#define GENERATE_TRAITS(typeAlias, type)\
//    class typeAlias##1;\
//    class typeAlias##2;\
//    class typeAlias##3;\
//    class typeAlias##4;\
//                        \
//    class typeAlias##2x2;\
//    class typeAlias##2x3;\
//    class typeAlias##2x4;\
//                         \
//    class typeAlias##3x2;\
//    class typeAlias##3x3;\
//    class typeAlias##3x4;\
//                         \
//    class typeAlias##4x2;\
//    class typeAlias##4x3;\
//    class typeAlias##4x4;\
//                         \
//    template<>                               \
//    struct vector_traits<type>               \
//    {                                        \
//        using data_type = type;              \
//                                             \
//        using vector2_type = typeAlias##2;        \
//        using vector3_type = typeAlias##3;        \
//        using vector4_type = typeAlias##4;        \
//                                             \
//        using matrix2x2_type = typeAlias##2x2;    \
//        using matrix2x3_type = typeAlias##2x3;    \
//        using matrix2x4_type = typeAlias##2x4;    \
//                                             \
//        using matrix3x2_type = typeAlias##3x2;    \
//        using matrix3x3_type = typeAlias##3x3;    \
//        using matrix3x4_type = typeAlias##3x4;    \
//                                             \
//        using matrix4x2_type = typeAlias##4x2;    \
//        using matrix4x3_type = typeAlias##4x3;    \
//        using matrix4x4_type = typeAlias##4x4;    \
//    };                                       
//


 #define GENERATE_TRAITS(typeAlias, type)\
   template<>                               \
   struct vector_traits<type>               \
   {                                        \
       using data_type = type;              \
                                            \
       using vector2_type = typeAlias##2;        \
       using vector3_type = typeAlias##3;        \
       using vector4_type = typeAlias##4;        \
   };                                       


    //GENERATE_TRAITS(double, double);
    //GENERATE_TRAITS(uint, std::uint32_t);
    //GENERATE_TRAITS(int, std::int32_t);


    //template<typename dataType>
    //static constexpr bool is_square_matrix = std::_Is_any_of_v<dataType, 
    //                                                                     float2x2,  float3x3,  float4x4, 
    //                                                                     double2x2, double3x3, double4x4,
    //                                                                     uint2x2,   uint3x3,   uint4x4,
    //                                                                     int2x2,    int3x3,    int4x4>;
}




#endif //_SQ_MATH_TYPE_TRAITS_HPP_