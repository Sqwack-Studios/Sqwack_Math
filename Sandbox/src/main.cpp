#include <sqwack_math/sqwack_math.hpp>
#include <iostream>

using namespace sq;

int main()
{
    math::float2 hello2{ 1.5f, 1.0f };
    math::float2 hello4{ 1.5f, 1.0f };

    math::float3 hello3{ 2.0f, 5.0f };

    hello2.x = hello4.y;

    float tt{ hello2.x };
    
    std::cout << tt << "\n" << std::endl;


    std::cin >> tt;

	return 0;
}