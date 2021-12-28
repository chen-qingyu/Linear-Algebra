#include "fractiontest.h"
#include "fraction.h"
#include <assert.h>

void FractionTest::test()
{
    std::cout << "FractionTest::test(): Begin test." << std::endl;
    frac();
    op1();
    op2();
    op3();
    cmp1();
    cmp2();
    cmp3();
    tostr();
    std::cout << "FractionTest::test(): All test OK!" << std::endl;
}

void FractionTest::frac()
{
    assert(Fraction() == Fraction(0));
    assert(Fraction(1) == Fraction(2, 2));
    assert(Fraction(4, 6) == Fraction(2, 3));

    std::cout << "frac(): Fraction() test OK." << std::endl;
}

void FractionTest::op1()
{
    assert(1 + Fraction(1, 2) == Fraction(3, 2));
    assert(1 - Fraction(1, 2) == Fraction(1, 2));
    assert(1 * Fraction(1, 2) == Fraction(1, 2));
    assert(1 / Fraction(1, 2) == Fraction(2));

    assert(2 + Fraction(1, 2) == Fraction(5, 2));
    assert(2 - Fraction(1, 2) == Fraction(3, 2));
    assert(2 * Fraction(1, 2) == Fraction(1));
    assert(2 / Fraction(1, 2) == Fraction(4));

    std::cout << "op1(): int (op) Fraction test OK." << std::endl;
}

void FractionTest::op2()
{
    assert(Fraction(1, 2) + Fraction(1, 2) == Fraction(1));
    assert(Fraction(1, 2) - Fraction(1, 2) == Fraction(0));
    assert(Fraction(1, 2) * Fraction(1, 2) == Fraction(1, 4));
    assert(Fraction(1, 2) / Fraction(1, 2) == Fraction(1));

    assert(Fraction(3, 2) + Fraction(1, 2) == Fraction(2));
    assert(Fraction(3, 2) - Fraction(1, 2) == Fraction(1));
    assert(Fraction(3, 2) * Fraction(1, 2) == Fraction(3, 4));
    assert(Fraction(3, 2) / Fraction(1, 2) == Fraction(3));

    std::cout << "op2(): Fraction (op) Fraction test OK." << std::endl;
}

void FractionTest::op3()
{
    assert(Fraction(1, 2) + 1 == Fraction(3, 2));
    assert(Fraction(1, 2) - 1 == Fraction(-1, 2));
    assert(Fraction(1, 2) * 1 == Fraction(1, 2));
    assert(Fraction(1, 2) / 1 == Fraction(1, 2));

    assert(Fraction(1, 2) + 2 == Fraction(5, 2));
    assert(Fraction(1, 2) - 2 == Fraction(-3, 2));
    assert(Fraction(1, 2) * 2 == Fraction(1));
    assert(Fraction(1, 2) / 2 == Fraction(1, 4));

    std::cout << "op3(): Fraction (op) int test OK." << std::endl;
}

void FractionTest::cmp1()
{
    assert(0 == Fraction(0));
    assert(1 > Fraction(1, 2));
    assert(0 < Fraction(1, 2));
    assert(2 >= Fraction(1));
    assert(1 >= Fraction(1));
    assert(0 <= Fraction(1));
    assert(1 <= Fraction(1));

    std::cout << "cmp1(): int (cmp) Fraction test OK." << std::endl;
}

void FractionTest::cmp2()
{
    assert(Fraction(0) == Fraction(0));
    assert(Fraction(1) > Fraction(1, 2));
    assert(Fraction(0) < Fraction(1, 2));
    assert(Fraction(2, 3) >= Fraction(1, 3));
    assert(Fraction(1, 3) >= Fraction(1, 3));
    assert(Fraction(-1, 3) <= Fraction(1, 3));
    assert(Fraction(1, 3) <= Fraction(1, 3));

    std::cout << "cmp2(): Fraction (cmp) Fraction test OK." << std::endl;
}

void FractionTest::cmp3()
{
    assert(Fraction(0) == 0);
    assert(Fraction(2, 1) > 1);
    assert(Fraction(1, 2) < 1);
    assert(Fraction(3, 1) >= 2);
    assert(Fraction(2, 1) >= 2);
    assert(Fraction(3, 2) <= 2);
    assert(Fraction(4, 2) <= 2);

    std::cout << "cmp3(): Fraction (cmp) int test OK." << std::endl;
}

void FractionTest::tostr()
{
    assert(Fraction(1, 2).toString() == "1/2");
    assert(Fraction(2, 1).toString() == "2");
    assert(Fraction(10).toString() == "10");
    assert(Fraction().toString() == "0");
    assert(Fraction(5, 10).toString() == "1/2");
    assert(Fraction(10, 5).toString() == "2");
    assert(Fraction(11, 12).toString() == "11/12");

    std::cout << "tostr(): toString() test OK." << std::endl;
}
