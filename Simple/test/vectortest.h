#ifndef VECTORTEST_H
#define VECTORTEST_H

class VectorTest
{
public:
    static void test();

private:
    static void vect();   // Vector()
    static void append(); // append()
    static void op();     // [] ==
    static void tostr();  // toString()
    static void op1();    // + -
    static void op2();    // dot product
    static void op3();    // scalar multiplication
    static void len();    // length()
    static void vp();     // isVerticalTo() isParallelTo()
    static void unit();   // unitize()
    static void all();    // comprehensive
};

#endif // VECTORTEST_H
