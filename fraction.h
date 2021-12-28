/******************************************
 * File: fraction.h
 * Author: 青羽
 * Blog: https://chen-qingyu.github.io/
 * Date: 2021.12.28
 ******************************************/

#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class Fraction
{
    // std::cout << Fraction
    friend std::ostream& operator<<(std::ostream& os, Fraction f);

    // int (op) Fraction
    friend Fraction operator+(int n, Fraction f);
    friend Fraction operator-(int n, Fraction f);
    friend Fraction operator*(int n, Fraction f);
    friend Fraction operator/(int n, Fraction f);

    // int (cmp) Fraction
    friend bool operator==(int n, Fraction f);
    friend bool operator>(int n, Fraction f);
    friend bool operator<(int n, Fraction f);
    friend bool operator>=(int n, Fraction f);
    friend bool operator<=(int n, Fraction f);

public:
    Fraction();
    Fraction(int n);
    Fraction(int num, int den);

    // Fraction (op) Fraction
    Fraction operator+(Fraction f);
    Fraction operator-(Fraction f);
    Fraction operator*(Fraction f);
    Fraction operator/(Fraction f);

    // Fraction (cmp) Fraction
    bool operator==(Fraction f);
    bool operator>(Fraction f);
    bool operator<(Fraction f);
    bool operator>=(Fraction f);
    bool operator<=(Fraction f);

    // Fraction (op) int
    Fraction operator+(int n);
    Fraction operator-(int n);
    Fraction operator*(int n);
    Fraction operator/(int n);

    // Fraction (cmp) int
    bool operator==(int n);
    bool operator>(int n);
    bool operator<(int n);
    bool operator>=(int n);
    bool operator<=(int n);

    double toDouble();
    std::string toString();

private:
    int num; // 分子 Numerator
    int den; // 分母 Denominator

    void simplify();
};

#endif // FRACTION_H
