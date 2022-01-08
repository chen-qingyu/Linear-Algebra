/******************************************
 * FileName: real.cpp
 * Brief: 能够精确运算和表示的实数
 * Author: 青羽
 * Blog: https://chen-qingyu.github.io/
 * CreateDate: 2021.01.08
 ******************************************/

#include <cmath>
#include <map>

#include "real.h"

/********************
 * class Real::Item
 ********************/

/********************
 * private function
 ********************/

void Real::Item::simplify()
{
    // case 1: coef or rational == 0
    if (coef == 0 || rational == 0)
    {
        coef = 0;
        rational = 1;
        power = 0;
    }

    // case 2: rational == 1
    if (rational == 1)
    {
        // coef not change
        // rational not change
        power = 0;
    }

    // case 3: power == 0
    if (power == 0)
    {
        // coef not change
        rational = 1;
        // power not change
    }

    // case 4: |power.num| > 1
    if (std::abs(power.num) > 1)
    {
        // coef not change
        for (int i = 1; i < std::abs(power.num); ++i)
        {
            rational *= rational;
        }
        power.num = (power.num > 0 ? 1 : -1);
        // power.den not change
    }

    // case 5: power.den > 1
    if (power.den > 1)
    {
        std::map<int, int> counter;
        int factor = 2;
        int r = rational;

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
        //    coef: 1, rational: 8, power: (1/3)
        // -> coef: 2, rational: 1, power: 0
        // 12^(1/2):
        //    coef: 1, rational: 12, power: 1/2
        // -> coef: 2, rational: 3, power: 1/2
        for (factor = 2; factor < rational; ++factor)
        {
            // √24 -> √(2*2*2*3) -> 2√6
            if (counter[factor] >= power.den)
            {
                int tmp = power.den;
                while (tmp != 0)
                {
                    rational /= factor;
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
        if (rational == 1)
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

Real::Item::Item(Fraction coef, int rational, Fraction power)
{
    this->coef = coef;
    this->rational = rational;
    this->power = power;

    simplify();
}

Real::Item::Item(int n)
{
    this->coef = Fraction(n);
    this->rational = 1;
    this->power = 0;

    simplify();
}

/*
 * Item (op) Item
 */

Real::Item Real::Item::operator+(const Real::Item& i) const
{
    if (rational == i.rational && power == i.power)
    {
        return Item(coef + i.coef, rational, power);
    }

    // TODO

    return Item();
}

Real::Item Real::Item::operator-(const Real::Item& i) const
{
    if (rational == i.rational && power == i.power)
    {
        return Item(coef - i.coef, rational, power);
    }

    // TODO

    return Item();
}

Real::Item Real::Item::operator*(const Real::Item& i) const
{
    if (power == i.power)
    {
        return Item(coef * i.coef, rational * i.rational, power);
    }

    // TODO

    return Item();
}

Real::Item Real::Item::operator/(const Real::Item& i) const
{
    if (power == i.power)
    {
        return Item(coef / (i.coef * i.rational), rational * i.rational, power);
    }

    // TODO

    return Item();
}

/*
 * Item (cmp) Item
 */

bool Real::Item::operator==(const Real::Item& i) const
{
    return coef == i.coef
           && rational == i.rational
           && power == i.power;
}

bool Real::Item::operator>(const Real::Item& i) const
{
    return operator-(i).operator double() > 0;
}

bool Real::Item::operator<(const Real::Item& i) const
{
    return operator-(i).operator double() < 0;
}

bool Real::Item::operator>=(const Real::Item& i) const
{
    return operator-(i).operator double() > 0 || operator==(i);
}

bool Real::Item::operator<=(const Real::Item& i) const
{
    return operator-(i).operator double() < 0 || operator==(i);
}

/*
 * type conversion
 */

Real::Item::operator double() const
{
    return (double)coef * (std::pow(rational, (double)power));
}

string Real::Item::toString() const
{
    if (coef == 0 || rational == 0)
    {
        return string("0");
    }

    if (rational == 1 || power == 0)
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
    str += std::to_string(rational);
    if (power != 1)
    {
        str += "^(" + power.toString() + ")";
    }

    return str;
}

/*******************
 * friend function
 *******************/

// TODO
// for list sort
bool cmp(const Real::Item& first, const Real::Item& second)
{
    return first.rational > second.rational || first.power > second.power;
}

/********************
 * class Real
 ********************/

/********************
 * private function
 ********************/

// TODO
void Real::simplify()
{
    // step 1: single item
    if (size == 1)
    {
        return;
    }

    // step 2: merge similar terms
    list<Item> tmp;
    while (poly.size() != 0)
    {
        auto head = poly.begin();
        int coef = 0;
        for (auto current = ++poly.begin(); current != poly.end(); ++current)
        {
            if (head->rational == current->rational && head->power == current->power)
            {
                coef += current->coef;
                poly.erase(current);
            }
        }
        coef += head->coef;
        tmp.push_back(Item(coef, head->rational, head->power));
        poly.erase(head);
    }
    poly = tmp;

    // step 3: sort
    poly.sort(cmp);
}

/********************
 * public function
 ********************/

/*
 * constructor
 */

Real::Real(Item item)
{
    this->poly = {item};
    size = 1;
}

// TODO
Real::Real(list<Item> poly)
{
    this->poly = poly;
    size = poly.size();

    simplify();
}

Real::Real(Fraction f)
{
    this->poly = {Item(f)};
    size = 1;
}

Real::Real(int n)
{
    this->poly = {Item(n)};
    size = 1;
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
    return poly.front() == Item(f);
}

/*
 * Real (cmp) int
 */

bool Real::operator==(int n) const
{
    return poly.front() == Item(n);
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
