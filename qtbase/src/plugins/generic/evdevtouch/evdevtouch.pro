TARGET = qevdevtouchplugin5_3_1_V3-WinEC70Colibri-msvc2008

PLUGIN_TYPE = generic
PLUGIN_EXTENDS = -
PLUGIN_CLASS_NAME = QEvdevTouchScreenPlugin
load(qt_plugin)

SOURCES = main.cpp

QT += core-private platformsupport-private gui-private

OTHER_FILES += \
    evdevtouch.json

