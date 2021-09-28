#include "angle.h"
#include <complex>

int main(int argc, char *argv[])
{
    // using functions in namespace ns_angle
    using ns_angle::operator""_Deg;
    using ns_angle::operator""_Rad;

    // example for class Degree
    ns_angle::Degree degree(10.0f);
    degree += 5.0_Deg;
    degree += 15.0_Deg;
    // output : 30[D]
    std::cout << degree << std::endl;
    // output : +30,0,0.0
    std::cout << ns_angle::toAngleStrExp(degree) << std::endl;
    // output : 0.523599[R]
    std::cout << static_cast<ns_angle::Radian>(degree) << std::endl;
    // output : 0.866025
    std::cout << std::cos(degree) << std::endl;
    // output : 0.5
    std::cout << std::sin(degree) << std::endl;

    // example for class Radian
    ns_angle::Radian radian = 3.14_Rad;
    radian = static_cast<ns_angle::Radian>(degree);
    radian *= 2.0;
    // output : 1.0472[R]
    std::cout << radian << std::endl;
    // output : +60,0,0.0
    std::cout << ns_angle::toAngleStrExp(radian) << std::endl;
    // output : 60[D]
    std::cout << static_cast<ns_angle::Degree>(radian) << std::endl;
    // output : 0.5
    std::cout << std::cos(radian) << std::endl;
    // output : 0.866025
    std::cout << std::sin(radian) << std::endl;

    return 0;
}
