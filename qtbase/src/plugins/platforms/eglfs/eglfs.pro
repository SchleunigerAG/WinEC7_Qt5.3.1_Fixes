TARGET = qeglfs5_3_1_V3-WinEC70Colibri-msvc2008

PLUGIN_TYPE = platforms
PLUGIN_CLASS_NAME = QEglFSIntegrationPlugin
!equals(TARGET, $$QT_DEFAULT_QPA_PLUGIN): PLUGIN_EXTENDS = -
load(qt_plugin)

SOURCES += $$PWD/main.cpp

include(eglfs.pri)
