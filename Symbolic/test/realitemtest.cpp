#include <assert.h>

#include "realitem.h"
#include "realitemtest.h"

void RealItemTest::test()
{
    std::cout << "==== RealItemTest::test(): Begin test. ====" << std::endl;
    ri();
    //    op1();
    //    op2();
    //    op3();
    //    cmp1();
    //    cmp2();
    //    cmp3();
    //    tostr();
    //    opassign1();
    //    opassign2();
    //    unary();
    //    all();
    std::cout << "==== RealItemTest::test(): All test OK! ====" << std::endl;
}

void RealItemTest::ri()
{
    RealItem item = RealItem(0, 233, 233);
    assert(item.coef == 0);
    assert(item.rational == 1);
    assert(item.power == 0);

    item = RealItem(233, 0, 233);
    assert(item.coef == 0);
    assert(item.rational == 1);
    assert(item.power == 0);

    item = RealItem(233, 1, 233);
    assert(item.coef == 233);
    assert(item.rational == 1);
    assert(item.power == 0);

    item = RealItem(233, 233, 0);
    assert(item.coef == 233);
    assert(item.rational == 1);
    assert(item.power == 0);

    item = RealItem(3, 2, 2);
    assert(item.coef == 3);
    assert(item.rational == 4);
    assert(item.power == 1);

    // 8^(1/3) -> 2
    item = RealItem(1, 8, Fraction(1, 3));
    assert(item.coef == 2);
    assert(item.rational == 1);
    assert(item.power == 0);

    // √12 -> 2√3
    item = RealItem(1, 12, Fraction(1, 2));
    assert(item.coef == 2);
    assert(item.rational == 3);
    assert(item.power == Fraction(1, 2));

    // 4 * 24^(-1/2) -> 2 * 6^(-1/2)
    item = RealItem(4, 24, Fraction(-1, 2));
    assert(item.coef == 2);
    assert(item.rational == 6);
    assert(item.power == Fraction(-1, 2));

    // 2^(-2/3) -> 4^(-1/3)
    item = RealItem(1, 2, Fraction(-2, 3));
    assert(item.coef == 1);
    assert(item.rational == 4);
    assert(item.power == Fraction(-1, 3));

    std::cout << "ri(): RealItem() test OK." << std::endl;
}
