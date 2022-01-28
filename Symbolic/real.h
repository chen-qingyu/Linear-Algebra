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

    void simplify();

public:
    using size_t = vector<RealItem>::size_type;

    /*
     * constructor
     */
    Real(const RealItem& ri = RealItem(0));
    Real(const vector<RealItem>& poly);

    /*
     * Real (op) Real
     */
    Real operator+(const Real& r) const;
    Real operator-(const Real& r) const;
    Real operator*(const Real& r) const;
    Real operator/(const Real& r) const;
    Real operator%(const Real& r) const;

    /*
     * Real (cmp) Real
     */
    bool operator==(const Real& r) const;
    bool operator!=(const Real& r) const;
    bool operator>(const Real& r) const;
    bool operator<(const Real& r) const;
    bool operator>=(const Real& r) const;
    bool operator<=(const Real& r) const;

    /*
     * Real (op)= Real
     */
    Real& operator+=(const Real& r);
    Real& operator-=(const Real& r);
    Real& operator*=(const Real& r);
    Real& operator/=(const Real& r);

    /*
     * Real (op) int
     */
    Real operator+(int n) const;
    Real operator-(int n) const;
    Real operator*(int n) const;
    Real operator/(int n) const;

    /*
     * Real (cmp) int
     */
    bool operator==(int n) const;
    bool operator!=(int n) const;
    bool operator>(int n) const;
    bool operator<(int n) const;
    bool operator>=(int n) const;
    bool operator<=(int n) const;

    /*
     * Real (op)= int
     */
    Real& operator+=(int n);
    Real& operator-=(int n);
    Real& operator*=(int n);
    Real& operator/=(int n);

    /*
     * type conversion
     */
    operator double() const;
    string toString() const;

    /*
     * othors
     */
    Real& zeroAdjust();

    /*******************
     * friend function
     *******************/

    /*
     * std::cout << Real
     */
    friend std::ostream& operator<<(std::ostream& os, const Real& r);

    /*
     * int (op) Real
     */
    friend Real operator+(int n, const Real& r);
    friend Real operator-(int n, const Real& r);
    friend Real operator*(int n, const Real& r);
    friend Real operator/(int n, const Real& r);

    /*
     * int (cmp) Real
     */
    friend bool operator==(int n, const Real& r);
    friend bool operator!=(int n, const Real& r);
    friend bool operator>(int n, const Real& r);
    friend bool operator<(int n, const Real& r);
    friend bool operator>=(int n, const Real& r);
    friend bool operator<=(int n, const Real& r);
};

#endif // REAL_H
