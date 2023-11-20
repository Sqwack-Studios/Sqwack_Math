#ifndef _SQ_MATH_BASE_TYPES_HPP_
#define _SQ_MATH_BASE_TYPES_HPP_

#include <cstdint>

//*********************************************************************************************************************************************************************************************//
//            This file implements the base types used as containers, proxy and adaptors to build vector types and matrices                                                                    //
//                                                                                                                                                                                             //
//            - There are two main problems in order to support swizzling and anonymous types:                                                                                                 //
//                                                                                                                                                                                             //
//            a) When swizzling, we don't want to copy everytime we swizzle. Imagine the following situation:                                                                                  //
//                                                                                                                                                                                             //
//                                                                                                                                                                                             //
//               float2 dir { 1.0f, 0.0f};                                                                                                                                                     //
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


namespace sq::math
{

    template<typename mathType>      // template that will hold information about types
    struct vector_traits
    {
        using mathematic_type = mathType::mathematic_type;  //represents the mathematical construct that manages dataType. i.e, a vector, a matrix that can perform operations
        using data_type = mathType::data_type;
    };

    template<typename traits, size_t size, size_t index>
    class nComponent
    {
    protected:

        using data_type = traits::data_type;

    public:

        data_type data[size];



    };

 






}
#endif //_SQ_MATH_BASE_TYPES_HPP_
