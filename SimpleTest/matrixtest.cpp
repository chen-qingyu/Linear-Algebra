#include "test.h"

#include "../Simple/matrix.h"

TEST(MatrixTest, matr)
{
    Matrix m;
    ASSERT_EQ(m.size.row, (Matrix::size_t)0);
    ASSERT_EQ(m.size.col, (Matrix::size_t)0);
    Matrix m2 = Matrix({Vector({1, 2, 3}), Vector({4, 5, 6})});
    ASSERT_EQ(m2.size.row, (Matrix::size_t)2);
    ASSERT_EQ(m2.size.col, (Matrix::size_t)3);
    ASSERT_EQ(m2[0], Vector({1, 2, 3}));
    ASSERT_EQ(m2[1], Vector({4, 5, 6}));
    Matrix m3 = Matrix(4, 0);
    ASSERT_EQ(m3.size.row, (Matrix::size_t)4);
    ASSERT_EQ(m3.size.col, (Matrix::size_t)4);
    ASSERT_EQ(m3[3][3], 0);
    Matrix m4 = Matrix(4, 5, 1);
    ASSERT_EQ(m4.size.row, (Matrix::size_t)4);
    ASSERT_EQ(m4.size.col, (Matrix::size_t)5);
    ASSERT_EQ(m4[3][4], 1);

    std::cout << "Matrix() test OK." << std::endl;
}

TEST(MatrixTest, op)
{
    Matrix m = Matrix(2, 3, 0);
    ASSERT_EQ(m[0][0], 0);
    ASSERT_EQ(m[1][2], 0);
    m[0][0] = 1;
    m[1][2] = 233;
    ASSERT_EQ(m[0][0], 1);
    ASSERT_EQ(m[1][2], 233);

    try
    {
        m[2][3] = 9;
    }
    catch (std::runtime_error e)
    {
        ASSERT_EQ(e.what(), std::string("Error: Matrix index out of bounds."));
    }

    ASSERT_EQ(m, Matrix({Vector({1, 0, 0}), Vector({0, 0, 233})}));
    ASSERT_NE(m, Matrix());

    std::cout << "operator[] operator== operator!= test OK." << std::endl;
}

TEST(MatrixTest, tostr)
{
    Matrix m = Matrix();
    ASSERT_EQ(m.toString(), "[]");
    Matrix m2 = Matrix(2, 3, 0);
    ASSERT_EQ(m2.toString(), "[0.000000 0.000000 0.000000]\n[0.000000 0.000000 0.000000]");
    Matrix m3 = Matrix(1, 2, 5);
    ASSERT_EQ(m3.toString(), "[5.000000 5.000000]");

    std::cout << "toString() test OK." << std::endl;
}

TEST(MatrixTest, op1)
{
    Matrix m1 = Matrix(2, 3, 1);
    Matrix m2 = Matrix(2, 3, 2);
    ASSERT_EQ(m1 + m2, Matrix(2, 3, 3));
    ASSERT_EQ(m1 - m2, Matrix(2, 3, -1));
    ASSERT_EQ(m2 - m1, Matrix(2, 3, 1));

    Matrix m3 = Matrix(2, 2, 1);
    Matrix m4 = Matrix(2, 2, 2);
    Matrix m5 = Matrix(2, 3, 3);
    ASSERT_EQ(m3 * m4, Matrix(2, 2, 4));
    ASSERT_EQ(m3 * m5, Matrix(2, 3, 6));
    ASSERT_EQ(m4 * m5, Matrix(2, 3, 12));

    Matrix m6 = Matrix(1, 3, 1);
    Matrix m7 = Matrix(3, 1, 1);
    ASSERT_EQ(m6 * m7, Matrix(1, 3));

    try
    {
        (m5 * m4);
    }
    catch (std::runtime_error e)
    {
        ASSERT_EQ(e.what(), std::string("Error: The row and column size don't match."));
    }

    try
    {
        (m5 + m4);
    }
    catch (std::runtime_error e)
    {
        ASSERT_EQ(e.what(), std::string("Error: Add two matrices of different size."));
    }

    std::cout << "operator+ operator- operator* test OK." << std::endl;
}

TEST(MatrixTest, op2)
{
    Matrix m = Matrix(2, 2, 1);
    ASSERT_EQ(m * 2, Matrix(2, 2, 2));
    ASSERT_EQ(2 * m, Matrix(2, 2, 2));
    ASSERT_EQ(m / 1, Matrix(2, 2, 1));
    ASSERT_EQ(m / 2, Matrix(2, 2, 0.5));

    std::cout << "scalar multiplication test OK." << std::endl;
}

TEST(MatrixTest, trans)
{
    Matrix m = Matrix(2, 3, 1);
    ASSERT_EQ(m.transpose(), Matrix(3, 2, 1));
    ASSERT_EQ(m, Matrix(2, 3, 1));
    Matrix m2 = Matrix(1, 5, 1);
    Matrix m3 = m2;
    ASSERT_EQ(m2 * m3.transpose(), Matrix(1, 5));

    std::cout << "transpose() test OK." << std::endl;
}

TEST(MatrixTest, e)
{
    Matrix m = Matrix({Vector({1, 2, 3}), Vector({4, 5, 6}), Vector({7, 8, 9})});
    m.E((size_t)0, (size_t)1);
    ASSERT_EQ(m, Matrix({Vector({4, 5, 6}), Vector({1, 2, 3}), Vector({7, 8, 9})}));
    m.E((size_t)1, (double)2);
    ASSERT_EQ(m, Matrix({Vector({4, 5, 6}), Vector({2, 4, 6}), Vector({7, 8, 9})}));
    m.E((size_t)0, (size_t)1, -1);
    ASSERT_EQ(m, Matrix({Vector({2, 1, 0}), Vector({2, 4, 6}), Vector({7, 8, 9})}));

    std::cout << "elementary row transformation test OK." << std::endl;
}
