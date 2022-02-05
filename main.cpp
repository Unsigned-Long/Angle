#include <complex>

#include "angle.h"

using namespace ns_angle::ns_literals;

int main(int argc, char *argv[]) {
  auto angle = ns_angle::Angle(12.43_deg);
  std::cout << angle << " = " << angle.radian() << " = " << angle.degree()
            << std::endl;

  angle = ns_angle::Angle(ns_angle::Radian(-3.13));
  std::cout << angle << " = " << angle.radian() << " = " << angle.degree()
            << std::endl;

  angle = ns_angle::Angle(30, 0, 0.0);
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
   * 12'25'48.0" = 0.217(rad) = 12.430(deg)
   * -179'-20'-8.8" = -3.130(rad) = -179.336(deg)
   * sin(30'0'0.0") = 0.5
   * cos(60'0'0.0") = 0.5
   * sin(90'0'0.0") = 1
   * cos(45'0'0.0") = 0.707107
   * sin(30'0'0.0") = 0.5
   */
  return 0;
}
