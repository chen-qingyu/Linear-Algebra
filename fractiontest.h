#ifndef FRACTIONTEST_H
#define FRACTIONTEST_H

#include "fraction.h"

class FractionTest
{
public:
    static void test();

private:
    static void frac();      // Fraction()
    static void op1();       // int (op) Fraction
    static void op2();       // Fraction (op) Fraction
    static void op3();       // Fraction (op) int
    static void cmp1();      // int (cmp) Fraction
    static void cmp2();      // Fraction (cmp) Fraction
    static void cmp3();      // Fraction (cmp) int
    static void tostr();     // toString()
    static void opassign1(); // Fraction (op)= Fraction
    static void opassign2(); // Fraction (op)= int
    static void unary();     // (op) Fraction
    static void all();       // comprehensive
};

#endif // FRACTIONTEST_H
