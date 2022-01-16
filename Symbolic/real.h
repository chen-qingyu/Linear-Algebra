/******************************************
 * FileName: real.h
 * Brief: 能够精确运算和表示的实数
 * Author: 青羽
 * Blog: https://chen-qingyu.github.io/
 * CreateDate: 2021.01.08
 ******************************************/

#ifndef REAL_H
#define REAL_H

#include <string>
#include <vector>

#include "realitem.h"

using std::string;
using std::vector;

class Real
{
private:
    vector<RealItem> poly; // polynomial of RealItem
    size_t size;

    void simplify();

public:
    using size_t = vector<RealItem>::size_type;

    /*
     * constructor
     */
    Real(RealItem ri = RealItem(0));
    Real(vector<RealItem> poly);

    /*
     * Real (cmp) Real
     */
    bool operator==(const Real& r) const;
    bool operator>(const Real& r) const;
    bool operator<(const Real& r) const;
    bool operator>=(const Real& r) const;
    bool operator<=(const Real& r) const;

    /*
     * Real (cmp) Fraction
     */
    bool operator==(const Fraction& f) const;

    /*
     * Real (cmp) int
     */
    bool operator==(int n) const;

    /*
     * Real (op) Real
     */
    Real operator+(const Real& r) const;
    Real operator-(const Real& r) const;
    Real operator*(const Real& r) const;
    Real operator/(const Real& r) const;

    /*
     * type conversion
     */
    operator double() const;
    string toString() const;

    /*******************
     * friend function
     *******************/

    friend std::ostream& operator<<(std::ostream& os, const Real& r);
};

#endif // REAL_H
