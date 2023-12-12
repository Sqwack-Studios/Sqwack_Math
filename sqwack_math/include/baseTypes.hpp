#ifndef _SQ_MATH_BASE_TYPES_HPP_
#define _SQ_MATH_BASE_TYPES_HPP_

#include <cstdint>
#include "typeTraits.hpp"

//*********************************************************************************************************************************************************************************************//
//            This file implements the base types used as containers, proxy and adaptors to build vector types and matrices                                                                    //
//                                                                                                                                                                                             //
//            - There are two main problems in order to support swizzling and anonymous types:                                                                                                 //
//                                                                                                                                                                                             //
//            a) When swizzling, we don't want to copy everytime we swizzle. Imagine the following situation:                                                                                  //
//                                                                                                                                                                                             //
//                                                                                                                                                                                             //
//               float2 dir { 1.0f, 0.0f };                                                                                                                                                     //
//               float2 opp;                                                                                                                                                                   //
//                                                                                                                                                                                             //
//               opp = dir.xy; // in this case yes, we want to copy.                                                                                                                           //
//                                                                                                                                                                                             //
//               //now, let's change dir                                                                                                                                                       //
//                                                                                                                                                                                             //
//               dir.xy = {0.0f, 0.0f} // now, we access consecutive components by reference.                                                                                                  //
//                                                                                                                                                                                             //
//               ....                                                                                                                                                                          //
//                                                                                                                                                                                             //
//               dir.yx = {0.0f, 0.0f} //wait, what?. This should be illegal, because we created a vector where temp = { dir.y, dir.x}, and rval shouldnt be assignable.                       //
//                                                                                                                                                                                             //
//               So, consecutive swizzling in forward direction (i.e, x, xy, xyz, xyzw) should return references or copies. But unordered swizzling always copies.                             //
//                                                                                                                                                                                             //
//                                                                                                                                                                                             //
//            b) We have to abstract from the mathematical entities that we use to make calculations, from the containers. What I mean is that                                                 //
//            the basic types described in this header file are just container-like classes with some extra functionality like swizzling. They cannot perform                                  //
//            any mathematical operation because those won't be defined here. When these classes are working, another header file will define appropiate                                       //
//            floatN, floatNxM classes that will be able to perform cross, dot products, etc.                                                                                                  //
//                                                                                                                                                                                             //
//           - This is forcing us to build some template class that can actually deduce the type based on some traits. Because we have two types to bear in mind:                              //
//                                                                                                                                                                                             //
//             1) the type that the containers are refered to (i.e, baseVec<myStruct>, the data type they hold)                                                                                //
//             2) and the type that manages the underlying container (i.e, float2 has a float type, and a float2 "supertype" that manages mathematical operations over float container)        //
//                                                                                                                                                                                             //
//          This can easily described using traits.                                                                                                                                            //
//                                                                                                                                                                                             //
//          Based on what has been stated, although is quite verbose, we can define a component type that represents a single element in a array container. Then,                              //
//          we can compose a vector type using unions of components and subvectors or swizzle proxies:                                                                                         //
//                                                                                                                                                                                             //
//                                                                                                                                                                                             //
//                                                                                                                                                                                             //
//                                                                                                                                                                                             //
//                  nVector implemented in terms of nComponent and Swizzle proxy using unions                                                                                                  //
//                             ________________                                                                                                                                                //
//                            |                |                                                                                                                                               //
//                            |                |                                                                                                                                               //
//                            |     nVector    |                                                                                                                                               //
//                            |                |                                                                                                                                               //
//                            |________________|                                                                                                                                               //
//                                     |                                                                                                                                                       //
//                        _____________|_______________                                                                                                                                        //
//                       |                             |                                                                                                                                       //
//                  _____________             _________________                                                                                                                                //
//                 |             |           |                 |                                                                                                                               //
//                 |             |           |                 |                                                                                                                               //
//                 |  nComponent |           |  Swizzle proxy  |                                                                                                                               //
//                 |             |           |                 |                                                                                                                               //
//                 |_____________|           |_________________|                                                                                                                               //
//                                                                                                                                                                                             //
//                                                                                                                                                                                             //
//                                                                                                                                                                                             //
//                                                                                                                                                                                             //
//        Then, a superclass inherits from nVector, which can implement its own functionality. In this case, a math library. This superclass defines                                           //
//        the traits needed for the underlying classes to work.                                                                                                                                //
//                                                                                                                                                                                             //
//                             ________________                                                                                                                                                //
//                            |                |                                                                                                                                               //
//                            |                |    traits::data_type float       (recommended reading: Effective C++, Item 47 "Use traits classes for information about types")                                                                                                             //
//                            |     float2     |    traits::manager_type float2                                                                                                                //
//                            |                |                                                                                                                                               //
//                            |________________|                                                                                                                                               //
//                                                                                                                                                                                             //
//        this enables nComponent and Swizzle proxy to know the data they are saving. Also, it hints swizzle proxy which type it needs to transform during swizzle phase.                      //
//        When some requests a .xy swizzle, it is being requested to the underlying nVector interface, which requests to the proxy. The proxy has to return a type, but not                    //
//        a swizzle proxy type, or a nVector type, it has to return a float2 type. Thats why we need traits.                                                                                   //
//                                                                                                                                                                                             //
//                                                                                                                                                                                             //
//        For matrices I'm not sure what I'm going to do, but I think traits or a policy system can help when using column/row convention                                                      //                           //
//*********************************************************************************************************************************************************************************************//


namespace sqm
{
    
    template<typename dataType, size_t size, size_t index>
    class nthComponent
    {
    public:
        using data_type = dataType;

        data_type data[size];

        //Implicit conversion between component and underlying data type
        operator data_type() const noexcept
        {
            return data[index];
        }

        //Implicit reference conversion between component and underlying data type
        operator data_type&() noexcept
        {
            return data[index];
        }

        //Reference operator that returns not the component, but the underlying data type
        const data_type* operator&() const noexcept
        {
            return &data[index];
        }

        //Reference operator that returns not the component, but the underlying data type
        data_type* operator&() noexcept
        {
            return &data[index];
        }

        nthComponent& operator=(data_type rhs) noexcept
        {
            data[index] = rhs;
            return *this;
        }

        //Assignment of components with the same size and index
        nthComponent& operator=(const nthComponent& rhs) noexcept
        {
            data[index] = rhs.data[index];

            return *this;
        }

        //Assignment of components with different size and index. This allows us to assign components without calling operator data_type()
        template<size_t size, size_t idx>
        nthComponent& operator=(const nthComponent<data_type, size, idx>& rhs) noexcept
        {
            data[index] = rhs.data[idx];

            return *this;
        }

    };

    template<typename dataType, typename mathType, size_t size, size_t ... indices>
    class SwizzleProxy
    {
    public:
        using data_type = dataType;
        using mathematic_type = mathType;

        data_type data[size];
    };
 

    template<size_t length, typename dataType>
    class vector;


    template<typename dataType>
    class vector<2, dataType>
    {
    public:
        using traits = vector_traits<dataType>;
        using data_type = dataType;
        using mathematic_type = traits::vector2_type;

        vector<2, data_type>() = default;
        vector<2, data_type>(const vector<2, data_type>& rhs) = default;
        vector<2, data_type>(data_type _x, data_type _y) { x = _x, y = _y; };
        vector<2, data_type>(data_type all);

        static constexpr size_t length{ 2u };
        union //union that represents: each component of the vector, and each swizzle combination
        {
            nthComponent<data_type, length, 0u> x;
            nthComponent<data_type, length, 1u> y;

            nthComponent<data_type, length, 0u> r;
            nthComponent<data_type, length, 1u> g;

            //Space coords
            SwizzleProxy<data_type, mathematic_type, 2u, 0u, 1u> xy;
            SwizzleProxy<data_type, mathematic_type, 2u, 1u, 0u> yx;

            //Color coords
            SwizzleProxy<data_type, mathematic_type, 2u, 0u, 1u> rg;
            SwizzleProxy<data_type, mathematic_type, 2u, 1u, 0u> gb;
            //Add repetition proxies?

        };
    };

    template<typename dataType>
    class vector<3, dataType>
    {
    public:
        using traits = vector_traits<dataType>;
        using data_type = dataType;
        using mathematic_type = traits::vector3_type;

        static constexpr size_t length{ 3u };


        vector<3, dataType>() = default;
        vector<3, dataType>(const vector<3, dataType>& rhs) = default;
        vector<3, dataType>(data_type _x, data_type _y, data_type _z) { x = _x, y = _y, z = _z; };
        vector<3, dataType>(data_type all);

        union
        {
            //Space coords components//
            nthComponent<data_type, length, 0> x;
            nthComponent<data_type, length, 1> y;
            nthComponent<data_type, length, 2> z;


            SwizzleProxy<data_type, mathematic_type, 2, 0, 1> xy;
            SwizzleProxy<data_type, mathematic_type, 2, 1, 0> yx;
            SwizzleProxy<data_type, mathematic_type, 2, 0, 2> xz;
            SwizzleProxy<data_type, mathematic_type, 2, 2, 0> zx;
            SwizzleProxy<data_type, mathematic_type, 2, 1, 2> yz;
            SwizzleProxy<data_type, mathematic_type, 2, 2, 1> zy;

            SwizzleProxy<data_type, mathematic_type, 3, 0, 1, 2> xyz;
            SwizzleProxy<data_type, mathematic_type, 3, 1, 0, 2> yxz;
            SwizzleProxy<data_type, mathematic_type, 3, 1, 2, 0> yzx;
            SwizzleProxy<data_type, mathematic_type, 3, 2, 1, 0> xzy;
            SwizzleProxy<data_type, mathematic_type, 3, 2, 0, 1> zxy;
            SwizzleProxy<data_type, mathematic_type, 3, 2, 1, 0> zyx;

            //Color space components//
            nthComponent<data_type, length, 0> r;
            nthComponent<data_type, length, 1> g;
            nthComponent<data_type, length, 2> b;

            SwizzleProxy<data_type, mathematic_type, 2, 0, 1> rg;
            SwizzleProxy<data_type, mathematic_type, 2, 1, 0> gr;
            SwizzleProxy<data_type, mathematic_type, 2, 0, 2> rb;
            SwizzleProxy<data_type, mathematic_type, 2, 2, 0> br;
            SwizzleProxy<data_type, mathematic_type, 2, 1, 2> gb;
            SwizzleProxy<data_type, mathematic_type, 2, 2, 1> bg;

            SwizzleProxy<data_type, mathematic_type, 3, 0, 1, 2> rgb;
            SwizzleProxy<data_type, mathematic_type, 3, 1, 0, 2> grb;
            SwizzleProxy<data_type, mathematic_type, 3, 1, 2, 0> gbr;
            SwizzleProxy<data_type, mathematic_type, 3, 2, 1, 0> rbg;
            SwizzleProxy<data_type, mathematic_type, 3, 2, 0, 1> brg;
            SwizzleProxy<data_type, mathematic_type, 3, 2, 1, 0> bgr;
        };
    };


    template<typename dataType> using vector2 = vector<2, dataType>;
    template<typename dataType> using vector3 = vector<3, dataType>;
    template<typename dataType> using vector4 = vector<4, dataType>;



}
#endif //_SQ_MATH_BASE_TYPES_HPP_
