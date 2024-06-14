#ifndef _SQ_MATH_GEOMETRIC_OPS_HPP_
#define _SQ_MATH_GEOMETRIC_OPS_HPP_

//Intrinsics from https://learn.microsoft.com/en-us/windows/win32/direct3dhlsl

namespace sqm
{
    //TODO: Implement this.

    template<size_t size, typename T>
    T dot(const vector<size, T>& a, const vector<size, T>& b);


    //template<typename T>
    //vector3<T> crossLH(const vector3<T>& a, const vector3<T>& b);
    //
    //template<typename T>
    //vector3<T> crossRH(const vector3<T>& a, const vector3<T>& b);

    template<size_t size, typename T>
    T distance(const vector<size, T>& a, const vector<size, T>& b);

    template<size_t size, typename T>
    T length(const vector<size, T>& a, const vector<size, T>& b);

    template<size_t size, typename T>
    vector<size, T> normalize(const vector<size, T>& a);

    template<size_t size, typename T>
    vector<size, T> normalize(const vector<size, T>& a, T& outLength);


    template<size_t size, typename T>
    vector<size, T> reflect(const vector<size, T>& incident, const vector<size, T>& normal);

    template<size_t size, typename T>
    vector<size, T> refract(const vector<size, T>& incident, const vector<size, T>& normal, float IOR);

}


#endif //_SQ_MATH_GEOMETRIC_OPS_HPP_
