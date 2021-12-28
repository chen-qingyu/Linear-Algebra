#include <QCoreApplication>
#include <fraction.h>
#include <test.h>

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);

    FractionTest::test();

    return a.exec();
}
