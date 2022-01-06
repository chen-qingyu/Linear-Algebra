#ifndef VECTOR_TEST_H
#define VECTOR_TEST_H

#include "vector.h"

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
    static void all();    // comprehensive
};

#endif // VECTOR_TEST_H
