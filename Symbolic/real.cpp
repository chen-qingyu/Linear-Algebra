/******************************************
 * FileName: real.cpp
 * Brief: 能够精确运算和表示的实数
 * Author: 青羽
 * Blog: https://chen-qingyu.github.io/
 * CreateDate: 2021.01.08
 ******************************************/

#include <algorithm>
#include <cmath>
#include <map>

#include "real.h"

/********************
 * private function
 ********************/

// TODO
void Real::simplify()
{
    zeroAdjust();

    // case 1: single item
    if (poly.size() == 1)
    {
        return;
    }

    // case 2: sort
    std::sort(poly.begin(), poly.end());
}

/********************
 * public function
 ********************/

/*
 * constructor
 */

Real::Real(const RealItem& ri)
{
    this->poly = {ri};

    simplify();
}

Real::Real(const vector<RealItem>& poly)
{
    if (poly.size() == 0)
    {
        throw std::runtime_error("Error: The vector of RealItem is empty");
    }

    this->poly = poly;

    simplify();
}

/*
 * Real (op) Real
 */

Real Real::operator+(const Real& r) const
{
    return Real(poly.front() + r.poly.front());

    // TODO
}

Real Real::operator-(const Real& r) const
{
    return Real(poly.front() - r.poly.front());

    // TODO
}

Real Real::operator*(const Real& r) const
{
    return Real(poly.front() * r.poly.front());

    // TODO
}

Real Real::operator/(const Real& r) const
{
    return Real(poly.front() / r.poly.front());

    // TODO
}

/*
 * Real (cmp) Real
 */

bool Real::operator==(const Real& r) const
{
    size_t size = poly.size();
    for (size_t i = 0; i < size; ++i)
    {
        if ((*this).poly[i] != r.poly[i])
        {
            return false;
        }
    }
    return true;
}

bool Real::operator!=(const Real& r) const
{
    return !operator==(r);
}

bool Real::operator>(const Real& r) const
{
    return gt(operator double(), (double)r);
}

bool Real::operator<(const Real& r) const
{
    return lt(operator double(), (double)r);
}

bool Real::operator>=(const Real& r) const
{
    return operator>(r) || operator==(r);
}

bool Real::operator<=(const Real& r) const
{
    return operator<(r) || operator==(r);
}

/*
 * Real (op)= Real
 */

/*
 * Real (op) int
 */

/*
 * Real (cmp) int
 */

bool Real::operator==(int n) const
{
    return operator==(Real(RealItem(n)));
}

/*
 * Real (op)= int
 */

/*
 * type conversion
 */

Real::operator double() const
{
    double result = 0;
    for (const auto& item : poly)
    {
        result += (double)item;
    }
    return result;
}

string Real::toString() const
{
    string str = "";
    for (const auto& item : poly)
    {
        str += item.toString();
        str += " + ";
    }
    if (str != "")
    {
        str.erase(str.end() - 3, str.end());
    }
    return str;
}

/*
 * othors
 */

Real& Real::zeroAdjust()
{
    for (auto& ri : poly)
    {
        if (eq(ri, 0))
        {
            ri = RealItem(0);
        }
    }
    return *this;
}

/*******************
 * friend function
 *******************/

/*
 * std::cout << Real
 */

std::ostream& operator<<(std::ostream& os, const Real& r)
{
    return os << r.toString();
}

/*
 * int (op) Real
 */

/*
 * int (cmp) Real
 */
