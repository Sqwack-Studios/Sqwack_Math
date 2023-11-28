#include <sqwack_math/sqwack_math.hpp>
#include <iostream>

using namespace sqm;

int main()
{
    float2 hello2{ 1.5f, 1.0f };
    float2 hello4{ 1.5f, 1.0f };

    float3 hello3{ 2.0f, 5.0f };

    
    hello2.x = hello4.y;

    
    float tt{ hello2.x };
    
    std::cout << tt << "\n" << std::endl;


    std::cin >> tt;

	return 0;
}