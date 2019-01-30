TARGET  = qgif5_3_1_V3-WinEC70Colibri-msvc2008

PLUGIN_TYPE = imageformats
PLUGIN_CLASS_NAME = QGifPlugin
load(qt_plugin)

include(../../../gui/image/qgifhandler.pri)
SOURCES += $$PWD/main.cpp
HEADERS += $$PWD/main.h
OTHER_FILES += gif.json
