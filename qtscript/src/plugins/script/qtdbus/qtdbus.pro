TARGET  = qtscriptdbus5_3_1_V3-WinEC70Colibri-msvc2008

PLUGIN_TYPE = script
PLUGIN_CLASS_NAME = QtDBusScriptPlugin
load(qt_plugin)

QT = core gui script
CONFIG += qdbus

SOURCES += main.cpp
HEADERS += main.h
