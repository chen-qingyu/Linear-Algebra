include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
    test.h \
    ../Simple/vector.h \
    ../Simple/matrix.h \
    ../Simple/squarematrix.h

SOURCES += \
    main.cpp \
    ../Simple/vector.cpp \
    ../Simple/matrix.cpp \
    ../Simple/squarematrix.cpp \
    vectortest.cpp \
    matrixtest.cpp \
    squarematrixtest.cpp
