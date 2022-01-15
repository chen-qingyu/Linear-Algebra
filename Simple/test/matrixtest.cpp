#include <assert.h>

#include "matrix.h"
#include "matrixtest.h"

void MatrixTest::test()
{
    std::cout << "==== MatrixTest::test(): Begin test. ====" << std::endl;
    matr();
    op();
    tostr();
    op1();
    op2();
    trans();
    e();
    //    all();
    std::cout << "==== MatrixTest::test(): All test OK! ====" << std::endl;
}

void MatrixTest::matr()
{
    Matrix m;
    assert(m.size.row == 0 && m.size.col == 0);
    Matrix m2 = Matrix({Vector({1, 2, 3}), Vector({4, 5, 6})});
    assert(m2.size.row == 2 && m2.size.col == 3);
    assert(m2[0] == Vector({1, 2, 3}));
    assert(m2[1] == Vector({4, 5, 6}));
    Matrix m3 = Matrix(4, 0);
    assert(m3.size.row == 4 && m3.size.col == 4);
    assert(m3[3][3] == 0);
    Matrix m4 = Matrix(4, 5, 1);
    assert(m4.size.row == 4 && m4.size.col == 5);
    assert(m4[3][4] == 1);

    std::cout << "matr(): Matrix() test OK." << std::endl;
}

void MatrixTest::op()
{
    Matrix m = Matrix(2, 3, 0);
    assert(m[0][0] == 0);
    assert(m[1][2] == 0);
    m[0][0] = 1;
    m[1][2] = 233;
    assert(m[0][0] == 1);
    assert(m[1][2] == 233);

    try
    {
        m[2][3] = 9;
    }
    catch (std::runtime_error e)
    {
        assert(e.what() == std::string("Error: Matrix index out of bounds."));
    }

    assert(m == Matrix({Vector({1, 0, 0}), Vector({0, 0, 233})}));
    assert(m != Matrix());

    std::cout << "op(): operator[] operator== operator!= test OK." << std::endl;
}

void MatrixTest::tostr()
{
    Matrix m = Matrix();
    assert(m.toString() == "[]");
    Matrix m2 = Matrix(2, 3, 0);
    assert(m2.toString() == "[0.000000 0.000000 0.000000]\n[0.000000 0.000000 0.000000]");
    Matrix m3 = Matrix(1, 2, 5);
    assert(m3.toString() == "[5.000000 5.000000]");

    std::cout << "tostr(): toString() test OK." << std::endl;
}

void MatrixTest::op1()
{
    Matrix m1 = Matrix(2, 3, 1);
    Matrix m2 = Matrix(2, 3, 2);
    assert(m1 + m2 == Matrix(2, 3, 3));
    assert(m1 - m2 == Matrix(2, 3, -1));
    assert(m2 - m1 == Matrix(2, 3, 1));

    Matrix m3 = Matrix(2, 2, 1);
    Matrix m4 = Matrix(2, 2, 2);
    Matrix m5 = Matrix(2, 3, 3);
    assert(m3 * m4 == Matrix(2, 2, 4));
    assert(m3 * m5 == Matrix(2, 3, 6));
    assert(m4 * m5 == Matrix(2, 3, 12));

    Matrix m6 = Matrix(1, 3, 1);
    Matrix m7 = Matrix(3, 1, 1);
    assert(m6 * m7 == Matrix(1, 3));

    try
    {
        (m5 * m4);
    }
    catch (std::runtime_error e)
    {
        assert(e.what() == std::string("Error: The row and column size don't match."));
    }

    try
    {
        (m5 + m4);
    }
    catch (std::runtime_error e)
    {
        assert(e.what() == std::string("Error: Add two matrices of different size."));
    }

    std::cout << "op1(): operator+ operator- operator* test OK." << std::endl;
}

void MatrixTest::op2()
{
    Matrix m = Matrix(2, 2, 1);
    assert(m * 2 == Matrix(2, 2, 2));
    assert(2 * m == Matrix(2, 2, 2));
    assert(m / 1 == Matrix(2, 2, 1));
    assert(m / 2 == Matrix(2, 2, 0.5));

    std::cout << "op2(): scalar multiplication test OK." << std::endl;
}

void MatrixTest::trans()
{
    Matrix m = Matrix(2, 3, 1);
    assert(m.transpose() == Matrix(3, 2, 1));
    assert(m == Matrix(2, 3, 1));
    Matrix m2 = Matrix(1, 5, 1);
    Matrix m3 = m2;
    assert(m2 * m3.transpose() == Matrix(1, 5));

    std::cout << "trans(): transpose() test OK." << std::endl;
}

void MatrixTest::e()
{
    Matrix m = Matrix({Vector({1, 2, 3}), Vector({4, 5, 6}), Vector({7, 8, 9})});
    m.E((size_t)0, (size_t)1);
    assert(m == Matrix({Vector({4, 5, 6}), Vector({1, 2, 3}), Vector({7, 8, 9})}));
    m.E((size_t)1, (double)2);
    assert(m == Matrix({Vector({4, 5, 6}), Vector({2, 4, 6}), Vector({7, 8, 9})}));
    m.E((size_t)0, (size_t)1, -1);
    assert(m == Matrix({Vector({2, 1, 0}), Vector({2, 4, 6}), Vector({7, 8, 9})}));

    std::cout << "e(): elementary row transformation test OK." << std::endl;
}
