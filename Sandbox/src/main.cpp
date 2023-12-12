#include <sqwack_math/sqwack_math.hpp>


#pragma warning( push )
#pragma warning( disable : 4710)
#pragma warning( disable : 4711 )

#include <iostream>

#pragma warning( pop )
using namespace sqm;

struct whatever {};
int main()
{
    float2 hello2{ 1.5f, 1.0f };
    float2 hello4{ 1.5f, 1.0f };

    float3 hello3{ 2.0f, 5.0f, 2.0f };

    //sqm::crossLH(hello3, hello3);
    //sqm::dot(hello3, hello3);
    

    //constexpr bool has_traits_float_test = has_vector_traits<float>;
    //constexpr bool has_traits_whatever_test = has_vector_traits<whatever>;
    //constexpr bool isSquare = is_square_matrix<float2x3>;

    //hello2.x = hello4.y;

    
    float tt{ hello2.x };
    
    std::cout << tt << "\n" << std::endl;


    //std::cin >> tt;

	return 0;
}