CONFIG += testcase
TARGET = tst_qgeocameratiles

INCLUDEPATH += ../../../src/location/maps

SOURCES += tst_qgeocameratiles.cpp

QT += location positioning-private testlib 3d
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0
