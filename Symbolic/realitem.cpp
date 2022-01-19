/******************************************
 * FileName: realitem.cpp
 * Brief: 能够精确运算和表示的实数项
 * Author: 青羽
 * Blog: https://chen-qingyu.github.io/
 * CreateDate: 2021.01.16
 ******************************************/

#include <cmath>
#include <map>

#include "realitem.h"

/********************
 * private function
 ********************/

void RealItem::simplify()
{
    // case 1: coef or integer == 0
    if (coef == 0 || integer == 0)
    {
        coef = 0;
        integer = 1;
        power = 0;
    }

    // case 2: integer == 1
    if (integer == 1)
    {
        // coef not change
        // integer not change
        power = 0;
    }

    // case 3: power == 0
    if (power == 0)
    {
        // coef not change
        integer = 1;
        // power not change
    }

    // case 4: |power.num| > 1
    if (std::abs(power.num) > 1)
    {
        // coef not change
        for (int i = 1; i < std::abs(power.num); ++i)
        {
            integer *= integer;
        }
        power.num = (power.num > 0 ? 1 : -1);
        // power.den not change
    }

    // case 5: power.den > 1
    if (power.den > 1)
    {
        std::map<int, int> counter;
        int factor = 2;
        int r = integer;

        // decompose prime factor
        // 8^(1/3) -> fac 2: cnt 3
        // 12^(1/2) -> fac 2: cnt: 2, fac: 3, cnt: 1
        while (r > 1)
        {
            if (r % factor == 0)
            {
                ++counter[factor];
                r /= factor;
            }
            else
            {
                ++factor;
            }
        }

        // 8^(1/3):
        //    coef: 1, integer: 8, power: (1/3)
        // -> coef: 2, integer: 1, power: 0
        // 12^(1/2):
        //    coef: 1, integer: 12, power: 1/2
        // -> coef: 2, integer: 3, power: 1/2
        for (factor = 2; factor < integer; ++factor)
        {
            // √24 -> √(2*2*2*3) -> 2√6
            if (counter[factor] >= power.den)
            {
                int tmp = power.den;
                while (tmp != 0)
                {
                    integer /= factor;
                    --tmp;
                }

                if (power > 0)
                {
                    coef *= factor;
                }
                else if (power < 0)
                {
                    coef /= factor;
                }
            }
        }
        if (integer == 1)
        {
            power = 0;
        }
    }
}

/*******************
 * public function
 *******************/

/*
 * constructor
 */

RealItem::RealItem(const Fraction& coef, int integer, const Fraction& power)
{
    this->coef = coef;
    this->integer = integer;
    this->power = power;

    simplify();
}

/*
 * RealItem (op) RealItem
 */

RealItem RealItem::operator+(const RealItem& ri) const
{
    if (integer != ri.integer || power != ri.power)
    {
        throw std::runtime_error("Error: Invalid operation of RealItem.");
    }

    return RealItem(coef + ri.coef, integer, power);
}

RealItem RealItem::operator-(const RealItem& ri) const
{
    if (integer != ri.integer || power != ri.power)
    {
        throw std::runtime_error("Error: Invalid operation of RealItem.");
    }

    return RealItem(coef - ri.coef, integer, power);
}

RealItem RealItem::operator*(const RealItem& ri) const
{
    if (power != ri.power)
    {
        throw std::runtime_error("Error: Invalid operation of RealItem.");
    }

    return RealItem(coef * ri.coef, integer * ri.integer, power);
}

RealItem RealItem::operator/(const RealItem& ri) const
{
    if (power != ri.power)
    {
        throw std::runtime_error("Error: Invalid operation of RealItem.");
    }

    return RealItem(coef / (ri.coef * ri.integer), integer * ri.integer, power);
}

/*
 * RealItem (cmp) RealItem
 */

bool RealItem::operator==(const RealItem& ri) const
{
    return coef == ri.coef
           && integer == ri.integer
           && power == ri.power;
}

bool RealItem::operator!=(const RealItem& ri) const
{
    return !operator==(ri);
}

bool RealItem::operator>(const RealItem& ri) const
{
    return gt(operator double(), (double)ri);
}

bool RealItem::operator<(const RealItem& ri) const
{
    return lt(operator double(), (double)ri);
}

bool RealItem::operator>=(const RealItem& ri) const
{
    return operator>(ri) || operator==(ri);
}

bool RealItem::operator<=(const RealItem& ri) const
{
    return operator<(ri) || operator==(ri);
}

/*
 * RealItem (op)= RealItem
 */

RealItem RealItem::operator+=(const RealItem& ri)
{
    *this = *this + ri;
    return *this;
}

RealItem RealItem::operator-=(const RealItem& ri)
{
    *this = *this - ri;
    return *this;
}

RealItem RealItem::operator*=(const RealItem& ri)
{
    *this = *this * ri;
    return *this;
}

RealItem RealItem::operator/=(const RealItem& ri)
{
    *this = *this / ri;
    return *this;
}

/*
 * RealItem (op) int
 */

RealItem RealItem::operator+(int n) const
{
    return operator+(RealItem(n));
}

RealItem RealItem::operator-(int n) const
{
    return operator-(RealItem(n));
}

RealItem RealItem::operator*(int n) const
{
    return operator*(RealItem(n));
}

RealItem RealItem::operator/(int n) const
{
    return operator/(RealItem(n));
}

/*
 * RealItem (cmp) int
 */

bool RealItem::operator==(int n) const
{
    return operator==(RealItem(n));
}

bool RealItem::operator!=(int n) const
{
    return operator!=(RealItem(n));
}

bool RealItem::operator>(int n) const
{
    return operator>(RealItem(n));
}

bool RealItem::operator<(int n) const
{
    return operator<(RealItem(n));
}

bool RealItem::operator>=(int n) const
{
    return operator>=(RealItem(n));
}

bool RealItem::operator<=(int n) const
{
    return operator<=(RealItem(n));
}

/*
 * RealItem (op)= int
 */

RealItem RealItem::operator+=(int n)
{
    *this += RealItem(n);
    return *this;
}

RealItem RealItem::operator-=(int n)
{
    *this -= RealItem(n);
    return *this;
}

RealItem RealItem::operator*=(int n)
{
    *this *= RealItem(n);
    return *this;
}

RealItem RealItem::operator/=(int n)
{
    *this /= RealItem(n);
    return *this;
}

/*
 * (op) RealItem
 */

RealItem RealItem::operator-() const
{
    return (*this) * (-1);
}

RealItem& RealItem::operator++()
{
    *this += 1;
    return *this;
}

RealItem& RealItem::operator--()
{
    *this -= 1;
    return *this;
}

RealItem RealItem::operator++(int)
{
    RealItem tmp = *this;
    *this += 1;
    return tmp;
}

RealItem RealItem::operator--(int)
{
    RealItem tmp = *this;
    *this -= 1;
    return tmp;
}

/*
 * type conversion
 */

RealItem::operator double() const
{
    return (double)coef * (std::pow(integer, (double)power));
}

string RealItem::toString() const
{
    if (coef == 0 || integer == 0)
    {
        return string("0");
    }

    if (integer == 1 || power == 0)
    {
        return coef.toString();
    }

    string str = "";
    if (coef != 1)
    {
        if (coef == -1)
        {
            str += "-";
        }
        else
        {
            str += "(" + coef.toString() + ")*";
        }
    }
    str += std::to_string(integer);
    if (power != 1)
    {
        str += "^(" + power.toString() + ")";
    }

    return str;
}

/*******************
 * friend function
 *******************/

/*
 * std::cout << RealItem
 */

std::ostream& operator<<(std::ostream& os, const RealItem& ri)
{
    return os << ri.toString();
}

/*
 * int (op) RealItem
 */

RealItem operator+(int n, const RealItem& ri)
{
    return RealItem(n) + ri;
}

RealItem operator-(int n, const RealItem& ri)
{
    return RealItem(n) - ri;
}

RealItem operator*(int n, const RealItem& ri)
{
    return RealItem(n) * ri;
}

RealItem operator/(int n, const RealItem& ri)
{
    return RealItem(n) / ri;
}

/*
 * int (cmp) RealItem
 */

bool operator==(int n, const RealItem& ri)
{
    return RealItem(n) == ri;
}

bool operator!=(int n, const RealItem& ri)
{
    return RealItem(n) != ri;
}

bool operator>(int n, const RealItem& ri)
{
    return RealItem(n) > ri;
}

bool operator<(int n, const RealItem& ri)
{
    return RealItem(n) < ri;
}

bool operator>=(int n, const RealItem& ri)
{
    return RealItem(n) >= ri;
}

bool operator<=(int n, const RealItem& ri)
{
    return RealItem(n) <= ri;
}
