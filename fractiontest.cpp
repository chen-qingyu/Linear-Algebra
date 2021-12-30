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
    opassign1();
    opassign2();
    unary();
    integration();
    std::cout << "FractionTest::test(): All test OK!" << std::endl;
}

void FractionTest::frac()
{
    assert(Fraction(0) == Fraction());
    assert(Fraction(2, 2) == Fraction(1));
    assert(Fraction(4, 6) == Fraction(2, 3));
    assert(Fraction(5, -6) == Fraction(-5, 6));
    assert(Fraction(-5, -6) == Fraction(5, 6));
    assert(Fraction(5, -1) == Fraction(-5));
    assert(Fraction(-5, -1) == Fraction(5));

    try
    {
        Fraction(1, 0);
    }
    catch (std::runtime_error e)
    {
        assert(e.what() == std::string("Error: Zero denominator."));
    }

    Fraction a = 99;
    Fraction b(a);
    Fraction c = b;
    assert(a == 99);
    assert(b == 99);
    assert(c == 99);
    a = Fraction(99, 2);
    b = a;
    c = b;
    assert(a == Fraction(99, 2));
    assert(b == Fraction(99, 2));
    assert(c == Fraction(99, 2));

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
    assert(5 == Fraction(10, 2));
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
    assert(Fraction(9, 6) == Fraction(3, 2));
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
    assert(Fraction(10, 2) == 5);
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
    assert(Fraction(9, -4).toString() == "-9/4");

    std::cout << "tostr(): toString() test OK." << std::endl;
}

void FractionTest::opassign1()
{
    assert((Fraction(1, 2) += Fraction(1, 2)) == Fraction(1));
    assert((Fraction(1, 2) -= Fraction(1, 2)) == Fraction(0));
    assert((Fraction(1, 2) *= Fraction(1, 2)) == Fraction(1, 4));
    assert((Fraction(1, 2) /= Fraction(1, 2)) == Fraction(1));

    assert((Fraction(3, 2) += Fraction(1, 2)) == Fraction(2));
    assert((Fraction(3, 2) -= Fraction(1, 2)) == Fraction(1));
    assert((Fraction(3, 2) *= Fraction(1, 2)) == Fraction(3, 4));
    assert((Fraction(3, 2) /= Fraction(1, 2)) == Fraction(3));

    std::cout << "opassign1(): Fraction (op)= Fraction test OK." << std::endl;
}

void FractionTest::opassign2()
{
    assert((Fraction(1, 2) += 1) == Fraction(3, 2));
    assert((Fraction(1, 2) -= 1) == Fraction(-1, 2));
    assert((Fraction(1, 2) *= 1) == Fraction(1, 2));
    assert((Fraction(1, 2) /= 1) == Fraction(1, 2));

    assert((Fraction(1, 2) += 2) == Fraction(5, 2));
    assert((Fraction(1, 2) -= 2) == Fraction(-3, 2));
    assert((Fraction(1, 2) *= 2) == Fraction(1));
    assert((Fraction(1, 2) /= 2) == Fraction(1, 4));

    std::cout << "opassign2(): Fraction (op)= int test OK." << std::endl;
}

void FractionTest::unary()
{
    Fraction a(1, 2);
    assert((a = -a) == Fraction(-1, 2));
    assert((++a) == Fraction(1, 2));
    assert((--a) == Fraction(-1, 2));
    assert((a++) == Fraction(-1, 2));
    assert(a == Fraction(1, 2));
    assert((a--) == Fraction(1, 2));
    assert(a == Fraction(-1, 2));

    Fraction b(1, 3);
    assert(((++b) = 1) == 1);
    assert(b == 1);
    assert(((--b) = 233) == 233);
    assert(b == 233);
    assert(((b++) = 1) == 1);
    assert(b == 234);
    assert(((b--) = 1) == 1);
    assert(b == 233);

    std::cout << "unary(): (op) Fraction test OK." << std::endl;
}

void FractionTest::integration()
{
    Fraction a;
    assert(a == 0);
    assert((a = Fraction(1, -3)) == Fraction(-1, 3));
    assert((a += Fraction(1, -3)) == Fraction(-2, 3));
    assert(a.toString() == "-2/3");
    assert((a = -100) == Fraction(-100));
    assert(a.toString() == "-100");
    assert((a = 1) == Fraction(1));
    assert((a -= Fraction(1, 100)) == Fraction(99, 100));
    assert((a *= 50) == Fraction(99, 2));
    assert((a /= 99) == Fraction(1, 2));
    assert(a.toString() == "1/2");
    assert((double)a == 0.5);
    assert((a = a + a) == 1);
    assert((a = a * a) == 1);
    assert((a = a / a) == 1);
    assert((a = a - a) == 0);
    assert((double)a == 0.0);

    const Fraction b;
    assert(b == 0);

    const Fraction c(1, 3);
    assert(c == b + Fraction(1, 3));

    Fraction d(1, 2);
    assert((d += d) == 1);
    assert((d += d) == 2);
    assert((d *= d) == 4);
    assert((d /= d) == 1);
    assert((d -= d) == 0);

    assert((a + b + c + d) == Fraction(1, 3));

    try
    {
        d /= b;
    }
    catch (std::runtime_error e)
    {
        assert(e.what() == std::string("Error: Zero denominator."));
    }

    std::cout << "integration(): comprehensive test OK." << std::endl;
}
