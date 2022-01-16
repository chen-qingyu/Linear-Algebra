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
    friend class RealItemTest;

private:
    // RealItem = coef * (rational^power)
    Fraction coef;  // 系数 coefficient
    int rational;   // 有理数 rational number
    Fraction power; // 幂次 power

    void simplify();

public:
    /*
     * constructor
     */
    RealItem(const Fraction& coef = 0, int rational = 1, const Fraction& power = 0);

    /*
     * RealItem (op) RealItem
     */
    RealItem operator+(const RealItem& ri) const;
    RealItem operator-(const RealItem& ri) const;
    RealItem operator*(const RealItem& ri) const;
    RealItem operator/(const RealItem& ri) const;

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
    RealItem operator+(int n) const;
    RealItem operator-(int n) const;
    RealItem operator*(int n) const;
    RealItem operator/(int n) const;

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
    RealItem operator-() const;
    RealItem& operator++();
    RealItem& operator--();
    RealItem operator++(int);
    RealItem operator--(int);

    /*
     * type conversion
     */
    operator double() const;
    string toString() const;

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
    friend RealItem operator+(int n, const RealItem& ri);
    friend RealItem operator-(int n, const RealItem& ri);
    friend RealItem operator*(int n, const RealItem& ri);
    friend RealItem operator/(int n, const RealItem& ri);

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
