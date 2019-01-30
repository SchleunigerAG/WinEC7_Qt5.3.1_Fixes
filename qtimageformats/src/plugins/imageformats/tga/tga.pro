TARGET = qtga5_3_1_V3-WinEC70Colibri-msvc2008

PLUGIN_TYPE = imageformats
PLUGIN_CLASS_NAME = QTgaPlugin
load(qt_plugin)

HEADERS += qtgahandler.h \
    qtgafile.h
SOURCES += qtgahandler.cpp \
    qtgafile.cpp
OTHER_FILES += tga.json

SOURCES += main.cpp
