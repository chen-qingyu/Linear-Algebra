#ifndef FRACTIONTEST_H
#define FRACTIONTEST_H

#include "fraction.h"

class FractionTest
{
public:
    static void test();

private:
    static void op1(); // int (op) Fraction
    static void op2(); // Fraction (op) Fraction
    static void op3(); // Fraction (op) int
};

#endif // FRACTIONTEST_H
