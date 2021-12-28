#include "fractiontest.h"
#include "fraction.h"
#include <assert.h>

void FractionTest::test()
{
    std::cout << "FractionTest::test(): Begin test." << std::endl;
    op1();
    op2();
    op3();
    std::cout << "FractionTest::test(): All test OK!" << std::endl;
}

void FractionTest::op1()
{
    assert(1 + Fraction(1, 2) == Fraction(3, 2));
    assert(1 - Fraction(1, 2) == Fraction(1, 2));
    assert(1 * Fraction(1, 2) == Fraction(1, 2));
    assert(1 / Fraction(1, 2) == Fraction(2));
    std::cout << "op1(): int (op) Fraction test OK." << std::endl;
}

void FractionTest::op2()
{
    assert(Fraction(1, 2) + Fraction(1, 2) == Fraction(1));
    assert(Fraction(1, 2) - Fraction(1, 2) == Fraction(0));
    assert(Fraction(1, 2) * Fraction(1, 2) == Fraction(1, 4));
    assert(Fraction(1, 2) / Fraction(1, 2) == Fraction(1));
    std::cout << "op2(): Fraction (op) Fraction test OK." << std::endl;
}

void FractionTest::op3()
{
    assert(Fraction(1, 2) + 1 == Fraction(3, 2));
    assert(Fraction(1, 2) - 1 == Fraction(-1, 2));
    assert(Fraction(1, 2) * 1 == Fraction(1, 2));
    assert(Fraction(1, 2) / 1 == Fraction(1, 2));
    std::cout << "op3(): Fraction (op) int test OK." << std::endl;
}
