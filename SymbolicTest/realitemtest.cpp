#include "test.h"

#include "../Symbolic/realitem.h"

TEST(RealItemTest, ri)
{
    RealItem item = RealItem(0, 233, 233);
    ASSERT_EQ(item, RealItem(0, 1, 0));

    item = RealItem(233, 0, 233);
    ASSERT_EQ(item, RealItem(0, 1, 0));

    item = RealItem(233, 1, 233);
    ASSERT_EQ(item, RealItem(233, 1, 0));

    item = RealItem(233, 233, 0);
    ASSERT_EQ(item, RealItem(233, 1, 0));

    item = RealItem(3, 2, 2);
    ASSERT_EQ(item, RealItem(3, 4, 1));

    // 8^(1/3) -> 2
    item = RealItem(1, 8, Fraction(1, 3));
    ASSERT_EQ(item, RealItem(2, 1, 0));

    // √12 -> 2√3
    item = RealItem(1, 12, Fraction(1, 2));
    ASSERT_EQ(item, RealItem(2, 3, Fraction(1, 2)));

    // 4 * 24^(-1/2) -> 2 * 6^(-1/2)
    item = RealItem(4, 24, Fraction(-1, 2));
    ASSERT_EQ(item, RealItem(2, 6, Fraction(-1, 2)));

    // 2^(-2/3) -> 4^(-1/3)
    item = RealItem(1, 2, Fraction(-2, 3));
    ASSERT_EQ(item, RealItem(1, 4, Fraction(-1, 3)));

    std::cout << "RealItem() test OK." << std::endl;
}
