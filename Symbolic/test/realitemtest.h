#ifndef REALITEMTEST_H
#define REALITEMTEST_H

class RealItemTest
{
public:
    static void test();

private:
    static void ri();        // RealItem()
    static void op1();       // int (op) RealItem
    static void op2();       // RealItem (op) RealItem
    static void op3();       // RealItem (op) int
    static void cmp1();      // int (cmp) RealItem
    static void cmp2();      // RealItem (cmp) RealItem
    static void cmp3();      // RealItem (cmp) int
    static void tostr();     // toString()
    static void opassign1(); // RealItem (op)= RealItem
    static void opassign2(); // RealItem (op)= int
    static void unary();     // (op) RealItem
    static void all();       // comprehensive
};

#endif // REALITEMTEST_H
