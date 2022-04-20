#include "test.h"

#include "../Simple/matrix.h"

TEST(MatrixTest, matr)
{
    Matrix m;
    ASSERT_EQ(m.rowSize(), (Matrix::size_t)0);
    ASSERT_EQ(m.colSize(), (Matrix::size_t)0);

    Matrix m2 = Matrix({Vector({1, 2, 3}), Vector({4, 5, 6})});
    ASSERT_EQ(m2.rowSize(), (Matrix::size_t)2);
    ASSERT_EQ(m2.colSize(), (Matrix::size_t)3);
    ASSERT_EQ(m2[0], Vector({1, 2, 3}));
    ASSERT_EQ(m2[1], Vector({4, 5, 6}));

    Matrix m3 = Matrix(4, 0);
    ASSERT_EQ(m3.rowSize(), (Matrix::size_t)4);
    ASSERT_EQ(m3.colSize(), (Matrix::size_t)4);
    ASSERT_EQ(m3[3][3], 0);

    Matrix m4 = Matrix(4, 5, 1);
    ASSERT_EQ(m4.rowSize(), (Matrix::size_t)4);
    ASSERT_EQ(m4.colSize(), (Matrix::size_t)5);
    ASSERT_EQ(m4[3][4], 1);

    Matrix m5 = {{1, 2, 3}, {4, 5, 6}};
    ASSERT_EQ(m5.rowSize(), (Matrix::size_t)2);
    ASSERT_EQ(m5.colSize(), (Matrix::size_t)3);
    ASSERT_EQ(m5[0][0], 1);
    ASSERT_EQ(m5[1][2], 6);

    try
    {
        Matrix m6 = {{1, 2, 3}, {4, 5, 6, 7}};
    }
    catch (std::runtime_error e)
    {
        ASSERT_STREQ(e.what(), "Error: The row vectors are not of equal size.");
    }

    try
    {
        Matrix m7 = {{}, {}};
    }
    catch (std::runtime_error e)
    {
        ASSERT_STREQ(e.what(), "Error: The matrix are empty.");
    }

    Matrix m8(1, 9);
    ASSERT_EQ(m8.rowSize(), (Matrix::size_t)1);
    ASSERT_EQ(m8.colSize(), (Matrix::size_t)1);
    ASSERT_EQ(m8[0][0], 9);
    m8 = {{1, 2}, {3, 4}, {5, 6}};
    ASSERT_EQ(m8.rowSize(), (Matrix::size_t)3);
    ASSERT_EQ(m8.colSize(), (Matrix::size_t)2);
    ASSERT_EQ(m8[0][0], 1);
    ASSERT_EQ(m8[2][1], 6);

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
        ASSERT_STREQ(e.what(), "Error: Matrix index out of bounds.");
    }

    ASSERT_EQ(m, Matrix({Vector({1, 0, 0}), Vector({0, 0, 233})}));
    ASSERT_NE(m, Matrix());

    std::cout << "operator[] operator== operator!= test OK." << std::endl;
}

TEST(MatrixTest, tostr)
{
    Matrix m = Matrix();
    ASSERT_EQ((string)m, "[]");
    Matrix m2 = Matrix(2, 3, 0);
    ASSERT_EQ((string)m2, "[0.000000 0.000000 0.000000]\n[0.000000 0.000000 0.000000]");
    Matrix m3 = Matrix(1, 2, 5);
    ASSERT_EQ((string)m3, "[5.000000 5.000000]");

    std::cout << "operator string() test OK." << std::endl;
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
        ASSERT_STREQ(e.what(), "Error: The row and column size don't match.");
    }

    try
    {
        (m5 + m4);
    }
    catch (std::runtime_error e)
    {
        ASSERT_STREQ(e.what(), "Error: Add two matrices of different size.");
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

TEST(MatrixTest, echelon)
{
    Matrix m = Matrix(2, 1);
    ASSERT_EQ((string)m.rowEchelon(), "[1.000000 1.000000]\n[0.000000 0.000000]");
    m = Matrix({Vector({1, 2, 3}), Vector({4, 5, 6})});
    ASSERT_EQ((string)m.rowEchelon(), "[1.000000 2.000000 3.000000]\n[0.000000 -3.000000 -6.000000]");
    m = Matrix({Vector({1, 2}), Vector({3, 4}), Vector({5, 6})});
    ASSERT_EQ((string)m.rowEchelon(), "[1.000000 2.000000]\n[0.000000 -2.000000]\n[0.000000 0.000000]");

    std::cout << "rowEchelon() test OK." << std::endl;
}

TEST(MatrixTest, rank)
{
    Matrix m = Matrix(2, 1);
    ASSERT_EQ(m.rank(), (Matrix::size_t)1);

    m = Matrix({Vector({1, 2, 3}), Vector({4, 5, 6})});
    ASSERT_EQ(m.rank(), (Matrix::size_t)2);

    m = Matrix({Vector({1, 2}), Vector({3, 4}), Vector({5, 6})});
    ASSERT_EQ(m.rank(), (Matrix::size_t)2);

    m = Matrix({Vector({1, 2, 3}), Vector({4, 5, 6}), Vector({7, 8, 9})});
    ASSERT_EQ(m.rank(), (Matrix::size_t)2);

    m = Matrix({Vector({1, 2, 3}), Vector({4, 5, 6}), Vector({7, 8, 0})});
    ASSERT_EQ(m.rank(), (Matrix::size_t)3);

    std::cout << "rank() test OK." << std::endl;
}

TEST(MatrixTest, combine)
{
    Matrix m1 = {{1, 2}, {3, 4}};
    Matrix m2(2, 0);
    ASSERT_EQ(m1.combine(Matrix::COL, m2), Matrix({{1, 2, 0, 0}, {3, 4, 0, 0}}));
    ASSERT_EQ(m2.combine(Matrix::COL, m1), Matrix({{0, 0, 1, 2}, {0, 0, 3, 4}}));
    ASSERT_EQ(m1.combine(Matrix::ROW, m2), Matrix({{1, 2}, {3, 4}, {0, 0}, {0, 0}}));
    ASSERT_EQ(m2.combine(Matrix::ROW, m1), Matrix({{0, 0}, {0, 0}, {1, 2}, {3, 4}}));

    Matrix m3 = {{1, 2, 3, 4, 5}};
    Matrix m4 = {{6, 7, 8, 9, 10}};
    ASSERT_EQ(m3.combine(Matrix::COL, m4), Matrix({{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}}));
    ASSERT_EQ(m4.combine(Matrix::COL, m3), Matrix({{6, 7, 8, 9, 10, 1, 2, 3, 4, 5}}));
    ASSERT_EQ(m3.combine(Matrix::ROW, m4), Matrix({{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}}));
    ASSERT_EQ(m4.combine(Matrix::ROW, m3), Matrix({{6, 7, 8, 9, 10}, {1, 2, 3, 4, 5}}));

    std::cout << "combine() test OK." << std::endl;
}

TEST(MatrixTest, split)
{
    Matrix m1 = {{1, 2}, {3, 4}, {5, 6}};
    ASSERT_EQ(m1.split(Matrix::COL, 1)[0], Matrix({{1}, {3}, {5}}));
    ASSERT_EQ(m1.split(Matrix::COL, 1)[1], Matrix({{2}, {4}, {6}}));
    ASSERT_EQ(m1.split(Matrix::ROW, 1)[0], Matrix({{1, 2}}));
    ASSERT_EQ(m1.split(Matrix::ROW, 1)[1], Matrix({{3, 4}, {5, 6}}));

    Matrix m2 = {{1, 2, 3, 4, 5}};
    ASSERT_EQ(m2.split(Matrix::COL, 3)[0], Matrix({{1, 2, 3}}));
    ASSERT_EQ(m2.split(Matrix::COL, 3)[1], Matrix({{4, 5}}));
    try
    {
        m2.split(Matrix::ROW, 1);
    }
    catch (std::runtime_error e)
    {
        ASSERT_STREQ(e.what(), "Error: Invalid position.");
    }

    std::cout << "split() test OK." << std::endl;
}
