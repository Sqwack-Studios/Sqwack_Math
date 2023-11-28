#ifndef _SQ_MATH_GEOMETRIC_OPS_HPP_
#define _SQ_MATH_GEOMETRIC_OPS_HPP_

//Intrinsics from https://learn.microsoft.com/en-us/windows/win32/direct3dhlsl

namespace sqm
{
    
    template<size_t size, typename dataType>
    dataType dot(const vectorN<size, dataType>& a, const vectorN<size, dataType>& b);


    template<typename dataType>
    vector3<dataType> crossLH(const vector3<dataType>& a, const vector3<dataType>& b);
    
    template<typename dataType>
    vector3<dataType> crossRH(const vector3<dataType>& a, const vector3<dataType>& b);

    template<size_t size, typename dataType>
    dataType distance(const vectorN<size, dataType>& a, const vectorN<size, dataType>& b);

    template<size_t size, typename dataType>
    dataType length(const vectorN<size, dataType>& a, const vectorN<size, dataType>& b);

    template<size_t size, typename dataType>
    vectorN<size, dataType> normalize(const vectorN<size, dataType>& a);

    template<size_t size, typename dataType>
    vectorN<size, dataType> reflect(const vectorN<size, dataType>& incident, const vectorN<size, dataType>& normal);

    template<size_t size, typename dataType>
    vectorN<size, dataType> refract(const vectorN<size, dataType>& incident, const vectorN<size, dataType>& normal, float IOR);

}


#endif //_SQ_MATH_GEOMETRIC_OPS_HPP_
