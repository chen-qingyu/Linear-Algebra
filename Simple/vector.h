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

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

class Vector
{
private:
    vector<double> doubles; // 每个元素都是双精度浮点数

public:
    using size_t = vector<double>::size_type;

    size_t size; // 元素个数

    /*
     * constructor
     */
    Vector();
    Vector(vector<double> doubles);

    /*
     * append element
     */
    Vector& append(const double& d);
    Vector& append(const Vector& v);

    /*
     * Vector[]
     */
    double& operator[](size_t idx);

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
    // Vector * Vector -> double
    double operator*(const Vector& v) const;

    /*
     * Vector (op) double
     */
    // scalar multiplication
    // Vector * / double -> Vector
    Vector operator*(const double& d) const;
    Vector operator/(const double& d) const;

    /*
     * othors
     */
    double length() const;
    bool isVerticalTo(const Vector& v) const;
    bool isParallelTo(const Vector& v) const;
    Vector unitization() const;

    /*******************
     * friend function
     *******************/

    /*
     * std::cout << Vector
     */
    friend std::ostream& operator<<(std::ostream& os, const Vector& v);

    // double * Vector -> Vector
    // scalar multiplication
    friend Vector operator*(const double& d, const Vector& v);
};

#endif // VECTOR_H
