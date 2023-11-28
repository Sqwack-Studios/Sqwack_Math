#ifndef _SQ_MATH_GEOMETRIC_OPS_HPP_
#define _SQ_MATH_GEOMETRIC_OPS_HPP_

//Intrinsics from https://learn.microsoft.com/en-us/windows/win32/direct3dhlsl

namespace sqm
{
    
    template<size_t length, typename dataType>
    dataType dot(const vectorN<length, dataType>& a, const vectorN<length, dataType>& b);

}


#endif //_SQ_MATH_GEOMETRIC_OPS_HPP_
