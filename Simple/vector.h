/******************************************
 * FileName: vector.h
 * Brief: 向量
 * Author: 青羽
 * Blog: https://chen-qingyu.github.io/
 * CreateDate: 2022.01.11
 ******************************************/

#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <string>
#include <vector>

#include "double.h"

using std::string;
using std::vector;

class Vector
{
    friend class SquareMatrix;

private:
    vector<double> doubles; // 每个元素都是双精度浮点数

public:
    using size_t = vector<double>::size_type;

    size_t size; // 元素个数

    /*
     * constructor
     */
    Vector();
    Vector(const vector<double>& vd);
    // TODO
    //    Vector(size_t n, double element);
    Vector(vector<double>::const_iterator begin, vector<double>::const_iterator end);

    /*
     * append element
     */
    Vector& append(const double& d);
    Vector& append(const vector<double>& vd);
    Vector& append(const Vector& v);
    Vector& append(vector<double>::const_iterator begin, vector<double>::const_iterator end);

    /*
     * Vector[]
     */
    double& operator[](size_t idx);
    double operator[](size_t idx) const;

    /*
     * Vector == != Vector
     */
    bool operator==(const Vector& v) const;
    bool operator!=(const Vector& v) const;

    /*
     * type conversion
     */
    string toString() const;

    /*
     * Vector + - Vector
     */
    Vector operator+(const Vector& v) const;
    Vector operator-(const Vector& v) const;

    /*
     * dot product
     */
    double operator*(const Vector& v) const;

    /*
     * scalar multiplication
     */
    Vector operator*(const double& d) const;
    Vector operator/(const double& d) const;

    /*
     * othors
     */
    double length() const;
    bool isVerticalTo(const Vector& v) const;
    bool isParallelTo(const Vector& v) const;
    Vector& unitize();
    Vector& zeroAdjust();
    size_t countLeadingZeros() const;
    bool isZero() const;

    /*******************
     * friend function
     *******************/

    /*
     * std::cout << Vector
     */
    friend std::ostream& operator<<(std::ostream& os, const Vector& v);

    /*
     * scalar multiplication
     */
    friend Vector operator*(const double& d, const Vector& v);
};

#endif // VECTOR_H
