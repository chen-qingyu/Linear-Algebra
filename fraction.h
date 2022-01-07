/******************************************
 * File: fraction.h
 * Author: 青羽
 * Blog: https://chen-qingyu.github.io/
 * Date: 2021.12.28
 ******************************************/

#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <string>

class Fraction
{
private:
    int num; // 分子 Numerator
    int den; // 分母 Denominator

    void simplify();

public:
    Fraction(int num = 0, int den = 1);
    Fraction(int num, Fraction den);
    Fraction(Fraction num, int den);
    Fraction(Fraction num, Fraction den);

    // Fraction (op) Fraction
    Fraction operator+(const Fraction& f) const;
    Fraction operator-(const Fraction& f) const;
    Fraction operator*(const Fraction& f) const;
    Fraction operator/(const Fraction& f) const;

    // Fraction (cmp) Fraction
    bool operator==(const Fraction& f) const;
    bool operator>(const Fraction& f) const;
    bool operator<(const Fraction& f) const;
    bool operator>=(const Fraction& f) const;
    bool operator<=(const Fraction& f) const;

    // Fraction (op)= Fraction
    Fraction operator+=(const Fraction& f);
    Fraction operator-=(const Fraction& f);
    Fraction operator*=(const Fraction& f);
    Fraction operator/=(const Fraction& f);

    // Fraction (op) int
    Fraction operator+(int n) const;
    Fraction operator-(int n) const;
    Fraction operator*(int n) const;
    Fraction operator/(int n) const;

    // Fraction (cmp) int
    bool operator==(int n) const;
    bool operator>(int n) const;
    bool operator<(int n) const;
    bool operator>=(int n) const;
    bool operator<=(int n) const;

    // Fraction (op)= int
    Fraction operator+=(int n);
    Fraction operator-=(int n);
    Fraction operator*=(int n);
    Fraction operator/=(int n);

    // (op) Fraction
    Fraction operator-() const;
    Fraction& operator++();
    Fraction& operator--();
    Fraction operator++(int);
    Fraction operator--(int);

    operator double() const;
    std::string toString() const;

    /*
     * friend function
     */

    // std::cout << Fraction
    friend std::ostream& operator<<(std::ostream& os, const Fraction& f);

    // int (op) Fraction
    friend Fraction operator+(int n, const Fraction& f);
    friend Fraction operator-(int n, const Fraction& f);
    friend Fraction operator*(int n, const Fraction& f);
    friend Fraction operator/(int n, const Fraction& f);

    // int (cmp) Fraction
    friend bool operator==(int n, const Fraction& f);
    friend bool operator>(int n, const Fraction& f);
    friend bool operator<(int n, const Fraction& f);
    friend bool operator>=(int n, const Fraction& f);
    friend bool operator<=(int n, const Fraction& f);
};

#endif // FRACTION_H
