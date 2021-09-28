#include "angle.hpp"
#include <complex>

int main(int argc, char *argv[])
{
    // using functions in namespace ns_scene
    using ns_scene::operator""_Deg;
    using ns_scene::operator""_Rad;

    // example for class Degree
    ns_scene::Degree degree(10.0f);
    degree += 5.0_Deg;
    degree += 15.0_Deg;
    // output : 30[D]
    std::cout << degree << std::endl;
    // output : +30,0,0.0
    std::cout << ns_scene::toAngleStrExp(degree) << std::endl;
    // output : 0.523599[R]
    std::cout << static_cast<ns_scene::Radian>(degree) << std::endl;
    // output : 0.866025
    std::cout << std::cos(degree) << std::endl;
    // output : 0.5
    std::cout << std::sin(degree) << std::endl;

    // example for class Radian
    ns_scene::Radian radian = 3.14_Rad;
    radian = static_cast<ns_scene::Radian>(degree);
    radian *= 2.0;
    // output : 1.0472[R]
    std::cout << radian << std::endl;
    // output : +60,0,0.0
    std::cout << ns_scene::toAngleStrExp(radian) << std::endl;
    // output : 60[D]
    std::cout << static_cast<ns_scene::Degree>(radian) << std::endl;
    // output : 0.5
    std::cout << std::cos(radian) << std::endl;
    // output : 0.866025
    std::cout << std::sin(radian) << std::endl;

    return 0;
}
