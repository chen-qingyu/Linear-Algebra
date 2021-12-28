#include "fraction.h"

/*******************
 * friend function
 *******************/

std::ostream& operator<<(std::ostream& os, Fraction f)
{
    os << f.toString();
    return os;
}

/*
 * int (op) Fraction
 */

Fraction operator+(int n, Fraction f)
{
    return Fraction(n) + f;
}

Fraction operator-(int n, Fraction f)
{
    return Fraction(n) - f;
}

Fraction operator*(int n, Fraction f)
{
    return Fraction(n) * f;
}

Fraction operator/(int n, Fraction f)
{
    return Fraction(n) / f;
}

/*
 * int (cmp) Fraction
 */

bool operator==(int n, Fraction f)
{
    return Fraction(n) == f;
}

bool operator>(int n, Fraction f)
{
    return Fraction(n) > f;
}

bool operator<(int n, Fraction f)
{
    return Fraction(n) < f;
}

bool operator>=(int n, Fraction f)
{
    return Fraction(n) >= f;
}

bool operator<=(int n, Fraction f)
{
    return Fraction(n) <= f;
}

/*******************
 * public function
 *******************/

Fraction::Fraction()
{
    num = 0;
    den = 1;
}

Fraction::Fraction(int n)
{
    num = n;
    den = 1;
}

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

/*
 * Fraction (op) Fraction
 */

// a/b + c/d == (ad+bc) / (bd)
Fraction Fraction::operator+(Fraction f)
{
    simplify();
    return Fraction(num * f.den + den * f.num, den * f.den);
}

// a/b - c/d == (ad-bc) / (bd)
Fraction Fraction::operator-(Fraction f)
{
    simplify();
    return Fraction(num * f.den - den * f.num, den * f.den);
}

// (a/b) * (c/d) == (ac) / (bd)
Fraction Fraction::operator*(Fraction f)
{
    simplify();
    return Fraction(num * f.num, den * f.den);
}

// (a/b) / (c/d) == (ad) / (bc)
Fraction Fraction::operator/(Fraction f)
{
    simplify();
    return Fraction(num * f.den, den * f.num);
}

/*
 * Fraction (cmp) Fraction
 */

bool Fraction::operator==(Fraction f)
{
    simplify();
    f.simplify();
    return num == f.num && den == f.den;
}

bool Fraction::operator>(Fraction f)
{
    return operator-(f).toDouble() > 0;
}

bool Fraction::operator<(Fraction f)
{
    return operator-(f).toDouble() < 0;
}

bool Fraction::operator>=(Fraction f)
{
    return operator-(f).toDouble() > 0 || operator==(f);
}

bool Fraction::operator<=(Fraction f)
{
    return operator-(f).toDouble() < 0 || operator==(f);
}

/*
 * Fraction (op) int
 */

Fraction Fraction::operator+(int n)
{
    return operator+(Fraction(n));
}

Fraction Fraction::operator-(int n)
{
    return operator-(Fraction(n));
}

Fraction Fraction::operator*(int n)
{
    return operator*(Fraction(n));
}

Fraction Fraction::operator/(int n)
{
    return operator/(Fraction(n));
}

/*
 * Fraction (cmp) int
 */

bool Fraction::operator==(int n)
{
    return operator==(Fraction(n));
}

bool Fraction::operator>(int n)
{
    return operator>(Fraction(n));
}

bool Fraction::operator<(int n)
{
    return operator<(Fraction(n));
}

bool Fraction::operator>=(int n)
{
    return operator>=(Fraction(n));
}

bool Fraction::operator<=(int n)
{
    return operator<=(Fraction(n));
}

double Fraction::toDouble()
{
    return (double)num / (double)den;
}

std::string Fraction::toString()
{
    simplify();
    std::string str;
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
