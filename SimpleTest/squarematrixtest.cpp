#include "test.h"

#include "../Simple/squarematrix.h"

TEST(SquareMatrix, squa)
{
    SquareMatrix sm1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    ASSERT_EQ(sm1.size, (Matrix::size_t)3);
    ASSERT_EQ(sm1[0][0], 1);
    ASSERT_EQ(sm1[2][2], 9);

    SquareMatrix sm2;
    ASSERT_EQ(sm2.size, (Matrix::size_t)0);
    ASSERT_EQ(sm2, SquareMatrix());

    SquareMatrix sm3(4);
    ASSERT_EQ(sm3.size, (Matrix::size_t)4);
    ASSERT_EQ(sm3[0][0], 1);
    ASSERT_EQ(sm3[0][1], 0);
    ASSERT_EQ(sm3[1][0], 0);
    ASSERT_EQ(sm3[1][1], 1);

    SquareMatrix sm4(4, 1);
    ASSERT_EQ(sm4.size, (Matrix::size_t)4);
    ASSERT_EQ(sm4[0][0], 1);
    ASSERT_EQ(sm4[0][1], 1);
    ASSERT_EQ(sm4[1][0], 1);
    ASSERT_EQ(sm4[1][1], 1);

    try
    {
        SquareMatrix sm5 = {{1, 2, 3}, {4, 5, 6}};
    }
    catch (std::runtime_error e)
    {
        ASSERT_STREQ(e.what(), "Error: The rows and columns of the square matrix are not equal.");
    }

    SquareMatrix sm6(5, 4);
    ASSERT_EQ(sm6.size, (Matrix::size_t)5);
    ASSERT_EQ(sm6[0][0], 4);
    ASSERT_EQ(sm6[4][4], 4);
    sm6 = {{1, 2}, {3, 4}};
    ASSERT_EQ(sm6.size, (Matrix::size_t)2);
    ASSERT_EQ(sm6[0][0], 1);
    ASSERT_EQ(sm6[1][1], 4);

    std::cout << "SquareMatrix() test OK." << std::endl;
}

TEST(SquareMatrix, det)
{
    SquareMatrix sm = SquareMatrix(2, 1);
    ASSERT_TRUE(eq(sm.det(), 0));

    sm = SquareMatrix({Vector({1, 2, 3}), Vector({4, 5, 6}), Vector({7, 8, 9})});
    ASSERT_TRUE(eq(sm.det(), 0));

    sm = SquareMatrix({Vector({1, 2, 3}), Vector({4, 5, 6}), Vector({7, 8, 0})});
    ASSERT_TRUE(eq(sm.det(), 27));

    sm = SquareMatrix(2, 1) + SquareMatrix(2, 1) + SquareMatrix(2, 1);
    ASSERT_TRUE(eq(sm.det(), 0));

    sm = SquareMatrix({Vector({1, 1}), Vector({1, 1})}) + SquareMatrix({Vector({1, 2}), Vector({3, 4})});
    ASSERT_TRUE(eq(sm.det(), -2));

    sm = SquareMatrix(1, 1);
    ASSERT_TRUE(eq(sm.det(), 1));

    sm = SquareMatrix(1, 233);
    ASSERT_TRUE(eq(sm.det(), 233));

    sm = SquareMatrix(1, 233) + SquareMatrix(1, 233);
    ASSERT_TRUE(eq(sm.det(), 466));

    std::cout << "det() test OK." << std::endl;
}

TEST(SquareMatrix, inv)
{
    SquareMatrix sm({Vector({1, 1}), Vector({1, 1})});
    ASSERT_EQ(sm.inverse(), SquareMatrix());

    sm = SquareMatrix({Vector({1, 2}), Vector({3, 4})});
    ASSERT_EQ(sm.inverse(), SquareMatrix({Vector({-2, 1}), Vector({1.5, -0.5})}));

    sm = SquareMatrix({Vector({1, 2, 3}), Vector({4, 5, 6}), Vector({7, 8, 9})});
    ASSERT_EQ(sm.inverse(), SquareMatrix());

    sm = SquareMatrix({Vector({1, 2, 3}), Vector({4, 5, 6}), Vector({7, 8, 0})});
    ASSERT_EQ(sm.inverse(), SquareMatrix({Vector({-1.777777777777778, 0.888888888888889, -0.111111111111111}),
                                Vector({1.555555555555556, -0.777777777777778, 0.222222222222222}),
                                Vector({-0.111111111111111, 0.222222222222222, -0.111111111111111})}));

    std::cout << "inverse() test OK." << std::endl;
}

TEST(SquareMatrix, opassign)
{
    SquareMatrix sm;
    ASSERT_EQ(sm, SquareMatrix());

    sm = SquareMatrix({Vector({1, 1}), Vector({1, 1})});
    ASSERT_EQ(sm, SquareMatrix({Vector({1, 1}), Vector({1, 1})}));

    SquareMatrix sm2 = SquareMatrix({Vector({2, 2}), Vector({2, 2})});
    ASSERT_EQ(sm2, SquareMatrix({Vector({2, 2}), Vector({2, 2})}));

    sm2 = sm;
    ASSERT_EQ(sm2, SquareMatrix({Vector({1, 1}), Vector({1, 1})}));

    std::cout << "operator=() test OK." << std::endl;
}
