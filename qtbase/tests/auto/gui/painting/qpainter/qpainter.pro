CONFIG += testcase
CONFIG += parallel_test
TARGET = tst_qpainter

QT += testlib
qtHaveModule(widgets): QT += widgets widgets-private

SOURCES  += tst_qpainter.cpp

TESTDATA += drawEllipse/* drawLine_rop_bitmap/* drawPixmap_rop/* drawPixmap_rop_bitmap/* \
            task217400.png
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0
