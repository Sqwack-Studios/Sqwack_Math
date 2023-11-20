#ifndef _SQ_MATH_FLOAT2_HPP_
#define _SQ_MATH_FLOAT2_HPP_

#include "traits.hpp"

namespace sq::math
{


    class float2 : public nComponent<float2_traits, 2, 0>
    {
    public:
        using traits = float2_traits;


    };
}


#endif //_SQ_MATH_FLOAT2_HPP_