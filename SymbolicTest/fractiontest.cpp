#include "test.h"

#include "../Symbolic/fraction.h"

TEST(FractionTest, frac)
{
    ASSERT_EQ(Fraction(0), Fraction());
    ASSERT_EQ(Fraction(2, 2), Fraction(1));
    ASSERT_EQ(Fraction(4, 6), Fraction(2, 3));
    ASSERT_EQ(Fraction(5, -6), Fraction(-5, 6));
    ASSERT_EQ(Fraction(-5, -6), Fraction(5, 6));
    ASSERT_EQ(Fraction(5, -1), Fraction(-5));
    ASSERT_EQ(Fraction(-5, -1), Fraction(5));

    ASSERT_EQ(Fraction(1, Fraction(1, 2)), 2);
    ASSERT_EQ(Fraction(1, Fraction(1, Fraction(1, Fraction(1, -2)))), -2);

    ASSERT_EQ(Fraction(Fraction(1, 2), 1), Fraction(1, 2));
    ASSERT_EQ(Fraction(Fraction(1, 2), 2), Fraction(1, 4));

    ASSERT_EQ(Fraction(Fraction(1, 2), Fraction(1, 2)), 1);
    ASSERT_EQ(Fraction(Fraction(1, 2), Fraction(2, 3)), Fraction(3, 4));

    try
    {
        Fraction(1, 0);
    }
    catch (std::runtime_error e)
    {
        ASSERT_STREQ(e.what(), "Error: Zero denominator.");
    }

    Fraction a = 99;
    Fraction b(a);
    Fraction c = b;
    ASSERT_EQ(a, 99);
    ASSERT_EQ(b, 99);
    ASSERT_EQ(c, 99);
    a = Fraction(99, 2);
    b = a;
    c = b;
    ASSERT_EQ(a, Fraction(99, 2));
    ASSERT_EQ(b, Fraction(99, 2));
    ASSERT_EQ(c, Fraction(99, 2));

    std::cout << "Fraction() test OK." << std::endl;
}

TEST(FractionTest, op1)
{
    ASSERT_EQ(1 + Fraction(1, 2), Fraction(3, 2));
    ASSERT_EQ(1 - Fraction(1, 2), Fraction(1, 2));
    ASSERT_EQ(1 * Fraction(1, 2), Fraction(1, 2));
    ASSERT_EQ(1 / Fraction(1, 2), Fraction(2));

    ASSERT_EQ(2 + Fraction(1, 2), Fraction(5, 2));
    ASSERT_EQ(2 - Fraction(1, 2), Fraction(3, 2));
    ASSERT_EQ(2 * Fraction(1, 2), Fraction(1));
    ASSERT_EQ(2 / Fraction(1, 2), Fraction(4));

    std::cout << "int (op) Fraction test OK." << std::endl;
}

TEST(FractionTest, op2)
{
    ASSERT_EQ(Fraction(1, 2) + Fraction(1, 2), Fraction(1));
    ASSERT_EQ(Fraction(1, 2) - Fraction(1, 2), Fraction(0));
    ASSERT_EQ(Fraction(1, 2) * Fraction(1, 2), Fraction(1, 4));
    ASSERT_EQ(Fraction(1, 2) / Fraction(1, 2), Fraction(1));

    ASSERT_EQ(Fraction(3, 2) + Fraction(1, 2), Fraction(2));
    ASSERT_EQ(Fraction(3, 2) - Fraction(1, 2), Fraction(1));
    ASSERT_EQ(Fraction(3, 2) * Fraction(1, 2), Fraction(3, 4));
    ASSERT_EQ(Fraction(3, 2) / Fraction(1, 2), Fraction(3));

    std::cout << "Fraction (op) Fraction test OK." << std::endl;
}

TEST(FractionTest, op3)
{
    ASSERT_EQ(Fraction(1, 2) + 1, Fraction(3, 2));
    ASSERT_EQ(Fraction(1, 2) - 1, Fraction(-1, 2));
    ASSERT_EQ(Fraction(1, 2) * 1, Fraction(1, 2));
    ASSERT_EQ(Fraction(1, 2) / 1, Fraction(1, 2));

    ASSERT_EQ(Fraction(1, 2) + 2, Fraction(5, 2));
    ASSERT_EQ(Fraction(1, 2) - 2, Fraction(-3, 2));
    ASSERT_EQ(Fraction(1, 2) * 2, Fraction(1));
    ASSERT_EQ(Fraction(1, 2) / 2, Fraction(1, 4));

    std::cout << "Fraction (op) int test OK." << std::endl;
}

TEST(FractionTest, cmp1)
{
    ASSERT_EQ(0, Fraction(0));
    ASSERT_EQ(5, Fraction(10, 2));
    ASSERT_GT(1, Fraction(1, 2));
    ASSERT_LT(0, Fraction(1, 2));
    ASSERT_GE(2, Fraction(1));
    ASSERT_GE(1, Fraction(1));
    ASSERT_LE(0, Fraction(1));
    ASSERT_LE(1, Fraction(1));

    std::cout << "int (cmp) Fraction test OK." << std::endl;
}

TEST(FractionTest, cmp2)
{
    ASSERT_EQ(Fraction(0), Fraction(0));
    ASSERT_EQ(Fraction(9, 6), Fraction(3, 2));
    ASSERT_GT(Fraction(1), Fraction(1, 2));
    ASSERT_LT(Fraction(0), Fraction(1, 2));
    ASSERT_GE(Fraction(2, 3), Fraction(1, 3));
    ASSERT_GE(Fraction(1, 3), Fraction(1, 3));
    ASSERT_LE(Fraction(-1, 3), Fraction(1, 3));
    ASSERT_LE(Fraction(1, 3), Fraction(1, 3));

    std::cout << "Fraction (cmp) Fraction test OK." << std::endl;
}

TEST(FractionTest, cmp3)
{
    ASSERT_EQ(Fraction(0), 0);
    ASSERT_EQ(Fraction(10, 2), 5);
    ASSERT_GT(Fraction(2, 1), 1);
    ASSERT_LT(Fraction(1, 2), 1);
    ASSERT_GE(Fraction(3, 1), 2);
    ASSERT_GE(Fraction(2, 1), 2);
    ASSERT_LE(Fraction(3, 2), 2);
    ASSERT_LE(Fraction(4, 2), 2);

    std::cout << "Fraction (cmp) int test OK." << std::endl;
}

TEST(FractionTest, tostr)
{
    ASSERT_EQ((string)Fraction(1, 2), "1/2");
    ASSERT_EQ((string)Fraction(2, 1), "2");
    ASSERT_EQ((string)Fraction(10), "10");
    ASSERT_EQ((string)Fraction(), "0");
    ASSERT_EQ((string)Fraction(5, 10), "1/2");
    ASSERT_EQ((string)Fraction(10, 5), "2");
    ASSERT_EQ((string)Fraction(11, 12), "11/12");
    ASSERT_EQ((string)Fraction(9, -4), "-9/4");

    std::cout << "operator string() test OK." << std::endl;
}

TEST(FractionTest, opassign1)
{
    ASSERT_EQ((Fraction(1, 2) += Fraction(1, 2)), Fraction(1));
    ASSERT_EQ((Fraction(1, 2) -= Fraction(1, 2)), Fraction(0));
    ASSERT_EQ((Fraction(1, 2) *= Fraction(1, 2)), Fraction(1, 4));
    ASSERT_EQ((Fraction(1, 2) /= Fraction(1, 2)), Fraction(1));

    ASSERT_EQ((Fraction(3, 2) += Fraction(1, 2)), Fraction(2));
    ASSERT_EQ((Fraction(3, 2) -= Fraction(1, 2)), Fraction(1));
    ASSERT_EQ((Fraction(3, 2) *= Fraction(1, 2)), Fraction(3, 4));
    ASSERT_EQ((Fraction(3, 2) /= Fraction(1, 2)), Fraction(3));

    std::cout << "Fraction (op)= Fraction test OK." << std::endl;
}

TEST(FractionTest, opassign2)
{
    ASSERT_EQ((Fraction(1, 2) += 1), Fraction(3, 2));
    ASSERT_EQ((Fraction(1, 2) -= 1), Fraction(-1, 2));
    ASSERT_EQ((Fraction(1, 2) *= 1), Fraction(1, 2));
    ASSERT_EQ((Fraction(1, 2) /= 1), Fraction(1, 2));

    ASSERT_EQ((Fraction(1, 2) += 2), Fraction(5, 2));
    ASSERT_EQ((Fraction(1, 2) -= 2), Fraction(-3, 2));
    ASSERT_EQ((Fraction(1, 2) *= 2), Fraction(1));
    ASSERT_EQ((Fraction(1, 2) /= 2), Fraction(1, 4));

    std::cout << "Fraction (op)= int test OK." << std::endl;
}

TEST(FractionTest, unary)
{
    Fraction a(1, 2);
    ASSERT_EQ((a = -a), Fraction(-1, 2));
    ASSERT_EQ(++a, Fraction(1, 2));
    ASSERT_EQ(--a, Fraction(-1, 2));
    ASSERT_EQ(a++, Fraction(-1, 2));
    ASSERT_EQ(a, Fraction(1, 2));
    ASSERT_EQ(a--, Fraction(1, 2));
    ASSERT_EQ(a, Fraction(-1, 2));

    Fraction b(1, 3);
    ASSERT_EQ(((++b) = 1), 1);
    ASSERT_EQ(b, 1);
    ASSERT_EQ(((--b) = 233), 233);
    ASSERT_EQ(b++, 233);
    ASSERT_EQ(b, 234);
    ASSERT_EQ(b--, 234);
    ASSERT_EQ(b, 233);

    std::cout << "(op) Fraction test OK." << std::endl;
}

TEST(FractionTest, all)
{
    Fraction a;
    ASSERT_EQ(a, 0);
    ASSERT_EQ((a = Fraction(1, -3)), Fraction(-1, 3));
    ASSERT_EQ((a += Fraction(1, -3)), Fraction(-2, 3));
    ASSERT_EQ((string)a, "-2/3");
    ASSERT_EQ((a = -100), Fraction(-100));
    ASSERT_EQ((string)a, "-100");
    ASSERT_EQ((a = 1), Fraction(1));
    ASSERT_EQ((a -= Fraction(1, 100)), Fraction(99, 100));
    ASSERT_EQ((a *= 50), Fraction(99, 2));
    ASSERT_EQ((a /= 99), Fraction(1, 2));
    ASSERT_EQ((string)a, "1/2");
    ASSERT_EQ((double)a, 0.5);
    ASSERT_EQ((a = a + a), 1);
    ASSERT_EQ((a = a * a), 1);
    ASSERT_EQ((a = a / a), 1);
    ASSERT_EQ((a = a - a), 0);
    ASSERT_EQ((double)a, 0.0);

    const Fraction b;
    ASSERT_EQ(b, 0);

    const Fraction c(1, 3);
    ASSERT_EQ(c, b + Fraction(1, 3));

    Fraction d(1, 2);
    ASSERT_EQ((d += d), 1);
    ASSERT_EQ((d += d), 2);
    ASSERT_EQ((d *= d), 4);
    ASSERT_EQ((d /= d), 1);
    ASSERT_EQ((d -= d), 0);

    ASSERT_EQ((a + b + c + d), Fraction(1, 3));

    try
    {
        d /= b;
    }
    catch (std::runtime_error e)
    {
        ASSERT_STREQ(e.what(), "Error: Zero denominator.");
    }

    std::cout << "comprehensive test OK." << std::endl;
}
