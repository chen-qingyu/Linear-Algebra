/******************************************
 * FileName: vector.cpp
 * Brief: 向量
 * Author: 青羽
 * Blog: https://chen-qingyu.github.io/
 * CreateDate: 2022.01.11
 ******************************************/

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

Vector::Vector(const vector<double>& doubles)
{
    this->doubles = doubles;
    this->size = doubles.size();
}

// TODO
//Vector::Vector(size_t n, double element)
//{
//    for (size_t i = 0; i < n; ++i)
//    {
//        this->doubles.push_back(element);
//    }
//    this->size = n;
//}

/*
 * append element
 */

Vector& Vector::append(const double& d)
{
    doubles.push_back(d);
    size += 1;
    return *this;
}

Vector& Vector::append(const vector<double>& ds)
{
    doubles.insert(doubles.end(), ds.begin(), ds.end());
    size += ds.size();
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
    if (idx >= size)
    {
        throw std::runtime_error("Error: Vector index out of bounds.");
    }

    return doubles[idx];
}

double Vector::operator[](size_t idx) const
{
    if (idx >= size)
    {
        throw std::runtime_error("Error: Vector index out of bounds.");
    }

    return doubles[idx];
}

/*
 * Vector == != Vector
 */

bool Vector::operator==(const Vector& v) const
{
    if (size != v.size)
    {
        return false;
    }

    for (size_t i = 0; i < size; ++i)
    {
        if (ne(doubles[i], v.doubles[i]))
        {
            return false;
        }
    }

    return true;
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
        for (const auto& d : doubles)
        {
            str += std::to_string(d) + " ";
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
        throw std::runtime_error("Error: Add two vectors of different size.");
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
        throw std::runtime_error("Error: Subtract two vectors of different size.");
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

/*
 * dot product
 */

double Vector::operator*(const Vector& v) const
{
    if (size != v.size)
    {
        throw std::runtime_error("Error: Multiply two vectors of different size.");
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
 * scalar multiplication
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
        throw std::runtime_error("Error: The vectors are not of equal size.");
    }
    if (size == 0)
    {
        throw std::runtime_error("Error: The vectors are empty.");
    }

    return eq((*this) * v, 0);
}

bool Vector::isParallelTo(const Vector& v) const
{
    if (size != v.size)
    {
        throw std::runtime_error("Error: The vectors are not of equal size.");
    }
    if (size == 0)
    {
        throw std::runtime_error("Error: The vectors are empty.");
    }

    return eq(std::abs((*this) * v), length() * v.length());
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

Vector& Vector::zeroAdjust()
{
    for (auto& d : doubles)
    {
        if (eq(d, 0))
        {
            d = 0;
        }
    }
    return *this;
}

size_t Vector::countLeadingZeros() const
{
    size_t lz = 0;
    for (const auto& d : doubles)
    {
        if (eq(d, 0))
        {
            ++lz;
        }
        else
        {
            break;
        }
    }
    return lz;
}

bool Vector::isZero() const
{
    return countLeadingZeros() == size;
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

Vector operator*(const double& d, const Vector& v)
{
    return v * d;
}
