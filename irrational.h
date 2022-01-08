/******************************************
 * File: irrational.h
 * Author: 青羽
 * Blog: https://chen-qingyu.github.io/
 * Date: 2022.01.08
 ******************************************/

#ifndef IRRATIONAL_H
#define IRRATIONAL_H

#include <list>
#include <string>

#include "fraction.h"

using std::list;
using std::string;

class Irrational
{
    friend class IrrationalTest;
    friend class Fraction;
    friend class Vector;

private:
    class Item
    {
        friend class IrrationalTest;
        friend class Fraction;
        friend class Vector;

    private:
        Fraction coef;  // coefficient
        int rational;   // rational number
        Fraction power; // power

        void simplify();

    public:
        Item(Fraction coef = 0, int rational = 1, Fraction power = 0);
        bool operator==(const Item& item) const;

        friend bool cmp(const Irrational::Item& first, const Irrational::Item& second);
    };

    list<Item> irrational;
    int size;

    //    void simplify();

public:
    Irrational(Item item = Item());
    Irrational(list<Item> irrational);
    Irrational(int n);

    bool operator==(const Irrational& ir) const;

    Irrational operator+(const Irrational& ir) const;
    Irrational operator-(const Irrational& ir) const;
    Irrational operator*(const Irrational& ir) const;
    Irrational operator/(const Irrational& ir) const;

    string toString() const;

    friend bool cmp(const Irrational::Item& first, const Irrational::Item& second);
    friend std::ostream& operator<<(std::ostream& os, const Irrational& ir);
};

#endif // IRRATIONAL_H
