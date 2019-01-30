TARGET = qtsensorgestures_shakeplugin5_3_1_V3-WinEC70Colibri-msvc2008
QT = core sensors

PLUGIN_TYPE = sensorgestures
PLUGIN_CLASS_NAME = QShakeSensorGesturePlugin
PLUGIN_EXTENDS = -
load(qt_plugin)

# Input
HEADERS += qshakesensorgestureplugin.h \
           qshakerecognizer.h
SOURCES += qshakesensorgestureplugin.cpp \
           qshakerecognizer.cpp

OTHER_FILES += \
    plugin.json

