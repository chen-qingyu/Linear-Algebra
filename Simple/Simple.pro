TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        matrix.cpp \
        test/vectortest.cpp \
        vector.cpp

HEADERS += \
    double.h \
    matrix.h \
    test.h \
    test/vectortest.h \
    vector.h
