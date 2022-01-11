/******************************************
 * FileName: real.h
 * Brief: 能够精确运算和表示的实数
 * Author: 青羽
 * Blog: https://chen-qingyu.github.io/
 * CreateDate: 2021.01.08
 ******************************************/

#ifndef REAL_H
#define REAL_H

#include <list>
#include <string>

#include "fraction.h"

using std::list;
using std::string;

class Real
{
    friend class RealTest;
    friend class Vector;

private:
    class Item
    {
        friend class RealTest;
        friend class Real;
        friend class Vector;

    private:
        // coef * (rational^power)
        Fraction coef;  // 系数 coefficient
        int rational;   // 有理数 rational number
        Fraction power; // 幂次 power

        void simplify();

    public:
        /*
         * constructor
         */
        Item(Fraction coef = 0, int rational = 1, Fraction power = 0);
        Item(int n);

        /*
         * Item (op) Item
         */
        Item operator+(const Item& i) const;
        Item operator-(const Item& i) const;
        Item operator*(const Item& i) const;
        Item operator/(const Item& i) const;

        /*
         * Item (cmp) Item
         */
        bool operator==(const Item& i) const;
        bool operator>(const Item& i) const;
        bool operator<(const Item& i) const;
        bool operator>=(const Item& i) const;
        bool operator<=(const Item& i) const;

        /*
         * type conversion
         */
        operator double() const;
        string toString() const;

        /*******************
         * friend function
         *******************/

        // for list sort
        friend bool cmp(const Real::Item& first, const Real::Item& second);
    };

    list<Item> poly; // polynomial of Item
    int size;

    void simplify();

public:
    /*
     * constructor
     */
    Real(Item item = Item());
    // TODO
    Real(list<Item> poly);
    Real(Fraction f);
    Real(int n);

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

    friend bool cmp(const Real::Item& first, const Real::Item& second);
    friend std::ostream& operator<<(std::ostream& os, const Real& r);
};

#endif // REAL_H
