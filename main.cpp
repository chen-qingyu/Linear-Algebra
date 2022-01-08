#include <QCoreApplication>

#include "test.h"

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);

    //    FractionTest::test();
    //    VectorTest::test();
    IrrationalTest::test();

    return a.exec();
}
