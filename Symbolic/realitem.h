/******************************************
 * FileName: realitem.h
 * Brief: 能够精确运算和表示的实数项
 * Author: 青羽
 * Blog: https://chen-qingyu.github.io/
 * CreateDate: 2021.01.16
 ******************************************/

#ifndef REALITEM_H
#define REALITEM_H

#include <string>

#include "fraction.h"

using std::string;

class RealItem
{
private:
    // RealItem = coef * (integer^power)
    Fraction coef;  // 系数 coefficient
    int integer;    // 整数 integer
    Fraction power; // 幂次 power

    void simplify();

public:
    /*
     * constructor
     */
    RealItem(const Fraction& coef = 0, int integer = 1, const Fraction& power = 0);

    /*
     * RealItem (op) RealItem
     */
    const RealItem operator+(const RealItem& ri) const;
    const RealItem operator-(const RealItem& ri) const;
    const RealItem operator*(const RealItem& ri) const;
    const RealItem operator/(const RealItem& ri) const;

    /*
     * RealItem (cmp) RealItem
     */
    bool operator==(const RealItem& ri) const;
    bool operator!=(const RealItem& ri) const;
    bool operator>(const RealItem& ri) const;
    bool operator<(const RealItem& ri) const;
    bool operator>=(const RealItem& ri) const;
    bool operator<=(const RealItem& ri) const;

    /*
     * RealItem (op)= RealItem
     */
    RealItem operator+=(const RealItem& ri);
    RealItem operator-=(const RealItem& ri);
    RealItem operator*=(const RealItem& ri);
    RealItem operator/=(const RealItem& ri);

    /*
     * RealItem (op) int
     */
    const RealItem operator+(int n) const;
    const RealItem operator-(int n) const;
    const RealItem operator*(int n) const;
    const RealItem operator/(int n) const;

    /*
     * RealItem (cmp) int
     */
    bool operator==(int n) const;
    bool operator!=(int n) const;
    bool operator>(int n) const;
    bool operator<(int n) const;
    bool operator>=(int n) const;
    bool operator<=(int n) const;

    /*
     * RealItem (op)= int
     */
    RealItem operator+=(int n);
    RealItem operator-=(int n);
    RealItem operator*=(int n);
    RealItem operator/=(int n);

    /*
     * (op) RealItem
     */
    const RealItem operator-() const;
    RealItem& operator++();
    RealItem& operator--();
    const RealItem operator++(int);
    const RealItem operator--(int);

    /*
     * type conversion
     */
    operator double() const;
    operator string() const;

    /*******************
     * friend function
     *******************/

    /*
     * std::cout << RealItem
     */
    friend std::ostream& operator<<(std::ostream& os, const RealItem& ri);

    /*
     * int (op) RealItem
     */
    friend const RealItem operator+(int n, const RealItem& ri);
    friend const RealItem operator-(int n, const RealItem& ri);
    friend const RealItem operator*(int n, const RealItem& ri);
    friend const RealItem operator/(int n, const RealItem& ri);

    /*
     * int (cmp) RealItem
     */
    friend bool operator==(int n, const RealItem& ri);
    friend bool operator!=(int n, const RealItem& ri);
    friend bool operator>(int n, const RealItem& ri);
    friend bool operator<(int n, const RealItem& ri);
    friend bool operator>=(int n, const RealItem& ri);
    friend bool operator<=(int n, const RealItem& ri);
};

#endif // REALITEM_H
