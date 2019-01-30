TARGET  = qsvgicon5_3_1_V3-WinEC70Colibri-msvc2008

PLUGIN_TYPE = iconengines
PLUGIN_EXTENDS = svg
PLUGIN_CLASS_NAME = QSvgIconPlugin
load(qt_plugin)

HEADERS += qsvgiconengine.h
SOURCES += main.cpp \
           qsvgiconengine.cpp
OTHER_FILES += qsvgiconengine.json
QT += svg core-private gui-private
