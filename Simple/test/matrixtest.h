#ifndef MATRIXTEST_H
#define MATRIXTEST_H

class MatrixTest
{
public:
    static void test();

private:
    static void matr();  // Matrix()
    static void op();    // [] == !=
    static void tostr(); // toString()
    static void op1();   // + - *
    static void op2();   // scalar multiplication
    static void trans(); // transpose()
    static void e();     // elementary row transformation
    //    static void rank();  // rank()
    //        static void all();   // comprehensive
};

#endif // MATRIXTEST_H
