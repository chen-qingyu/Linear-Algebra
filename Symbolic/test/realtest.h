#ifndef REALTEST_H
#define REALTEST_H

class RealTest
{
public:
    static void test();

private:
    static void real();      // Real()
    static void op1();       // int (op) Real
    static void op2();       // Real (op) Real
    static void op3();       // Real (op) int
    static void cmp1();      // int (cmp) Real
    static void cmp2();      // Real (cmp) Real
    static void cmp3();      // Real (cmp) int
    static void tostr();     // toString()
    static void opassign1(); // Real (op)= Real
    static void opassign2(); // Real (op)= int
    static void all();       // comprehensive
};

#endif // REALTEST_H
