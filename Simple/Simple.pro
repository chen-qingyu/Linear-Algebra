TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        test/vectortest.cpp \
        vector.cpp

HEADERS += \
    double.h \
    test.h \
    test/vectortest.h \
    vector.h
