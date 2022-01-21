#include "squarematrix.h"

int main(void)
{
    SquareMatrix sm = SquareMatrix({Vector({1, 2}), Vector({3, 4})});
    sm.inverse();
    std::cout << "OK";
    return 0;
}
