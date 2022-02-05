#include <complex>

#include "angle.h"

using namespace ns_angle::ns_literals;

int main(int argc, char *argv[]) {
  auto angle = ns_angle::Angle(78.98_deg);
  std::cout << angle << " = " << angle.radian() << " = " << angle.degree()
            << std::endl;

  angle = ns_angle::Angle(ns_angle::Radian(0.934));
  std::cout << angle << " = " << angle.radian() << " = " << angle.degree()
            << std::endl;

  angle = ns_angle::Angle::make_pangle(12, 13, 14);
  std::cout << angle << " = " << angle.radian() << " = " << angle.degree()
            << std::endl;

  angle = ns_angle::Angle::make_nangle(12, 13, 14);
  std::cout << angle << " = " << angle.radian() << " = " << angle.degree()
            << std::endl;

  angle = ns_angle::Angle(30, 0.0, 0.0);
  std::cout << "sin(" << angle << ") = " << std::sin(angle) << std::endl;

  angle.added(30);
  std::cout << "cos(" << angle << ") = " << std::cos(angle) << std::endl;

  auto angle2 = angle.add(30);
  std::cout << "sin(" << angle2 << ") = " << std::sin(angle2) << std::endl;

  angle2.subed(45);
  std::cout << "cos(" << angle2 << ") = " << std::cos(angle2) << std::endl;

  auto angle3 = angle2.sub(15);
  std::cout << "sin(" << angle3 << ") = " << std::sin(angle3) << std::endl;

  /**
   * @brief output
   * 
   * +78'58'48.0" = 1.378(rad) = 78.980(deg)
   * +53'30'51.3" = 0.934(rad) = 53.514(deg)
   * +12'13'14.0" = 0.213(rad) = 12.221(deg)
   * -12'13'14.0" = -0.213(rad) = -12.221(deg)
   * sin(+30'0'0.0") = 0.5
   * cos(+60'0'0.0") = 0.5
   * sin(+90'0'0.0") = 1
   * cos(+45'0'0.0") = 0.707107
   * sin(+30'0'0.0") = 0.5
   */
  return 0;
}
