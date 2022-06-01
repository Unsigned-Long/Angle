#include "angle.h"
#include "artwork/logger/logger.h"

using namespace ns_angle::ns_literals;

int main(int argc, char *argv[]) {
  auto angle = ns_angle::Angle(78.98_deg);
  std::cout << angle << " = " << angle.radian() << " = " << angle.degree()
            << std::endl;

  angle = ns_angle::Angle(0.934_rad);
  std::cout << angle << " = " << angle.radian() << " = " << angle.degree()
            << std::endl;

  angle = ns_angle::Angle::make_pangle(12, 13, 14);
  std::cout << angle << " = " << angle.radian() << " = " << angle.degree()
            << std::endl;

  angle = ns_angle::Angle::make_nangle(12, 13, 14);
  std::cout << angle << " = " << angle.radian() << " = " << angle.degree()
            << std::endl;

  angle = ns_angle::Angle::make_dangle(30.0);
  std::cout << "sin(" << angle << ") = " << std::sin(angle) << std::endl;

  angle += 30.0_deg;
  std::cout << "cos(" << angle << ") = " << std::cos(angle) << std::endl;

  auto angle2 = angle + 30.0_deg;
  std::cout << "sin(" << angle2 << ") = " << std::sin(angle2) << std::endl;

  angle2 -= 45.0_deg;
  std::cout << "cos(" << angle2 << ") = " << std::cos(angle2) << std::endl;

  auto angle3 = angle2 - 15.0_deg;
  std::cout << "sin(" << angle3 << ") = " << std::sin(angle3) << std::endl;

  angle = ns_angle::Angle::make_rangle(M_PI);
  LOG_VAR(angle);
  LOG_VAR((angle *= 2.0));
  LOG_VAR(angle.muled(0.5));
  LOG_VAR((angle /= 3.0));
  LOG_VAR(angle.dived(0.5));
  /**
   * @brief output
   *
   * +78'58'48.0" = +1.378(rad) = +78.980(deg)
   * +53'30'51.3" = +0.934(rad) = +53.514(deg)
   * +12'13'14.0" = +0.213(rad) = +12.221(deg)
   * -12'13'14.0" = -0.213(rad) = -12.221(deg)
   * sin(+30'0'0.0") = 0.5
   * cos(+60'0'0.0") = 0.5
   * sin(+90'0'0.0") = 1
   * cos(+45'0'0.0") = 0.707107
   * sin(+30'0'0.0") = 0.5
   * -- angle: +180'0'0.0"
   * -- (angle *= 2.0): +360'0'0.0"
   * -- angle * 0.5: +180'0'0.0"
   * -- (angle /= 3.0): +120'0'0.0"
   * -- angle / 0.5: +240'0'0.0"
   */
  return 0;
}
