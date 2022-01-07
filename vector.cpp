/******************************************
 * File: vector.cpp
 * Author: 青羽
 * Blog: https://chen-qingyu.github.io/
 * Date: 2022.01.06
 ******************************************/

#include <cfloat>
#include <cmath>

#include "vector.h"

/*******************
 * public function
 *******************/

Vector::Vector()
{
    this->elements = {};
    this->size = 0;
}

Vector::Vector(vector<Fraction> elements)
{
    this->elements = elements;
    this->size = elements.size();
}

Vector& Vector::append(const Fraction& f)
{
    elements.push_back(f);
    size += 1;
    return *this;
}

Vector& Vector::append(const Vector& v)
{
    elements.insert(elements.end(), v.elements.begin(), v.elements.end());
    size += v.size;
    return *this;
}

Fraction& Vector::operator[](size_t idx)
{
    return elements[idx];
}

bool Vector::operator==(const Vector& v) const
{
    return elements == v.elements;
}

std::string Vector::toString() const
{
    std::string str = "[";
    if (size == 0)
    {
        str += "]";
    }
    else
    {
        for (const auto& f : elements)
        {
            str += f.toString() + " ";
        }
        str[str.length() - 1] = ']';
    }
    return str;
}

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
        result.elements[i] += v.elements[i];
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
        result.elements[i] -= v.elements[i];
    }
    return result;
}

Fraction Vector::operator*(const Vector& v) const
{
    if (size != v.size)
    {
        throw std::runtime_error("Error: Multiply two vectors of different lengths.");
    }
    if (size == 0)
    {
        throw std::runtime_error("Error: The vectors are empty.");
    }

    Fraction result;
    for (size_t i = 0; i < size; ++i)
    {
        result += elements[i] * v.elements[i];
    }
    return result;
}

Vector Vector::operator*(const Fraction& f) const
{
    if (size == 0)
    {
        throw std::runtime_error("Error: The vector is empty.");
    }

    Vector result = Vector(*this);
    for (size_t i = 0; i < size; ++i)
    {
        result.elements[i] *= f;
    }
    return result;
}

Vector Vector::operator/(const Fraction& f) const
{
    return operator*(Fraction(1, f));
}

double Vector::length() const
{
    if (size == 0)
    {
        throw std::runtime_error("Error: The vector is empty.");
    }

    double result = 0;
    for (size_t i = 0; i < size; ++i)
    {
        result += elements[i] * elements[i];
    }
    return std::sqrt(result);
}

bool Vector::isVerticalTo(const Vector& v) const
{
    if (size != v.size)
    {
        throw std::runtime_error("Error: Multiply two vectors of different lengths.");
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
        throw std::runtime_error("Error: Multiply two vectors of different lengths.");
    }
    if (size == 0)
    {
        throw std::runtime_error("Error: The vectors are empty.");
    }

    // |(*this) * v)| eq |length() * v.length()|
    return std::abs((double)((*this) * v)) - std::abs(length() * v.length()) < DBL_EPSILON;
}

/*******************
 * friend function
 *******************/

std::ostream& operator<<(std::ostream& os, const Vector& v)
{
    return os << v.toString();
}

Vector operator*(const Fraction& f, const Vector& v)
{
    if (v.size == 0)
    {
        throw std::runtime_error("Error: The vector is empty.");
    }

    Vector result = Vector(v);
    for (Vector::size_t i = 0; i < v.size; ++i)
    {
        result.elements[i] *= f;
    }
    return result;
}
