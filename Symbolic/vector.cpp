/******************************************
 * FileName: vector.cpp
 * Brief: 能够精确运算和表示的向量
 * Author: 青羽
 * Blog: https://chen-qingyu.github.io/
 * CreateDate: 2022.01.06
 ******************************************/

#include <cfloat>
#include <cmath>

#include "vector.h"

/*******************
 * public function
 *******************/

/*
 * constructor
 */

Vector::Vector()
{
    this->reals = {};
    this->size = 0;
}

// TODO
//Vector::Vector(vector<Real> reals)
//{
//    this->reals = reals;
//    this->size = reals.size();
//}

// TODO
Vector::Vector(vector<Fraction> reals)
{
    vector<Real> tmp;
    for (auto& f : reals)
    {
        tmp.push_back(Real::Item(f));
    }
    this->reals = tmp;
    this->size = reals.size();
}

/*
 * append element
 */

Vector& Vector::append(const Real& f)
{
    reals.push_back(f);
    size += 1;
    return *this;
}

Vector& Vector::append(const Vector& v)
{
    reals.insert(reals.end(), v.reals.begin(), v.reals.end());
    size += v.size;
    return *this;
}

/*
 * Vector[]
 */

Real& Vector::operator[](size_t idx)
{
    return reals[idx];
}

/*
 * Vector (cmp) Vector
 */

bool Vector::operator==(const Vector& v) const
{
    return reals == v.reals;
}

/*
 * type conversion
 */

string Vector::toString() const
{
    string str = "[";
    if (size == 0)
    {
        str += "]";
    }
    else
    {
        for (const auto& f : reals)
        {
            str += f.toString() + " ";
        }
        str[str.length() - 1] = ']';
    }
    return str;
}

/*
 * Vector (op) Vector
 */

Vector Vector::operator+(const Vector& v) const
{
    if (size != v.size)
    {
        throw std::runtime_error("Error: Add two vectors of different lengths.");
    }
    if (size == 0)
    {
        throw std::runtime_error("Error: The vectors are empty.");
    }

    Vector result = Vector(*this);
    for (size_t i = 0; i < size; ++i)
    {
        result.reals[i] = result.reals[i] + v.reals[i];
    }
    return result;
}

Vector Vector::operator-(const Vector& v) const
{
    if (size != v.size)
    {
        throw std::runtime_error("Error: Subtract two vectors of different lengths.");
    }
    if (size == 0)
    {
        throw std::runtime_error("Error: The vectors are empty.");
    }

    Vector result = Vector(*this);
    for (size_t i = 0; i < size; ++i)
    {
        result.reals[i] = result.reals[i] - v.reals[i];
    }
    return result;
}

Real Vector::operator*(const Vector& v) const
{
    if (size != v.size)
    {
        throw std::runtime_error("Error: Multiply two vectors of different lengths.");
    }
    if (size == 0)
    {
        throw std::runtime_error("Error: The vectors are empty.");
    }

    Real result;
    for (size_t i = 0; i < size; ++i)
    {
        result = result + reals[i] * v.reals[i];
    }
    return result;
}

/*
 * Vector (op) Real
 */

Vector Vector::operator*(const Real& f) const
{
    if (size == 0)
    {
        throw std::runtime_error("Error: The vector is empty.");
    }

    Vector result = Vector(*this);
    for (size_t i = 0; i < size; ++i)
    {
        result.reals[i] = result.reals[i] * f;
    }
    return result;
}

// TODO
Vector Vector::operator/(const Real& f) const
{
    Real r = f;
    r.poly.front().power *= -1;
    return operator*(r);
}

/*
 * othors
 */

Real Vector::length() const
{
    if (size == 0)
    {
        throw std::runtime_error("Error: The vector is empty.");
    }

    Real result = 0;
    for (size_t i = 0; i < size; ++i)
    {
        result = result + reals[i] * reals[i];
    }

    // TODO

    result.poly.front().power = Fraction(1, 2);
    return result;
}

bool Vector::isVerticalTo(const Vector& v) const
{
    if (size != v.size)
    {
        throw std::runtime_error("Error: Two vectors of different lengths.");
    }
    if (size == 0)
    {
        throw std::runtime_error("Error: The vectors are empty.");
    }

    return (*this) * v == Real(0);
}

bool Vector::isParallelTo(const Vector& v) const
{
    if (size != v.size)
    {
        throw std::runtime_error("Error: Two vectors of different lengths.");
    }
    if (size == 0)
    {
        throw std::runtime_error("Error: The vectors are empty.");
    }

    // |(*this) * v)| eq |length() * v.length()|
    return (*this) * v == length() * v.length()
           || (*this) * v == length() * v.length() * Real(-1);
}

Vector Vector::unitization() const
{
    if (size == 0)
    {
        throw std::runtime_error("Error: The vector is empty.");
    }

    return (*this) / length();
}

/*******************
 * friend function
 *******************/

/*
 * std::cout << Fraction
 */

std::ostream& operator<<(std::ostream& os, const Vector& v)
{
    return os << v.toString();
}

// Real * Vector -> Vector
// scalar multiplication
Vector operator*(const Real& f, const Vector& v)
{
    if (v.size == 0)
    {
        throw std::runtime_error("Error: The vector is empty.");
    }

    Vector result = Vector(v);
    for (Vector::size_t i = 0; i < v.size; ++i)
    {
        result.reals[i] = result.reals[i] * f;
    }
    return result;
}
