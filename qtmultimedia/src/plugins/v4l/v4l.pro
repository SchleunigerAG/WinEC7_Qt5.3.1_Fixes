TARGET = qtmedia_v4lengine5_3_1_V3-WinEC70Colibri-msvc2008
QT += multimedia-private

PLUGIN_TYPE = mediaservice
PLUGIN_CLASS_NAME = V4LServicePlugin
load(qt_plugin)

HEADERS += v4lserviceplugin.h
SOURCES += v4lserviceplugin.cpp

include(radio/radio.pri)
