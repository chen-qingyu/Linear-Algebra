#include "test.h"

#include "../Simple/squarematrix.h"

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
