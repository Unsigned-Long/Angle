#pragma once

/**
 * @file angle.h
 * @author csl (3079625093@qq.com)
 * @version 0.1
 * @date 2022-02-05
 *
 * @copyright Copyright (c) 2022
 */

#include <cmath>
#include <iomanip>
#include <iostream>
#include <ratio>
#include <sstream>
#include <tuple>

namespace ns_angle::ns_priv {
/**
 * @brief used to convert the specified angular units
 */
using deg_min = std::ratio<1, 60>;
using min_sed = std::ratio<1, 60>;
using deg_sed = std::ratio<1, 3600>;
using min_deg = std::ratio<60, 1>;
using sed_min = std::ratio<60, 1>;
using sed_deg = std::ratio<3600, 1>;

template <typename RatioType>
static long double trans(long double srcVal) {
  return srcVal / (RatioType::num) * (RatioType::den);
}

/**
 * @brief convert the degree to radian
 * @param deg the degree
 * @return long double
 */
static long double degree2Radian(const long double& deg) {
  return deg / 180.0 * M_PI;
}

/**
 * @brief convert the radian to degree
 * @param rad the radian
 * @return long double
 */
static long double radian2Degree(const long double& rad) {
  return rad * 180.0 / M_PI;
}

/**
 * @brief get the integer part and frac part of a value
 * @param val the value
 * @return std::tuple<int, long double>
 */
static std::tuple<int, long double> frac(long double val) {
  int v1 = static_cast<int>(val);
  long double v2 = val - v1;
  return {v1, v2};
}

/**
 * @brief format a value
 * @param val the value
 * @param prec the precision
 * @return std::string
 */
std::string format(long double val, std::size_t prec = 1) {
  std::stringstream stream;
  stream << std::setiosflags(std::ios::fixed) << std::setprecision(prec) << val;
  return stream.str();
}

}  // namespace ns_angle::ns_priv

namespace ns_angle {

/**
 * @brief the degree angle system
 */
struct Degree {
 public:
  long double _deg;

  Degree(long double degree) : _deg(degree) {}
};

/**
 * @brief output the Degree object
 */
std::ostream& operator<<(std::ostream& os, const Degree& degree) {
  os << ns_priv::format(degree._deg, 3) << "(deg)";
  return os;
}

/**
 * @brief the radian angle system
 */
struct Radian {
 public:
  long double _rad;
  Radian(long double radian) : _rad(radian) {}
};

/**
 * @brief output the Radian object
 */
std::ostream& operator<<(std::ostream& os, const Radian& radian) {
  os << ns_priv::format(radian._rad, 3) << "(rad)";
  return os;
}

/**
 * @brief the angle system
 */
class Angle {
 public:
  friend std::ostream& operator<<(std::ostream& os, const Angle& angle);

 private:
  long double _radVal;

 public:
  /**
   * @brief Construct a new Angle object using degree
   */
  Angle(const ns_angle::Degree& deg)
      : _radVal(ns_priv::degree2Radian(deg._deg)) {}

  /**
   * @brief Construct a new Angle object using radian
   */
  Angle(const ns_angle::Radian& rad) : _radVal(rad._rad) {}

  /**
   * @brief Construct a new Angle object using d'm's"
   */
  Angle(int deg, int min = 0, long double sed = 0.0) {
    auto val = deg + ns_priv::trans<ns_priv::min_deg>(min) +
               ns_priv::trans<ns_priv::sed_deg>(sed);
    this->_radVal = ns_priv::degree2Radian(val);
  }

  /**
   * @brief get the radian
   */
  inline Radian radian() const { return Radian(this->_radVal); }

  /**
   * @brief get the degree
   */
  inline Degree degree() const {
    return Degree(ns_priv::radian2Degree(this->_radVal));
  }

  /**
   * @brief used to convert the angle to long double [static_cast]
   */
  inline operator long double() { return this->_radVal; }

  /**
   * @brief Self increasing
   */
  Angle& added(const ns_angle::Degree& deg) {
    this->_radVal += ns_priv::degree2Radian(deg._deg);
    return *this;
  }
  /**
   * @brief Self increasing
   */
  Angle& added(const ns_angle::Radian& rad) {
    this->_radVal += rad._rad;
    return *this;
  }
  /**
   * @brief Self increasing
   */
  Angle& added(int deg, int min = 0, long double sed = 0.0) {
    this->_radVal += Angle(deg, min, sed).radian()._rad;
    return *this;
  }

  /**
   * @brief retuen increasd object based on self
   */
  Angle add(const ns_angle::Degree& deg) const {
    auto copy = *this;
    copy.added(deg);
    return copy;
  }
  /**
   * @brief retuen increasd object based on self
   */
  Angle add(const ns_angle::Radian& rad) const {
    auto copy = *this;
    copy.added(rad);
    return copy;
  }
  /**
   * @brief retuen increasd object based on self
   */
  Angle add(int deg, int min = 0, long double sed = 0.0) const {
    auto copy = *this;
    copy.added(deg, min, sed);
    return copy;
  }

  /**
   * @brief Self decreasing
   */
  Angle& subed(const ns_angle::Degree& deg) {
    this->_radVal -= ns_priv::degree2Radian(deg._deg);
    return *this;
  }
  /**
   * @brief Self decreasing
   */
  Angle& subed(const ns_angle::Radian& rad) {
    this->_radVal -= rad._rad;
    return *this;
  }
  /**
   * @brief Self decreasing
   */
  Angle& subed(int deg, int min = 0, long double sed = 0.0) {
    this->_radVal -= Angle(deg, min, sed).radian()._rad;
    return *this;
  }

  /**
   * @brief retuen decreasd object based on self
   */
  Angle sub(const ns_angle::Degree& deg) const {
    auto copy = *this;
    copy.subed(deg);
    return copy;
  }
  /**
   * @brief retuen decreasd object based on self
   */
  Angle sub(const ns_angle::Radian& rad) const {
    auto copy = *this;
    copy.subed(rad);
    return copy;
  }
  /**
   * @brief retuen decreasd object based on self
   */
  Angle sub(int deg, int min = 0, long double sed = 0.0) const {
    auto copy = *this;
    copy.subed(deg, min, sed);
    return copy;
  }

  /**
   * @brief split the d'm's"
   * @return std::tuple<int, int, long double>
   */
  std::tuple<int, int, long double> split() const {
    auto deg = ns_priv::radian2Degree(this->_radVal);
    auto [d, _d] = ns_priv::frac(deg);
    auto [m, _m] = ns_priv::frac(ns_priv::trans<ns_priv::deg_min>(_d));
    auto s = ns_priv::trans<ns_priv::min_sed>(_m);
    if (std::abs(s - 60.0) < 1E-10)
      s = 0.0, m += 1;
    else if (std::abs(s + 60.0) < 1E-10)
      s = 0.0, m -= 1;

    if (std::abs(m - 60.0) < 1E-10)
      m = 0.0, d += 1;
    else if (std::abs(m + 60.0) < 1E-10)
      m = 0.0, d -= 1;
    return {d, m, s};
  }

 private:
  Angle() = delete;
};

/**
 * @brief output the angle object
 */
std::ostream& operator<<(std::ostream& os, const Angle& angle) {
  auto dms = angle.split();
  os << std::get<0>(dms) << '\'' << std::get<1>(dms) << '\''
     << ns_priv::format(std::get<2>(dms)) << '\"';
  return os;
}

}  // namespace ns_angle

namespace ns_angle::ns_literals {
/**
 * @brief using literal '_deg' to create a Degree object
 * @return ns_angle::Degree
 */
static ns_angle::Degree operator""_deg(long double deg) {
  return ns_angle::Degree(deg);
}

/**
 * @brief using literal '_rad' to create a Radian object
 * @return ns_angle::Radian
 */
static ns_angle::Radian operator""_rad(long double rad) {
  return ns_angle::Radian(rad);
}
}  // namespace ns_angle::ns_literals
