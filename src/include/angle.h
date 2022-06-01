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
  static long double degree2Radian(const long double &deg) {
    return deg / 180.0 * M_PI;
  }

  /**
   * @brief convert the radian to degree
   * @param rad the radian
   * @return long double
   */
  static long double radian2Degree(const long double &rad) {
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

} // namespace ns_angle::ns_priv

namespace ns_angle {

  class Angle;

  /**
   * @brief the degree angle system
   */
  struct Degree {
  public:
    long double _deg;

    explicit Degree(long double degree) : _deg(degree) {}

    inline operator long double() const { return ns_priv::degree2Radian(this->_deg); }

    [[nodiscard]] std::string to_string(int precision = 3) const {
      std::stringstream stream;
      stream << std::fixed << std::setprecision(precision);
      stream << (this->_deg < 0.0 ? '-' : '+') << std::abs(this->_deg) << "(deg)";
      return stream.str();
    }
  };

  /**
   * @brief output the Degree object
   */
  static std::ostream &operator<<(std::ostream &os, const Degree &degree) {
    os << degree.to_string();
    return os;
  }

  /**
   * @brief the radian angle system
   */
  struct Radian {
  public:
    long double _rad;

    explicit Radian(long double radian) : _rad(radian) {}

    inline operator long double() const { return this->_rad; }

    [[nodiscard]] std::string to_string(int precision = 3) const {
      std::stringstream stream;
      stream << std::fixed << std::setprecision(precision);
      stream << (this->_rad < 0.0 ? '-' : '+') << std::abs(this->_rad) << "(rad)";
      return stream.str();
    }
  };

  /**
   * @brief output the Radian object
   */
  static std::ostream &operator<<(std::ostream &os, const Radian &radian) {
    os << radian.to_string();
    return os;
  }

  /**
   * @brief the angle system
   */
  class Angle;

  class Angle {

  private:
    long double _radVal;

  public:
    /**
     * @brief Construct a new Angle object using degree
     */
    explicit Angle(const ns_angle::Degree &deg)
        : _radVal(ns_priv::degree2Radian(deg._deg)) {}

    /**
     * @brief Construct a new Angle object using radian
     */
    explicit Angle(const ns_angle::Radian &rad) : _radVal(rad._rad) {}

  protected:
    /**
     * @brief Construct a new Angle object using d'm's"
     *
     * @attention positive angle [+30'12'15.0"] equals to Angle(30, 12, 15.0)
     * @attention negative angle [-14'24'46.0"] equals to Angle(-14, -24, -46.0)
     */
    explicit Angle(int deg, int min = 0, long double sed = 0.0) {
      auto val = deg + ns_priv::trans<ns_priv::min_deg>(min) +
                 ns_priv::trans<ns_priv::sed_deg>(sed);
      this->_radVal = ns_priv::degree2Radian(val);
    }

  public:
    /**
     * @brief Construct a new positive Angle object using d'm's"
     *
     * @attention [+30'12'15.0"] equals to make_pangle(30, 12, 15.0)
     */
    static Angle make_pangle(int deg, int min = 0, long double sed = 0.0) {
      return Angle(deg, min, sed);
    }

    /**
     * @brief Construct a new negative Angle object using d'm's"
     *
     * @attention [-14'24'46.0"] equals to make_nangle(14, 24, 46.0)
     */
    static Angle make_nangle(int deg, int min = 0, long double sed = 0.0) {
      auto angle = Angle(deg, min, sed);
      angle._radVal *= -1;
      return angle;
    }

    /**
     * @brief Construct a new Angle object using radian system
     *
     * @param radian the radian value
     * @attention Angle(Radian(12.45)) equals to make_rangle(12.45)
     */
    static Angle make_rangle(long double radian) { return Angle(Radian(radian)); }

    /**
     * @brief Construct a new Angle object using degree system
     *
     * @param degree the degree value
     * @attention Angle(Degree(12.45)) equals to make_dangle(12.45)
     */
    static Angle make_dangle(long double degree) { return Angle(Degree(degree)); }

    /**
     * @brief get the radian
     */
    [[nodiscard]] inline Radian radian() const {
      return Radian(this->_radVal);
    }

    /**
     * @brief get the degree
     */
    [[nodiscard]] inline Degree degree() const {
      return Degree(ns_priv::radian2Degree(this->_radVal));
    }

    /**
     * @brief used to convert the angle to long double [static_cast]
     */
    inline operator long double() const { return this->_radVal; }

  public:
    /**
     * @brief Self increasing
     */
    inline Angle &operator+=(const ns_angle::Degree &deg) {
      return this->add(deg);
    }
    inline Angle &operator+=(const ns_angle::Radian &rad) {
      return this->add(rad);
    }
    inline Angle &operator+=(const Angle &angle) {
      return this->add(angle);
    }
    /**
     * @brief return increased object based on self
     */
    inline Angle operator+(const ns_angle::Degree &deg) const {
      return this->added(deg);
    }
    inline Angle operator+(const ns_angle::Radian &rad) const {
      return this->added(rad);
    }
    inline Angle operator+(const Angle &angle) const {
      return this->added(angle);
    }

  protected:
    /**
     * @brief Self increasing
     */
    inline Angle &add(const ns_angle::Degree &deg) {
      this->_radVal += ns_priv::degree2Radian(deg._deg);
      return *this;
    }
    /**
     * @brief Self increasing
     */
    inline Angle &add(const ns_angle::Radian &rad) {
      this->_radVal += rad._rad;
      return *this;
    }
    /**
     * @brief Self increasing
     */
    inline Angle &add(const Angle &angle) {
      this->_radVal += angle._radVal;
      return *this;
    }

    /**
     * @brief return increased object based on self
     */
    [[nodiscard]] inline Angle added(const ns_angle::Degree &deg) const {
      auto copy = *this;
      copy.add(deg);
      return copy;
    }
    /**
     * @brief return increased object based on self
     */
    [[nodiscard]] inline Angle added(const ns_angle::Radian &rad) const {
      auto copy = *this;
      copy.add(rad);
      return copy;
    }
    /**
     * @brief return increased object based on self
     */
    [[nodiscard]] inline Angle added(const Angle &angle) const {
      return this->added(angle.radian());
    }

  public:
    /**
     * @brief Self decreasing
     */
    inline Angle &operator-=(const ns_angle::Degree &deg) {
      return this->sub(deg);
    }
    inline Angle &operator-=(const ns_angle::Radian &rad) {
      return this->sub(rad);
    }
    inline Angle &operator-=(const Angle &angle) {
      return this->sub(angle);
    }
    /**
     * @brief return decreased object based on self
     */
    inline Angle operator-(const ns_angle::Degree &deg) const {
      return this->subed(deg);
    }
    inline Angle operator-(const ns_angle::Radian &rad) const {
      return this->subed(rad);
    }
    inline Angle operator-(const Angle &angle) const {
      return this->subed(angle);
    }

  protected:
    /**
     * @brief Self decreasing
     */
    inline Angle &sub(const ns_angle::Degree &deg) {
      this->_radVal -= ns_priv::degree2Radian(deg._deg);
      return *this;
    }
    /**
     * @brief Self decreasing
     */
    inline Angle &sub(const ns_angle::Radian &rad) {
      this->_radVal -= rad._rad;
      return *this;
    }
    /**
     * @brief Self decreasing
     */
    inline Angle &sub(const Angle &angle) {
      this->_radVal -= angle._radVal;
      return *this;
    }

    /**
     * @brief return decreased object based on self
     */
    [[nodiscard]] inline Angle subed(const ns_angle::Degree &deg) const {
      auto copy = *this;
      copy.sub(deg);
      return copy;
    }
    /**
     * @brief return decreased object based on self
     */
    [[nodiscard]] inline Angle subed(const ns_angle::Radian &rad) const {
      auto copy = *this;
      copy.sub(rad);
      return copy;
    }
    /**
     * @brief return decreased object based on self
     */
    [[nodiscard]] inline Angle subed(const Angle &angle) const {
      return this->subed(angle.radian());
    }

  public:
    inline Angle &operator*=(long double factor) {
      return this->mul(factor);
    }
    // don't overload the operator '*' becase it will cause conflicts during type conversion
    inline Angle muled(long double factor) const {
      auto copy = *this;
      copy.mul(factor);
      return copy;
    }

  protected:
    inline Angle &mul(long double factor) {
      this->_radVal *= factor;
      return *this;
    }

  public:
    inline Angle &operator/=(long double factor) {
      return this->div(factor);
    }
    // don't overload the operator '/' becase it will cause conflicts during type conversion
    inline Angle dived(long double factor) const {
      auto copy = *this;
      copy.div(factor);
      return copy;
    }

  protected:
    inline Angle &div(long double factor) {
      this->_radVal /= factor;
      return *this;
    }

  public:
    /**
     * @brief format the angle to d'm's"
     * @return std::string
     */
    [[nodiscard]] inline std::string to_string(int precision = 1) const {
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

      d = std::abs(d);
      m = std::abs(m);
      s = std::abs(s);

      std::stringstream stream;
      stream << std::fixed << std::setprecision(precision);
      stream << (this->_radVal < 0.0 ? '-' : '+');
      stream << std::to_string(d) << '\'';
      stream << std::to_string(m) << '\'';
      stream << s << '\"';
      return stream.str();
    }

  public:
    Angle() = delete;
  };

  /**
   * @brief output the angle object
   */
  static std::ostream &operator<<(std::ostream &os, const Angle &angle) {
    os << angle.to_string();
    return os;
  }

} // namespace ns_angle

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
} // namespace ns_angle::ns_literals
