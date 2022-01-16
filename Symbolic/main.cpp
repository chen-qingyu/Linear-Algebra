#include <QCoreApplication>

#include "test.h"

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);

    FractionTest::test();
    RealItemTest::test();
    RealTest::test();

    return a.exec();
}
