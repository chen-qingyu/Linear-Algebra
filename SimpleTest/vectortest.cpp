#include <cmath>

#include "test.h"

#include "../Simple/vector.h"

TEST(VectorTest, vect)
{
    Vector a;
    ASSERT_EQ(a, Vector());
    ASSERT_EQ(a.size, (Vector::size_t)0);

    Vector b = Vector({1});
    ASSERT_EQ(b, Vector().append(1));
    ASSERT_EQ(b.size, (Vector::size_t)1);

    Vector c = Vector({0, 1, 2});
    ASSERT_EQ(c, Vector().append(0).append(1).append(2));
    ASSERT_EQ(c.size, (Vector::size_t)3);

    Vector d = {1, 2, 3, 4};
    ASSERT_EQ(d, Vector({1, 2, 3, 4}));
    ASSERT_EQ(d.size, (Vector::size_t)4);

    Vector e(5, 4);
    ASSERT_EQ(e, Vector({4, 4, 4, 4, 4}));
    ASSERT_EQ(e.size, (Vector::size_t)5);

    vector<double> vd = {1, 2, 3, 4, 5};
    Vector f(vd);
    ASSERT_EQ(f, Vector({1, 2, 3, 4, 5}));
    ASSERT_EQ(f.size, (Vector::size_t)5);

    Vector g = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    ASSERT_EQ(g.size, (Vector::size_t)10);
    ASSERT_EQ(g[0], 0);
    ASSERT_EQ(g[9], 9);
    g = {2, 3, 5, 7, 11};
    ASSERT_EQ(g.size, (Vector::size_t)5);
    ASSERT_EQ(g[0], 2);
    ASSERT_EQ(g[4], 11);

    std::cout << "Vector() test OK." << std::endl;
}

TEST(VectorTest, append)
{
    Vector v;
    v.append(1).append(2).append(3);
    ASSERT_EQ(v, Vector({1, 2, 3}));
    ASSERT_EQ(v.append(v), Vector({1, 2, 3, 1, 2, 3}));
    ASSERT_EQ(v, Vector({1, 2, 3, 1, 2, 3}));

    std::cout << "append() test OK." << std::endl;
}

TEST(VectorTest, op)
{
    Vector a = Vector({-1, 0, 1, 0.5});
    ASSERT_EQ(a[0], -1);
    ASSERT_EQ(a[1], 0);
    ASSERT_EQ(a[2], 1);
    ASSERT_TRUE(eq(a[3], 0.5));
    a[0] = 233;
    ASSERT_EQ(a[0], 233);

    try
    {
        a[4] = 666;
    }
    catch (std::runtime_error e)
    {
        ASSERT_STREQ(e.what(), "Error: Vector index out of bounds.");
    }

    std::cout << "op(): operator[] operator== test OK." << std::endl;
}

TEST(VectorTest, tostr)
{
    ASSERT_EQ(Vector().toString(), "[]");
    ASSERT_EQ(Vector({1, 2, 3}).toString(), "[1.000000 2.000000 3.000000]");
    ASSERT_EQ(Vector({0, 0.5, 0.66}).toString(), "[0.000000 0.500000 0.660000]");

    std::cout << "toString() test OK." << std::endl;
}

TEST(VectorTest, op1)
{
    Vector v1 = Vector({1, 2, 3});
    Vector v2 = Vector({4, 5, 6});

    Vector v3 = v1 + v2;
    ASSERT_EQ(v1 + v2, v2 + v1);
    ASSERT_EQ(v1, Vector({1, 2, 3}));
    ASSERT_EQ(v2, Vector({4, 5, 6}));
    ASSERT_EQ(v3, Vector({5, 7, 9}));

    Vector v4 = v1 - v2;
    ASSERT_EQ(v1 - v2, Vector({-3, -3, -3}));
    ASSERT_EQ(v1, Vector({1, 2, 3}));
    ASSERT_EQ(v2, Vector({4, 5, 6}));
    ASSERT_EQ(v4, Vector({-3, -3, -3}));

    Vector v5 = v2 - v1;
    ASSERT_EQ(v2 - v1, Vector({3, 3, 3}));
    ASSERT_EQ(v1, Vector({1, 2, 3}));
    ASSERT_EQ(v2, Vector({4, 5, 6}));
    ASSERT_EQ(v5, Vector({3, 3, 3}));

    Vector v6 = Vector({1, 1, 1, 1});
    try
    {
        v1 + v6;
    }
    catch (std::runtime_error e)
    {
        ASSERT_STREQ(e.what(), "Error: Add two vectors of different size.");
    }
    try
    {
        v1 - v6;
    }
    catch (std::runtime_error e)
    {
        ASSERT_STREQ(e.what(), "Error: Subtract two vectors of different size.");
    }
    try
    {
        v6 - v1;
    }
    catch (std::runtime_error e)
    {
        ASSERT_STREQ(e.what(), "Error: Subtract two vectors of different size.");
    }

    Vector v7, v8;
    try
    {
        v7 + v8;
    }
    catch (std::runtime_error e)
    {
        ASSERT_STREQ(e.what(), "Error: The vectors are empty.");
    }
    try
    {
        v7 - v8;
    }
    catch (std::runtime_error e)
    {
        ASSERT_STREQ(e.what(), "Error: The vectors are empty.");
    }
    try
    {
        v8 - v7;
    }
    catch (std::runtime_error e)
    {
        ASSERT_STREQ(e.what(), "Error: The vectors are empty.");
    }

    std::cout << "operator+ operator- test OK." << std::endl;
}

TEST(VectorTest, op2)
{
    Vector v1 = Vector({1, 1});
    Vector v2 = Vector({1, 1});

    double d1 = v1 * v2;
    ASSERT_EQ(v1 * v2, 2);
    ASSERT_EQ(2, v2 * v1);
    ASSERT_EQ(v1, Vector({1, 1}));
    ASSERT_EQ(v2, Vector({1, 1}));
    ASSERT_EQ(d1, 2);

    v1.append(2);  // [1 1 2]
    v2.append(-2); // [1 1 -2]
    ASSERT_EQ(v1 * v2, -2);
    ASSERT_EQ(-2, v2 * v1);
    ASSERT_EQ(v1, Vector({1, 1, 2}));
    ASSERT_EQ(v2, Vector({1, 1, -2}));

    v1.append(0);
    try
    {
        (v1 * v2);
    }
    catch (std::runtime_error e)
    {
        ASSERT_STREQ(e.what(), "Error: Multiply two vectors of different size.");
    }

    Vector v3, v4;
    try
    {
        (v3 * v4);
    }
    catch (std::runtime_error e)
    {
        ASSERT_STREQ(e.what(), "Error: The vectors are empty.");
    }

    std::cout << "dot product test OK." << std::endl;
}

TEST(VectorTest, op3)
{
    double d = 0.5;
    Vector v = Vector({1, 1, 1});
    ASSERT_EQ(v * d, Vector({0.5, 0.5, 0.5}));
    ASSERT_EQ(d * v, Vector({0.5, 0.5, 0.5}));
    ASSERT_EQ(v * d, d * v);
    ASSERT_EQ(v, Vector({1, 1, 1}));
    ASSERT_EQ(v * 10, Vector({10, 10, 10}));
    ASSERT_EQ(10 * v, Vector({10, 10, 10}));

    Vector empty;
    try
    {
        10 * empty;
    }
    catch (std::runtime_error e)
    {
        ASSERT_STREQ(e.what(), "Error: The vector is empty.");
    }
    try
    {
        empty * 10;
    }
    catch (std::runtime_error e)
    {
        ASSERT_STREQ(e.what(), "Error: The vector is empty.");
    }

    ASSERT_EQ(v, Vector({1, 1, 1}));
    ASSERT_EQ(v / 1, Vector({1, 1, 1}));
    ASSERT_EQ(v / 2, Vector({0.5, 0.5, 0.5}));
    ASSERT_EQ(v / 0.5, Vector({2, 2, 2}));
    ASSERT_EQ(v / 0.01, Vector({100, 100, 100}));

    std::cout << "scalar multiplication test OK." << std::endl;
}

TEST(VectorTest, len)
{
    Vector v;
    try
    {
        v.length();
    }
    catch (std::runtime_error e)
    {
        ASSERT_STREQ(e.what(), "Error: The vector is empty.");
    }

    v.append(0);
    ASSERT_EQ(v.length(), 0);
    v.append(1);
    ASSERT_EQ(v.length(), 1);

    v[0] = 3;
    v[1] = 4;
    ASSERT_EQ(v.length(), 5);

    std::cout << "length() test OK." << std::endl;
}

TEST(VectorTest, vp)
{
    Vector zero = Vector({0, 0});

    ASSERT_TRUE(zero.isVerticalTo(Vector({0, 0})));
    ASSERT_TRUE(zero.isVerticalTo(Vector({1, 1})));
    ASSERT_TRUE(zero.isVerticalTo(Vector({2, 3})));

    ASSERT_TRUE(zero.isParallelTo(Vector({0, 0})));
    ASSERT_TRUE(zero.isParallelTo(Vector({1, 1})));
    ASSERT_TRUE(zero.isParallelTo(Vector({2, 3})));

    Vector v = Vector({1, 1});

    ASSERT_TRUE(v.isVerticalTo(Vector({1, -1})));
    ASSERT_TRUE(v.isVerticalTo(Vector({-1, 1})));

    ASSERT_TRUE(v.isParallelTo(Vector({2, 2})));
    ASSERT_TRUE(v.isParallelTo(Vector({-2, -2})));

    v.append(9); // [1 1 9]
    ASSERT_TRUE(v.isVerticalTo(Vector({1, -1, 0})));
    ASSERT_TRUE(v.isParallelTo(Vector({-1, -1, -9})));

    std::cout << "isVerticalTo() isParallelTo() test OK." << std::endl;
}

TEST(VectorTest, unit)
{
    Vector v = Vector({1, 1});

    ASSERT_EQ(v.unitize(), Vector({1 / std::sqrt(2), 1 / std::sqrt(2)}));
    ASSERT_TRUE(eq(v.length(), 1));
    ASSERT_EQ(v, Vector({1 / std::sqrt(2), 1 / std::sqrt(2)}));
    ASSERT_TRUE(eq(v.unitize().unitize().unitize().length(), 1));

    std::cout << "unitize() test OK." << std::endl;
}

TEST(VectorTest, all)
{
    Vector v;
    ASSERT_EQ(v.size, (Vector::size_t)0);

    v.append({1, 2, 3});
    ASSERT_EQ(v.size, (Vector::size_t)3);

    Vector v2({4, 5, 6});
    v.append(v2);
    ASSERT_EQ(v.size, (Vector::size_t)6);

    v.append(7);
    ASSERT_EQ(v.size, (Vector::size_t)7);

    int len = 0;
    for (int i = 1; i <= 7; ++i)
    {
        len += i * i;
    }
    ASSERT_TRUE(eq(v.length(), std::sqrt(len)));

    ASSERT_TRUE(eq(v.unitize().length(), 1));

    ASSERT_EQ(v, v.unitize());

    v = Vector({0, 1});
    ASSERT_TRUE(v.isVerticalTo(Vector({10, 0})));
    ASSERT_TRUE(v.isParallelTo(Vector({0, -10})));
    v[0] = 10;
    v[1] = 0;
    ASSERT_TRUE(v.isVerticalTo(Vector({0, -10})));
    ASSERT_TRUE(v.isParallelTo(Vector({-10, 0})));
    ASSERT_EQ(v.unitize(), Vector({1, 0}));
    ASSERT_EQ((v = v * 99), Vector({99, 0}));
    ASSERT_EQ((v = v / 99), Vector({1, 0}));
    ASSERT_EQ((v = v + Vector({10, 0})), Vector({11, 0}));
    ASSERT_EQ((v = v - Vector({1, 10})), Vector({10, -10}));
    ASSERT_EQ((v = 0.1 * v), Vector({1, -1}));
    ASSERT_TRUE(eq(v.length(), std::sqrt(2)));

    std::cout << "comprehensive test OK." << std::endl;
}
