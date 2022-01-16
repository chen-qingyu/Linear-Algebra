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
    // case 1: single item
    if (size == 1)
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

Real::Real(RealItem ri)
{
    this->poly = {ri};
    size = 1;
}

Real::Real(vector<RealItem> poly)
{
    this->poly = poly;
    this->size = poly.size();

    simplify();
}

/*
 * Real (cmp) Real
 */

bool Real::operator==(const Real& r) const
{
    return poly.front() == r.poly.front();

    // TODO
    //    if (size == r.size)
    //    {
    //        auto ap = poly.begin();
    //        auto bp = r.poly.begin();
    //        while (ap != poly.end())
    //        {
    //            if (!((*ap) == (*bp)))
    //            {
    //                return false;
    //            }
    //            ++ap;
    //            ++bp;
    //        }
    //        return true;
    //    }
    //    return false;
}

bool Real::operator>(const Real& r) const
{
    return poly.front() > r.poly.front();

    // TODO
}

bool Real::operator<(const Real& r) const
{
    return poly.front() < r.poly.front();

    // TODO
}

bool Real::operator>=(const Real& r) const
{
    return poly.front() >= r.poly.front();

    // TODO
}

bool Real::operator<=(const Real& r) const
{
    return poly.front() <= r.poly.front();

    // TODO
}

/*
 * Real (cmp) Fraction
 */

bool Real::operator==(const Fraction& f) const
{
    return poly.front() == RealItem(f);
}

/*
 * Real (cmp) int
 */

bool Real::operator==(int n) const
{
    return poly.front() == RealItem(n);
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
    return str.erase(str.size() - 3, str.size());
}

/*******************
 * friend function
 *******************/

std::ostream& operator<<(std::ostream& os, const Real& r)
{
    return os << r.toString();
}
