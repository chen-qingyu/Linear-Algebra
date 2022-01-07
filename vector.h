/******************************************
 * File: vector.h
 * Author: 青羽
 * Blog: https://chen-qingyu.github.io/
 * Date: 2022.01.06
 ******************************************/

#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <string>
#include <vector>

#include "fraction.h"

using std::vector;

class Vector
{
private:
    vector<Fraction> elements;

public:
    using size_t = vector<Fraction>::size_type;

    size_t size;

    Vector();
    Vector(vector<Fraction> elements);

    Vector& append(const Fraction& f);
    Vector& append(const Vector& v);

    Fraction& operator[](size_t idx);
    bool operator==(const Vector& v) const;

    std::string toString() const;

    // Vector + - Vector -> Vector
    Vector operator+(const Vector& v) const;
    Vector operator-(const Vector& v) const;

    // dot product
    // Vector * Vector -> Fraction
    Fraction operator*(const Vector& v) const;

    // scalar multiplication
    // Vector * / Fraction -> Vector
    Vector operator*(const Fraction& f) const;
    Vector operator/(const Fraction& f) const;

    double length() const;

    bool isVerticalTo(const Vector& v) const;
    bool isParallelTo(const Vector& v) const;

    /*
     * friend function
     */

    // std::cout << Fraction
    friend std::ostream& operator<<(std::ostream& os, const Vector& v);

    // Vector * Fraction -> Vector
    // scalar multiplication
    friend Vector operator*(const Fraction& f, const Vector& v);
};

#endif // VECTOR_H
