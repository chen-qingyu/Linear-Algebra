include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
    test.h \
    ../Symbolic/fraction.h \
    ../Symbolic/realitem.h \
    ../Symbolic/real.h \
    ../Symbolic/vector.h

SOURCES += \
    main.cpp \
    ../Symbolic/fraction.cpp \
    ../Symbolic/realitem.cpp \
    ../Symbolic/real.cpp \
    ../Symbolic/vector.cpp \
    fractiontest.cpp \
    realitemtest.cpp \
    realtest.cpp \
    vectortest.cpp
