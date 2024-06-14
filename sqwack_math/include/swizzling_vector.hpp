#ifndef _SQM_SWIZZLING_VECTOR_
#define _SQM_SWIZZLING_VECTOR_

#include "swizzling.hpp"

namespace sqm
{
    template<size_t N, typename T>
    class vector;

    //TODO: Try constexpr factory functions

    template<typename T>
    class vector<2, T>
    {
    public:
        //using traits = vector_traits<T>;
        using data_type = T;
        using mathematic_type = vector<2, T>;

        constexpr vector<2, data_type>() = default;
        constexpr vector<2, data_type>(const vector<2, data_type>& rhs) = default;
        constexpr vector<2, data_type>(data_type _x, data_type _y) { data[0] = _x; data[1] = _y; };
        constexpr vector<2, data_type>(data_type all) { data[0] = all; data[1] = all; };

        vector<2, T>& operator=(const vector<2, T>& rhs) = default;

        static constexpr size_t length{ 2u };
        union //union that represents: each component of the vector, and each swizzle combination
        {
            data_type data[length];

            nthComponent<data_type, length, 0u> x;
            nthComponent<data_type, length, 1u> y;
            
            nthComponent<data_type, length, 0u> r;
            nthComponent<data_type, length, 1u> g;

            //Space coords
            SwizzleProxy<data_type, mathematic_type, 2u, 0u, 1u> xy;
            SwizzleProxy<data_type, mathematic_type, 2u, 1u, 0u> yx;

            //Color coords
            //SwizzleProxy<data_type, traits::vector2_type, 2u, 0u, 1u> rg;
            //SwizzleProxy<data_type, traits::vector2_type, 2u, 1u, 0u> gb;
            //Add repetition proxies?

        };
    };

    //template<typename T>
    //class vector<3, T>
    //{
    //public:
    //    using traits = vector_traits<T>;
    //    using data_type = T;
    //    using mathematic_type = traits::vector3_type;
    //
    //    static constexpr size_t length{ 3u };
    //
    //
    //    constexpr vector<3, T>() = default;
    //    constexpr vector<3, T>(const vector<3, T>& rhs) = default;
    //    constexpr vector<3, T>(data_type _x, data_type _y, data_type _z) : x(x_), y(_y), z(_z) { x = _x, y = _y, z = _z; };
    //    constexpr vector<3, T>(data_type all) : x(all), y(all), z(all) {};
    //
    //    union
    //    {
    //        //Space coords components//
    //        nthComponent<data_type, length, 0> x;
    //        nthComponent<data_type, length, 1> y;
    //        nthComponent<data_type, length, 2> z;
    //
    //
    //        SwizzleProxy<data_type, traits::vector2_type, 2, 0, 1> xy;
    //        SwizzleProxy<data_type, traits::vector2_type, 2, 1, 0> yx;
    //        SwizzleProxy<data_type, traits::vector2_type, 2, 0, 2> xz;
    //        SwizzleProxy<data_type, traits::vector2_type, 2, 2, 0> zx;
    //        SwizzleProxy<data_type, traits::vector2_type, 2, 1, 2> yz;
    //        SwizzleProxy<data_type, traits::vector2_type, 2, 2, 1> zy;
    //
    //        SwizzleProxy<data_type, traits::vector3_type, 3, 0, 1, 2> xyz;
    //        SwizzleProxy<data_type, traits::vector3_type, 3, 1, 0, 2> yxz;
    //        SwizzleProxy<data_type, traits::vector3_type, 3, 1, 2, 0> yzx;
    //        SwizzleProxy<data_type, traits::vector3_type, 3, 2, 1, 0> xzy;
    //        SwizzleProxy<data_type, traits::vector3_type, 3, 2, 0, 1> zxy;
    //        SwizzleProxy<data_type, traits::vector3_type, 3, 2, 1, 0> zyx;
    //
    //        //Color space components//
    //        nthComponent<data_type, length, 0> r;
    //        nthComponent<data_type, length, 1> g;
    //        nthComponent<data_type, length, 2> b;
    //
    //        SwizzleProxy<data_type, traits::vector2_type, 2, 0, 1> rg;
    //        SwizzleProxy<data_type, traits::vector2_type, 2, 1, 0> gr;
    //        SwizzleProxy<data_type, traits::vector2_type, 2, 0, 2> rb;
    //        SwizzleProxy<data_type, traits::vector2_type, 2, 2, 0> br;
    //        SwizzleProxy<data_type, traits::vector2_type, 2, 1, 2> gb;
    //        SwizzleProxy<data_type, traits::vector2_type, 2, 2, 1> bg;
    //
    //        SwizzleProxy<data_type, traits::vector3_type, 3, 0, 1, 2> rgb;
    //        SwizzleProxy<data_type, traits::vector3_type, 3, 1, 0, 2> grb;
    //        SwizzleProxy<data_type, traits::vector3_type, 3, 1, 2, 0> gbr;
    //        SwizzleProxy<data_type, traits::vector3_type, 3, 2, 1, 0> rbg;
    //        SwizzleProxy<data_type, traits::vector3_type, 3, 2, 0, 1> brg;
    //        SwizzleProxy<data_type, traits::vector3_type, 3, 2, 1, 0> bgr;
    //    };
    //};


    template<typename T> using vector2 = vector<2, T>;
    template<typename T> using vector3 = vector<3, T>;
    template<typename T> using vector4 = vector<4, T>;

}

#endif //_SQM_SWIZZLING_VECTOR_