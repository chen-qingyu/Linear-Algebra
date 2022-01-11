/******************************************
 * FileName: vector.cpp
 * Brief: 向量
 * Author: 青羽
 * Blog: https://chen-qingyu.github.io/
 * CreateDate: 2022.01.11
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
    this->doubles = {};
    this->size = 0;
}

Vector::Vector(vector<double> doubles)
{
    this->doubles = doubles;
    this->size = doubles.size();
}

/*
 * append element
 */

Vector& Vector::append(const double& d)
{
    doubles.push_back(d);
    size += 1;
    return *this;
}

Vector& Vector::append(const Vector& v)
{
    doubles.insert(doubles.end(), v.doubles.begin(), v.doubles.end());
    size += v.size;
    return *this;
}

/*
 * Vector[]
 */

double& Vector::operator[](size_t idx)
{
    return doubles[idx];
}

/*
 * Vector (cmp) Vector
 */

bool Vector::operator==(const Vector& v) const
{
    return doubles == v.doubles;
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
        for (const auto& d : doubles)
        {
            str += std::to_string(d) + " ";
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
        result.doubles[i] += v.doubles[i];
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
        result.doubles[i] -= v.doubles[i];
    }
    return result;
}

double Vector::operator*(const Vector& v) const
{
    if (size != v.size)
    {
        throw std::runtime_error("Error: Multiply two vectors of different lengths.");
    }
    if (size == 0)
    {
        throw std::runtime_error("Error: The vectors are empty.");
    }

    double result = 0;
    for (size_t i = 0; i < size; ++i)
    {
        result += doubles[i] * v.doubles[i];
    }
    return result;
}

/*
 * Vector (op) double
 */

Vector Vector::operator*(const double& d) const
{
    if (size == 0)
    {
        throw std::runtime_error("Error: The vector is empty.");
    }

    Vector result = Vector(*this);
    for (size_t i = 0; i < size; ++i)
    {
        result.doubles[i] *= d;
    }
    return result;
}

Vector Vector::operator/(const double& d) const
{
    if (size == 0)
    {
        throw std::runtime_error("Error: The vector is empty.");
    }

    Vector result = Vector(*this);
    for (size_t i = 0; i < size; ++i)
    {
        result.doubles[i] /= d;
    }
    return result;
}

/*
 * othors
 */

double Vector::length() const
{
    if (size == 0)
    {
        throw std::runtime_error("Error: The vector is empty.");
    }

    double result = 0;
    for (size_t i = 0; i < size; ++i)
    {
        result += doubles[i] * doubles[i];
    }

    return std::sqrt(result);
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

    return (*this) * v == 0;
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

    return std::abs((*this) * v) == length() * v.length();
}

/*******************
 * inline function
 *******************/

// EQual
inline bool eq(double a, double b)
{
    return std::abs(a - b) < DBL_EPSILON;
}

// Not Equal
inline bool ne(double a, double b)
{
    return !eq(a, b);
}

// Greater Than
inline bool gt(double a, double b)
{
    return a - b > DBL_EPSILON;
}

// Less Than
inline bool lt(double a, double b)
{
    return a - b < DBL_EPSILON;
}

// Greater than or Equal
inline bool ge(double a, double b)
{
    return gt(a, b) || eq(a, b);
}

// Less than or Equal
inline bool le(double a, double b)
{
    return lt(a, b) || eq(a, b);
}
