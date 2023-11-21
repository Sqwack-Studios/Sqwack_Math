#pragma once
//  Swizzling refferences: "How to achieve vector swizzling in C++"
//  https://stackoverflow.com/questions/51641131/how-to-achieve-vector-swizzling-in-c
// 
// Eric Lengyel, "Linear Algebra Upgraded": http://terathon.com/gdc18_lengyel.pdf
// 
// I've seen some libraries like https://github.com/gwiazdorrr/CxxSwizzle and it's just so hard to read modern c++
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                                                                //
//     ******This file contains all the work left to do in the math library. It will also contain all the requirements for the library*******     //
//                                                                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                                                                //
//                                                         *** Main Requirements / Design ***                                                     //
//                                                                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                                                                //
//           a) The library must support vector2, vector3, vector4 and matrix types from 2x2 up to 4x4, included non-square sizes                 //
//                                                                                                                                                //
//           b) For now, it will only support float types for computations.                                                                       //
//                                                                                                                                                //
//           c) Vector and matrix types will be renamed following HLSL types: Vector2 -> float2, Vector3 -> float3...                             //
//                                ==                                            Matrix2x2 -> float2x2, Matrix3x3 -> float3x3...                   //
//                                                                                                                                                //
//           d) Containers must be templated so that someone can define their own Vector/Matrix types. This base class will be extremely simple.  //
//                                                                                                                                                //
//             - d.1) Mathematical types will be specialized template definitions containing mathematical functions                               //
//                                                                                                                                                //
//           e) Support for component swizzle                                                                                                     //
//                                                                                                                                                //
//           f) SIMD instructions supported                                                                                                       //
//                                                                                                                                                //
//             - f.1) Provide a SIMD type and expose SIMD operations so that user can concatenate operations over the same type                   //
//               , reducing number of loads/unloads.                                                                                              //
//                                                                                                                                                //
//           g) Support common operations in vector and matrices, as well as some common helper functions in computer graphics, like rotations,   //
//                                                                                                                                                //
//              lookAt matrix generation, handiness...                                                                                            //
//                                                                                                                                                //
//           e) Memory model and math convention is column-major                                                                                  //
//                                                                                                                                                //
//           f) Transform                                                                                                                         //
//                                                                                                                                                //
//                                                                                                                                                //
//                                                                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                                                                //
//                                                        *** Once Main Requirements are met ***                                                  //
//                                                                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//            A.1) Strassen's algorithm                                                                                                           //
//            A.2) Plane                                                                                                                          //
//                                                                                                                                                //
//            b) Sphere                                                                                                                           //
//                                                                                                                                                //
//            c) Triangle                                                                                                                         //
//                                                                                                                                                //
//            d) Cube, AABB...                                                                                                                    //
//                                                                                                                                                //
//            e) Frustum                                                                                                                          //
//                                                                                                                                                //
//            f) Ray                                                                                                                              //
//                                                                                                                                                //
//              - f.1) Ray - Intersection algorithms                                                                                              //
//                                                                                                                                                //
//                                                                                                                                                //
//            g.2) Explore AVX-512 types: provide an interface that takes advantage of SoA. Vector/Matrix operations can be batched               //
//                 in single AVX instructions, for example, an AVX-512 register is 16 float wide.                                                 //
//                 You can compute up to four float4 operations, five float3 operations, and 8 float2 operations in                               //
//                 the same instruction. I think that this can heavily improve computation-extensive algorithms like physics engines              //
//                                                                                                                                                //
//                                                                                                                                                //
//                                                                                                                                                //
//                                                                                                                                                //
//                                                                                                                                                //
//                                                                                                                                                //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////																																			  //















