/******************************************
 * FileName: vector.h
 * Brief: 能够精确运算和表示的向量
 * Author: 青羽
 * Blog: https://chen-qingyu.github.io/
 * CreateDate: 2022.01.06
 ******************************************/

#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <string>
#include <vector>

#include "real.h"

using std::string;
using std::vector;

class Vector
{
private:
    vector<Real> reals; // 每个元素都是实数

public:
    using size_t = vector<Real>::size_type;

    size_t size; // 元素个数

    /*
     * constructor
     */
    Vector();
    //    Vector(const vector<Real>& reals);
    Vector(vector<Fraction> reals);

    /*
     * append element
     */
    Vector& append(const Real& f);
    Vector& append(const Vector& v);

    /*
     * Vector[]
     */
    Real& operator[](size_t idx);

    /*
     * Vector (cmp) Vector
     */
    bool operator==(const Vector& v) const;

    /*
     * type conversion
     */
    string toString() const;

    /*
     * Vector (op) Vector
     */
    // Vector + - Vector -> Vector
    Vector operator+(const Vector& v) const;
    Vector operator-(const Vector& v) const;

    // dot product
    // Vector * Vector -> Real
    Real operator*(const Vector& v) const;

    /*
     * Vector (op) Real
     */
    // scalar multiplication
    // Vector * / Real -> Vector
    Vector operator*(const Real& f) const;
    Vector operator/(const Real& f) const;

    /*
     * othors
     */
    Real length() const;
    bool isVerticalTo(const Vector& v) const;
    bool isParallelTo(const Vector& v) const;
    Vector unitization() const;

    /*******************
     * friend function
     *******************/

    /*
     * std::cout << Fraction
     */
    friend std::ostream& operator<<(std::ostream& os, const Vector& v);

    // Real * Vector -> Vector
    // scalar multiplication
    friend Vector operator*(const Real& f, const Vector& v);
};

#endif // VECTOR_H
