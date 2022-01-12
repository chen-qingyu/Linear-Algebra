TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        matrix.cpp \
        squarematrix.cpp \
        test/matrixtest.cpp \
        test/squarematrixtest.cpp \
        test/vectortest.cpp \
        vector.cpp

HEADERS += \
    double.h \
    matrix.h \
    squarematrix.h \
    test.h \
    test/matrixtest.h \
    test/squarematrixtest.h \
    test/vectortest.h \
    vector.h
