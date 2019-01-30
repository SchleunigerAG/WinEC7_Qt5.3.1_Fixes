TARGET = qwbmp5_3_1_V3-WinEC70Colibri-msvc2008

PLUGIN_TYPE = imageformats
PLUGIN_CLASS_NAME = QWbmpPlugin
load(qt_plugin)

HEADERS += qwbmphandler_p.h
SOURCES += qwbmphandler.cpp
OTHER_FILES += wbmp.json

SOURCES += main.cpp
