# ___Angle___ Calculation

[TOC]

___Author Info___

___Name___  csl  
___Email___ 3079625093@qq.com

```cpp
                              _|            
  _|_|_|  _|_|_|      _|_|_|  _|    _|_|    
_|    _|  _|    _|  _|    _|  _|  _|_|_|_|  
_|    _|  _|    _|  _|    _|  _|  _|        
  _|_|_|  _|    _|    _|_|_|  _|    _|_|_|  
                          _|                
                      _|_|                 
```

## 1. Using Example

<img src="./docs/code.png" width=80%>

## 2. Main Classes

### 2.1 ___Degree___ class



just used to create angle object

+ ___ns_angle::Degree operator""_deg(long double deg)__

+ ___std::ostream& operator<<(std::ostream& os, const Degree& degree)___
```cpp
/**
 * @brief output the Degree object
 */
```
### 2.2 ___Radian___ class

just used to create angle object

+ ___ns_angle::Radian operator""_rad(long double rad)__

+ ___std::ostream& operator<<(std::ostream& os, const Radian& radian)___
```cpp
/**
 * @brief output the Radian object
 */
```

### 2.3 ___Angle___ class

___Angle___ class is used to calculate angles. The following is an introduction to some important class member functions.  

+ ___Angle(const ns_angle::Degree& deg)___
```cpp
  /**
   * @brief Construct a new Angle object using degree
   */
```
+ ___Angle(const ns_angle::Radian& rad)___
```cpp
  /**
   * @brief Construct a new Angle object using radian
   */
```
+ ___static Angle make_pangle(int deg, int min = 0, long double sed = 0.0)___
```cpp
  /**
   * @brief Construct a new positive Angle object using d'm's"
   *
   * @attention [+30'12'15.0"] equals to make_pangle(30, 12, 15.0)
   */
```
+ ___static Angle make_nangle(int deg, int min = 0, long double sed = 0.0)___
```cpp
  /**
   * @brief Construct a new negative Angle object using d'm's"
   *
   * @attention [-14'24'46.0"] equals to make_nangle(14, 24, 46.0)
   */
```
+ ___static Angle make_rangle(long double radian)___
```cpp
  /**
   * @brief Construct a new Angle object using radian system
   *
   * @param radian the radian value
   * @attention Angle(Radian(12.45)) equals to make_rangle(12.45)
   */
```
+ ___static Angle make_dangle(long double degree)___
```cpp
  /**
   * @brief Construct a new Angle object using degree system
   *
   * @param degree the degree value
   * @attention Angle(Degree(12.45)) equals to make_dangle(12.45)
   */
```
+ ___Radian radian() const___
```cpp
  /**
   * @brief get the radian
   */
```
+ ___Degree degree() const___
```cpp
  /**
   * @brief get the degree
   */
```
+ ___operator long double()___
```cpp
  /**
   * @brief used to convert the angle to long double [static_cast]
   */
```

+ ___inline Angle &operator+=(const ns_angle::Degree &deg)___
+ ___inline Angle &operator+=(const ns_angle::Radian &rad)___
+ ___inline Angle &operator+=(const Angle &angle)___
```cpp
  /**
   * @brief Self increasing
   */
```

+ ___inline Angle operator+(const ns_angle::Degree &deg) const___
+ ___inline Angle operator+(const ns_angle::Radian &rad) const___
+ ___inline Angle operator+(const Angle &angle) const___

```cpp
  /**
   * @brief retuen increasd object based on self
   */
```

+ ___inline Angle &operator-=(const ns_angle::Degree &deg)___

+ ___inline Angle &operator-=(const ns_angle::Radian &rad)___

+ ___inline Angle &operator-=(const Angle &angle)___


```cpp
  /**
   * @brief Self decreasing
   */
```

+ ___inline Angle operator-(const ns_angle::Degree &deg) const___ 
+ ___inline Angle operator-(const ns_angle::Radian &rad) const___
+ ___inline Angle operator-(const Angle &angle) const___

```cpp
  /**
   * @brief retuen decreasd object based on self
   */
```

+ ___inline std::string to_string(std::size_t prec = 1) const___
```cpp
   /**
   * @brief format the angle to d'm's"
   * @return std::string
   */
```

+ ___std::ostream& operator<<(std::ostream& os, const Angle& angle)___
```cpp
/**
 * @brief output the angle object
 */
```

+ ___inline Angle &operator*=(long double factor)___
+ ***inline Angle muled(long double factor) const***

```cpp
// don't overload the operator '*' becase it will cause conflicts during type conversion
```

+ ___inline Angle &operator/=(long double factor)___
+ ***inline Angle dived(long double factor) const***

```cpp
// don't overload the operator '/' becase it will cause conflicts during type conversion
```

