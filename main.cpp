#include <QCoreApplication>
#include <fraction.h>
#include <test.h>
#include <time.h>

int main(int argc, char* argv[])
{
    QCoreApplication a(argc, argv);

    FractionTest::test();

    return a.exec();
}
