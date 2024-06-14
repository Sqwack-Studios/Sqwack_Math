#include <sqwack_math/sqwack_math.hpp>
#pragma warning( push )
#pragma warning( disable : 4710)
#pragma warning( disable : 4711 )

#include <iostream>

#pragma warning( pop )

struct vec2f
{
    float x, y;
};



int main()
{
    sqm::float2 pepe{ 1.0f, 5.0f };
    sqm::float2 aaa;

    aaa.xy = pepe.xy;
    volatile float aaaF = aaa.x;


    //sqm::float2 papapaaa{};
    vec2f polla{  3.0f, 1.0f };
    vec2f bbb;
    //papapaaa = pepe;

    bbb = polla;
    volatile float bbbF = bbb.x;
    
    
	return 0;
}