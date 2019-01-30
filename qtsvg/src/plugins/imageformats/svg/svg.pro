TARGET  = qsvg5_3_1_V3-WinEC70Colibri-msvc2008

PLUGIN_TYPE = imageformats
PLUGIN_EXTENDS = svg
PLUGIN_CLASS_NAME = QSvgPlugin
load(qt_plugin)

HEADERS += qsvgiohandler.h
SOURCES += main.cpp \
           qsvgiohandler.cpp
QT += svg
