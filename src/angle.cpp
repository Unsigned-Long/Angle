#include "angle.h"

namespace ns_angle
{

#pragma region global
    Radian operator+(const Radian &radian, const Degree &degree)
    {
        return radian.operator+(degree.toRadian());
    }
    Degree operator+(const Degree &degree, const Radian &radian)
    {
        return degree.operator+(radian.toDegree());
    }
    Radian operator-(const Radian &radian, const Degree &degree)
    {
        return radian.operator-(degree.toRadian());
    }
    Degree operator-(const Degree &degree, const Radian &radian)
    {
        return degree.operator-(radian.toDegree());
    }
    Degree operator"" _Deg(long double v) 
    {
        return Degree{static_cast<float>(v)};
    }
    Radian operator"" _Rad(long double v)
    {
        return Radian{static_cast<float>(v)};
    }

    std::string toAngleStrExp(const Degree &degree, std::size_t dec)
    {
        float temp = degree._degree;
        char symbol = temp >= 0.0f ? '+' : (temp = -temp, '-');
        int d = static_cast<int>(temp);
        temp -= d;
        temp *= 60.0f;
        int m = static_cast<int>(temp);
        temp -= m;
        temp *= 60.0f;
        float s = temp;
        std::string exp;
        exp.push_back(symbol);
        exp += std::to_string(d);
        exp.push_back(',');
        exp += std::to_string(m);
        exp.push_back(',');
        auto second = std::to_string(s);
        auto dotIter = std::find(second.cbegin(), second.cend(), '.');
        auto tDec = std::distance(dotIter, --second.cend());
        if (dec == 0)
        {
            for (int i = 0; i != tDec + 1; i++)
            {
                second.pop_back();
            }
        }
        else if (dec <= tDec)
        {
            for (int i = 0; i != tDec - dec; i++)
            {
                second.pop_back();
            }
        }
        else
        {
            second += std::string(dec - tDec, '0');
        }
        exp += second;
        return exp;
    }
    std::string toAngleStrExp(const Radian &radian, std::size_t dec)
    {
        return toAngleStrExp(radian.toDegree(), dec);
    }
#pragma endregion

#pragma region Degree class
    Degree::operator float() const
    {
        return this->toRadian()._radian;
    }
    Degree::operator Radian() const
    {
        return this->toRadian();
    }
    Radian Degree::toRadian() const
    {
        return Radian(this->_degree / 180.0 * PI);
    }
    Degree Degree::operator+(const Degree &degree) const
    {
        return Degree(this->_degree + degree._degree);
    }
    Degree Degree::operator+() const
    {
        return *this;
    }
    Degree Degree::operator-(const Degree &degree) const
    {
        return Degree(this->_degree - degree._degree);
    }
    Degree Degree::operator-() const
    {
        return Degree(-this->_degree);
    }
    Degree Degree::operator*(float value) const
    {
        return Degree(this->_degree * value);
    }
    Degree Degree::operator/(float value) const
    {
        return Degree(this->_degree / value);
    }
    std::ostream &operator<<(std::ostream &os, const Degree &degree)
    {
        os << degree._degree << "[D]";
        return os;
    }
    Degree operator*(float value, const Degree &degree)
    {
        return degree * value;
    }
    Degree operator/(float value, const Degree &degree)
    {
        return Degree(value / degree._degree);
    }
    Degree &Degree::operator+=(const Degree &degree)
    {
        this->_degree += degree._degree;
        return *this;
    }
    Degree &Degree::operator-=(const Degree &degree)
    {
        this->_degree -= degree._degree;
        return *this;
    }
    Degree &Degree::operator+=(const Radian &radian)
    {
        return this->operator+=(radian.toDegree());
    }
    Degree &Degree::operator-=(const Radian &radian)
    {
        return this->operator-=(radian.toDegree());
    }
    Degree &Degree::operator*=(float value)
    {
        this->_degree *= value;
        return *this;
    }
    Degree &Degree::operator/=(float value)
    {
        this->_degree /= value;

        return *this;
    }
#pragma endregion

#pragma region Radian class
    Radian::operator float() const
    {
        return this->_radian;
    }
    Radian::operator Degree() const
    {
        return this->toDegree();
    }
    Degree Radian::toDegree() const
    {
        return Degree(this->_radian * 180.0 / PI);
    }
    Radian Radian::operator+(const Radian &radian) const
    {
        return Radian(this->_radian + radian._radian);
    }
    Radian Radian::operator+() const
    {
        return *this;
    }
    Radian Radian::operator-(const Radian &radian) const
    {
        return Radian(this->_radian - radian._radian);
    }
    Radian Radian::operator-() const
    {
        return Radian(-this->_radian);
    }
    Radian Radian::operator*(float value) const
    {
        return Radian(this->_radian * value);
    }
    Radian Radian::operator/(float value) const
    {
        return Radian(this->_radian / value);
    }
    std::ostream &operator<<(std::ostream &os, const Radian &radian)
    {
        os << radian._radian << "[R]";
        return os;
    }
    Radian operator*(float value, const Radian &radian)
    {
        return radian * value;
    }
    Radian operator/(float value, const Radian &radian)
    {
        return Radian(value / radian._radian);
    }
    Radian &Radian::operator+=(const Radian &radian)
    {
        this->_radian += radian._radian;
        return *this;
    }
    Radian &Radian::operator-=(const Radian &radian)
    {
        this->_radian -= radian._radian;
        return *this;
    }
    Radian &Radian::operator+=(const Degree &degree)
    {
        return this->operator+=(degree.toRadian());
    }
    Radian &Radian::operator-=(const Degree &degree)
    {
        return this->operator-=(degree.toRadian());
    }
    Radian &Radian::operator*=(float value)
    {
        this->_radian *= value;
        return *this;
    }
    Radian &Radian::operator/=(float value)
    {
        this->_radian /= value;
        return *this;
    }
#pragma endregion

} // namespace ns_angle
