# Classes for <kbd>___Degree___</kbd> and <kbd>___Radian___</kbd> angle calculation
### Author Info
<kbd>___Name___</kbd>  csl  
<kbd>___Email___</kbd> 3079625093@qq.com
## One. Using Example

```cpp
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
```

## Two. Class introduction
### (1) <kbd>___Degree___</kbd> class
<kbd>___Degree___</kbd> class is used to calculate angles based on the Degree System. It contains a wealth of operator overloaded functions, including but not limited to <kbd>___+___</kbd> <kbd>___-___</kbd> <kbd>___+=___</kbd> <kbd>___-=___</kbd>. The following is an introduction to some important class member functions.  

1.1 <kbd>Degree(float degree)</kbd>
```cpp
// the constructor
Degree(float degree) : _degree(degree) {}
```
1.2 <kbd>operator float() const</kbd>
```cpp
// operator overload for type float
// it's used for type transform like std::sin(Degree())
operator float() const;
```
1.3 <kbd>explicit operator Radian() const</kbd>
```cpp
// operator overload for type Radian
// it's used to transform a Degree object to a Radian object
explicit operator Radian() const;
```
1.4 <kbd>Radian toRadian() const</kbd>
```cpp
// it's used in the function explicit operator Radian() const;
Radian toRadian() const;
```
1.5 <kbd>~Degree()</kbd>
```cpp
// deconstructor
~Degree();
```
1.6 <kbd>Degree operator+(const Degree &degree) const</kbd>
```cpp
// operator overload for "+"
Degree operator+(const Degree &degree) const;
```
1.7 <kbd>Degree operator-(const Degree &degree) const</kbd>
```cpp
// operator overload for "-"
Degree operator-(const Degree &degree) const;
```
1.8 <kbd>Degree operator*(float value) const</kbd>
```cpp
// operator overload for "*"
Degree operator*(float value) const;
```
1.9 <kbd>Degree operator/(float value) const</kbd>
```cpp
// operator overload for "/"
Degree operator/(float value) const;
```
1.10 <kbd>other functions</kbd>
```cpp
// other operator overload can be find in the scene header file
// ...
```

### (2) <kbd>___Radian___</kbd> class
<kbd>___Radian___</kbd> class is used to calculate angles based on the Radian System. It contains a wealth of operator overloaded functions, including but not limited to <kbd>___+___</kbd> <kbd>___-___</kbd> <kbd>___+=___</kbd> <kbd>___-=___</kbd>. The following is an introduction to some important class member functions.  

2.1 <kbd>Radian(float radian)</kbd>
```cpp
// the constructor
Radian(float radian) : _radian(radian) {}
```
2.2 <kbd>operator float() const</kbd>
```cpp
// operator overload for type float
// it's used for type transform like std::sin(Degree())
operator float() const;
```
2.3 <kbd>explicit operator Radian() const</kbd>
```cpp
// operator overload for type Degree
// it's used to transform a Radian object to a Degree object
explicit operator Degree() const;
```
2.4 <kbd>Radian toDegree() const</kbd>
```cpp
// it's used in the function explicit operator Degree() const;
Radian toDegree() const;
```
2.5 <kbd>~Radian()</kbd>
```cpp
// deconstructor
~Radian();
```
2.6 <kbd>Radian operator+(const Radian &radian) const</kbd>
```cpp
// operator overload for "+"
Radian operator+(const Radian &radian) const;
```
2.7 <kbd>Radian operator-(const Radian &radian) const</kbd>
```cpp
// operator overload for "-"
Radian operator-(const Radian &radian) const;
```
2.8 <kbd>Radian operator*(float value) const</kbd>
```cpp
// operator overload for "*"
Radian operator*(float value) const;
```
2.9 <kbd>Radian operator/(float value) const</kbd>
```cpp
// operator overload for "/"
Radian operator/(float value) const;
```
2.10 <kbd>other functions</kbd>
```cpp
// other operator overload can be find in the scene header file
// ...
```