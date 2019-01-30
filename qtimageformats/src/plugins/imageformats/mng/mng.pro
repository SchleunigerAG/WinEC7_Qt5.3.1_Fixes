TARGET  = qmng5_3_1_V3-WinEC70Colibri-msvc2008

PLUGIN_TYPE = imageformats
PLUGIN_CLASS_NAME = QMngPlugin
load(qt_plugin)

include(qmnghandler.pri)
SOURCES += main.cpp
OTHER_FILES += mng.json
