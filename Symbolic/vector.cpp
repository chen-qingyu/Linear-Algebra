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
Vector::Vector(const vector<Fraction>& reals)
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

Vector& Vector::append(const Real& r)
{
    reals.push_back(r);
    size += 1;
    return *this;
}

// TODO
Vector& Vector::append(const vector<Real>& reals)
{
    this->reals.insert(this->reals.end(), reals.begin(), reals.end());
    size += reals.size();
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
 * Vector == != Vector
 */

bool Vector::operator==(const Vector& v) const
{
    return reals == v.reals;
}

bool Vector::operator!=(const Vector& v) const
{
    return !operator==(v);
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
 * Vector + - Vector
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

/*
 * dot product
 */

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
 * scalar multiplication
 */

Vector Vector::operator*(const Real& r) const
{
    if (size == 0)
    {
        throw std::runtime_error("Error: The vector is empty.");
    }

    Vector result = Vector(*this);
    for (size_t i = 0; i < size; ++i)
    {
        result.reals[i] = result.reals[i] * r;
    }
    return result;
}

// TODO
Vector Vector::operator/(const Real& r) const
{
    if (size == 0)
    {
        throw std::runtime_error("Error: The vector is empty.");
    }

    Real rr = r;
    rr.poly.front().power *= -1;
    return operator*(rr);
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

Vector& Vector::unitize()
{
    if (size == 0)
    {
        throw std::runtime_error("Error: The vector is empty.");
    }

    (*this) = (*this) / length();
    return *this;
}

/*******************
 * friend function
 *******************/

/*
 * std::cout << Vector
 */

std::ostream& operator<<(std::ostream& os, const Vector& v)
{
    return os << v.toString();
}

/*
 * scalar multiplication
 */

Vector operator*(const Real& r, const Vector& v)
{
    return v * r;
}
