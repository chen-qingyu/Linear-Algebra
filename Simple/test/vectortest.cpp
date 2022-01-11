#include <assert.h>
#include <cmath>

#include "vector.h"
#include "vectortest.h"

void VectorTest::test()
{
    std::cout << "==== VectorTest::test(): Begin test. ====" << std::endl;
    vect();
    append();
    op();
    tostr();
    op1();
    op2();
    op3();
    len();
    vp();
    unit();
    all();
    std::cout << "==== VectorTest::test(): All test OK! ====" << std::endl;
}

void VectorTest::vect()
{
    Vector a;
    assert(a == Vector());
    assert(a.size == 0);

    Vector b = Vector({1});
    assert(b == Vector().append(1));
    assert(b.size == 1);

    Vector c = Vector({0, 1, 2});
    assert(c == Vector().append(0).append(1).append(2));
    assert(c.size == 3);

    std::cout << "vect(): Vector() test OK." << std::endl;
}

void VectorTest::append()
{
    Vector v;
    v.append(1).append(2).append(3);
    assert(v == Vector({1, 2, 3}));
    assert(v.append(v) == Vector({1, 2, 3, 1, 2, 3}));
    assert(v == Vector({1, 2, 3, 1, 2, 3}));

    std::cout << "append(): append() test OK." << std::endl;
}

void VectorTest::op()
{
    Vector a = Vector({-1, 0, 1, 0.5});
    assert(a[0] == -1);
    assert(a[1] == 0);
    assert(a[2] == 1);
    assert(eq(a[3], 0.5));
    a[0] = 233;
    assert(a[0] == 233);
    a[10] = 666;
    assert(a[10] == 666);

    std::cout << "op(): operator[] operator== test OK." << std::endl;
}

void VectorTest::tostr()
{
    assert(Vector().toString() == "[]");
    assert(Vector({1, 2, 3}).toString() == "[1.000000 2.000000 3.000000]");
    assert(Vector({0, 0.5, 0.66}).toString() == "[0.000000 0.500000 0.660000]");

    std::cout << "tostr(): toString() test OK." << std::endl;
}

void VectorTest::op1()
{
    Vector v1 = Vector({1, 2, 3});
    Vector v2 = Vector({4, 5, 6});

    Vector v3 = v1 + v2;
    assert(v1 + v2 == v2 + v1);
    assert(v1 == Vector({1, 2, 3}));
    assert(v2 == Vector({4, 5, 6}));
    assert(v3 == Vector({5, 7, 9}));

    Vector v4 = v1 - v2;
    assert(v1 - v2 == Vector({-3, -3, -3}));
    assert(v1 == Vector({1, 2, 3}));
    assert(v2 == Vector({4, 5, 6}));
    assert(v4 == Vector({-3, -3, -3}));

    Vector v5 = v2 - v1;
    assert(v2 - v1 == Vector({3, 3, 3}));
    assert(v1 == Vector({1, 2, 3}));
    assert(v2 == Vector({4, 5, 6}));
    assert(v5 == Vector({3, 3, 3}));

    Vector v6 = Vector({1, 1, 1, 1});
    try
    {
        v1 + v6;
    }
    catch (std::runtime_error e)
    {
        assert(e.what() == std::string("Error: Add two vectors of different lengths."));
    }
    try
    {
        v1 - v6;
    }
    catch (std::runtime_error e)
    {
        assert(e.what() == std::string("Error: Subtract two vectors of different lengths."));
    }
    try
    {
        v6 - v1;
    }
    catch (std::runtime_error e)
    {
        assert(e.what() == std::string("Error: Subtract two vectors of different lengths."));
    }

    Vector v7, v8;
    try
    {
        v7 + v8;
    }
    catch (std::runtime_error e)
    {
        assert(e.what() == std::string("Error: The vectors are empty."));
    }
    try
    {
        v7 - v8;
    }
    catch (std::runtime_error e)
    {
        assert(e.what() == std::string("Error: The vectors are empty."));
    }
    try
    {
        v8 - v7;
    }
    catch (std::runtime_error e)
    {
        assert(e.what() == std::string("Error: The vectors are empty."));
    }

    std::cout << "op1(): operator+ operator- test OK." << std::endl;
}

void VectorTest::op2()
{
    Vector v1 = Vector({1, 1});
    Vector v2 = Vector({1, 1});

    double d1 = v1 * v2;
    assert(v1 * v2 == 2);
    assert(2 == v2 * v1);
    assert(v1 == Vector({1, 1}));
    assert(v2 == Vector({1, 1}));
    assert(d1 == 2);

    v1.append(2);  // [1 1 2]
    v2.append(-2); // [1 1 -2]
    assert(v1 * v2 == -2);
    assert(-2 == v2 * v1);
    assert(v1 == Vector({1, 1, 2}));
    assert(v2 == Vector({1, 1, -2}));

    v1.append(0);
    try
    {
        (v1 * v2);
    }
    catch (std::runtime_error e)
    {
        assert(e.what() == std::string("Error: Multiply two vectors of different lengths."));
    }

    Vector v3, v4;
    try
    {
        (v3 * v4);
    }
    catch (std::runtime_error e)
    {
        assert(e.what() == std::string("Error: The vectors are empty."));
    }

    std::cout << "op2(): dot product test OK." << std::endl;
}

void VectorTest::op3()
{
    double d = 0.5;
    Vector v = Vector({1, 1, 1});
    assert(v * d == Vector({0.5, 0.5, 0.5}));
    assert(d * v == Vector({0.5, 0.5, 0.5}));
    assert(v * d == d * v);
    assert(v == Vector({1, 1, 1}));
    assert(v * 10 == Vector({10, 10, 10}));
    assert(10 * v == Vector({10, 10, 10}));

    Vector empty;
    try
    {
        10 * empty;
    }
    catch (std::runtime_error e)
    {
        assert(e.what() == std::string("Error: The vector is empty."));
    }
    try
    {
        empty * 10;
    }
    catch (std::runtime_error e)
    {
        assert(e.what() == std::string("Error: The vector is empty."));
    }

    assert(v == Vector({1, 1, 1}));
    assert(v / 1 == Vector({1, 1, 1}));
    assert(v / 2 == Vector({0.5, 0.5, 0.5}));
    assert(v / 0.5 == Vector({2, 2, 2}));
    assert(v / 0.01 == Vector({100, 100, 100}));

    std::cout << "op3(): scalar multiplication test OK." << std::endl;
}

void VectorTest::len()
{
    Vector v;
    try
    {
        v.length();
    }
    catch (std::runtime_error e)
    {
        assert(e.what() == std::string("Error: The vector is empty."));
    }

    v.append(0);
    assert(v.length() == 0);
    v.append(1);
    assert(v.length() == 1);

    v[0] = 3;
    v[1] = 4;
    assert(v.length() == 5);

    std::cout << "len(): length() test OK." << std::endl;
}

void VectorTest::vp()
{
    Vector zero = Vector({0, 0});

    assert(zero.isVerticalTo(Vector({0, 0})));
    assert(zero.isVerticalTo(Vector({1, 1})));
    assert(zero.isVerticalTo(Vector({2, 3})));

    assert(zero.isParallelTo(Vector({0, 0})));
    assert(zero.isParallelTo(Vector({1, 1})));
    assert(zero.isParallelTo(Vector({2, 3})));

    Vector v = Vector({1, 1});

    assert(v.isVerticalTo(Vector({1, -1})));
    assert(v.isVerticalTo(Vector({-1, 1})));

    assert(v.isParallelTo(Vector({2, 2})));
    assert(v.isParallelTo(Vector({-2, -2})));

    v.append(9); // [1 1 9]
    assert(v.isVerticalTo(Vector({1, -1, 0})));
    assert(v.isParallelTo(Vector({-1, -1, -9})));

    std::cout << "vp(): isVerticalTo() isParallelTo() test OK." << std::endl;
}

void VectorTest::unit()
{
    Vector v = Vector({1, 1});

    assert(v.unitize() == Vector({1 / std::sqrt(2), 1 / std::sqrt(2)}));
    assert(eq(v.length(), 1));
    assert(v == Vector({1 / std::sqrt(2), 1 / std::sqrt(2)}));
    assert(eq(v.unitize().unitize().unitize().length(), 1));

    std::cout << "unit(): unitize() test OK." << std::endl;
}

void VectorTest::all()
{
    Vector v;
    assert(v.size == 0);

    v.append({1, 2, 3});
    assert(v.size == 3);

    Vector v2({4, 5, 6});
    v.append(v2);
    assert(v.size == 6);

    v.append(7);
    assert(v.size == 7);

    int len = 0;
    for (int i = 1; i <= 7; ++i)
    {
        len += i * i;
    }
    assert(eq(v.length(), std::sqrt(len)));

    assert(eq(v.unitize().length(), 1));

    assert(v == v.unitize());

    v = Vector({0, 1});
    assert(v.isVerticalTo(Vector({10, 0})));
    assert(v.isParallelTo(Vector({0, -10})));
    v[0] = 10;
    v[1] = 0;
    assert(v.isVerticalTo(Vector({0, -10})));
    assert(v.isParallelTo(Vector({-10, 0})));
    assert(v.unitize() == Vector({1, 0}));
    assert((v = v * 99) == Vector({99, 0}));
    assert((v = v / 99) == Vector({1, 0}));
    assert((v = v + Vector({10, 0})) == Vector({11, 0}));
    assert((v = v - Vector({1, 10})) == Vector({10, -10}));
    assert((v = 0.1 * v) == Vector({1, -1}));
    assert(eq(v.length(), std::sqrt(2)));

    std::cout << "all(): comprehensive test OK." << std::endl;
}
