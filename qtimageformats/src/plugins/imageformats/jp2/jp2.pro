TARGET  = qjp25_3_1_V3-WinEC70Colibri-msvc2008

PLUGIN_TYPE = imageformats
PLUGIN_CLASS_NAME = QJp2Plugin
load(qt_plugin)

include(qjp2handler.pri)
SOURCES += main.cpp
OTHER_FILES += jp2.json
