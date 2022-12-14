/******************************************
 * FileName: fraction.cpp
 * Brief: 能够精确运算和表示的有理分式
 * Author: 青羽
 * Blog: https://chen-qingyu.github.io/
 * CreateDate: 2021.12.28
 ******************************************/

#include "fraction.h"

/********************
 * private function
 ********************/

void Fraction::simplify()
{
    // 1. 确保分母为正 2/-8 => -2/8
    if (den < 0)
    {
        num = -num;
        den = -den;
    }

    // 2. 约分 -2/8 => -1/4
    // 欧几里得算法求最大公约数
    int a = abs(num);
    int b = abs(den);
    while (b > 0)
    {
        int t = a % b;
        a = b;
        b = t;
    }
    num /= a;
    den /= a;
}

/*******************
 * public function
 *******************/

/*
 * constructor
 */

Fraction::Fraction(int num, int den)
{
    if (den == 0)
    {
        throw std::runtime_error("Error: Zero denominator.");
    }

    this->num = num;
    this->den = den;
    simplify();
}

Fraction::Fraction(int num, const Fraction& den)
{
    if (den == 0)
    {
        throw std::runtime_error("Error: Zero denominator.");
    }

    (*this) = num / den;
    simplify();
}

Fraction::Fraction(const Fraction& num, int den)
{
    if (den == 0)
    {
        throw std::runtime_error("Error: Zero denominator.");
    }

    (*this) = num / den;
    simplify();
}

Fraction::Fraction(const Fraction& num, const Fraction& den)
{
    if (den == 0)
    {
        throw std::runtime_error("Error: Zero denominator.");
    }

    (*this) = num / den;
    simplify();
}

/*
 * Fraction (op) Fraction
 */

// a/b + c/d == (ad+bc) / (bd)
const Fraction Fraction::operator+(const Fraction& f) const
{
    return Fraction(num * f.den + den * f.num, den * f.den);
}

// a/b - c/d == (ad-bc) / (bd)
const Fraction Fraction::operator-(const Fraction& f) const
{
    return Fraction(num * f.den - den * f.num, den * f.den);
}

// (a/b) * (c/d) == (ac) / (bd)
const Fraction Fraction::operator*(const Fraction& f) const
{
    return Fraction(num * f.num, den * f.den);
}

// (a/b) / (c/d) == (ad) / (bc)
const Fraction Fraction::operator/(const Fraction& f) const
{
    return Fraction(num * f.den, den * f.num);
}

/*
 * Fraction (cmp) Fraction
 */

bool Fraction::operator==(const Fraction& f) const
{
    return num == f.num && den == f.den;
}

bool Fraction::operator!=(const Fraction& f) const
{
    return !operator==(f);
}

bool Fraction::operator>(const Fraction& f) const
{
    return gt(operator double(), (double)f);
}

bool Fraction::operator<(const Fraction& f) const
{
    return lt(operator double(), (double)f);
}

bool Fraction::operator>=(const Fraction& f) const
{
    return operator>(f) || operator==(f);
}

bool Fraction::operator<=(const Fraction& f) const
{
    return operator<(f) || operator==(f);
}

/*
 * Fraction (op)= Fraction
 */

Fraction& Fraction::operator+=(const Fraction& f)
{
    *this = *this + f;
    return *this;
}

Fraction& Fraction::operator-=(const Fraction& f)
{
    *this = *this - f;
    return *this;
}

Fraction& Fraction::operator*=(const Fraction& f)
{
    *this = *this * f;
    return *this;
}

Fraction& Fraction::operator/=(const Fraction& f)
{
    *this = *this / f;
    return *this;
}

/*
 * Fraction (op) int
 */

const Fraction Fraction::operator+(int n) const
{
    return operator+(Fraction(n));
}

const Fraction Fraction::operator-(int n) const
{
    return operator-(Fraction(n));
}

const Fraction Fraction::operator*(int n) const
{
    return operator*(Fraction(n));
}

const Fraction Fraction::operator/(int n) const
{
    return operator/(Fraction(n));
}

/*
 * Fraction (cmp) int
 */

bool Fraction::operator==(int n) const
{
    return operator==(Fraction(n));
}

bool Fraction::operator!=(int n) const
{
    return operator!=(Fraction(n));
}

bool Fraction::operator>(int n) const
{
    return operator>(Fraction(n));
}

bool Fraction::operator<(int n) const
{
    return operator<(Fraction(n));
}

bool Fraction::operator>=(int n) const
{
    return operator>=(Fraction(n));
}

bool Fraction::operator<=(int n) const
{
    return operator<=(Fraction(n));
}

/*
 * Fraction (op)= int
 */

Fraction& Fraction::operator+=(int n)
{
    *this += Fraction(n);
    return *this;
}

Fraction& Fraction::operator-=(int n)
{
    *this -= Fraction(n);
    return *this;
}

Fraction& Fraction::operator*=(int n)
{
    *this *= Fraction(n);
    return *this;
}

Fraction& Fraction::operator/=(int n)
{
    *this /= Fraction(n);
    return *this;
}

/*
 * (op) Fraction
 */

// -Fraction
const Fraction Fraction::operator-() const
{
    return (*this) * (-1);
}

// ++Fraction
Fraction& Fraction::operator++()
{
    *this += 1;
    return *this;
}

// --Fraction
Fraction& Fraction::operator--()
{
    *this -= 1;
    return *this;
}

// Fraction++
const Fraction Fraction::operator++(int)
{
    Fraction tmp = *this;
    *this += 1;
    return tmp;
}

// Fraction--
const Fraction Fraction::operator--(int)
{
    Fraction tmp = *this;
    *this -= 1;
    return tmp;
}

/*
 * type conversion
 */

Fraction::operator double() const
{
    return (double)num / (double)den;
}

Fraction::operator string() const
{
    string str = "";
    if (num % den == 0)
    {
        str = std::to_string(num / den);
    }
    else
    {
        str = std::to_string(num) + "/" + std::to_string(den);
    }
    return str;
}

/*******************
 * friend function
 *******************/

/*
 * std::cout << Fraction
 */

std::ostream& operator<<(std::ostream& os, const Fraction& f)
{
    return os << (string)f;
}

/*
 * int (op) Fraction
 */

const Fraction operator+(int n, const Fraction& f)
{
    return Fraction(n) + f;
}

const Fraction operator-(int n, const Fraction& f)
{
    return Fraction(n) - f;
}

const Fraction operator*(int n, const Fraction& f)
{
    return Fraction(n) * f;
}

const Fraction operator/(int n, const Fraction& f)
{
    return Fraction(n) / f;
}

/*
 * int (cmp) Fraction
 */

bool operator==(int n, const Fraction& f)
{
    return Fraction(n) == f;
}

bool operator!=(int n, const Fraction& f)
{
    return Fraction(n) != f;
}

bool operator>(int n, const Fraction& f)
{
    return Fraction(n) > f;
}

bool operator<(int n, const Fraction& f)
{
    return Fraction(n) < f;
}

bool operator>=(int n, const Fraction& f)
{
    return Fraction(n) >= f;
}

bool operator<=(int n, const Fraction& f)
{
    return Fraction(n) <= f;
}
