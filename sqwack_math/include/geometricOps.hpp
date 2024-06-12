#ifndef _SQ_MATH_GEOMETRIC_OPS_HPP_
#define _SQ_MATH_GEOMETRIC_OPS_HPP_

//Intrinsics from https://learn.microsoft.com/en-us/windows/win32/direct3dhlsl

namespace sqm
{
    //TODO: Implement this.

    template<size_t size, typename dataType>
    dataType dot(const vector<size, dataType>& a, const vector<size, dataType>& b);


    template<typename dataType>
    vector3<dataType> crossLH(const vector3<dataType>& a, const vector3<dataType>& b);
    
    template<typename dataType>
    vector3<dataType> crossRH(const vector3<dataType>& a, const vector3<dataType>& b);

    template<size_t size, typename dataType>
    dataType distance(const vector<size, dataType>& a, const vector<size, dataType>& b);

    template<size_t size, typename dataType>
    dataType length(const vector<size, dataType>& a, const vector<size, dataType>& b);

    template<size_t size, typename dataType>
    vector<size, dataType> normalize(const vector<size, dataType>& a);

    template<size_t size, typename dataType>
    vector<size, dataType> normalize(const vector<size, dataType>& a, dataType& outLength);


    template<size_t size, typename dataType>
    vector<size, dataType> reflect(const vector<size, dataType>& incident, const vector<size, dataType>& normal);

    template<size_t size, typename dataType>
    vector<size, dataType> refract(const vector<size, dataType>& incident, const vector<size, dataType>& normal, float IOR);

}


#endif //_SQ_MATH_GEOMETRIC_OPS_HPP_
