#include <assert.h>

#include "irrational.h"
#include "irrationaltest.h"

void IrrationalTest::test()
{
    std::cout << "==== IrrationalTest::test(): Begin test. ====" << std::endl;
    item();
    irra();
    tostr();
    std::cout << "==== IrrationalTest::test(): All test OK! ====" << std::endl;
}

void IrrationalTest::item()
{
    Irrational::Item item = Irrational::Item(0, 233, 233);
    assert(item.coef == 0);
    assert(item.rational == 1);
    assert(item.power == 0);

    item = Irrational::Item(233, 0, 233);
    assert(item.coef == 0);
    assert(item.rational == 1);
    assert(item.power == 0);

    item = Irrational::Item(233, 1, 233);
    assert(item.coef == 233);
    assert(item.rational == 1);
    assert(item.power == 0);

    item = Irrational::Item(233, 233, 0);
    assert(item.coef == 233);
    assert(item.rational == 1);
    assert(item.power == 0);

    item = Irrational::Item(3, 2, 2);
    assert(item.coef == 3);
    assert(item.rational == 4);
    assert(item.power == 1);

    // 8^(1/3) -> 2
    item = Irrational::Item(1, 8, Fraction(1, 3));
    assert(item.coef == 2);
    assert(item.rational == 1);
    assert(item.power == 0);

    // √12 -> 2√3
    item = Irrational::Item(1, 12, Fraction(1, 2));
    assert(item.coef == 2);
    assert(item.rational == 3);
    assert(item.power == Fraction(1, 2));

    // 4 * 24^(-1/2) -> 2 * 6^(-1/2)
    item = Irrational::Item(4, 24, Fraction(-1, 2));
    assert(item.coef == 2);
    assert(item.rational == 6);
    assert(item.power == Fraction(-1, 2));

    // 2^(-2/3) -> 4^(-1/3)
    item = Irrational::Item(1, 2, Fraction(-2, 3));
    assert(item.coef == 1);
    assert(item.rational == 4);
    assert(item.power == Fraction(-1, 3));

    std::cout << "item(): Item::simplify() test OK." << std::endl;
}

void IrrationalTest::irra()
{
    using item = Irrational::Item;
    Irrational a = Irrational({item(1, 2, Fraction(1, 2)), item(2, 2, Fraction(1, 2))});
    Irrational b = Irrational(item(3, 2, Fraction(1, 2)));
    //    assert(a == b);

    std::cout << "irra(): Irrational::simplify() test OK." << std::endl;
}

void IrrationalTest::tostr()
{
    using item = Irrational::Item;
    Irrational a = Irrational({item(1, 2, Fraction(1, 2)), item(2, 2, Fraction(1, 2))});
    Irrational b = Irrational(item(3, 2, Fraction(1, 2)));
    assert(a.toString() == "1*2^(1/2) + 2*2^(1/2)");
    assert(b.toString() == "3*2^(1/2)");

    std::cout << "tostr(): toString() test OK." << std::endl;
}
