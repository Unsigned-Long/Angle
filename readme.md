# <kbd>___Angle___</kbd> Calculation

### Author Info
<kbd>___Name___</kbd>  csl  
<kbd>___Email___</kbd> 3079625093@qq.com

## One. Using Example

```cpp
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
```
## <kbd>___Degree___</kbd> class
just used to create angle object

+ <kbd>ns_angle::Degree operator""_deg(long double deg)</kbd>

+ <kbd>std::ostream& operator<<(std::ostream& os, const Degree& degree)</kbd>
```cpp
/**
 * @brief output the Degree object
 */
```
## <kbd>___Radian___</kbd> class
just used to create angle object

+ <kbd>ns_angle::Radian operator""_rad(long double rad)</kbd>

+ <kbd>std::ostream& operator<<(std::ostream& os, const Radian& radian)</kbd>
```cpp
/**
 * @brief output the Radian object
 */
```

## <kbd>___Angle___</kbd> class
<kbd>___Angle___</kbd> class is used to calculate angles. The following is an introduction to some important class member functions.  

+ <kbd>Angle(const ns_angle::Degree& deg)</kbd>
```cpp
  /**
   * @brief Construct a new Angle object using degree
   */
```
+ <kbd>Angle(const ns_angle::Radian& rad)</kbd>
```cpp
  /**
   * @brief Construct a new Angle object using radian
   */
```
+ <kbd>Angle(int deg, int min = 0, long double sed = 0.0)</kbd>
```cpp
  /**
   * @brief Construct a new Angle object using d'm's"
   *
   * @attention positive angle [+30'12'15.0"] equals to Angle(30, 12, 15.0)
   * @attention negative angle [-14'24'46.0"] equals to Angle(-14, -24, -46.0)
   */
```
+ <kbd>static Angle make_pangle(int deg, int min = 0, long double sed = 0.0)</kbd>
```cpp
  /**
   * @brief Construct a new positive Angle object using d'm's"
   *
   * @attention [+30'12'15.0"] equals to make_pangle(30, 12, 15.0)
   */
```
+ <kbd>static Angle make_nangle(int deg, int min = 0, long double sed = 0.0)</kbd>
```cpp
  /**
   * @brief Construct a new negative Angle object using d'm's"
   *
   * @attention [-14'24'46.0"] equals to make_nangle(14, 24, 46.0)
   */
```
+ <kbd>Radian radian() const</kbd>
```cpp
  /**
   * @brief get the radian
   */
```
+ <kbd>Degree degree() const</kbd>
```cpp
  /**
   * @brief get the degree
   */
```
+ <kbd>operator long double()</kbd>
```cpp
  /**
   * @brief used to convert the angle to long double [static_cast]
   */
```

+ <kbd>Angle& added(const ns_angle::Degree& deg)</kbd>

+ <kbd>Angle& added(const ns_angle::Radian& rad)</kbd>

+ <kbd>Angle& added(int deg, int min = 0, long double sed = 0.0)</kbd>
```cpp
  /**
   * @brief Self increasing
   */
```

+ <kbd>Angle add(const ns_angle::Degree& deg) const</kbd>

+ <kbd>Angle add(const ns_angle::Radian& rad) const</kbd>

+ <kbd>Angle add(int deg, int min = 0, long double sed = 0.0) const</kbd>

```cpp
  /**
   * @brief retuen increasd object based on self
   */
```

+ <kbd>Angle& subed(const ns_angle::Degree& deg)</kbd>

+ <kbd>Angle& subed(const ns_angle::Radian& rad)</kbd>

+ <kbd>Angle& subed(int deg, int min = 0, long double sed = 0.0)</kbd>

```cpp
  /**
   * @brief Self decreasing
   */
```

+ <kbd>Angle sub(const ns_angle::Degree& deg) const</kbd>

+ <kbd>Angle sub(const ns_angle::Radian& rad) const</kbd>

+ <kbd>Angle sub(int deg, int min = 0, long double sed = 0.0) const</kbd>

```cpp
  /**
   * @brief retuen decreasd object based on self
   */
```

+ <kbd>std::tuple<int, int, long double> split() const</kbd>
```cpp
  /**
   * @brief split the d'm's"
   * @return std::tuple<int, int, long double>
   */
```

+ <kbd>std::ostream& operator<<(std::ostream& os, const Angle& angle)</kbd>
```cpp
/**
 * @brief output the angle object
 */
```
