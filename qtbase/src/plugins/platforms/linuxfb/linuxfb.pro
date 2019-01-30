TARGET = qlinuxfb5_3_1_V3-WinEC70Colibri-msvc2008

PLUGIN_TYPE = platforms
PLUGIN_CLASS_NAME = QLinuxFbIntegrationPlugin
!equals(TARGET, $$QT_DEFAULT_QPA_PLUGIN): PLUGIN_EXTENDS = -
load(qt_plugin)

QT += core-private gui-private platformsupport-private

SOURCES = main.cpp qlinuxfbintegration.cpp qlinuxfbscreen.cpp
HEADERS = qlinuxfbintegration.h qlinuxfbscreen.h

CONFIG += qpa/genericunixfontdatabase

OTHER_FILES += linuxfb.json
