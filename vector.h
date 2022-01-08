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

#include "irrational.h"

using std::vector;

class Vector
{
private:
    vector<Irrational> elements;

public:
    using size_t = vector<Irrational>::size_type;

    size_t size;

    Vector();
    Vector(vector<Irrational> elements);

    Vector& append(const Irrational& f);
    Vector& append(const Vector& v);

    Irrational& operator[](size_t idx);
    bool operator==(const Vector& v) const;

    std::string toString() const;

    // Vector + - Vector -> Vector
    Vector operator+(const Vector& v) const;
    Vector operator-(const Vector& v) const;

    // dot product
    // Vector * Vector -> Fraction
    Irrational operator*(const Vector& v) const;

    // scalar multiplication
    // Vector * / Fraction -> Vector
    Vector operator*(const Irrational& f) const;
    Vector operator/(const Irrational& f) const;

    double length() const;

    bool isVerticalTo(const Vector& v) const;
    bool isParallelTo(const Vector& v) const;

    Vector unitization() const;

    /*
     * friend function
     */

    // std::cout << Fraction
    friend std::ostream& operator<<(std::ostream& os, const Vector& v);

    // Vector * Fraction -> Vector
    // scalar multiplication
    friend Vector operator*(const Irrational& f, const Vector& v);
};

#endif // VECTOR_H
